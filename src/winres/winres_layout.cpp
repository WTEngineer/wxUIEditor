/////////////////////////////////////////////////////////////////////////////
// Purpose:   resForm layout code
// Author:    Ralph Walden
// Copyright: Copyright (c) 2020-2021 KeyWorks Software (Ralph Walden)
// License:   Apache License -- see ../../LICENSE
/////////////////////////////////////////////////////////////////////////////

#include "tttextfile.h"  // textfile -- Classes for reading and writing line-oriented files

#include "winres_form.h"

#include "node_creator.h"  // NodeCreator -- Class used to create nodes

void resForm::CreateDialogLayout()
{
    if (!m_ctrls.size())
        return;  // empty dialog -- rare, but it does happen

    SortCtrls();

    // dlg_sizer is the top level sizer for the entire dialog

    auto dlg_sizer = g_NodeCreator.CreateNode(gen_VerticalBoxSizer, m_form_node.get());
    dlg_sizer->prop_set_value(prop_var_name, "dlg_sizer");
    m_form_node->Adopt(dlg_sizer);

    for (size_t idx_child = 0; idx_child < m_ctrls.size(); ++idx_child)
    {
        auto& child = m_ctrls[idx_child];
        // A group box will have added a bunch of children, so if the current child has been added already then ignore it.
        // Note that children can appear to the left or right of a group box, which is why we can't just step over a group of
        // children when a group box is encountered.
        if (child.isAdded())
            continue;

        if (child.isGen(gen_wxButton))
        {
            if (ProcessStdButton(dlg_sizer.get(), idx_child))
            {
                continue;
            }
        }
        // Special handling for last control
        if (idx_child + 1 >= m_ctrls.size())
        {
            // If last control is a button, we may need to center or right-align it.
            if (child.isGen(gen_wxButton))
            {
                int dlg_margin = (du_width() / 2) - child.du_width();
                if (child.du_left() > dlg_margin)
                {
                    if (child.du_left() + child.du_width() < (du_width() - dlg_margin))
                        child.prop_set_value(prop_alignment, "wxALIGN_CENTER_HORIZONTAL");
                    else
                        child.prop_set_value(prop_alignment, "wxALIGN_RIGHT");
                }
            }

            ASSERT_MSG(!child.isGen(gen_wxStaticBoxSizer), "Ignoring group box with no children")
            if (!child.isGen(gen_wxStaticBoxSizer))
            {
                // orphaned child, add to form's top level sizer
                dlg_sizer->Adopt(child.GetNodePtr());
            }
            break;
        }

        // Check for a possible row
        if (is_same_top(&child, &m_ctrls[idx_child + 1]))
        {
            // If there is more than one child with the same top position, then create a horizontal box sizer
            // and add all children with the same top position.
            auto sizer = g_NodeCreator.CreateNode(gen_wxBoxSizer, dlg_sizer.get());
            dlg_sizer->Adopt(sizer);
            sizer->prop_set_value(prop_orientation, "wxHORIZONTAL");

            while (idx_child < m_ctrls.size() && is_same_top(&child, &m_ctrls[idx_child]))
            {
                if (m_ctrls[idx_child].isAdded())
                    break;  // means there was a static box to the right

                if (m_ctrls[idx_child].GetNode()->isGen(gen_wxStaticBoxSizer))
                {
                    // Group boxes can have controls to the left and right that are lower than the top of the box. That means
                    // that they will have been sorted after the group box, but must be added before it.

                    AddStaticBoxChildren(m_ctrls[idx_child], idx_child);
                }

                // Note that we add the child we are comparing to first.
                sizer->Adopt(m_ctrls[idx_child].GetNodePtr());
                ++idx_child;
            }
            if (idx_child < m_ctrls.size() && m_ctrls[idx_child].isAdded())
                continue;

            // In order to properly step through the loop
            --idx_child;

            if (m_ctrls[idx_child].du_left() + m_ctrls[idx_child].du_width() > du_width() - 10)
            {
                sizer->prop_set_value(prop_alignment, "wxALIGN_RIGHT");
            }
        }

        // Add one or more controls vertically
        else
        {
            if (child.GetNode()->isGen(gen_wxStaticBoxSizer))
            {
                AddStaticBoxChildren(child, idx_child);

                // There may be a control to the left or right of the group box but not at the same top position.

                std::vector<resCtrl*> a_left_siblings;
                std::vector<resCtrl*> a_right_siblings;

                for (size_t side_child = idx_child + 1; side_child < m_ctrls.size(); side_child++)
                {
                    if (m_ctrls[side_child].isAdded())
                        continue;

                    if (is_within_vertical(&m_ctrls[side_child], &m_ctrls[idx_child]))
                    {
                        if (m_ctrls[side_child].GetLeft() < m_ctrls[idx_child].GetLeft())
                        {
                            a_left_siblings.emplace_back(&m_ctrls[side_child]);
                        }
                        else
                        {
                            a_right_siblings.emplace_back(&m_ctrls[side_child]);
                        }
                    }
                    else
                        break;
                }

                if (a_left_siblings.size() || a_right_siblings.size())
                {
                    auto sizer = g_NodeCreator.CreateNode(gen_wxBoxSizer, dlg_sizer.get());
                    if (a_left_siblings.size())
                        AddSiblings(sizer.get(), a_left_siblings, &m_ctrls[idx_child]);
                    Adopt(sizer, child);
                    if (a_right_siblings.size())
                        AddSiblings(sizer.get(), a_right_siblings, &m_ctrls[idx_child]);
                    dlg_sizer->Adopt(sizer);
                }
                else
                {
                    Adopt(dlg_sizer, child);
                }

                continue;
            }

            auto sizer = g_NodeCreator.CreateNode(gen_VerticalBoxSizer, dlg_sizer.get());
            dlg_sizer->Adopt(sizer);
            sizer->Adopt(child.GetNodePtr());
            if (idx_child == 0)
                continue;

            while (idx_child < m_ctrls.size() && !is_same_top(&m_ctrls[idx_child - 1], &m_ctrls[idx_child]))
            {
                if (m_ctrls[idx_child].isAdded())
                    break;  // means there was a static box to the right

                // Note that we add the child we are comparing to first.
                sizer->Adopt(m_ctrls[idx_child].GetNodePtr());
                if (idx_child + 2 < m_ctrls.size())
                {
                    // If the next two sizers have the same top, then they need to be placed in a horizontal sizer.
                    if (m_ctrls[idx_child + 1].du_top() == m_ctrls[idx_child + 2].du_top())
                        break;
                }
                ++idx_child;
            }
        }
    }

    dlg_sizer->FixDuplicateNodeNames();
}

