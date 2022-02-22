/////////////////////////////////////////////////////////////////////////////
// Purpose:   Enumerations for generators
// Author:    Ralph Walden
// Copyright: Copyright (c) 2021 KeyWorks Software (Ralph Walden)
// License:   Apache License -- see ../LICENSE
/////////////////////////////////////////////////////////////////////////////

// These maps can be used to convert the enumeration value into a string for writing out to a project file. When wxUiEditor
// is first initialized, the regular maps will be read and used to initialize the rmaps.

#include "gen_enums.h"

using namespace GenEnum;

std::map<PropType, const char*> GenEnum::map_PropTypes = {

    // These types need to be listed in xml/gen.dtd

    { type_animation, "animation" },
    { type_bitlist, "bitlist" },
    { type_bitmap, "bitmap" },
    { type_bool, "bool" },
    { type_code_edit, "code_edit" },
    { type_editoption, "editoption" },
    { type_file, "file" },
    { type_float, "float" },
    { type_html_edit, "html_edit" },
    { type_id, "id" },
    { type_image, "image" },
    { type_int, "int" },
    { type_option, "option" },
    { type_path, "path" },
    { type_string, "string" },
    { type_string_code_single, "string_code_single" },
    { type_string_edit, "string_edit" },
    { type_string_edit_escapes, "string_edit_escapes" },
    { type_string_edit_single, "string_edit_single" },
    { type_string_escapes, "string_escapes" },
    { type_stringlist, "stringlist" },
    { type_uint, "uint" },
    { type_uintpairlist, "uintpairlist" },
    { type_wxColour, "wxColour" },
    { type_wxFont, "wxFont" },
    { type_wxPoint, "wxPoint" },
    { type_wxSize, "wxSize" },

};

