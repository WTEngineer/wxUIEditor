/////////////////////////////////////////////////////////////////////////////
// Purpose:   Generate C++ and Python events
// Author:    Ralph Walden
// Copyright: Copyright (c) 2020-2023 KeyWorks Software (Ralph Walden)
// License:   Apache License -- see ../../LICENSE
/////////////////////////////////////////////////////////////////////////////

#include <algorithm>

#include "gen_base.h"

#include "../customprops/eventhandler_dlg.h"  // EventHandlerDlg static functions
#include "base_generator.h"                   // BaseGenerator -- Base Generator class
#include "code.h"                             // Code -- Helper class for generating code
#include "file_codewriter.h"                  // FileCodeWriter -- Classs to write code to disk
#include "lambdas.h"                          // Functions for formatting and storage of lamda events
#include "project_handler.h"                  // ProjectHandler class

using namespace code;

extern const char* python_perl_ruby_end_cmt_line;  // "# ************* End of generated code"
extern const char* python_triple_quote;            // "\"\"\"";
extern const char* ruby_begin_cmt_block;           // "# begin";
extern const char* ruby_end_cmt_block;             // "# end";

/////////////////////////////////////////// Default generator event code ///////////////////////////////////////////

void BaseGenerator::GenEvent(Code& code, NodeEvent* event, const std::string& class_name)
{
    Code handler(event->getNode(), code.m_language);
    tt_string event_code;
    if (code.m_language == GEN_LANG_CPLUSPLUS)
    {
        event_code = EventHandlerDlg::GetCppValue(event->get_value());
    }
    else if (code.m_language == GEN_LANG_PYTHON)
    {
        event_code = EventHandlerDlg::GetPythonValue(event->get_value());
    }
    else if (code.m_language == GEN_LANG_RUBY)
    {
        event_code = EventHandlerDlg::GetRubyValue(event->get_value());
    }
    else
    {
        FAIL_MSG("Unknown language");
    }

    if (event_code.empty())
        return;

    // This is what we normally use if an ID is needed. However, a C++ lambda needs to put the
    // ID on it's own line, so we use a string for this to allow the lambda processing code to
    // replace it.

    std::string comma(", ");

    bool is_lambda { false };

    if (event_code.contains("["))
    {
        if (code.is_cpp())
        {
            handler << event->get_name() << ',' << event_code;
            // Put the lambda expression on it's own line
            handler.GetCode().Replace("[", "\n\t[");
            comma = ",\n\t";
            ExpandLambda(handler.GetCode());
            is_lambda = true;
        }
        else if (code.is_python())
        {
            handler.Add(event->get_name()) += ", lambda event:";
            auto body_pos = event_code.find(']') + 1;
            event_code.erase(0, body_pos);
            handler.Str(event_code);
            is_lambda = true;
        }
        else if (code.is_ruby())
        {
            handler << event->get_name() << ',' << event_code;
            // Put the lambda expression on it's own line
            handler.GetCode().Replace("[", "\n\t{");
            comma = ",\n\t";
            ExpandLambda(handler.GetCode());
            is_lambda = true;
        }
    }
    else if (event_code.contains("::"))
    {
        handler.Add(event->get_name()) << ", ";
        if (code.is_cpp())
        {
            if (event_code[0] != '&' && handler.is_cpp())
                handler << '&';
        }
        else
        {
            // We don't know what module this function is in, so I'm not sure this will
            // acutally work. The user will instead need to create a Python function
            // that starts with the module name.
            event_code.Replace("::", ".");
        }

        handler << event_code;
    }
    else
    {
        if (code.is_cpp() || code.is_python())
        {
            handler.Add(event->get_name());
            if (code.is_cpp())
                handler << ", &" << class_name << "::" << event_code << ", this";
            else if (code.is_python())
                handler.Add(", self.") << event_code;
        }
        else if (code.is_ruby())
        {
            tt_string event_name = event->get_name();
            // remove "wx" prefix, make the rest of the name lower case
            event_name.erase(0, 2);
            std::transform(event_name.begin(), event_name.end(), event_name.begin(),
                           [](unsigned char c)
                           {
                               return std::tolower(c);
                           });

            if (event->getNode()->isForm())
                handler.Str(event_name).Str("(:") << event_code << ')';
            else
                handler.Str(event_name).Str("(").NodeName().Str(".get_id, :") << event_code << ')';
        }
    }

    // With lambdas, line breaks have already been added
    code.EnableAutoLineBreak(is_lambda ? false : true);

    // Do *NOT* assume that code.m_node is the same as event->getNode()!

    if (event->getNode()->isStaticBoxSizer())
    {
        code.AddIfPython("self.");
        if (event->get_name() == "wxEVT_CHECKBOX")
        {
            code.Add(event->getNode()->as_string(prop_checkbox_var_name));
        }
        else if (event->get_name() == "wxEVT_RADIOBUTTON")
        {
            code.Add(event->getNode()->as_string(prop_radiobtn_var_name));
        }
        else
        {
            code.NodeName().Function("GetStaticBox()");
        }

        if (code.is_cpp() || code.is_python())
        {
            code.Function("Bind(") << handler.GetCode();
        }
        else if (code.is_ruby())
        {
            code.Function("") << handler.GetCode();
        }

        code.EndFunction();
    }
    else if (event->getNode()->isGen(gen_wxMenuItem) || event->getNode()->isGen(gen_tool) ||
             event->getNode()->isGen(gen_auitool))
    {
        if (code.is_cpp() || code.is_python())
        {
            code.AddIfPython("self.");
            code << "Bind(" << handler.GetCode() << comma;
            if (event->getNode()->as_string(prop_id) != "wxID_ANY")
            {
                auto id = event->getNode()->getPropId();
                code.AddIfPython("id=").Add(id).EndFunction();
            }
            else
            {
                code.AddIfPython("id=").Add(event->getNode()->getNodeName()).Function("GetId()").EndFunction();
            }
        }
        else if (code.is_ruby())
        {
            code << handler;
        }
    }
    else if (event->getNode()->isGen(gen_ribbonTool))
    {
        if (code.is_python())
            code.Add("self.");
        if (!event->getNode()->hasValue(prop_id))
        {
            code.AddComment("**WARNING** -- tool id not specified, event handler may never be called\n");
            if (code.is_cpp() || code.is_python())
            {
                code << "Bind(" << handler.GetCode() << comma;
                code.Add("wxID_ANY").EndFunction();
            }
            else if (code.is_ruby())
            {
                code << handler;
            }
        }
        else
        {
            if (code.is_cpp() || code.is_python())
            {
                code << "Bind(" << handler.GetCode() << comma;
                code.Add(event->getNode()->as_string(prop_id)).EndFunction();
            }
            else if (code.is_ruby())
            {
                code << handler;
            }
        }
    }
    else if (event->getNode()->isForm())
    {
        if (code.is_cpp() || code.is_python())
        {
            code.AddIfPython("self.");
            code << "Bind(" << handler.GetCode();
            code.EndFunction();
        }
        else if (code.is_ruby())
        {
            code << handler;
        }
    }
    else
    {
        if (code.is_cpp() || code.is_python())
        {
            if (code.is_python() && !event->getNode()->isLocal())
                code.Add("self.");
            code.Add(event->getNode()->getNodeName()).Function("Bind(") << handler.GetCode();
            code.EndFunction();
        }
        else if (code.is_ruby())
        {
            code << handler;
        }
    }

    code.EnableAutoLineBreak(true);
}

