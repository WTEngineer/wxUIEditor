////////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor -- see https://github.com/KeyWorksRW/wxUiEditor/
//
// DO NOT EDIT THIS FILE! Your changes will be lost if it is re-generated!
////////////////////////////////////////////////////////////////////////////////

#include "pch.h"

#include <wx/ribbon/page.h>
#include <wx/ribbon/panel.h>
#include <wx/sizer.h>

#include "ribbondlg_base.h"

RibbonDlgBase::RibbonDlgBase(wxWindow* parent, wxWindowID id, const wxString& title,
        const wxPoint& pos, const wxSize& size, long style) :
    wxDialog(parent, id, title, pos, size, style)
{
    auto parent_sizer = new wxBoxSizer(wxVERTICAL);

    m_rbnBar = new wxRibbonBar(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxRIBBON_BAR_FLOW_HORIZONTAL|wxRIBBON_BAR_SHOW_PAGE_LABELS);
    m_rbnBar->SetArtProvider(new wxRibbonAUIArtProvider);
    parent_sizer->Add(m_rbnBar, wxSizerFlags(1).Expand().Border(wxALL));

    auto rbnPage = new wxRibbonPage(m_rbnBar, wxID_ANY, wxString::FromUTF8("First"));
    m_rbnBar->SetActivePage(rbnPage);

    auto rbnPanel = new wxRibbonPanel(rbnPage, wxID_ANY, wxString::FromUTF8("First Panel"));

    auto m_ribbonPage2 = new wxRibbonPage(m_rbnBar, wxID_ANY, wxString::FromUTF8("Second"));

    auto m_ribbonPanel2 = new wxRibbonPanel(m_ribbonPage2, wxID_ANY, wxString::FromUTF8("Second Panel"));
    m_rbnBar->Realize();

    SetSizerAndFit(parent_sizer);

    Centre(wxBOTH);
}