std::map<GenEnum::PropName, const char*> GenEnum::map_PropNames = {

    { prop_Apply, "Apply" },
    { prop_BottomDockable, "BottomDockable" },
    { prop_Cancel, "Cancel" },
    { prop_Close, "Close" },
    { prop_ContextHelp, "ContextHelp" },
    { prop_Help, "Help" },
    { prop_LeftDockable, "LeftDockable" },
    { prop_No, "No" },
    { prop_OK, "OK" },
    { prop_RightDockable, "RightDockable" },
    { prop_Save, "Save" },
    { prop_TopDockable, "TopDockable" },
    { prop_Yes, "Yes" },
    { prop_add_default_border, "add_default_border" },
    { prop_additional_carets_blink, "additional_carets_blink" },
    { prop_additional_carets_visible, "additional_carets_visible" },
    { prop_align, "align" },
    { prop_html_content, "html_content" },
    { prop_html_file, "html_file" },
    { prop_html_url, "html_url" },
    { prop_alignment, "alignment" },
    { prop_allow_mouse_rectangle, "allow_mouse_rectangle" },
    { prop_animation, "animation" },
    { prop_art_directory, "art_directory" },
    { prop_art_provider, "art_provider" },
    { prop_aui_layer, "aui_layer" },
    { prop_aui_name, "aui_name" },
    { prop_aui_position, "aui_position" },
    { prop_aui_row, "aui_row" },
    { prop_auth_needed, "auth_needed" },
    { prop_auto_complete, "auto_complete" },
    { prop_automatic_folding, "automatic_folding" },
    { prop_autosize_cols, "autosize_cols" },
    { prop_autosize_rows, "autosize_rows" },
    { prop_background_colour, "background_colour" },
    { prop_backspace_unindents, "backspace_unindents" },
    { prop_base_directory, "base_directory" },
    { prop_base_file, "base_file" },
    { prop_base_hdr_includes, "base_hdr_includes" },
    { prop_base_src_includes, "base_src_includes" },
    { prop_best_size, "best_size" },
    { prop_bitmap, "bitmap" },
    { prop_bitmapsize, "bitmapsize" },
    { prop_bmp_background_colour, "bmp_background_colour" },
    { prop_bmp_min_width, "bmp_min_width" },
    { prop_bmp_placement, "bmp_placement" },
    { prop_border, "border" },
    { prop_border_size, "border_size" },
    { prop_borders, "borders" },
    { prop_cancel_button, "cancel_button" },
    { prop_caption, "caption" },
    { prop_caption_visible, "caption_visible" },
    { prop_cell_bg, "cell_bg" },
    { prop_cell_fit, "cell_fit" },
    { prop_cell_font, "cell_font" },
    { prop_cell_horiz_alignment, "cell_horiz_alignment" },
    { prop_cell_text, "cell_text" },
    { prop_cell_vert_alignment, "cell_vert_alignment" },
    { prop_center, "center" },
    { prop_center_pane, "center_pane" },
    { prop_checkbox_var_name, "checkbox_var_name" },
    { prop_checked, "checked" },
    { prop_class_access, "class_access" },
    { prop_class_decoration, "class_decoration" },
    { prop_class_name, "class_name" },
    { prop_close_button, "close_button" },
    { prop_cmake_file, "cmake_file" },
    { prop_cmake_varname, "cmake_varname" },
    { prop_col_label_horiz_alignment, "col_label_horiz_alignment" },
    { prop_col_label_size, "col_label_size" },
    { prop_col_label_values, "col_label_values" },
    { prop_col_label_vert_alignment, "col_label_vert_alignment" },
    { prop_collapsed, "collapsed" },
    { prop_colour, "colour" },
    { prop_cols, "cols" },
    { prop_colspan, "colspan" },
    { prop_column, "column" },
    { prop_column_labels, "column_labels" },
    { prop_column_sizes, "column_sizes" },
    { prop_compiler_standard, "compiler_standard" },
    { prop_contents, "contents" },
    { prop_context_help, "context_help" },
    { prop_context_menu, "context_menu" },
    { prop_current, "current" },
    { prop_custom_colour, "custom_colour" },
    { prop_custom_margin, "custom_margin" },
    { prop_custom_mask_folders, "custom_mask_folders" },
    { prop_custom_mouse_sensitive, "custom_mouse_sensitive" },
    { prop_custom_type, "custom_type" },
    { prop_custom_width, "custom_width" },
    { prop_default, "default" },
    { prop_default_button, "default_button" },
    { prop_default_col_size, "default_col_size" },
    { prop_default_pane, "default_pane" },
    { prop_default_row_size, "default_row_size" },
    { prop_defaultfilter, "defaultfilter" },
    { prop_defaultfolder, "defaultfolder" },
    { prop_derived_class, "derived_class" },
    { prop_derived_class_name, "derived_class_name" },
    { prop_derived_directory, "derived_directory" },
    { prop_derived_file, "derived_file" },
    { prop_derived_header, "derived_header" },
    { prop_digits, "digits" },
    { prop_direction, "direction" },
    { prop_disabled, "disabled" },
    { prop_disabled_bmp, "disabled_bmp" },
    { prop_display_images, "display_images" },
    { prop_dock, "dock" },
    { prop_dock_fixed, "dock_fixed" },
    { prop_docking, "docking" },
    { prop_drag_col_move, "drag_col_move" },
    { prop_drag_col_size, "drag_col_size" },
    { prop_drag_grid_size, "drag_grid_size" },
    { prop_drag_row_size, "drag_row_size" },
    { prop_duration, "duration" },
    { prop_editing, "editing" },
    { prop_ellipsize, "ellipsize" },
    { prop_empty_cell_size, "empty_cell_size" },
    { prop_enable_user_code, "enable_user_code" },
    { prop_end_colour, "end_colour" },
    { prop_eol_mode, "eol_mode" },
    { prop_extra_style, "extra_style" },
    { prop_fields, "fields" },
    { prop_filter, "filter" },
    { prop_filter_index, "filter_index" },
    { prop_flag, "flag" },
    { prop_flags, "flags" },
    { prop_flexible_direction, "flexible_direction" },
    { prop_floatable, "floatable" },
    { prop_focus, "focus" },
    { prop_focus_bmp, "focus_bmp" },
    { prop_fold_flags, "fold_flags" },
    { prop_fold_margin, "fold_margin" },
    { prop_fold_marker_colour, "fold_marker_colour" },
    { prop_fold_marker_style, "fold_marker_style" },
    { prop_fold_width, "fold_width" },
    { prop_font, "font" },
    { prop_foreground_colour, "foreground_colour" },
    { prop_generate_cmake, "generate_cmake" },
    { prop_generate_ids, "generate_ids" },
    { prop_get_function, "get_function" },
    { prop_grid_line_color, "grid_line_color" },
    { prop_grid_lines, "grid_lines" },
    { prop_gripper, "gripper" },
    { prop_growablecols, "growablecols" },
    { prop_growablerows, "growablerows" },
    { prop_handler_name, "handler_name" },
    { prop_header, "header" },
    { prop_header_ext, "header_ext" },
    { prop_height, "height" },
    { prop_help, "help" },
    { prop_help_provider, "help_provider" },
    { prop_hexadecimal, "hexadecimal" },
    { prop_hgap, "hgap" },
    { prop_hidden, "hidden" },
    { prop_hide_effect, "hide_effect" },
    { prop_hint, "hint" },
    { prop_hover_color, "hover_color" },
    { prop_icon, "icon" },
    { prop_id, "id" },
    { prop_image_size, "image_size" },
    { prop_inactive_bitmap, "inactive_bitmap" },
    { prop_inc, "inc" },
    { prop_include_advanced, "include_advanced" },
    { prop_indentation_guides, "indentation_guides" },
    { prop_initial, "initial" },
    { prop_initial_filename, "initial_filename" },
    { prop_initial_folder, "initial_folder" },
    { prop_initial_font, "initial_font" },
    { prop_initial_path, "initial_path" },
    { prop_initial_state, "initial_state" },
    { prop_inserted_hdr_code, "inserted_hdr_code" },
    { prop_internationalize, "internationalize" },
    { prop_kind, "kind" },
    { prop_label, "label" },
    { prop_label_bg, "label_bg" },
    { prop_label_font, "label_font" },
    { prop_label_text, "label_text" },
    { prop_line_digits, "line_digits" },
    { prop_line_margin, "line_margin" },
    { prop_line_numbers, "line_numbers" },  // previously used in wxStyledTextCtrl, but now uses margins
    { prop_line_size, "line_size" },
    { prop_local_pch_file, "local_pch_file" },
    { prop_main_label, "main_label" },
    { prop_majorDimension, "majorDimension" },
    { prop_margin_height, "margin_height" },
    { prop_margin_width, "margin_width" },
    { prop_margins, "margins" },
    { prop_markup, "markup" },
    { prop_max, "max" },
    { prop_maxValue, "maxValue" },
    { prop_max_point_size, "max_point_size" },
    { prop_max_rows, "max_rows" },
    { prop_max_size, "max_size" },
    { prop_maximize_button, "maximize_button" },
    { prop_maximum_size, "maximum_size" },
    { prop_maxlength, "maxlength" },
    { prop_message, "message" },
    { prop_min, "min" },
    { prop_minValue, "minValue" },
    { prop_min_pane_size, "min_pane_size" },
    { prop_min_point_size, "min_point_size" },
    { prop_min_rows, "min_rows" },
    { prop_min_size, "min_size" },
    { prop_minimize_button, "minimize_button" },
    { prop_minimum_size, "minimum_size" },
    { prop_mockup_size, "mockup_size" },
    { prop_mode, "mode" },
    { prop_model_column, "model_column" },
    { prop_moveable, "moveable" },
    { prop_multiple_selection_typing, "multiple_selection_typing" },
    { prop_multiple_selections, "multiple_selections" },
    { prop_name_space, "name_space" },
    { prop_namespace, "namespace" },
    { prop_native_col_header, "native_col_header" },
    { prop_native_col_labels, "native_col_labels" },
    { prop_non_flexible_grow_mode, "non_flexible_grow_mode" },
    { prop_normal_color, "normal_color" },
    { prop_note, "note" },
    { prop_orientation, "orientation" },
    { prop_packing, "packing" },
    { prop_page_size, "page_size" },
    { prop_pagesize, "pagesize" },
    { prop_pane_border, "pane_border" },
    { prop_pane_position, "pane_position" },
    { prop_pane_size, "pane_size" },
    { prop_parameters, "parameters" },
    { prop_paste_multiple, "paste_multiple" },
    { prop_persist, "persist" },
    { prop_persist_name, "persist_name" },
    { prop_pin_button, "pin_button" },
    { prop_play, "play" },
    { prop_pos, "pos" },
    { prop_position, "position" },
    { prop_pressed, "pressed" },
    { prop_pressed_bmp, "pressed_bmp" },
    { prop_private_members, "private_members" },
    { prop_proportion, "proportion" },
    { prop_radiobtn_var_name, "radiobtn_var_name" },
    { prop_range, "range" },
    { prop_read_only, "read_only" },
    { prop_resize, "resize" },
    { prop_row, "row" },
    { prop_row_label_horiz_alignment, "row_label_horiz_alignment" },
    { prop_row_label_size, "row_label_size" },
    { prop_row_label_values, "row_label_values" },
    { prop_row_label_vert_alignment, "row_label_vert_alignment" },
    { prop_row_sizes, "row_sizes" },
    { prop_rows, "rows" },
    { prop_rowspan, "rowspan" },
    { prop_sashgravity, "sashgravity" },
    { prop_sashpos, "sashpos" },
    { prop_sashsize, "sashsize" },
    { prop_scale_mode, "scale_mode" },
    { prop_scroll_rate_x, "scroll_rate_x" },
    { prop_scroll_rate_y, "scroll_rate_y" },
    { prop_search_button, "search_button" },
    { prop_select, "select" },
    { prop_selection, "selection" },
    { prop_selection_int, "selection_int" },
    { prop_selection_mode, "selection_mode" },
    { prop_selection_string, "selection_string" },
    { prop_separation, "separation" },
    { prop_separator_margin, "separator_margin" },
    { prop_separator_width, "separator_width" },
    { prop_set_function, "set_function" },
    { prop_settings_code, "settings_code" },
    { prop_shortcut, "shortcut" },
    { prop_show, "show" },
    { prop_show_effect, "show_effect" },
    { prop_show_hidden, "show_hidden" },
    { prop_size, "size" },
    { prop_smart_size, "smart_size" },
    { prop_source_ext, "source_ext" },
    { prop_splitmode, "splitmode" },
    { prop_src_preamble, "src_preamble" },
    { prop_start_colour, "start_colour" },
    { prop_static_line, "static_line" },
    { prop_statusbar, "statusbar" },
    { prop_stc_indentation_size, "indentation_size" },
    { prop_stc_left_margin_width, "left_margin_width" },
    { prop_stc_lexer, "lexer" },
    { prop_stc_right_margin_width, "right_margin_width" },
    { prop_stc_select_wrapped_line, "select_wrapped_line" },
    { prop_stc_wrap_indent_mode, "wrap_indent_mode" },
    { prop_stc_wrap_mode, "wrap_mode" },
    { prop_stc_wrap_start_indent, "wrap_start_indent" },
    { prop_stc_wrap_visual_flag, "wrap_visual_flag" },
    { prop_stc_wrap_visual_location, "wrap_visual_location" },
    { prop_style, "style" },
    { prop_symbol_margin, "symbol_margin" },
    { prop_symbol_mouse_sensitive, "symbol_mouse_sensitive" },
    { prop_sync_hover_colour, "sync_hover_colour" },
    { prop_tab_behaviour, "tab_behaviour" },
    { prop_tab_height, "tab_height" },
    { prop_tab_indents, "tab_indents" },
    { prop_tab_position, "tab_position" },
    { prop_tab_width, "tab_width" },
    { prop_text, "text" },
    { prop_theme, "theme" },
    { prop_thumb_length, "thumb_length" },
    { prop_thumbsize, "thumbsize" },
    { prop_tick_frequency, "tick_frequency" },
    { prop_title, "title" },
    { prop_toolbar_pane, "toolbar_pane" },
    { prop_tooltip, "tooltip" },
    { prop_type, "type" },
    { prop_unchecked_bitmap, "unchecked_bitmap" },
    { prop_underlined, "underlined" },
    { prop_url, "url" },
    { prop_use_derived_class, "use_derived_class" },
    { prop_use_tabs, "use_tabs" },
    { prop_user_cpp_code, "user_cpp_code" },
    { prop_validator_data_type, "validator_data_type" },
    { prop_validator_style, "validator_style" },
    { prop_validator_type, "validator_type" },
    { prop_validator_variable, "validator_variable" },
    { prop_value, "value" },
    { prop_var_comment, "var_comment" },
    { prop_var_name, "var_name" },
    { prop_variant, "variant" },
    { prop_vgap, "vgap" },
    { prop_view_eol, "view_eol" },
    { prop_view_tab_strikeout, "view_tab_strikeout" },
    { prop_view_whitespace, "view_whitespace" },
    { prop_visited_color, "visited_color" },
    { prop_width, "width" },
    { prop_wildcard, "wildcard" },
    { prop_window_extra_style, "window_extra_style" },
    { prop_window_name, "window_name" },
    { prop_window_style, "window_style" },
    { prop_wrap, "wrap" },
    { prop_wrap_flags, "wrap_flags" },
    { prop_wxWidgets_version, "wxWidgets_version" },

};
std::map<std::string_view, GenEnum::PropName, std::less<>> GenEnum::rmap_PropNames;

