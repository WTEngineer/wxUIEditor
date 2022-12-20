////////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor -- see https://github.com/KeyWorksRW/wxUiEditor/
//
// DO NOT EDIT THIS FILE! Your changes will be lost if it is re-generated!
////////////////////////////////////////////////////////////////////////////////

#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/stattext.h>
#include <wx/valgen.h>
#include <wx/valtext.h>

#include "newframe_base.h"

bool NewFrame::Create(wxWindow* parent, wxWindowID id, const wxString& title,
        const wxPoint& pos, const wxSize& size, long style, const wxString &name)
{
    if (!wxDialog::Create(parent, id, title, pos, size, style, name))
        return false;

    auto* box_sizer = new wxBoxSizer(wxVERTICAL);

    auto* box_sizer_3 = new wxBoxSizer(wxVERTICAL);
    box_sizer->Add(box_sizer_3, wxSizerFlags().Border(wxALL));

    auto* staticText_3 = new wxStaticText(this, wxID_ANY,
        "These are initial values -- all of them can be changed after the window is created.");
    staticText_3->Wrap(300);
    box_sizer_3->Add(staticText_3, wxSizerFlags().Border(wxALL));

    m_infoBar = new wxInfoBar(this);
    m_infoBar->SetShowHideEffects(wxSHOW_EFFECT_NONE, wxSHOW_EFFECT_NONE);
    m_infoBar->SetEffectDuration(500);
    box_sizer_3->Add(m_infoBar, wxSizerFlags().Expand().Border(wxALL));

    auto* class_sizer = new wxBoxSizer(wxHORIZONTAL);
    box_sizer->Add(class_sizer, wxSizerFlags().Expand().Border(wxALL));

    auto* staticText = new wxStaticText(this, wxID_ANY, "&Base class name:");
    class_sizer->Add(staticText, wxSizerFlags().Center().Border(wxALL));

    m_classname = new wxTextCtrl(this, wxID_ANY, "MyFrameBase");
    m_classname->SetValidator(wxTextValidator(wxFILTER_NONE, &m_base_class));
    class_sizer->Add(m_classname, wxSizerFlags(1).Border(wxALL));

    m_checkBox_mainframe = new wxCheckBox(this, wxID_ANY, "Main Frame Window");
    m_checkBox_mainframe->SetValidator(wxGenericValidator(&m_has_mainframe));
    auto* static_box = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, m_checkBox_mainframe), wxVERTICAL);

    auto* box_sizer_2 = new wxBoxSizer(wxVERTICAL);
    static_box->Add(box_sizer_2, wxSizerFlags().Expand().DoubleBorder(wxALL));

    m_checkBox_toolbar = new wxCheckBox(static_box->GetStaticBox(), wxID_ANY, "Add Toolbar");
    m_checkBox_toolbar->SetValue(true);
    m_checkBox_toolbar->SetValidator(wxGenericValidator(&m_has_toolbar));
    box_sizer_2->Add(m_checkBox_toolbar, wxSizerFlags().Expand().Border(wxALL));

    m_checkBox_menu = new wxCheckBox(static_box->GetStaticBox(), wxID_ANY, "Add Menu");
    m_checkBox_menu->SetValue(true);
    m_checkBox_menu->SetValidator(wxGenericValidator(&m_has_menu));
    box_sizer_2->Add(m_checkBox_menu, wxSizerFlags().Expand().Border(wxALL));

    m_checkBox_statusbar = new wxCheckBox(static_box->GetStaticBox(), wxID_ANY, "Add Statusbar");
    m_checkBox_statusbar->SetValue(true);
    m_checkBox_statusbar->SetValidator(wxGenericValidator(&m_has_statusbar));
    box_sizer_2->Add(m_checkBox_statusbar, wxSizerFlags().Expand().Border(wxALL));

    box_sizer->Add(static_box, wxSizerFlags().Expand().DoubleBorder(wxALL));

    auto* stdBtn = CreateStdDialogButtonSizer(wxOK|wxCANCEL);
    box_sizer->Add(CreateSeparatedSizer(stdBtn), wxSizerFlags().Expand().Border(wxALL));

    SetSizerAndFit(box_sizer);
    Centre(wxBOTH);

    // Event handlers
    Bind(wxEVT_INIT_DIALOG,
        [this](wxInitDialogEvent& event)
        {
            m_classname->SetFocus();
            event.Skip();
        } );
    m_classname->Bind(wxEVT_TEXT,
        [this](wxCommandEvent&)
        {VerifyClassName();
        } );
    m_checkBox_mainframe->Bind(wxEVT_CHECKBOX, &NewFrame::OnCheckMainFrame, this);

    return true;
}
