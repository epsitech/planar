/**
  * \file VecPlnrVCard.cpp
  * vector VecPlnrVCard (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "VecPlnrVCard.h"

/******************************************************************************
 namespace VecPlnrVCard
 ******************************************************************************/

uint VecPlnrVCard::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "crdplnrnav") return CRDPLNRNAV;
	else if (s == "crdplnrusg") return CRDPLNRUSG;
	else if (s == "crdplnrusr") return CRDPLNRUSR;
	else if (s == "crdplnrprs") return CRDPLNRPRS;
	else if (s == "crdplnrfil") return CRDPLNRFIL;
	else if (s == "crdplnrdtp") return CRDPLNRDTP;
	else if (s == "crdplnrctp") return CRDPLNRCTP;
	else if (s == "crdplnrmat") return CRDPLNRMAT;
	else if (s == "crdplnrprj") return CRDPLNRPRJ;
	else if (s == "crdplnrdsn") return CRDPLNRDSN;
	else if (s == "crdplnrdom") return CRDPLNRDOM;
	else if (s == "crdplnrdgd") return CRDPLNRDGD;
	else if (s == "crdplnrdvc") return CRDPLNRDVC;
	else if (s == "crdplnrsru") return CRDPLNRSRU;
	else if (s == "crdplnrstk") return CRDPLNRSTK;
	else if (s == "crdplnrlyr") return CRDPLNRLYR;
	else if (s == "crdplnrclc") return CRDPLNRCLC;
	else if (s == "crdplnrcli") return CRDPLNRCLI;
	else if (s == "crdplnrtpo") return CRDPLNRTPO;
	else if (s == "crdplnrarr") return CRDPLNRARR;
	else if (s == "crdplnrari") return CRDPLNRARI;
	else if (s == "crdplnrrtc") return CRDPLNRRTC;

	return(0);
};

string VecPlnrVCard::getSref(
			const uint ix
		) {
	if (ix == CRDPLNRNAV) return("CrdPlnrNav");
	else if (ix == CRDPLNRUSG) return("CrdPlnrUsg");
	else if (ix == CRDPLNRUSR) return("CrdPlnrUsr");
	else if (ix == CRDPLNRPRS) return("CrdPlnrPrs");
	else if (ix == CRDPLNRFIL) return("CrdPlnrFil");
	else if (ix == CRDPLNRDTP) return("CrdPlnrDtp");
	else if (ix == CRDPLNRCTP) return("CrdPlnrCtp");
	else if (ix == CRDPLNRMAT) return("CrdPlnrMat");
	else if (ix == CRDPLNRPRJ) return("CrdPlnrPrj");
	else if (ix == CRDPLNRDSN) return("CrdPlnrDsn");
	else if (ix == CRDPLNRDOM) return("CrdPlnrDom");
	else if (ix == CRDPLNRDGD) return("CrdPlnrDgd");
	else if (ix == CRDPLNRDVC) return("CrdPlnrDvc");
	else if (ix == CRDPLNRSRU) return("CrdPlnrSru");
	else if (ix == CRDPLNRSTK) return("CrdPlnrStk");
	else if (ix == CRDPLNRLYR) return("CrdPlnrLyr");
	else if (ix == CRDPLNRCLC) return("CrdPlnrClc");
	else if (ix == CRDPLNRCLI) return("CrdPlnrCli");
	else if (ix == CRDPLNRTPO) return("CrdPlnrTpo");
	else if (ix == CRDPLNRARR) return("CrdPlnrArr");
	else if (ix == CRDPLNRARI) return("CrdPlnrAri");
	else if (ix == CRDPLNRRTC) return("CrdPlnrRtc");

	return("");
};

string VecPlnrVCard::getTitle(
			const uint ix
			, const uint ixPlnrVLocale
		) {
	if (ixPlnrVLocale == 1) {
		if (ix == CRDPLNRUSG) return("user groups");
		else if (ix == CRDPLNRUSR) return("users");
		else if (ix == CRDPLNRPRS) return("persons");
		else if (ix == CRDPLNRFIL) return("files");
		else if (ix == CRDPLNRDTP) return("device templates");
		else if (ix == CRDPLNRCTP) return("calculation templates");
		else if (ix == CRDPLNRMAT) return("materials");
		else if (ix == CRDPLNRPRJ) return("projects");
		else if (ix == CRDPLNRDSN) return("designs");
		else if (ix == CRDPLNRDOM) return("domains");
		else if (ix == CRDPLNRDGD) return("domain guides");
		else if (ix == CRDPLNRDVC) return("devices");
		else if (ix == CRDPLNRSRU) return("structures");
		else if (ix == CRDPLNRSTK) return("stacks");
		else if (ix == CRDPLNRLYR) return("layers");
		else if (ix == CRDPLNRCLC) return("calculations");
		else if (ix == CRDPLNRCLI) return("calculation items");
		else if (ix == CRDPLNRTPO) return("tape-outs");
		else if (ix == CRDPLNRARR) return("arrays");
		else if (ix == CRDPLNRARI) return("array items");
		else if (ix == CRDPLNRRTC) return("reticles");
		else return(getSref(ix));
	};

	return("");
};

void VecPlnrVCard::fillFeed(
			const uint ixPlnrVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=22;i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixPlnrVLocale));
};

