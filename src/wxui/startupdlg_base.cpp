////////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor -- see https://github.com/KeyWorksRW/wxUiEditor/
//
// DO NOT EDIT THIS FILE! Your changes will be lost if it is re-generated!
////////////////////////////////////////////////////////////////////////////////

#include <wx/artprov.h>
#include <wx/bmpbndl.h>
#include <wx/button.h>
#include <wx/icon.h>
#include <wx/statbmp.h>
#include <wx/statline.h>

#include "startupdlg_base.h"

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

namespace wxue_img
{
    extern const unsigned char import_svg[418];
    extern const unsigned char new_project_svg[921];
}

bool StartupDlg::Create(wxWindow* parent, wxWindowID id, const wxString& title,
        const wxPoint& pos, const wxSize& size, long style, const wxString &name)
{
    if (!wxDialog::Create(parent, id, title, pos, size, style, name))
        return false;

    SetIcon(wxueBundleSVG(wxue_img::logo_svg, 1943, 7265, wxSize(16, 16)).GetIconFor(this));

    auto* dlg_sizer = new wxBoxSizer(wxVERTICAL);

    auto* box_sizer_6 = new wxBoxSizer(wxHORIZONTAL);
    dlg_sizer->Add(box_sizer_6, wxSizerFlags(1).Expand().Border(wxALL));

    auto* bmp_4 = new wxStaticBitmap(this, wxID_ANY, wxueBundleSVG(wxue_img::logo_svg, 1943, 7265, wxSize(64, 64)));
    box_sizer_6->Add(bmp_4, wxSizerFlags().Border(wxALL));

    box_sizer_6->AddSpacer(10 + wxSizerFlags::GetDefaultBorder());

    m_name_version = new wxStaticText(this, wxID_ANY, "wxUiEditor");
    {
        wxFont font(wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT));
        font.SetSymbolicSize(wxFONTSIZE_X_LARGE);
        m_name_version->SetFont(font);
    }
    box_sizer_6->Add(m_name_version, wxSizerFlags(1).Center().Border(wxALL));

    auto* box_sizer_8 = new wxBoxSizer(wxHORIZONTAL);
    dlg_sizer->Add(box_sizer_8, wxSizerFlags().Border(wxALL));

    auto* box_sizer = new wxBoxSizer(wxVERTICAL);
    box_sizer_8->Add(box_sizer, wxSizerFlags().Border(wxALL));

    auto* staticText = new wxStaticText(this, wxID_ANY, "Recent");
    {
        wxFont font(wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT));
        font.SetSymbolicSize(wxFONTSIZE_X_LARGE);
        font.SetWeight(wxFONTWEIGHT_SEMIBOLD);
        staticText->SetFont(font);
    }
    box_sizer->Add(staticText, wxSizerFlags().Border(wxALL));

    m_staticTextRecentProjects = new wxStaticText(this, wxID_ANY, "Recent projects you have opened will appear here");
    m_staticTextRecentProjects->Wrap(200);
    box_sizer->Add(m_staticTextRecentProjects, wxSizerFlags().Border(wxALL));

    m_recent_flex_grid = new wxFlexGridSizer(2, 0, 0);
    {
        m_recent_flex_grid->AddGrowableCol(1, 1);
        m_recent_flex_grid->SetFlexibleDirection(wxHORIZONTAL);
    }
    box_sizer->Add(m_recent_flex_grid, wxSizerFlags().Border(wxALL));

    auto* static_line_2 = new wxStaticLine(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL);
    box_sizer_8->Add(static_line_2, wxSizerFlags().Expand().Border(wxALL, 20));

    auto* box_sizer_2 = new wxBoxSizer(wxVERTICAL);
    box_sizer_8->Add(box_sizer_2, wxSizerFlags().Border(wxLEFT|wxRIGHT, 15));

    auto* staticText_2 = new wxStaticText(this, wxID_ANY, "Start");
    {
        wxFont font(wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT));
        font.SetSymbolicSize(wxFONTSIZE_X_LARGE);
        font.SetWeight(wxFONTWEIGHT_SEMIBOLD);
        staticText_2->SetFont(font);
    }
    box_sizer_2->Add(staticText_2, wxSizerFlags().Border(wxALL));

    auto* box_sizer_4 = new wxBoxSizer(wxHORIZONTAL);
    box_sizer_2->Add(box_sizer_4, wxSizerFlags().Border(wxALL));

    auto* bmp_2 = new wxStaticBitmap(this, wxID_ANY, wxArtProvider::GetBitmapBundle(wxART_FILE_OPEN, wxART_TOOLBAR));
    box_sizer_4->Add(bmp_2, wxSizerFlags().Border(wxALL));

    auto* hyperlink_2 = new wxGenericHyperlinkCtrl(this, wxID_ANY, "Open...", wxEmptyString, wxDefaultPosition, wxDefaultSize,
        wxHL_DEFAULT_STYLE);
    hyperlink_2->SetFont(wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT));
    hyperlink_2->SetHoverColour(hyperlink_2->GetNormalColour());
    box_sizer_4->Add(hyperlink_2, wxSizerFlags().Center().Border(wxALL));

    auto* box_sizer_3 = new wxBoxSizer(wxHORIZONTAL);
    box_sizer_2->Add(box_sizer_3, wxSizerFlags().Border(wxALL));

    auto* bmp = new wxStaticBitmap(this, wxID_ANY, wxueBundleSVG(wxue_img::import_svg, 418, 1013, wxSize(24, 24)));
    box_sizer_3->Add(bmp, wxSizerFlags().Border(wxALL));

    auto* hyperlink = new wxGenericHyperlinkCtrl(this, wxID_ANY, "Import...", wxEmptyString, wxDefaultPosition, wxDefaultSize,
        wxHL_DEFAULT_STYLE);
    hyperlink->SetFont(wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT));
    hyperlink->SetHoverColour(hyperlink->GetNormalColour());
    box_sizer_3->Add(hyperlink, wxSizerFlags().Center().Border(wxALL));

    auto* box_sizer_5 = new wxBoxSizer(wxHORIZONTAL);
    box_sizer_2->Add(box_sizer_5, wxSizerFlags().Border(wxALL));

    auto* bmp_3 = new wxStaticBitmap(this, wxID_ANY, wxueBundleSVG(wxue_img::new_project_svg, 921, 2208, wxSize(24, 24)));
    box_sizer_5->Add(bmp_3, wxSizerFlags().Border(wxALL));

    auto* hyperlink_3 = new wxGenericHyperlinkCtrl(this, wxID_ANY, "New", wxEmptyString, wxDefaultPosition, wxDefaultSize,
        wxHL_DEFAULT_STYLE);
    hyperlink_3->SetFont(wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT));
    hyperlink_3->SetHoverColour(hyperlink_3->GetNormalColour());
    box_sizer_5->Add(hyperlink_3, wxSizerFlags().Center().Border(wxALL));

    auto* box_sizer_7 = new wxBoxSizer(wxVERTICAL);
    dlg_sizer->Add(box_sizer_7, wxSizerFlags().Expand().Border(wxALL));

    auto* static_line = new wxStaticLine(this);
    box_sizer_7->Add(static_line, wxSizerFlags().Expand().Border(wxALL));

    auto* stdBtn = CreateStdDialogButtonSizer(wxCANCEL|wxNO_DEFAULT);
    stdBtn->GetCancelButton()->SetDefault();
    box_sizer_7->Add(stdBtn, wxSizerFlags(1).Center().Border(wxALL));

    SetSizerAndFit(dlg_sizer);
    Centre(wxBOTH);

    // Event handlers
    Bind(wxEVT_INIT_DIALOG, &StartupDlg::OnInit, this);
    hyperlink_2->Bind(wxEVT_HYPERLINK, &StartupDlg::OnOpen, this);
    hyperlink->Bind(wxEVT_HYPERLINK, &StartupDlg::OnImport, this);
    hyperlink_3->Bind(wxEVT_HYPERLINK, &StartupDlg::OnNew, this);

    return true;
}

