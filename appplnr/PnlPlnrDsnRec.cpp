/**
  * \file PnlPlnrDsnRec.cpp
  * app access code for job PnlPlnrDsnRec (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PnlPlnrDsnRec.h"

/******************************************************************************
 class PnlPlnrDsnRec::VecVDo
 ******************************************************************************/

uint PnlPlnrDsnRec::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s.compare("butminimizeclick") == 0) return BUTMINIMIZECLICK;
	else if (s.compare("butregularizeclick") == 0) return BUTREGULARIZECLICK;

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

bool PnlPlnrDsnRec::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfPlnrDsnRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfPlnrDsnRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtRef", TxtRef)) add(TXTREF);
	};

	return basefound;
};

set<uint> PnlPlnrDsnRec::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtRef.compare(comp->TxtRef) == 0) insert(items, TXTREF);

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

PnlPlnrDsnRec::StatApp::StatApp(
			const bool initdonePre
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
		) : Block() {
	this->initdonePre = initdonePre;
	this->initdoneDetail = initdoneDetail;
	this->initdoneViewxy = initdoneViewxy;
	this->initdoneViewz = initdoneViewz;
	this->initdoneMod1NDesign = initdoneMod1NDesign;
	this->initdoneDrv1NDesign = initdoneDrv1NDesign;
	this->initdoneDsn1NDevice = initdoneDsn1NDevice;
	this->initdoneDsn1NStack = initdoneDsn1NStack;
	this->initdoneDsn1NDomaingd = initdoneDsn1NDomaingd;
	this->initdoneDsn1NDomain = initdoneDsn1NDomain;
	this->initdone1NBlock = initdone1NBlock;
	this->initdone1NReticle = initdone1NReticle;
	this->initdoneHk1NLevel = initdoneHk1NLevel;
	this->initdoneHk1NVertex = initdoneHk1NVertex;
	this->initdoneHk1NLineguide = initdoneHk1NLineguide;
	this->initdoneHk1NArcguide = initdoneHk1NArcguide;
	this->initdoneHk1NLayer = initdoneHk1NLayer;
	this->initdoneHk1NStructure = initdoneHk1NStructure;

	mask = {INITDONEPRE, INITDONEDETAIL, INITDONEVIEWXY, INITDONEVIEWZ, INITDONEMOD1NDESIGN, INITDONEDRV1NDESIGN, INITDONEDSN1NDEVICE, INITDONEDSN1NSTACK, INITDONEDSN1NDOMAINGD, INITDONEDSN1NDOMAIN, INITDONE1NBLOCK, INITDONE1NRETICLE, INITDONEHK1NLEVEL, INITDONEHK1NVERTEX, INITDONEHK1NLINEGUIDE, INITDONEHK1NARCGUIDE, INITDONEHK1NLAYER, INITDONEHK1NSTRUCTURE};
};

bool PnlPlnrDsnRec::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppPlnrDsnRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppPlnrDsnRec";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdonePre", initdonePre)) add(INITDONEPRE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneDetail", initdoneDetail)) add(INITDONEDETAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneViewxy", initdoneViewxy)) add(INITDONEVIEWXY);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneViewz", initdoneViewz)) add(INITDONEVIEWZ);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneMod1NDesign", initdoneMod1NDesign)) add(INITDONEMOD1NDESIGN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneDrv1NDesign", initdoneDrv1NDesign)) add(INITDONEDRV1NDESIGN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneDsn1NDevice", initdoneDsn1NDevice)) add(INITDONEDSN1NDEVICE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneDsn1NStack", initdoneDsn1NStack)) add(INITDONEDSN1NSTACK);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneDsn1NDomaingd", initdoneDsn1NDomaingd)) add(INITDONEDSN1NDOMAINGD);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneDsn1NDomain", initdoneDsn1NDomain)) add(INITDONEDSN1NDOMAIN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdone1NBlock", initdone1NBlock)) add(INITDONE1NBLOCK);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdone1NReticle", initdone1NReticle)) add(INITDONE1NRETICLE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneHk1NLevel", initdoneHk1NLevel)) add(INITDONEHK1NLEVEL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneHk1NVertex", initdoneHk1NVertex)) add(INITDONEHK1NVERTEX);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneHk1NLineguide", initdoneHk1NLineguide)) add(INITDONEHK1NLINEGUIDE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneHk1NArcguide", initdoneHk1NArcguide)) add(INITDONEHK1NARCGUIDE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneHk1NLayer", initdoneHk1NLayer)) add(INITDONEHK1NLAYER);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneHk1NStructure", initdoneHk1NStructure)) add(INITDONEHK1NSTRUCTURE);
	};

	return basefound;
};

