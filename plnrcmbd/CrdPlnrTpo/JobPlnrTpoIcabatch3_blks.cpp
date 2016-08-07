/**
  * \file JobPlnrTpoIcabatch3_blks.cpp
  * job handler for job JobPlnrTpoIcabatch3 (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

/******************************************************************************
 class JobPlnrTpoIcabatch3::VecVSge
 ******************************************************************************/

uint JobPlnrTpoIcabatch3::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	else if (s == "creidle") return CREIDLE;
	else if (s == "create") return CREATE;
	else if (s == "expand1") return EXPAND1;
	else if (s == "expand2") return EXPAND2;
	else if (s == "plot") return PLOT;
	else if (s == "done") return DONE;

	return(0);
};

string JobPlnrTpoIcabatch3::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	else if (ix == CREIDLE) return("creidle");
	else if (ix == CREATE) return("create");
	else if (ix == EXPAND1) return("expand1");
	else if (ix == EXPAND2) return("expand2");
	else if (ix == PLOT) return("plot");
	else if (ix == DONE) return("done");

	return("");
};

void JobPlnrTpoIcabatch3::VecVSge::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=7;i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};


