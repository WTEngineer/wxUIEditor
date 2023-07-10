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
#include <wx/gdicmn.h>
#include <wx/listbox.h>

class Node;

#include <map>
#include <set>

#include "gen_enums.h"

class NodeSearchDlg : public wxDialog
{
public:
    NodeSearchDlg() {}
    NodeSearchDlg(wxWindow *parent, wxWindowID id = wxID_ANY, const wxString& title = "Node Search",
        const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize,
        long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER, const wxString &name = wxDialogNameStr)
    {
        Create(parent, id, title, pos, size, style, name);
    }

    bool Create(wxWindow *parent, wxWindowID id = wxID_ANY, const wxString& title = "Node Search", const wxPoint& pos =
        wxDefaultPosition, const wxSize& size = wxDefaultSize,
        long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER, const wxString &name = wxDialogNameStr);

    bool isSearchGenerators() const { return m_search_generators; }
    bool isSearchVarnames() const { return m_search_varnames; }
    bool isSearchLabels() const { return m_search_labels; }
    bool isSearchIDs() const { return m_search_ids; }

    struct FoundInfo
    {
        const char* name;
        std::vector<Node*> forms;
    };

    std::string& GetNameChoice() { return m_name; }
    Node* GetForm() { return m_form; }
    void FindGenerators(Node* node);
    void FindVariables(Node* node);
    void FindLabels(Node* node);

protected:

    // Event handlers

    void OnGenerators(wxCommandEvent& event);
    void OnIDs(wxCommandEvent& event);
    void OnInit(wxInitDialogEvent& event);
    void OnLabels(wxCommandEvent& event);
    void OnOK(wxCommandEvent& event);
    void OnSelectLocated(wxCommandEvent& event);
    void OnUnused(wxCommandEvent& event);
    void OnVariables(wxCommandEvent& event);

private:

    // Validator variables

    bool m_search_generators { true };
    bool m_search_ids { false };
    bool m_search_labels { false };
    bool m_search_varnames { false };

    // Class member variables

    wxListBox* m_listbox;
    wxListBox* m_listbox_forms;

    std::string m_name;  // could be gen_name, var_name, label or ID
    Node* m_form = nullptr;
    std::map<std::string, std::set<Node*>> m_map_found;
};

// ************* End of generated code ***********
// DO NOT EDIT THIS COMMENT BLOCK!
//
// Code below this comment block will be preserved
// if the code for this class is re-generated.
//
// clang-format on
// ***********************************************
