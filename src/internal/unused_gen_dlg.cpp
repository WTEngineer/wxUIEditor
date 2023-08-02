///////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor - see https://github.com/KeyWorksRW/wxUiEditor/
//
// Do not edit any code above the "End of generated code" comment block.
// Any changes before that block will be lost if it is re-generated!
///////////////////////////////////////////////////////////////////////////////

// clang-format off

#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/stattext.h>

#include <unordered_set>

#include "unused_gen_dlg.h"

#include "gen_enums.h"
#include "node.h"
#include "project_handler.h"

bool UnusedGenerators::Create(wxWindow* parent, wxWindowID id, const wxString& title,
    const wxPoint& pos, const wxSize& size, long style, const wxString &name)
{
    if (!wxDialog::Create(parent, id, title, pos, size, style, name))
        return false;

    auto* dlg_sizer = new wxBoxSizer(wxVERTICAL);

    auto* staticText = new wxStaticText(this, wxID_ANY, "Unused generators in the entire project");
    staticText->Wrap(200);
    dlg_sizer->Add(staticText, wxSizerFlags().Border(wxALL));

    m_listbox = new wxListBox(this, wxID_ANY);
    m_listbox->SetMinSize(ConvertDialogToPixels(wxSize(120, 100)));
    dlg_sizer->Add(m_listbox, wxSizerFlags().Expand().Border(wxALL));

    auto* btn = new wxButton(this, wxID_ANY, "&Save...");
    dlg_sizer->Add(btn, wxSizerFlags().Border(wxALL));

    auto* stdBtn = CreateStdDialogButtonSizer(wxOK);
    dlg_sizer->Add(CreateSeparatedSizer(stdBtn), wxSizerFlags().Expand().Border(wxALL));

    SetSizerAndFit(dlg_sizer);
    Centre(wxBOTH);

    // Event handlers
    btn->Bind(wxEVT_BUTTON, &UnusedGenerators::OnSave, this);
    Bind(wxEVT_INIT_DIALOG, &UnusedGenerators::OnInit, this);

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
// Author:    Ralph Walden
// Copyright: Copyright (c) 2023 KeyWorks Software (Ralph Walden)
// License:   Apache License -- see ../../LICENSE
/////////////////////////////////////////////////////////////////////////////

void FindGenerators(Node* node, std::unordered_set<std::string, str_view_hash, std::equal_to<>>& used)
{
    if (node->isGen(gen_Images))
        return;
    if (!node->isGen(gen_folder) && !node->isGen(gen_sub_folder) && !node->isGen(gen_Images))
    {
        if (!used.contains(map_GenNames[node->getGenName()]))
        {
            used.emplace(map_GenNames[node->getGenName()]);
        }
    }
    if (node->getChildCount())
    {
        for (auto& child: node->getChildNodePtrs())
        {
            FindGenerators(child.get(), used);
        }
    }
}

// clang-format off

const auto gen_ignore_list = {

    gen_VerticalBoxSizer,
    gen_gbsizeritem,
    gen_name_array_size,
    gen_oldbookpage,
    gen_sizer_dimension,
    gen_sizeritem,
    gen_splitteritem,

    // These are categories, not actual generators -- this should be kept in sync with the
    // categories in gen_enums.cpp

    gen_Bitmaps,
    gen_Boolean_Validator,
    gen_CPlusSettings,
    gen_Choice_Validator,
    gen_Code,
    gen_Code_Generation,
    gen_Command_Bitmaps,
    gen_DerivedCPlusSettings,
    gen_DlgWindowSettings,
    gen_Integer_Validator,
    gen_List_Validator,
    gen_PythonFrameSettings,
    gen_PythonSettings,
    gen_RubyFrameSettings,
    gen_RubySettings,
    gen_String_Validator,
    gen_Text_Validator,
    gen_Window_Events,
    gen_XRC,
    gen_XrcSettings,
    gen_flexgridsizerbase,
    gen_folder_Code,
    gen_folder_XRC,
    gen_folder_wxPython,
    gen_folder_wxRuby,
    gen_sizer_child,
    gen_sizeritem_settings,
    gen_wxMdiWindow,
    gen_wxPython,
    gen_wxTopLevelWindow,
    gen_wxTreeCtrlBase,
    gen_wxWindow,

    gen_unknown,

};

// clang-format on

void UnusedGenerators::OnInit(wxInitDialogEvent& event)
{
    std::unordered_set<std::string, str_view_hash, std::equal_to<>> used;

    for (const auto& child: Project.getProjectNode()->getChildNodePtrs())
    {
        FindGenerators(child.get(), used);
    }

    bool skipping = true;
    for (auto& iter: rmap_GenNames)
    {
        bool ignored_gen = false;
        for (auto& ignore: gen_ignore_list)
        {
            if (ignore == iter.second)
            {
                ignored_gen = true;
                break;
            }
        }
        if (ignored_gen)
        {
            continue;
        }

        if (skipping)
        {
            if (iter.second != gen_BookPage)
            {
                continue;
            }
            else
            {
                skipping = false;
            }
        }

        if (!used.contains(iter.first))
        {
            m_listbox->Append(wxString::FromUTF8Unchecked(iter.first.data(), iter.first.size()));
        }
    }

    event.Skip();
}

#include <wx/filedlg.h>

void UnusedGenerators::OnSave(wxCommandEvent& WXUNUSED(event))
{
    auto filename = wxSaveFileSelector("Save unused", "txt", wxEmptyString, this);
    if (filename.empty())
        return;

    tt_string_vector file;
    for (unsigned int idx = 0; idx < m_listbox->GetCount(); ++idx)
    {
        file.emplace_back(m_listbox->GetString(idx).ToStdString());
    }

    if (auto result = file.WriteFile(filename.utf8_string()); !result)
    {
        wxMessageBox(wxString("Cannot create or write to the file ") << filename, "Save unused");
    }
}
