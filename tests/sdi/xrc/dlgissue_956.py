<?xml version="1.0"?>
<!--Generated by wxUiEditor - - see https://github.com/KeyWorksRW/wxUiEditor -->
<!--DO NOT EDIT THIS FILE! Your changes will be lost if it is re-generated!-->
<resource xmlns="http://www.wxwidgets.org/wxxrc" version="2.5.3.0">
	<object class="wxDialog" name="DlgIssue_956">
		<title>colspan codegen issue</title>
		<style>wxDEFAULT_DIALOG_STYLE</style>
		<centered>1</centered>
		<object class="wxBoxSizer" name="dlg_sizer">
			<orient>wxVERTICAL</orient>
			<object class="sizeritem">
				<flag>wxALL|wxEXPAND</flag>
				<border>5</border>
				<object class="wxPanel" name="panel_2">
					<style>wxBORDER_THEME|wxTAB_TRAVERSAL</style>
					<object class="wxGridBagSizer" name="grid_bag_sizer">
						<vgap>0</vgap>
						<hgap>0</hgap>
						<growablerows>1</growablerows>
						<growablecols>1</growablecols>
						<flexibledirection>wxBOTH</flexibledirection>
						<nonflexiblegrowmode>wxFLEX_GROWMODE_ALL</nonflexiblegrowmode>
						<object class="sizeritem">
							<cellpos>0,0</cellpos>
							<cellspan>1,1</cellspan>
							<flag>wxALL</flag>
							<border>5</border>
							<object class="wxStaticText" name="m_staticText_4">
								<label>list test</label>
								<wrap>-1</wrap>
							</object>
						</object>
						<object class="sizeritem">
							<cellpos>0,1</cellpos>
							<cellspan>1,1</cellspan>
							<flag>wxALL|wxEXPAND</flag>
							<border>5</border>
							<option>1</option>
							<object class="wxChoice" name="m_choice" />
						</object>
						<object class="sizeritem">
							<cellpos>0,2</cellpos>
							<cellspan>1,1</cellspan>
							<flag>wxALL</flag>
							<border>5</border>
							<object class="wxButton" name="m_btn">
								<label>&amp;Refresh</label>
								<markup>1</markup>
							</object>
						</object>
						<object class="sizeritem">
							<cellpos>0,3</cellpos>
							<cellspan>1,1</cellspan>
							<flag>wxALL</flag>
							<border>5</border>
							<object class="wxButton" name="m_btn_2">
								<label>&amp;New</label>
								<markup>1</markup>
							</object>
						</object>
						<object class="sizeritem">
							<cellpos>0,4</cellpos>
							<cellspan>1,1</cellspan>
							<flag>wxALL</flag>
							<border>5</border>
							<object class="wxButton" name="m_btn_3">
								<label>&amp;Edit</label>
								<markup>1</markup>
							</object>
						</object>
						<object class="sizeritem">
							<cellpos>0,5</cellpos>
							<cellspan>1,1</cellspan>
							<flag>wxALL</flag>
							<border>5</border>
							<object class="wxButton" name="m_btn_4">
								<label>&amp;Delete</label>
								<markup>1</markup>
							</object>
						</object>
						<object class="sizeritem">
							<cellpos>1,0</cellpos>
							<cellspan>1,1</cellspan>
							<flag>wxALL</flag>
							<border>5</border>
							<object class="wxStaticText" name="m_staticText_5">
								<label>test type</label>
								<wrap>-1</wrap>
							</object>
						</object>
						<object class="sizeritem">
							<cellpos>1,1</cellpos>
							<cellspan>1,5</cellspan>
							<flag>wxALL|wxEXPAND</flag>
							<border>5</border>
							<object class="wxChoice" name="m_choice_2" />
						</object>
					</object>
				</object>
			</object>
			<object class="sizeritem">
				<flag>wxLEFT|wxRIGHT|wxTOP|wxEXPAND</flag>
				<border>5</border>
				<object class="wxBoxSizer">
					<orient>wxVERTICAL</orient>
					<object class="sizeritem">
						<flag>wxBOTTOM|wxEXPAND</flag>
						<border>5</border>
						<object class="wxStaticLine" />
					</object>
				</object>
			</object>
			<object class="sizeritem">
				<flag>wxALL|wxEXPAND</flag>
				<border>5</border>
				<object class="wxStdDialogButtonSizer" name="stdBtn">
					<object class="button">
						<object class="wxButton" name="wxID_OK">
							<default>1</default>
						</object>
					</object>
					<object class="button">
						<object class="wxButton" name="wxID_CANCEL" />
					</object>
				</object>
			</object>
		</object>
	</object>
</resource>