set<uint> PnlPlnrDsnRec::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (initdonePre == comp->initdonePre) insert(items, INITDONEPRE);
	if (initdoneDetail == comp->initdoneDetail) insert(items, INITDONEDETAIL);
	if (initdoneViewxy == comp->initdoneViewxy) insert(items, INITDONEVIEWXY);
	if (initdoneViewz == comp->initdoneViewz) insert(items, INITDONEVIEWZ);
	if (initdoneMod1NDesign == comp->initdoneMod1NDesign) insert(items, INITDONEMOD1NDESIGN);
	if (initdoneDrv1NDesign == comp->initdoneDrv1NDesign) insert(items, INITDONEDRV1NDESIGN);
	if (initdoneDsn1NDevice == comp->initdoneDsn1NDevice) insert(items, INITDONEDSN1NDEVICE);
	if (initdoneDsn1NStack == comp->initdoneDsn1NStack) insert(items, INITDONEDSN1NSTACK);
	if (initdoneDsn1NDomaingd == comp->initdoneDsn1NDomaingd) insert(items, INITDONEDSN1NDOMAINGD);
	if (initdoneDsn1NDomain == comp->initdoneDsn1NDomain) insert(items, INITDONEDSN1NDOMAIN);
	if (initdone1NBlock == comp->initdone1NBlock) insert(items, INITDONE1NBLOCK);
	if (initdone1NReticle == comp->initdone1NReticle) insert(items, INITDONE1NRETICLE);
	if (initdoneHk1NLevel == comp->initdoneHk1NLevel) insert(items, INITDONEHK1NLEVEL);
	if (initdoneHk1NVertex == comp->initdoneHk1NVertex) insert(items, INITDONEHK1NVERTEX);
	if (initdoneHk1NLineguide == comp->initdoneHk1NLineguide) insert(items, INITDONEHK1NLINEGUIDE);
	if (initdoneHk1NArcguide == comp->initdoneHk1NArcguide) insert(items, INITDONEHK1NARCGUIDE);
	if (initdoneHk1NLayer == comp->initdoneHk1NLayer) insert(items, INITDONEHK1NLAYER);
	if (initdoneHk1NStructure == comp->initdoneHk1NStructure) insert(items, INITDONEHK1NSTRUCTURE);

	return(items);
};

