/**
  * \file VecPlnrVTag.cpp
  * vector VecPlnrVTag (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "VecPlnrVTag.h"

/******************************************************************************
 namespace VecPlnrVTag
 ******************************************************************************/

uint VecPlnrVTag::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "about") return ABOUT;
	else if (s == "always") return ALWAYS;
	else if (s == "cancel") return CANCEL;
	else if (s == "close") return CLOSE;
	else if (s == "clsess") return CLSESS;
	else if (s == "create") return CREATE;
	else if (s == "detail") return DETAIL;
	else if (s == "done") return DONE;
	else if (s == "download") return DOWNLOAD;
	else if (s == "emplong") return EMPLONG;
	else if (s == "empshort") return EMPSHORT;
	else if (s == "error") return ERROR;
	else if (s == "filename") return FILENAME;
	else if (s == "fls") return FLS;
	else if (s == "for") return FOR;
	else if (s == "general") return GENERAL;
	else if (s == "goto") return GOTO;
	else if (s == "help") return HELP;
	else if (s == "import") return IMPORT;
	else if (s == "loaini") return LOAINI;
	else if (s == "nav") return NAV;
	else if (s == "no") return NO;
	else if (s == "ok") return OK;
	else if (s == "opscpllast") return OPSCPLLAST;
	else if (s == "opsprep") return OPSPREP;
	else if (s == "progress") return PROGRESS;
	else if (s == "quest") return QUEST;
	else if (s == "run") return RUN;
	else if (s == "sess") return SESS;
	else if (s == "showlong") return SHOWLONG;
	else if (s == "showshort") return SHOWSHORT;
	else if (s == "stop") return STOP;
	else if (s == "tru") return TRU;
	else if (s == "upload") return UPLOAD;
	else if (s == "yes") return YES;

	return(0);
};

string VecPlnrVTag::getSref(
			const uint ix
		) {
	if (ix == ABOUT) return("about");
	else if (ix == ALWAYS) return("always");
	else if (ix == CANCEL) return("cancel");
	else if (ix == CLOSE) return("close");
	else if (ix == CLSESS) return("clsess");
	else if (ix == CREATE) return("create");
	else if (ix == DETAIL) return("detail");
	else if (ix == DONE) return("done");
	else if (ix == DOWNLOAD) return("download");
	else if (ix == EMPLONG) return("emplong");
	else if (ix == EMPSHORT) return("empshort");
	else if (ix == ERROR) return("error");
	else if (ix == FILENAME) return("filename");
	else if (ix == FLS) return("fls");
	else if (ix == FOR) return("for");
	else if (ix == GENERAL) return("general");
	else if (ix == GOTO) return("goto");
	else if (ix == HELP) return("help");
	else if (ix == IMPORT) return("import");
	else if (ix == LOAINI) return("loaini");
	else if (ix == NAV) return("nav");
	else if (ix == NO) return("no");
	else if (ix == OK) return("ok");
	else if (ix == OPSCPLLAST) return("opscpllast");
	else if (ix == OPSPREP) return("opsprep");
	else if (ix == PROGRESS) return("progress");
	else if (ix == QUEST) return("quest");
	else if (ix == RUN) return("run");
	else if (ix == SESS) return("sess");
	else if (ix == SHOWLONG) return("showlong");
	else if (ix == SHOWSHORT) return("showshort");
	else if (ix == STOP) return("stop");
	else if (ix == TRU) return("tru");
	else if (ix == UPLOAD) return("upload");
	else if (ix == YES) return("yes");

	return("");
};

string VecPlnrVTag::getTitle(
			const uint ix
			, const uint ixPlnrVLocale
		) {
	if (ixPlnrVLocale == 1) {
		if (ix == ABOUT) return("About Planar");
		else if (ix == ALWAYS) return("always");
		else if (ix == CANCEL) return("cancel");
		else if (ix == CLOSE) return("close");
		else if (ix == CLSESS) return("close session");
		else if (ix == CREATE) return("create");
		else if (ix == DETAIL) return("details");
		else if (ix == DONE) return("done");
		else if (ix == DOWNLOAD) return("download");
		else if (ix == EMPLONG) return("no entries");
		else if (ix == EMPSHORT) return("empty");
		else if (ix == ERROR) return("error");
		else if (ix == FILENAME) return("file name");
		else if (ix == FLS) return("No");
		else if (ix == FOR) return("for &pretit;");
		else if (ix == GENERAL) return("generally");
		else if (ix == GOTO) return("go to");
		else if (ix == HELP) return("Planar help");
		else if (ix == IMPORT) return("import");
		else if (ix == LOAINI) return("load initialization data");
		else if (ix == NAV) return("navigation");
		else if (ix == NO) return("no");
		else if (ix == OK) return("OK");
		else if (ix == OPSCPLLAST) return("operations completed, last");
		else if (ix == OPSPREP) return("operations prepared");
		else if (ix == PROGRESS) return("progress");
		else if (ix == QUEST) return("question");
		else if (ix == RUN) return("execute");
		else if (ix == SESS) return("session");
		else if (ix == SHOWLONG) return("showing &firstdisp; to &lastdisp; of &ntot;");
		else if (ix == SHOWSHORT) return("&firstdisp;-&lastdisp; of &ntot;");
		else if (ix == TRU) return("Yes");
		else if (ix == UPLOAD) return("upload");
		else if (ix == YES) return("yes");
		else return(getSref(ix));
	};

	return("");
};

void VecPlnrVTag::appendToFeed(
			const uint ix
			, const uint ixPlnrVLocale
			, Feed& feed
		) {
	feed.appendIxSrefTitles(ix, getSref(ix), getTitle(ix, ixPlnrVLocale));
};


