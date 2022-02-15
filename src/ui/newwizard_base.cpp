////////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor -- see https://github.com/KeyWorksRW/wxUiEditor/
//
// DO NOT EDIT THIS FILE! Your changes will be lost if it is re-generated!
////////////////////////////////////////////////////////////////////////////////

#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/valgen.h>
#include <wx/valtext.h>

#include "newwizard_base.h"

bool NewWizard::Create(wxWindow* parent, wxWindowID id, const wxString& title,
        const wxPoint& pos, const wxSize& size, long style, const wxString &name)
{
    if (!wxDialog::Create(parent, id, title, pos, size, style, name))
        return false;

    auto parent_sizer = new wxBoxSizer(wxVERTICAL);

    auto box_sizer_3 = new wxBoxSizer(wxVERTICAL);
    parent_sizer->Add(box_sizer_3, wxSizerFlags().Border(wxALL));

    auto staticText_3 = new wxStaticText(this, wxID_ANY, "These are initial values -- all of them can be changed after the wizard is created.");
    staticText_3->Wrap(300);
    box_sizer_3->Add(staticText_3, wxSizerFlags().Border(wxALL));

    m_infoBar = new wxInfoBar(this);
    m_infoBar->SetShowHideEffects(wxSHOW_EFFECT_NONE, wxSHOW_EFFECT_NONE);
    box_sizer_3->Add(m_infoBar, wxSizerFlags().Expand().Border(wxALL));

    auto box_sizer_2 = new wxBoxSizer(wxHORIZONTAL);
    parent_sizer->Add(box_sizer_2, wxSizerFlags().Expand().Border(wxALL));

    auto staticText = new wxStaticText(this, wxID_ANY, "&Base class name:");
    staticText->SetToolTip("Change this to something unique to your project.");
    box_sizer_2->Add(staticText, wxSizerFlags().Center().Border(wxALL));

    m_classname = new wxTextCtrl(this, wxID_ANY, "MyWizardBase");
    m_classname->SetValidator(wxTextValidator(wxFILTER_NONE, &m_base_class));
    m_classname->SetToolTip("Change this to something unique to your project.");
    box_sizer_2->Add(m_classname, wxSizerFlags(1).Border(wxALL));

    auto box_sizer__2 = new wxBoxSizer(wxHORIZONTAL);
    parent_sizer->Add(box_sizer__2, wxSizerFlags().Expand().Border(wxALL));

    auto staticText_2 = new wxStaticText(this, wxID_ANY, "&Title:");
    box_sizer__2->Add(staticText_2, wxSizerFlags().Center().Border(wxALL));

    m_textCtrl_title = new wxTextCtrl(this, wxID_ANY, wxEmptyString);
    m_textCtrl_title->SetHint("Text for wizard's Title Bar");
    m_textCtrl_title->SetValidator(wxTextValidator(wxFILTER_NONE, &m_title));
    box_sizer__2->Add(m_textCtrl_title, wxSizerFlags(1).Border(wxALL));

    auto box_sizer = new wxBoxSizer(wxVERTICAL);
    parent_sizer->Add(box_sizer, wxSizerFlags().Border(wxALL));

    auto box_sizer_4 = new wxBoxSizer(wxHORIZONTAL);
    box_sizer->Add(box_sizer_4, wxSizerFlags().Border(wxRIGHT|wxTOP|wxBOTTOM, wxSizerFlags::GetDefaultBorder()));

    auto staticText_4 = new wxStaticText(this, wxID_ANY, "&Initial Pages:");
    box_sizer_4->Add(staticText_4, wxSizerFlags().Center().Border(wxLEFT|wxTOP|wxBOTTOM, wxSizerFlags::GetDefaultBorder()));

    m_spinCtrlTabs = new wxSpinCtrl(this, wxID_ANY, wxEmptyString,
            wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 7, 3);
    m_spinCtrlTabs->SetValidator(wxGenericValidator(&m_num_pages));
    box_sizer_4->Add(m_spinCtrlTabs, wxSizerFlags().Center().Border(wxALL));

    auto stdBtn = CreateStdDialogButtonSizer(wxOK|wxCANCEL);
    parent_sizer->Add(CreateSeparatedSizer(stdBtn), wxSizerFlags().Expand().Border(wxALL));

    SetSizerAndFit(parent_sizer);
    Centre(wxBOTH);

    // Event handlers
    Bind(wxEVT_INIT_DIALOG, &NewWizard::OnInit, this);
    m_classname->Bind(wxEVT_TEXT,
        [this](wxCommandEvent&)
        {VerifyClassName();
        } );

    return true;
}
