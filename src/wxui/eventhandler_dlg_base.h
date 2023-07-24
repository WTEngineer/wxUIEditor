///////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor - see https://github.com/KeyWorksRW/wxUiEditor/
//
// Do not edit any code above the "End of generated code" comment block.
// Any changes before that block will be lost if it is re-generated!
///////////////////////////////////////////////////////////////////////////////

// clang-format off

#pragma once

#include <wx/checkbox.h>
#include <wx/dialog.h>
#include <wx/event.h>
#include <wx/gdicmn.h>
#include <wx/notebook.h>
#include <wx/radiobut.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/stattext.h>
#include <wx/stc/stc.h>
#include <wx/textctrl.h>

class EventHandlerDlgBase : public wxDialog
{
public:
    EventHandlerDlgBase() {}
    EventHandlerDlgBase(wxWindow *parent, wxWindowID id = wxID_ANY, const wxString& title = "Event Handler",
        const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize,
        long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER, const wxString &name = wxDialogNameStr)
    {
        Create(parent, id, title, pos, size, style, name);
    }

    bool Create(wxWindow *parent, wxWindowID id = wxID_ANY, const wxString& title = "Event Handler",
        const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize,
        long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER, const wxString &name = wxDialogNameStr);

protected:

    // Virtual event handlers -- override them in your derived class

    virtual void OnChange(wxCommandEvent& event) { event.Skip(); }
    virtual void OnInit(wxInitDialogEvent& event) { event.Skip(); }
    virtual void OnOK(wxCommandEvent& event) { event.Skip(); }
    virtual void OnPageChanged(wxBookCtrlEvent& event) { event.Skip(); }
    virtual void OnUseFunction(wxCommandEvent& event) { event.Skip(); }
    virtual void OnUseLambda(wxCommandEvent& event) { event.Skip(); }
    virtual void OnUsePythonFunction(wxCommandEvent& event) { event.Skip(); }
    virtual void OnUsePythonLambda(wxCommandEvent& event) { event.Skip(); }

    // Class member variables

    wxCheckBox* m_check_capture_this;
    wxCheckBox* m_check_include_event;
    wxNotebook* m_notebook;
    wxRadioButton* m_cpp_radio_use_function;
    wxStaticBoxSizer* m_cpp_function_box;
    wxRadioButton* m_cpp_radio_use_lambda;
    wxStaticBoxSizer* m_cpp_lambda_box;
    wxRadioButton* m_py_radio_use_function;
    wxStaticBoxSizer* m_py_function_box;
    wxRadioButton* m_py_radio_use_lambda;
    wxStaticBoxSizer* m_py_lambda_box;
    wxRadioButton* m_ruby_radio_use_function;
    wxStaticBoxSizer* m_ruby_function_box;
    wxRadioButton* m_ruby_radio_use_lambda;
    wxStaticBoxSizer* m_ruby_lambda_box;
    wxStaticText* m_static_bind_text;
    wxStyledTextCtrl* m_cpp_stc_lambda;
    wxStyledTextCtrl* m_ruby_stc_lambda;
    wxTextCtrl* m_cpp_text_function;
    wxTextCtrl* m_py_text_function;
    wxTextCtrl* m_py_text_lambda;
    wxTextCtrl* m_ruby_text_function;
};

// ************* End of generated code ***********
// DO NOT EDIT THIS COMMENT BLOCK!
//
// Code below this comment block will be preserved
// if the code for this class is re-generated.
//
// clang-format on
// ***********************************************
