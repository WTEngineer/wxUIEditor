/////////////////////////////////////////////////////////////////////////////
// Purpose:   Data List generator
// Author:    Ralph Walden
// Copyright: Copyright (c) 2023 KeyWorks Software (Ralph Walden)
// License:   Apache License -- see ../../LICENSE
/////////////////////////////////////////////////////////////////////////////

#include <wx/panel.h>     // Base header for wxPanel
#include <wx/sizer.h>     // provide wxSizer class for layout
#include <wx/statbmp.h>   // wxStaticBitmap class interface
#include <wx/stattext.h>  // wxStaticText base header

#include "gen_data_list.h"

#include "bitmaps.h"          // Contains various images handling functions
#include "gen_base.h"         // BaseCodeGenerator -- Generate Src and Hdr files for Base Class
#include "image_handler.h"    // ImageHandler class
#include "mainframe.h"        // MainFrame -- Main window frame
#include "node.h"             // Node class
#include "project_handler.h"  // ProjectHandler class
#include "undo_cmds.h"        // InsertNodeAction -- Undoable command classes derived from UndoAction
#include "utils.h"            // Utility functions that work with properties
#include "write_code.h"       // Write code to Scintilla or file

#include "ui_images.h"

#include "../mockup/mockup_content.h"  // MockupContent -- Mockup of a form's contents
#include "../mockup/mockup_parent.h"   // MockupParent -- Top-level MockUp Parent window

// using namespace wxue_data;

//////////////////////////////////////////  ImagesGenerator  //////////////////////////////////////////

wxObject* DataGenerator::CreateMockup(Node* /* node */, wxObject* wxobject)
{
    auto parent = wxStaticCast(wxobject, wxWindow);

    m_item_name = new wxStaticText(parent, wxID_ANY, "Select an item below to display information about it.");
    m_text_info = new wxStaticText(parent, wxID_ANY, wxEmptyString);

    auto node = wxGetFrame().getSelectedNode();
    if (node->isGen(gen_embedded_image))
    {
        auto bundle = ProjectImages.GetPropertyImageBundle(node->as_string(prop_bitmap));

        tt_view_vector mstr(node->as_string(prop_bitmap), ';');

        if (mstr.size() > 1)
        {
            if (bundle && bundle->lst_filenames.size())
            {
                tt_string list;
                for (auto& iter: bundle->lst_filenames)
                {
                    if (list.size())
                    {
                        list << '\n';
                    }
                    list << iter;
                }
                m_item_name->SetLabel(list.make_wxString());
            }
            else
            {
                m_item_name->SetLabel(mstr[1].make_wxString());
            }
        }
        else
        {
            m_item_name->SetLabel(wxEmptyString);
        }
    }

    auto sizer = new wxBoxSizer(wxVERTICAL);
    sizer->Add(m_item_name, wxSizerFlags(0).Border(wxALL).Expand());
    sizer->Add(m_text_info, wxSizerFlags(0).Border(wxALL).Expand());

    return sizer;
}

int DataGenerator::GetRequiredVersion(Node* node)
{
    if (node->hasValue(prop_auto_update))
    {
        // return minRequiredVer + 5;  // 1.2.1 release
        return minRequiredVer + 4;  // 1.2.0 release
    }

    return minRequiredVer;
}

// clang-format off

inline constexpr const auto txt_get_data_function = R"===(
    // Convert compressed data string into a char array
    std::shared_ptr<char[]> get_data(const unsigned char* data,
        size_t size_data, size_t size_data_uncompressed)
    {
        auto str = std::make_shared_ptr<char[]>(size_data_uncompressed);
        wxMemoryInputStream stream_in(data, size_data);
        wxZlibInputStream zlib_strm(stream_in);
        zlib_strm.Read(str.get(), size_data);
        return str;
    };
)===";

// clang-format on

void BaseCodeGenerator::GenerateDataForm()
{
    ASSERT_MSG(m_form_node, "Attempting to generate Data List when no form was located.");

    if (!m_form_node->getChildCount())
    {
        return;
    }
    if (m_panel_type != HDR_PANEL)
    {
        m_source->writeLine("#include <wx/mstream.h>  // memory stream classes", indent::none);
        m_source->writeLine("#include <wx/zstream.h>  // zlib stream classes", indent::none);

        m_source->writeLine();
        m_source->writeLine("#include <memory>  // for std::make_unique", indent::none);

        m_source->writeLine();
        m_source->writeLine("namespace wxue_data\n{");
        m_source->Indent();
        m_source->SetLastLineBlank();

        tt_string_vector function;
        function.ReadString(txt_get_data_function);
        for (auto& iter: function)
        {
            m_source->writeLine(iter, indent::none);
        }

        // TODO: [Randalphwa - 12-13-2023] Add the actual data here, followed by the function names

        m_source->Unindent();
        m_source->writeLine("}\n");
    }

    /////////////// Header code ///////////////

    if (m_panel_type != CPP_PANEL)
    {
        m_header->writeLine();
        m_header->writeLine("namespace wxue_data\n{");
        m_header->Indent();
        m_header->SetLastLineBlank();
        m_header->writeLine(
            "std::shared_ptr<char[]> get_data(const unsigned char* data, size_t size_data, size_t size_data_uncompressed);");

        m_header->writeLine();

        if (m_form_node->as_bool(prop_add_externs))
        {
            m_header->writeLine();
            for (auto data_child: m_form_node->getChildNodePtrs())
            {
                tt_string line("extern const unsigned char ");
                line << data_child->as_string(prop_string_name) << "[];";
                if (data_child->hasValue(prop_file))
                {
                    line << "  // " << data_child->as_string(prop_file);
                }
                m_header->writeLine(line);
            }
        }

        m_header->Unindent();
        m_header->writeLine("}\n");
    }
}

//////////////////////////////////////////  DataStringGenerator  //////////////////////////////////////////

//////////////////////////////////////////  data_list namespace functions  ////////////////////////////////

Node* data_list::FindDataList()
{
    Node* data_node = nullptr;
    if (Project.getChildCount() > 0)
    {
        if (Project.getChild(0)->isGen(gen_Data))
        {
            data_node = Project.getChild(0);
        }
        else
        {
            for (const auto& iter: Project.getChildNodePtrs())
            {
                if (iter->isGen(gen_Data))
                {
                    data_node = iter.get();
                    break;
                }
            }
        }
    }
    return data_node;
}
