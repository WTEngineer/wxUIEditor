/////////////////////////////////////////////////////////////////////////////
// Purpose:   Text component classes
// Author:    Ralph Walden
// Copyright: Copyright (c) 2020-2021 KeyWorks Software (Ralph Walden)
// License:   Apache License -- see ../../LICENSE
/////////////////////////////////////////////////////////////////////////////

#ifdef _MSC_VER
    #pragma warning(push)

    #pragma warning(disable : 4267)  // conversion from 'size_t' to 'int', possible loss of data
#endif

#include <wx/event.h>                  // Event classes
#include <wx/html/htmlwin.h>           // wxHtmlWindow class for parsing & displaying HTML
#include <wx/propgrid/manager.h>       // wxPropertyGridManager
#include <wx/propgrid/propgrid.h>      // wxPropertyGrid
#include <wx/richtext/richtextctrl.h>  // A rich edit control
#include <wx/stattext.h>               // wxStaticText base header
#include <wx/stc/stc.h>                // A wxWidgets implementation of Scintilla.
#include <wx/webview.h>                // Common interface and events for web view component

#ifdef _MSC_VER
    #pragma warning(pop)
#endif

#include "text_widgets.h"

#include "gen_common.h"  // GeneratorLibrary -- Generator classes
#include "node.h"        // Node class
#include "utils.h"       // Utility functions that work with properties

wxObject* StaticTextGenerator::CreateMockup(Node* node, wxObject* parent)
{
    auto widget = new wxStaticText(wxStaticCast(parent, wxWindow), wxID_ANY, wxEmptyString, DlgPoint(parent, node, prop_pos),
                                   DlgSize(parent, node, prop_size), GetStyleInt(node));

    if (node->prop_as_bool(prop_markup))
        widget->SetLabelMarkup(node->prop_as_wxString(prop_label));
    else
        widget->SetLabel(node->prop_as_wxString(prop_label));

    if (node->prop_as_int(prop_wrap) > 0)
        widget->Wrap(node->prop_as_int(prop_wrap));

    widget->Bind(wxEVT_LEFT_DOWN, &BaseGenerator::OnLeftClick, this);

    return widget;
}

bool StaticTextGenerator::OnPropertyChange(wxObject* widget, Node* node, NodeProperty* prop)
{
    if (prop->isProp(prop_wrap) || prop->isProp(prop_label) || prop->isProp(prop_markup))
    {
        // If the text was wrapped previously, then it already has \n characters inserted in it, so we need to restore
        // it to it's original state before wrapping again.

        auto ctrl = wxStaticCast(widget, wxStaticText);
        if (node->prop_as_bool(prop_markup))
            ctrl->SetLabelMarkup(node->prop_as_wxString(prop_label));
        else
            ctrl->SetLabel(node->prop_as_wxString(prop_label));

        if (node->prop_as_int(prop_wrap) > 0)
            ctrl->Wrap(node->prop_as_int(prop_wrap));

        return true;
    }

    return false;
}

std::optional<ttlib::cstr> StaticTextGenerator::GenConstruction(Node* node)
{
    ttlib::cstr code;
    if (node->IsLocal())
        code << "auto ";
    code << node->get_node_name() << GenerateNewAssignment(node);

    code << GetParentName(node) << ", " << node->prop_as_string(prop_id) << ", ";

    // If the label is going to be set via SetLabelMarkup(), then there is no reason to initialize it here and then
    // replace it on the next line of code (which will be the call to SetLabelMarkUp())
    if (node->prop_as_bool(prop_markup))
    {
        code << "wxEmptyString";
    }
    else
    {
        auto& label = node->prop_as_string(prop_label);
        if (label.size())
        {
            code << GenerateQuotedString(label);
        }
        else
        {
            code << "wxEmptyString";
        }
    }

    GeneratePosSizeFlags(node, code);

    return code;
}

std::optional<ttlib::cstr> StaticTextGenerator::GenEvents(NodeEvent* event, const std::string& class_name)
{
    return GenEventCode(event, class_name);
}

