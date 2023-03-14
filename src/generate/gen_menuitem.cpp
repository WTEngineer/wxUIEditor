/////////////////////////////////////////////////////////////////////////////
// Purpose:   Menu Item Generator
// Author:    Ralph Walden
// Copyright: Copyright (c) 2020-2022 KeyWorks Software (Ralph Walden)
// License:   Apache License -- see ../../LICENSE
/////////////////////////////////////////////////////////////////////////////

#include <wx/menu.h>  // wxMenu and wxMenuBar classes

#include "gen_common.h"       // GeneratorLibrary -- Generator classes
#include "node.h"             // Node class
#include "project_handler.h"  // ProjectHandler class

#include "gen_menuitem.h"

bool MenuItemGenerator::ConstructionCode(Code& code)
{
    Node* node = code.node();
    if (code.is_cpp() && code.is_local_var())
        code << "auto* ";

    if (node->GetParent()->isGen(gen_PopupMenu))
    {
        code.NodeName();
        if (code.is_cpp())
            code += " = Append(";
        else
            code += " = self.Append(";
        code.as_string(prop_id).Comma();
    }
    else
    {
        code.NodeName().CreateClass().ParentName().Comma().as_string(prop_id).Comma();
    }

    auto& label = node->as_string(prop_label);
    if (label.size())
    {
        if (node->HasValue(prop_shortcut))
        {
            code.QuotedString(tt_string() << label << '\t' << node->as_string(prop_shortcut));
        }
        else
        {
            code.QuotedString(label);
        }
    }
    else
    {
        code.Add("wxEmptyString");
    }

    if (code.HasValue(prop_help) || node->as_string(prop_kind) != "wxITEM_NORMAL")
    {
        code.Comma().CheckLineLength().QuotedString(prop_help).Comma().as_string(prop_kind);
    }
    code.EndFunction();

    return true;
}

bool MenuItemGenerator::SettingsCode(Code& code)
{
    Node* node = code.node();
    if (code.HasValue(prop_extra_accels) && code.is_cpp())
    {
        // auto_indent = indent::auto_keep_whitespace;
        code.OpenBrace().Add("wxAcceleratorEntry entry;").Eol();

        bool is_old_widgets = (Project.value(prop_wxWidgets_version) == "3.1");
        if (is_old_widgets)
        {
            code += "#if wxCHECK_VERSION(3, 1, 6)\n";
        }

        tt_string_vector accel_list(node->as_string(prop_extra_accels), "\"", tt::TRIM::both);
        for (auto& accel: accel_list)
        {
            // There are spaces between the quoted strings which will create an entry that we
            // need to ignore
            if (accel.size())
            {
                code.Eol(eol_if_needed) << "if (entry.FromString(" << GenerateQuotedString(accel) << "))";
                code.Eol().Tab().NodeName().Function("AddExtraAccel(entry").EndFunction();
            }
        }

        if (is_old_widgets)
        {
            code.Eol(eol_if_needed) += "#endif";
        }
        code.CloseBrace();
        code.UpdateBreakAt();
    }

    if (code.HasValue(prop_bitmap))
    {
        code.Eol(eol_if_empty);
        if (code.is_cpp())
        {
            auto& description = node->as_string(prop_bitmap);
            bool is_vector_code = GenerateVectorCode(description, code.GetCode());
            code.UpdateBreakAt();

            if (!is_vector_code)
            {
                code.NodeName().Function("SetBitmap(");
                if (Project.value(prop_wxWidgets_version) != "3.1")
                {
                    GenerateBundleCode(description, code.GetCode());
                    code.EndFunction();
                }
                else
                {
                    code.Eol() += "#if wxCHECK_VERSION(3, 1, 6)\n\t";
                    GenerateBundleCode(description, code.GetCode());
                    code.Eol() += "#else";
                    code.Eol().Tab() << "wxBitmap(" << GenerateBitmapCode(description) << ")";
                    code.Eol() += "#endif";
                    code.Eol().EndFunction();
                }
                code.Eol();
            }
            else
            {
                code.Tab().NodeName().Function("SetBitmap(");
                if (Project.value(prop_wxWidgets_version) != "3.1")
                {
                    code += "wxBitmapBundle::FromBitmaps(bitmaps)";
                    code.UpdateBreakAt();
                    code.EndFunction().CloseBrace();
                }
                else
                {
                    code += "\n#if wxCHECK_VERSION(3, 1, 6)\n\t";
                    code.Tab() += "wxBitmapBundle::FromBitmaps(bitmaps)";
                    code += "\n#else\n\t";
                    code.Tab() << "wxBitmap(" << GenerateBitmapCode(description) << ")\n";
                    code << "#endif\n";
                    code.UpdateBreakAt();
                    code.Tab().EndFunction().CloseBrace();
                }
            }
        }

        // wxPython version
        else
        {
            bool is_list_created = PythonBitmapList(code, prop_bitmap);
            code.NodeName().Function("SetBitmap(");
            if (is_list_created)
            {
                code += "wx.BitmapBundle.FromBitmaps(bitmaps)";
            }
            else
            {
                PythonBundleCode(code, prop_bitmap);
            }
            code.EndFunction();
        }
    }
    if (code.HasValue(prop_unchecked_bitmap))
    {
        code.Eol();
        code.AddComment("Set the unchecked bitmap").Eol();
        if (code.is_cpp())
        {
            auto& description = node->as_string(prop_unchecked_bitmap);
            bool is_vector_code = GenerateVectorCode(description, code.GetCode());
            code.UpdateBreakAt();

            if (!is_vector_code)
            {
                code.NodeName().Function("SetBitmap(");
                if (Project.value(prop_wxWidgets_version) != "3.1")
                {
                    GenerateBundleCode(description, code.GetCode());
                    code.UpdateBreakAt();
                    code.Comma() += "false";
                }
                else
                {
                    code += "\n#if wxCHECK_VERSION(3, 1, 6)\n\t";
                    GenerateBundleCode(description, code.GetCode());
                    code += "\n#else\n\t";
                    code << "wxBitmap(" << GenerateBitmapCode(description) << ", false)\n";
                    code << "#endif\n";
                }
                code.UpdateBreakAt();
                code.EndFunction();
            }
            else
            {
                code.Tab().NodeName().Function("SetBitmap(");
                if (Project.value(prop_wxWidgets_version) != "3.1")
                {
                    code += "wxBitmapBundle::FromBitmaps(bitmaps)";
                    code.UpdateBreakAt();
                    code.Comma() += "false";
                    code.EndFunction();
                    code += "\n}\n";
                }
                else
                {
                    code += "\n#if wxCHECK_VERSION(3, 1, 6)\n\t";
                    code.Tab() += "wxBitmapBundle::FromBitmaps(bitmaps), false";
                    code += "\n#else\n\t";
                    code.Tab() << "wxBitmap(" << GenerateBitmapCode(description) << ", false)\n";
                    code << "#endif\n";
                    code.UpdateBreakAt();
                    code.Tab().EndFunction();
                }
            }
        }

        // wxPython version
        else
        {
            code.Eol(eol_if_needed);
            bool is_list_created = PythonBitmapList(code, prop_unchecked_bitmap);
            code.NodeName().Function("SetBitmap(");
            if (is_list_created)
            {
                code += "wx.BitmapBundle.FromBitmaps(bitmaps)";
            }
            else
            {
                PythonBundleCode(code, prop_bitmap);
            }
            code.Comma() += "False";
            code.EndFunction();
        }
    }

    if (!node->GetParent()->isGen(gen_PopupMenu))
    {
        code.Eol(eol_if_empty).ParentName().Function("Append(").NodeName().EndFunction();
    }

    if ((node->as_string(prop_kind) == "wxITEM_CHECK" || node->as_string(prop_kind) == "wxITEM_RADIO") &&
        code.IsTrue(prop_checked))
    {
        code.Eol(eol_if_empty).NodeName().Function("Check(").EndFunction();
    }

    return true;
}