// This function is called by both C++ and Python code generation.

void BaseCodeGenerator::GenSrcEventBinding(Node* node, EventVector& events)
{
    ASSERT_MSG(events.size(), "GenSrcEventBinding() shouldn't be called if there are no events");
    if (events.empty())
    {
        return;
    }

    auto propName = node->getPropPtr(prop_class_name);
    if (!propName)
    {
        FAIL_MSG(tt_string("Missing \"name\" property in ") << node->declName() << " class.");
        return;
    }

    auto& class_name = propName->as_string();
    if (class_name.empty())
    {
        FAIL_MSG("Property name cannot be null");
        return;
    }

    for (auto& iter: events)
    {
        auto lambda = [](NodeEvent* a, NodeEvent* b)
        {
            return (a->get_name() < b->get_name());
        };

        // Sort events by event name
        std::sort(events.begin(), events.end(), lambda);

        if (auto generator = iter->getNode()->getGenerator(); generator)
        {
            Code code(node, m_language);
            if (generator->GenEvent(code, iter, class_name); code.size())
            {
                if (!code.GetCode().contains("["))
                {
                    m_source->writeLine(code);
                }
                else  // this is a lambda
                {
                    if (!is_cpp())
                    {
                        m_source->writeLine("# You cannot use C++ lambda functions as an event handler in wxPython.");
                    }
                    else
                    {
                        tt_string convert(code.GetCode());
                        convert.Replace("@@", "\n", tt::REPLACE::all);
                        tt_string_vector lines(convert, '\n');
                        bool initial_bracket = false;
                        for (auto& line: lines)
                        {
                            if (line.contains("}"))
                            {
                                m_source->Unindent();
                            }
                            else if (!initial_bracket && line.contains("["))
                            {
                                initial_bracket = true;
                                m_source->Indent();
                            }

                            size_t indentation = indent::auto_no_whitespace;
                            m_source->writeLine(line, indentation);

                            if (line.contains("{"))
                            {
                                m_source->Indent();
                            }
                        }
                        m_source->Unindent();
                    }
                }
            }
        }
    }
}

