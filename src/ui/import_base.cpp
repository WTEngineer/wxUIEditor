////////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor -- see https://github.com/KeyWorksRW/wxUiEditor/
//
// DO NOT EDIT THIS FILE! Your changes will be lost if it is re-generated!
////////////////////////////////////////////////////////////////////////////////

#include <wx/icon.h>

#include "import_base.h"

#include <wx/mstream.h>  // memory stream classes
#include <wx/zstream.h>  // zlib stream classes

#include <memory>  // for std::make_unique

// Convert compressed SVG string into a wxBitmapBundle
inline wxBitmapBundle wxueBundleSVG(const unsigned char* data,
    size_t size_data, size_t size_svg, wxSize def_size)
{
    auto str = std::make_unique<char[]>(size_svg);
    wxMemoryInputStream stream_in(data, size_data);
    wxZlibInputStream zlib_strm(stream_in);
    zlib_strm.Read(str.get(), size_svg);
    return wxBitmapBundle::FromSVG(str.get(), def_size);
};

bool ImportBase::Create(wxWindow* parent, wxWindowID id, const wxString& title,
        const wxPoint& pos, const wxSize& size, long style, const wxString &name)
{
    if (!wxDialog::Create(parent, id, title, pos, size, style, name))
        return false;

    SetIcon(wxueBundleSVG(wxue_img::import_svg, 418, 1013, wxSize(16, 16)).GetIconFor(this));

    auto parent_sizer = new wxBoxSizer(wxVERTICAL);

    m_import_staticbox = new wxStaticBoxSizer(wxVERTICAL, this, "Import Type");
    parent_sizer->Add(m_import_staticbox, wxSizerFlags().Expand().Border(wxALL));

    auto flex_grid_sizer = new wxFlexGridSizer(2, 0, 0);
    m_import_staticbox->Add(flex_grid_sizer, wxSizerFlags().Border(wxALL));

    m_radio_wxCrafter = new wxRadioButton(m_import_staticbox->GetStaticBox(), wxID_ANY, "wx&Crafter Project(s)", wxDefaultPosition, wxDefaultSize,
        wxRB_GROUP);
    flex_grid_sizer->Add(m_radio_wxCrafter, wxSizerFlags().Border(wxALL));

    m_radio_wxFormBuilder = new wxRadioButton(m_import_staticbox->GetStaticBox(), wxID_ANY, "wx&FormBuilder Project(s)");
    flex_grid_sizer->Add(m_radio_wxFormBuilder, wxSizerFlags().Border(wxALL));

    m_radio_wxGlade = new wxRadioButton(m_import_staticbox->GetStaticBox(), wxID_ANY, "wx&Glade Project(s)");
    flex_grid_sizer->Add(m_radio_wxGlade, wxSizerFlags().Border(wxALL));

    m_radio_wxSmith = new wxRadioButton(m_import_staticbox->GetStaticBox(), wxID_ANY, "wx&Smith Project(s)");
    flex_grid_sizer->Add(m_radio_wxSmith, wxSizerFlags().Border(wxALL));

    m_radio_WindowsResource = new wxRadioButton(m_import_staticbox->GetStaticBox(), wxID_ANY, "&Windows Resource");
    flex_grid_sizer->Add(m_radio_WindowsResource, wxSizerFlags().Border(wxALL));

    m_radio_XRC = new wxRadioButton(m_import_staticbox->GetStaticBox(), wxID_ANY, "&XRC File(s)");
    flex_grid_sizer->Add(m_radio_XRC, wxSizerFlags().Border(wxALL));

    auto box_sizer = new wxBoxSizer(wxHORIZONTAL);
    m_import_staticbox->Add(box_sizer, wxSizerFlags().Border(wxALL));

    m_combo_recent_dirs = new wxComboBox(m_import_staticbox->GetStaticBox(), wxID_ANY, wxEmptyString);
    m_combo_recent_dirs->Hide();
    m_combo_recent_dirs->SetInitialSize(wxSize(240 > GetBestSize().x ? 240 : -1, -1));
    box_sizer->Add(m_combo_recent_dirs, wxSizerFlags().Border(wxALL));

    m_btnRemove = new wxButton(m_import_staticbox->GetStaticBox(), wxID_ANY, "Remove");
    m_btnRemove->Hide();
    box_sizer->Add(m_btnRemove, wxSizerFlags().Border(wxALL));

    auto box_sizer6 = new wxBoxSizer(wxHORIZONTAL);
    m_import_staticbox->Add(box_sizer6, wxSizerFlags().Expand().Border(wxALL));

    m_btnAddFile = new wxButton(m_import_staticbox->GetStaticBox(), wxID_ANY, "&Directory...");
    m_btnAddFile->SetToolTip("You can add multiple formbuilder projects to a single wxUiEdtior project.");
    box_sizer6->Add(m_btnAddFile, wxSizerFlags().Center().Border(wxLEFT|wxRIGHT|wxTOP, wxSizerFlags::GetDefaultBorder()));

    m_static_cwd = new wxStaticText(m_import_staticbox->GetStaticBox(), wxID_ANY, "...", wxDefaultPosition, wxDefaultSize,
        wxST_ELLIPSIZE_MIDDLE);
    box_sizer6->Add(m_static_cwd, wxSizerFlags(1).Center().Border(wxALL));

    auto box_sizer7 = new wxBoxSizer(wxVERTICAL);
    m_import_staticbox->Add(box_sizer7, wxSizerFlags(1).Expand().Border(wxALL));

    m_staticImportList = new wxStaticText(m_import_staticbox->GetStaticBox(), wxID_ANY, "&Files:");
    box_sizer7->Add(m_staticImportList, wxSizerFlags().Border(wxLEFT|wxRIGHT|wxTOP, wxSizerFlags::GetDefaultBorder()));

    m_checkListProjects = new wxCheckListBox(m_import_staticbox->GetStaticBox(), wxID_ANY);
    m_checkListProjects->SetMinSize(wxSize(-1, 240));
    box_sizer7->Add(m_checkListProjects, wxSizerFlags().Expand().Border(wxALL));

    auto box_sizer_2 = new wxBoxSizer(wxHORIZONTAL);
    box_sizer7->Add(box_sizer_2, wxSizerFlags().Border(wxALL));

    auto btn_2 = new wxButton(m_import_staticbox->GetStaticBox(), wxID_ANY, "Select &All");
    box_sizer_2->Add(btn_2, wxSizerFlags().Border(wxALL));

    auto btn__2 = new wxButton(m_import_staticbox->GetStaticBox(), wxID_ANY, "Select &None");
    box_sizer_2->Add(btn__2, wxSizerFlags().Border(wxALL));

    m_stdBtn = CreateStdDialogButtonSizer(wxOK|wxCANCEL);
    parent_sizer->Add(CreateSeparatedSizer(m_stdBtn), wxSizerFlags().Expand().Border(wxALL));

    SetSizerAndFit(parent_sizer);
    Centre(wxBOTH);

    // Event handlers
    Bind(wxEVT_INIT_DIALOG, &ImportBase::OnInitDialog, this);
    m_radio_wxCrafter->Bind(wxEVT_RADIOBUTTON, &ImportBase::OnCrafter, this);
    m_radio_wxFormBuilder->Bind(wxEVT_RADIOBUTTON, &ImportBase::OnFormBuilder, this);
    m_radio_wxGlade->Bind(wxEVT_RADIOBUTTON, &ImportBase::OnWxGlade, this);
    m_radio_wxSmith->Bind(wxEVT_RADIOBUTTON, &ImportBase::OnWxSmith, this);
    m_radio_WindowsResource->Bind(wxEVT_RADIOBUTTON, &ImportBase::OnWindowsResource, this);
    m_radio_XRC->Bind(wxEVT_RADIOBUTTON, &ImportBase::OnXRC, this);
    m_combo_recent_dirs->Bind(wxEVT_COMBOBOX, &ImportBase::OnRecentDir, this);
    m_btnRemove->Bind(wxEVT_BUTTON, &ImportBase::OnRemove, this);
    m_btnAddFile->Bind(wxEVT_BUTTON, &ImportBase::OnDirectory, this);
    m_checkListProjects->Bind(wxEVT_CHECKLISTBOX, &ImportBase::OnCheckFiles, this);
    btn_2->Bind(wxEVT_BUTTON, &ImportBase::OnSelectAll, this);
    btn__2->Bind(wxEVT_BUTTON, &ImportBase::OnSelectNone, this);
    Bind(wxEVT_BUTTON, &ImportBase::OnOK, this, wxID_OK);

    return true;
}

