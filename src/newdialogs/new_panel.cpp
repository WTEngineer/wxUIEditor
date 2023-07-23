///////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor - see https://github.com/KeyWorksRW/wxUiEditor/
//
// Do not edit any code above the "End of generated code" comment block.
// Any changes before that block will be lost if it is re-generated!
///////////////////////////////////////////////////////////////////////////////

// clang-format off

#include <wx/button.h>
#include <wx/checkbox.h>
#include <wx/combobox.h>
#include <wx/stattext.h>
#include <wx/valgen.h>
#include <wx/valtext.h>

#include "new_panel.h"

bool NewPanel::Create(wxWindow* parent, wxWindowID id, const wxString& title,
    const wxPoint& pos, const wxSize& size, long style, const wxString &name)
{
    if (!wxDialog::Create(parent, id, title, pos, size, style, name))
        return false;

    auto* dlg_sizer = new wxBoxSizer(wxVERTICAL);

    auto* box_sizer_3 = new wxBoxSizer(wxVERTICAL);

    auto* staticText_3 = new wxStaticText(this, wxID_ANY,
        "These are initial values -- all of them can be changed after the panel is created.");
    staticText_3->Wrap(300);
    box_sizer_3->Add(staticText_3, wxSizerFlags().Border(wxALL));

    m_infoBar = new wxInfoBar(this);
    m_infoBar->SetShowHideEffects(wxSHOW_EFFECT_NONE, wxSHOW_EFFECT_NONE);
    m_infoBar->SetEffectDuration(500);
    box_sizer_3->Add(m_infoBar, wxSizerFlags().Expand().Border(wxALL));

    dlg_sizer->Add(box_sizer_3, wxSizerFlags().Border(wxALL));

    m_class_sizer = new wxBoxSizer(wxHORIZONTAL);

    auto* staticText = new wxStaticText(this, wxID_ANY, "&Base class name:");
    staticText->SetToolTip("Change this to something unique to your project.");
    m_class_sizer->Add(staticText, wxSizerFlags().Center().Border(wxALL));

    m_classname = new wxTextCtrl(this, wxID_ANY, "MyPanelBase");
    m_classname->SetValidator(wxTextValidator(wxFILTER_NONE, &m_base_class));
    m_classname->SetToolTip("Change this to something unique to your project.");
    m_class_sizer->Add(m_classname, wxSizerFlags(1).Border(wxALL));

    dlg_sizer->Add(m_class_sizer, wxSizerFlags().Expand().Border(wxALL));

    auto* box_sizer = new wxBoxSizer(wxHORIZONTAL);

    auto* staticText_2 = new wxStaticText(this, wxID_ANY, "&Parent sizer type:");
    box_sizer->Add(staticText_2, wxSizerFlags().Center().Border(wxALL));

    auto* comboBox = new wxComboBox(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize,
        0, nullptr, wxCB_READONLY);
    comboBox->Append("Box");
    comboBox->Append("FlexGrid");
    comboBox->Append("Grid");
    comboBox->Append("GridBag");
    comboBox->Append("StaticBox");
    comboBox->Append("Wrap");
    m_sizer_type = "Box";  // set validator variable
    comboBox->SetValidator(wxGenericValidator(&m_sizer_type));
    box_sizer->Add(comboBox, wxSizerFlags().Border(wxALL));

    dlg_sizer->Add(box_sizer, wxSizerFlags().Border(wxALL));

    auto* box_sizer_2 = new wxBoxSizer(wxHORIZONTAL);

    auto* checkTabTraversal = new wxCheckBox(this, wxID_ANY, "&Tab traversal");
    checkTabTraversal->SetValue(true);
    checkTabTraversal->SetValidator(wxGenericValidator(&m_tab_traversal));
    checkTabTraversal->SetToolTip("Checking this will cause the tab key to traverse child windows.");
    box_sizer_2->Add(checkTabTraversal, wxSizerFlags().Border(wxALL));

    dlg_sizer->Add(box_sizer_2, wxSizerFlags().Border(wxALL));

    auto* stdBtn = CreateStdDialogButtonSizer(wxOK|wxCANCEL);
    dlg_sizer->Add(CreateSeparatedSizer(stdBtn), wxSizerFlags().Expand().Border(wxALL));

    SetSizerAndFit(dlg_sizer);
    Centre(wxBOTH);

    // Event handlers
    Bind(wxEVT_INIT_DIALOG, &NewPanel::OnInit, this);
    m_classname->Bind(wxEVT_TEXT,
        [this](wxCommandEvent&)
        {VerifyClassName();
        });

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
// Purpose:   Dialog for creating a new form panel
// Author:    Ralph Walden
// Copyright: Copyright (c) 2022-2023 KeyWorks Software (Ralph Walden)
// License:   Apache License -- see ../../LICENSE
/////////////////////////////////////////////////////////////////////////////

#include "../panels/nav_panel.h"  // NavigationPanel -- Navigation Panel
#include "mainframe.h"            // MainFrame -- Main window frame
#include "new_common.h"           // Contains code common between all new_ dialogs
#include "node.h"                 // Node class
#include "node_creator.h"         // NodeCreator -- Class used to create nodes
#include "project_handler.h"      // ProjectHandler class
#include "undo_cmds.h"            // InsertNodeAction -- Undoable command classes derived from UndoAction

void NewPanel::OnInit(wxInitDialogEvent& event)
{
    if (!m_is_form)
    {
        for (size_t idx = 0; idx < m_class_sizer->GetItemCount(); ++idx)
        {
            m_class_sizer->GetItem(idx)->GetWindow()->Hide();
        }
    }

    event.Skip();  // transfer all validator data to their windows and update UI
}

void NewPanel::createNode()
{
    NodeSharedPtr new_node;
    if (m_is_form)
    {
        new_node = NodeCreation.createNode(gen_PanelForm, Project.getProjectNode());
        ASSERT(new_node);
    }
    else
    {
        new_node = NodeCreation.createNode(gen_wxPanel, wxGetFrame().GetSelectedNode());
        if (!new_node)
        {
            wxMessageBox("You need to have a sizer selected before you can create a wxPanel.", "Create wxPanel");
            return;
        }
    }

    NodeSharedPtr sizer = nullptr;

    if (m_sizer_type == "FlexGrid")
    {
        sizer = NodeCreation.createNode(gen_wxFlexGridSizer, new_node.get());
    }
    else if (m_sizer_type == "Grid")
    {
        sizer = NodeCreation.createNode(gen_wxGridSizer, new_node.get());
    }
    else if (m_sizer_type == "GridBag")
    {
        sizer = NodeCreation.createNode(gen_wxGridBagSizer, new_node.get());
    }
    else if (m_sizer_type == "StaticBox")
    {
        sizer = NodeCreation.createNode(gen_wxStaticBoxSizer, new_node.get());
    }
    else if (m_sizer_type == "Wrap")
    {
        sizer = NodeCreation.createNode(gen_wxWrapSizer, new_node.get());
    }
    else
    {
        sizer = NodeCreation.createNode(gen_VerticalBoxSizer, new_node.get());
    }

    new_node->adoptChild(sizer);

    if (!m_tab_traversal)
    {
        new_node->set_value(prop_window_style, "");
    }

    if (!m_is_form)
    {
        sizer->set_value(prop_var_name, "panel_sizer");
        sizer->fixDuplicateName();

        auto parent = wxGetFrame().GetSelectedNode();
        auto pos = parent->findInsertionPos(parent);
        tt_string undo_str("New wxPanel");
        wxGetFrame().PushUndoAction(std::make_shared<InsertNodeAction>(new_node.get(), parent, undo_str, pos));
    }
    else
    {
        new_node->set_value(prop_class_name, m_base_class.utf8_string());
        if (new_node->as_string(prop_class_name) != new_node->getPropDefaultValue(prop_class_name))
        {
            UpdateFormClass(new_node.get());
        }

        auto parent_node = wxGetFrame().GetSelectedNode();
        if (!parent_node)
        {
            parent_node = Project.getProjectNode();
        }
        else
        {
            parent_node = parent_node->getValidFormParent();
        }

        wxGetFrame().SelectNode(parent_node);

        tt_string undo_str("New wxPanel");
        wxGetFrame().PushUndoAction(std::make_shared<InsertNodeAction>(new_node.get(), parent_node, undo_str, -1));
    }

    wxGetFrame().FireCreatedEvent(new_node);
    wxGetFrame().SelectNode(new_node, evt_flags::fire_event | evt_flags::force_selection);
    wxGetFrame().GetNavigationPanel()->ChangeExpansion(new_node.get(), true, true);
}

// Called whenever m_classname changes
void NewPanel::VerifyClassName()
{
    if (!IsClassNameUnique(m_classname->GetValue()))
    {
        if (!m_is_info_shown)
        {
            m_infoBar->ShowMessage("This class name is already in use.", wxICON_WARNING);
            FindWindow(GetAffirmativeId())->Disable();
            Fit();
            m_is_info_shown = true;
        }
        return;
    }

    else if (m_is_info_shown)
    {
        m_is_info_shown = false;
        m_infoBar->Dismiss();
        FindWindow(GetAffirmativeId())->Enable();
        Fit();
    }
}
