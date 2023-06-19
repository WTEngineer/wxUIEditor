///////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor - see https://github.com/KeyWorksRW/wxUiEditor/
//
// Do not edit any code above the "End of generated code" comment block.
// Any changes before that block will be lost if it is re-generated!
///////////////////////////////////////////////////////////////////////////////

// clang-format off

#pragma once

#include <wx/bitmap.h>
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/event.h>
#include <wx/gdicmn.h>
#include <wx/icon.h>
#include <wx/image.h>
#include <wx/listbox.h>
#include <wx/stattext.h>

class IncludeFilesDialog : public wxDialog
{
public:
    IncludeFilesDialog() {}
    IncludeFilesDialog(wxWindow *parent, wxWindowID id = wxID_ANY, const wxString& title = "Include Files",
        const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize,
        long style = wxDEFAULT_DIALOG_STYLE, const wxString &name = wxDialogNameStr)
    {
        Create(parent, id, title, pos, size, style, name);
    }

    bool Create(wxWindow *parent, wxWindowID id = wxID_ANY, const wxString& title = "Include Files",
        const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize,
        long style = wxDEFAULT_DIALOG_STYLE, const wxString &name = wxDialogNameStr);

protected:

    // Event handlers

    void OnAdd(wxCommandEvent& event);
    void OnInit(wxInitDialogEvent& event);
    void OnItemSelected(wxCommandEvent& event);
    void OnMoveDown(wxCommandEvent& event);
    void OnMoveUp(wxCommandEvent& event);
    void OnRemove(wxCommandEvent& event);
    void OnSort(wxCommandEvent& event);

private:

    // Class member variables

    wxButton* m_btn_move_down;
    wxButton* m_btn_move_up;
    wxButton* m_btn_remove;
    wxButton* m_btn_sort;
    wxListBox* m_listbox;
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