namespace wxue_img
{

    const unsigned char import_svg[418] {
    120,218,141,83,203,78,195,48,16,228,83,86,225,106,167,246,218,73,28,40,72,168,106,197,133,43,7,110,16,232,67,10,18,82,
    171,74,244,235,217,89,167,144,67,16,84,169,31,51,235,217,241,110,50,223,31,55,183,243,215,183,245,158,118,175,55,5,22,
    85,44,102,183,243,143,231,195,150,246,135,207,254,237,166,88,239,250,254,234,178,93,44,221,106,117,93,144,196,61,132,
    16,141,143,169,243,77,89,27,103,2,203,174,140,152,3,31,125,203,157,51,160,236,128,90,37,238,155,212,217,124,66,0,229,
    172,114,143,62,57,162,206,101,114,192,243,177,123,201,116,42,212,28,44,181,211,222,156,187,91,46,199,222,162,207,217,
    152,37,87,20,225,132,49,58,100,146,60,2,43,98,20,220,114,85,119,136,148,173,224,70,113,220,130,104,17,26,241,223,202,
    191,170,33,106,6,241,19,61,52,201,120,57,103,125,40,145,132,165,32,174,76,152,57,158,75,0,10,168,81,84,30,77,149,79,200,
    206,14,156,28,250,41,129,144,118,80,202,143,92,100,84,1,239,81,130,141,238,55,190,45,166,202,193,47,78,126,90,141,119,
    98,87,27,78,190,100,234,200,162,29,142,108,50,54,148,181,206,137,30,169,170,133,115,6,44,9,14,80,153,28,157,12,98,147,
    73,116,36,150,14,177,6,35,22,34,2,91,112,99,139,97,186,75,19,182,126,247,148,254,107,201,255,237,167,250,175,159,22,133,
    176,12,59,209,88,105,2,217,10,201,89,196,123,178,13,218,165,35,194,208,69,12,195,42,193,174,71,157,191,137,148,39,128,
    34,217,83,93,201,2,67,94,89,93,118,191,197,3,14,131,28,196,85,251,236,66,77,44,164,31,242,30,181,144,97,151,212,255,249,
    30,79,163,251,55,184,255,76,62,244,25,62,247,139,47,17,124,226,91
    };

}