void BaseCodeGenerator::GenHdrEvents(const EventVector& events)
{
    ASSERT(m_language == GEN_LANG_CPLUSPLUS);

    if (events.size() || m_CtxMenuEvents.size())
    {
        std::set<tt_string> code_lines;

        for (auto& event: events)
        {
            auto event_code = EventHandlerDlg::GetCppValue(event->get_value());
            // Ignore lambda's and functions in another class
            if (event_code.contains("[") || event_code.contains("::"))
                continue;

            tt_string code;

            // If the form has a wxContextMenuEvent node, then the handler for the form's wxEVT_CONTEXT_MENU is a method of
            // the base class and is not virtual.

            if (event->getNode()->isForm() && event->get_name() == "wxEVT_CONTEXT_MENU")
            {
                bool has_handler = false;

                for (const auto& child: event->getNode()->getChildNodePtrs())
                {
                    if (child->isGen(gen_wxContextMenuEvent))
                    {
                        has_handler = true;
                        break;
                    }
                }

                if (has_handler)
                {
                    code << "void " << event_code << "(" << event->getEventInfo()->get_event_class() << "& event);";
                    code_lines.insert(code);
                    continue;
                }
            }
            if ((event->get_name() == "wxEVT_WEBVIEW_FULL_SCREEN_CHANGED" ||
                 event->get_name() == "wxEVT_WEBVIEW_SCRIPT_MESSAGE_RECEIVED") &&
                Project.as_string(prop_wxWidgets_version) == "3.1")
            {
                code << "\n#if wxCHECK_VERSION(3, 1, 5)\n";
                if (m_form_node->as_bool(prop_use_derived_class))
                {
                    code << "virtual void " << event->get_value() << "(" << event->getEventInfo()->get_event_class()
                         << "& event) { event.Skip(); }";
                }
                else
                {
                    code << "void " << event_code << "(" << event->getEventInfo()->get_event_class() << "& event);";
                }
                code << "\n#endif";
            }
            else
            {
                if (m_form_node->as_bool(prop_use_derived_class))
                {
                    code << "virtual void " << event_code << "(" << event->getEventInfo()->get_event_class()
                         << "& event) { event.Skip(); }";
                }
                else
                {
                    code << "void " << event_code << "(" << event->getEventInfo()->get_event_class() << "& event);";
                }
            }
            code_lines.insert(code);
        }

        // Unlike the above code, there shouldn't be any wxEVT_CONTEXT_MENU events since m_CtxMenuEvents should only contain
        // menu items events.

        for (const auto& event: m_CtxMenuEvents)
        {
            auto event_code = EventHandlerDlg::GetCppValue(event->get_value());
            // Ignore lambda's and functions in another class
            if (event_code.contains("[") || event_code.contains("::"))
                continue;

            tt_string code;

            if (m_form_node->as_bool(prop_use_derived_class))
            {
                code << "virtual void " << event_code << "(" << event->getEventInfo()->get_event_class()
                     << "& event) { event.Skip(); }";
            }
            else
            {
                code << "void " << event_code << "(" << event->getEventInfo()->get_event_class() << "& event);";
            }

            code_lines.insert(code);
        }

        if (code_lines.size())
        {
            m_header->writeLine();
            if (m_form_node->as_bool(prop_use_derived_class))
            {
                m_header->writeLine("// Virtual event handlers -- override them in your derived class");
                m_header->writeLine();
            }
            else
            {
                m_header->writeLine("// Event handlers");
                m_header->writeLine();
            }
            for (auto& iter: code_lines)
            {
                m_header->writeLine(iter.subview());
            }
        }
    }
}

