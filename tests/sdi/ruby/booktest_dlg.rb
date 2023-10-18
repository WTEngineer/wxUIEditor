###############################################################################
# Code generated by wxUiEditor -- see https://github.com/KeyWorksRW/wxUiEditor/
#
# Do not edit any code above the "End of generated code" comment block.
# Any changes before that block will be lost if it is re-generated!
###############################################################################

WX_GLOBAL_CONSTANTS = true unless defined? WX_GLOBAL_CONSTANTS

require 'wx/core'
require 'wx/aui'

require_relative 'images'

class BookTestDlg < Wx::Dialog
  def initialize(parent, id = Wx::ID_ANY, title = 'Book tests',
                 pos = Wx::DEFAULT_POSITION, size = Wx::DEFAULT_SIZE,
                 style = Wx::DEFAULT_DIALOG_STYLE)

    super(parent, id, title, pos, size, style)

    dlg_sizer = Wx::BoxSizer.new(Wx::VERTICAL)
    dlg_sizer.set_min_size(400, 400)

    @notebook = Wx::AUI::AuiNotebook.new(self, Wx::ID_ANY,
      Wx::DEFAULT_POSITION, Wx::DEFAULT_SIZE, Wx::AUI::AUI_NB_TOP|
      Wx::AUI::AUI_NB_TAB_SPLIT|Wx::AUI::AUI_NB_TAB_MOVE|
      Wx::AUI::AUI_NB_SCROLL_BUTTONS|Wx::AUI::AUI_NB_CLOSE_ON_ACTIVE_TAB|
      Wx::AUI::AUI_NB_MIDDLE_CLICK_CLOSE)
    dlg_sizer.add(@notebook, Wx::SizerFlags.new(1).expand.border(Wx::ALL))

    page_2 = Wx::Panel.new(@notebook, Wx::ID_ANY, Wx::DEFAULT_POSITION,
      Wx::DEFAULT_SIZE, Wx::TAB_TRAVERSAL)
    @notebook.add_page(page_2, 'ChoiceBook')

    page_sizer_1 = Wx::BoxSizer.new(Wx::VERTICAL)

    @choicebook = Wx::Choicebook.new(page_2, Wx::ID_ANY)
    @choicebook.set_min_size(Wx::Size.new(400, 400))
    page_sizer_1.add(@choicebook, Wx::SizerFlags.new.border(Wx::ALL))

    btn = Wx::Button.new(@choicebook, Wx::ID_ANY, 'First')
    @choicebook.get_control_sizer().add(btn, Wx::SizerFlags().Expand().Border(
      Wx::ALL))

    btn_2 = Wx::Button.new(@choicebook, Wx::ID_ANY, 'Last')
    @choicebook.get_control_sizer().add(btn_2, Wx::SizerFlags().Expand().Border(
      Wx::ALL))

    page_20 = Wx::Panel.new(@choicebook, Wx::ID_ANY, Wx::DEFAULT_POSITION,
      Wx::DEFAULT_SIZE, Wx::TAB_TRAVERSAL)
    @choicebook.add_page(page_20, 'English')
    page_20.set_background_colour(Wx::SystemSettings.get_colour(
      Wx::SYS_COLOUR_BTNFACE))

    parent_sizer_13 = Wx::BoxSizer.new(Wx::VERTICAL)

    @staticText_16 = Wx::StaticText.new(page_20, Wx::ID_ANY,
      'This is a sentence in English.')
    parent_sizer_13.add(@staticText_16, Wx::SizerFlags.new.border(Wx::ALL))

    box_sizer = Wx::BoxSizer.new(Wx::VERTICAL)

    @staticText_2 = Wx::StaticText.new(page_20, Wx::ID_ANY,
      'The First and Last buttons above are children of the wcChoicebook. They are added using choicebook->GetControlSizer() which allows them to share the layout space for the wxChoice control.')
    @staticText_2.wrap(380)
    box_sizer.add(@staticText_2, Wx::SizerFlags.new.expand.border(Wx::ALL))

    parent_sizer_13.add(box_sizer, Wx::SizerFlags.new.border(Wx::ALL))
    page_20.set_sizer_and_fit(parent_sizer_13)

    page_21 = Wx::Panel.new(@choicebook, Wx::ID_ANY, Wx::DEFAULT_POSITION,
      Wx::DEFAULT_SIZE, Wx::TAB_TRAVERSAL)
    @choicebook.add_page(page_21, 'Français')
    page_21.set_background_colour(Wx::SystemSettings.get_colour(
      Wx::SYS_COLOUR_BTNFACE))

    parent_sizer__2 = Wx::BoxSizer.new(Wx::VERTICAL)

    @staticText_17 = Wx::StaticText.new(page_21, Wx::ID_ANY,
      'Ceci est une phrase en français.')
    parent_sizer__2.add(@staticText_17, Wx::SizerFlags.new.border(Wx::ALL))

    box_sizer_3 = Wx::BoxSizer.new(Wx::VERTICAL)

    @staticText__3 = Wx::StaticText.new(page_21, Wx::ID_ANY,
      'The First and Last buttons above are children of the wcChoicebook. They are added using choicebook->GetControlSizer() which allows them to share the layout space for the wxChoice control.')
    @staticText__3.wrap(390)
    box_sizer_3.add(@staticText__3, Wx::SizerFlags.new.expand.border(Wx::ALL))

    parent_sizer__2.add(box_sizer_3, Wx::SizerFlags.new.border(Wx::ALL))
    page_21.set_sizer_and_fit(parent_sizer__2)

    page_22 = Wx::Panel.new(@choicebook, Wx::ID_ANY, Wx::DEFAULT_POSITION,
      Wx::DEFAULT_SIZE, Wx::TAB_TRAVERSAL)
    @choicebook.add_page(page_22, '日本語')
    page_22.set_background_colour(Wx::SystemSettings.get_colour(
      Wx::SYS_COLOUR_BTNFACE))

    parent_sizer_14 = Wx::BoxSizer.new(Wx::VERTICAL)

    @staticText_18 = Wx::StaticText.new(page_22, Wx::ID_ANY,
      'これは日本語の文章です。')
    parent_sizer_14.add(@staticText_18, Wx::SizerFlags.new.border(Wx::ALL))

    box_sizer_2 = Wx::BoxSizer.new(Wx::VERTICAL)

    @staticText__2 = Wx::StaticText.new(page_22, Wx::ID_ANY,
      'The First and Last buttons above are children of the wcChoicebook. They are added using choicebook->GetControlSizer() which allows them to share the layout space for the wxChoice control.')
    @staticText__2.wrap(390)
    box_sizer_2.add(@staticText__2, Wx::SizerFlags.new.expand.border(Wx::ALL))

    parent_sizer_14.add(box_sizer_2, Wx::SizerFlags.new.border(Wx::ALL))
    page_22.set_sizer_and_fit(parent_sizer_14)
    page_2.set_sizer_and_fit(page_sizer_1)

    page_3 = Wx::Panel.new(@notebook, Wx::ID_ANY, Wx::DEFAULT_POSITION,
      Wx::DEFAULT_SIZE, Wx::TAB_TRAVERSAL)
    @notebook.add_page(page_3, 'ListBook')

    page_sizer_2 = Wx::BoxSizer.new(Wx::VERTICAL)

    @listbook = Wx::Listbook.new(page_3, Wx::ID_ANY, Wx::DEFAULT_POSITION,
      Wx::DEFAULT_SIZE, Wx::LB_LEFT)

    bundle_list = [
      wxue_get_bundle($english_png),
      wxue_get_bundle($french_png),
      wxue_get_bundle($japanese_png)
    ]
    @listbook.set_images(bundle_list)
    @listbook.set_min_size(Wx::Size.new(400, 400))
    page_sizer_2.add(@listbook, Wx::SizerFlags.new.border(Wx::ALL))

    page_6 = Wx::Panel.new(@listbook, Wx::ID_ANY, Wx::DEFAULT_POSITION,
      Wx::DEFAULT_SIZE, Wx::TAB_TRAVERSAL)
    @listbook.add_page(page_6, 'English', false, 0)
    page_6.set_background_colour(Wx::SystemSettings.get_colour(
      Wx::SYS_COLOUR_BTNFACE))

    parent_sizer = Wx::BoxSizer.new(Wx::VERTICAL)

    @staticText_6 = Wx::StaticText.new(page_6, Wx::ID_ANY,
      'This is a sentence in English.')
    parent_sizer.add(@staticText_6, Wx::SizerFlags.new.border(Wx::ALL))
    page_6.set_sizer_and_fit(parent_sizer)

    page_7 = Wx::Panel.new(@listbook, Wx::ID_ANY, Wx::DEFAULT_POSITION,
      Wx::DEFAULT_SIZE, Wx::TAB_TRAVERSAL)
    @listbook.add_page(page_7, 'Français', false, 1)
    page_7.set_background_colour(Wx::SystemSettings.get_colour(
      Wx::SYS_COLOUR_BTNFACE))

    parent_sizer_2 = Wx::BoxSizer.new(Wx::VERTICAL)

    @staticText_3 = Wx::StaticText.new(page_7, Wx::ID_ANY,
      'Ceci est une phrase en français.')
    parent_sizer_2.add(@staticText_3, Wx::SizerFlags.new.border(Wx::ALL))
    page_7.set_sizer_and_fit(parent_sizer_2)

    page_8 = Wx::Panel.new(@listbook, Wx::ID_ANY, Wx::DEFAULT_POSITION,
      Wx::DEFAULT_SIZE, Wx::TAB_TRAVERSAL)
    @listbook.add_page(page_8, '日本語', false, 2)
    page_8.set_background_colour(Wx::SystemSettings.get_colour(
      Wx::SYS_COLOUR_BTNFACE))

    parent_sizer_3 = Wx::BoxSizer.new(Wx::VERTICAL)

    @staticText_7 = Wx::StaticText.new(page_8, Wx::ID_ANY,
      'これは日本語の文章です。')
    parent_sizer_3.add(@staticText_7, Wx::SizerFlags.new.border(Wx::ALL))
    page_8.set_sizer_and_fit(parent_sizer_3)

    page_3.set_sizer_and_fit(page_sizer_2)

    page_4 = Wx::Panel.new(@notebook, Wx::ID_ANY, Wx::DEFAULT_POSITION,
      Wx::DEFAULT_SIZE, Wx::TAB_TRAVERSAL)
    @notebook.add_page(page_4, 'NoteBook')

    page_sizer_3 = Wx::BoxSizer.new(Wx::VERTICAL)

    @notebook_2 = Wx::Notebook.new(page_4, Wx::ID_ANY)

    bundle_list = [
      wxue_get_bundle($english_png),
      wxue_get_bundle($french_png),
      wxue_get_bundle($japanese_png)
    ]
    @notebook_2.set_images(bundle_list)
    @notebook_2.set_min_size(Wx::Size.new(400, 400))
    page_sizer_3.add(@notebook_2, Wx::SizerFlags.new.expand.border(Wx::ALL))

    page_9 = Wx::Panel.new(@notebook_2, Wx::ID_ANY, Wx::DEFAULT_POSITION,
      Wx::DEFAULT_SIZE, Wx::TAB_TRAVERSAL)
    @notebook_2.add_page(page_9, 'English', false, 0)
    page_9.set_background_colour(Wx::SystemSettings.get_colour(
      Wx::SYS_COLOUR_BTNFACE))

    parent_sizer_4 = Wx::BoxSizer.new(Wx::VERTICAL)

    @staticText_4 = Wx::StaticText.new(page_9, Wx::ID_ANY,
      'This is a sentence in English.')
    parent_sizer_4.add(@staticText_4, Wx::SizerFlags.new.border(Wx::ALL))
    page_9.set_sizer_and_fit(parent_sizer_4)

    page_10 = Wx::Panel.new(@notebook_2, Wx::ID_ANY, Wx::DEFAULT_POSITION,
      Wx::DEFAULT_SIZE, Wx::TAB_TRAVERSAL)
    @notebook_2.add_page(page_10, 'Français', false, 1)
    page_10.set_background_colour(Wx::SystemSettings.get_colour(
      Wx::SYS_COLOUR_BTNFACE))

    parent_sizer_5 = Wx::BoxSizer.new(Wx::VERTICAL)

    @staticText_8 = Wx::StaticText.new(page_10, Wx::ID_ANY,
      'Ceci est une phrase en français.')
    parent_sizer_5.add(@staticText_8, Wx::SizerFlags.new.border(Wx::ALL))
    page_10.set_sizer_and_fit(parent_sizer_5)

    page_11 = Wx::Panel.new(@notebook_2, Wx::ID_ANY, Wx::DEFAULT_POSITION,
      Wx::DEFAULT_SIZE, Wx::TAB_TRAVERSAL)
    @notebook_2.add_page(page_11, '日本語', false, 2)
    page_11.set_background_colour(Wx::SystemSettings.get_colour(
      Wx::SYS_COLOUR_BTNFACE))

    parent_sizer_6 = Wx::BoxSizer.new(Wx::VERTICAL)

    @staticText_9 = Wx::StaticText.new(page_11, Wx::ID_ANY,
      'これは日本語の文章です。')
    parent_sizer_6.add(@staticText_9, Wx::SizerFlags.new.border(Wx::ALL))
    page_11.set_sizer_and_fit(parent_sizer_6)

    page_4.set_sizer_and_fit(page_sizer_3)

    page_5 = Wx::Panel.new(@notebook, Wx::ID_ANY, Wx::DEFAULT_POSITION,
      Wx::DEFAULT_SIZE, Wx::TAB_TRAVERSAL)
    @notebook.add_page(page_5, 'ToolBook')

    page_sizer_4 = Wx::BoxSizer.new(Wx::VERTICAL)

    @toolbook = Wx::Toolbook.new(page_5, Wx::ID_ANY)

    bundle_list = [
      wxue_get_bundle($english_png),
      wxue_get_bundle($french_png),
      wxue_get_bundle($japanese_png)
    ]
    @toolbook.set_images(bundle_list)
    @toolbook.set_min_size(Wx::Size.new(400, 400))
    page_sizer_4.add(@toolbook, Wx::SizerFlags.new.border(Wx::ALL))

    page_12 = Wx::Panel.new(@toolbook, Wx::ID_ANY, Wx::DEFAULT_POSITION,
      Wx::DEFAULT_SIZE, Wx::TAB_TRAVERSAL)
    @toolbook.add_page(page_12, 'English', false, 0)
    page_12.set_background_colour(Wx::SystemSettings.get_colour(
      Wx::SYS_COLOUR_BTNFACE))

    parent_sizer_7 = Wx::BoxSizer.new(Wx::VERTICAL)

    @staticText_5 = Wx::StaticText.new(page_12, Wx::ID_ANY,
      'This is a sentence in English.')
    parent_sizer_7.add(@staticText_5, Wx::SizerFlags.new.border(Wx::ALL))
    page_12.set_sizer_and_fit(parent_sizer_7)

    page_13 = Wx::Panel.new(@toolbook, Wx::ID_ANY, Wx::DEFAULT_POSITION,
      Wx::DEFAULT_SIZE, Wx::TAB_TRAVERSAL)
    @toolbook.add_page(page_13, 'Français', false, 1)
    page_13.set_background_colour(Wx::SystemSettings.get_colour(
      Wx::SYS_COLOUR_BTNFACE))

    parent_sizer_8 = Wx::BoxSizer.new(Wx::VERTICAL)

    @staticText_10 = Wx::StaticText.new(page_13, Wx::ID_ANY,
      'Ceci est une phrase en français.')
    parent_sizer_8.add(@staticText_10, Wx::SizerFlags.new.border(Wx::ALL))
    page_13.set_sizer_and_fit(parent_sizer_8)

    page_14 = Wx::Panel.new(@toolbook, Wx::ID_ANY, Wx::DEFAULT_POSITION,
      Wx::DEFAULT_SIZE, Wx::TAB_TRAVERSAL)
    @toolbook.add_page(page_14, '日本語', false, 2)
    page_14.set_background_colour(Wx::SystemSettings.get_colour(
      Wx::SYS_COLOUR_BTNFACE))

    parent_sizer_9 = Wx::BoxSizer.new(Wx::VERTICAL)

    @staticText_11 = Wx::StaticText.new(page_14, Wx::ID_ANY,
      'これは日本語の文章です。')
    parent_sizer_9.add(@staticText_11, Wx::SizerFlags.new.border(Wx::ALL))
    page_14.set_sizer_and_fit(parent_sizer_9)

    page_5.set_sizer_and_fit(page_sizer_4)

    page = Wx::Panel.new(@notebook, Wx::ID_ANY, Wx::DEFAULT_POSITION,
      Wx::DEFAULT_SIZE, Wx::TAB_TRAVERSAL)
    @notebook.add_page(page, 'TreeBook')

    page_sizer_5 = Wx::BoxSizer.new(Wx::VERTICAL)

    @treebook = Wx::Treebook.new(page, Wx::ID_ANY)

    bundle_list = [
      wxue_get_bundle($english_png),
      wxue_get_bundle($french_png),
      wxue_get_bundle($japanese_png)
    ]
    @treebook.set_images(bundle_list)
    @treebook.set_min_size(Wx::Size.new(400, 400))
    page_sizer_5.add(@treebook, Wx::SizerFlags.new.border(Wx::ALL))

    page_15 = Wx::Panel.new(@treebook, Wx::ID_ANY, Wx::DEFAULT_POSITION,
      Wx::DEFAULT_SIZE, Wx::TAB_TRAVERSAL)
    @treebook.add_page(page_15, 'English', false, 0)
    page_15.set_background_colour(Wx::SystemSettings.get_colour(
      Wx::SYS_COLOUR_BTNFACE))

    parent_sizer_10 = Wx::BoxSizer.new(Wx::VERTICAL)

    @staticText_12 = Wx::StaticText.new(page_15, Wx::ID_ANY,
      'This is a sentence in English.')
    parent_sizer_10.add(@staticText_12, Wx::SizerFlags.new.border(Wx::ALL))
    page_15.set_sizer_and_fit(parent_sizer_10)

    page_16 = Wx::Panel.new(@treebook, Wx::ID_ANY, Wx::DEFAULT_POSITION,
      Wx::DEFAULT_SIZE, Wx::TAB_TRAVERSAL)
    @treebook.add_sub_page(page_16, 'British', false, 1)
    page_16.set_background_colour(Wx::SystemSettings.get_colour(
      Wx::SYS_COLOUR_BTNFACE))

    page_sizer = Wx::BoxSizer.new(Wx::VERTICAL)

    @staticText_13 = Wx::StaticText.new(page_16, Wx::ID_ANY, 'Theatre')
    page_sizer.add(@staticText_13, Wx::SizerFlags.new.border(Wx::ALL))
    page_16.set_sizer_and_fit(page_sizer)

    page_17 = Wx::Panel.new(@treebook, Wx::ID_ANY, Wx::DEFAULT_POSITION,
      Wx::DEFAULT_SIZE, Wx::TAB_TRAVERSAL)
    @treebook.add_sub_page(page_17, 'United States', false, 2)
    page_17.set_background_colour(Wx::SystemSettings.get_colour(
      Wx::SYS_COLOUR_BTNFACE))

    page_sizer_6 = Wx::BoxSizer.new(Wx::VERTICAL)

    @staticText_14 = Wx::StaticText.new(page_17, Wx::ID_ANY, 'Theater')
    page_sizer_6.add(@staticText_14, Wx::SizerFlags.new.border(Wx::ALL))
    page_17.set_sizer_and_fit(page_sizer_6)

    page_18 = Wx::Panel.new(@treebook, Wx::ID_ANY, Wx::DEFAULT_POSITION,
      Wx::DEFAULT_SIZE, Wx::TAB_TRAVERSAL)
    @treebook.add_page(page_18, 'Français', false, 3)
    page_18.set_background_colour(Wx::SystemSettings.get_colour(
      Wx::SYS_COLOUR_BTNFACE))

    parent_sizer_11 = Wx::BoxSizer.new(Wx::VERTICAL)

    @staticText_15 = Wx::StaticText.new(page_18, Wx::ID_ANY,
      'Ceci est une phrase en français.')
    parent_sizer_11.add(@staticText_15, Wx::SizerFlags.new.border(Wx::ALL))
    page_18.set_sizer_and_fit(parent_sizer_11)

    page_19 = Wx::Panel.new(@treebook, Wx::ID_ANY, Wx::DEFAULT_POSITION,
      Wx::DEFAULT_SIZE, Wx::TAB_TRAVERSAL)
    @treebook.add_page(page_19, '日本語', false, 4)
    page_19.set_background_colour(Wx::SystemSettings.get_colour(
      Wx::SYS_COLOUR_BTNFACE))

    parent_sizer_12 = Wx::BoxSizer.new(Wx::VERTICAL)

    @staticText = Wx::StaticText.new(page_19, Wx::ID_ANY,
      'これは日本語の文章です。')
    parent_sizer_12.add(@staticText, Wx::SizerFlags.new.border(Wx::ALL))
    page_19.set_sizer_and_fit(parent_sizer_12)

    page.set_sizer_and_fit(page_sizer_5)

    if Wx::PLATFORM != 'WXMAC'
      stdBtn_line = Wx::StaticLine.new(self, Wx::ID_ANY, Wx::DEFAULT_POSITION,
                                  Wx::Size.new(20, -1))
      dlg_sizer.add(stdBtn_line, Wx::SizerFlags.new.expand.border(Wx::ALL))
    end
    stdBtn = Wx::StdDialogButtonSizer.new
    _ok_btn = Wx::Button.new(self, Wx::ID_OK)
    stdBtn.add_button(_ok_btn)
    _ok_btn.set_default
    stdBtn.add_button(Wx::Button.new(self, Wx::ID_CANCEL))
    stdBtn.realize
    dlg_sizer.add(stdBtn, Wx::SizerFlags.new.expand.border(Wx::ALL))

    set_sizer_and_fit(dlg_sizer)
    centre(Wx::BOTH)

    # Event handlers
    evt_button(btn.get_id, :OnEvent)
    evt_button(btn_2.get_id, :OnEvent)
  end
end
# ************* End of generated code ***********
# DO NOT EDIT THIS COMMENT BLOCK!
#
# Code below this comment block will be preserved
# if the code for this class is re-generated.
# ***********************************************

def OnEvent(event)
  event.skip
end
