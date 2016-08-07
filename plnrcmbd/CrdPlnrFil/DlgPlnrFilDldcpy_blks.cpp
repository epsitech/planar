/**
  * \file DlgPlnrFilDldcpy_blks.cpp
  * job handler for job DlgPlnrFilDldcpy (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

/******************************************************************************
 class DlgPlnrFilDldcpy::VecVDo
 ******************************************************************************/

uint DlgPlnrFilDldcpy::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butdneclick") return BUTDNECLICK;

	return(0);
};

string DlgPlnrFilDldcpy::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTDNECLICK) return("ButDneClick");

	return("");
};

/******************************************************************************
 class DlgPlnrFilDldcpy::StatApp
 ******************************************************************************/

void DlgPlnrFilDldcpy::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const string& shortMenu
		) {
	if (difftag.length() == 0) difftag = "StatAppDlgPlnrFilDldcpy";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppDlgPlnrFilDldcpy";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "shortMenu", shortMenu);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgPlnrFilDldcpy::Tag
 ******************************************************************************/

void DlgPlnrFilDldcpy::Tag::writeXML(
			const uint ixPlnrVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagDlgPlnrFilDldcpy";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemDlgPlnrFilDldcpy";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Download copy");
		};
		writeStringAttr(wr, itemtag, "sref", "ButDne", StrMod::cap(VecPlnrVTag::getTitle(VecPlnrVTag::DONE, ixPlnrVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgPlnrFilDldcpy::DpchAppDo
 ******************************************************************************/

DlgPlnrFilDldcpy::DpchAppDo::DpchAppDo() : DpchAppPlnr(VecPlnrVDpch::DPCHAPPDLGPLNRFILDLDCPYDO) {
	ixVDo = 0;
};

void DlgPlnrFilDldcpy::DpchAppDo::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppDlgPlnrFilDldcpyDo");
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
 class DlgPlnrFilDldcpy::DpchEngData
 ******************************************************************************/

DlgPlnrFilDldcpy::DpchEngData::DpchEngData(
			const ubigint jref
			, const set<uint>& mask
		) : DpchEngPlnr(VecPlnrVDpch::DPCHENGDLGPLNRFILDLDCPYDATA, jref) {
	if (find(mask, ALL)) this->mask = {JREF, STATAPP, TAG};
	else this->mask = mask;

};

void DlgPlnrFilDldcpy::DpchEngData::merge(
			DpchEngPlnr* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(TAG)) add(TAG);
};

void DlgPlnrFilDldcpy::DpchEngData::writeXML(
			const uint ixPlnrVLocale
			, pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngDlgPlnrFilDldcpyData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixPlnrVLocale, wr);
	xmlTextWriterEndElement(wr);
};


