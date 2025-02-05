/////////////////////////////////////////////////////////////////////////////
// Purpose:   ProjectHandler class
// Author:    Ralph Walden
// Copyright: Copyright (c) 2020-2024 KeyWorks Software (Ralph Walden)
// License:   Apache License -- see ../LICENSE
/////////////////////////////////////////////////////////////////////////////

#pragma once  // NOLINT(#pragma once in main file)

#include <utility>  // for pair<>

#include "gen_enums.h"  // Enumerations for generators
#include "node.h"       // Node class

namespace pugi
{
    class xml_document;
}

class ImportXML;

enum : size_t
{
    OUTPUT_NONE = 0,
    OUTPUT_CPLUS = 1 << 0,
    OUTPUT_DERIVED = 1 << 1,
    OUTPUT_C_DERIVED = OUTPUT_CPLUS | OUTPUT_DERIVED,
    OUTPUT_PYTHON = 1 << 2,
    OUTPUT_RUBY = 1 << 3,
    OUTPUT_XRC = 1 << 4,
};

enum
{
    OUT_FLAG_NONE = 0,
    OUT_FLAG_IGNORE_DERIVED = 1 << 0,  // Ignore derived output files
    OUT_FLAG_IGNORE_XRC = 1 << 1,      // Ignore XRC output files
};

class ProjectHandler
{
private:
    ProjectHandler() {}

public:
    ProjectHandler(ProjectHandler const&) = delete;

    void operator=(ProjectHandler const&) = delete;

    static ProjectHandler& getInstance()
    {
        static ProjectHandler instance;
        return instance;
    }

    // Calling this will also initialize the ProjectImage class
    void Initialize(NodeSharedPtr project, bool allow_ui = true);

    // This will convert the project path into a full path
    void setProjectFile(const tt_string& file);

    // Returns the full path to the directory the project file is in
    tt_string getProjectPath() const { return m_projectPath; }

    // Returns the full path to the project filename
    tt_string getProjectFile() const { return m_projectFile; }

    // Get a bit flag indicating which output types are enabled.
    //
    // OUTPUT_DERIVED is only set if the file is specified and does *not* exist.
    size_t getOutputType(int flags = OUT_FLAG_NONE) const;

    // Change to the project's directory
    bool ChangeDir() const { return m_projectPath.ChangeDir(); }

    tt_string ArtDirectory() const;

    // If the node is within a folder, and the folder specifies a directory, then that
    // directory is returned. Otherwise the project base directory is returned.
    tt_string getBaseDirectory(Node* node, int language = GEN_LANG_CPLUSPLUS) const;

    // Returns the absolute path to the output file for this node. If no output filename is
    // specified, first will still contain a path with no filename, and second will be false.
    std::pair<tt_string, bool> GetOutputPath(Node* form, int language = GEN_LANG_CPLUSPLUS) const;

    // If the node is within a folder, and the folder specifies a directory, then that
    // directory is returned. Otherwise the project derived directory is returned.
    tt_string getDerivedDirectory(Node* node, int language = GEN_LANG_CPLUSPLUS) const;

    // Returns the full path to the derived filename or an empty string if no derived file
    // was specified.
    tt_string getDerivedFilename(Node*) const;

    Node* getProjectNode() const { return m_project_node.get(); }
    auto& getChildNodePtrs() { return m_project_node->getChildNodePtrs(); }
    Node* getChild(size_t index) { return m_project_node->getChild(index); }

    // This includes forms in folders and sub-folders
    void CollectForms(std::vector<Node*>& forms, Node* node_start = nullptr);

    // Returns the first project child that is a form, or nullptr if no form children found.
    Node* getFirstFormChild(Node* node = nullptr) const;

    // Make class and filenames unique to the project
    void FixupDuplicatedNode(Node* new_node);

    auto getProjectVersion() const { return m_ProjectVersion; }
    auto getOriginalProjectVersion() const { return m_OriginalProjectVersion; }
    void ForceProjectVersion(int version) { m_ProjectVersion = version; }

    // Call this after the user has been warned about saving a project file that is incompatible
    // with older versions of wxUiEditor
    void UpdateOriginalProjectVersion() { m_OriginalProjectVersion = m_ProjectVersion; }

    // Call setProjectUpdated() if the project file's minimum version needs to be updated
    void setProjectUpdated() { m_isProject_updated = true; }
    // Call isProjectUpdated() to determine if the project file's minimum version needs to be updated
    bool isProjectUpdated() const { return m_isProject_updated; }

