/**
  * \file PnlPlnrDsnRec_blks.cpp
  * job handler for job PnlPlnrDsnRec (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

/******************************************************************************
 class PnlPlnrDsnRec::VecVDo
 ******************************************************************************/

uint PnlPlnrDsnRec::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butminimizeclick") return BUTMINIMIZECLICK;
	else if (s == "butregularizeclick") return BUTREGULARIZECLICK;

	return(0);
};

string PnlPlnrDsnRec::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");
	else if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");

	return("");
};

/******************************************************************************
 class PnlPlnrDsnRec::ContInf
 ******************************************************************************/

PnlPlnrDsnRec::ContInf::ContInf(
			const string& TxtRef
		) : Block() {
	this->TxtRef = TxtRef;

	mask = {TXTREF};
};

void PnlPlnrDsnRec::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfPlnrDsnRec";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfPlnrDsnRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtRef", TxtRef);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrDsnRec::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtRef == comp->TxtRef) insert(items, TXTREF);

	return(items);
};

set<uint> PnlPlnrDsnRec::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTREF};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrDsnRec::StatApp
 ******************************************************************************/

void PnlPlnrDsnRec::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const bool initdonePre
			, const bool initdoneDetail
			, const bool initdoneViewxy
			, const bool initdoneViewz
			, const bool initdoneMod1NDesign
			, const bool initdoneDrv1NDesign
			, const bool initdoneDsn1NDevice
			, const bool initdoneDsn1NStack
			, const bool initdoneDsn1NDomaingd
			, const bool initdoneDsn1NDomain
			, const bool initdone1NBlock
			, const bool initdone1NReticle
			, const bool initdoneHk1NLevel
			, const bool initdoneHk1NVertex
			, const bool initdoneHk1NLineguide
			, const bool initdoneHk1NArcguide
			, const bool initdoneHk1NLayer
			, const bool initdoneHk1NStructure
		) {
	if (difftag.length() == 0) difftag = "StatAppPlnrDsnRec";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppPlnrDsnRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "initdonePre", initdonePre);
		writeBoolAttr(wr, itemtag, "sref", "initdoneDetail", initdoneDetail);
		writeBoolAttr(wr, itemtag, "sref", "initdoneViewxy", initdoneViewxy);
		writeBoolAttr(wr, itemtag, "sref", "initdoneViewz", initdoneViewz);
		writeBoolAttr(wr, itemtag, "sref", "initdoneMod1NDesign", initdoneMod1NDesign);
		writeBoolAttr(wr, itemtag, "sref", "initdoneDrv1NDesign", initdoneDrv1NDesign);
		writeBoolAttr(wr, itemtag, "sref", "initdoneDsn1NDevice", initdoneDsn1NDevice);
		writeBoolAttr(wr, itemtag, "sref", "initdoneDsn1NStack", initdoneDsn1NStack);
		writeBoolAttr(wr, itemtag, "sref", "initdoneDsn1NDomaingd", initdoneDsn1NDomaingd);
		writeBoolAttr(wr, itemtag, "sref", "initdoneDsn1NDomain", initdoneDsn1NDomain);
		writeBoolAttr(wr, itemtag, "sref", "initdone1NBlock", initdone1NBlock);
		writeBoolAttr(wr, itemtag, "sref", "initdone1NReticle", initdone1NReticle);
		writeBoolAttr(wr, itemtag, "sref", "initdoneHk1NLevel", initdoneHk1NLevel);
		writeBoolAttr(wr, itemtag, "sref", "initdoneHk1NVertex", initdoneHk1NVertex);
		writeBoolAttr(wr, itemtag, "sref", "initdoneHk1NLineguide", initdoneHk1NLineguide);
		writeBoolAttr(wr, itemtag, "sref", "initdoneHk1NArcguide", initdoneHk1NArcguide);
		writeBoolAttr(wr, itemtag, "sref", "initdoneHk1NLayer", initdoneHk1NLayer);
		writeBoolAttr(wr, itemtag, "sref", "initdoneHk1NStructure", initdoneHk1NStructure);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrDsnRec::StatShr
 ******************************************************************************/

