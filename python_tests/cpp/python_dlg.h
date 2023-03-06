///////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor - see https://github.com/KeyWorksRW/wxUiEditor/
//
// Do not edit any code above the "End of generated code" comment block.
// Any changes before that block will be lost if it is re-generated!
///////////////////////////////////////////////////////////////////////////////

// clang-format off

#pragma once

#include <wx/aui/auibar.h>
#include <wx/colour.h>
#include <wx/dialog.h>
#include <wx/event.h>
#include <wx/gdicmn.h>
#include <wx/settings.h>
#include <wx/spinctrl.h>
#include <wx/stattext.h>

class PythonDlg : public wxDialog
{
public:
    PythonDlg() {}
    PythonDlg(wxWindow *parent, wxWindowID id = wxID_ANY, const wxString& title = "Hello Python Dialog!",
        const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize,
        long style = wxDEFAULT_DIALOG_STYLE, const wxString &name = wxDialogNameStr)
    {
        Create(parent, id, title, pos, size, style, name);
    }

    bool Create(wxWindow *parent, wxWindowID id = wxID_ANY, const wxString& title = "Hello Python Dialog!",
        const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize,
        long style = wxDEFAULT_DIALOG_STYLE, const wxString &name = wxDialogNameStr);

protected:

    // Event handlers

    void OnInit(wxInitDialogEvent& event);

    // Class member variables

    wxAuiToolBar* auiToolBar;
    wxSpinCtrl* spinCtrl;
    wxStaticText* m_staticText;
};

// ************* End of generated code ***********
// DO NOT EDIT THIS COMMENT BLOCK!
//
// Code below this comment block will be preserved
// if the code for this class is re-generated.
//
// clang-format on
// ***********************************************