set<uint> PnlPlnrDsnRec::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {INITDONEPRE, INITDONEDETAIL, INITDONEVIEWXY, INITDONEVIEWZ, INITDONEMOD1NDESIGN, INITDONEDRV1NDESIGN, INITDONEDSN1NDEVICE, INITDONEDSN1NSTACK, INITDONEDSN1NDOMAINGD, INITDONEDSN1NDOMAIN, INITDONE1NBLOCK, INITDONE1NRETICLE, INITDONEHK1NLEVEL, INITDONEHK1NVERTEX, INITDONEHK1NLINEGUIDE, INITDONEHK1NARCGUIDE, INITDONEHK1NLAYER, INITDONEHK1NSTRUCTURE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrDsnRec::StatShr
 ******************************************************************************/

PnlPlnrDsnRec::StatShr::StatShr(
			const uint ixPlnrVExpstate
			, const string& scrJrefPre
			, const string& scrJrefDetail
			, const string& scrJrefViewxy
			, const bool pnlviewxyAvail
			, const string& scrJrefViewz
			, const bool pnlviewzAvail
			, const string& scrJrefMod1NDesign
			, const bool pnlmod1ndesignAvail
			, const string& scrJrefDrv1NDesign
			, const string& scrJrefDsn1NDevice
			, const bool pnldsn1ndeviceAvail
			, const string& scrJrefDsn1NStack
			, const bool pnldsn1nstackAvail
			, const string& scrJrefDsn1NDomaingd
			, const string& scrJrefDsn1NDomain
			, const string& scrJref1NBlock
			, const bool pnl1nblockAvail
			, const string& scrJref1NReticle
			, const bool pnl1nreticleAvail
			, const string& scrJrefHk1NLevel
			, const bool pnlhk1nlevelAvail
			, const string& scrJrefHk1NVertex
			, const bool pnlhk1nvertexAvail
			, const string& scrJrefHk1NLineguide
			, const bool pnlhk1nlineguideAvail
			, const string& scrJrefHk1NArcguide
			, const bool pnlhk1narcguideAvail
			, const string& scrJrefHk1NLayer
			, const bool pnlhk1nlayerAvail
			, const string& scrJrefHk1NStructure
			, const bool pnlhk1nstructureAvail
			, const bool ButRegularizeActive
		) : Block() {
	this->ixPlnrVExpstate = ixPlnrVExpstate;
	this->scrJrefPre = scrJrefPre;
	this->scrJrefDetail = scrJrefDetail;
	this->scrJrefViewxy = scrJrefViewxy;
	this->pnlviewxyAvail = pnlviewxyAvail;
	this->scrJrefViewz = scrJrefViewz;
	this->pnlviewzAvail = pnlviewzAvail;
	this->scrJrefMod1NDesign = scrJrefMod1NDesign;
	this->pnlmod1ndesignAvail = pnlmod1ndesignAvail;
	this->scrJrefDrv1NDesign = scrJrefDrv1NDesign;
	this->scrJrefDsn1NDevice = scrJrefDsn1NDevice;
	this->pnldsn1ndeviceAvail = pnldsn1ndeviceAvail;
	this->scrJrefDsn1NStack = scrJrefDsn1NStack;
	this->pnldsn1nstackAvail = pnldsn1nstackAvail;
	this->scrJrefDsn1NDomaingd = scrJrefDsn1NDomaingd;
	this->scrJrefDsn1NDomain = scrJrefDsn1NDomain;
	this->scrJref1NBlock = scrJref1NBlock;
	this->pnl1nblockAvail = pnl1nblockAvail;
	this->scrJref1NReticle = scrJref1NReticle;
	this->pnl1nreticleAvail = pnl1nreticleAvail;
	this->scrJrefHk1NLevel = scrJrefHk1NLevel;
	this->pnlhk1nlevelAvail = pnlhk1nlevelAvail;
	this->scrJrefHk1NVertex = scrJrefHk1NVertex;
	this->pnlhk1nvertexAvail = pnlhk1nvertexAvail;
	this->scrJrefHk1NLineguide = scrJrefHk1NLineguide;
	this->pnlhk1nlineguideAvail = pnlhk1nlineguideAvail;
	this->scrJrefHk1NArcguide = scrJrefHk1NArcguide;
	this->pnlhk1narcguideAvail = pnlhk1narcguideAvail;
	this->scrJrefHk1NLayer = scrJrefHk1NLayer;
	this->pnlhk1nlayerAvail = pnlhk1nlayerAvail;
	this->scrJrefHk1NStructure = scrJrefHk1NStructure;
	this->pnlhk1nstructureAvail = pnlhk1nstructureAvail;
	this->ButRegularizeActive = ButRegularizeActive;

	mask = {IXPLNRVEXPSTATE, SCRJREFPRE, SCRJREFDETAIL, SCRJREFVIEWXY, PNLVIEWXYAVAIL, SCRJREFVIEWZ, PNLVIEWZAVAIL, SCRJREFMOD1NDESIGN, PNLMOD1NDESIGNAVAIL, SCRJREFDRV1NDESIGN, SCRJREFDSN1NDEVICE, PNLDSN1NDEVICEAVAIL, SCRJREFDSN1NSTACK, PNLDSN1NSTACKAVAIL, SCRJREFDSN1NDOMAINGD, SCRJREFDSN1NDOMAIN, SCRJREF1NBLOCK, PNL1NBLOCKAVAIL, SCRJREF1NRETICLE, PNL1NRETICLEAVAIL, SCRJREFHK1NLEVEL, PNLHK1NLEVELAVAIL, SCRJREFHK1NVERTEX, PNLHK1NVERTEXAVAIL, SCRJREFHK1NLINEGUIDE, PNLHK1NLINEGUIDEAVAIL, SCRJREFHK1NARCGUIDE, PNLHK1NARCGUIDEAVAIL, SCRJREFHK1NLAYER, PNLHK1NLAYERAVAIL, SCRJREFHK1NSTRUCTURE, PNLHK1NSTRUCTUREAVAIL, BUTREGULARIZEACTIVE};
};

bool PnlPlnrDsnRec::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxPlnrVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrPlnrDsnRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrPlnrDsnRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxPlnrVExpstate", srefIxPlnrVExpstate)) {
			ixPlnrVExpstate = VecPlnrVExpstate::getIx(srefIxPlnrVExpstate);
			add(IXPLNRVEXPSTATE);
		};
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefPre", scrJrefPre)) add(SCRJREFPRE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDetail", scrJrefDetail)) add(SCRJREFDETAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefViewxy", scrJrefViewxy)) add(SCRJREFVIEWXY);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnlviewxyAvail", pnlviewxyAvail)) add(PNLVIEWXYAVAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefViewz", scrJrefViewz)) add(SCRJREFVIEWZ);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnlviewzAvail", pnlviewzAvail)) add(PNLVIEWZAVAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefMod1NDesign", scrJrefMod1NDesign)) add(SCRJREFMOD1NDESIGN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnlmod1ndesignAvail", pnlmod1ndesignAvail)) add(PNLMOD1NDESIGNAVAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDrv1NDesign", scrJrefDrv1NDesign)) add(SCRJREFDRV1NDESIGN);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDsn1NDevice", scrJrefDsn1NDevice)) add(SCRJREFDSN1NDEVICE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnldsn1ndeviceAvail", pnldsn1ndeviceAvail)) add(PNLDSN1NDEVICEAVAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDsn1NStack", scrJrefDsn1NStack)) add(SCRJREFDSN1NSTACK);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnldsn1nstackAvail", pnldsn1nstackAvail)) add(PNLDSN1NSTACKAVAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDsn1NDomaingd", scrJrefDsn1NDomaingd)) add(SCRJREFDSN1NDOMAINGD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDsn1NDomain", scrJrefDsn1NDomain)) add(SCRJREFDSN1NDOMAIN);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJref1NBlock", scrJref1NBlock)) add(SCRJREF1NBLOCK);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnl1nblockAvail", pnl1nblockAvail)) add(PNL1NBLOCKAVAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJref1NReticle", scrJref1NReticle)) add(SCRJREF1NRETICLE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnl1nreticleAvail", pnl1nreticleAvail)) add(PNL1NRETICLEAVAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefHk1NLevel", scrJrefHk1NLevel)) add(SCRJREFHK1NLEVEL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnlhk1nlevelAvail", pnlhk1nlevelAvail)) add(PNLHK1NLEVELAVAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefHk1NVertex", scrJrefHk1NVertex)) add(SCRJREFHK1NVERTEX);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnlhk1nvertexAvail", pnlhk1nvertexAvail)) add(PNLHK1NVERTEXAVAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefHk1NLineguide", scrJrefHk1NLineguide)) add(SCRJREFHK1NLINEGUIDE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnlhk1nlineguideAvail", pnlhk1nlineguideAvail)) add(PNLHK1NLINEGUIDEAVAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefHk1NArcguide", scrJrefHk1NArcguide)) add(SCRJREFHK1NARCGUIDE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnlhk1narcguideAvail", pnlhk1narcguideAvail)) add(PNLHK1NARCGUIDEAVAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefHk1NLayer", scrJrefHk1NLayer)) add(SCRJREFHK1NLAYER);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnlhk1nlayerAvail", pnlhk1nlayerAvail)) add(PNLHK1NLAYERAVAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefHk1NStructure", scrJrefHk1NStructure)) add(SCRJREFHK1NSTRUCTURE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnlhk1nstructureAvail", pnlhk1nstructureAvail)) add(PNLHK1NSTRUCTUREAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButRegularizeActive", ButRegularizeActive)) add(BUTREGULARIZEACTIVE);
	};

	return basefound;
};

