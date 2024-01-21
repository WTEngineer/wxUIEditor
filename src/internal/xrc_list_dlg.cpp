///////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor - see https://github.com/KeyWorksRW/wxUiEditor/
//
// Do not edit any code above the "End of generated code" comment block.
// Any changes before that block will be lost if it is re-generated!
///////////////////////////////////////////////////////////////////////////////

// clang-format off

#include <wx/button.h>
#include <wx/sizer.h>

#include "xrc_list_dlg.h"

bool XrcListDlg::Create(wxWindow* parent, wxWindowID id, const wxString& title,
    const wxPoint& pos, const wxSize& size, long style, const wxString &name)
{
    if (!wxDialog::Create(parent, id, title, pos, size, style, name))
        return false;

    auto* dlg_sizer = new wxBoxSizer(wxVERTICAL);

    m_listbox = new wxListBox(this, wxID_ANY);
    m_listbox->SetMinSize(ConvertDialogToPixels(wxSize(100, 70)));
    dlg_sizer->Add(m_listbox, wxSizerFlags().Expand().Border(wxALL));

    auto* stdBtn = CreateStdDialogButtonSizer(wxOK|wxCANCEL);
    dlg_sizer->Add(CreateSeparatedSizer(stdBtn), wxSizerFlags().Expand().Border(wxALL));

    SetSizerAndFit(dlg_sizer);
    Centre(wxBOTH);

    // Event handlers
    Bind(wxEVT_BUTTON, &XrcListDlg::OnOK, this, wxID_OK);
    Bind(wxEVT_INIT_DIALOG, &XrcListDlg::OnInit, this);

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
// Purpose:   Test XRC
// Author:    Ralph Walden
// Copyright: Copyright (c) 2024 KeyWorks Software (Ralph Walden)
// License:   Apache License -- see ../../LICENSE
/////////////////////////////////////////////////////////////////////////////

#include "mainframe.h"        // MainFrame -- Main window frame
#include "project_handler.h"  // ProjectHandler class

void XrcListDlg::OnInit(wxInitDialogEvent& WXUNUSED(event))
{
    std::vector<Node*> forms;
    Project.CollectForms(forms);
    auto idx_cur_sel = 0;
    for (auto& form: forms)
    {
        if (form->isGen(gen_wxDialog))
        {
            auto index = m_listbox->Append(form->as_string(prop_class_name), static_cast<void*>(form));
            if (m_form == wxGetMainFrame()->getSelectedNode())
                idx_cur_sel = index;
        }
    }

    if (m_listbox->GetCount())
        m_listbox->SetSelection(idx_cur_sel);
}

void XrcListDlg::OnOK(wxCommandEvent& WXUNUSED(event))
{
    auto idx = m_listbox->GetSelection();
    if (idx == wxNOT_FOUND)
    {
        EndModal(wxID_CANCEL);
        return;
    }

    m_form = static_cast<Node*>(m_listbox->GetClientData(idx));
    EndModal(wxID_OK);
}