std::optional<ttlib::cstr> StaticTextGenerator::GenSettings(Node* node, size_t& /* auto_indent */)
{
    ttlib::cstr code;
    if (node->prop_as_bool(prop_markup))
    {
        if (code.size())
            code << '\n';
        code << node->get_node_name() << "->SetLabelMarkup(" << GenerateQuotedString(node->prop_as_string(prop_label))
             << ");";
    }

    // Note that wrap MUST be called after the text is set, otherwise it will be ignored.
    if (node->prop_as_int(prop_wrap) > 0)
    {
        if (code.size())
            code << '\n';
        code << node->get_node_name() << "->Wrap(" << node->prop_as_string(prop_wrap) << ");";
    }
    return code;
}

bool StaticTextGenerator::GetIncludes(Node* node, std::set<std::string>& set_src, std::set<std::string>& set_hdr)
{
    InsertGeneratorInclude(node, "#include <wx/stattext.h>", set_src, set_hdr);
    if (node->prop_as_string(prop_validator_variable).size())
        InsertGeneratorInclude(node, "#include <wx/valgen.h>", set_src, set_hdr);

    return true;
}

//////////////////////////////////////////  TextCtrlGenerator  //////////////////////////////////////////

wxObject* TextCtrlGenerator::CreateMockup(Node* node, wxObject* parent)
{
    auto widget = new wxTextCtrl(wxStaticCast(parent, wxWindow), wxID_ANY, node->prop_as_wxString(prop_value),
                                 DlgPoint(parent, node, prop_pos), DlgSize(parent, node, prop_size), GetStyleInt(node));

    widget->SetMaxLength(node->prop_as_int(prop_maxlength));

    if (node->HasValue(prop_auto_complete))
    {
        auto array = ConvertToWxArrayString(node->prop_as_string(prop_auto_complete));
        widget->AutoComplete(array);
    }

    if (node->HasValue(prop_hint))
        widget->SetHint(node->prop_as_wxString(prop_hint));

    if (node->prop_as_string(prop_spellcheck).contains("enabled"))
    {
        if (node->prop_as_string(prop_spellcheck).contains("grammar"))
            widget->EnableProofCheck(wxTextProofOptions::Default().GrammarCheck());
        else
            widget->EnableProofCheck(wxTextProofOptions::Default());
    }

    widget->Bind(wxEVT_LEFT_DOWN, &BaseGenerator::OnLeftClick, this);

    return widget;
}

bool TextCtrlGenerator::OnPropertyChange(wxObject* widget, Node* /* node */, NodeProperty* prop)
{
    if (prop->isProp(prop_value))
    {
        wxStaticCast(widget, wxTextCtrl)->SetValue(prop->as_wxString());
        return true;
    }

    return false;
}

std::optional<ttlib::cstr> TextCtrlGenerator::GenConstruction(Node* node)
{
    ttlib::cstr code;
    if (node->IsLocal())
        code << "auto ";
    code << node->get_node_name() << GenerateNewAssignment(node);

    code << GetParentName(node) << ", " << node->prop_as_string(prop_id) << ", ";
    if (node->prop_as_string(prop_value).size())
        code << GenerateQuotedString(node->prop_as_string(prop_value));
    else
        code << "wxEmptyString";

    if (node->prop_as_string(prop_window_name).empty())
        GeneratePosSizeFlags(node, code);
    else
    {
        // We have to generate a default validator before the window name, which GeneratePosSizeFlags doesn't do. We don't
        // actually need that validator, since GenSettings will create it, but we have to supply something before the window
        // name.

        code << ", ";
        GenPos(node, code);
        code << ", ";
        GenSize(node, code);
        code << ", ";
        GenStyle(node, code);
        code << ", wxDefaultValidator, " << node->prop_as_string(prop_window_name);
        code << ");";
    }

    return code;
}

