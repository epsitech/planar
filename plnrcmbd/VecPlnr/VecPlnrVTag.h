/**
  * \file VecPlnrVTag.h
  * vector VecPlnrVTag (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef VECPLNRVTAG_H
#define VECPLNRVTAG_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
	* VecPlnrVTag
	*/
namespace VecPlnrVTag {
	const uint ABOUT = 1;
	const uint ALWAYS = 2;
	const uint CANCEL = 3;
	const uint CLOSE = 4;
	const uint CLSESS = 5;
	const uint CREATE = 6;
	const uint DETAIL = 7;
	const uint DONE = 8;
	const uint DOWNLOAD = 9;
	const uint EMPLONG = 10;
	const uint EMPSHORT = 11;
	const uint ERROR = 12;
	const uint FILENAME = 13;
	const uint FLS = 14;
	const uint FOR = 15;
	const uint GENERAL = 16;
	const uint GOTO = 17;
	const uint HELP = 18;
	const uint IMPORT = 19;
	const uint LOAINI = 20;
	const uint NAV = 21;
	const uint NO = 22;
	const uint OK = 23;
	const uint OPSCPLLAST = 24;
	const uint OPSPREP = 25;
	const uint PROGRESS = 26;
	const uint QUEST = 27;
	const uint RUN = 28;
	const uint SESS = 29;
	const uint SHOWLONG = 30;
	const uint SHOWSHORT = 31;
	const uint STOP = 32;
	const uint TRU = 33;
	const uint UPLOAD = 34;
	const uint YES = 35;

	uint getIx(const string& sref);
	string getSref(const uint ix);

	string getTitle(const uint ix, const uint ixPlnrVLocale);

	void appendToFeed(const uint ix, const uint ixPlnrVLocale, Feed& feed);
};

#endif


