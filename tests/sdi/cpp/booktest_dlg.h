///////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor - see https://github.com/KeyWorksRW/wxUiEditor/
//
// Do not edit any code above the "End of generated code" comment block.
// Any changes before that block will be lost if it is re-generated!
///////////////////////////////////////////////////////////////////////////////

// clang-format off

#pragma once

#include <wx/aui/auibook.h>
#include <wx/choicebk.h>
#include <wx/dialog.h>
#include <wx/event.h>
#include <wx/gdicmn.h>
#include <wx/listbook.h>
#include <wx/notebook.h>
#include <wx/stattext.h>
#include <wx/toolbook.h>
#include <wx/treebook.h>

class BookTestDlg : public wxDialog
{
public:
    BookTestDlg() {}
    BookTestDlg(wxWindow *parent, wxWindowID id = wxID_ANY, const wxString& title = "Book tests", const wxPoint& pos =
        wxDefaultPosition, const wxSize& size = wxDefaultSize,
        long style = wxDEFAULT_DIALOG_STYLE, const wxString &name = wxDialogNameStr)
    {
        Create(parent, id, title, pos, size, style, name);
    }

    bool Create(wxWindow *parent, wxWindowID id = wxID_ANY, const wxString& title = "Book tests", const wxPoint& pos =
        wxDefaultPosition, const wxSize& size = wxDefaultSize,
        long style = wxDEFAULT_DIALOG_STYLE, const wxString &name = wxDialogNameStr);

protected:

    // Class member variables

    wxAuiNotebook* m_notebook;
    wxChoicebook* m_choicebook;
    wxListbook* m_listbook;
    wxNotebook* m_notebook_2;
    wxStaticText* m_staticText;
    wxStaticText* m_staticText_10;
    wxStaticText* m_staticText_11;
    wxStaticText* m_staticText_12;
    wxStaticText* m_staticText_13;
    wxStaticText* m_staticText_14;
    wxStaticText* m_staticText_15;
    wxStaticText* m_staticText_16;
    wxStaticText* m_staticText_17;
    wxStaticText* m_staticText_18;
    wxStaticText* m_staticText_2;
    wxStaticText* m_staticText_3;
    wxStaticText* m_staticText_4;
    wxStaticText* m_staticText_5;
    wxStaticText* m_staticText_6;
    wxStaticText* m_staticText_7;
    wxStaticText* m_staticText_8;
    wxStaticText* m_staticText_9;
    wxStaticText* m_staticText__2;
    wxStaticText* m_staticText__3;
    wxToolbook* m_toolbook;
    wxTreebook* m_treebook;
};

// ************* End of generated code ***********
// DO NOT EDIT THIS COMMENT BLOCK!
//
// Code below this comment block will be preserved
// if the code for this class is re-generated.
//
// clang-format on
// ***********************************************
