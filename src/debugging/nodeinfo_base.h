////////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor -- see https://github.com/KeyWorksRW/wxUiEditor/
//
// DO NOT EDIT THIS FILE! Your changes will be lost if it is re-generated!
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/dialog.h>
#include <wx/gdicmn.h>
#include <wx/stattext.h>

class NodeInfoBase : public wxDialog
{
public:
    NodeInfoBase() {}
    NodeInfoBase(wxWindow *parent, wxWindowID id = wxID_ANY, const wxString& title = wxString::FromUTF8("Node Information"),
        const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize,
        long style = wxDEFAULT_DIALOG_STYLE, const wxString &name = wxDialogNameStr)
    {
        Create(parent, id, title, pos, size, style, name);
    }

    bool Create(wxWindow *parent, wxWindowID id = wxID_ANY, const wxString& title = wxString::FromUTF8("Node Information"),
        const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize,
        long style = wxDEFAULT_DIALOG_STYLE, const wxString &name = wxDialogNameStr);

protected:

    // Class member variables

    wxStaticText* m_txt_clipboard;
    wxStaticText* m_txt_generator;
    wxStaticText* m_txt_memory;
    wxStaticText* m_txt_project;
    wxStaticText* m_txt_type;
};