PnlPlnrDsnRec::StatShr::StatShr(
			const uint ixPlnrVExpstate
			, const ubigint jrefPre
			, const ubigint jrefDetail
			, const ubigint jrefViewxy
			, const bool pnlviewxyAvail
			, const ubigint jrefViewz
			, const bool pnlviewzAvail
			, const ubigint jrefMod1NDesign
			, const bool pnlmod1ndesignAvail
			, const ubigint jrefDrv1NDesign
			, const ubigint jrefDsn1NDevice
			, const bool pnldsn1ndeviceAvail
			, const ubigint jrefDsn1NStack
			, const bool pnldsn1nstackAvail
			, const ubigint jrefDsn1NDomaingd
			, const ubigint jrefDsn1NDomain
			, const ubigint jref1NBlock
			, const bool pnl1nblockAvail
			, const ubigint jref1NReticle
			, const bool pnl1nreticleAvail
			, const ubigint jrefHk1NLevel
			, const bool pnlhk1nlevelAvail
			, const ubigint jrefHk1NVertex
			, const bool pnlhk1nvertexAvail
			, const ubigint jrefHk1NLineguide
			, const bool pnlhk1nlineguideAvail
			, const ubigint jrefHk1NArcguide
			, const bool pnlhk1narcguideAvail
			, const ubigint jrefHk1NLayer
			, const bool pnlhk1nlayerAvail
			, const ubigint jrefHk1NStructure
			, const bool pnlhk1nstructureAvail
			, const bool ButRegularizeActive
		) : Block() {
	this->ixPlnrVExpstate = ixPlnrVExpstate;
	this->jrefPre = jrefPre;
	this->jrefDetail = jrefDetail;
	this->jrefViewxy = jrefViewxy;
	this->pnlviewxyAvail = pnlviewxyAvail;
	this->jrefViewz = jrefViewz;
	this->pnlviewzAvail = pnlviewzAvail;
	this->jrefMod1NDesign = jrefMod1NDesign;
	this->pnlmod1ndesignAvail = pnlmod1ndesignAvail;
	this->jrefDrv1NDesign = jrefDrv1NDesign;
	this->jrefDsn1NDevice = jrefDsn1NDevice;
	this->pnldsn1ndeviceAvail = pnldsn1ndeviceAvail;
	this->jrefDsn1NStack = jrefDsn1NStack;
	this->pnldsn1nstackAvail = pnldsn1nstackAvail;
	this->jrefDsn1NDomaingd = jrefDsn1NDomaingd;
	this->jrefDsn1NDomain = jrefDsn1NDomain;
	this->jref1NBlock = jref1NBlock;
	this->pnl1nblockAvail = pnl1nblockAvail;
	this->jref1NReticle = jref1NReticle;
	this->pnl1nreticleAvail = pnl1nreticleAvail;
	this->jrefHk1NLevel = jrefHk1NLevel;
	this->pnlhk1nlevelAvail = pnlhk1nlevelAvail;
	this->jrefHk1NVertex = jrefHk1NVertex;
	this->pnlhk1nvertexAvail = pnlhk1nvertexAvail;
	this->jrefHk1NLineguide = jrefHk1NLineguide;
	this->pnlhk1nlineguideAvail = pnlhk1nlineguideAvail;
	this->jrefHk1NArcguide = jrefHk1NArcguide;
	this->pnlhk1narcguideAvail = pnlhk1narcguideAvail;
	this->jrefHk1NLayer = jrefHk1NLayer;
	this->pnlhk1nlayerAvail = pnlhk1nlayerAvail;
	this->jrefHk1NStructure = jrefHk1NStructure;
	this->pnlhk1nstructureAvail = pnlhk1nstructureAvail;
	this->ButRegularizeActive = ButRegularizeActive;

	mask = {IXPLNRVEXPSTATE, JREFPRE, JREFDETAIL, JREFVIEWXY, PNLVIEWXYAVAIL, JREFVIEWZ, PNLVIEWZAVAIL, JREFMOD1NDESIGN, PNLMOD1NDESIGNAVAIL, JREFDRV1NDESIGN, JREFDSN1NDEVICE, PNLDSN1NDEVICEAVAIL, JREFDSN1NSTACK, PNLDSN1NSTACKAVAIL, JREFDSN1NDOMAINGD, JREFDSN1NDOMAIN, JREF1NBLOCK, PNL1NBLOCKAVAIL, JREF1NRETICLE, PNL1NRETICLEAVAIL, JREFHK1NLEVEL, PNLHK1NLEVELAVAIL, JREFHK1NVERTEX, PNLHK1NVERTEXAVAIL, JREFHK1NLINEGUIDE, PNLHK1NLINEGUIDEAVAIL, JREFHK1NARCGUIDE, PNLHK1NARCGUIDEAVAIL, JREFHK1NLAYER, PNLHK1NLAYERAVAIL, JREFHK1NSTRUCTURE, PNLHK1NSTRUCTUREAVAIL, BUTREGULARIZEACTIVE};
};