void resForm::AddSiblings(Node* parent_sizer, std::vector<resCtrl*>& actrls, resCtrl* pSibling)
{
    if (actrls.size() == 1)
    {
        if (pSibling && is_same_top(actrls[0], pSibling))
        {
            // If both siblings have the same top position, then just add this sibling directly to the parent sizer
            parent_sizer->Adopt(actrls[0]->GetNodePtr());
            actrls[0]->setAdded();
            return;
        }
        else
        {
            // There's only one item which is positioned below the top of the sibling. We create a vertical box sizer and add
            // a spacer before the control to provide approximately the same amount of vertical space above the control.

            auto vert_sizer = g_NodeCreator.CreateNode(gen_VerticalBoxSizer, parent_sizer);
            parent_sizer->Adopt(vert_sizer);
            auto spacer = g_NodeCreator.CreateNode(gen_spacer, vert_sizer.get());
            spacer->prop_set_value(prop_height, actrls[0]->du_top() - pSibling->du_top());
            vert_sizer->Adopt(spacer);
            vert_sizer->Adopt(actrls[0]->GetNodePtr());
            actrls[0]->setAdded();
        }
    }
    else
    {
        auto vert_sizer = g_NodeCreator.CreateNode(gen_VerticalBoxSizer, parent_sizer);
        parent_sizer->Adopt(vert_sizer);

        for (size_t idx_child = 0; idx_child < actrls.size(); ++idx_child)
        {
            auto& child = *actrls[idx_child];

            // Check for a possible row
            if ((idx_child + 1 < actrls.size()) && is_same_top(&child, actrls[idx_child + 1]))
            {
                // If there is more than one child with the same top position, then create a horizontal box sizer
                // and add all children with the same top position.
                auto horz_sizer = g_NodeCreator.CreateNode(gen_wxBoxSizer, vert_sizer.get());
                vert_sizer->Adopt(horz_sizer);
                horz_sizer->prop_set_value(prop_orientation, "wxHORIZONTAL");

                while (idx_child < actrls.size() && is_same_top(&child, actrls[idx_child]))
                {
                    if (actrls[idx_child]->isAdded())
                        break;  // means there was a static box to the right

                    if (actrls[idx_child]->GetNode()->isGen(gen_wxStaticBoxSizer))
                    {
                        // Group boxes can have controls to the left and right that are lower than the top of the box. That
                        // means that they will have been sorted after the group box, but must be added before it.

                        AddStaticBoxChildren(*actrls[idx_child], idx_child);
                    }

                    // Note that we add the child we are comparing to first.
                    horz_sizer->Adopt(actrls[idx_child]->GetNodePtr());
                    actrls[idx_child]->setAdded();
                    ++idx_child;
                }
                if (idx_child < actrls.size() && actrls[idx_child]->isAdded())
                    continue;

                // In order to properly step through the loop and add the last control
                --idx_child;
            }
            else
            {
                if (child.GetNode()->isGen(gen_wxStaticBoxSizer))
                {
                    AddStaticBoxChildren(child, idx_child);

                    // There may be a control to the left or right of the group box but not at the same top position.

                    std::vector<resCtrl*> a_left_siblings;
                    std::vector<resCtrl*> a_right_siblings;

                    // REVIEW: [KeyWorks - 11-07-2021] This will only work properly if the bottom of the group box isn't
                    // lower then it's siblings bottom -- otherwise, the controls might not be included in the array. The
                    // only way to fix this would be to locate this group box node in m_ctrls and add the children using
                    // m_ctrls.

                    for (size_t side_child = idx_child + 1; side_child < actrls.size(); side_child++)
                    {
                        if (actrls[side_child]->isAdded())
                            continue;

                        if (is_within_vertical(actrls[side_child], actrls[idx_child]))
                        {
                            if (actrls[side_child]->GetLeft() < actrls[idx_child]->GetLeft())
                            {
                                a_left_siblings.emplace_back(actrls[side_child]);
                            }
                            else
                            {
                                a_right_siblings.emplace_back(actrls[side_child]);
                            }
                        }
                        else
                            break;
                    }

                    if (a_left_siblings.size() || a_right_siblings.size())
                    {
                        auto horz_sizer = g_NodeCreator.CreateNode(gen_wxBoxSizer, vert_sizer.get());
                        if (a_left_siblings.size())
                            AddSiblings(horz_sizer.get(), a_left_siblings, actrls[idx_child]);
                        Adopt(horz_sizer, child);
                        child.setAdded();
                        if (a_right_siblings.size())
                            AddSiblings(horz_sizer.get(), a_right_siblings, actrls[idx_child]);
                        vert_sizer->Adopt(horz_sizer);
                    }
                    else
                    {
                        vert_sizer->Adopt(child.GetNodePtr());
                        child.setAdded();
                    }

                    continue;
                }

                // Not a group box, so just add the control normally
                vert_sizer->Adopt(child.GetNodePtr());
                child.setAdded();
            }
        }
    }
}

