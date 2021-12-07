////////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor -- see https://github.com/KeyWorksRW/wxUiEditor/
//
// DO NOT EDIT THIS FILE! Your changes will be lost if it is re-generated!
////////////////////////////////////////////////////////////////////////////////

#include <wx/button.h>
#include <wx/sizer.h>

#include "editcodedialog_base.h"

bool EditCodeDialogBase::Create(wxWindow *parent, wxWindowID id, const wxString &title,
        const wxPoint&pos, const wxSize& size, long style, const wxString &name)
{
    if (!wxDialog::Create(parent, id, title, pos, size, style, name))
        return false;

    auto parent_sizer = new wxBoxSizer(wxVERTICAL);

    m_stc = new wxStyledTextCtrl(this, wxID_ANY);
    {
        m_stc->SetProperty("fold", "1");
        m_stc->SetMarginType(1, wxSTC_MARGIN_SYMBOL);
        m_stc->SetMarginMask(1, wxSTC_MASK_FOLDERS);
        m_stc->SetMarginWidth(1, 16);
        m_stc->SetMarginSensitive(1, true);
        m_stc->SetFoldFlags(wxSTC_FOLDFLAG_LINEBEFORE_CONTRACTED | wxSTC_FOLDFLAG_LINEAFTER_CONTRACTED);
        m_stc->SetMarginWidth(0, 0);
        m_stc->SetUseTabs(false);
        m_stc->SetTabWidth(4);
        m_stc->SetBackSpaceUnIndents(true);
        m_stc->SetInitialSize(ConvertPixelsToDialog(
        wxSize(600 > GetBestSize().x ? 600 : -1, 400> GetBestSize().y ? 400 : -1)));
    }
    m_stc->SetInitialSize(ConvertPixelsToDialog(
        wxSize(600 > GetBestSize().x ? 600 : -1, 400> GetBestSize().y ? 400 : -1)));
    parent_sizer->Add(m_stc, wxSizerFlags().DoubleBorder(wxALL));

    auto stdBtn_2 = CreateStdDialogButtonSizer(wxOK|wxCANCEL);
    parent_sizer->Add(CreateSeparatedSizer(stdBtn_2), wxSizerFlags().Expand().Border(wxALL));

    SetSizerAndFit(parent_sizer);
    Centre(wxBOTH);

    // Event handlers
    Bind(wxEVT_INIT_DIALOG, &EditCodeDialogBase::OnInit, this);
    m_stc->Bind(wxEVT_STC_CHANGE, &EditCodeDialogBase::OnChange, this);
    Bind(wxEVT_BUTTON, &EditCodeDialogBase::OnOK, this, wxID_OK);

    return true;
}
