/**
  * \file SessPlnr_blks.cpp
  * job handler for job SessPlnr (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

/******************************************************************************
 class SessPlnr::StatShr
 ******************************************************************************/

SessPlnr::StatShr::StatShr(
			const ubigint jrefCrdnav
		) : Block() {
	this->jrefCrdnav = jrefCrdnav;

	mask = {JREFCRDNAV};
};

void SessPlnr::StatShr::writeXML(
			pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrSessPlnr";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrSessPlnr";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "scrJrefCrdnav", Scr::scramble(mScr, scr, descr, jrefCrdnav));
	xmlTextWriterEndElement(wr);
};

set<uint> SessPlnr::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (jrefCrdnav == comp->jrefCrdnav) insert(items, JREFCRDNAV);

	return(items);
};

set<uint> SessPlnr::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {JREFCRDNAV};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class SessPlnr::DpchEngData
 ******************************************************************************/

SessPlnr::DpchEngData::DpchEngData(
			const ubigint jref
			, StatShr* statshr
			, const set<uint>& mask
		) : DpchEngPlnr(VecPlnrVDpch::DPCHENGSESSPLNRDATA, jref) {
	if (find(mask, ALL)) this->mask = {JREF, STATSHR};
	else this->mask = mask;

	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

void SessPlnr::DpchEngData::merge(
			DpchEngPlnr* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
};

void SessPlnr::DpchEngData::writeXML(
			const uint ixPlnrVLocale
			, pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngSessPlnrData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		if (has(STATSHR)) statshr.writeXML(mScr, scr, descr, wr);
	xmlTextWriterEndElement(wr);
};