void resForm::AddStaticBoxChildren(const resCtrl& box, size_t idx_group_box)
{
    if (box.du_width() > du_width() - 30)
    {
        box.GetNode()->prop_set_value(prop_flags, "wxEXPAND");
    }

    std::vector<resCtrl*> group_ctrls;
    CollectGroupControls(group_ctrls, idx_group_box);

    const auto& static_box = m_ctrls[idx_group_box];
    for (size_t idx_child = 0; idx_child < group_ctrls.size(); ++idx_child)
    {
        auto result = GroupGridSizerNeeded(group_ctrls, idx_child);
        if (result < 0)
        {
            // No alignment with the next control, so just add it normally
            auto& child = reinterpret_cast<resCtrl&>(*group_ctrls[idx_child]);
            Adopt(static_box.GetNodePtr(), child);

            // REVIEW: [KeyWorks - 06-16-2021] Does this actually happen in a group box?
            int dlg_margin = (box.du_width() / 2) - child.du_width();
            if (child.du_left() + du_width() < (box.du_width() - dlg_margin))
                child.prop_set_value(prop_alignment, "wxALIGN_CENTER_HORIZONTAL");
            continue;
        }
        else if (result == 0)
        {
            // Single row with all control tops the same, so use a horizontal box sizer
            auto sizer = g_NodeCreator.CreateNode(gen_wxBoxSizer, box.GetNode());
            sizer->prop_set_value(prop_orientation, "wxHORIZONTAL");
            static_box.GetNode()->Adopt(sizer);

            auto& child = reinterpret_cast<resCtrl&>(*group_ctrls[idx_child]);

            while (idx_child < group_ctrls.size() && group_ctrls[idx_child]->du_top() == child.du_top())
            {
                // Note that we add the child we are comparing to first.
                Adopt(sizer, *group_ctrls[idx_child]);
                ++idx_child;
            }
            // In order to properly step through the loop
            --idx_child;
        }
        else
        {
            // Multiple rows and columns, so use a flex grid sizer. There will be cases where a regular grid sizer would
            // work, but it would add a lot of complexity to figure that out, and visually it would look the same.

            auto total_columns = result;  // This is just for readability
            auto grid_sizer = g_NodeCreator.CreateNode(gen_wxFlexGridSizer, box.GetNode());
            grid_sizer->prop_set_value(prop_cols, ttlib::itoa(total_columns));
            static_box.GetNode()->Adopt(grid_sizer);

            // TODO: [KeyWorks - 11-08-2021] The following code will handle cases where there are missing right columns in a
            // row, but it doesn't handle gaps within a row.

            int cur_column = 1;
            for (; idx_child < group_ctrls.size();)
            {
                // Always add the first control in column 0
                Adopt(grid_sizer, *group_ctrls[idx_child]);

                if (group_ctrls[idx_child]->isGen(gen_wxStaticBoxSizer))
                {
                    size_t idx_child_group_box = idx_group_box + 1;
                    for (; idx_child_group_box < m_ctrls.size(); ++idx_child_group_box)
                    {
                        if (m_ctrls[idx_child_group_box].GetNode() == group_ctrls[idx_child]->GetNode())
                            break;
                    }
                    if (idx_child_group_box < m_ctrls.size())
                    {
                        AddStaticBoxChildren(*group_ctrls[idx_child], idx_child_group_box);
                    }
                }

                // Now add the other columns

                auto idx_column = idx_child + 1;
                for (; idx_column < group_ctrls.size(); ++idx_column)
                {
                    if (is_same_top(group_ctrls[idx_child], group_ctrls[idx_column], true))
                    {
                        Adopt(grid_sizer, *group_ctrls[idx_column]);
                        ++cur_column;

                        if (group_ctrls[idx_column]->isGen(gen_wxStaticBoxSizer))
                        {
                            size_t idx_child_group_box = idx_group_box + 1;
                            for (; idx_child_group_box < m_ctrls.size(); ++idx_child_group_box)
                            {
                                if (m_ctrls[idx_child_group_box].GetNode() == group_ctrls[idx_column]->GetNode())
                                    break;
                            }
                            if (idx_child_group_box < m_ctrls.size())
                            {
                                AddStaticBoxChildren(*group_ctrls[idx_column], idx_child_group_box);
                            }
                        }
                    }
                    else
                    {
                        // All columns for this row have been added
                        break;
                    }
                }
                idx_child = idx_column;

                if (idx_child < group_ctrls.size())
                {
                    // Deal with case where a row doesn't have an entry for every column -- we simply add a spacer to fill
                    // out the total number of columns.
                    while (cur_column < total_columns)
                    {
                        auto spacer = g_NodeCreator.CreateNode(gen_spacer, grid_sizer.get());
                        grid_sizer->Adopt(spacer);
                        ++cur_column;
                    }
                }

                cur_column = 1;
            }
            return;
        }
    }

    // TODO: [KeyWorks - 05-31-2021] Depending on the number and position of the children, we may need to change the
    // orientation as well as spanning more than one column or row.
}

