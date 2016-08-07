/**
  * \file DlgPlnrClcGenrpv_blks.cpp
  * job handler for job DlgPlnrClcGenrpv (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

/******************************************************************************
 class DlgPlnrClcGenrpv::VecVDo
 ******************************************************************************/

uint DlgPlnrClcGenrpv::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butdneclick") return BUTDNECLICK;

	return(0);
};

string DlgPlnrClcGenrpv::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTDNECLICK) return("ButDneClick");

	return("");
};

/******************************************************************************
 class DlgPlnrClcGenrpv::StatApp
 ******************************************************************************/

void DlgPlnrClcGenrpv::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const string& shortMenu
		) {
	if (difftag.length() == 0) difftag = "StatAppDlgPlnrClcGenrpv";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppDlgPlnrClcGenrpv";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "shortMenu", shortMenu);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgPlnrClcGenrpv::Tag
 ******************************************************************************/

void DlgPlnrClcGenrpv::Tag::writeXML(
			const uint ixPlnrVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagDlgPlnrClcGenrpv";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemDlgPlnrClcGenrpv";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Generate result data plot or video");
		};
		writeStringAttr(wr, itemtag, "sref", "ButDne", StrMod::cap(VecPlnrVTag::getTitle(VecPlnrVTag::DONE, ixPlnrVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgPlnrClcGenrpv::DpchAppDo
 ******************************************************************************/

DlgPlnrClcGenrpv::DpchAppDo::DpchAppDo() : DpchAppPlnr(VecPlnrVDpch::DPCHAPPDLGPLNRCLCGENRPVDO) {
	ixVDo = 0;
};

void DlgPlnrClcGenrpv::DpchAppDo::readXML(
			pthread_mutex_t* mScr
			, map<string,ubigint>& descr
			, xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppDlgPlnrClcGenrpvDo");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) {
			jref = Scr::descramble(mScr, descr, scrJref);
			add(JREF);
		};
		if (extractStringUclc(docctx, basexpath, "srefIxVDo", "", srefIxVDo)) {
			ixVDo = VecVDo::getIx(srefIxVDo);
			add(IXVDO);
		};
	} else {
	};
};

/******************************************************************************
 class DlgPlnrClcGenrpv::DpchEngData
 ******************************************************************************/

DlgPlnrClcGenrpv::DpchEngData::DpchEngData(
			const ubigint jref
			, const set<uint>& mask
		) : DpchEngPlnr(VecPlnrVDpch::DPCHENGDLGPLNRCLCGENRPVDATA, jref) {
	if (find(mask, ALL)) this->mask = {JREF, STATAPP, TAG};
	else this->mask = mask;

};

void DlgPlnrClcGenrpv::DpchEngData::merge(
			DpchEngPlnr* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(TAG)) add(TAG);
};

void DlgPlnrClcGenrpv::DpchEngData::writeXML(
			const uint ixPlnrVLocale
			, pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngDlgPlnrClcGenrpvData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixPlnrVLocale, wr);
	xmlTextWriterEndElement(wr);
};


