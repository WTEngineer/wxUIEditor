////////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor -- see https://github.com/KeyWorksRW/wxUiEditor/
//
// DO NOT EDIT THIS FILE! Your changes will be lost if it is re-generated!
////////////////////////////////////////////////////////////////////////////////

#include "pch.h"

#include <wx/bitmap.h>
#include <wx/icon.h>
#include <wx/image.h>

#include "ribbon_ids.h"
#include "gen_enums.h"     // Enumerations for generators

using namespace GenEnum;

#include "menudatactrl_base.h"

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
    extern const unsigned char dataview_ctrl_png[245];
    extern const unsigned char dataviewlist_ctrl_png[701];
    extern const unsigned char dataviewtree_ctrl_png[254];
}

MenuDataCtrl::MenuDataCtrl() : wxMenu()
{
    if (!wxImage::FindHandler(wxBITMAP_TYPE_PNG))
        wxImage::AddHandler(new wxPNGHandler);

    auto menu_item = Append(gen_wxDataViewCtrl, wxString::FromUTF8("Insert wxDataViewCtrl"));
    menu_item->SetBitmap(GetImageFromArray(wxue_img::dataview_ctrl_png, sizeof(wxue_img::dataview_ctrl_png)));

    auto menu_item_2 = Append(gen_wxDataViewTreeCtrl, wxString::FromUTF8("Insert wxDataViewTreeCtrl"));
    menu_item_2->SetBitmap(GetImageFromArray(wxue_img::dataviewtree_ctrl_png, sizeof(wxue_img::dataviewtree_ctrl_png)));

    auto menu_item_3 = Append(gen_wxDataViewListCtrl, wxString::FromUTF8("Insert wxDataViewListCtrl"));
    menu_item_3->SetBitmap(GetImageFromArray(wxue_img::dataviewlist_ctrl_png, sizeof(wxue_img::dataviewlist_ctrl_png)));
}

namespace wxue_img
{

    #if (__cplusplus >= 201703L || (defined(_MSVC_LANG) && _MSVC_LANG >= 201703L))
        inline
    #endif
    const unsigned char dataview_ctrl_png[245] {
    137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,21,0,0,0,21,8,2,0,0,0,38,117,50,193,0,0,0,3,115,66,73,84,8,8,8,219,225,79,224,0,
    0,0,9,112,72,89,115,0,0,10,240,0,0,10,240,1,66,172,52,152,0,0,0,152,73,68,65,84,56,203,99,180,155,117,143,129,2,192,194,192,192,112,
    48,85,145,108,253,76,112,86,88,68,8,153,246,67,52,175,186,179,54,44,34,100,213,138,53,150,137,83,208,20,29,159,159,131,211,0,187,89,
    247,254,255,255,255,255,255,255,208,240,224,255,164,3,38,6,202,0,118,253,196,135,5,11,86,109,171,74,137,14,11,172,254,39,62,44,104,227,
    127,226,195,130,133,160,182,195,82,213,248,194,130,160,255,241,135,5,97,247,175,90,177,134,238,254,95,181,98,13,69,254,71,6,228,248,
    31,217,205,248,253,207,130,213,205,228,164,95,226,221,140,12,176,235,39,30,0,0,223,130,154,171,82,229,228,206,0,0,0,0,73,69,78,68,174,
    66,96,130
    };