int resForm::GridSizerNeeded(size_t idx_start, size_t idx_end, const resCtrl* /* p_static_box */)
{
    ASSERT(idx_end < m_ctrls.size());

    if (idx_start + 1 > idx_end || m_ctrls[idx_start + 1].du_top() != m_ctrls[idx_start].du_top())
        return -1;

    size_t row_children = 2;
    while (idx_start + row_children < idx_end && m_ctrls[idx_start + row_children].du_top() != m_ctrls[idx_start].du_top())
        ++row_children;

    size_t idx_next_row = idx_start + row_children;
    if (idx_next_row >= idx_end)
        return 0;  // only one aligned row, so a box sizer is needed

    size_t max_columns = row_children;

    while (idx_next_row < idx_end && m_ctrls[idx_next_row + 1].du_top() != m_ctrls[idx_next_row].du_top())
    {
        row_children = 2;
        while (idx_next_row + row_children < idx_end &&
               m_ctrls[idx_next_row + row_children].du_top() != m_ctrls[idx_next_row].du_top())
            ++row_children;
        if (row_children > max_columns)
            max_columns = row_children;

        idx_next_row = idx_next_row + row_children;
        if (idx_next_row >= idx_end)
            break;
    }

    return static_cast<int>(max_columns);
}

int resForm::GroupGridSizerNeeded(std::vector<resCtrl*>& group_ctrls, size_t idx_start) const
{
    if (idx_start + 1 >= group_ctrls.size() || !is_same_top(group_ctrls[idx_start], group_ctrls[idx_start + 1]))
        return -1;

    size_t row_children = 2;
    while (idx_start + row_children < group_ctrls.size() &&
           is_same_top(group_ctrls[idx_start], group_ctrls[idx_start + row_children], true))
        ++row_children;

    size_t idx_next_row = idx_start + row_children;
    if (idx_next_row + 1 >= group_ctrls.size() ||
        is_same_top(group_ctrls[idx_start], group_ctrls[idx_start + idx_next_row + 1], true))
    {
        return 0;  // only one aligned row, so a box sizer is needed
    }

    size_t max_columns = row_children;

    while (idx_next_row + 1 < group_ctrls.size())
    {
        if (is_same_top(group_ctrls[idx_next_row], group_ctrls[idx_next_row + 1]))
        {
            row_children = 2;
            while (idx_next_row + row_children < group_ctrls.size() &&
                   is_same_top(group_ctrls[idx_next_row], group_ctrls[idx_next_row + row_children], true))
                ++row_children;
            if (row_children > max_columns)
                max_columns = row_children;
        }
        idx_next_row = idx_next_row + row_children;
    }

    return static_cast<int>(max_columns);
}

