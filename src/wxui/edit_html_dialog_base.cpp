///////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor - see https://github.com/KeyWorksRW/wxUiEditor/
//
// Do not edit any code above the "End of generated code" comment block.
// Any changes before that block will be lost if it is re-generated!
///////////////////////////////////////////////////////////////////////////////

// clang-format off

#include <wx/button.h>
#include <wx/persist.h>
#include <wx/persist/toplevel.h>
#include <wx/sizer.h>

#include "edit_html_dialog_base.h"

bool EditHtmlDialogBase::Create(wxWindow* parent, wxWindowID id, const wxString& title,
    const wxPoint& pos, const wxSize& size, long style, const wxString &name)
{
    if (!wxDialog::Create(parent, id, title, pos, size, style, name))
        return false;

    auto* parent_sizer = new wxBoxSizer(wxVERTICAL);

    m_splitter = new wxSplitterWindow(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_3D);
    m_splitter->SetSashGravity(0.0);
    m_splitter->SetMinimumPaneSize(250);
    parent_sizer->Add(m_splitter, wxSizerFlags(1).Expand().Border(wxALL));

    m_scintilla = new wxStyledTextCtrl(m_splitter);
    {
        m_scintilla->SetLexer(wxSTC_LEX_HTML);
        m_scintilla->SetEOLMode(wxSTC_EOL_LF);
        m_scintilla->SetWrapMode(wxSTC_WRAP_WORD);
        m_scintilla->SetWrapVisualFlags(wxSTC_WRAPVISUALFLAG_END);
        m_scintilla->SetWrapIndentMode(wxSTC_WRAPINDENT_INDENT);
        m_scintilla->SetMultipleSelection(wxSTC_MULTIPASTE_EACH);
        m_scintilla->SetMultiPaste(wxSTC_MULTIPASTE_EACH);
        m_scintilla->SetAdditionalSelectionTyping(true);
        m_scintilla->SetAdditionalCaretsBlink(true);
        // Sets text margin scaled appropriately for the current DPI on Windows,
        // 5 on wxGTK or wxOSX
        m_scintilla->SetMarginLeft(wxSizerFlags::GetDefaultBorder());
        m_scintilla->SetMarginRight(wxSizerFlags::GetDefaultBorder());
        m_scintilla->SetMarginWidth(1, 0); // Remove default margin
        m_scintilla->SetMarginWidth(0, 16);
        m_scintilla->SetMarginType(0, wxSTC_MARGIN_SYMBOL);
        m_scintilla->SetMarginMask(0, ~wxSTC_MASK_FOLDERS);
        m_scintilla->SetMarginSensitive(0, false);
        m_scintilla->SetIndentationGuides(wxSTC_IV_LOOKFORWARD);
        m_scintilla->SetUseTabs(false);
        m_scintilla->SetTabWidth(4);
        m_scintilla->SetBackSpaceUnIndents(true);
    }
    {
        wxFont font(wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT));
        font.SetSymbolicSize(wxFONTSIZE_LARGE);
        m_scintilla->StyleSetFont(wxSTC_STYLE_DEFAULT, font);
    }

    m_htmlWin = new wxHtmlWindow(m_splitter);
    m_splitter->SplitVertically(m_scintilla, m_htmlWin);

    auto* stdBtn_2 = CreateStdDialogButtonSizer(wxOK|wxCANCEL);
    parent_sizer->Add(CreateSeparatedSizer(stdBtn_2), wxSizerFlags().Expand().Border(wxALL));

    SetSizerAndFit(parent_sizer);
    Centre(wxBOTH);

    wxPersistentRegisterAndRestore(this, "EditHtmlDialogBase");

    // Event handlers
    Bind(wxEVT_INIT_DIALOG, &EditHtmlDialogBase::OnInit, this);
    m_scintilla->Bind(wxEVT_STC_CHANGE, &EditHtmlDialogBase::OnTextChange, this);
    Bind(wxEVT_BUTTON, &EditHtmlDialogBase::OnOK, this, wxID_OK);

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
