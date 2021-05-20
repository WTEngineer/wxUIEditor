////////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor -- see https://github.com/KeyWorksRW/wxUiEditor/
//
// DO NOT EDIT THIS FILE! Your changes will be lost if it is re-generated!
////////////////////////////////////////////////////////////////////////////////

#include "pch.h"

#include "mainframe_base.h"

MainFrameBase::MainFrameBase(wxWindow* parent, wxWindowID id, const wxString& title,
        const wxPoint& pos, const wxSize& size, long style) :
    wxFrame(parent, id, title, pos, size, style)
{
    auto menubar = new wxMenuBar();

    auto menuDialogs = new wxMenu();

    auto menuItem = new wxMenuItem(menuDialogs, wxID_ANY, wxString::FromUTF8("DlgMulitTest..."),
    wxString::FromUTF8("Common controls"), wxITEM_NORMAL);
    menuDialogs->Append(menuItem);

    auto menuItem_2 = new wxMenuItem(menuDialogs, wxID_ANY, wxString::FromUTF8("Common Controls..."),
    wxString::FromUTF8("Common controls"), wxITEM_NORMAL);
    menuDialogs->Append(menuItem_2);

    auto menuItem1 = new wxMenuItem(menuDialogs, wxID_ANY, wxString::FromUTF8("Other Controls Dialog..."));
    menuDialogs->Append(menuItem1);

    auto menuItem2 = new wxMenuItem(menuDialogs, wxID_ANY, wxString::FromUTF8("Ribbon Dialog"));
    menuDialogs->Append(menuItem2);

    auto menuItem3 = new wxMenuItem(menuDialogs, wxID_ANY, wxString::FromUTF8("Wizard"));
    menuDialogs->Append(menuItem3);

    auto submenu = new wxMenu();

    auto menu_choicebook = new wxMenuItem(submenu, wxID_ANY, wxString::FromUTF8("Choicebook"));
    submenu->Append(menu_choicebook);

    auto menu_listbook = new wxMenuItem(submenu, wxID_ANY, wxString::FromUTF8("Listbook"));
    submenu->Append(menu_listbook);

    auto menu_notebook = new wxMenuItem(submenu, wxID_ANY, wxString::FromUTF8("Notebook"));
    submenu->Append(menu_notebook);

    auto menu_toolbook = new wxMenuItem(submenu, wxID_ANY, wxString::FromUTF8("Toolbook"));
    submenu->Append(menu_toolbook);

    auto menu_treebook = new wxMenuItem(submenu, wxID_ANY, wxString::FromUTF8("Treebook"));
    submenu->Append(menu_treebook);
    menuDialogs->AppendSubMenu(submenu, wxString::FromUTF8("Book Controls"));

    menuDialogs->AppendSeparator();

    auto menuItem4 = new wxMenuItem(menuDialogs, wxID_EXIT, wxString::FromUTF8("Exit"));
    menuDialogs->Append(menuItem4);
    menubar->Append(menuDialogs, wxString::FromUTF8("&Dialogs"));

    SetMenuBar(menubar);

    m_statusBar = CreateStatusBar();

    Centre(wxBOTH);

    // Event handlers
    Bind(wxEVT_MENU, &MainFrameBase::OnMultiTestDialog, this, menuItem->GetId());
    Bind(wxEVT_MENU, &MainFrameBase::OnCommonDialog, this, menuItem_2->GetId());
    Bind(wxEVT_MENU, &MainFrameBase::OnOtherCtrls, this, menuItem1->GetId());
    Bind(wxEVT_MENU, &MainFrameBase::OnRibbonDialog, this, menuItem2->GetId());
    Bind(wxEVT_MENU, &MainFrameBase::OnWizard, this, menuItem3->GetId());
    Bind(wxEVT_MENU, &MainFrameBase::OnChoicebook, this, menu_choicebook->GetId());
    Bind(wxEVT_MENU, &MainFrameBase::OnListbook, this, menu_listbook->GetId());
    Bind(wxEVT_MENU, &MainFrameBase::OnNotebook, this, menu_notebook->GetId());
    Bind(wxEVT_MENU, &MainFrameBase::OnToolbook, this, menu_toolbook->GetId());
    Bind(wxEVT_MENU, &MainFrameBase::OnTreebook, this, menu_treebook->GetId());
    Bind(wxEVT_MENU, &MainFrameBase::OnQuit, this, wxID_EXIT);
}
