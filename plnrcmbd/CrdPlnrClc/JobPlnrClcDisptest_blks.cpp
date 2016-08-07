/**
  * \file JobPlnrClcDisptest_blks.cpp
  * job handler for job JobPlnrClcDisptest (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

/******************************************************************************
 class JobPlnrClcDisptest::VecVSge
 ******************************************************************************/

uint JobPlnrClcDisptest::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	else if (s == "prpidle") return PRPIDLE;
	else if (s == "prepare") return PREPARE;
	else if (s == "expand1") return EXPAND1;
	else if (s == "expand2") return EXPAND2;
	else if (s == "expand3") return EXPAND3;
	else if (s == "discr") return DISCR;
	else if (s == "calc") return CALC;
	else if (s == "plot") return PLOT;
	else if (s == "done") return DONE;

	return(0);
};

string JobPlnrClcDisptest::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	else if (ix == PRPIDLE) return("prpidle");
	else if (ix == PREPARE) return("prepare");
	else if (ix == EXPAND1) return("expand1");
	else if (ix == EXPAND2) return("expand2");
	else if (ix == EXPAND3) return("expand3");
	else if (ix == DISCR) return("discr");
	else if (ix == CALC) return("calc");
	else if (ix == PLOT) return("plot");
	else if (ix == DONE) return("done");

	return("");
};

void JobPlnrClcDisptest::VecVSge::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=10;i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};


