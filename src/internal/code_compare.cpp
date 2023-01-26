///////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor - see https://github.com/KeyWorksRW/wxUiEditor/
//
// Do not edit any code above the "End of generated code" comment block.
// Any changes before that block will be lost if it is re-generated!
///////////////////////////////////////////////////////////////////////////////

// clang-format off

#include <wx/sizer.h>
#include <wx/stattext.h>

#include "code_compare.h"

#include "WinMerge.xpm"

bool CodeCompare::Create(wxWindow* parent, wxWindowID id, const wxString& title,
    const wxPoint& pos, const wxSize& size, long style, const wxString &name)
{
    if (!wxDialog::Create(parent, id, title, pos, size, style, name))
        return false;

    auto* dlg_sizer = new wxBoxSizer(wxVERTICAL);

    auto* box_sizer = new wxBoxSizer(wxVERTICAL);

    auto* staticText_2 = new wxStaticText(this, wxID_ANY,
        "If you have WinMergeU.exe installed, and you have previously generated classes, then you can use this to compare what would be generated now. This can be helpful if you need to confirm code generation changes without having to actually write out the code.\n");
    staticText_2->Wrap(320);
    box_sizer->Add(staticText_2, wxSizerFlags().Border(wxLEFT|wxRIGHT|wxTOP, wxSizerFlags::GetDefaultBorder()));

    auto* grid_sizer = new wxGridSizer(3, 0, 0);

    m_radio_cplusplus = new wxRadioButton(this, wxID_ANY, "&C++", wxDefaultPosition, wxDefaultSize, wxRB_GROUP);
    grid_sizer->Add(m_radio_cplusplus, wxSizerFlags().Border(wxALL));

    m_radio_python = new wxRadioButton(this, wxID_ANY, "&Python");
    grid_sizer->Add(m_radio_python, wxSizerFlags().Border(wxALL));

    box_sizer->Add(grid_sizer, wxSizerFlags().Center().Border(wxALL));

    box_sizer->AddSpacer(15);

    auto* staticText = new wxStaticText(this, wxID_ANY, "C&hanged Classes:");
    box_sizer->Add(staticText, wxSizerFlags().Border(wxALL));

    m_list_changes = new wxListBox(this, wxID_ANY);
    m_list_changes->Enable(false);
    m_list_changes->SetMinSize(wxSize(250, 200));
    box_sizer->Add(m_list_changes, wxSizerFlags().Expand().Border(wxALL));

    m_btn = new wxButton(this, wxID_ANY, "&WinMerge...");
        m_btn->SetBitmap(wxBitmapBundle::FromBitmap(wxImage(WinMerge_xpm)));
    m_btn->Enable(false);
    box_sizer->Add(m_btn, wxSizerFlags().Border(wxALL));

    dlg_sizer->Add(box_sizer, wxSizerFlags().Border(wxALL));

    auto* stdBtn = CreateStdDialogButtonSizer(wxCLOSE|wxNO_DEFAULT);
    stdBtn->GetCancelButton()->SetDefault();
    dlg_sizer->Add(CreateSeparatedSizer(stdBtn), wxSizerFlags().Expand().Border(wxALL));

    SetSizerAndFit(dlg_sizer);
    Centre(wxBOTH);

    // Event handlers
    m_btn->Bind(wxEVT_BUTTON, &CodeCompare::OnWinMerge, this);
    Bind(wxEVT_INIT_DIALOG, &CodeCompare::OnInit, this);
    m_radio_cplusplus->Bind(wxEVT_RADIOBUTTON, &CodeCompare::OnCPlusPlus, this);
    m_radio_python->Bind(wxEVT_RADIOBUTTON, &CodeCompare::OnPython, this);

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

/////////////////// Non-generated Copyright/License Info ////////////////////
// Purpose:   Compare code generation
// Author:    Ralph Walden
// Copyright: Copyright (c) 2021-2023 KeyWorks Software (Ralph Walden)
// License:   Apache License -- see ../../LICENSE
/////////////////////////////////////////////////////////////////////////////

#if !defined(INTERNAL_TESTING)
    #error "INTERNAL_TESTING must be defined if you include this moduel!"
#endif

#include <wx/dir.h>  // wxDir is a class for enumerating the files in a directory

#include "gen_base.h"         // BaseCodeGenerator -- Generate Src and Hdr files for Base Class
#include "gen_results.h"      // Code generation file writing functions
#include "node.h"             // Node class
#include "project_handler.h"  // ProjectHandler class

#include "pugixml.hpp"

// clang-format on

CodeCompare::~CodeCompare()
{
    wxDir dir;
    wxArrayString files;

    dir.GetAllFiles(".", &files, "~wxue_**.*");

    for (auto& iter: files)
    {
        wxRemoveFile(iter);
    }

    if (Project.HasValue(prop_base_directory))
    {
        dir.GetAllFiles(Project.as_ttString(prop_base_directory), &files, "~wxue_**.*");

        for (auto& iter: files)
        {
            // ~wxue_.WinMerge will often be added to this list, but deleted before we start processing, so check first
            if (wxFileExists(iter))
            {
                wxRemoveFile(iter);
            }
        }
    }
}

void CodeCompare::OnInit(wxInitDialogEvent& /* event */)
{
    GenResults results;

    GenerateCodeFiles(results, &m_class_list);
    if (m_class_list.size())
    {
        for (auto& iter: m_class_list)
        {
            m_list_changes->AppendString(iter.wx_str());
        }
        m_btn->Enable();
    }
}

void CodeCompare::OnCPlusPlus(wxCommandEvent& /* event */)
{
    GenResults results;

    m_class_list.clear();
    m_list_changes->Clear();

    if (GenerateCodeFiles(results, &m_class_list))
    {
        for (auto& iter: m_class_list)
        {
            m_list_changes->AppendString(iter.wx_str());
        }
        m_btn->Enable();
    }
}

void CodeCompare::OnPython(wxCommandEvent& /* event */)
{
    GenResults results;

    m_class_list.clear();
    m_list_changes->Clear();

    if (GeneratePythonFiles(results, &m_class_list))
    {
        for (auto& iter: m_class_list)
        {
            m_list_changes->AppendString(iter.wx_str());
        }
        m_btn->Enable();
    }
}

// clang-format off

#if defined(_WIN32)

#include <windows.h>

// clang-format on

// Converts all text to UTF16 before calling ShellExecuteW(...)
HINSTANCE winShellRun(std::string_view filename, std::string_view args, std::string_view directory,
                      INT nShow = SW_SHOWNORMAL, HWND hwndParent = NULL);

HINSTANCE winShellRun(std::string_view filename, std::string_view args, std::string_view dir, INT nShow, HWND hwndParent)
{
    std::wstring name16;
    tt::utf8to16(filename, name16);
    std::wstring args16;
    tt::utf8to16(args, args16);
    std::wstring dir16;
    tt::utf8to16(dir, dir16);

    return ShellExecuteW(hwndParent, NULL, name16.c_str(), args16.c_str(), dir16.c_str(), nShow);
}

void CodeCompare::OnWinMerge(wxCommandEvent& /* event */)
{
    pugi::xml_document doc;
    auto root = doc.append_child("project");

    int language = GEN_LANG_CPLUSPLUS;
    if (m_radio_python->GetValue())
        language = GEN_LANG_PYTHON;

    GenerateTmpFiles(m_class_list, root, language);

    doc.save_file("~wxue_.WinMerge");

    // WinMergeU.exe typically is not in the system PATH, and as such, wxExecute won't be able to find it. ShellExecute will
    // find the registered location for the program.

    tt_cwd cwd;

    // /e -- terminate with escape
    // /u -- don't add files to MRU
    winShellRun("WinMergeU.exe", "/e /u ~wxue_.WinMerge", cwd.sub_cstr().c_str());
}

#endif  // _WIN32
