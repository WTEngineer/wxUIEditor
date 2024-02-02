///////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor - see https://github.com/KeyWorksRW/wxUiEditor/
//
// Do not edit any code above the "End of generated code" comment block.
// Any changes before that block will be lost if it is re-generated!
///////////////////////////////////////////////////////////////////////////////

// clang-format off

#include <wx/colour.h>
#include <wx/font.h>
#include <wx/settings.h>
#include <wx/sizer.h>
#include <wx/stattext.h>

#include "xrccompare.h"

bool XrcCompare::Create(wxWindow* parent, wxWindowID id, const wxString& title,
    const wxPoint& pos, const wxSize& size, long style, const wxString &name)
{
    if (!wxDialog::Create(parent, id, title, pos, size, style, name))
        return false;

    m_grid_bag_sizer = new wxGridBagSizer();

    auto* box_sizer = new wxBoxSizer(wxVERTICAL);

    auto* staticText = new wxStaticText(this, wxID_ANY, "C++ Generated");
    {
        wxFontInfo font_info(9);
        font_info.Underlined();
        staticText->SetFont(wxFont(font_info));
    }
    staticText->SetForegroundColour(wxColour("#FF0000"));
    box_sizer->Add(staticText, wxSizerFlags().Border(wxALL));

    m_grid_bag_sizer->Add(box_sizer, wxGBPosition(0, 0), wxGBSpan(1, 1), wxTOP|wxRIGHT|wxLEFT, 5);

    m_static_line = new wxStaticLine(this, wxID_ANY, wxDefaultPosition, ConvertDialogToPixels(wxSize(-1, 100)), wxLI_VERTICAL);
    m_grid_bag_sizer->Add(m_static_line, wxGBPosition(0, 1), wxGBSpan(3, 1), wxALL, 5);

    auto* box_sizer_2 = new wxBoxSizer(wxVERTICAL);

    auto* staticText_2 = new wxStaticText(this, wxID_ANY, "XRC Generated");
    {
        wxFontInfo font_info(9);
        font_info.Underlined();
        staticText_2->SetFont(wxFont(font_info));
    }
    staticText_2->SetForegroundColour(wxColour("#008000"));
    box_sizer_2->Add(staticText_2, wxSizerFlags().Border(wxALL));

    m_grid_bag_sizer->Add(box_sizer_2, wxGBPosition(0, 2), wxGBSpan(1, 1), wxTOP|wxRIGHT|wxLEFT, 5);

    SetSizerAndFit(m_grid_bag_sizer);
    Centre(wxBOTH);

    return true;
}

// ************* End of generated code ***********
// DO NOT EDIT THIS COMMENT BLOCK!
//
// Code below this comment block will be preserved
// if the code for this class is re-generated.
//
// clang-format on
// ***********************************************

/////////////////// Non-generated Copyright/License Info ////////////////////
// Purpose:   C++/XRC UI Comparison dialog
// Author:    Ralph Walden
// Copyright: Copyright (c) 2022 KeyWorks Software (Ralph Walden)
// License:   Apache License -- see ../../LICENSE
/////////////////////////////////////////////////////////////////////////////

#include <wx/mstream.h>           // Memory stream classes
#include <wx/persist.h>           // common classes for persistence support
#include <wx/persist/toplevel.h>  // persistence support for wxTLW
#include <wx/stattext.h>          // wxStaticText base header
#include <wx/xml/xml.h>           // wxXmlDocument - XML parser & data holder class
#include <wx/xrc/xmlres.h>        // XML resources

// The following handlers must be explicitly added

#include <wx/xrc/xh_aui.h>             // XRC resource handler for wxAUI
#include <wx/xrc/xh_auitoolb.h>        // XML resource handler for wxAuiToolBar
#include <wx/xrc/xh_ribbon.h>          // XML resource handler for wxRibbon related classes
#include <wx/xrc/xh_richtext.h>        // XML resource handler for wxRichTextCtrl
#include <wx/xrc/xh_styledtextctrl.h>  // XML resource handler for wxStyledTextCtrl

#include "mainframe.h"  // MainFrame -- Main window frame
#include "node.h"       // Node class

// Defined in mockup_preview.cpp
void CreateMockupChildren(Node* node, wxWindow* parent, wxObject* parentNode, wxSizer* parent_sizer, wxWindow* form_window);

// Defined in gen_xrc.cpp
std::string GenerateXrcStr(Node* node_start, size_t xrc_flags);

extern const char* txt_dlg_name;

XrcCompare::~XrcCompare()
{
    if (m_created)
        wxXmlResource::Get()->Unload(m_res_name);
}