// This function simply generates unhandled event handlers in a multi-string comment.

void BaseCodeGenerator::GenPythonEventHandlers(EventVector& events)
{
    ASSERT_MSG(events.size(), "GenPythonEventHandlers() shouldn't be called if there are no events");
    if (events.empty())
    {
        return;
    }

    // Multiple events can be bound to the same function, so use a set to make sure we only generate each function once.
    std::unordered_set<std::string> code_lines;

    Code code(m_form_node, GEN_LANG_PYTHON);
    auto sort_event_handlers = [](NodeEvent* a, NodeEvent* b)
    {
        return (EventHandlerDlg::GetPythonValue(a->get_value()) < EventHandlerDlg::GetPythonValue(b->get_value()));
    };

    // Sort events by function name
    std::sort(events.begin(), events.end(), sort_event_handlers);

    bool inherited_class = m_form_node->hasValue(prop_python_inherit_name);
    if (!inherited_class)
    {
        m_header->Indent();
    }
    else
    {
        m_header->Unindent();
        m_header->writeLine();
    }

    bool found_user_handlers = false;
    if (m_panel_type == NOT_PANEL)
    {
        tt_view_vector org_file;
        tt_string path;

        // Set path to the output file
        if (auto& base_file = m_form_node->as_string(prop_python_file); base_file.size())
        {
            path = Project.getBaseDirectory(m_form_node, GEN_LANG_PYTHON);
            if (path.size())
            {
                path.append_filename(base_file);
            }
            else
            {
                path = base_file;
            }

            if (path.extension().empty())
            {
                path += ".py";
            }
            path.make_absolute();
            path.backslashestoforward();
        }

        // If the user has defined any event handlers, add them to the code_lines set so we
        // don't generate them again.
        if (path.size() && org_file.ReadFile(path))
        {
            size_t line_index;
            for (line_index = 0; line_index < org_file.size(); ++line_index)
            {
                if (org_file[line_index].is_sameprefix(python_perl_ruby_end_cmt_line))
                {
                    break;
                }
            }
            for (++line_index; line_index < org_file.size(); ++line_index)
            {
                auto def = org_file[line_index].view_nonspace();
                if (org_file[line_index].view_nonspace().starts_with("def "))
                {
                    code_lines.emplace(def);
                    found_user_handlers = true;
                }
            }
        }
    }

    if (found_user_handlers)
    {
        code.Str("# Unimplemented Event handler functions\n# Copy any listed and paste them below the comment block, or "
                 "to your inherited class.");
        code.Eol().Str(python_triple_quote).Eol();
    }
    else
    {
        code.Str("# Event handler functions\n# Add these below the comment block, or to your inherited class.");
        code.Eol().Str(python_triple_quote).Eol();
    }
    m_source->writeLine(code);

    code.clear();
    for (auto& event: events)
    {
        auto python_handler = EventHandlerDlg::GetPythonValue(event->get_value());
        // Ignore lambda's
        if (python_handler.starts_with("[python:lambda]"))
            continue;

        tt_string set_code;
        set_code << "def " << python_handler << "(self, event):";
        if (code_lines.find(set_code) != code_lines.end())
            continue;
        code_lines.emplace(set_code);

        code.Str(set_code).Eol();
        code.Tab().Str("event.Skip()").Eol().Eol();
    }

    if (found_user_handlers)
    {
        m_header->writeLine("# Unimplemented Event handler functions");
    }
    else
    {
        m_header->writeLine("# Event handler functions");
    }
    m_header->writeLine(code);

    if (!inherited_class)
    {
        m_header->Unindent();
    }
    code.Eol(eol_if_needed).Str(python_triple_quote).Eol().Eol();
    m_source->writeLine(code);
}

