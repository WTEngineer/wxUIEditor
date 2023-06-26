///////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor - see https://github.com/KeyWorksRW/wxUiEditor/
//
// Do not edit any code above the "End of generated code" comment block.
// Any changes before that block will be lost if it is re-generated!
///////////////////////////////////////////////////////////////////////////////

// clang-format off

#include <wx/persist.h>
#include <wx/persist/toplevel.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/stattext.h>

#include "global_ids_dlg_base.h"

bool GlobalCustomIDSBase::Create(wxWindow* parent, wxWindowID id, const wxString& title,
    const wxPoint& pos, const wxSize& size, long style, const wxString &name)
{
    if (!wxDialog::Create(parent, id, title, pos, size, style, name))
        return false;

    auto* dlg_sizer = new wxBoxSizer(wxVERTICAL);

    auto* flex_grid_sizer = new wxFlexGridSizer(2, 0, 10);

    auto* staticText = new wxStaticText(this, wxID_ANY, "Project and Folders");
    flex_grid_sizer->Add(staticText, wxSizerFlags().Border(wxALL));

    auto* staticText_2 = new wxStaticText(this, wxID_ANY, "Forms");
    flex_grid_sizer->Add(staticText_2, wxSizerFlags().Border(wxALL));

    m_lb_folders = new wxListBox(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, nullptr, wxLB_MULTIPLE);
    m_lb_folders->SetFocus();
    m_lb_folders->Append("Project");
    m_lb_folders->SetSelection(0);
    m_lb_folders->SetMinSize(ConvertDialogToPixels(wxSize(130, 80)));
    flex_grid_sizer->Add(m_lb_folders, wxSizerFlags().Border(wxALL));

    m_lb_forms = new wxListBox(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, nullptr, wxLB_MULTIPLE|wxLB_SORT);
    m_lb_forms->SetMinSize(ConvertDialogToPixels(wxSize(130, 80)));
    flex_grid_sizer->Add(m_lb_forms, wxSizerFlags().Border(wxALL));

    auto* box_sizer_9 = new wxBoxSizer(wxHORIZONTAL);

    auto* btn = new wxButton(this, wxID_ANY, "All");
    box_sizer_9->Add(btn, wxSizerFlags().Border(wxALL));

    auto* btn_2 = new wxButton(this, wxID_ANY, "None");
    box_sizer_9->Add(btn_2, wxSizerFlags().Border(wxALL));

    flex_grid_sizer->Add(box_sizer_9, wxSizerFlags().Border(wxALL));

    auto* box_sizer_10 = new wxBoxSizer(wxHORIZONTAL);

    auto* btn_3 = new wxButton(this, wxID_ANY, "All");
    box_sizer_10->Add(btn_3, wxSizerFlags().Border(wxALL));

    auto* btn_4 = new wxButton(this, wxID_ANY, "None");
    box_sizer_10->Add(btn_4, wxSizerFlags().Border(wxALL));

    flex_grid_sizer->Add(box_sizer_10, wxSizerFlags().Border(wxALL));

    dlg_sizer->Add(flex_grid_sizer, wxSizerFlags().Expand().Border(wxALL));

    auto* box_sizer_2 = new wxBoxSizer(wxHORIZONTAL);

    auto* static_box = new wxStaticBoxSizer(wxVERTICAL, this, "Remove");

    auto* box_sizer_3 = new wxBoxSizer(wxHORIZONTAL);

    auto* box_sizer_4 = new wxBoxSizer(wxVERTICAL);

    auto* staticText_4 = new wxStaticText(static_box->GetStaticBox(), wxID_ANY, "Old Prefix");
    box_sizer_4->Add(staticText_4, wxSizerFlags().Border(wxALL));

    m_text_old_prefix = new wxTextCtrl(static_box->GetStaticBox(), wxID_ANY, wxEmptyString);
    m_text_old_prefix->SetHint("old prefix");
    box_sizer_4->Add(m_text_old_prefix, wxSizerFlags().Border(wxALL));

    m_btn_remove_prefix = new wxButton(static_box->GetStaticBox(), wxID_ANY, "Remove");
    box_sizer_4->Add(m_btn_remove_prefix, wxSizerFlags().Border(wxALL));

    box_sizer_3->Add(box_sizer_4, wxSizerFlags().Border(wxALL));

    auto* box_sizer_5 = new wxBoxSizer(wxVERTICAL);

    auto* staticText_5 = new wxStaticText(static_box->GetStaticBox(), wxID_ANY, "Old Suffix");
    box_sizer_5->Add(staticText_5, wxSizerFlags().Border(wxALL));

    m_text_old_suffix = new wxTextCtrl(static_box->GetStaticBox(), wxID_ANY, wxEmptyString);
    m_text_old_suffix->SetHint("old suffix");
    box_sizer_5->Add(m_text_old_suffix, wxSizerFlags().Border(wxALL));

    m_btn_remove_old_suffix = new wxButton(static_box->GetStaticBox(), wxID_ANY, "Remove");
    box_sizer_5->Add(m_btn_remove_old_suffix, wxSizerFlags().Border(wxALL));

    box_sizer_3->Add(box_sizer_5, wxSizerFlags().Border(wxALL));

    static_box->Add(box_sizer_3, wxSizerFlags().Expand().Border(wxALL));

    box_sizer_2->Add(static_box, wxSizerFlags().Expand().Border(wxALL));

    auto* static_box_2 = new wxStaticBoxSizer(wxVERTICAL, this, "Add");

    auto* box_sizer_6 = new wxBoxSizer(wxHORIZONTAL);

    auto* box_sizer_7 = new wxBoxSizer(wxVERTICAL);

    auto* staticText_6 = new wxStaticText(static_box_2->GetStaticBox(), wxID_ANY, "New Prefix:");
    box_sizer_7->Add(staticText_6, wxSizerFlags().Border(wxALL));

    m_combo_prefixes = new wxComboBox(static_box_2->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition,
        wxDefaultSize, 0, nullptr, wxCB_DROPDOWN|wxCB_SORT);
    box_sizer_7->Add(m_combo_prefixes, wxSizerFlags().Border(wxALL));

    m_btn_Add_new_prefix = new wxButton(static_box_2->GetStaticBox(), wxID_ANY, "Add");
    box_sizer_7->Add(m_btn_Add_new_prefix, wxSizerFlags().Border(wxALL));

    box_sizer_6->Add(box_sizer_7, wxSizerFlags().Border(wxALL));

    auto* box_sizer_8 = new wxBoxSizer(wxVERTICAL);

    auto* staticText_7 = new wxStaticText(static_box_2->GetStaticBox(), wxID_ANY, "New Suffix:");
    box_sizer_8->Add(staticText_7, wxSizerFlags().Border(wxALL));

    m_combo_suffixes = new wxComboBox(static_box_2->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition,
        wxDefaultSize, 0, nullptr, wxCB_DROPDOWN|wxCB_SORT);
    box_sizer_8->Add(m_combo_suffixes, wxSizerFlags().Border(wxALL));

    m_btn_add_new_suffix_2 = new wxButton(static_box_2->GetStaticBox(), wxID_ANY, "Add");
    box_sizer_8->Add(m_btn_add_new_suffix_2, wxSizerFlags().Border(wxALL));

    box_sizer_6->Add(box_sizer_8, wxSizerFlags().Border(wxALL));

    static_box_2->Add(box_sizer_6, wxSizerFlags().Expand().Border(wxALL));

    box_sizer_2->Add(static_box_2, wxSizerFlags().Expand().Border(wxALL));

    dlg_sizer->Add(box_sizer_2, wxSizerFlags().Expand().Border(wxALL));

    auto* box_sizer = new wxBoxSizer(wxHORIZONTAL);

    m_grid = new wxGrid(this, wxID_ANY);
    {
        m_grid->CreateGrid(5, 2);
        m_grid->EnableDragGridSize(false);
        m_grid->SetMargins(0, 0);
        m_grid->SetSelectionMode(wxGrid::wxGridSelectNone);
        m_grid->SetDefaultCellAlignment(wxALIGN_LEFT, wxALIGN_TOP);
        m_grid->SetDefaultColSize(200);
        m_grid->SetColLabelAlignment(wxALIGN_CENTER, wxALIGN_CENTER);
        m_grid->SetColLabelSize(wxGRID_AUTOSIZE);
        m_grid->SetColLabelValue(0, "Original");
        m_grid->SetColLabelValue(1, "Modified");
        m_grid->SetRowLabelAlignment(wxALIGN_CENTER, wxALIGN_CENTER);
        m_grid->HideRowLabels();
        m_grid->SetColLabelValue(0, "Original");
        m_grid->SetColLabelValue(1, "Modified");
    }
    box_sizer->Add(m_grid, wxSizerFlags().Border(wxALL));

    m_btn_commit = new wxButton(this, wxID_ANY, "Commit change");
    box_sizer->Add(m_btn_commit, wxSizerFlags().Center().Border(wxALL));

    dlg_sizer->Add(box_sizer, wxSizerFlags().Border(wxALL));

    auto* stdBtn = CreateStdDialogButtonSizer(wxOK|wxCANCEL);
    dlg_sizer->Add(CreateSeparatedSizer(stdBtn), wxSizerFlags().Expand().Border(wxALL));

    SetSizerAndFit(dlg_sizer);
    Centre(wxBOTH);

    wxPersistentRegisterAndRestore(this, "GlobalCustomIDSBase");

    // Event handlers
    btn->Bind(wxEVT_BUTTON, &GlobalCustomIDSBase::OnSelectAllFolders, this);
    btn_2->Bind(wxEVT_BUTTON, &GlobalCustomIDSBase::OnSelectNoFolders, this);
    btn_3->Bind(wxEVT_BUTTON, &GlobalCustomIDSBase::OnSelectAllForms, this);
    btn_4->Bind(wxEVT_BUTTON, &GlobalCustomIDSBase::OnSelectNoForms, this);
    m_btn_remove_prefix->Bind(wxEVT_BUTTON, &GlobalCustomIDSBase::OnRemovePrefix, this);
    m_btn_remove_old_suffix->Bind(wxEVT_BUTTON, &GlobalCustomIDSBase::OnRemoveSuffix, this);
    m_btn_Add_new_prefix->Bind(wxEVT_BUTTON, &GlobalCustomIDSBase::OnAddPrefix, this);
    m_btn_add_new_suffix_2->Bind(wxEVT_BUTTON, &GlobalCustomIDSBase::OnAddSuffix, this);
    m_btn_commit->Bind(wxEVT_BUTTON, &GlobalCustomIDSBase::OnCommit, this);
    Bind(wxEVT_INIT_DIALOG, &GlobalCustomIDSBase::OnInit, this);
    m_lb_folders->Bind(wxEVT_LISTBOX, &GlobalCustomIDSBase::OnSelectFolders, this);
    m_lb_forms->Bind(wxEVT_LISTBOX, &GlobalCustomIDSBase::OnSelectForms, this);

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