std::optional<ttlib::cstr> TextCtrlGenerator::GenSettings(Node* node, size_t& auto_indent)
{
    ttlib::cstr code;

    if (node->HasValue(prop_hint))
    {
        if (code.size())
            code << '\n';
        code << node->get_node_name() << "->SetHint(" << GenerateQuotedString(node->prop_as_string(prop_hint)) << ");";
    }

    if (node->prop_as_bool(prop_focus))
    {
        if (code.size())
            code << '\n';
        code << node->get_node_name() << "->SetFocus()";
    }

    if (node->prop_as_bool(prop_maxlength))
    {
        if (code.size())
            code << '\n';
        if (node->prop_as_string(prop_style).contains("wxTE_MULTILINE"))
        {
            code << "#if !defined(__WXGTK__))\n\t";
            code << node->get_node_name() << "->SetMaxLength(" << node->prop_as_string(prop_maxlength) << ");\n";
            code << "#endif";
            auto_indent = false;
        }
        else
        {
            code << node->get_node_name() << "->SetMaxLength(" << node->prop_as_string(prop_maxlength) << ");";
        }
    }

    if (node->HasValue(prop_auto_complete))
    {
        auto_indent = false;
        code << "\t{\n\t\twxArrayString tmp_array;\n";
        auto array = ConvertToArrayString(node->prop_as_string(prop_auto_complete));
        for (auto& iter: array)
        {
            code << "\t\ttmp_array.push_back(wxString::FromUTF8(\"" << iter << "\"));\n";
        }
        code << "\t\t" << node->get_node_name() << "->AutoComplete(tmp_array);\n";
        code << "\t}";
    }

    if (node->prop_as_string(prop_spellcheck).contains("enabled"))
    {
        if (wxGetProject().prop_as_string(prop_wxWidgets_version) == "3.1")
        {
            code << "\n#if wxCHECK_VERSION(3, 1, 6)\n\t";
            code << node->get_node_name() << "->EnableProofCheck(wxTextProofOptions::Default()";
            if (node->prop_as_string(prop_spellcheck).contains("grammar"))
                code << ".GrammarCheck()";
            code << ");";
            code << "\n#endif";
        }
        else
        {
            code << node->get_node_name() << "->EnableProofCheck(wxTextProofOptions::Default()";
            if (node->prop_as_string(prop_spellcheck).contains("grammar"))
                code << ".GrammarCheck()";
            code << ");";
        }
    }

    return code;
}

std::optional<ttlib::cstr> TextCtrlGenerator::GenEvents(NodeEvent* event, const std::string& class_name)
{
    return GenEventCode(event, class_name);
}

bool TextCtrlGenerator::GetIncludes(Node* node, std::set<std::string>& set_src, std::set<std::string>& set_hdr)
{
    InsertGeneratorInclude(node, "#include <wx/textctrl.h>", set_src, set_hdr);
    if (node->prop_as_string(prop_validator_variable).size())
    {
        if (node->prop_as_string(prop_validator_type) == "wxGenericValidator")
            InsertGeneratorInclude(node, "#include <wx/valgen.h>", set_src, set_hdr);
        else
            InsertGeneratorInclude(node, "#include <wx/valtext.h>", set_src, set_hdr);
    }

    return true;
}

void TextCtrlGenerator::ChangeEnableState(wxPropertyGridManager* prop_grid, NodeProperty* changed_prop)
{
    if (changed_prop->isProp(prop_spellcheck))
    {
        if (auto pg_parent = prop_grid->GetProperty("spellcheck"); pg_parent)
        {
            for (unsigned int idx = 0; idx < pg_parent->GetChildCount(); ++idx)
            {
                if (auto pg_setting = pg_parent->Item(idx); pg_setting)
                {
                    auto label = pg_setting->GetLabel();
                    if (label == "grammar")
                    {
                        pg_setting->Enable(changed_prop->as_string().contains("enabled"));
                    }
                }
            }
        }
    }
    else
    {
        BaseGenerator::ChangeEnableState(prop_grid, changed_prop);
    }
}

