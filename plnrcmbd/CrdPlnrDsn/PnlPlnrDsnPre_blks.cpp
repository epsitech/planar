/**
  * \file PnlPlnrDsnPre_blks.cpp
  * job handler for job PnlPlnrDsnPre (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

/******************************************************************************
 class PnlPlnrDsnPre::Tag
 ******************************************************************************/

void PnlPlnrDsnPre::Tag::writeXML(
			const uint ixPlnrVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagPlnrDsnPre";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemPlnrDsnPre";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Design modification");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrDsnPre::DpchEngData
 ******************************************************************************/

PnlPlnrDsnPre::DpchEngData::DpchEngData(
			const ubigint jref
			, const set<uint>& mask
		) : DpchEngPlnr(VecPlnrVDpch::DPCHENGPLNRDSNPREDATA, jref) {
	if (find(mask, ALL)) this->mask = {JREF, TAG};
	else this->mask = mask;

};

void PnlPlnrDsnPre::DpchEngData::merge(
			DpchEngPlnr* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(TAG)) add(TAG);
};

void PnlPlnrDsnPre::DpchEngData::writeXML(
			const uint ixPlnrVLocale
			, pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngPlnrDsnPreData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		if (has(TAG)) Tag::writeXML(ixPlnrVLocale, wr);
	xmlTextWriterEndElement(wr);
};