// This function simply generates unhandled event handlers in a multi-string comment.

void BaseCodeGenerator::GenRubyEventHandlers(EventVector& events)
{
    ASSERT_MSG(events.size(), "GenRubyEventHandlers() shouldn't be called if there are no events");
    if (events.empty())
    {
        return;
    }

    // Multiple events can be bound to the same function, so use a set to make sure we only generate each function once.
    std::unordered_set<std::string> code_lines;

    Code code(m_form_node, GEN_LANG_RUBY);
    auto sort_event_handlers = [](NodeEvent* a, NodeEvent* b)
    {
        return (EventHandlerDlg::GetRubyValue(a->get_value()) < EventHandlerDlg::GetRubyValue(b->get_value()));
    };

    // Sort events by function name
    std::sort(events.begin(), events.end(), sort_event_handlers);

    bool inherited_class = m_form_node->hasValue(prop_ruby_inherit_name);
    if (!inherited_class)
    {
        m_header->Indent();
    }
    else
    {
        m_header->Unindent();
        m_header->writeLine();
    }

    bool found_user_handlers = false;
    if (m_panel_type == NOT_PANEL)
    {
        tt_view_vector org_file;
        tt_string path;

        // Set path to the output file
        if (auto& base_file = m_form_node->as_string(prop_ruby_file); base_file.size())
        {
            path = Project.getBaseDirectory(m_form_node, GEN_LANG_RUBY);
            if (path.size())
            {
                path.append_filename(base_file);
            }
            else
            {
                path = base_file;
            }

            if (path.extension().empty())
            {
                path += ".rb";
            }
            path.make_absolute();
            path.backslashestoforward();
        }

        // If the user has defined any event handlers, add them to the code_lines set so we
        // don't generate them again.
        if (path.size() && org_file.ReadFile(path))
        {
            size_t line_index;
            for (line_index = 0; line_index < org_file.size(); ++line_index)
            {
                if (org_file[line_index].is_sameprefix(python_perl_ruby_end_cmt_line))
                {
                    break;
                }
            }
            for (++line_index; line_index < org_file.size(); ++line_index)
            {
                auto def = org_file[line_index].view_nonspace();
                if (org_file[line_index].view_nonspace().starts_with("def "))
                {
                    code_lines.emplace(def);
                    found_user_handlers = true;
                }
            }
        }
    }

    if (found_user_handlers)
    {
        code.Str("# Unimplemented Event handler functions\n# Copy any listed and paste them below the comment block, or "
                 "to your inherited class.");
        code.Eol().Eol();
        m_source->writeLine(code, indent::none);
        m_source->writeLine(ruby_begin_cmt_block, indent::none);
    }
    else
    {
        code.Str("# Event handler functions\n# Add these below the comment block, or to your inherited class.");
        code.Eol().Eol();
        m_source->writeLine(code, indent::none);
        m_source->writeLine(ruby_begin_cmt_block, indent::none);
    }

    code.clear();
    for (auto& event: events)
    {
        auto ruby_handler = EventHandlerDlg::GetRubyValue(event->get_value());
        // Ignore lambda's
        if (ruby_handler.starts_with("[ruby:lambda]"))
            continue;

        tt_string set_code;
        set_code << "def " << ruby_handler;
        if (code_lines.find(set_code) != code_lines.end())
            continue;
        code_lines.emplace(set_code);

        code.Str(set_code).Eol();
        code.Tab().Str("event.skip()").Eol().Unindent();
        code.Str("end").Eol().Eol();
    }

    if (found_user_handlers)
    {
        m_header->writeLine("# Unimplemented Event handler functions");
    }
    else
    {
        m_header->writeLine("# Event handler functions");
    }
    m_header->writeLine(code);

    if (!inherited_class)
    {
        m_header->Unindent();
    }
    code.Eol(eol_if_needed);
    m_source->writeLine(code);
    m_source->writeLine(ruby_end_cmt_block, indent::none);

    // Add a blank line after the comment block so that the final 'end' will be separated from
    // the comment block.
    m_source->writeLine();
}