//////////////////////////////////////////  RichTextCtrlGenerator  //////////////////////////////////////////
wxObject* RichTextCtrlGenerator::CreateMockup(Node* node, wxObject* parent)
{
    auto widget = new wxRichTextCtrl(wxStaticCast(parent, wxWindow), wxID_ANY, node->prop_as_wxString(prop_value),
                                     DlgPoint(parent, node, prop_pos), DlgSize(parent, node, prop_size),
                                     GetStyleInt(node) | wxRE_MULTILINE);

    if (node->HasValue(prop_hint))
        widget->SetHint(node->prop_as_wxString(prop_hint));

    widget->Bind(wxEVT_LEFT_DOWN, &BaseGenerator::OnLeftClick, this);

    return widget;
}

std::optional<ttlib::cstr> RichTextCtrlGenerator::GenConstruction(Node* node)
{
    ttlib::cstr code;
    if (node->IsLocal())
        code << "auto ";
    code << node->get_node_name() << GenerateNewAssignment(node);

    code << GetParentName(node) << ", " << node->prop_as_string(prop_id) << ", ";
    if (node->prop_as_string(prop_value).size())
        code << GenerateQuotedString(node->prop_as_string(prop_value));
    else
        code << "wxEmptyString";

    if (node->prop_as_string(prop_window_name).empty())
        GeneratePosSizeFlags(node, code);
    else
    {
        // We have to generate a default validator before the window name, which GeneratePosSizeFlags doesn't do. We don't
        // actually need that validator, but we have to supply something before the window name.

        code << ", ";
        GenPos(node, code);
        code << ", ";
        GenSize(node, code);
        code << ", ";
        GenStyle(node, code);
        code << ", wxDefaultValidator, " << node->prop_as_string(prop_window_name);
        code << ");";
    }

    return code;
}

std::optional<ttlib::cstr> RichTextCtrlGenerator::GenSettings(Node* node, size_t& /* auto_indent */)
{
    ttlib::cstr code;

    if (node->HasValue(prop_hint))
    {
        if (code.size())
            code << '\n';
        code << node->get_node_name() << "->SetHint(" << GenerateQuotedString(node->prop_as_string(prop_hint)) << ");";
    }

    if (node->prop_as_bool(prop_focus))
    {
        if (code.size())
            code << '\n';
        code << node->get_node_name() << "->SetFocus()";
    }

    if (code.size())
        return code;
    else

        return {};
}

std::optional<ttlib::cstr> RichTextCtrlGenerator::GenEvents(NodeEvent* event, const std::string& class_name)
{
    return GenEventCode(event, class_name);
}

bool RichTextCtrlGenerator::GetIncludes(Node* node, std::set<std::string>& set_src, std::set<std::string>& set_hdr)
{
    InsertGeneratorInclude(node, "#include <wx/richtext/richtextctrl.h>", set_src, set_hdr);
    return true;
}

//////////////////////////////////////////  HtmlWindowGenerator  //////////////////////////////////////////

wxObject* HtmlWindowGenerator::CreateMockup(Node* node, wxObject* parent)
{
    auto widget = new wxHtmlWindow(wxStaticCast(parent, wxWindow), wxID_ANY, DlgPoint(parent, node, prop_pos),
                                   DlgSize(parent, node, prop_size), GetStyleInt(node));

    if (node->HasValue(prop_html_content))
    {
        widget->SetPage(node->prop_as_wxString(prop_html_content));
    }
    else
    {
        widget->SetPage("<b>wxHtmlWindow</b><br/><br/>This is a dummy page.</body></html>");
    }

    widget->Bind(wxEVT_LEFT_DOWN, &BaseGenerator::OnLeftClick, this);

    return widget;
}

std::optional<ttlib::cstr> HtmlWindowGenerator::GenConstruction(Node* node)
{
    ttlib::cstr code;
    if (node->IsLocal())
        code << "auto ";
    code << node->get_node_name() << GenerateNewAssignment(node);

    code << GetParentName(node) << ", " << node->prop_as_string(prop_id);

    GeneratePosSizeFlags(node, code);
    code.Replace(", wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHW_SCROLLBAR_AUTO)", ")");

    return code;
}