void PnlPlnrDsnRec::StatShr::writeXML(
			pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrPlnrDsnRec";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrPlnrDsnRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxPlnrVExpstate", VecPlnrVExpstate::getSref(ixPlnrVExpstate));
		writeStringAttr(wr, itemtag, "sref", "scrJrefPre", Scr::scramble(mScr, scr, descr, jrefPre));
		writeStringAttr(wr, itemtag, "sref", "scrJrefDetail", Scr::scramble(mScr, scr, descr, jrefDetail));
		writeStringAttr(wr, itemtag, "sref", "scrJrefViewxy", Scr::scramble(mScr, scr, descr, jrefViewxy));
		writeBoolAttr(wr, itemtag, "sref", "pnlviewxyAvail", pnlviewxyAvail);
		writeStringAttr(wr, itemtag, "sref", "scrJrefViewz", Scr::scramble(mScr, scr, descr, jrefViewz));
		writeBoolAttr(wr, itemtag, "sref", "pnlviewzAvail", pnlviewzAvail);
		writeStringAttr(wr, itemtag, "sref", "scrJrefMod1NDesign", Scr::scramble(mScr, scr, descr, jrefMod1NDesign));
		writeBoolAttr(wr, itemtag, "sref", "pnlmod1ndesignAvail", pnlmod1ndesignAvail);
		writeStringAttr(wr, itemtag, "sref", "scrJrefDrv1NDesign", Scr::scramble(mScr, scr, descr, jrefDrv1NDesign));
		writeStringAttr(wr, itemtag, "sref", "scrJrefDsn1NDevice", Scr::scramble(mScr, scr, descr, jrefDsn1NDevice));
		writeBoolAttr(wr, itemtag, "sref", "pnldsn1ndeviceAvail", pnldsn1ndeviceAvail);
		writeStringAttr(wr, itemtag, "sref", "scrJrefDsn1NStack", Scr::scramble(mScr, scr, descr, jrefDsn1NStack));
		writeBoolAttr(wr, itemtag, "sref", "pnldsn1nstackAvail", pnldsn1nstackAvail);
		writeStringAttr(wr, itemtag, "sref", "scrJrefDsn1NDomaingd", Scr::scramble(mScr, scr, descr, jrefDsn1NDomaingd));
		writeStringAttr(wr, itemtag, "sref", "scrJrefDsn1NDomain", Scr::scramble(mScr, scr, descr, jrefDsn1NDomain));
		writeStringAttr(wr, itemtag, "sref", "scrJref1NBlock", Scr::scramble(mScr, scr, descr, jref1NBlock));
		writeBoolAttr(wr, itemtag, "sref", "pnl1nblockAvail", pnl1nblockAvail);
		writeStringAttr(wr, itemtag, "sref", "scrJref1NReticle", Scr::scramble(mScr, scr, descr, jref1NReticle));
		writeBoolAttr(wr, itemtag, "sref", "pnl1nreticleAvail", pnl1nreticleAvail);
		writeStringAttr(wr, itemtag, "sref", "scrJrefHk1NLevel", Scr::scramble(mScr, scr, descr, jrefHk1NLevel));
		writeBoolAttr(wr, itemtag, "sref", "pnlhk1nlevelAvail", pnlhk1nlevelAvail);
		writeStringAttr(wr, itemtag, "sref", "scrJrefHk1NVertex", Scr::scramble(mScr, scr, descr, jrefHk1NVertex));
		writeBoolAttr(wr, itemtag, "sref", "pnlhk1nvertexAvail", pnlhk1nvertexAvail);
		writeStringAttr(wr, itemtag, "sref", "scrJrefHk1NLineguide", Scr::scramble(mScr, scr, descr, jrefHk1NLineguide));
		writeBoolAttr(wr, itemtag, "sref", "pnlhk1nlineguideAvail", pnlhk1nlineguideAvail);
		writeStringAttr(wr, itemtag, "sref", "scrJrefHk1NArcguide", Scr::scramble(mScr, scr, descr, jrefHk1NArcguide));
		writeBoolAttr(wr, itemtag, "sref", "pnlhk1narcguideAvail", pnlhk1narcguideAvail);
		writeStringAttr(wr, itemtag, "sref", "scrJrefHk1NLayer", Scr::scramble(mScr, scr, descr, jrefHk1NLayer));
		writeBoolAttr(wr, itemtag, "sref", "pnlhk1nlayerAvail", pnlhk1nlayerAvail);
		writeStringAttr(wr, itemtag, "sref", "scrJrefHk1NStructure", Scr::scramble(mScr, scr, descr, jrefHk1NStructure));
		writeBoolAttr(wr, itemtag, "sref", "pnlhk1nstructureAvail", pnlhk1nstructureAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButRegularizeActive", ButRegularizeActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlPlnrDsnRec::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixPlnrVExpstate == comp->ixPlnrVExpstate) insert(items, IXPLNRVEXPSTATE);
	if (jrefPre == comp->jrefPre) insert(items, JREFPRE);
	if (jrefDetail == comp->jrefDetail) insert(items, JREFDETAIL);
	if (jrefViewxy == comp->jrefViewxy) insert(items, JREFVIEWXY);
	if (pnlviewxyAvail == comp->pnlviewxyAvail) insert(items, PNLVIEWXYAVAIL);
	if (jrefViewz == comp->jrefViewz) insert(items, JREFVIEWZ);
	if (pnlviewzAvail == comp->pnlviewzAvail) insert(items, PNLVIEWZAVAIL);
	if (jrefMod1NDesign == comp->jrefMod1NDesign) insert(items, JREFMOD1NDESIGN);
	if (pnlmod1ndesignAvail == comp->pnlmod1ndesignAvail) insert(items, PNLMOD1NDESIGNAVAIL);
	if (jrefDrv1NDesign == comp->jrefDrv1NDesign) insert(items, JREFDRV1NDESIGN);
	if (jrefDsn1NDevice == comp->jrefDsn1NDevice) insert(items, JREFDSN1NDEVICE);
	if (pnldsn1ndeviceAvail == comp->pnldsn1ndeviceAvail) insert(items, PNLDSN1NDEVICEAVAIL);
	if (jrefDsn1NStack == comp->jrefDsn1NStack) insert(items, JREFDSN1NSTACK);
	if (pnldsn1nstackAvail == comp->pnldsn1nstackAvail) insert(items, PNLDSN1NSTACKAVAIL);
	if (jrefDsn1NDomaingd == comp->jrefDsn1NDomaingd) insert(items, JREFDSN1NDOMAINGD);
	if (jrefDsn1NDomain == comp->jrefDsn1NDomain) insert(items, JREFDSN1NDOMAIN);
	if (jref1NBlock == comp->jref1NBlock) insert(items, JREF1NBLOCK);
	if (pnl1nblockAvail == comp->pnl1nblockAvail) insert(items, PNL1NBLOCKAVAIL);
	if (jref1NReticle == comp->jref1NReticle) insert(items, JREF1NRETICLE);
	if (pnl1nreticleAvail == comp->pnl1nreticleAvail) insert(items, PNL1NRETICLEAVAIL);
	if (jrefHk1NLevel == comp->jrefHk1NLevel) insert(items, JREFHK1NLEVEL);
	if (pnlhk1nlevelAvail == comp->pnlhk1nlevelAvail) insert(items, PNLHK1NLEVELAVAIL);
	if (jrefHk1NVertex == comp->jrefHk1NVertex) insert(items, JREFHK1NVERTEX);
	if (pnlhk1nvertexAvail == comp->pnlhk1nvertexAvail) insert(items, PNLHK1NVERTEXAVAIL);
	if (jrefHk1NLineguide == comp->jrefHk1NLineguide) insert(items, JREFHK1NLINEGUIDE);
	if (pnlhk1nlineguideAvail == comp->pnlhk1nlineguideAvail) insert(items, PNLHK1NLINEGUIDEAVAIL);
	if (jrefHk1NArcguide == comp->jrefHk1NArcguide) insert(items, JREFHK1NARCGUIDE);
	if (pnlhk1narcguideAvail == comp->pnlhk1narcguideAvail) insert(items, PNLHK1NARCGUIDEAVAIL);
	if (jrefHk1NLayer == comp->jrefHk1NLayer) insert(items, JREFHK1NLAYER);
	if (pnlhk1nlayerAvail == comp->pnlhk1nlayerAvail) insert(items, PNLHK1NLAYERAVAIL);
	if (jrefHk1NStructure == comp->jrefHk1NStructure) insert(items, JREFHK1NSTRUCTURE);
	if (pnlhk1nstructureAvail == comp->pnlhk1nstructureAvail) insert(items, PNLHK1NSTRUCTUREAVAIL);
	if (ButRegularizeActive == comp->ButRegularizeActive) insert(items, BUTREGULARIZEACTIVE);

	return(items);
};

