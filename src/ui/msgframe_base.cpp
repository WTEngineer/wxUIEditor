////////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor -- see https://github.com/KeyWorksRW/wxUiEditor/
//
// DO NOT EDIT THIS FILE! Your changes will be lost if it is re-generated!
////////////////////////////////////////////////////////////////////////////////

#include "pch.h"

#include <wx/artprov.h>
#include <wx/sizer.h>

#include "msgframe_base.h"

#include <wx/mstream.h>  // Memory stream classes

// Convert a data array into a wxImage
inline wxImage GetImageFromArray(const unsigned char* data, size_t size_data)
{
    wxMemoryInputStream strm(data, size_data);
    wxImage image;
    image.LoadFile(strm);
    return image;
};

namespace wxue_img
{
    extern const unsigned char hidden_png[494];
}

MsgFrameBase::MsgFrameBase(wxWindow* parent, wxWindowID id, const wxString& title,
        const wxPoint& pos, const wxSize& size, long style) :
    wxFrame(parent, id, title, pos, size, style)
{
    if (!wxImage::FindHandler(wxBITMAP_TYPE_PNG))
        wxImage::AddHandler(new wxPNGHandler);

    auto menubar = new wxMenuBar();

    auto menu_file = new wxMenu();

    auto menu_item_saveas = new wxMenuItem(menu_file, wxID_SAVEAS, wxEmptyString);
    menu_item_saveas->SetBitmap(wxArtProvider::GetBitmap(wxART_FILE_SAVE_AS, wxART_MENU));
    menu_file->Append(menu_item_saveas);

    menu_file->AppendSeparator();

    auto menu_item_clear = new wxMenuItem(menu_file, wxID_CLEAR, wxEmptyString);
    menu_item_clear->SetBitmap(wxArtProvider::GetBitmap(wxART_CUT, wxART_MENU));
    menu_file->Append(menu_item_clear);

    auto menu_item_hide = new wxMenuItem(menu_file, id_hide, wxString::FromUTF8("&Hide"));
    menu_item_hide->SetBitmap(GetImageFromArray(wxue_img::hidden_png, sizeof(wxue_img::hidden_png)));
    menu_file->Append(menu_item_hide);
    menubar->Append(menu_file, wxString::FromUTF8("&File"));

    auto menu_view = new wxMenu();

    m_menu_item_warnings = new wxMenuItem(menu_view, id_warning_msgs, wxString::FromUTF8("Warnings"),
        wxEmptyString, wxITEM_CHECK);
    m_menu_item_warnings->SetBitmap(wxArtProvider::GetBitmap(wxART_WARNING, wxART_MENU));
    menu_view->Append(m_menu_item_warnings);

    m_menu_item_events = new wxMenuItem(menu_view, id_event_msgs, wxString::FromUTF8("Events"),
        wxEmptyString, wxITEM_CHECK);
    m_menu_item_events->SetBitmap(wxArtProvider::GetBitmap(wxART_TIP, wxART_MENU));
    menu_view->Append(m_menu_item_events);

    m_menu_item_info = new wxMenuItem(menu_view, wxID_INFO, wxEmptyString,
        wxEmptyString, wxITEM_CHECK);
    m_menu_item_info->SetBitmap(wxArtProvider::GetBitmap(wxART_INFORMATION, wxART_MENU));
    menu_view->Append(m_menu_item_info);
    menubar->Append(menu_view, wxString::FromUTF8("&View"));

    SetMenuBar(menubar);

    auto parent_sizer = new wxBoxSizer(wxVERTICAL);

    m_textCtrl = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE|wxTE_READONLY|wxTE_RICH|wxHSCROLL);
    m_textCtrl->SetMinSize(wxSize(350, 300));
    parent_sizer->Add(m_textCtrl, wxSizerFlags(1).Expand().Border(wxALL, 0));

    SetSizerAndFit(parent_sizer);

    Centre(wxBOTH);

    // Event handlers
    Bind(wxEVT_CLOSE_WINDOW, &MsgFrameBase::OnClose, this);
    Bind(wxEVT_MENU, &MsgFrameBase::OnSaveAs, this, wxID_SAVEAS);
    Bind(wxEVT_MENU, &MsgFrameBase::OnClear, this, wxID_CLEAR);
    Bind(wxEVT_MENU, &MsgFrameBase::OnHide, this, id_hide);
    Bind(wxEVT_MENU, &MsgFrameBase::OnWarnings, this, id_warning_msgs);
    Bind(wxEVT_MENU, &MsgFrameBase::OnEvents, this, id_event_msgs);
    Bind(wxEVT_MENU, &MsgFrameBase::OnInfo, this, wxID_INFO);
}
