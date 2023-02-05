/////////////////////////////////////////////////////////////////////////////
// Purpose:   wxPropertyGrid generator
// Author:    Ralph Walden
// Copyright: Copyright (c) 2020-2023 KeyWorks Software (Ralph Walden)
// License:   Apache License -- see ../../LICENSE
/////////////////////////////////////////////////////////////////////////////

#include <wx/propgrid/propgrid.h>  // wxPropertyGrid

#include "gen_common.h"     // GeneratorLibrary -- Generator classes
#include "gen_xrc_utils.h"  // Common XRC generating functions
#include "node.h"           // Node class
#include "pugixml.hpp"      // xml read/write/create/process
#include "utils.h"          // Utility functions that work with properties

#include "gen_prop_grid.h"

wxObject* PropertyGridGenerator::CreateMockup(Node* node, wxObject* parent)
{
    auto widget = new wxPropertyGrid(wxStaticCast(parent, wxWindow), wxID_ANY, DlgPoint(parent, node, prop_pos),
                                     DlgSize(parent, node, prop_size), GetStyleInt(node));

    if (node->HasValue(prop_extra_style))
    {
        widget->SetExtraStyle(node->prop_as_int(prop_extra_style));
    }

    widget->Bind(wxEVT_LEFT_DOWN, &BaseGenerator::OnLeftClick, this);

    return widget;
}

void PropertyGridGenerator::AfterCreation(wxObject* wxobject, wxWindow* /* wxparent */, Node* node, bool /* is_preview */)
{
    auto pg = wxStaticCast(wxobject, wxPropertyGrid);

    for (const auto& child: node->GetChildNodePtrs())
    {
        if (child->isGen(gen_propGridItem))
        {
            if (child->prop_as_string(prop_type) == "Category")
            {
                pg->Append(new wxPropertyCategory(child->prop_as_wxString(prop_label), child->prop_as_wxString(prop_label)));
            }
            else
            {
                wxPGProperty* prop = wxDynamicCast(
                    wxCreateDynamicObject("wx" + (child->prop_as_string(prop_type)) + "Property"), wxPGProperty);
                if (prop)
                {
                    prop->SetLabel(child->prop_as_wxString(prop_label));
                    prop->SetName(child->prop_as_wxString(prop_label));
                    pg->Append(prop);

                    if (child->HasValue(prop_help))
                    {
                        pg->SetPropertyHelpString(prop, child->prop_as_wxString(prop_help));
                    }
                }
            }
        }
    }
}

bool PropertyGridGenerator::ConstructionCode(Code& code)
{
    code.AddAuto().NodeName().CreateClass().ValidParentName().Comma().Add(prop_id);
    code.PosSizeFlags(false, "wxPG_DEFAULT_STYLE");

    if (code.HasValue(prop_extra_style))
        code.Eol().NodeName().Function("SetExtraStyle(").Add(prop_extra_style).EndFunction();

    return true;
}

bool PropertyGridGenerator::GetIncludes(Node* node, std::set<std::string>& set_src, std::set<std::string>& set_hdr)
{
    InsertGeneratorInclude(node, "#include <wx/propgrid/propgrid.h>", set_src, set_hdr);

    // TODO: [Randalphwa - 02-05-2023] This needs to be determined based on what items have been added
    // InsertGeneratorInclude(node, "#include <wx/propgrid/advprops.h>", set_src, set_hdr);
    return true;
}
