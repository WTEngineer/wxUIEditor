/////////////////////////////////////////////////////////////////////////////
// Purpose:   Navigation Panel
// Author:    Ralph Walden
// Copyright: Copyright (c) 2020-2021 KeyWorks Software (Ralph Walden)
// License:   Apache License -- see ../LICENSE
/////////////////////////////////////////////////////////////////////////////

#include "pch.h"

#include <wx/imaglist.h>  // wxImageList base header
#include <wx/panel.h>     // Base header for wxPanel
#include <wx/sizer.h>     // provide wxSizer class for layout
#include <wx/toolbar.h>   // wxToolBar interface declaration

#include "nav_panel.h"

#include "bitmaps.h"       // Map of bitmaps accessed by name
#include "cstm_event.h"    // CustomEvent -- Custom Event class
#include "mainframe.h"     // MainFrame -- Main window frame
#include "navpopupmenu.h"  // NavPopupMenu -- Context-menu for an item
#include "node.h"          // Node class
#include "node_creator.h"  // NodeCreator class
#include "node_decl.h"     // NodeDeclaration class
#include "uifuncs.h"       // Miscellaneous functions for displaying UI
#include "undo_cmds.h"     // InsertNodeAction -- Undoable command classes derived from UndoAction

#include "../utils/auto_freeze.h"  // AutoFreeze -- Automatically Freeze/Thaw a window

constexpr size_t MaxLabelLength = 16;

enum
{
    id_NavExpand = wxID_HIGHEST + 1000,
    id_NavCollapse,
    id_NavCollExpand,
    id_NavMoveLeft,
    id_NavMoveRight,
    id_NavMoveUp,
    id_NavMoveDown,
};

