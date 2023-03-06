///////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor - see https://github.com/KeyWorksRW/wxUiEditor/
//
// Do not edit any code above the "End of generated code" comment block.
// Any changes before that block will be lost if it is re-generated!
///////////////////////////////////////////////////////////////////////////////

// clang-format off

#if wxCHECK_VERSION(3, 1, 6)
    #include <wx/bmpbndl.h>
#else
    #include <wx/bitmap.h>
#endif

#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/statbmp.h>

#include "images.h"

#include "python_dlg.h"

namespace wxue_img
{
    extern const unsigned char face_smile_svg[1781];
    extern const unsigned char fontPicker_png[763];
}

bool PythonDlg::Create(wxWindow* parent, wxWindowID id, const wxString& title,
    const wxPoint& pos, const wxSize& size, long style, const wxString &name)
{
    if (!wxDialog::Create(parent, id, title, pos, size, style, name))
        return false;
    if (!wxImage::FindHandler(wxBITMAP_TYPE_PNG))
        wxImage::AddHandler(new wxPNGHandler);

    auto* bSizer1 = new wxBoxSizer(wxVERTICAL);

    auto* box_sizer = new wxBoxSizer(wxVERTICAL);

    auiToolBar = new wxAuiToolBar(this, wxID_ANY, wxDefaultPosition, wxDefaultSize,
        wxAUI_TB_PLAIN_BACKGROUND);
    auiToolBar->AddLabel(wxID_ANY, "Label");
    auiToolBar->AddTool(wxID_ANY, "Search",
#if wxCHECK_VERSION(3, 1, 6)
        wxue_img::bundle_fontPicker_png()
#else
        wxBitmap(wxueImage(wxue_img::fontPicker_png, sizeof(wxue_img::fontPicker_png)))
#endif
    );
    auiToolBar->AddSpacer(auiToolBar->FromDIP(10));

    spinCtrl = new wxSpinCtrl(auiToolBar);
    auiToolBar->AddControl(spinCtrl);
    auiToolBar->Realize();
    box_sizer->Add(auiToolBar, wxSizerFlags().Border(wxALL));

    m_staticText = new wxStaticText(this, wxID_ANY, wxString::FromUTF8("wxPython est génial n\'est-ce pas?"),
        ConvertDialogToPixels(wxPoint(50, 100)), ConvertDialogToPixels(wxSize(150, 32)), wxALIGN_CENTER_HORIZONTAL,
        "my_text");
    m_staticText->SetWindowVariant(wxWINDOW_VARIANT_LARGE);
    m_staticText->SetForegroundColour(wxColour(0, 128, 0));
    box_sizer->Add(m_staticText, wxSizerFlags().Center().Border(wxALL));

        auto* bmp = new wxStaticBitmap(this, wxID_ANY, 
#if wxCHECK_VERSION(3, 1, 6)
            wxue_img::bundle_face_smile_svg(32, 32));
#else
        wxBitmap(wxNullBitmap /* SVG images require wxWidgets 3.1.6 */));
#endif
    box_sizer->Add(bmp, wxSizerFlags().Border(wxALL));

    bSizer1->Add(box_sizer, wxSizerFlags().Expand().Border(wxALL));

    auto* stdBtn = CreateStdDialogButtonSizer(wxOK|wxCANCEL);
    bSizer1->Add(CreateSeparatedSizer(stdBtn), wxSizerFlags().Expand().Border(wxALL));

    SetSizerAndFit(bSizer1);
    Centre(wxBOTH);

    // Event handlers
    Bind(wxEVT_INIT_DIALOG, &PythonDlg::OnInit, this);

    return true;
}

// ************* End of generated code ***********
// DO NOT EDIT THIS COMMENT BLOCK!
//
// Code below this comment block will be preserved
// if the code for this class is re-generated.
//
// clang-format on
// ***********************************************

/////////////////// Non-generated Copyright/License Info ////////////////////
// Author:    Ralph Walden
// Copyright: Copyright (c) 2020-2022 KeyWorks Software (Ralph Walden)
// License:   Apache License -- see ../../LICENSE
/////////////////////////////////////////////////////////////////////////////

void PythonDlg::OnInit(wxInitDialogEvent& event)
{
    event.Skip();  // transfer all validator data to their windows and update UI
}

#include "mainframe.h"

void MainFrame::OnPythonDlg(wxCommandEvent& WXUNUSED(event))
{
    PythonDlg dlg(this);
    dlg.ShowModal();
}