    bool isUiAllowed() const { return m_allow_ui; }

    bool is_wxWidgets31() const { return m_project_node->as_string(prop_wxWidgets_version) == "3.1"; }
    int get_WidgetsMinorVersion();  // Currently returns 1, 2 or 3 for 3.1, 3.2, 3.3

    size_t getChildCount() const { return m_project_node->getChildCount(); }

    // Returns a GEN_LANG_... enum value. Specify a node if you want to check for a folder
    // override of the language.
    int getCodePreference(Node* node = nullptr) const;

    // const tt_string& value(GenEnum::PropName name) const { return m_project_node->as_string(name); }
    const tt_string_view view(PropName name) const { return m_project_node->as_string(name); }
    const tt_string& as_string(PropName name) const { return m_project_node->as_string(name); }

    bool as_bool(PropName name) const { return m_project_node->as_bool(name); }
    size_t as_size_t(PropName name) const { return (to_size_t) m_project_node->as_int(name); }

    // Returns true if the property exists, has a value (!= wxDefaultSize, !=
    // wxDefaultPosition, or non-sepcified bitmap)
    bool hasValue(PropName name) const { return m_project_node->hasValue(name); }

    bool LoadProject(const tt_string& file, bool allow_ui = true);
    NodeSharedPtr LoadProject(pugi::xml_document& doc, bool allow_ui = true);

    bool Import(ImportXML& import, tt_string& file, bool append = false, bool allow_ui = true);
    bool ImportProject(tt_string& file, bool allow_ui = true);

    void appendCrafter(wxArrayString& files);
    void appendDialogBlocks(wxArrayString& files);
    void appendFormBuilder(wxArrayString& files);
    void appendGlade(wxArrayString& files);
    void appendSmith(wxArrayString& files);
    void appendXRC(wxArrayString& files);
    void appendWinRes(const tt_string& rc_file, std::vector<tt_string>& dialogs);

    bool NewProject(bool create_empty = false, bool allow_ui = true);

    // Call this after a project is imported and converted into a Node tree. This will do a
    // final check and fixup for things like inconsistent styles, invalid gridbag sizer rows
    // and columns, etc. Because it runs on the Node tree, it doesn't matter what importer
    // was used.
    void FinalImportCheck(Node* project, bool set_line_length = true);

    // Called by FinalImportCheck() to recursively check the node and all of it's children,
    // grandchildren, etc.
    void RecursiveNodeCheck(Node* node);

    // Assumes CollectForms() has already been called. Finds out which form should be used
    // to generate wxue() functions for embedded images.
    void FindWxueFunctions(std::vector<Node*>& forms);

    // After calling FindWxueFunctions(), this will return the form that should be used to
    // generate the one copy of wxueBundleSVG() that is used by all forms.
    Node* getForm_BundleSVG() const { return m_form_BundleSVG; }

    // After calling FindWxueFunctions(), this will return the form that should be used to
    // generate the one copy of wxueImage() that is used by all forms.
    Node* getForm_Image() const { return m_form_Image; }

    // After calling FindWxueFunctions(), this will return the form that should be used to
    // generate the one copy of wxueAnimation() that is used by all forms.
    Node* getForm_Animation() const { return m_form_BundleBitmaps; }

    // This will assume any ImagesList class will be the first child of the project, and will
    // either return that Node* or nullptr if no ImagesList class is found.
    Node* getImagesForm();

    // This will assume any Data class will be the first or second child of the project, and
    // will either return that Node* or nullptr if no Data class is found.
    Node* getDataForm();

    // Sets project property value only if the property exists, returns false if it doesn't
    // exist.
    template <typename T>
    bool set_value(PropName name, T value)
    {
        if (auto prop = m_project_node->getPropPtr(name); prop)
        {
            prop->set_value(value);
            return true;
        }
        else
        {
            return false;
        }
    }

private:
    NodeSharedPtr m_project_node { nullptr };

    Node* m_form_BundleSVG { nullptr };
    Node* m_form_Image { nullptr };
    Node* m_form_BundleBitmaps { nullptr };
    Node* m_form_Animation { nullptr };
    Node* m_ImagesForm { nullptr };
    Node* m_DataForm { nullptr };

    tt_string m_projectFile;
    tt_string m_projectPath;

    int m_ProjectVersion;
    int m_OriginalProjectVersion;

    bool m_allow_ui { true };
    bool m_isProject_updated { false };
};

extern ProjectHandler& Project;