NavigationPanel::NavigationPanel(wxWindow* parent, MainFrame* frame) : wxPanel(parent)
{
    m_pMainFrame = frame;

    SetWindowStyle(wxBORDER_RAISED);

    m_tree_ctrl = new wxTreeCtrl(this, wxID_ANY, wxDefaultPosition, wxDefaultSize,
                                 wxTR_HAS_BUTTONS | wxTR_LINES_AT_ROOT | wxTR_DEFAULT_STYLE | wxBORDER_SUNKEN);
    int index = 0;
    m_iconList = new wxImageList(CompImgSize, CompImgSize);

    for (auto iter: g_NodeCreator.GetNodeDeclarationArray())
    {
        if (!iter)
        {
            // This will happen if there is an enumerated value but no generator for it
            continue;
        }
        auto& comp_name = iter->GetClassName();
        m_iconList->Add(iter->GetImage());
        m_iconIdx[comp_name] = index++;
    }

    m_tree_ctrl->AssignImageList(m_iconList);

    auto toolbar = new wxToolBar(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTB_NODIVIDER);
    toolbar->AddTool(id_NavCollExpand, wxEmptyString, GetXPMImage("nav_coll_expand"), wxNullBitmap, wxITEM_NORMAL,
                     "Collapse siblings, expand children",
                     "Expand selected item, collapse all other items at the same level");
    toolbar->AddTool(id_NavExpand, wxEmptyString, GetXPMImage("nav_expand"), wxNullBitmap, wxITEM_NORMAL,
                     "Expand all children", "Expand selected item and all of it's sub-items");
    toolbar->AddTool(id_NavCollapse, wxEmptyString, GetXPMImage("nav_collapse"), wxNullBitmap, wxITEM_NORMAL,
                     "Collapse all siblings", "Collapse selected item and all items at the same level");

    toolbar->AddSeparator();

    toolbar->AddTool(id_NavMoveLeft, "Move Left", GetXPMImage("nav_moveleft"), wxNullBitmap, wxITEM_NORMAL, "Move Left",
                     "Move the selected item left");
    toolbar->AddTool(id_NavMoveUp, "Move Up", GetXPMImage("nav_moveup"), wxNullBitmap, wxITEM_NORMAL, "Move Ip",
                     "Move the selected item up");
    toolbar->AddTool(id_NavMoveDown, "Move Down", GetXPMImage("nav_movedown"), wxNullBitmap, wxITEM_NORMAL, "Move Down",
                     "Move the selected item down");
    toolbar->AddTool(id_NavMoveRight, "Move Right", GetXPMImage("nav_moveright"), wxNullBitmap, wxITEM_NORMAL, "Move Right",
                     "Move the selected item right");

    toolbar->Realize();

    auto toolbar_sizer = new wxBoxSizer(wxHORIZONTAL);
    toolbar_sizer->AddSpacer(50);
    toolbar_sizer->Add(toolbar, wxSizerFlags().Expand().Border(wxBOTTOM | wxTOP));

    auto parent_sizer = new wxBoxSizer(wxVERTICAL);
    parent_sizer->Add(toolbar_sizer, wxSizerFlags().Expand());
    parent_sizer->Add(m_tree_ctrl, wxSizerFlags(1).Expand());

    SetSizerAndFit(parent_sizer);

    Bind(wxEVT_TREE_SEL_CHANGED, &NavigationPanel::OnSelChanged, this);

    Bind(wxEVT_TREE_ITEM_RIGHT_CLICK, &NavigationPanel::OnRightClick, this);
    Bind(wxEVT_TREE_BEGIN_DRAG, &NavigationPanel::OnBeginDrag, this);
    Bind(wxEVT_TREE_END_DRAG, &NavigationPanel::OnEndDrag, this);

    Bind(EVT_NodePropChange, &NavigationPanel::OnNodePropChange, this);
    Bind(EVT_NodeSelected, &NavigationPanel::OnNodeSelected, this);

    Bind(EVT_ProjectUpdated, [this](CustomEvent&) { AddAllNodes(); });

    Bind(EVT_NodeCreated, [this](CustomEvent& event) {
        if (event.GetNode())
        {
            AddNode(event.GetNode(), event.GetNode()->GetParent());
        }
    });
    Bind(EVT_NodeDeleted, [this](CustomEvent& event) { DeleteNode(event.GetNode()); });

    Bind(wxEVT_MENU, &NavigationPanel::OnExpand, this, id_NavExpand);
    Bind(wxEVT_MENU, &NavigationPanel::OnCollapse, this, id_NavCollapse);
    Bind(wxEVT_MENU, &NavigationPanel::OnCollExpand, this, id_NavCollExpand);

    Bind(
        wxEVT_MENU, [this](wxCommandEvent&) { m_pMainFrame->MoveNode(MoveDirection::Down); }, id_NavMoveDown);

    Bind(
        wxEVT_MENU, [this](wxCommandEvent&) { m_pMainFrame->MoveNode(MoveDirection::Left); }, id_NavMoveLeft);

    Bind(
        wxEVT_MENU, [this](wxCommandEvent&) { m_pMainFrame->MoveNode(MoveDirection::Right); }, id_NavMoveRight);

    Bind(
        wxEVT_MENU, [this](wxCommandEvent&) { m_pMainFrame->MoveNode(MoveDirection::Up); }, id_NavMoveUp);

    Bind(wxEVT_UPDATE_UI, &NavigationPanel::OnUpdateEvent, this);

    m_pMainFrame->AddCustomEventHandler(GetEventHandler());
}

Node* NavigationPanel::GetNode(wxTreeItemId item)
{
    if (item.IsOk())
    {
        if (auto iter = m_tree_node_map.find(item); iter != m_tree_node_map.end())
        {
            return iter->second;
        }
    }
    return nullptr;
}

void NavigationPanel::AddAllNodes()
{
    AutoFreeze freeze(this);

    m_tree_ctrl->DeleteAllItems();
    m_tree_node_map.clear();
    m_node_tree_map.clear();

    auto project = wxGetApp().GetProject();
    if (project)
    {
        wxTreeItemId dummy;
        AddChildNodes(project, dummy, true);

        // First we expand everything
        ExpandAllNodes(project);

        // Now we collapse all the project's immediate children

        for (size_t index = 0; index < project->GetChildCount(); ++index)
        {
            if (auto item_it = m_node_tree_map.find(project->GetChild(index)); item_it != m_node_tree_map.end())
            {
                m_tree_ctrl->Collapse(item_it->second);
            }
        }
    }
}

