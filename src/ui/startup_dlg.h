///////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor - see https://github.com/KeyWorksRW/wxUiEditor/
//
// Do not edit any code above the "End of generated code" comment block.
// Any changes before that block will be lost if it is re-generated!
///////////////////////////////////////////////////////////////////////////////

// clang-format off

#pragma once

#include <wx/dialog.h>
#include <wx/event.h>
#include <wx/font.h>
#include <wx/gdicmn.h>
#include <wx/hyperlink.h>
#include <wx/generic/hyperlink.h>
#include <wx/sizer.h>
#include <wx/stattext.h>

namespace wxue_img
{
    // new-project.svg
    extern const unsigned char new_project_svg[921];
}

class StartupDlg : public wxDialog
{
public:
    StartupDlg() {}
    StartupDlg(wxWindow *parent, wxWindowID id = wxID_ANY, const wxString& title = "Open, Import, or Create Project",
        const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize,
        long style = wxDEFAULT_DIALOG_STYLE, const wxString &name = wxDialogNameStr)
    {
        Create(parent, id, title, pos, size, style, name);
    }

    bool Create(wxWindow *parent, wxWindowID id = wxID_ANY, const wxString& title = "Open, Import, or Create Project",
        const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize,
        long style = wxDEFAULT_DIALOG_STYLE, const wxString &name = wxDialogNameStr);

protected:

    // Event handlers

    void OnImport(wxHyperlinkEvent& event);
    void OnInit(wxInitDialogEvent& event);
    void OnNew(wxHyperlinkEvent& event);
    void OnOpen(wxHyperlinkEvent& event);

private:

    // Class member variables

    wxFlexGridSizer* m_recent_flex_grid;
    wxStaticText* m_name_version;
    wxStaticText* m_staticTextRecentProjects;  // // This should be hidden if there actually are any recent projects

// ************* End of generated code ***********
// DO NOT EDIT THIS COMMENT BLOCK!
//
// Code below this comment block will be preserved
// if the code for this class is re-generated.
//
// ***********************************************

    // clang-format on

public:
    enum : size_t
    {
        START_MRU,
        START_CONVERT,
        START_OPEN,
        START_EMPTY,
    };

    auto GetCommandType() const { return m_cmdType; }
    tt_string& GetProjectFile() { return m_value; }

protected:
    void OnHyperlink(wxHyperlinkEvent& event);

private:
    tt_string m_value;
    size_t m_cmdType { START_EMPTY };
};