set<uint> PnlPlnrDsnRec::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixPlnrVExpstate == comp->ixPlnrVExpstate) insert(items, IXPLNRVEXPSTATE);
	if (scrJrefPre.compare(comp->scrJrefPre) == 0) insert(items, SCRJREFPRE);
	if (scrJrefDetail.compare(comp->scrJrefDetail) == 0) insert(items, SCRJREFDETAIL);
	if (scrJrefViewxy.compare(comp->scrJrefViewxy) == 0) insert(items, SCRJREFVIEWXY);
	if (pnlviewxyAvail == comp->pnlviewxyAvail) insert(items, PNLVIEWXYAVAIL);
	if (scrJrefViewz.compare(comp->scrJrefViewz) == 0) insert(items, SCRJREFVIEWZ);
	if (pnlviewzAvail == comp->pnlviewzAvail) insert(items, PNLVIEWZAVAIL);
	if (scrJrefMod1NDesign.compare(comp->scrJrefMod1NDesign) == 0) insert(items, SCRJREFMOD1NDESIGN);
	if (pnlmod1ndesignAvail == comp->pnlmod1ndesignAvail) insert(items, PNLMOD1NDESIGNAVAIL);
	if (scrJrefDrv1NDesign.compare(comp->scrJrefDrv1NDesign) == 0) insert(items, SCRJREFDRV1NDESIGN);
	if (scrJrefDsn1NDevice.compare(comp->scrJrefDsn1NDevice) == 0) insert(items, SCRJREFDSN1NDEVICE);
	if (pnldsn1ndeviceAvail == comp->pnldsn1ndeviceAvail) insert(items, PNLDSN1NDEVICEAVAIL);
	if (scrJrefDsn1NStack.compare(comp->scrJrefDsn1NStack) == 0) insert(items, SCRJREFDSN1NSTACK);
	if (pnldsn1nstackAvail == comp->pnldsn1nstackAvail) insert(items, PNLDSN1NSTACKAVAIL);
	if (scrJrefDsn1NDomaingd.compare(comp->scrJrefDsn1NDomaingd) == 0) insert(items, SCRJREFDSN1NDOMAINGD);
	if (scrJrefDsn1NDomain.compare(comp->scrJrefDsn1NDomain) == 0) insert(items, SCRJREFDSN1NDOMAIN);
	if (scrJref1NBlock.compare(comp->scrJref1NBlock) == 0) insert(items, SCRJREF1NBLOCK);
	if (pnl1nblockAvail == comp->pnl1nblockAvail) insert(items, PNL1NBLOCKAVAIL);
	if (scrJref1NReticle.compare(comp->scrJref1NReticle) == 0) insert(items, SCRJREF1NRETICLE);
	if (pnl1nreticleAvail == comp->pnl1nreticleAvail) insert(items, PNL1NRETICLEAVAIL);
	if (scrJrefHk1NLevel.compare(comp->scrJrefHk1NLevel) == 0) insert(items, SCRJREFHK1NLEVEL);
	if (pnlhk1nlevelAvail == comp->pnlhk1nlevelAvail) insert(items, PNLHK1NLEVELAVAIL);
	if (scrJrefHk1NVertex.compare(comp->scrJrefHk1NVertex) == 0) insert(items, SCRJREFHK1NVERTEX);
	if (pnlhk1nvertexAvail == comp->pnlhk1nvertexAvail) insert(items, PNLHK1NVERTEXAVAIL);
	if (scrJrefHk1NLineguide.compare(comp->scrJrefHk1NLineguide) == 0) insert(items, SCRJREFHK1NLINEGUIDE);
	if (pnlhk1nlineguideAvail == comp->pnlhk1nlineguideAvail) insert(items, PNLHK1NLINEGUIDEAVAIL);
	if (scrJrefHk1NArcguide.compare(comp->scrJrefHk1NArcguide) == 0) insert(items, SCRJREFHK1NARCGUIDE);
	if (pnlhk1narcguideAvail == comp->pnlhk1narcguideAvail) insert(items, PNLHK1NARCGUIDEAVAIL);
	if (scrJrefHk1NLayer.compare(comp->scrJrefHk1NLayer) == 0) insert(items, SCRJREFHK1NLAYER);
	if (pnlhk1nlayerAvail == comp->pnlhk1nlayerAvail) insert(items, PNLHK1NLAYERAVAIL);
	if (scrJrefHk1NStructure.compare(comp->scrJrefHk1NStructure) == 0) insert(items, SCRJREFHK1NSTRUCTURE);
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

	diffitems = {IXPLNRVEXPSTATE, SCRJREFPRE, SCRJREFDETAIL, SCRJREFVIEWXY, PNLVIEWXYAVAIL, SCRJREFVIEWZ, PNLVIEWZAVAIL, SCRJREFMOD1NDESIGN, PNLMOD1NDESIGNAVAIL, SCRJREFDRV1NDESIGN, SCRJREFDSN1NDEVICE, PNLDSN1NDEVICEAVAIL, SCRJREFDSN1NSTACK, PNLDSN1NSTACKAVAIL, SCRJREFDSN1NDOMAINGD, SCRJREFDSN1NDOMAIN, SCRJREF1NBLOCK, PNL1NBLOCKAVAIL, SCRJREF1NRETICLE, PNL1NRETICLEAVAIL, SCRJREFHK1NLEVEL, PNLHK1NLEVELAVAIL, SCRJREFHK1NVERTEX, PNLHK1NVERTEXAVAIL, SCRJREFHK1NLINEGUIDE, PNLHK1NLINEGUIDEAVAIL, SCRJREFHK1NARCGUIDE, PNLHK1NARCGUIDEAVAIL, SCRJREFHK1NLAYER, PNLHK1NLAYERAVAIL, SCRJREFHK1NSTRUCTURE, PNLHK1NSTRUCTUREAVAIL, BUTREGULARIZEACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlPlnrDsnRec::Tag
 ******************************************************************************/

PnlPlnrDsnRec::Tag::Tag(
			const string& Cpt
		) : Block() {
	this->Cpt = Cpt;

	mask = {CPT};
};

bool PnlPlnrDsnRec::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagPlnrDsnRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemPlnrDsnRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
	};

	return basefound;
};

/******************************************************************************
 class PnlPlnrDsnRec::DpchAppDo
 ******************************************************************************/

PnlPlnrDsnRec::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRDSNRECDO, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

void PnlPlnrDsnRec::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppPlnrDsnRecDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlPlnrDsnRec::DpchEngData
 ******************************************************************************/

PnlPlnrDsnRec::DpchEngData::DpchEngData() : DpchEngPlnr(VecPlnrVDpch::DPCHENGPLNRDSNRECDATA) {
};

void PnlPlnrDsnRec::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngPlnrDsnRecData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		continf = ContInf();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};