void NavigationPanel::OnSelChanged(wxTreeEvent& event)
{
    auto id = event.GetItem();
    if (!id.IsOk())
        return;

    if (auto iter = m_tree_node_map.find(id); iter != m_tree_node_map.end())
    {
        m_isSelChangeSuspended = true;
        m_pMainFrame->SelectNode(iter->second);
        m_isSelChangeSuspended = false;
    }
}

void NavigationPanel::OnRightClick(wxTreeEvent& event)
{
    auto id = event.GetItem();
    if (auto iter = m_tree_node_map.find(id); iter != m_tree_node_map.end())
    {
        auto menu = new NavPopupMenu(iter->second);
        auto pos = event.GetPoint();
        menu->UpdateUI(menu);
        PopupMenu(menu, pos.x, pos.y);
    }
}

void NavigationPanel::OnBeginDrag(wxTreeEvent& event)
{
    if (event.GetItem() == m_tree_ctrl->GetRootItem())
    {
        return;
    }

    m_drag_node = event.GetItem();
    event.Allow();
}

void NavigationPanel::OnEndDrag(wxTreeEvent& event)
{
    auto itemSrc = m_drag_node;
    m_drag_node = nullptr;

    auto itemDst = event.GetItem();

    // ensure that itemDst is not itemSrc or a child of itemSrc
    auto item = itemDst;
    while (item.IsOk())
    {
        if (item == itemSrc)
        {
            return;
        }
        item = m_tree_ctrl->GetItemParent(item);
    }

    auto node_src = GetNode(itemSrc);
    if (!node_src)
    {
        return;
    }

    auto node_dst = GetNode(itemDst);
    if (!node_dst)
    {
        return;
    }

    // TODO: [KeyWorks - 11-19-2020] Currently, we only allow dragging into a sizer. However, depending on the child, there
    // may be other hosts that would work, such as moving a menuitem or a submenu.

    auto nextSizer = node_dst;
    while (nextSizer && !nextSizer->IsSizer())
    {
        nextSizer = nextSizer->GetParent();
    }

    if (nextSizer)
    {
        if (nextSizer->GetClassName() == "wxStdDialogButtonSizer")
        {
            appMsgBox("You cannot move a control into a wxStdDialogBtnSizer", _tt(strIdMoveTitle));
            return;
        }

        m_pMainFrame->PushUndoAction(std::make_shared<ChangeParentAction>(node_src, nextSizer));

        m_pMainFrame->FireCreatedEvent(node_src);
        m_pMainFrame->SelectNode(node_src, true);
    }
}

void NavigationPanel::AddChildNodes(Node* node, wxTreeItemId& parent, bool is_root)
{
    wxTreeItemId new_parent;

    if (is_root)
        new_parent = m_tree_ctrl->AddRoot("", -1, -1);
    else
    {
        size_t pos = 0;

        auto parent_node = node->GetParent();
        ASSERT(parent_node)
        pos = parent_node->GetChildPosition(node);

        if (pos > 0)
            new_parent = m_tree_ctrl->InsertItem(parent, pos, "", -1, -1);
        else
            new_parent = m_tree_ctrl->AppendItem(parent, "", -1, -1);
    }

    m_node_tree_map[node] = new_parent;
    m_tree_node_map[new_parent] = node;

    auto image_index = GetImageIndex(node);
    m_tree_ctrl->SetItemImage(new_parent, image_index);

    UpdateDisplayName(new_parent, node);

    auto count = node->GetChildCount();
    for (size_t i = 0; i < count; i++)
    {
        AddChildNodes(node->GetChild(i), new_parent);
    }
}

int NavigationPanel::GetImageIndex(Node* node)
{
    const char* name = node->GetNodeDeclaration()->GetClassName().c_str();
    if (ttlib::is_sameas(name, "VerticalBoxSizer"))
    {
        auto& prop = node->prop_as_string(prop_orientation);
        if (prop != "wxVERTICAL")
            name = "wxBoxSizer";
    }
    else if (ttlib::is_sameas(name, "wxBoxSizer"))
    {
        auto& prop = node->prop_as_string(prop_orientation);
        if (prop != "wxHORIZONTAL")
            name = "VerticalBoxSizer";
    }

    if (auto it = m_iconIdx.find(name); it != m_iconIdx.end())
        return it->second;
    else
        return 0;
}

