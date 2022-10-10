////////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor -- see https://github.com/KeyWorksRW/wxUiEditor/
//
// DO NOT EDIT THIS FILE! Your changes will be lost if it is re-generated!
////////////////////////////////////////////////////////////////////////////////

#include <wx/artprov.h>
#include <wx/bitmap.h>
#include <wx/icon.h>
#include <wx/image.h>

#include "navtoolbar_base.h"

#include <wx/mstream.h>  // memory stream classes
#include <wx/zstream.h>  // zlib stream classes

#include <memory>  // for std::make_unique

// Convert compressed SVG string into a wxBitmapBundle
inline wxBitmapBundle wxueBundleSVG(const unsigned char* data,
    size_t size_data, size_t size_svg, wxSize def_size)
{
    auto str = std::make_unique<char[]>(size_svg);
    wxMemoryInputStream stream_in(data, size_data);
    wxZlibInputStream zlib_strm(stream_in);
    zlib_strm.Read(str.get(), size_svg);
    return wxBitmapBundle::FromSVG(str.get(), def_size);
};

NavToolbar::NavToolbar(wxWindow* parent, wxWindowID id, 
        const wxPoint& pos, const wxSize& size, long style) :
    wxToolBar(parent, id, pos, size, style)
{

    AddTool(id_NavCollExpand, wxEmptyString, wxueBundleSVG(wxue_img::nav_coll_expand_svg, 249, 482, wxSize(16, 16)), wxNullBitmap, wxITEM_NORMAL, 
            "Collapse siblings, expand children", "Expand selected item, collapse all other items at the same level");

    AddTool(id_NavExpand, wxEmptyString, wxueBundleSVG(wxue_img::nav_expand_svg, 248, 410, wxSize(16, 16)), wxNullBitmap, wxITEM_NORMAL, 
            "Expand all children", "Expand selected item and all of it's sub-items");

    AddTool(id_NavCollapse, wxEmptyString, wxueBundleSVG(wxue_img::nav_collapse_svg, 244, 432, wxSize(16, 16)), wxNullBitmap, wxITEM_NORMAL, 
            "Collapse all siblings", "Collapse selected item and all items at the same level");

    AddSeparator();
    AddTool(id_NavMoveLeft, wxEmptyString, wxArtProvider::GetBitmapBundle(wxART_GO_BACK, wxART_MENU), wxNullBitmap, wxITEM_NORMAL, 
            "Move Left", "Move the selected item left");

    AddTool(id_NavMoveUp, wxEmptyString, wxArtProvider::GetBitmapBundle(wxART_GO_UP, wxART_MENU), wxNullBitmap, wxITEM_NORMAL, 
            "Move Up", "Move the selected item up");

    AddTool(id_NavMoveDown, wxEmptyString, wxArtProvider::GetBitmapBundle(wxART_GO_DOWN, wxART_MENU), wxNullBitmap, wxITEM_NORMAL, 
            "Move Down", "Move the selected item down");

    AddTool(id_NavMoveRight, wxEmptyString, wxArtProvider::GetBitmapBundle(wxART_GO_FORWARD, wxART_OTHER), wxNullBitmap, wxITEM_NORMAL, 
            "Move Right", "Move the selected item right");

}

namespace wxue_img
{

    const unsigned char nav_coll_expand_svg[249] {
    120,218,85,81,193,118,131,32,16,236,167,236,35,215,168,32,49,70,171,158,211,67,175,61,228,70,43,1,95,176,250,212,152,
    151,191,47,32,74,51,92,150,157,217,217,133,45,198,89,84,69,205,175,35,52,117,137,76,64,40,138,170,66,64,243,123,27,127,
    88,207,115,49,116,247,190,237,106,94,34,197,158,124,64,158,82,236,155,171,18,125,180,76,112,100,29,4,73,80,85,244,108,
    146,48,78,79,165,107,174,141,82,249,14,227,19,198,248,125,156,134,238,198,131,71,83,79,50,39,33,53,64,160,235,90,200,
    150,91,124,218,147,52,204,44,96,134,32,134,51,164,142,202,32,89,34,10,95,64,14,225,209,2,8,117,252,139,116,243,51,90,
    178,214,249,172,132,53,25,111,145,110,24,135,216,194,36,221,20,18,98,125,230,85,117,240,114,105,230,11,12,103,20,103,
    32,120,157,201,247,185,192,167,239,180,255,247,0,234,252,83,109,227,229,153,23,108,218,163,115,125,109,225,199,191,44,
    127,111,126,157,36,118,125,145,222,106,100,118,251,246,7,157,48,114,179
    };

    const unsigned char nav_collapse_svg[244] {
    120,218,109,145,205,82,132,48,16,132,125,148,169,120,21,200,228,7,18,4,206,122,240,234,193,91,148,44,80,155,21,10,112,
    173,245,233,77,128,93,14,218,167,78,77,247,212,151,154,98,58,55,85,81,219,195,4,93,93,146,96,184,72,73,82,21,13,116,159,
    199,233,195,12,54,111,198,254,107,56,245,181,45,137,51,23,59,146,125,228,204,187,117,37,121,62,153,198,146,101,69,195,
    133,34,85,49,152,185,133,105,190,56,95,58,116,206,229,247,116,209,227,52,143,253,209,70,223,93,61,183,57,198,60,136,128,
    47,190,192,246,226,236,1,105,156,46,130,87,200,98,189,72,66,11,122,77,48,117,117,28,206,192,182,172,188,57,120,130,125,
    195,109,43,188,173,132,1,77,176,229,147,255,81,170,63,148,52,166,140,201,76,100,59,167,64,170,16,87,78,164,28,61,167,
    138,41,69,65,21,91,57,81,107,161,245,230,228,138,41,117,202,60,251,230,184,15,70,215,121,180,87,126,118,76,137,24,48,
    19,127,163,36,92,234,238,23,239,71,112,18
    };

    const unsigned char nav_expand_svg[248] {
    120,218,101,81,203,78,195,48,16,228,83,44,115,5,103,189,126,135,36,103,56,112,229,192,45,16,55,137,234,146,40,73,65,253,
    123,236,150,166,138,184,141,52,143,29,205,22,243,119,91,21,141,223,205,164,111,74,154,128,51,154,102,85,209,146,254,107,
    63,127,214,163,207,219,105,56,142,135,161,241,37,13,245,201,79,244,70,133,250,195,135,146,190,28,234,214,211,115,68,235,
    140,165,85,49,214,75,71,230,229,20,162,105,215,135,144,223,3,88,0,120,154,151,105,216,251,199,159,190,89,186,28,153,64,
    141,134,146,104,124,37,150,73,137,78,160,125,224,154,73,97,20,121,35,28,153,141,224,153,40,6,168,184,64,36,156,105,48,
    66,112,157,104,96,42,250,56,74,231,220,70,181,134,69,149,100,74,163,2,80,132,71,77,244,24,228,82,27,194,197,134,92,115,
    58,34,152,228,198,2,254,129,235,165,181,77,42,120,17,156,51,174,125,17,54,249,183,14,239,151,113,210,42,92,137,255,3,
    142,225,56,167,213,179,248,141,44,253,228,238,23,218,50,103,79
    };

}
