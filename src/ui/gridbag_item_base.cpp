////////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor -- see https://github.com/KeyWorksRW/wxUiEditor/
//
// DO NOT EDIT THIS FILE! Your changes will be lost if it is re-generated!
////////////////////////////////////////////////////////////////////////////////

#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/stattext.h>

#include "gridbag_item_base.h"

bool GridBagItemBase::Create(wxWindow* parent, wxWindowID id, const wxString& title,
        const wxPoint& pos, const wxSize& size, long style, const wxString &name)
{
    if (!wxDialog::Create(parent, id, title, pos, size, style, name))
        return false;

    auto dlg_sizer = new wxBoxSizer(wxVERTICAL);

    auto flex_grid_sizer = new wxFlexGridSizer(4, 0, 5);
    dlg_sizer->Add(flex_grid_sizer, wxSizerFlags().Border(wxALL));

    auto staticText = new wxStaticText(this, wxID_ANY, "&Column:");
    flex_grid_sizer->Add(staticText, wxSizerFlags().Center().Border(wxALL));

    m_spin_column = new wxSpinCtrl(this, wxID_ANY, wxEmptyString,
            wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 10, 0);
    flex_grid_sizer->Add(m_spin_column, wxSizerFlags().Border(wxRIGHT|wxTOP|wxBOTTOM, wxSizerFlags::GetDefaultBorder()));

    auto staticText_2 = new wxStaticText(this, wxID_ANY, "Span c&olumns:");
    flex_grid_sizer->Add(staticText_2, wxSizerFlags().Center().Border(wxALL));

    m_spin_span_column = new wxSpinCtrl(this, wxID_ANY, wxEmptyString,
            wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 1, 10, 1);
    flex_grid_sizer->Add(m_spin_span_column, wxSizerFlags().Border(wxRIGHT|wxTOP|wxBOTTOM, wxSizerFlags::GetDefaultBorder()));

    auto staticText_3 = new wxStaticText(this, wxID_ANY, "&Row:");
    flex_grid_sizer->Add(staticText_3, wxSizerFlags().Center().Border(wxALL));

    m_spin_row = new wxSpinCtrl(this, wxID_ANY, wxEmptyString,
            wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 10, 0);
    flex_grid_sizer->Add(m_spin_row, wxSizerFlags().Border(wxRIGHT|wxTOP|wxBOTTOM, wxSizerFlags::GetDefaultBorder()));

    auto staticText_4 = new wxStaticText(this, wxID_ANY, "Span ro&ws:");
    flex_grid_sizer->Add(staticText_4, wxSizerFlags().Center().Border(wxALL));

    m_spin_span_row = new wxSpinCtrl(this, wxID_ANY, wxEmptyString,
            wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 1, 10, 1);
    flex_grid_sizer->Add(m_spin_span_row, wxSizerFlags().Border(wxRIGHT|wxTOP|wxBOTTOM, wxSizerFlags::GetDefaultBorder()));

    m_infoBar = new wxInfoBar(this);
    m_infoBar->SetShowHideEffects(wxSHOW_EFFECT_NONE, wxSHOW_EFFECT_NONE);
    dlg_sizer->Add(m_infoBar, wxSizerFlags(1).Expand().Border(wxALL));

    auto box_sizer = new wxBoxSizer(wxHORIZONTAL);
    dlg_sizer->Add(box_sizer, wxSizerFlags().Border(wxALL));

    m_radio_column = new wxRadioButton(this, wxID_ANY, "Insert &column", wxDefaultPosition, wxDefaultSize,
        wxRB_GROUP);
    m_radio_column->Hide();
    box_sizer->Add(m_radio_column, wxSizerFlags().Border(wxALL));

    m_radio_row = new wxRadioButton(this, wxID_ANY, "Insert &row");
    m_radio_row->Hide();
    box_sizer->Add(m_radio_row, wxSizerFlags().Border(wxALL));

    auto stdBtn = CreateStdDialogButtonSizer(wxOK|wxCANCEL);
    dlg_sizer->Add(CreateSeparatedSizer(stdBtn), wxSizerFlags().Expand().Border(wxALL));

    SetSizerAndFit(dlg_sizer);
    Centre(wxBOTH);

    // Event handlers
    Bind(wxEVT_INIT_DIALOG, &GridBagItemBase::OnInit, this);
    m_spin_column->Bind(wxEVT_SPINCTRL, &GridBagItemBase::OnColumn, this);
    m_spin_row->Bind(wxEVT_SPINCTRL, &GridBagItemBase::OnRow, this);
    Bind(wxEVT_BUTTON, &GridBagItemBase::OnOK, this, wxID_OK);

    return true;
}