std::map<GenType, const char*> GenEnum::map_GenTypes = {

    { type_aui_tool, "aui_tool" },
    { type_aui_toolbar, "aui_toolbar" },
    { type_auinotebook, "auinotebook" },
    { type_bookpage, "bookpage" },
    { type_choicebook, "choicebook" },
    { type_container, "container" },
    { type_ctx_menu, "ctx_menu" },
    { type_dataviewcolumn, "dataviewcolumn" },
    { type_dataviewctrl, "dataviewctrl" },
    { type_dataviewlistcolumn, "dataviewlistcolumn" },
    { type_dataviewlistctrl, "dataviewlistctrl" },
    { type_dataviewtreectrl, "dataviewtreectrl" },
    { type_embed_image, "embed_image" },
    { type_form, "form" },
    { type_frame_form, "frame_form" },
    { type_gbsizer, "gbsizer" },
    { type_gbsizeritem, "gbsizeritem" },
    { type_images, "images" },
    { type_interface, "interface" },
    { type_listbook, "listbook" },
    { type_menu, "menu" },
    { type_menubar, "menubar" },
    { type_menubar_form, "menubar_form" },
    { type_menuitem, "menuitem" },
    { type_notebook, "notebook" },
    { type_oldbookpage, "oldbookpage" },
    { type_page, "page" },
    { type_popup_menu, "popup_menu" },
    { type_project, "project" },
    { type_propgrid, "propgrid" },
    { type_propgriditem, "propgriditem" },
    { type_propgridman, "propgridman" },
    { type_propgridpage, "propgridpage" },
    { type_ribbonbar, "ribbonbar" },
    { type_ribbonbar_form, "ribbonbar_form" },
    { type_ribbonbutton, "ribbonbutton" },
    { type_ribbonbuttonbar, "ribbonbuttonbar" },
    { type_ribbongallery, "ribbongallery" },
    { type_ribbongalleryitem, "ribbongalleryitem" },
    { type_ribbonpage, "ribbonpage" },
    { type_ribbonpanel, "ribbonpanel" },
    { type_ribbontool, "ribbontool" },
    { type_ribbontoolbar, "ribbontoolbar" },
    { type_simplebook, "simplebook" },
    { type_sizer, "sizer" },
    { type_sizeritem, "sizeritem" },
    { type_splitter, "splitter" },
    { type_splitteritem, "splitteritem" },
    { type_statusbar, "statusbar" },
    { type_submenu, "submenu" },
    { type_tool, "tool" },
    { type_toolbar, "toolbar" },
    { type_toolbar_form, "toolbar_form" },
    { type_treelistctrl, "treelistctrl" },
    { type_treelistctrlcolumn, "treelistctrlcolumn" },
    { type_widget, "widget" },
    { type_wizard, "wizard" },
    { type_wizardpagesimple, "wizardpagesimple" },

};

