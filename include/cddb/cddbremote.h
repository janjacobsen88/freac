 /* fre:ac - free audio converter
  * Copyright (C) 2001-2013 Robert Kausch <robert.kausch@freac.org>
  *
  * This program is free software; you can redistribute it and/or
  * modify it under the terms of the "GNU General Public License".
  *
  * THIS PACKAGE IS PROVIDED "AS IS" AND WITHOUT ANY EXPRESS OR
  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE. */

#ifndef H_FREAC_CDDB_REMOTE
#define H_FREAC_CDDB_REMOTE

#include <cddb/cddb.h>

using namespace smooth::IO;

namespace BonkEnc
{
	class BEEXPORT CDDBRemote : public CDDB
	{
		private:
			Bool		 connected;

			Buffer<char>	 hostNameBuffer;

			Driver		*socket;
			InStream	*in;
			OutStream	*out;

			String		 SendCommand(const String &);
		public:
					 CDDBRemote(Config *);
			virtual		~CDDBRemote();

			Bool		 ConnectToServer();
			Int		 Query(Int);
			Int		 Query(const String &);
			Bool		 Read(const String &, Int, CDDBInfo &);
			Bool		 Submit(const CDDBInfo &);
			Bool		 CloseConnection();
	};
};

#endif
