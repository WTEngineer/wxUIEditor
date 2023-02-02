///////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor - see https://github.com/KeyWorksRW/wxUiEditor/
//
// Do not edit any code above the "End of generated code" comment block.
// Any changes before that block will be lost if it is re-generated!
///////////////////////////////////////////////////////////////////////////////

// clang-format off

#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/valgen.h>

#include "node_search_dlg.h"

bool NodeSearchDlg::Create(wxWindow* parent, wxWindowID id, const wxString& title,
    const wxPoint& pos, const wxSize& size, long style, const wxString &name)
{
    if (!wxDialog::Create(parent, id, title, pos, size, style, name))
        return false;

    auto* dlg_sizer = new wxBoxSizer(wxVERTICAL);

    auto* box_sizer_2 = new wxBoxSizer(wxHORIZONTAL);
    box_sizer_2->SetMinSize(250, 400);

    auto* box_sizer = new wxBoxSizer(wxVERTICAL);

    m_radio_generators = new wxRadioButton(this, wxID_ANY, "Search generators");
    m_radio_generators->SetValidator(wxGenericValidator(&m_search_generators));
    auto* static_box = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, m_radio_generators), wxVERTICAL);

    m_combo_generators = new wxComboBox(static_box->GetStaticBox(), wxID_ANY, wxEmptyString,
        wxDefaultPosition, wxDefaultSize, 0, nullptr, wxCB_SORT);
    m_combo_generators->SetFocus();
    m_combo_generators->SetValidator(wxGenericValidator(&m_gen_name));
    m_combo_generators->SetMinSize(ConvertDialogToPixels(wxSize(100, -1)));
    static_box->Add(m_combo_generators, wxSizerFlags().Border(wxALL));

    box_sizer->Add(static_box, wxSizerFlags().Expand().Border(wxALL));

    m_radio_var_names = new wxRadioButton(this, wxID_ANY, "Search var_names");
    m_radio_var_names->SetValidator(wxGenericValidator(&m_search_varnames));
    auto* static_box_2 = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, m_radio_var_names), wxVERTICAL);

    m_combo_variables = new wxComboBox(static_box_2->GetStaticBox(), wxID_ANY, wxEmptyString,
        wxDefaultPosition, wxDefaultSize, 0, nullptr, wxCB_SORT);
    m_combo_variables->SetValidator(wxGenericValidator(&m_var_name));
    m_combo_variables->SetMinSize(ConvertDialogToPixels(wxSize(100, -1)));
    static_box_2->Add(m_combo_variables, wxSizerFlags().Border(wxALL));

    box_sizer->Add(static_box_2, wxSizerFlags().Expand().Border(wxALL));

    m_radio_labels = new wxRadioButton(this, wxID_ANY, "Search labels");
    m_radio_labels->SetValidator(wxGenericValidator(&m_search_labels));
    auto* static_box_3 = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, m_radio_labels), wxVERTICAL);

    m_combo_labels = new wxComboBox(static_box_3->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition,
        wxDefaultSize, 0, nullptr, wxCB_SORT);
    m_combo_labels->SetValidator(wxGenericValidator(&m_label_name));
    m_combo_labels->SetMinSize(ConvertDialogToPixels(wxSize(100, -1)));
    m_combo_labels->SetMaxSize(ConvertDialogToPixels(wxSize(100, -1)));
    static_box_3->Add(m_combo_labels, wxSizerFlags().Border(wxALL));

    box_sizer->Add(static_box_3, wxSizerFlags().Expand().Border(wxALL));

    box_sizer_2->Add(box_sizer, wxSizerFlags().Expand().Border(wxALL));

    m_scintilla = new wxStyledTextCtrl(this);
    {
        m_scintilla->SetLexer(wxSTC_LEX_CPP);
        m_scintilla->SetEOLMode(wxSTC_EOL_LF);
        // Sets text margin scaled appropriately for the current DPI on Windows,
        // 5 on wxGTK or wxOSX
        m_scintilla->SetMarginLeft(wxSizerFlags::GetDefaultBorder());
        m_scintilla->SetMarginRight(wxSizerFlags::GetDefaultBorder());
        m_scintilla->SetMarginWidth(1, 0); // Remove default margin
        m_scintilla->SetBackSpaceUnIndents(true);
    }
    m_scintilla->SetMinSize(ConvertDialogToPixels(wxSize(120, -1)));
    box_sizer_2->Add(m_scintilla, wxSizerFlags(1).Expand().Border(wxALL));

    dlg_sizer->Add(box_sizer_2, wxSizerFlags(1).Expand().Border(wxALL));

    auto* stdBtn = CreateStdDialogButtonSizer(wxOK|wxCANCEL);
    dlg_sizer->Add(CreateSeparatedSizer(stdBtn), wxSizerFlags().Expand().Border(wxALL));

    SetSizerAndFit(dlg_sizer);
    Centre(wxBOTH);

    // Event handlers
    Bind(wxEVT_INIT_DIALOG, &NodeSearchDlg::OnInit, this);
    m_radio_generators->Bind(wxEVT_RADIOBUTTON, &NodeSearchDlg::OnRadioSearchGenerators, this);
    m_radio_var_names->Bind(wxEVT_RADIOBUTTON, &NodeSearchDlg::OnRadioSearchVarNames, this);
    m_radio_labels->Bind(wxEVT_RADIOBUTTON, &NodeSearchDlg::OnRadioSearchLabels, this);

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
// Purpose:   Dialog to search for a node
// Author:    Ralph Walden
// Copyright: Copyright (c) 2022 KeyWorks Software (Ralph Walden)
// License:   Apache License -- see ../../LICENSE
/////////////////////////////////////////////////////////////////////////////

