/////////////////////////////////////////////////////////////////////////////
// Purpose:   wxWrapSizer generator
// Author:    Ralph Walden
// Copyright: Copyright (c) 2020-2022 KeyWorks Software (Ralph Walden)
// License:   Apache License -- see ../../LICENSE
/////////////////////////////////////////////////////////////////////////////

#include <wx/sizer.h>
#include <wx/wrapsizer.h>

#include "gen_common.h"  // GeneratorLibrary -- Generator classes
#include "node.h"        // Node class

#include "pugixml.hpp"  // xml read/write/create/process

#include "gen_wrap_sizer.h"

wxObject* WrapSizerGenerator::CreateMockup(Node* node, wxObject* parent)
{
    auto sizer = new wxWrapSizer(node->as_int(prop_orientation), node->as_int(prop_flags));
    sizer->SetMinSize(node->as_wxSize(prop_minimum_size));
    if (auto dlg = wxDynamicCast(parent, wxDialog); dlg)
    {
        if (!dlg->GetSizer())
            dlg->SetSizer(sizer);
    }
    return sizer;
}

void WrapSizerGenerator::AfterCreation(wxObject* wxobject, wxWindow* /*wxparent*/, Node* node, bool /* is_preview */)
{
    if (node->as_bool(prop_hide_children))
    {
        if (auto sizer = wxStaticCast(wxobject, wxSizer); sizer)
            sizer->ShowItems(false);
    }
}

bool WrapSizerGenerator::ConstructionCode(Code& code)
{
    code.AddAuto().NodeName().CreateClass().as_string(prop_orientation).Comma();
    if (code.hasValue(prop_wrap_flags))
        code.as_string(prop_wrap_flags);
    else
        code += "0";
    code.EndFunction();

    if (code.hasValue(prop_minimum_size))
    {
        code.Eol().NodeName().Function("SetMinSize(").WxSize(prop_minimum_size).EndFunction();
    }

    return true;
}

bool WrapSizerGenerator::AfterChildrenCode(Code& code)
{
    if (code.IsTrue(prop_hide_children))
    {
        code.NodeName().Function("ShowItems(").False().EndFunction();
    }

    auto parent = code.node()->getParent();
    if (!parent->isSizer() && !parent->isGen(gen_wxDialog) && !parent->isGen(gen_PanelForm))
    {
        code.NewLine(true);
        if (parent->isGen(gen_wxRibbonPanel))
        {
            code.ParentName().Function("SetSizerAndFit(").NodeName().EndFunction();
        }
        else
        {
            if (GetParentName(code.node()) != "this")
            {
                code.ParentName().Function("SetSizerAndFit(").NodeName().EndFunction();
            }
            else
            {
                code.FormFunction("SetSizerAndFit(").NodeName().EndFunction();
            }
        }
    }

    return true;
}

bool WrapSizerGenerator::GetIncludes(Node* node, std::set<std::string>& set_src, std::set<std::string>& set_hdr)
{
    InsertGeneratorInclude(node, "#include <wx/wrapsizer.h>", set_src, set_hdr);
    return true;
}

// ../../wxSnapShot/src/xrc/xh_sizer.cpp
// ../../../wxWidgets/src/xrc/xh_sizer.cpp
// See Handle_wxWrapSizer()

int WrapSizerGenerator::GenXrcObject(Node* node, pugi::xml_node& object, size_t /* xrc_flags */)
{
    pugi::xml_node item;
    auto result = BaseGenerator::xrc_sizer_item_created;

    if (node->getParent()->isSizer())
    {
        GenXrcSizerItem(node, object);
        item = object.append_child("object");
    }
    else
    {
        item = object;
        result = BaseGenerator::xrc_updated;
    }

    item.append_attribute("class").set_value("wxWrapSizer");
    item.append_attribute("name").set_value(node->as_string(prop_var_name));
    item.append_child("orient").text().set(node->as_string(prop_orientation));

    ADD_ITEM_PROP(prop_wrap_flags, "flag")

    if (node->hasValue(prop_minimum_size))
    {
        item.append_child("minsize").text().set(node->as_string(prop_minimum_size));
    }
    else if (node->getParent()->isForm() && node->getParent()->hasValue(prop_minimum_size))
    {
        // As of wxWidgets 3.1.7, minsize can only be used for sizers, and wxSplitterWindow. That's a problem for forms which
        // often can specify their own minimum size. The workaround is to set the minimum size of the parent sizer that we
        // create for most forms.

        item.append_child("minsize").text().set(node->getParent()->as_string(prop_minimum_size));
    }
    return result;
}

void WrapSizerGenerator::RequiredHandlers(Node* /* node */, std::set<std::string>& handlers)
{
    handlers.emplace("wxSizerXmlHandler");
}
