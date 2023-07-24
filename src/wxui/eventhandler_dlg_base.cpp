///////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor - see https://github.com/KeyWorksRW/wxUiEditor/
//
// Do not edit any code above the "End of generated code" comment block.
// Any changes before that block will be lost if it is re-generated!
///////////////////////////////////////////////////////////////////////////////

// clang-format off

#include <wx/bitmap.h>
#include <wx/button.h>
#include <wx/colour.h>
#include <wx/icon.h>
#include <wx/image.h>
#include <wx/panel.h>
#include <wx/persist.h>
#include <wx/persist/toplevel.h>
#include <wx/settings.h>

#include "ui_images.h"

#include "eventhandler_dlg_base.h"

#include <wx/mstream.h>  // memory stream classes
#include <wx/zstream.h>  // zlib stream classes

#include <memory>  // for std::make_unique

// Convert compressed SVG string into a wxBitmapBundle
inline wxBitmapBundle wxueBundleSVG(const unsigned char* data,
    size_t size_data, size_t size_svg, wxSize def_size)
{
    auto str = std::make_unique<char[]>(size_svg);
    wxMemoryInputStream stream_in(data, size_data);
    wxZlibInputStream zlib_strm(stream_in);
    zlib_strm.Read(str.get(), size_svg);
    return wxBitmapBundle::FromSVG(str.get(), def_size);
};

namespace wxue_img
{
    extern const unsigned char cpp_logo_svg[587];
    extern const unsigned char ruby_logo_svg[1853];
    extern const unsigned char wxPython_1_5x_png[765];
    extern const unsigned char wxPython_2x_png[251];
    extern const unsigned char wxPython_png[399];
}