set<uint> PnlPlnrDsnRec::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXPLNRVEXPSTATE, JREFPRE, JREFDETAIL, JREFVIEWXY, PNLVIEWXYAVAIL, JREFVIEWZ, PNLVIEWZAVAIL, JREFMOD1NDESIGN, PNLMOD1NDESIGNAVAIL, JREFDRV1NDESIGN, JREFDSN1NDEVICE, PNLDSN1NDEVICEAVAIL, JREFDSN1NSTACK, PNLDSN1NSTACKAVAIL, JREFDSN1NDOMAINGD, JREFDSN1NDOMAIN, JREF1NBLOCK, PNL1NBLOCKAVAIL, JREF1NRETICLE, PNL1NRETICLEAVAIL, JREFHK1NLEVEL, PNLHK1NLEVELAVAIL, JREFHK1NVERTEX, PNLHK1NVERTEXAVAIL, JREFHK1NLINEGUIDE, PNLHK1NLINEGUIDEAVAIL, JREFHK1NARCGUIDE, PNLHK1NARCGUIDEAVAIL, JREFHK1NLAYER, PNLHK1NLAYERAVAIL, JREFHK1NSTRUCTURE, PNLHK1NSTRUCTUREAVAIL, BUTREGULARIZEACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrDsnRec::Tag
 ******************************************************************************/