void NavigationPanel::UpdateDisplayName(wxTreeItemId id, Node* node)
{
    ttlib::cstr text;
    auto prop = node->get_prop_ptr(prop_label);
    if (prop && prop->get_value().size())
    {
        text = prop->get_value();
        // Accelerators make the text hard to read, so remove them
        text.Replace("&", "", true);

        if (text.size() > MaxLabelLength)
        {
            text.erase(MaxLabelLength);
            text << "...";
        }
    }
    else if (prop = node->get_prop_ptr(prop_var_name); prop)
    {
        text = prop->get_value();
    }
    else if (prop = node->get_prop_ptr(prop_class_name); prop)
    {
        text = prop->get_value();
    }
    else if (node->GetClassName() == "ribbonTool")
    {
        text = node->prop_as_string(prop_id);
    }

    if (text.empty() && node->GetClassName() == "Project")
    {
        text << _tt(strIdProjectName) << wxGetApp().getProjectFileName().filename();
    }

    // If there is no name then add the class name in parenthesis.
    else if (text.empty())
    {
        text += " (" + node->GetClassName() + ")";
    }

    m_tree_ctrl->SetItemText(id, text.wx_str());
}

void NavigationPanel::ExpandAllNodes(Node* node)
{
    if (auto item_it = m_node_tree_map.find(node); item_it != m_node_tree_map.end())
    {
        m_tree_ctrl->Expand(item_it->second);
    }

    auto count = node->GetChildCount();
    for (size_t i = 0; i < count; i++)
        ExpandAllNodes(node->GetChild(i));
}

void NavigationPanel::AddNode(Node* node, Node* parent)
{
    if (node && parent)
    {
        if (auto it = m_node_tree_map.find(parent); it != m_node_tree_map.end() && it->second.IsOk())
        {
            AddChildNodes(node, it->second, false);
        }
    }
}

void NavigationPanel::DeleteNode(Node* node)
{
    if (auto it = m_node_tree_map.find(node); it != m_node_tree_map.end() && it->second.IsOk())
    {
        m_tree_ctrl->Delete(it->second);
        EraseAllMaps(it->first);
    }
}

void NavigationPanel::EraseAllMaps(Node* node)
{
    if (auto it = m_node_tree_map.find(node); it != m_node_tree_map.end() && it->second.IsOk())
    {
        m_tree_node_map.erase(it->second);
    }

    m_node_tree_map.erase(node);

    for (size_t i = 0; i < node->GetChildCount(); i++)
    {
        EraseAllMaps(node->GetChild(i));
    }
}

void NavigationPanel::OnNodeSelected(CustomEvent& event)
{
    if (m_isSelChangeSuspended)
        return;

    auto node = event.GetNode();
    ASSERT(node);

    if (auto it = m_node_tree_map.find(node); it != m_node_tree_map.end())
    {
        m_tree_ctrl->EnsureVisible(it->second);
        m_tree_ctrl->SelectItem(it->second);
    }
    else
    {
        FAIL_MSG(ttlib::cstr("There is no tree item associated with this object.\n\tClass: ")
                 << node->GetClassName() << "\n\tName: " << node->prop_as_string(prop_var_name).wx_str());
    }
}

void NavigationPanel::OnNodePropChange(CustomEvent& event)
{
    auto prop = event.GetNodeProperty();

    if (prop->isProp(prop_var_name) || prop->isProp(prop_label) || prop->isProp(prop_class_name))
    {
        auto& class_name = prop->GetNode()->GetClassName();
        if (ttlib::contains(class_name, "bookpage"))
        {
            if (auto it = m_node_tree_map.find(prop->GetNode()->GetChild(0)); it != m_node_tree_map.end())
            {
                UpdateDisplayName(it->second, it->first);
            }
        }
        else if (auto it = m_node_tree_map.find(prop->GetNode()); it != m_node_tree_map.end())
        {
            UpdateDisplayName(it->second, it->first);
        }
    }
    else if (prop->GetPropName() == "id" && prop->GetNode()->GetClassName() == "ribbonTool")
    {
        if (auto it = m_node_tree_map.find(prop->GetNode()); it != m_node_tree_map.end())
        {
            UpdateDisplayName(it->second, it->first);
        }
    }

    else if (prop->isProp(prop_orientation))
    {
        if (auto it = m_node_tree_map.find(prop->GetNode()); it != m_node_tree_map.end())
        {
            auto& class_name = it->first->GetNodeDeclaration()->GetClassName();
            if (class_name == "VerticalBoxSizer" || class_name == "wxBoxSizer")
            {
                auto image_index = GetImageIndex(it->first);
                m_tree_ctrl->SetItemImage(it->second, image_index);
            }
        }
    }
}

