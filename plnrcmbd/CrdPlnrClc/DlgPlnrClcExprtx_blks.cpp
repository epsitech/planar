/**
  * \file DlgPlnrClcExprtx_blks.cpp
  * job handler for job DlgPlnrClcExprtx (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

/******************************************************************************
 class DlgPlnrClcExprtx::VecVDo
 ******************************************************************************/

uint DlgPlnrClcExprtx::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butdneclick") return BUTDNECLICK;

	return(0);
};

string DlgPlnrClcExprtx::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTDNECLICK) return("ButDneClick");

	return("");
};

/******************************************************************************
 class DlgPlnrClcExprtx::StatApp
 ******************************************************************************/

void DlgPlnrClcExprtx::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const string& shortMenu
		) {
	if (difftag.length() == 0) difftag = "StatAppDlgPlnrClcExprtx";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppDlgPlnrClcExprtx";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "shortMenu", shortMenu);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgPlnrClcExprtx::Tag
 ******************************************************************************/

void DlgPlnrClcExprtx::Tag::writeXML(
			const uint ixPlnrVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagDlgPlnrClcExprtx";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemDlgPlnrClcExprtx";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Export result data as text");
		};
		writeStringAttr(wr, itemtag, "sref", "ButDne", StrMod::cap(VecPlnrVTag::getTitle(VecPlnrVTag::DONE, ixPlnrVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgPlnrClcExprtx::DpchAppDo
 ******************************************************************************/

DlgPlnrClcExprtx::DpchAppDo::DpchAppDo() : DpchAppPlnr(VecPlnrVDpch::DPCHAPPDLGPLNRCLCEXPRTXDO) {
	ixVDo = 0;
};

void DlgPlnrClcExprtx::DpchAppDo::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppDlgPlnrClcExprtxDo");
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
 class DlgPlnrClcExprtx::DpchEngData
 ******************************************************************************/

DlgPlnrClcExprtx::DpchEngData::DpchEngData(
			const ubigint jref
			, const set<uint>& mask
		) : DpchEngPlnr(VecPlnrVDpch::DPCHENGDLGPLNRCLCEXPRTXDATA, jref) {
	if (find(mask, ALL)) this->mask = {JREF, STATAPP, TAG};
	else this->mask = mask;

};

void DlgPlnrClcExprtx::DpchEngData::merge(
			DpchEngPlnr* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(TAG)) add(TAG);
};

void DlgPlnrClcExprtx::DpchEngData::writeXML(
			const uint ixPlnrVLocale
			, pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngDlgPlnrClcExprtxData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixPlnrVLocale, wr);
	xmlTextWriterEndElement(wr);
};