bool XrcCompare::DoCreate(wxWindow* parent, Node* form_node)
{
    if (!Create(parent, wxID_ANY, "Compare C++/XRC Generated UI", wxDefaultPosition, wxDefaultSize,
                wxDEFAULT_DIALOG_STYLE | wxRESIZE_BORDER))
        return false;

        // Everything below up to the customization section is a direct copy of the XrcCompareBase::Create() function
#if 0
    m_grid_bag_sizer = new wxGridBagSizer();

    auto* staticText = new wxStaticText(this, wxID_ANY, "C++ Generated");
    m_grid_bag_sizer->Add(staticText, wxGBPosition(0, 0), wxGBSpan(1, 1), wxALL, 5);

    m_static_line =
        new wxStaticLine(this, wxID_ANY, wxDefaultPosition, ConvertDialogToPixels(wxSize(-1, 100)), wxLI_VERTICAL);
    m_grid_bag_sizer->Add(m_static_line, wxGBPosition(0, 1), wxGBSpan(2, 1), wxALL, 5);

    auto* staticText_2 = new wxStaticText(this, wxID_ANY, "XRC Generated");
    m_grid_bag_sizer->Add(staticText_2, wxGBPosition(0, 2), wxGBSpan(1, 1), wxALL, 5);
#endif
    // Customization section

    // TODO: [KeyWorks - 06-09-2022] Add the C++ and XRC top level sizers here

    m_created = true;

    auto xrc_resource = wxXmlResource::Get();
    xrc_resource->InitAllHandlers();
    xrc_resource->AddHandler(new wxRichTextCtrlXmlHandler);
    xrc_resource->AddHandler(new wxAuiXmlHandler);
    xrc_resource->AddHandler(new wxAuiToolBarXmlHandler);
    xrc_resource->AddHandler(new wxRibbonXmlHandler);
    xrc_resource->AddHandler(new wxStyledTextCtrlXmlHandler);
    m_res_name = "wxuiCompare";

    switch (form_node->getGenName())
    {
        case gen_PanelForm:
            {
                CreateMockupChildren(form_node, this, nullptr, m_grid_bag_sizer, this);

                if (!InitXrc(form_node))
                    return false;

                if (auto object = xrc_resource->LoadObject(this, form_node->as_string(prop_class_name), "wxPanel"); object)
                {
                    m_grid_bag_sizer->Add(wxStaticCast(object, wxPanel), wxGBPosition(1, 2), wxGBSpan(1, 1), wxALL, 5);
                }
                else
                {
                    wxMessageBox("Could not load XRC wxPanel", "Compare");
                    return false;
                }
            }
            break;

        case gen_wxDialog:
            {
                if (form_node->getChildCount() < 1)
                {
                    wxMessageBox("Only a dialog's children can be shown -- this dialog has none.", "Compare");
                    return false;
                }

                // The wxDialog generator will create a wxPanel as the mockup
                CreateMockupChildren(form_node, this, nullptr, m_grid_bag_sizer, this);

                // In theory, we should be able to start from the sizer and pass that to m_grid_bag_sizer. In practice, it
                // causes wxWidgets to crash. I'm not sure why, but setting both the C++ and XRC generators to use wxPanel
                // solves the problem.

                // GenerateXrcStr will return a wxPanel using the name txt_dlg_name ("_wxue_temp_dlg")
                if (!InitXrc(form_node))
                    return false;

                if (auto object = xrc_resource->LoadObject(this, txt_dlg_name, "wxPanel"); object)
                {
                    m_grid_bag_sizer->Add(wxStaticCast(object, wxPanel), wxGBPosition(1, 2), wxGBSpan(1, 1), wxALL, 5);
                }
                else
                {
                    wxMessageBox("Could not load top level sizer", "Compare");
                    return false;
                }
            }
            break;

        default:
            wxMessageBox("This form is not supported yet...", "Compare");
            return false;
    }

    SetSizerAndFit(m_grid_bag_sizer);
    // Centre(wxBOTH);
    // Fit();

    wxPersistentRegisterAndRestore(this, "XrcCompare");

    return true;
}

bool XrcCompare::InitXrc(Node* form_node)
{
    size_t xrc_flags = (form_node->isGen(gen_wxDialog) ? xrc::previewing : 0);
    auto doc_str = GenerateXrcStr(form_node, xrc_flags);
    wxMemoryInputStream stream(doc_str.c_str(), doc_str.size());
    auto xmlDoc = std::make_unique<wxXmlDocument>(stream);
    if (!xmlDoc->IsOk())
    {
        wxMessageBox("Invalid XRC file generated -- it cannot be loaded.", "Compare");
        return false;
    }
    if (!wxXmlResource::Get()->LoadDocument(xmlDoc.release(), m_res_name))
    {
        wxMessageBox("wxWidgets could not parse the XRC data.", "Compare");
        return false;
    }

    return true;
}