namespace wxue_img
{

    const unsigned char logo_svg[1943] {
    120,218,213,89,219,110,219,70,16,237,167,16,244,75,2,144,204,222,47,138,157,151,20,104,10,212,232,67,27,163,200,75,161,
    72,212,37,145,37,131,146,221,56,95,223,51,187,75,145,178,21,69,190,180,64,108,192,154,93,206,206,206,158,153,57,59,148,
    79,215,55,211,55,167,227,122,178,206,230,227,179,156,4,171,120,254,230,116,49,95,214,195,230,151,102,56,158,215,203,77,
    246,5,227,207,131,89,83,79,206,242,147,97,30,148,235,60,155,166,231,239,151,243,205,250,44,191,94,215,205,31,87,195,81,
    253,251,242,253,186,247,248,207,102,184,92,79,86,205,229,89,126,57,220,52,243,47,47,120,197,240,35,11,134,223,86,46,149,
    134,228,138,82,114,95,113,102,94,230,217,23,126,150,11,1,5,110,24,207,179,91,12,141,85,21,115,154,9,60,21,103,57,135,
    174,23,18,207,48,80,244,204,243,252,213,61,255,201,223,33,142,181,222,172,174,178,213,100,178,174,55,103,57,203,179,245,
    230,118,81,159,229,52,93,142,86,139,85,51,104,234,241,235,48,92,225,32,243,205,237,128,199,211,210,156,55,154,108,7,35,
    247,87,158,76,38,53,171,217,189,213,237,118,59,134,44,25,122,181,235,229,97,212,63,198,229,147,39,160,206,42,173,180,
    54,1,117,86,73,128,168,129,182,171,52,183,133,21,149,97,54,97,206,165,175,148,76,136,107,193,42,171,132,119,17,113,33,
    68,101,165,143,136,119,207,246,99,254,241,40,204,129,220,228,219,160,91,182,5,189,7,229,49,86,88,223,138,120,48,226,163,
    184,124,250,164,60,151,82,113,147,242,60,202,165,103,149,112,200,119,45,45,160,87,109,158,123,83,9,38,19,230,150,87,90,
    56,239,91,204,89,229,148,78,89,142,130,48,66,224,217,126,204,71,199,97,206,216,33,204,245,145,152,83,198,31,12,222,163,
    19,125,246,204,137,238,121,165,2,234,182,146,94,246,18,221,200,157,60,239,103,185,11,172,211,229,249,30,196,119,92,31,
    71,215,231,207,156,49,90,85,22,37,90,42,37,250,9,67,196,40,68,116,190,75,138,232,62,146,201,10,179,117,127,155,78,251,
    83,102,124,116,153,78,246,16,220,54,216,238,248,74,61,100,69,60,54,101,62,61,115,202,8,105,66,206,160,78,15,115,227,247,
    114,230,21,93,172,111,78,167,193,203,191,206,127,251,245,231,191,133,255,59,111,103,166,6,145,121,115,122,181,90,220,
    78,87,203,22,176,241,124,125,181,24,222,14,230,75,58,250,235,201,124,177,24,156,120,132,216,35,205,174,86,243,37,29,144,
    19,135,20,10,236,173,179,36,171,32,155,78,22,76,116,178,235,100,201,59,29,169,238,201,193,102,4,54,121,102,226,221,122,
    140,159,181,173,71,117,207,207,190,15,125,223,184,35,89,234,224,155,239,228,190,111,125,159,69,88,43,93,144,121,39,223,
    241,83,6,63,135,155,217,97,39,13,253,230,25,86,94,102,202,146,53,78,198,110,0,1,203,102,89,201,29,195,31,206,162,116,
    147,149,52,255,53,187,132,128,141,25,105,150,194,6,85,197,72,129,6,95,147,47,216,221,248,192,163,77,61,66,194,82,145,
    86,196,225,212,168,144,112,200,53,201,71,108,140,27,247,159,249,120,51,195,2,134,138,156,213,243,233,12,53,133,77,226,
    22,100,215,248,200,176,211,109,50,89,166,243,35,14,47,36,159,8,22,14,127,158,41,135,243,24,150,93,100,58,123,151,209,
    73,164,214,56,22,183,174,226,154,103,11,32,96,42,99,208,39,144,2,151,164,162,72,36,189,139,76,201,32,11,9,126,50,217,
    111,153,100,6,23,150,15,54,63,100,231,25,135,121,69,138,130,65,79,89,218,137,38,232,25,48,45,148,9,102,85,64,148,135,
    157,189,142,72,115,97,43,231,21,26,21,150,113,94,81,203,162,72,1,125,139,112,14,158,197,73,21,213,173,161,1,5,12,122,
    38,68,198,112,176,167,8,71,208,69,156,66,211,104,97,31,107,227,161,74,75,22,145,126,222,184,110,22,147,189,88,90,198,
    143,74,170,93,92,53,206,198,2,76,116,98,65,167,196,92,56,183,162,28,226,244,80,7,224,227,161,238,236,41,219,224,246,2,
    204,25,49,206,230,30,133,137,202,113,110,36,179,129,196,100,197,172,103,86,136,194,152,74,51,197,189,47,132,171,44,78,
    38,209,91,147,181,189,199,216,103,153,85,28,121,150,184,49,136,40,61,171,93,250,120,153,183,142,49,222,166,94,168,41,
    227,43,169,10,30,83,9,113,146,34,27,101,66,85,218,80,140,148,10,79,17,11,32,29,7,225,47,33,197,25,66,144,189,205,4,162,
    41,165,174,240,137,220,9,159,5,165,28,234,17,10,65,124,23,183,129,50,86,195,84,152,236,47,11,48,147,185,11,100,85,82,
    197,36,183,170,221,153,86,145,151,157,191,31,182,229,25,162,122,221,44,94,156,212,47,67,136,187,75,43,14,155,235,69,61,
    88,174,150,95,235,102,133,91,173,89,125,14,195,58,201,101,40,225,129,116,175,47,135,205,231,186,41,215,155,97,179,9,26,
    93,160,125,143,177,2,114,28,172,198,180,197,21,196,240,82,100,0,91,169,208,168,75,142,0,104,28,42,100,181,71,107,128,
    84,245,72,104,166,42,95,160,181,161,71,220,161,167,1,192,149,64,214,129,178,176,172,40,137,216,112,174,18,236,202,97,
    23,180,85,89,20,155,70,219,160,101,4,132,0,83,218,6,64,16,98,153,0,49,188,144,123,34,168,82,4,69,65,229,164,149,108,71,
    74,98,57,167,66,182,112,65,7,223,177,59,147,240,2,222,226,48,165,208,168,52,56,1,131,156,124,4,49,122,133,18,71,152,188,
    178,84,1,9,252,109,39,15,67,169,190,208,59,224,231,219,145,168,111,234,229,106,60,238,71,162,143,115,71,200,13,24,25,
    249,235,148,202,179,230,182,147,73,68,39,67,132,173,123,172,203,105,144,232,88,202,61,233,49,121,88,122,116,20,238,35,
    133,183,193,63,39,212,149,65,113,33,198,18,184,190,75,217,78,200,3,48,225,128,60,174,122,79,101,8,154,181,190,29,129,
    18,41,87,110,186,72,177,66,36,136,73,19,85,71,154,96,205,178,93,17,135,109,9,33,82,65,95,16,131,38,149,184,178,27,166,
    37,169,150,56,15,187,164,101,196,156,160,153,160,3,38,133,63,60,188,98,198,225,215,93,208,122,53,50,56,113,44,68,117,
    167,100,144,52,198,153,118,142,184,105,52,188,26,124,188,222,108,250,115,159,208,97,12,154,213,245,178,13,121,121,57,
    223,212,205,98,142,143,129,216,154,28,15,215,179,97,211,128,230,250,181,73,179,177,85,29,108,53,187,156,211,140,123,195,
    15,215,173,239,110,223,231,167,83,222,167,211,243,196,94,69,184,69,182,12,153,104,142,102,81,166,69,100,179,32,198,152,
    94,180,217,243,54,76,38,18,237,150,145,28,108,5,241,93,71,145,137,31,195,52,239,173,36,57,153,188,216,82,47,239,182,222,
    174,211,61,135,247,241,233,244,105,124,138,235,255,96,108,112,27,221,33,85,73,52,132,30,31,79,118,72,117,135,83,117,159,
    83,157,119,59,172,106,14,177,170,187,207,170,45,110,68,171,1,23,196,90,180,192,128,88,73,222,18,107,138,165,74,65,233,
    45,149,1,114,244,57,204,239,225,85,177,203,171,230,113,188,74,245,135,55,249,199,241,42,16,61,138,88,117,228,213,192,
    175,71,19,235,236,177,196,10,175,236,49,61,219,14,19,17,14,238,199,97,162,45,49,208,141,33,219,11,35,177,195,127,120,
    97,36,154,120,208,141,97,30,126,97,244,18,172,199,180,79,160,84,193,191,241,226,181,211,184,202,212,155,10,246,208,206,
    85,88,29,201,86,51,244,224,32,26,170,101,229,88,236,92,97,79,105,29,58,215,240,38,20,247,161,202,143,198,194,180,236,
    173,36,57,153,4,145,155,86,27,179,244,61,68,96,250,180,146,124,237,185,253,225,224,251,101,168,171,249,211,249,87,29,
    38,96,126,135,128,193,101,145,128,189,254,159,8,184,197,50,176,104,120,237,179,17,99,66,138,58,219,126,132,223,198,64,
    169,24,6,221,91,170,67,24,204,243,17,240,157,160,236,225,227,17,27,61,190,207,5,244,199,53,186,244,165,50,30,227,205,
    244,187,132,252,205,60,250,244,120,126,230,119,58,95,10,75,104,125,133,73,76,22,203,229,191,100,178,84,131,15,235,125,
    169,18,31,215,251,126,247,2,114,204,253,136,173,48,130,233,251,95,86,188,162,127,45,254,244,47,130,170,200,113
    };

}
