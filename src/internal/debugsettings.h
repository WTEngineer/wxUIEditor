///////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor - see https://github.com/KeyWorksRW/wxUiEditor/
//
// Do not edit any code above the "End of generated code" comment block.
// Any changes before that block will be lost if it is re-generated!
///////////////////////////////////////////////////////////////////////////////

// clang-format off

#pragma once

#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/event.h>
#include <wx/gdicmn.h>
#include <wx/sizer.h>

class DebugSettings : public wxDialog
{
public:
    DebugSettings() {}
    DebugSettings(wxWindow *parent, wxWindowID id = wxID_ANY, const wxString& title = "Test Settings",
        const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize,
        long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER, const wxString &name = wxDialogNameStr)
    {
        Create(parent, id, title, pos, size, style, name);
    }

    bool Create(wxWindow *parent, wxWindowID id = wxID_ANY, const wxString& title = "Test Settings",
        const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize,
        long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER, const wxString &name = wxDialogNameStr);

private:
    long m_orgFlags;

protected:

    // Event handlers

    void OnInit(wxInitDialogEvent& event);
    void OnOK(wxCommandEvent& event);
    void OnShowNow(wxCommandEvent& event);

    // Validator variables

    bool m_DisplayMsgEvent { false };
    bool m_DisplayMsgInfo { false };
    bool m_DisplayMsgWarnng { false };
    bool m_DisplayMsgWindow { false };
    bool m_FireCreationMsgs { false };

    // Class member variables

    wxButton* m_btn;
    wxStdDialogButtonSizer* std_button_sizer;
};

// ************* End of generated code ***********
// DO NOT EDIT THIS COMMENT BLOCK!
//
// Code below this comment block will be preserved
// if the code for this class is re-generated.
//
// clang-format on
// ***********************************************
