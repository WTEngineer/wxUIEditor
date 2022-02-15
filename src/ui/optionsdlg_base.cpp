////////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor -- see https://github.com/KeyWorksRW/wxUiEditor/
//
// DO NOT EDIT THIS FILE! Your changes will be lost if it is re-generated!
////////////////////////////////////////////////////////////////////////////////

#include <wx/button.h>
#include <wx/checkbox.h>
#include <wx/sizer.h>
#include <wx/valgen.h>

#include "optionsdlg_base.h"

bool OptionsDlgBase::Create(wxWindow* parent, wxWindowID id, const wxString& title,
        const wxPoint& pos, const wxSize& size, long style, const wxString &name)
{
    if (!wxDialog::Create(parent, id, title, pos, size, style, name))
        return false;

    auto parent_sizer = new wxBoxSizer(wxVERTICAL);

    auto box_sizer = new wxBoxSizer(wxVERTICAL);
    parent_sizer->Add(box_sizer, wxSizerFlags().Expand().Border(wxALL));

    auto checkBox_borders = new wxCheckBox(this, wxID_ANY, "New sizers have &borders on all sides");
    checkBox_borders->SetValue(true);
    checkBox_borders->SetValidator(wxGenericValidator(&m_sizers_all_borders));
    checkBox_borders->SetToolTip("If checked, all new sizers will be created with wxALL for the border.");
    box_sizer->Add(checkBox_borders, wxSizerFlags().Border(wxALL));

    auto checkBox_expand = new wxCheckBox(this, wxID_ANY, "New sizers have wx&EXPAND set");
    checkBox_expand->SetValue(true);
    checkBox_expand->SetValidator(wxGenericValidator(&m_sizers_always_expand));
    checkBox_expand->SetToolTip("If checked, new sizers will be created with the wxEXPAND flag.");
    box_sizer->Add(checkBox_expand, wxSizerFlags().Border(wxALL));

    box_sizer->AddSpacer(16);

    auto checkBox_wakatime = new wxCheckBox(this, wxID_ANY, "Enable WakaTime");
    checkBox_wakatime->SetValue(true);
    checkBox_wakatime->SetValidator(wxGenericValidator(&m_isWakaTimeEnabled));
    checkBox_wakatime->SetToolTip("If you have WakaTime installed, checking this will record time spent in the editor as \"designing\". (See https://wakatime.com/about)");
    box_sizer->Add(checkBox_wakatime, wxSizerFlags().Border(wxALL));

    auto stdBtn = CreateStdDialogButtonSizer(wxOK|wxCANCEL);
    parent_sizer->Add(CreateSeparatedSizer(stdBtn), wxSizerFlags().Expand().Border(wxALL));

    SetSizerAndFit(parent_sizer);
    Centre(wxBOTH);

    // Event handlers
    Bind(wxEVT_INIT_DIALOG, &OptionsDlgBase::OnInit, this);
    Bind(wxEVT_BUTTON, &OptionsDlgBase::OnAffirmative, this, wxID_OK);

    return true;
}