void resForm::CollectGroupControls(std::vector<resCtrl*>& group_ctrls, size_t idx_parent)
{
    auto& rc_parent = m_ctrls[idx_parent].GetDialogRect();

    for (size_t idx = idx_parent + 1; idx < m_ctrls.size(); ++idx)
    {
#if defined(_DEBUG)
        auto child = m_ctrls[idx];
        auto& child_rc = child.GetDialogRect();
#else
        auto& child_rc = m_ctrls[idx].GetDialogRect();
#endif  // _DEBUG
        if (rc_parent.Contains(m_ctrls[idx].GetDialogRect()))
        {
            group_ctrls.emplace_back(&m_ctrls[idx]);

            // If it's a group box, then we need to skip over it's children so that they are only added to the inner group
            if (m_ctrls[idx].isGen(gen_wxStaticBoxSizer))
            {
                auto& rc_sub_parent = m_ctrls[idx].GetDialogRect();
                for (++idx; idx < m_ctrls.size(); ++idx)
                {
                    if (!rc_sub_parent.Contains(m_ctrls[idx].GetDialogRect()))
                    {
                        break;
                    }
                }
                // Backup so that the outer loop will continue correctly
                --idx;
            }
            continue;
        }
        else
        {
            // It's possible the control is to the left or right of the group box in which case we keep looking. However, if
            // it's below it, then we're done.
            if (child_rc.GetTop() >= (rc_parent.GetTop() + rc_parent.GetHeight()))
                return;
        }
    }
}

void resForm::Adopt(const NodeSharedPtr& node, resCtrl& child)
{
    ASSERT_MSG(!child.isAdded(), "Logic problem, child has already been added.");

    node->Adopt(child.GetNodePtr());
    child.setAdded();
}

// This function tries to determine if standard dialog buttons are being used, in which case we can switch them to
// wxStdDialogButtonSizer. Unfortunately, we have to rely on English labels to determine the button type -- we can't assume a
// standard id like IDOK will also have a standard label.

static std::set<std::string> s_btn_names = {

    "OK", "Yes", "Save", "No", "Cancel", "Close"

};

bool resForm::ProcessStdButton(Node* parent_sizer, size_t idx_child)
{
    for (size_t idx = idx_child; idx < m_ctrls.size(); ++idx)
    {
        if (!m_ctrls[idx].isGen(gen_wxButton))
            return false;

        if (auto result = s_btn_names.find(m_ctrls[idx].GetNode()->prop_as_string(prop_label)); result == s_btn_names.end())
        {
            return false;
        }
    }

    // If we made it here, then all we have left are buttons, and they all have standard labels

    auto sizer = g_NodeCreator.CreateNode(gen_wxStdDialogButtonSizer, parent_sizer);
    // Clear the default properties
    sizer->prop_set_value(prop_default_button, "");
    sizer->prop_set_value(prop_OK, false);
    sizer->prop_set_value(prop_Cancel, false);

    // Set our own default property
    sizer->prop_set_value(prop_flags, "wxEXPAND");

    for (size_t idx = idx_child; idx < m_ctrls.size(); ++idx)
    {
        auto btn = m_ctrls[idx].GetNode();
        if (btn->prop_as_bool(prop_default))
            sizer->prop_set_value(prop_default_button, btn->prop_as_string(prop_label));
        auto result = rmap_PropNames.find(btn->prop_as_string(prop_label));
        if (result != rmap_PropNames.end())
        {
            sizer->prop_set_value(result->second, true);
        }
        m_ctrls[idx].setAdded();
    }

    parent_sizer->Adopt(sizer);
    return true;
}
