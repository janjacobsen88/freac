 /* fre:ac - free audio converter
  * Copyright (C) 2001-2013 Robert Kausch <robert.kausch@freac.org>
  *
  * This program is free software; you can redistribute it and/or
  * modify it under the terms of the "GNU General Public License".
  *
  * THIS PACKAGE IS PROVIDED "AS IS" AND WITHOUT ANY EXPRESS OR
  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE. */

#ifndef H_FREAC_CDDB_SUBMIT
#define H_FREAC_CDDB_SUBMIT

#include <smooth.h>

using namespace smooth;
using namespace smooth::GUI;

#include <config.h>

#include <cddb/cddbinfo.h>

#include <cdinfo/cdtext.h>
#include <cdinfo/cdplayerini.h>

namespace BonkEnc
{
	class cddbSubmitDlg : public Dialogs::Dialog
	{
		private:
			Divider		*divbar;

			Window		*mainWnd;
			Titlebar	*mainWnd_titlebar;

			GroupBox	*group_drive;
			ComboBox	*combo_drive;

			Text		*text_artist;
			EditBox		*edit_artist;
			List		*list_artist;
			Text		*text_album;
			EditBox		*edit_album;
			Text		*text_year;
			EditBox		*edit_year;
			Text		*text_genre;
			EditBox		*edit_genre;
			ListBox		*list_genre;
			Text		*text_disccomment;
			MultiEdit	*edit_disccomment;

			ListBox		*list_tracks;
			Text		*text_track;
			EditBox		*edit_track;
			Text		*text_trackartist;
			EditBox		*edit_trackartist;
			Text		*text_title;
			EditBox		*edit_title;
			Text		*text_comment;
			MultiEdit	*edit_comment;

			Text		*text_cdstatus;
			Text		*text_status;

			CheckBox	*check_updateJoblist;
			CheckBox	*check_submitLater;

			Button		*btn_cancel;
			Button		*btn_submit;

			Config		*currentConfig;

			Int		 activedrive;

			Bool		 dontUpdateInfo;
			Bool		 updateJoblist;
			Bool		 submitLater;

			CDDBInfo	 cddbInfo;

			Array<String>	 artists;
			Array<String>	 titles;
			Array<String>	 comments;

			CDText		 cdText;
			CDPlayerIni	 cdPlayerInfo;

			Void		 UpdateTrackList();

			String		 GetCDDBGenre(const String &);

			Bool		 IsDataValid();
			Bool		 IsStringValid(const String &);
		slots:
			Void		 Submit();
			Void		 Cancel();

			Void		 ChangeDrive();
			Void		 SelectTrack();
			Void		 UpdateTrack();
			Void		 FinishTrack();
			Void		 FinishArtist();
			Void		 UpdateComment();
			Void		 ToggleSubmitLater();

			Void		 SetArtist();	
		public:
					 cddbSubmitDlg();
					~cddbSubmitDlg();

			const Error	&ShowDialog();
	};
};

#endif
