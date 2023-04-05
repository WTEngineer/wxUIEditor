###############################################################################
# Code generated by wxUiEditor -- see https://github.com/KeyWorksRW/wxUiEditor/
#
# Do not edit any code above the "End of generated code" comment block.
# Any changes before that block will be lost if it is re-generated!
###############################################################################

import wx

from wx.lib.embeddedimage import PyEmbeddedImage

# 1_bottom.png
img_1_bottom_png = PyEmbeddedImage(
    b"iVBORw0KGgoAAAANSUhEUgAAABgAAAAYCAYAAADgdz34AAAACXBIWXMAAAsTAAALEwEAmpwYAAAARklE"
    b"QVRIx2NgGD4g7cx/hrQz/6nKZmBgYBqmQURFc0aDaDSIRoNoNIhGg4gagBHFawwMDP9nmVBmYNoZCGOW"
    b"CeNwS0U0AgDjl1CSPHv2FQAAAABJRU5ErkJggg==")

# bottom(1).png
bottom_1__png = PyEmbeddedImage(
    b"iVBORw0KGgoAAAANSUhEUgAAABgAAAAYCAYAAADgdz34AAAACXBIWXMAAAsTAAALEwEAmpwYAAAARklE"
    b"QVRIx2NgGD4g7cx/hrQz/6nKZmBgYBqmQURFc0aDaDSIRoNoNIhGg4gagBHFawwMDP9nmVBmYNoZCGOW"
    b"CeNwS0U0AgDjl1CSPHv2FQAAAABJRU5ErkJggg==")

# Ainsi ça se passe.png
Ainsi_c3_a_se_passe_png = PyEmbeddedImage(
    b"iVBORw0KGgoAAAANSUhEUgAAABgAAAAYCAYAAADgdz34AAAACXBIWXMAAAsTAAALEwEAmpwYAAAARklE"
    b"QVRIx2NgGD4g7cx/hrQz/6nKZmBgYBqmQURFc0aDaDSIRoNoNIhGg4gagBHFawwMDP9nmVBmYNoZCGOW"
    b"CeNwS0U0AgDjl1CSPHv2FQAAAABJRU5ErkJggg==")

class DlgIssue_960(wx.Dialog):
    def __init__(self, parent, id=wx.ID_ANY, title="", pos=
                wx.DefaultPosition, size=wx.DefaultSize,
                style=wx.DEFAULT_DIALOG_STYLE, name=wx.DialogNameStr):
        wx.Dialog.__init__(self)

        if not self.Create(parent, id, title, pos, size, style, name):
            return

        dlg_sizer = wx.BoxSizer(wx.VERTICAL)

        box_sizer = wx.BoxSizer(wx.HORIZONTAL)

        bmp = wx.StaticBitmap(self, wx.ID_ANY, wx.BitmapBundle.FromBitmap(
            img_1_bottom_png.Bitmap))
        box_sizer.Add(bmp, wx.SizerFlags().Border(wx.ALL))

        bmp_2 = wx.StaticBitmap(self, wx.ID_ANY, wx.BitmapBundle.FromBitmap(
            bottom_1__png.Bitmap))
        box_sizer.Add(bmp_2, wx.SizerFlags().Border(wx.ALL))

        dlg_sizer.Add(box_sizer, wx.SizerFlags().Border(wx.ALL))

        bmp_3 = wx.StaticBitmap(self, wx.ID_ANY, wx.BitmapBundle.FromBitmap(
            Ainsi_c3_a_se_passe_png.Bitmap))
        dlg_sizer.Add(bmp_3, wx.SizerFlags().Border(wx.ALL))

        if "wxMac" not in wx.PlatformInfo:
            stdBtn_line = wx.StaticLine(self, wx.ID_ANY, wx.DefaultPosition, wx.Size(20, -1))
            dlg_sizer.Add(stdBtn_line, wx.SizerFlags().Expand().Border(wx.ALL))

        stdBtn = wx.StdDialogButtonSizer()
        stdBtn_OK = wx.Button(self, wx.ID_OK)
        stdBtn.SetAffirmativeButton(stdBtn_OK)
        stdBtn_Cancel = wx.Button(self, wx.ID_CANCEL)
        stdBtn.SetCancelButton(stdBtn_Cancel)
        stdBtn_OK.SetDefault()
        stdBtn.Realize()
        dlg_sizer.Add(stdBtn, wx.SizerFlags().Expand().Border(wx.ALL))

        self.SetSizerAndFit(dlg_sizer)
        self.Centre(wx.BOTH)
# ************* End of generated code ***********
# DO NOT EDIT THIS COMMENT BLOCK!
#
# Code below this comment block will be preserved
# if the code for this class is re-generated.
# ***********************************************