std::optional<ttlib::cstr> HtmlWindowGenerator::GenSettings(Node* node, size_t& /* auto_indent */)
{
    ttlib::cstr code;

    if (node->HasValue(prop_html_content))
    {
        if (code.size())
            code << '\n';
        code << node->get_node_name() << "->SetPage(" << GenerateQuotedString(node->prop_as_string(prop_html_content))
             << ");\n";
    }

    if (code.size())
        return code;
    else

        return {};
}

std::optional<ttlib::cstr> HtmlWindowGenerator::GenEvents(NodeEvent* event, const std::string& class_name)
{
    return GenEventCode(event, class_name);
}

bool HtmlWindowGenerator::GetIncludes(Node* node, std::set<std::string>& set_src, std::set<std::string>& set_hdr)
{
    InsertGeneratorInclude(node, "#include <wx/html/htmlwin.h>", set_src, set_hdr);
    return true;
}

//////////////////////////////////////////  WebViewGenerator  //////////////////////////////////////////

#if !wxUSE_WEBVIEW_WEBKIT && !wxUSE_WEBVIEW_WEBKIT2 && !wxUSE_WEBVIEW_IE
    #error "A wxWebView backend is for the wxWebView Mockup"
#endif

wxObject* WebViewGenerator::CreateMockup(Node* node, wxObject* parent)
{
    auto widget = wxWebView::New(wxStaticCast(parent, wxWindow), wxID_ANY, node->prop_as_string(prop_url).wx_str(),
                                 DlgPoint(parent, node, prop_pos), DlgSize(parent, node, prop_size), wxWebViewBackendDefault,
                                 GetStyleInt(node));

    return widget;
}

std::optional<ttlib::cstr> WebViewGenerator::GenConstruction(Node* node)
{
    ttlib::cstr code;
    if (node->IsLocal())
        code << "auto ";
    code << node->get_node_name() << " = wxWebView::New(";

    code << GetParentName(node) << ", " << node->prop_as_string(prop_id) << ", "
         << GenerateQuotedString(node->prop_as_string(prop_url));

    bool isPosSet { false };
    auto pos = node->prop_as_wxPoint(prop_pos);
    if (pos.x != -1 || pos.y != -1)
    {
        code << ", wxPoint(" << pos.x << ", " << pos.y << ")";
        isPosSet = true;
    }

    auto size = node->prop_as_wxSize(prop_size);
    if (size.x != -1 || size.y != -1)
    {
        if (!isPosSet)
        {
            code << ", wxDefaultPosition";
            isPosSet = true;
        }
        code << ", wxSize(" << size.x << ", " << size.y << ")";
    }

    ttlib::cstr all_styles;
    GenStyle(node, all_styles);
    if (all_styles.is_sameas("0"))
        all_styles.clear();

    if (all_styles.size())
    {
        code << ", wxWebViewBackendDefault, " << all_styles;
    }

    code << ");";

    return code;
}

std::optional<ttlib::cstr> WebViewGenerator::GenEvents(NodeEvent* event, const std::string& class_name)
{
    if ((event->get_name() == "wxEVT_WEBVIEW_FULL_SCREEN_CHANGED" ||
         event->get_name() == "wxEVT_WEBVIEW_SCRIPT_MESSAGE_RECEIVED") &&
        wxGetProject().prop_as_string(prop_wxWidgets_version) == "3.1")
    {
        ttlib::cstr code("\n#if wxCHECK_VERSION(3, 1, 5)\n");
        code << GenEventCode(event, class_name);
        code << "\n#endif";
        return code;
    }
    else
    {
        return GenEventCode(event, class_name);
    }
}

bool WebViewGenerator::GetIncludes(Node* node, std::set<std::string>& set_src, std::set<std::string>& set_hdr)
{
    InsertGeneratorInclude(node, "#include <wx/webview.h>", set_src, set_hdr);
    return true;
}
