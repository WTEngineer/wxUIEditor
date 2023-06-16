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

#include <wx/aui/framemanager.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/statbmp.h>
#include <wx/statbox.h>

#include "images.h"

#include "python_dlg.h"

#include <wx/animate.h>

#include <wx/mstream.h>  // memory stream classes

// Convert a data array into a wxAnimation
inline wxAnimation wxueAnimation(const unsigned char* data, size_t size_data)
{
    wxMemoryInputStream strm(data, size_data);
    wxAnimation animation;
    animation.Load(strm);
    return animation;
};
namespace wxue_img
{
    extern const unsigned char clr_hourglass_gif[2017];
    extern const unsigned char disabled_png[437];
    // face-smile.svg
    extern const unsigned char face_smile_svg[1781];
    extern const unsigned char fontPicker_png[763];
}

bool PythonDlg::Create(wxWindow* parent, wxWindowID id, const wxString& title,
    const wxPoint& pos, const wxSize& size, long style, const wxString &name)
{
    if (!wxDialog::Create(parent, id, title, pos, size, style, name))
        return false;
    if (!wxImage::FindHandler(wxBITMAP_TYPE_GIF))
        wxImage::AddHandler(new wxGIFHandler);
    if (!wxImage::FindHandler(wxBITMAP_TYPE_PNG))
        wxImage::AddHandler(new wxPNGHandler);

    auto* bSizer1 = new wxBoxSizer(wxVERTICAL);

    auto* box_sizer = new wxBoxSizer(wxVERTICAL);

    auiToolBar = new wxAuiToolBar(this, wxID_ANY, wxDefaultPosition, wxDefaultSize,
        wxAUI_TB_PLAIN_BACKGROUND);
    auiToolBar->AddLabel(wxID_ANY, "Label");
    auto* tool_2 = auiToolBar->AddTool(wxID_ANY, "Search",
#if wxCHECK_VERSION(3, 1, 6)
        wxue_img::bundle_fontPicker_png()
#else
        wxBitmap(wxueImage(wxue_img::fontPicker_png, sizeof(wxue_img::fontPicker_png)))
#endif
    , wxNullBitmap, wxITEM_NORMAL, "This tool should be initially disabled.", "This tool should be initially disabled.",
        nullptr);
    tool_2->SetState(wxAUI_BUTTON_STATE_NORMAL|wxAUI_BUTTON_STATE_DISABLED);
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

    m_checkPlayAnimation = new wxCheckBox(this, wxID_ANY, "Play Animation");
    auto* static_box_2 = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY,
#if wxCHECK_VERSION(3, 1, 1)
        m_checkPlayAnimation),
#else
        wxEmptyString),
#endif
    wxVERTICAL);

    m_toggleBtn = new wxToggleButton(static_box_2->GetStaticBox(), wxID_ANY, "Play Animation", wxDefaultPosition,
        wxDefaultSize, wxBU_EXACTFIT);
    static_box_2->Add(m_toggleBtn, wxSizerFlags().Border(wxALL));

    m_animation_ctrl = new wxAnimationCtrl(static_box_2->GetStaticBox(), wxID_ANY, wxueAnimation(wxue_img::clr_hourglass_gif, sizeof(wxue_img::clr_hourglass_gif)),
        wxDefaultPosition, wxDefaultSize, wxAC_DEFAULT_STYLE);
    m_animation_ctrl->SetInactiveBitmap(wxueImage(wxue_img::disabled_png, sizeof(wxue_img::disabled_png)));
    static_box_2->Add(m_animation_ctrl, wxSizerFlags().Border(wxALL));

    box_sizer->Add(static_box_2, wxSizerFlags().Border(wxALL));

    bSizer1->Add(box_sizer, wxSizerFlags().Expand().Border(wxALL));

    auto* stdBtn = CreateStdDialogButtonSizer(wxOK|wxCANCEL);
    bSizer1->Add(CreateSeparatedSizer(stdBtn), wxSizerFlags().Expand().Border(wxALL));

    SetSizerAndFit(bSizer1);
    Centre(wxBOTH);

    // Event handlers
    m_checkPlayAnimation->Bind(wxEVT_CHECKBOX,
        [this](wxCommandEvent&)
        {
            if (m_checkPlayAnimation->GetValue()) 
            {
                m_animation_ctrl->Play();
            }
            else 
            {  
                m_animation_ctrl->Stop();
            }
        });
    Bind(wxEVT_INIT_DIALOG, &PythonDlg::OnInit, this);
    m_toggleBtn->Bind(wxEVT_TOGGLEBUTTON,
        [this](wxCommandEvent&)
        {
            if (m_toggleBtn->GetValue()) 
            {
                m_animation_ctrl->Play();
                m_checkPlayAnimation->SetValue(true);
            }
            else 
            {  
                m_animation_ctrl->Stop();
                m_checkPlayAnimation->SetValue(false);
            }
            Fit();
        });

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
