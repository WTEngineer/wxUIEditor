///////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor - see https://github.com/KeyWorksRW/wxUiEditor/
//
// Do not edit any code above the "End of generated code" comment block.
// Any changes before that block will be lost if it is re-generated!
///////////////////////////////////////////////////////////////////////////////

// clang-format off

#pragma once

#include <wx/aui/auibar.h>
#include <wx/bitmap.h>
#include <wx/dialog.h>
#include <wx/event.h>
#include <wx/gdicmn.h>
#include <wx/icon.h>
#include <wx/image.h>
#include <wx/ribbon/art.h>
#include <wx/ribbon/bar.h>
#include <wx/ribbon/control.h>
#include <wx/ribbon/toolbar.h>
#include <wx/toolbar.h>

namespace wxue_img
{
    // Images declared in this class module:

    extern const unsigned char left_svg[585];
    // redo@2x.png
    extern const unsigned char redo_2x_png[1264];
    extern const unsigned char redo_png[945];
    extern const unsigned char undo_png[962];
}

class ToolBarsDialog : public wxDialog
{
public:
    ToolBarsDialog() {}
    ToolBarsDialog(wxWindow *parent, wxWindowID id = wxID_ANY, const wxString& title = "Test Dialog", const wxPoint& pos =
        wxDefaultPosition, const wxSize& size = wxDefaultSize,
        long style = wxDEFAULT_DIALOG_STYLE, const wxString &name = wxDialogNameStr)
    {
        Create(parent, id, title, pos, size, style, name);
    }

    bool Create(wxWindow *parent, wxWindowID id = wxID_ANY, const wxString& title = "Test Dialog", const wxPoint& pos =
        wxDefaultPosition, const wxSize& size = wxDefaultSize,
        long style = wxDEFAULT_DIALOG_STYLE, const wxString &name = wxDialogNameStr);

    enum
    {
        rbn_tool1 = wxID_HIGHEST + 1,
        rbn_tool2,
        rbn_tool3,
        rbn_tool_art,
        rbn_tool_list,
        rbn_tool_svg
    };

protected:

    // Virtual event handlers -- override them in your derived class

    virtual void OnInit(wxInitDialogEvent& event) { event.Skip(); }
    virtual void OnTool(wxCommandEvent& event) { event.Skip(); }

    // Class member variables

    wxAuiToolBar* m_aui_tool_bar;
    wxAuiToolBarItem* m_aui_tool_svg;
    wxRibbonBar* m_rbnBar;
    wxToolBar* m_tool_bar;
    wxToolBarToolBase* m_tool_svg;
};

// ************* End of generated code ***********
// DO NOT EDIT THIS COMMENT BLOCK!
//
// Code below this comment block will be preserved
// if the code for this class is re-generated.
//
// clang-format on
// ***********************************************