std::map<GenEnum::GenName, const char*> GenEnum::map_GenNames = {

    { gen_AUI, "AUI" },  // This is always the first one, set to a value of 0

    // The following are categories (type="interface")

    { gen_Bitmaps, "Bitmaps" },
    { gen_Boolean_Validator, "Boolean Validator" },
    { gen_CMake, "CMake" },
    { gen_Choice_Validator, "Choice Validator" },
    { gen_Code, "Code" },
    { gen_Code_Generation, "Code Generation" },
    { gen_Command_Bitmaps, "Command Bitmaps" },
    { gen_Integer_Validator, "Integer Validator" },
    { gen_List_Validator, "List Validator" },
    { gen_String_Validator, "String Validator" },
    { gen_Text_Validator, "Text Validator" },
    { gen_Window_Events, "Window Events" },
    { gen_flexgridsizerbase, "flexgridsizerbase" },
    { gen_sizer_child, "sizer_child" },
    { gen_sizeritem_settings, "sizeritem_settings" },
    { gen_wxTopLevelWindow, "wxTopLevelWindow" },
    { gen_wxWindow, "wxWindow" },

    // The following are the rergular generators

    { gen_BookPage, "BookPage" },
    { gen_Check3State, "Check3State" },
    { gen_CustomControl, "CustomControl" },
    { gen_Images, "Images" },
    { gen_MenuBar, "MenuBar" },
    { gen_PageCtrl, "PageCtrl" },
    { gen_PanelForm, "PanelForm" },
    { gen_PopupMenu, "PopupMenu" },
    { gen_Project, "Project" },
    { gen_RibbonBar, "RibbonBar" },
    { gen_StaticCheckboxBoxSizer, "StaticCheckboxBoxSizer" },
    { gen_StaticRadioBtnBoxSizer, "StaticRadioBtnBoxSizer" },
    { gen_TextSizer, "TextSizer" },
    { gen_ToolBar, "ToolBar" },
    { gen_TreeListCtrlColumn, "TreeListCtrlColumn" },
    { gen_UserCode, "UserCode" },
    { gen_VerticalBoxSizer, "VerticalBoxSizer" },
    { gen_auitool, "auitool" },
    { gen_dataViewColumn, "dataViewColumn" },
    { gen_dataViewListColumn, "dataViewListColumn" },
    { gen_embedded_image, "embedded_image" },
    { gen_gbsizeritem, "gbsizeritem" },
    { gen_oldbookpage, "oldbookpage" },
    { gen_propGridItem, "propGridItem" },
    { gen_propGridPage, "propGridPage" },
    { gen_ribbonButton, "ribbonButton" },
    { gen_ribbonGalleryItem, "ribbonGalleryItem" },
    { gen_ribbonSeparator, "ribbonSeparator" },
    { gen_ribbonTool, "ribbonTool" },
    { gen_separator, "separator" },
    { gen_sizer_dimension, "sizer_dimension" },
    { gen_sizeritem, "sizeritem" },
    { gen_spacer, "spacer" },
    { gen_splitteritem, "splitteritem" },
    { gen_submenu, "submenu" },
    { gen_tool, "tool" },
    { gen_toolSeparator, "toolSeparator" },
    { gen_wxActivityIndicator, "wxActivityIndicator" },
    { gen_wxAnimationCtrl, "wxAnimationCtrl" },
    { gen_wxAuiMDIChildFrame, "wxAuiMDIChildFrame" },
    { gen_wxAuiNotebook, "wxAuiNotebook" },
    { gen_wxAuiToolBar, "wxAuiToolBar" },
    { gen_wxBannerWindow, "wxBannerWindow" },
    { gen_wxBitmapComboBox, "wxBitmapComboBox" },
    { gen_wxBoxSizer, "wxBoxSizer" },
    { gen_wxButton, "wxButton" },
    { gen_wxCalendarCtrl, "wxCalendarCtrl" },
    { gen_wxCheckBox, "wxCheckBox" },
    { gen_wxCheckListBox, "wxCheckListBox" },
    { gen_wxChoice, "wxChoice" },
    { gen_wxChoicebook, "wxChoicebook" },
    { gen_wxCollapsiblePane, "wxCollapsiblePane" },
    { gen_wxColourPickerCtrl, "wxColourPickerCtrl" },
    { gen_wxComboBox, "wxComboBox" },
    { gen_wxCommandLinkButton, "wxCommandLinkButton" },
    { gen_wxContextMenuEvent, "wxContextMenuEvent" },
    { gen_wxDataViewCtrl, "wxDataViewCtrl" },
    { gen_wxDataViewListCtrl, "wxDataViewListCtrl" },
    { gen_wxDataViewTreeCtrl, "wxDataViewTreeCtrl" },
    { gen_wxDatePickerCtrl, "wxDatePickerCtrl" },
    { gen_wxDialog, "wxDialog" },
    { gen_wxDirPickerCtrl, "wxDirPickerCtrl" },
    { gen_wxEditableListBox, "wxEditableListBox" },
    { gen_wxFileCtrl, "wxFileCtrl" },
    { gen_wxFilePickerCtrl, "wxFilePickerCtrl" },
    { gen_wxFlexGridSizer, "wxFlexGridSizer" },
    { gen_wxFontPickerCtrl, "wxFontPickerCtrl" },
    { gen_wxFrame, "wxFrame" },
    { gen_wxGauge, "wxGauge" },
    { gen_wxGenericDirCtrl, "wxGenericDirCtrl" },
    { gen_wxGrid, "wxGrid" },
    { gen_wxGridBagSizer, "wxGridBagSizer" },
    { gen_wxGridSizer, "wxGridSizer" },
    { gen_wxHtmlWindow, "wxHtmlWindow" },
    { gen_wxHyperlinkCtrl, "wxHyperlinkCtrl" },
    { gen_wxInfoBar, "wxInfoBar" },
    { gen_wxListBox, "wxListBox" },
    { gen_wxListView, "wxListView" },
    { gen_wxListbook, "wxListbook" },
    { gen_wxMenu, "wxMenu" },
    { gen_wxMenuBar, "wxMenuBar" },
    { gen_wxMenuItem, "wxMenuItem" },
    { gen_wxNotebook, "wxNotebook" },
    { gen_wxPanel, "wxPanel" },
    { gen_wxPopupTransientWindow, "wxPopupTransientWindow" },
    { gen_wxPropertyGrid, "wxPropertyGrid" },
    { gen_wxPropertyGridManager, "wxPropertyGridManager" },
    { gen_wxRadioBox, "wxRadioBox" },
    { gen_wxRadioButton, "wxRadioButton" },
    { gen_wxRearrangeCtrl, "wxRearrangeCtrl" },
    { gen_wxRibbonBar, "wxRibbonBar" },
    { gen_wxRibbonButtonBar, "wxRibbonButtonBar" },
    { gen_wxRibbonGallery, "wxRibbonGallery" },
    { gen_wxRibbonPage, "wxRibbonPage" },
    { gen_wxRibbonPanel, "wxRibbonPanel" },
    { gen_wxRibbonToolBar, "wxRibbonToolBar" },
    { gen_wxRichTextCtrl, "wxRichTextCtrl" },
    { gen_wxScrollBar, "wxScrollBar" },
    { gen_wxScrolledCanvas, "wxScrolledCanvas" },
    { gen_wxScrolledWindow, "wxScrolledWindow" },
    { gen_wxSearchCtrl, "wxSearchCtrl" },
    { gen_wxSimpleHtmlListBox, "wxSimpleHtmlListBox" },
    { gen_wxSimplebook, "wxSimplebook" },
    { gen_wxSlider, "wxSlider" },
    { gen_wxSpinButton, "wxSpinButton" },
    { gen_wxSpinCtrl, "wxSpinCtrl" },
    { gen_wxSpinCtrlDouble, "wxSpinCtrlDouble" },
    { gen_wxSplitterWindow, "wxSplitterWindow" },
    { gen_wxStaticBitmap, "wxStaticBitmap" },
    { gen_wxStaticBoxSizer, "wxStaticBoxSizer" },
    { gen_wxStaticLine, "wxStaticLine" },
    { gen_wxStaticText, "wxStaticText" },
    { gen_wxStatusBar, "wxStatusBar" },
    { gen_wxStdDialogButtonSizer, "wxStdDialogButtonSizer" },
    { gen_wxStyledTextCtrl, "wxStyledTextCtrl" },
    { gen_wxTextCtrl, "wxTextCtrl" },
    { gen_wxTimePickerCtrl, "wxTimePickerCtrl" },
    { gen_wxToggleButton, "wxToggleButton" },
    { gen_wxToolBar, "wxToolBar" },
    { gen_wxToolbook, "wxToolbook" },
    { gen_wxTreeCtrl, "wxTreeCtrl" },
    { gen_wxTreeCtrlBase, "wxTreeCtrlBase" },
    { gen_wxTreeListCtrl, "wxTreeListCtrl" },
    { gen_wxTreebook, "wxTreebook" },
    { gen_wxWebView, "wxWebView" },
    { gen_wxWizard, "wxWizard" },
    { gen_wxWizardPageSimple, "wxWizardPageSimple" },
    { gen_wxWrapSizer, "wxWrapSizer" },

};
std::map<std::string_view, GenEnum::GenName, std::less<>> GenEnum::rmap_GenNames;