#include <set>  // std::set

#include "mainframe.h"         // MainFrame -- Main window frame
#include "node.h"              // Node class
#include "panels/nav_panel.h"  // NavigationPanel -- Node tree class

Node* FindNodeByGenerator(Node* node, GenEnum::GenName gen_name)
{
    if (node->isGen(gen_name))
        return node;

    for (auto& child: node->GetChildNodePtrs())
    {
        auto result = FindNodeByGenerator(child.get(), gen_name);
        if (result)
            return result;
    }

    return nullptr;
}

Node* FindNodeByVarName(Node* node, const std::string& var_name)
{
    if (node->HasValue(prop_var_name) && node->as_string(prop_var_name) == var_name)
        return node;

    for (auto& child: node->GetChildNodePtrs())
    {
        auto result = FindNodeByVarName(child.get(), var_name);
        if (result)
            return result;
    }

    return nullptr;
}

Node* FindNodeByLabel(Node* node, const std::string& label_name)
{
    if (node->HasValue(prop_label) && node->as_string(prop_label) == label_name)
        return node;

    for (auto& child: node->GetChildNodePtrs())
    {
        auto result = FindNodeByLabel(child.get(), label_name);
        if (result)
            return result;
    }

    return nullptr;
}

void MainFrame::OnFindWidget(wxCommandEvent& WXUNUSED(event))
{
    NodeSearchDlg dlg(this);
    if (dlg.ShowModal() == wxID_OK)
    {
        auto start_node = GetSelectedNode();
        if (dlg.isSearchGenerators() && start_node)
        {
            auto gen = rmap_GenNames[dlg.get_GenName().ToStdString()];
            auto node = FindNodeByGenerator(start_node, gen);
            if (node)
            {
                SelectNode(node);
                m_nav_panel->SetFocus();
            }
            else
            {
                wxMessageBox(wxString() << "Unable to find " << dlg.get_GenName());
            }
        }
        else if (dlg.isSearchVarnames() && start_node)
        {
            auto var_name = dlg.get_VarName().ToStdString();
            auto node = FindNodeByVarName(start_node, var_name);
            if (node)
            {
                SelectNode(node);
                m_nav_panel->SetFocus();
            }
            else
            {
                wxMessageBox(wxString() << "Unable to find " << dlg.get_VarName());
            }
        }
        else if (dlg.isSearchLabels() && start_node)
        {
            auto label_name = dlg.get_Label().ToStdString();
            auto node = FindNodeByLabel(start_node, label_name);
            if (node)
            {
                SelectNode(node);
                m_nav_panel->SetFocus();
            }
            else
            {
                wxMessageBox(wxString() << "Unable to find " << dlg.get_Label());
            }
        }
        else
        {
            wxMessageBox("No selected node, or search criteria selected");
        }
    }
}

void PopulateGenerators(Node* node, std::set<std::string>& set_generators)
{
    if (node->GetChildCount())
    {
        for (auto& child: node->GetChildNodePtrs())
        {
            PopulateGenerators(child.get(), set_generators);
        }
    }
    set_generators.insert(map_GenNames[node->gen_name()]);
}

void PopulateVarNames(Node* node, wxComboBox* combo)
{
    if (node->GetChildCount())
    {
        for (auto& child: node->GetChildNodePtrs())
        {
            PopulateVarNames(child.get(), combo);
        }
    }
    else
    {
        if (node->HasValue(prop_var_name))
        {
            combo->Append(node->prop_as_wxString(prop_var_name));
        }
    }
}

void PopulateLabels(Node* node, wxComboBox* combo)
{
    if (node->GetChildCount())
    {
        for (auto& child: node->GetChildNodePtrs())
        {
            PopulateLabels(child.get(), combo);
        }
    }
    else
    {
        if (node->HasValue(prop_label))
        {
            combo->Append(node->prop_as_wxString(prop_label));
        }
    }
}

void NodeSearchDlg::OnInit(wxInitDialogEvent& event)
{
    if (auto cur_sel = wxGetFrame().GetSelectedNode(); cur_sel)
    {
        std::set<std::string> set_generators;
        PopulateGenerators(cur_sel, set_generators);
        for (auto& iter: set_generators)
        {
            m_combo_generators->Append(iter);
            m_scintilla->AddTextRaw(iter.c_str());
            m_scintilla->AddTextRaw("\n");
        }
        PopulateVarNames(cur_sel, m_combo_variables);
        PopulateLabels(cur_sel, m_combo_labels);
    }

    event.Skip();
}

void NodeSearchDlg::OnRadioSearchGenerators(wxCommandEvent& WXUNUSED(event))
{
    m_radio_generators->SetValue(true);
    m_radio_labels->SetValue(false);
    m_radio_var_names->SetValue(false);
}

void NodeSearchDlg::OnRadioSearchVarNames(wxCommandEvent& WXUNUSED(event))
{
    m_radio_generators->SetValue(false);
    m_radio_labels->SetValue(false);
    m_radio_var_names->SetValue(true);
}

void NodeSearchDlg::OnRadioSearchLabels(wxCommandEvent& WXUNUSED(event))
{
    m_radio_generators->SetValue(false);
    m_radio_labels->SetValue(true);
    m_radio_var_names->SetValue(false);
}