bool MenuItemGenerator::GetIncludes(Node* node, std::set<std::string>& set_src, std::set<std::string>& set_hdr)
{
    InsertGeneratorInclude(node, "#include <wx/menu.h>", set_src, set_hdr);
    if (node->HasValue(prop_extra_accels))
    {
        InsertGeneratorInclude(node, "#include <wx/accel.h>", set_src, set_hdr);
    }

    return true;
}

int MenuItemGenerator::GenXrcObject(Node* node, pugi::xml_node& object, size_t xrc_flags)
{
    auto result = node->GetParent()->IsSizer() ? BaseGenerator::xrc_sizer_item_created : BaseGenerator::xrc_updated;
    auto item = InitializeXrcObject(node, object);

    GenXrcObjectAttributes(node, item, "wxMenuItem");

    ADD_ITEM_PROP(prop_label, "label")
    ADD_ITEM_PROP(prop_shortcut, "accel")
    if (node->HasValue(prop_extra_accels))
    {
        auto child = item.append_child("extra-accels");
        tt_string_vector accel_list(node->as_string(prop_extra_accels), "\"", tt::TRIM::both);
        for (auto& accel: accel_list)
        {
            // There are spaces between the quoted strings which will create an entry that we
            // need to ignore
            if (accel.size())
                child.append_child("accel").text().set(accel);
        }
    }
    ADD_ITEM_PROP(prop_help, "help")
    ADD_ITEM_BOOL(prop_checked, "checked")
    if (node->as_bool(prop_disabled))
        item.append_child("enabled").text().set("0");

    if (node->value(prop_kind) == "wxITEM_RADIO")
        item.append_child("radio").text().set("1");
    else if (node->value(prop_kind) == "wxITEM_CHECK")
        item.append_child("checkable").text().set("1");

    GenXrcBitmap(node, item, xrc_flags);

    if (xrc_flags & xrc::add_comments)
    {
        GenXrcComments(node, item);
    }

    return result;
}
