/////////////////////////////////////////////////////////////////////////////
// Purpose:   Generate Lua code files
// Author:    Ralph Walden
// Copyright: Copyright (c) 2022 KeyWorks Software (Ralph Walden)
// License:   Apache License -- see ../../LICENSE
/////////////////////////////////////////////////////////////////////////////

#include "ttcwd_wx.h"  // cwd -- Class for storing and optionally restoring the current directory

#include "mainframe.h"

#include "base_generator.h"   // BaseGenerator -- Base widget generator class
#include "gen_base.h"         // BaseCodeGenerator -- Generate Base class
#include "gen_common.h"       // Common component functions
#include "gen_lang_common.h"  // Common mulit-language functions
#include "generate_dlg.h"     // GenerateDlg -- Dialog for choosing and generating specific language file(s)
#include "node.h"             // Node class
#include "project_class.h"    // Project class
#include "write_code.h"       // Write code to Scintilla or file

bool GenerateLuaFiles(GenResults& results, std::vector<ttlib::cstr>* pClassList)
{
    auto project = GetProject();
    if (project->GetChildCount() == 0)
    {
        wxMessageBox("You cannot generate any code until you have added a top level form.", "Code Generation");
        return false;
    }
    ttSaveCwd cwd;
    GetProject()->GetProjectPath().ChangeDir();
    ttlib::cstr path;

    bool generate_result = true;
    std::vector<Node*> forms;
    project->CollectForms(forms);

    for (const auto& form: forms)
    {
        if (auto& base_file = form->prop_as_string(prop_lua_file); base_file.size())
        {
            path = base_file;
            if (auto* node_folder = form->get_folder(); node_folder && node_folder->HasValue(prop_folder_lua_output_folder))
            {
                path = node_folder->as_string(prop_folder_lua_output_folder);
                path.append_filename(base_file.filename());
            }
            else if (GetProject()->HasValue(prop_lua_output_folder) && !path.contains("/"))
            {
                path = GetProject()->GetBaseDirectory(GEN_LANG_LUA).utf8_string();
                path.append_filename(base_file);
            }
            path.backslashestoforward();
        }
        else
        {
            results.msgs.emplace_back() << "No Lua filename specified for " << form->prop_as_string(prop_class_name) << '\n';
            continue;
        }

        try
        {
            BaseCodeGenerator codegen(GEN_LANG_LUA);

            auto h_cw = std::make_unique<FileCodeWriter>(path.wx_str());
            codegen.SetHdrWriteCode(h_cw.get());

            path.replace_extension(".lua");
            auto cpp_cw = std::make_unique<FileCodeWriter>(path.wx_str());
            codegen.SetSrcWriteCode(cpp_cw.get());

            codegen.GenerateLuaClass(form);

            auto retval = cpp_cw->WriteFile();

            if (retval > 0)
            {
                if (!pClassList)
                {
                    results.updated_files.emplace_back(path);
                }
                else
                {
                    pClassList->emplace_back(form->prop_as_string(prop_class_name));
                    continue;
                }
            }

            else if (retval < 0)
            {
                results.msgs.emplace_back() << "Cannot create or write to the file " << path << '\n';
            }
            else  // retval == result::exists
            {
                ++results.file_count;
            }
        }
        catch (const std::exception& TESTING_PARAM(e))
        {
            MSG_ERROR(e.what());
            wxMessageBox(ttlib::cstr("An internal error occurred generating code files for ")
                             << form->prop_as_string(prop_lua_file),
                         "Code generation");
            continue;
        }
    }
    return generate_result;
}

using namespace GenEnum;

// clang-format off

// REVIEW: [Randalphwa - 11-13-2022] I'm default to using "ui" as the prefix for all Lua variables. However, that doesn't
// seem like way to set it. A better option would be to let the user both name it and specify whether or not it should be set
// to local.

inline constexpr const auto txt_LuaCmtBlock =
R"===(---------------------------------------------------------------------------------
-- Code generated by wxUiEditor -- see https://github.com/KeyWorksRW/wxUiEditor/
--
-- DO NOT EDIT THIS FILE! Your changes will be lost if it is re-generated!
---------------------------------------------------------------------------------

-- If you run this with lua or luaJIT, you will need to set the LUA_CPATH environment
-- to the location of the wxLua shared library.

require("wx")

)===";

// clang-format on

void BaseCodeGenerator::GenerateLuaClass(Node* form_node, PANEL_PAGE panel_type)
{
    if (form_node->isGen(gen_Images))
    {
        return;
    }

    m_project = GetProject();
    m_form_node = form_node;

    m_panel_type = panel_type;

    EventVector events;
    std::thread thrd_get_events(&BaseCodeGenerator::CollectEventHandlers, this, form_node, std::ref(events));
    std::vector<Node*> forms;
    m_project->CollectForms(forms);

    for (const auto& form: forms)
    {
        if (form->isGen(gen_Images))
        {
            m_ImagesForm = form;
            break;
        }
    }

    m_header->Clear();
    m_source->Clear();

    m_source->writeLine(txt_LuaCmtBlock);
    m_header->writeLine("-- wxLua is available at https://github.com/pkulchenko/wxlua");
    m_header->writeLine("-- Lua information is available at https://www.lua.org/home.html");
    m_header->writeLine("-- LuaJIT information is available at https://luajit.org/");

    thrd_get_events.join();

    auto generator = form_node->GetNodeDeclaration()->GetGenerator();

    if (auto result = generator->GenLuaConstruction(form_node); result)
    {
        m_source->writeLine(result.value(), indent::none);
        m_source->writeLine();
        m_source->Indent();
    }

    size_t auto_indent = indent::auto_no_whitespace;
    if (auto result = generator->GenSettings(form_node, auto_indent, GEN_LANG_LUA); result)
    {
        if (result.value().size())
        {
            m_source->writeLine(result.value(), indent::auto_keep_whitespace);
            m_source->writeLine();
        }
    }

    if (form_node->get_prop_ptr(prop_window_extra_style))
    {
        ttlib::cstr code;
        GenerateWindowSettings(GEN_LANG_LUA, form_node, code);
        if (code.size())
        {
            // GenerateWindowSettings() can result in code within braces, so keep any leading whitespace.
            m_source->writeLine(code, indent::auto_keep_whitespace);
        }
    }

    m_source->SetLastLineBlank();
    for (const auto& child: form_node->GetChildNodePtrs())
    {
        if (child->isGen(gen_wxContextMenuEvent))
            continue;
        GenConstruction(child.get());
    }

    if (auto result = generator->GenAdditionalCode(code_after_children, form_node, GEN_LANG_LUA); result)
    {
        if (result.value().size())
        {
            m_source->writeLine();
            m_source->writeLine(result.value(), indent::none);
        }
    }

    // Make certain indentation is reset after all construction code is written
    m_source->ResetIndent();
}