bool EventHandlerDlgBase::Create(wxWindow* parent, wxWindowID id, const wxString& title,
    const wxPoint& pos, const wxSize& size, long style, const wxString &name)
{
    if (!wxDialog::Create(parent, id, title, pos, size, style, name))
        return false;
    if (!wxImage::FindHandler(wxBITMAP_TYPE_PNG))
        wxImage::AddHandler(new wxPNGHandler);

    auto* parent_sizer = new wxBoxSizer(wxVERTICAL);

    auto* box_sizer = new wxBoxSizer(wxVERTICAL);

    m_static_bind_text = new wxStaticText(this, wxID_ANY, "...");
    m_static_bind_text->Wrap(400);
    box_sizer->Add(m_static_bind_text, wxSizerFlags().Border(wxALL));

    m_notebook = new wxNotebook(this, wxID_ANY);
    {
        wxBookCtrlBase::Images bundle_list;
        bundle_list.push_back(wxue_img::bundle_cpp_logo_svg(16, 16));
        bundle_list.push_back(wxue_img::bundle_wxPython_png());
        bundle_list.push_back(wxueBundleSVG(wxue_img::ruby_logo_svg, 1853, 10034, wxSize(16, 16)));
        m_notebook->SetImages(bundle_list);
    }
    box_sizer->Add(m_notebook, wxSizerFlags().Expand().Border(wxALL));

    auto* cpp_page = new wxPanel(m_notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
    m_notebook->AddPage(cpp_page, "C++", false, 0);
    cpp_page->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNFACE));

    auto* page_sizer = new wxBoxSizer(wxVERTICAL);

    m_cpp_radio_use_function = new wxRadioButton(cpp_page, wxID_ANY, "Use function");
    m_cpp_function_box = new wxStaticBoxSizer(new wxStaticBox(cpp_page, wxID_ANY, m_cpp_radio_use_function), wxVERTICAL);

    m_cpp_text_function = new wxTextCtrl(m_cpp_function_box->GetStaticBox(), wxID_ANY, wxEmptyString);
    m_cpp_function_box->Add(m_cpp_text_function, wxSizerFlags().Expand().Border(wxALL));

    page_sizer->Add(m_cpp_function_box, wxSizerFlags().Expand().Border(wxALL));

    m_cpp_radio_use_lambda = new wxRadioButton(cpp_page, wxID_ANY, "Use lambda");
    m_cpp_lambda_box = new wxStaticBoxSizer(new wxStaticBox(cpp_page, wxID_ANY, m_cpp_radio_use_lambda), wxVERTICAL);

    auto* box_sizer_2 = new wxBoxSizer(wxHORIZONTAL);

    m_check_capture_this = new wxCheckBox(m_cpp_lambda_box->GetStaticBox(), wxID_ANY, "&Capture this");
    m_check_capture_this->SetValue(true);
    box_sizer_2->Add(m_check_capture_this, wxSizerFlags().Border(wxALL));

    m_check_include_event = new wxCheckBox(m_cpp_lambda_box->GetStaticBox(), wxID_ANY, "&Include event parameter");
    box_sizer_2->Add(m_check_include_event, wxSizerFlags().Border(wxALL));

    m_cpp_lambda_box->Add(box_sizer_2, wxSizerFlags().Border(wxALL));

    auto* staticText = new wxStaticText(m_cpp_lambda_box->GetStaticBox(), wxID_ANY, "Lambda body:");
    m_cpp_lambda_box->Add(staticText, wxSizerFlags().Border(wxALL));

    m_cpp_stc_lambda = new wxStyledTextCtrl(m_cpp_lambda_box->GetStaticBox());
    {
        m_cpp_stc_lambda->SetLexer(wxSTC_LEX_CPP);
        m_cpp_stc_lambda->SetEOLMode(wxSTC_EOL_LF);
        m_cpp_stc_lambda->SetWrapMode(wxSTC_WRAP_WORD);
        m_cpp_stc_lambda->SetWrapVisualFlags(wxSTC_WRAPVISUALFLAG_END);
        m_cpp_stc_lambda->SetWrapIndentMode(wxSTC_WRAPINDENT_INDENT);
        m_cpp_stc_lambda->SetMultipleSelection(wxSTC_MULTIPASTE_EACH);
        m_cpp_stc_lambda->SetMultiPaste(wxSTC_MULTIPASTE_EACH);
        m_cpp_stc_lambda->SetAdditionalSelectionTyping(true);
        m_cpp_stc_lambda->SetAdditionalCaretsBlink(true);
        // Sets text margin scaled appropriately for the current DPI on Windows,
        // 5 on wxGTK or wxOSX
        m_cpp_stc_lambda->SetMarginLeft(wxSizerFlags::GetDefaultBorder());
        m_cpp_stc_lambda->SetMarginRight(wxSizerFlags::GetDefaultBorder());
        m_cpp_stc_lambda->SetMarginWidth(1, 0); // Remove default margin
        m_cpp_stc_lambda->SetMarginWidth(0, 16);
        m_cpp_stc_lambda->SetMarginType(0, wxSTC_MARGIN_SYMBOL);
        m_cpp_stc_lambda->SetMarginMask(0, ~wxSTC_MASK_FOLDERS);
        m_cpp_stc_lambda->SetMarginSensitive(0, false);
        m_cpp_stc_lambda->SetIndentationGuides(wxSTC_IV_LOOKFORWARD);
        m_cpp_stc_lambda->SetUseTabs(false);
        m_cpp_stc_lambda->SetTabWidth(4);
        m_cpp_stc_lambda->SetBackSpaceUnIndents(true);
    }
    m_cpp_stc_lambda->SetMinSize(ConvertDialogToPixels(wxSize(200, -1)));
    m_cpp_lambda_box->Add(m_cpp_stc_lambda, wxSizerFlags(1).Expand().DoubleBorder(wxALL));

    page_sizer->Add(m_cpp_lambda_box, wxSizerFlags(1).Expand().Border(wxALL));
    cpp_page->SetSizerAndFit(page_sizer);

    auto* python_page = new wxPanel(m_notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
    m_notebook->AddPage(python_page, "Python", false, 1);
    python_page->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNFACE));

    auto* page_sizer_2 = new wxBoxSizer(wxVERTICAL);

    m_py_radio_use_function = new wxRadioButton(python_page, wxID_ANY, "Use function");
    m_py_function_box = new wxStaticBoxSizer(new wxStaticBox(python_page, wxID_ANY, m_py_radio_use_function), wxVERTICAL);

    m_py_text_function = new wxTextCtrl(m_py_function_box->GetStaticBox(), wxID_ANY, wxEmptyString);
    m_py_function_box->Add(m_py_text_function, wxSizerFlags().Expand().Border(wxALL));

    page_sizer_2->Add(m_py_function_box, wxSizerFlags().Expand().Border(wxALL));

    m_py_radio_use_lambda = new wxRadioButton(python_page, wxID_ANY, "Use lambda");
    m_py_lambda_box = new wxStaticBoxSizer(new wxStaticBox(python_page, wxID_ANY, m_py_radio_use_lambda), wxVERTICAL);

    auto* staticText_2 = new wxStaticText(m_py_lambda_box->GetStaticBox(), wxID_ANY,
        "Lambda expression (event is the parameter):");
    m_py_lambda_box->Add(staticText_2, wxSizerFlags().Border(wxALL));

    m_py_text_lambda = new wxTextCtrl(m_py_lambda_box->GetStaticBox(), wxID_ANY, wxEmptyString);
    m_py_lambda_box->Add(m_py_text_lambda, wxSizerFlags().Expand().Border(wxALL));

    page_sizer_2->Add(m_py_lambda_box, wxSizerFlags(1).Expand().Border(wxALL));
    python_page->SetSizerAndFit(page_sizer_2);

    auto* ruby_page = new wxPanel(m_notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
    m_notebook->AddPage(ruby_page, "Ruby", false, 2);
    ruby_page->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNFACE));

    auto* page_sizer_3 = new wxBoxSizer(wxVERTICAL);

    m_ruby_radio_use_function = new wxRadioButton(ruby_page, wxID_ANY, "Use function");
    m_ruby_function_box = new wxStaticBoxSizer(new wxStaticBox(ruby_page, wxID_ANY, m_ruby_radio_use_function),
        wxVERTICAL);

    m_ruby_text_function = new wxTextCtrl(m_ruby_function_box->GetStaticBox(), wxID_ANY, wxEmptyString);
    m_ruby_function_box->Add(m_ruby_text_function, wxSizerFlags().Expand().Border(wxALL));

    m_ruby_radio_use_lambda = new wxRadioButton(m_ruby_function_box->GetStaticBox(), wxID_ANY, "Use lambda");
    m_ruby_lambda_box = new wxStaticBoxSizer(new wxStaticBox(m_ruby_function_box->GetStaticBox(), wxID_ANY,
        m_ruby_radio_use_lambda), wxVERTICAL);

    auto* box_sizer_3 = new wxBoxSizer(wxHORIZONTAL);

    m_ruby_lambda_box->Add(box_sizer_3, wxSizerFlags().Border(wxALL));

    auto* staticText_3 = new wxStaticText(m_ruby_lambda_box->GetStaticBox(), wxID_ANY, "Lambda body:");
    m_ruby_lambda_box->Add(staticText_3, wxSizerFlags().Border(wxALL));

    m_ruby_stc_lambda = new wxStyledTextCtrl(m_ruby_lambda_box->GetStaticBox());
    {
        m_ruby_stc_lambda->SetLexer(wxSTC_LEX_RUBY);
        m_ruby_stc_lambda->SetEOLMode(wxSTC_EOL_LF);
        m_ruby_stc_lambda->SetWrapMode(wxSTC_WRAP_WORD);
        m_ruby_stc_lambda->SetWrapVisualFlags(wxSTC_WRAPVISUALFLAG_END);
        m_ruby_stc_lambda->SetWrapIndentMode(wxSTC_WRAPINDENT_INDENT);
        m_ruby_stc_lambda->SetMultipleSelection(wxSTC_MULTIPASTE_EACH);
        m_ruby_stc_lambda->SetMultiPaste(wxSTC_MULTIPASTE_EACH);
        m_ruby_stc_lambda->SetAdditionalSelectionTyping(true);
        m_ruby_stc_lambda->SetAdditionalCaretsBlink(true);
        // Sets text margin scaled appropriately for the current DPI on Windows,
        // 5 on wxGTK or wxOSX
        m_ruby_stc_lambda->SetMarginLeft(wxSizerFlags::GetDefaultBorder());
        m_ruby_stc_lambda->SetMarginRight(wxSizerFlags::GetDefaultBorder());
        m_ruby_stc_lambda->SetMarginWidth(1, 0); // Remove default margin
        m_ruby_stc_lambda->SetMarginWidth(0, 16);
        m_ruby_stc_lambda->SetMarginType(0, wxSTC_MARGIN_SYMBOL);
        m_ruby_stc_lambda->SetMarginMask(0, ~wxSTC_MASK_FOLDERS);
        m_ruby_stc_lambda->SetMarginSensitive(0, false);
        m_ruby_stc_lambda->SetIndentationGuides(wxSTC_IV_LOOKFORWARD);
        m_ruby_stc_lambda->SetUseTabs(false);
        m_ruby_stc_lambda->SetTabWidth(4);
        m_ruby_stc_lambda->SetBackSpaceUnIndents(true);
    }
    m_ruby_stc_lambda->SetMinSize(ConvertDialogToPixels(wxSize(200, -1)));
    m_ruby_lambda_box->Add(m_ruby_stc_lambda, wxSizerFlags(1).Expand().DoubleBorder(wxALL));

    m_ruby_function_box->Add(m_ruby_lambda_box, wxSizerFlags(1).Expand().Border(wxALL));

    page_sizer_3->Add(m_ruby_function_box, wxSizerFlags().Expand().Border(wxALL));
    ruby_page->SetSizerAndFit(page_sizer_3);

    parent_sizer->Add(box_sizer, wxSizerFlags(1).Expand().Border(wxALL));

    parent_sizer->AddSpacer(10 + wxSizerFlags::GetDefaultBorder());

    auto* stdBtn = CreateStdDialogButtonSizer(wxOK|wxCANCEL);
    parent_sizer->Add(CreateSeparatedSizer(stdBtn), wxSizerFlags().Expand().Border(wxALL));

    SetSizerAndFit(parent_sizer);
    Centre(wxBOTH);

    wxPersistentRegisterAndRestore(this, "EventHandlerDlgBase");

    // Event handlers
    Bind(wxEVT_BUTTON, &EventHandlerDlgBase::OnOK, this, wxID_OK);
    m_check_capture_this->Bind(wxEVT_CHECKBOX, &EventHandlerDlgBase::OnChange, this);
    m_check_include_event->Bind(wxEVT_CHECKBOX, &EventHandlerDlgBase::OnChange, this);
    Bind(wxEVT_INIT_DIALOG, &EventHandlerDlgBase::OnInit, this);
    m_notebook->Bind(wxEVT_NOTEBOOK_PAGE_CHANGED, &EventHandlerDlgBase::OnPageChanged, this);
    m_cpp_radio_use_function->Bind(wxEVT_RADIOBUTTON, &EventHandlerDlgBase::OnUseFunction, this);
    m_cpp_radio_use_lambda->Bind(wxEVT_RADIOBUTTON, &EventHandlerDlgBase::OnUseLambda, this);
    m_py_radio_use_function->Bind(wxEVT_RADIOBUTTON, &EventHandlerDlgBase::OnUsePythonFunction, this);
    m_py_radio_use_lambda->Bind(wxEVT_RADIOBUTTON, &EventHandlerDlgBase::OnUsePythonLambda, this);
    m_ruby_radio_use_function->Bind(wxEVT_RADIOBUTTON, &EventHandlerDlgBase::OnUsePythonFunction, this);
    m_ruby_radio_use_lambda->Bind(wxEVT_RADIOBUTTON, &EventHandlerDlgBase::OnUseLambda, this);
    m_cpp_text_function->Bind(wxEVT_TEXT, &EventHandlerDlgBase::OnChange, this);
    m_py_text_function->Bind(wxEVT_TEXT, &EventHandlerDlgBase::OnChange, this);
    m_py_text_lambda->Bind(wxEVT_TEXT, &EventHandlerDlgBase::OnChange, this);
    m_ruby_text_function->Bind(wxEVT_TEXT, &EventHandlerDlgBase::OnChange, this);

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