void NavigationPanel::OnUpdateEvent(wxUpdateUIEvent& event)
{
    auto node = m_pMainFrame->GetSelectedNode();
    if (!node)
    {
        event.Enable(false);
        return;
    }

    switch (event.GetId())
    {
        case id_NavMoveUp:
            event.Enable(m_pMainFrame->MoveNode(node, MoveDirection::Up, true));
            break;

        case id_NavMoveDown:
            event.Enable(m_pMainFrame->MoveNode(node, MoveDirection::Down, true));
            break;

        case id_NavMoveLeft:
            event.Enable(m_pMainFrame->MoveNode(node, MoveDirection::Left, true));
            break;

        case id_NavMoveRight:
            event.Enable(m_pMainFrame->MoveNode(node, MoveDirection::Right, true));
            break;

        case id_NavExpand:
            event.Enable(node->GetChildCount() > 0);
            break;

        case id_NavCollapse:
            event.Enable(node->GetParent() && node->GetParent()->GetChildCount() > 0);
            break;

        case id_NavCollExpand:
            event.Enable((node->GetParent() && node->GetParent()->GetChildCount() > 0) || node->GetChildCount() > 0);
            break;
    }
}

void NavigationPanel::ChangeExpansion(Node* node, bool include_children, bool expand)
{
    if (include_children)
    {
        for (size_t child_index = 0; child_index < node->GetChildCount(); ++child_index)
        {
            auto child = node->GetChild(child_index);
            if (child->GetChildCount())
                ChangeExpansion(child, include_children, expand);
        }
    }
    if (node->GetChildCount())
    {
        if (expand)
        {
            if (auto item = m_node_tree_map.find(node); item != m_node_tree_map.end())
            {
                m_tree_ctrl->Expand(item->second);
            }
        }
        else
        {
            if (auto item = m_node_tree_map.find(node); item != m_node_tree_map.end())
            {
                m_tree_ctrl->Collapse(item->second);
            }
        }
    }
}

void NavigationPanel::OnExpand(wxCommandEvent&)
{
    auto node = m_pMainFrame->GetSelectedNode();
    ASSERT(node);
    if (!node)
        return;  // This is theoretically impossible

    AutoFreeze freeze(this);

    ChangeExpansion(node, true, true);
}

void NavigationPanel::OnCollapse(wxCommandEvent&)
{
    auto node = m_pMainFrame->GetSelectedNode();
    ASSERT(node);
    if (!node)
        return;  // This is theoretically impossible

    AutoFreeze freeze(this);

    auto parent = node->GetParent();
    if (parent && parent->GetChildCount())
    {
        for (size_t child_index = 0; child_index < parent->GetChildCount(); ++child_index)
        {
            ChangeExpansion(parent->GetChild(child_index), false, false);
        }
    }
    else
    {
        ChangeExpansion(node, false, false);
    }
}

void NavigationPanel::OnCollExpand(wxCommandEvent&)
{
    auto node = m_pMainFrame->GetSelectedNode();
    ASSERT(node);
    if (!node)
        return;  // This is theoretically impossible

    AutoFreeze freeze(this);

    auto parent = node->GetParent();
    if (parent && parent->GetChildCount())
    {
        for (size_t child_index = 0; child_index < parent->GetChildCount(); ++child_index)
        {
            if (parent->GetChild(child_index) != node)
                ChangeExpansion(parent->GetChild(child_index), false, false);
        }
    }

    ChangeExpansion(node, true, true);
}
