///////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor - see https://github.com/KeyWorksRW/wxUiEditor/
//
// Do not edit any code above the "End of generated code" comment block.
// Any changes before that block will be lost if it is re-generated!
///////////////////////////////////////////////////////////////////////////////

// clang-format off

#include <wx/bitmap.h>
#include <wx/icon.h>
#include <wx/image.h>

#include "form_toolbar_base.h"

#include "../art/french_png.h_img"

#include <wx/mstream.h>  // memory stream classes

// Convert a data array into a wxImage
inline wxImage wxueImage(const unsigned char* data, size_t size_data)
{
    wxMemoryInputStream strm(data, size_data);
    wxImage image;
    image.LoadFile(strm);
    return image;
};

namespace wxue_img
{
    extern const unsigned char english_png[541];
}

MyToolBarBase::MyToolBarBase(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style,
    const wxString& name) : wxToolBar(parent, id, pos, size, style, name)
{

    if (!wxImage::FindHandler(wxBITMAP_TYPE_PNG))
        wxImage::AddHandler(new wxPNGHandler);

    AddTool(wxID_ANY, wxEmptyString,
#if wxCHECK_VERSION(3, 1, 6)

        wxBitmapBundle::FromBitmap(wxueImage(wxue_img::english_png, sizeof(wxue_img::english_png)))
#else
        wxBitmap(wxueImage(wxue_img::english_png, sizeof(wxue_img::english_png)))
#endif
    , wxEmptyString, wxITEM_RADIO);

    AddTool(wxID_ANY, wxEmptyString,
#if wxCHECK_VERSION(3, 1, 6)
        wxBitmapBundle::FromBitmap(wxueImage(french_png, sizeof(french_png)))
#else
        wxBitmap(wxueImage(french_png, sizeof(french_png)))
#endif
    , wxEmptyString, wxITEM_RADIO);

    AddTool(wxID_ANY, wxEmptyString,
#if wxCHECK_VERSION(3, 1, 6)

        wxBitmapBundle::FromBitmap(wxueImage(wxue_img::japanese_png, sizeof(wxue_img::japanese_png)))
#else
        wxBitmap(wxueImage(wxue_img::japanese_png, sizeof(wxue_img::japanese_png)))
#endif
    , wxEmptyString, wxITEM_RADIO);

    m_comboBox = new wxComboBox(this, wxID_ANY);
    m_comboBox->Append("English");
    m_comboBox->Append("French");
    m_comboBox->Append("Japanese");
    m_comboBox->SetStringSelection("English");

    Realize();
}

namespace wxue_img
{

    const unsigned char japanese_png[377] {
        137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,19,0,0,0,15,8,2,0,0,0,137,38,99,123,0,0,0,3,115,66,73,
        84,8,8,8,219,225,79,224,0,0,0,9,112,72,89,115,0,0,10,240,0,0,10,240,1,66,172,52,152,0,0,1,28,73,68,65,84,40,
        207,157,147,205,106,131,64,20,133,239,157,145,49,5,5,209,252,20,146,247,112,31,178,203,182,251,190,89,159,
        161,155,236,36,123,95,163,164,180,26,21,65,161,153,33,215,219,69,154,96,84,146,146,217,205,25,62,230,206,57,
        103,176,105,26,120,104,89,13,51,81,211,230,17,17,152,249,178,5,0,196,150,0,66,8,41,133,69,71,250,57,104,234,
        223,204,204,204,136,8,136,157,19,41,196,211,200,182,6,39,33,163,77,145,155,44,85,227,169,242,3,169,236,129,
        105,251,210,225,251,115,191,221,148,113,68,117,37,29,215,11,87,147,229,122,244,60,191,67,146,209,251,237,38,
        121,127,51,201,14,128,1,80,127,125,0,192,252,229,85,92,223,44,58,111,51,69,94,198,209,25,3,0,54,201,174,140,
        35,93,228,208,50,169,75,50,179,201,82,170,171,51,246,39,83,93,153,44,229,27,36,34,170,241,84,58,238,41,139,
        139,44,29,87,141,167,120,109,242,245,180,136,182,31,120,225,74,205,22,103,24,213,108,225,133,43,229,7,157,
        120,186,14,9,101,79,150,107,0,232,120,219,15,6,181,54,253,38,220,206,243,212,132,97,242,63,29,194,35,209,99,
        189,197,135,255,202,47,147,61,169,40,229,190,213,122,0,0,0,0,73,69,78,68,174,66,96,130
    };

}

// ************* End of generated code ***********
// DO NOT EDIT THIS COMMENT BLOCK!
//
// Code below this comment block will be preserved
// if the code for this class is re-generated.
//
// clang-format on
// ***********************************************