void PnlPlnrDsnRec::Tag::writeXML(
			const uint ixPlnrVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagPlnrDsnRec";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemPlnrDsnRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Design");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrDsnRec::DpchAppDo
 ******************************************************************************/

PnlPlnrDsnRec::DpchAppDo::DpchAppDo() : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRDSNRECDO) {
	ixVDo = 0;
};

void PnlPlnrDsnRec::DpchAppDo::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppPlnrDsnRecDo");
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
 class PnlPlnrDsnRec::DpchEngData
 ******************************************************************************/

PnlPlnrDsnRec::DpchEngData::DpchEngData(
			const ubigint jref
			, ContInf* continf
			, StatShr* statshr
			, const set<uint>& mask
		) : DpchEngPlnr(VecPlnrVDpch::DPCHENGPLNRDSNRECDATA, jref) {
	if (find(mask, ALL)) this->mask = {JREF, CONTINF, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

void PnlPlnrDsnRec::DpchEngData::merge(
			DpchEngPlnr* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlPlnrDsnRec::DpchEngData::writeXML(
			const uint ixPlnrVLocale
			, pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngPlnrDsnRecData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(mScr, scr, descr, wr);
		if (has(TAG)) Tag::writeXML(ixPlnrVLocale, wr);
	xmlTextWriterEndElement(wr);
};