    #if (__cplusplus >= 201703L || (defined(_MSVC_LANG) && _MSVC_LANG >= 201703L))
        inline
    #endif
    const unsigned char dataviewlist_ctrl_png[701] {
    137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,22,0,0,0,22,8,6,0,0,0,196,180,108,59,0,0,0,4,115,66,73,84,8,8,8,8,124,8,100,136,
    0,0,0,9,112,72,89,115,0,0,10,240,0,0,10,240,1,66,172,52,152,0,0,2,95,73,68,65,84,56,203,189,149,65,75,27,65,24,134,159,217,221,220,76,
    32,26,65,77,79,43,136,136,7,65,208,131,69,40,85,122,241,47,244,234,239,241,218,94,122,239,191,104,236,69,88,106,37,34,88,67,72,64,72,
    194,70,214,53,217,36,147,236,204,244,210,216,172,99,111,218,239,52,251,204,203,203,199,59,223,236,192,43,149,0,216,255,92,55,174,73,
    49,128,86,10,215,117,49,198,160,141,193,117,92,180,209,96,12,142,227,160,181,70,8,129,16,2,165,20,142,227,60,174,93,215,69,9,143,202,
    177,47,60,0,215,164,188,15,191,18,69,17,231,231,231,236,237,237,17,134,33,173,86,139,237,237,109,106,181,26,82,74,214,214,214,184,186,
    186,98,97,97,129,149,149,21,206,206,206,88,93,93,165,88,44,82,169,84,120,187,191,207,247,55,31,1,112,166,141,79,38,19,154,205,38,135,
    135,135,4,65,192,112,56,228,224,224,128,56,142,153,155,155,163,92,46,19,4,1,190,239,179,177,177,65,163,209,96,119,119,151,251,251,123,
    130,32,224,232,232,136,229,229,101,16,226,111,30,239,62,253,50,39,39,39,230,105,181,219,109,83,173,86,45,94,173,86,77,171,213,50,207,
    213,135,47,13,51,211,241,203,151,55,93,104,173,233,118,187,153,205,135,135,7,70,163,145,197,165,148,244,122,61,60,207,179,12,141,49,
    182,241,237,237,173,101,32,165,180,120,146,36,164,105,74,146,36,182,177,46,204,26,11,60,207,99,107,107,43,35,234,116,58,132,97,200,230,
    230,102,134,95,94,94,82,42,149,88,90,90,178,140,157,159,205,217,169,48,47,150,173,21,133,82,138,122,189,158,17,245,251,125,146,36,177,
    120,175,215,67,107,205,96,48,120,198,88,240,127,166,194,117,93,124,223,127,54,227,167,124,48,24,252,51,99,241,173,145,189,121,47,246,
    243,249,115,243,188,233,225,165,105,202,197,197,69,70,52,26,141,144,82,90,60,142,99,146,36,161,211,233,88,198,90,229,179,81,56,142,67,
    185,92,206,136,162,40,34,142,99,139,167,105,74,161,80,160,88,44,218,45,255,232,219,198,165,82,41,163,81,74,33,165,180,120,187,221,38,
    159,207,91,28,192,17,201,127,153,10,193,120,60,230,244,244,212,234,88,41,69,20,69,25,62,30,143,233,118,187,220,220,220,88,134,169,42,
    103,15,47,151,203,177,179,179,147,17,133,97,200,221,221,29,235,235,235,25,126,125,125,205,252,252,60,139,139,139,118,167,181,86,246,
    105,242,76,138,151,203,61,142,203,244,106,26,99,30,159,162,233,247,148,205,142,215,148,13,39,154,202,177,47,94,43,98,126,3,224,19,117,
    44,169,7,104,193,0,0,0,0,73,69,78,68,174,66,96,130
    };

    #if (__cplusplus >= 201703L || (defined(_MSVC_LANG) && _MSVC_LANG >= 201703L))
        inline
    #endif
    const unsigned char dataviewtree_ctrl_png[254] {
    137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,22,0,0,0,22,8,6,0,0,0,196,180,108,59,0,0,0,4,115,66,73,84,8,8,8,8,124,8,100,136,
    0,0,0,9,112,72,89,115,0,0,10,240,0,0,10,240,1,66,172,52,152,0,0,0,160,73,68,65,84,56,203,99,96,160,17,96,100,96,96,96,176,155,117,239,
    63,53,13,61,148,166,196,200,2,227,184,191,94,78,61,131,97,12,187,89,247,254,183,182,182,254,167,22,96,96,96,96,96,194,102,99,88,68,8,
    197,174,102,193,102,232,170,59,107,25,24,24,24,24,44,19,167,96,213,116,124,126,14,233,6,175,90,177,134,36,3,112,1,38,124,146,148,4,9,
    11,62,67,87,149,146,31,36,56,13,166,52,72,152,136,81,68,78,144,176,16,99,232,97,169,106,146,131,132,160,193,228,6,201,104,80,144,22,
    20,228,4,9,11,41,134,178,135,93,34,58,72,136,54,152,212,32,25,122,101,5,205,0,0,145,41,142,166,113,110,231,41,0,0,0,0,73,69,78,68,174,
    66,96,130
    };

}
