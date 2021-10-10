////////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor -- see https://github.com/KeyWorksRW/wxUiEditor/
//
// DO NOT EDIT THIS FILE! Your changes will be lost if it is re-generated!
////////////////////////////////////////////////////////////////////////////////

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
    extern const unsigned char hidden_png[478];
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

namespace wxue_img
{

    const unsigned char hidden_png[478] {
    137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,24,0,0,0,24,8,6,0,0,0,224,119,61,248,0,0,0,9,112,72,89,115,0,0,11,19,0,0,11,19,1,
    0,154,156,24,0,0,1,144,73,68,65,84,72,199,229,148,161,171,242,96,20,198,127,219,68,28,12,6,98,48,12,4,131,197,106,147,89,52,25,140,107,
    98,51,250,63,88,13,254,33,186,32,54,139,101,65,131,77,4,209,110,80,16,22,84,176,156,91,188,227,126,223,39,119,239,117,134,15,238,129,
    193,222,195,206,121,118,158,231,188,15,252,15,225,251,190,180,219,109,249,60,119,58,29,25,12,6,242,54,128,84,42,37,128,0,98,154,102,
    244,174,82,171,41,98,200,171,245,122,220,7,150,101,201,11,192,234,0,174,235,82,44,22,73,167,211,81,206,48,12,28,199,161,86,171,37,227,
    126,189,94,75,92,108,183,91,249,177,6,253,126,95,70,163,17,155,205,6,203,178,104,52,26,84,171,85,202,229,50,134,97,176,223,239,89,46,
    151,204,231,115,14,135,3,142,227,224,121,30,195,225,240,185,38,179,217,76,186,221,174,60,248,78,252,120,158,39,190,239,11,128,182,88,
    44,100,50,153,176,219,237,48,77,147,124,62,79,38,147,137,192,199,227,49,182,109,115,185,92,168,84,42,228,114,57,166,211,41,217,108,150,
    211,233,68,171,213,194,178,44,0,238,247,59,199,227,145,48,12,41,20,10,52,155,205,120,29,122,189,158,0,98,219,118,196,123,169,84,18,64,
    234,245,186,36,189,7,18,4,1,34,130,235,186,81,242,122,189,178,90,173,208,117,253,51,175,189,186,72,114,62,159,191,221,162,184,187,160,
    130,252,232,243,164,88,211,98,251,232,42,99,220,110,183,119,216,205,183,118,240,15,53,65,16,40,25,158,178,217,253,77,211,131,158,228,
    102,247,132,111,194,48,84,30,255,39,252,253,49,197,219,39,248,250,231,170,205,95,18,92,85,220,164,91,245,139,226,3,173,7,253,64,244,
    107,162,174,0,0,0,0,73,69,78,68,174,66,96,130
    };

}
