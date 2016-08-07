/**
  * \file AppPlnr.cpp
  * Plnr app access library global functionality (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "AppPlnr.h"

/******************************************************************************
 class StgPlnrapp
 ******************************************************************************/

StgPlnrapp::StgPlnrapp(
			const string ip
			, const uint port
			, const string username
			, const string password
		) : Block() {
	this->ip = ip;
	this->port = port;
	this->username = username;
	this->password = password;

	mask = {IP, PORT, USERNAME, PASSWORD};
};

bool StgPlnrapp::all(
			const set<uint>& items
		) {
	if (!find(items, IP)) return false;
	if (!find(items, PORT)) return false;
	if (!find(items, USERNAME)) return false;
	if (!find(items, PASSWORD)) return false;

	return true;
};

bool StgPlnrapp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgPlnrapp");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemPlnrapp";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ip", ip)) add(IP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "port", port)) add(PORT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "username", username)) add(USERNAME);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "password", password)) add(PASSWORD);
	};

	return basefound;
};

void StgPlnrapp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgPlnrapp";

	string itemtag;
	if (shorttags)
		itemtag = "Si";
	else
		itemtag = "StgitemPlnrapp";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "ip", ip);
		writeUintAttr(wr, itemtag, "sref", "port", port);
		writeStringAttr(wr, itemtag, "sref", "username", username);
		writeStringAttr(wr, itemtag, "sref", "password", password);
	xmlTextWriterEndElement(wr);
};

set<uint> StgPlnrapp::compare(
			const StgPlnrapp* comp
		) {
	set<uint> items;

	if (ip.compare(comp->ip) == 0) insert(items, IP);
	if (port == comp->port) insert(items, PORT);
	if (username.compare(comp->username) == 0) insert(items, USERNAME);
	if (password.compare(comp->password) == 0) insert(items, PASSWORD);

	return items;
};

/******************************************************************************
 namespace AppPlnr
 ******************************************************************************/

uint AppPlnr::readDpchEng(
			char* buf
			, unsigned long buflen
			, DpchEngPlnr** dpcheng
		) {
	xmlDoc* doc = NULL;
	xmlXPathContext* docctx = NULL;

	parseBuffer(buf, buflen, &doc, &docctx);

	uint ixPlnrVDpch = VecPlnrVDpch::getIx(extractRoot(doc));

	if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGDLGPLNRCLCEXPRTXDATA) {
		*dpcheng = new DlgPlnrClcExprtx::DpchEngData();
		((DlgPlnrClcExprtx::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGDLGPLNRCLCGENRPVDATA) {
		*dpcheng = new DlgPlnrClcGenrpv::DpchEngData();
		((DlgPlnrClcGenrpv::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGDLGPLNRCLCUSECASEDATA) {
		*dpcheng = new DlgPlnrClcUsecase::DpchEngData();
		((DlgPlnrClcUsecase::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGDLGPLNRDSNGENPLTDATA) {
		*dpcheng = new DlgPlnrDsnGenplt::DpchEngData();
		((DlgPlnrDsnGenplt::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGDLGPLNRFILDLDCPYDATA) {
		*dpcheng = new DlgPlnrFilDldcpy::DpchEngData();
		((DlgPlnrFilDldcpy::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGDLGPLNRNAVLOAINIDATA) {
		*dpcheng = new DlgPlnrNavLoaini::DpchEngData();
		((DlgPlnrNavLoaini::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGDLGPLNRTPOUSECASEDATA) {
		*dpcheng = new DlgPlnrTpoUsecase::DpchEngData();
		((DlgPlnrTpoUsecase::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRACK) {
		*dpcheng = new DpchEngPlnrAck();
		((DpchEngPlnrAck*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRALERT) {
		*dpcheng = new DpchEngPlnrAlert();
		((DpchEngPlnrAlert*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRARIAMARRAYENVDATA) {
		*dpcheng = new PnlPlnrAriAMArrayEnv::DpchEngData();
		((PnlPlnrAriAMArrayEnv::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRARIDATA) {
		*dpcheng = new CrdPlnrAri::DpchEngData();
		((CrdPlnrAri::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRARIDETAILDATA) {
		*dpcheng = new PnlPlnrAriDetail::DpchEngData();
		((PnlPlnrAriDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRARIHEADBARDATA) {
		*dpcheng = new PnlPlnrAriHeadbar::DpchEngData();
		((PnlPlnrAriHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRARILISTDATA) {
		*dpcheng = new PnlPlnrAriList::DpchEngData();
		((PnlPlnrAriList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRARIRECDATA) {
		*dpcheng = new PnlPlnrAriRec::DpchEngData();
		((PnlPlnrAriRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRARR1NARRAYITEMDATA) {
		*dpcheng = new PnlPlnrArr1NArrayitem::DpchEngData();
		((PnlPlnrArr1NArrayitem::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRARRAENVDATA) {
		*dpcheng = new PnlPlnrArrAEnv::DpchEngData();
		((PnlPlnrArrAEnv::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRARRDATA) {
		*dpcheng = new CrdPlnrArr::DpchEngData();
		((CrdPlnrArr::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRARRDETAILDATA) {
		*dpcheng = new PnlPlnrArrDetail::DpchEngData();
		((PnlPlnrArrDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRARRHEADBARDATA) {
		*dpcheng = new PnlPlnrArrHeadbar::DpchEngData();
		((PnlPlnrArrHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRARRHK1NRETICLEDATA) {
		*dpcheng = new PnlPlnrArrHk1NReticle::DpchEngData();
		((PnlPlnrArrHk1NReticle::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRARRKENVKEYDATA) {
		*dpcheng = new PnlPlnrArrKEnvKey::DpchEngData();
		((PnlPlnrArrKEnvKey::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRARRLISTDATA) {
		*dpcheng = new PnlPlnrArrList::DpchEngData();
		((PnlPlnrArrList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRARRRECDATA) {
		*dpcheng = new PnlPlnrArrRec::DpchEngData();
		((PnlPlnrArrRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRCLC1NMATERIALDATA) {
		*dpcheng = new PnlPlnrClc1NMaterial::DpchEngData();
		((PnlPlnrClc1NMaterial::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRCLCAENVDATA) {
		*dpcheng = new PnlPlnrClcAEnv::DpchEngData();
		((PnlPlnrClcAEnv::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRCLCAPARDATA) {
		*dpcheng = new PnlPlnrClcAPar::DpchEngData();
		((PnlPlnrClcAPar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRCLCCAL1NCALCITEMDATA) {
		*dpcheng = new PnlPlnrClcCal1NCalcitem::DpchEngData();
		((PnlPlnrClcCal1NCalcitem::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRCLCDATA) {
		*dpcheng = new CrdPlnrClc::DpchEngData();
		((CrdPlnrClc::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRCLCDETAILDATA) {
		*dpcheng = new PnlPlnrClcDetail::DpchEngData();
		((PnlPlnrClcDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRCLCHEADBARDATA) {
		*dpcheng = new PnlPlnrClcHeadbar::DpchEngData();
		((PnlPlnrClcHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRCLCLISTDATA) {
		*dpcheng = new PnlPlnrClcList::DpchEngData();
		((PnlPlnrClcList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRCLCMNDOMAINDATA) {
		*dpcheng = new PnlPlnrClcMNDomain::DpchEngData();
		((PnlPlnrClcMNDomain::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRCLCMNFILEDATA) {
		*dpcheng = new PnlPlnrClcMNFile::DpchEngData();
		((PnlPlnrClcMNFile::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRCLCPREDATA) {
		*dpcheng = new PnlPlnrClcPre::DpchEngData();
		((PnlPlnrClcPre::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRCLCRECDATA) {
		*dpcheng = new PnlPlnrClcRec::DpchEngData();
		((PnlPlnrClcRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRCLCREF1NFILEDATA) {
		*dpcheng = new PnlPlnrClcRef1NFile::DpchEngData();
		((PnlPlnrClcRef1NFile::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRCLCSUP1NCALCDATA) {
		*dpcheng = new PnlPlnrClcSup1NCalc::DpchEngData();
		((PnlPlnrClcSup1NCalc::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRCLCVIEWDATA) {
		*dpcheng = new PnlPlnrClcView::DpchEngData();
		((PnlPlnrClcView::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRCLIAAMCALCENVDATA) {
		*dpcheng = new PnlPlnrCliAAMCalcEnv::DpchEngData();
		((PnlPlnrCliAAMCalcEnv::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRCLIAAMCALCPARDATA) {
		*dpcheng = new PnlPlnrCliAAMCalcPar::DpchEngData();
		((PnlPlnrCliAAMCalcPar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRCLIDATA) {
		*dpcheng = new CrdPlnrCli::DpchEngData();
		((CrdPlnrCli::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRCLIDETAILDATA) {
		*dpcheng = new PnlPlnrCliDetail::DpchEngData();
		((PnlPlnrCliDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRCLIHEADBARDATA) {
		*dpcheng = new PnlPlnrCliHeadbar::DpchEngData();
		((PnlPlnrCliHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRCLILISTDATA) {
		*dpcheng = new PnlPlnrCliList::DpchEngData();
		((PnlPlnrCliList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRCLIRECDATA) {
		*dpcheng = new PnlPlnrCliRec::DpchEngData();
		((PnlPlnrCliRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRCLIREF1NFILEDATA) {
		*dpcheng = new PnlPlnrCliRef1NFile::DpchEngData();
		((PnlPlnrCliRef1NFile::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRCONFIRM) {
		*dpcheng = new DpchEngPlnrConfirm();
		((DpchEngPlnrConfirm*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRCTPAENVDATA) {
		*dpcheng = new PnlPlnrCtpAEnv::DpchEngData();
		((PnlPlnrCtpAEnv::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRCTPAPARDATA) {
		*dpcheng = new PnlPlnrCtpAPar::DpchEngData();
		((PnlPlnrCtpAPar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRCTPDATA) {
		*dpcheng = new CrdPlnrCtp::DpchEngData();
		((CrdPlnrCtp::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRCTPDETAILDATA) {
		*dpcheng = new PnlPlnrCtpDetail::DpchEngData();
		((PnlPlnrCtpDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRCTPHEADBARDATA) {
		*dpcheng = new PnlPlnrCtpHeadbar::DpchEngData();
		((PnlPlnrCtpHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRCTPKCALCDOMPRPDATA) {
		*dpcheng = new PnlPlnrCtpKCalcdomprp::DpchEngData();
		((PnlPlnrCtpKCalcdomprp::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRCTPKCALCVARDATA) {
		*dpcheng = new PnlPlnrCtpKCalcvar::DpchEngData();
		((PnlPlnrCtpKCalcvar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRCTPKENVKEYDATA) {
		*dpcheng = new PnlPlnrCtpKEnvKey::DpchEngData();
		((PnlPlnrCtpKEnvKey::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRCTPKPARCATDATA) {
		*dpcheng = new PnlPlnrCtpKParCat::DpchEngData();
		((PnlPlnrCtpKParCat::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRCTPKPARPROPDATA) {
		*dpcheng = new PnlPlnrCtpKParProp::DpchEngData();
		((PnlPlnrCtpKParProp::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRCTPLISTDATA) {
		*dpcheng = new PnlPlnrCtpList::DpchEngData();
		((PnlPlnrCtpList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRCTPRECDATA) {
		*dpcheng = new PnlPlnrCtpRec::DpchEngData();
		((PnlPlnrCtpRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRCTPREF1NFILEDATA) {
		*dpcheng = new PnlPlnrCtpRef1NFile::DpchEngData();
		((PnlPlnrCtpRef1NFile::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRCTPSUP1NCALCDATA) {
		*dpcheng = new PnlPlnrCtpSup1NCalc::DpchEngData();
		((PnlPlnrCtpSup1NCalc::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRCTPTPL1NCALCDATA) {
		*dpcheng = new PnlPlnrCtpTpl1NCalc::DpchEngData();
		((PnlPlnrCtpTpl1NCalc::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRDGDDATA) {
		*dpcheng = new CrdPlnrDgd::DpchEngData();
		((CrdPlnrDgd::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRDGDDETAILDATA) {
		*dpcheng = new PnlPlnrDgdDetail::DpchEngData();
		((PnlPlnrDgdDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRDGDHEADBARDATA) {
		*dpcheng = new PnlPlnrDgdHeadbar::DpchEngData();
		((PnlPlnrDgdHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRDGDLISTDATA) {
		*dpcheng = new PnlPlnrDgdList::DpchEngData();
		((PnlPlnrDgdList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRDGDRECDATA) {
		*dpcheng = new PnlPlnrDgdRec::DpchEngData();
		((PnlPlnrDgdRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRDOMDATA) {
		*dpcheng = new CrdPlnrDom::DpchEngData();
		((CrdPlnrDom::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRDOMDETAILDATA) {
		*dpcheng = new PnlPlnrDomDetail::DpchEngData();
		((PnlPlnrDomDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRDOMHEADBARDATA) {
		*dpcheng = new PnlPlnrDomHeadbar::DpchEngData();
		((PnlPlnrDomHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRDOMLISTDATA) {
		*dpcheng = new PnlPlnrDomList::DpchEngData();
		((PnlPlnrDomList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRDOMMNCALCDATA) {
		*dpcheng = new PnlPlnrDomMNCalc::DpchEngData();
		((PnlPlnrDomMNCalc::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRDOMRECDATA) {
		*dpcheng = new PnlPlnrDomRec::DpchEngData();
		((PnlPlnrDomRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRDSN1NBLOCKDATA) {
		*dpcheng = new PnlPlnrDsn1NBlock::DpchEngData();
		((PnlPlnrDsn1NBlock::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRDSN1NRETICLEDATA) {
		*dpcheng = new PnlPlnrDsn1NReticle::DpchEngData();
		((PnlPlnrDsn1NReticle::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRDSNDATA) {
		*dpcheng = new CrdPlnrDsn::DpchEngData();
		((CrdPlnrDsn::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRDSNDETAILDATA) {
		*dpcheng = new PnlPlnrDsnDetail::DpchEngData();
		((PnlPlnrDsnDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRDSNDRV1NDESIGNDATA) {
		*dpcheng = new PnlPlnrDsnDrv1NDesign::DpchEngData();
		((PnlPlnrDsnDrv1NDesign::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRDSNDSN1NDEVICEDATA) {
		*dpcheng = new PnlPlnrDsnDsn1NDevice::DpchEngData();
		((PnlPlnrDsnDsn1NDevice::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRDSNDSN1NDOMAINDATA) {
		*dpcheng = new PnlPlnrDsnDsn1NDomain::DpchEngData();
		((PnlPlnrDsnDsn1NDomain::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRDSNDSN1NDOMAINGDDATA) {
		*dpcheng = new PnlPlnrDsnDsn1NDomaingd::DpchEngData();
		((PnlPlnrDsnDsn1NDomaingd::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRDSNDSN1NSTACKDATA) {
		*dpcheng = new PnlPlnrDsnDsn1NStack::DpchEngData();
		((PnlPlnrDsnDsn1NStack::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRDSNHEADBARDATA) {
		*dpcheng = new PnlPlnrDsnHeadbar::DpchEngData();
		((PnlPlnrDsnHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRDSNHK1NARCGUIDEDATA) {
		*dpcheng = new PnlPlnrDsnHk1NArcguide::DpchEngData();
		((PnlPlnrDsnHk1NArcguide::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRDSNHK1NLAYERDATA) {
		*dpcheng = new PnlPlnrDsnHk1NLayer::DpchEngData();
		((PnlPlnrDsnHk1NLayer::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRDSNHK1NLEVELDATA) {
		*dpcheng = new PnlPlnrDsnHk1NLevel::DpchEngData();
		((PnlPlnrDsnHk1NLevel::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRDSNHK1NLINEGUIDEDATA) {
		*dpcheng = new PnlPlnrDsnHk1NLineguide::DpchEngData();
		((PnlPlnrDsnHk1NLineguide::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRDSNHK1NSTRUCTUREDATA) {
		*dpcheng = new PnlPlnrDsnHk1NStructure::DpchEngData();
		((PnlPlnrDsnHk1NStructure::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRDSNHK1NVERTEXDATA) {
		*dpcheng = new PnlPlnrDsnHk1NVertex::DpchEngData();
		((PnlPlnrDsnHk1NVertex::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRDSNLISTDATA) {
		*dpcheng = new PnlPlnrDsnList::DpchEngData();
		((PnlPlnrDsnList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRDSNMOD1NDESIGNDATA) {
		*dpcheng = new PnlPlnrDsnMod1NDesign::DpchEngData();
		((PnlPlnrDsnMod1NDesign::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRDSNPREDATA) {
		*dpcheng = new PnlPlnrDsnPre::DpchEngData();
		((PnlPlnrDsnPre::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRDSNRECDATA) {
		*dpcheng = new PnlPlnrDsnRec::DpchEngData();
		((PnlPlnrDsnRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRDSNVIEWXYDATA) {
		*dpcheng = new PnlPlnrDsnViewxy::DpchEngData();
		((PnlPlnrDsnViewxy::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRDSNVIEWZDATA) {
		*dpcheng = new PnlPlnrDsnViewz::DpchEngData();
		((PnlPlnrDsnViewz::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRDTPAPARDATA) {
		*dpcheng = new PnlPlnrDtpAPar::DpchEngData();
		((PnlPlnrDtpAPar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRDTPDATA) {
		*dpcheng = new CrdPlnrDtp::DpchEngData();
		((CrdPlnrDtp::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRDTPDETAILDATA) {
		*dpcheng = new PnlPlnrDtpDetail::DpchEngData();
		((PnlPlnrDtpDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRDTPHEADBARDATA) {
		*dpcheng = new PnlPlnrDtpHeadbar::DpchEngData();
		((PnlPlnrDtpHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRDTPHK1NSTRUCTUREDATA) {
		*dpcheng = new PnlPlnrDtpHk1NStructure::DpchEngData();
		((PnlPlnrDtpHk1NStructure::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRDTPKPARKEYDATA) {
		*dpcheng = new PnlPlnrDtpKParKey::DpchEngData();
		((PnlPlnrDtpKParKey::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRDTPLISTDATA) {
		*dpcheng = new PnlPlnrDtpList::DpchEngData();
		((PnlPlnrDtpList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRDTPPREDATA) {
		*dpcheng = new PnlPlnrDtpPre::DpchEngData();
		((PnlPlnrDtpPre::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRDTPRECDATA) {
		*dpcheng = new PnlPlnrDtpRec::DpchEngData();
		((PnlPlnrDtpRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRDTPSUP1NDEVICEDATA) {
		*dpcheng = new PnlPlnrDtpSup1NDevice::DpchEngData();
		((PnlPlnrDtpSup1NDevice::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRDTPTPL1NDEVICEDATA) {
		*dpcheng = new PnlPlnrDtpTpl1NDevice::DpchEngData();
		((PnlPlnrDtpTpl1NDevice::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRDTPVIEWDATA) {
		*dpcheng = new PnlPlnrDtpView::DpchEngData();
		((PnlPlnrDtpView::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRDVCAPARDATA) {
		*dpcheng = new PnlPlnrDvcAPar::DpchEngData();
		((PnlPlnrDvcAPar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRDVCDATA) {
		*dpcheng = new CrdPlnrDvc::DpchEngData();
		((CrdPlnrDvc::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRDVCDETAILDATA) {
		*dpcheng = new PnlPlnrDvcDetail::DpchEngData();
		((PnlPlnrDvcDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRDVCHEADBARDATA) {
		*dpcheng = new PnlPlnrDvcHeadbar::DpchEngData();
		((PnlPlnrDvcHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRDVCHK1NARCGUIDEDATA) {
		*dpcheng = new PnlPlnrDvcHk1NArcguide::DpchEngData();
		((PnlPlnrDvcHk1NArcguide::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRDVCHK1NLINEGUIDEDATA) {
		*dpcheng = new PnlPlnrDvcHk1NLineguide::DpchEngData();
		((PnlPlnrDvcHk1NLineguide::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRDVCHK1NSTRUCTUREDATA) {
		*dpcheng = new PnlPlnrDvcHk1NStructure::DpchEngData();
		((PnlPlnrDvcHk1NStructure::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRDVCHK1NVERTEXDATA) {
		*dpcheng = new PnlPlnrDvcHk1NVertex::DpchEngData();
		((PnlPlnrDvcHk1NVertex::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRDVCLISTDATA) {
		*dpcheng = new PnlPlnrDvcList::DpchEngData();
		((PnlPlnrDvcList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRDVCPREDATA) {
		*dpcheng = new PnlPlnrDvcPre::DpchEngData();
		((PnlPlnrDvcPre::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRDVCRECDATA) {
		*dpcheng = new PnlPlnrDvcRec::DpchEngData();
		((PnlPlnrDvcRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRDVCSUP1NDEVICEDATA) {
		*dpcheng = new PnlPlnrDvcSup1NDevice::DpchEngData();
		((PnlPlnrDvcSup1NDevice::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRDVCVIEWDATA) {
		*dpcheng = new PnlPlnrDvcView::DpchEngData();
		((PnlPlnrDvcView::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRFILDATA) {
		*dpcheng = new CrdPlnrFil::DpchEngData();
		((CrdPlnrFil::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRFILDETAILDATA) {
		*dpcheng = new PnlPlnrFilDetail::DpchEngData();
		((PnlPlnrFilDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRFILHEADBARDATA) {
		*dpcheng = new PnlPlnrFilHeadbar::DpchEngData();
		((PnlPlnrFilHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRFILLISTDATA) {
		*dpcheng = new PnlPlnrFilList::DpchEngData();
		((PnlPlnrFilList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRFILMNCALCDATA) {
		*dpcheng = new PnlPlnrFilMNCalc::DpchEngData();
		((PnlPlnrFilMNCalc::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRFILRECDATA) {
		*dpcheng = new PnlPlnrFilRec::DpchEngData();
		((PnlPlnrFilRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRLYR1NBLOCKDATA) {
		*dpcheng = new PnlPlnrLyr1NBlock::DpchEngData();
		((PnlPlnrLyr1NBlock::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRLYR1NRETICLEDATA) {
		*dpcheng = new PnlPlnrLyr1NReticle::DpchEngData();
		((PnlPlnrLyr1NReticle::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRLYRDATA) {
		*dpcheng = new CrdPlnrLyr::DpchEngData();
		((CrdPlnrLyr::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRLYRDETAILDATA) {
		*dpcheng = new PnlPlnrLyrDetail::DpchEngData();
		((PnlPlnrLyrDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRLYRHEADBARDATA) {
		*dpcheng = new PnlPlnrLyrHeadbar::DpchEngData();
		((PnlPlnrLyrHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRLYRLISTDATA) {
		*dpcheng = new PnlPlnrLyrList::DpchEngData();
		((PnlPlnrLyrList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRLYRMNSTRUCTUREDATA) {
		*dpcheng = new PnlPlnrLyrMNStructure::DpchEngData();
		((PnlPlnrLyrMNStructure::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRLYRRECDATA) {
		*dpcheng = new PnlPlnrLyrRec::DpchEngData();
		((PnlPlnrLyrRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRMAT1NLAYERDATA) {
		*dpcheng = new PnlPlnrMat1NLayer::DpchEngData();
		((PnlPlnrMat1NLayer::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRMATAPARDATA) {
		*dpcheng = new PnlPlnrMatAPar::DpchEngData();
		((PnlPlnrMatAPar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRMATDATA) {
		*dpcheng = new CrdPlnrMat::DpchEngData();
		((CrdPlnrMat::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRMATDETAILDATA) {
		*dpcheng = new PnlPlnrMatDetail::DpchEngData();
		((PnlPlnrMatDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRMATHEADBARDATA) {
		*dpcheng = new PnlPlnrMatHeadbar::DpchEngData();
		((PnlPlnrMatHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRMATLISTDATA) {
		*dpcheng = new PnlPlnrMatList::DpchEngData();
		((PnlPlnrMatList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRMATMOD1NMATERIALDATA) {
		*dpcheng = new PnlPlnrMatMod1NMaterial::DpchEngData();
		((PnlPlnrMatMod1NMaterial::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRMATRECDATA) {
		*dpcheng = new PnlPlnrMatRec::DpchEngData();
		((PnlPlnrMatRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRMATREF1NFILEDATA) {
		*dpcheng = new PnlPlnrMatRef1NFile::DpchEngData();
		((PnlPlnrMatRef1NFile::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRNAVADMINDATA) {
		*dpcheng = new PnlPlnrNavAdmin::DpchEngData();
		((PnlPlnrNavAdmin::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRNAVCALCDATA) {
		*dpcheng = new PnlPlnrNavCalc::DpchEngData();
		((PnlPlnrNavCalc::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRNAVDATA) {
		*dpcheng = new CrdPlnrNav::DpchEngData();
		((CrdPlnrNav::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRNAVDESIGNDATA) {
		*dpcheng = new PnlPlnrNavDesign::DpchEngData();
		((PnlPlnrNavDesign::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRNAVGLOBALDATA) {
		*dpcheng = new PnlPlnrNavGlobal::DpchEngData();
		((PnlPlnrNavGlobal::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRNAVHEADBARDATA) {
		*dpcheng = new PnlPlnrNavHeadbar::DpchEngData();
		((PnlPlnrNavHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRNAVLAYOUTDATA) {
		*dpcheng = new PnlPlnrNavLayout::DpchEngData();
		((PnlPlnrNavLayout::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRNAVPREDATA) {
		*dpcheng = new PnlPlnrNavPre::DpchEngData();
		((PnlPlnrNavPre::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRPRJ1NCALCDATA) {
		*dpcheng = new PnlPlnrPrj1NCalc::DpchEngData();
		((PnlPlnrPrj1NCalc::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRPRJ1NDESIGNDATA) {
		*dpcheng = new PnlPlnrPrj1NDesign::DpchEngData();
		((PnlPlnrPrj1NDesign::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRPRJDATA) {
		*dpcheng = new CrdPlnrPrj::DpchEngData();
		((CrdPlnrPrj::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRPRJDETAILDATA) {
		*dpcheng = new PnlPlnrPrjDetail::DpchEngData();
		((PnlPlnrPrjDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRPRJHEADBARDATA) {
		*dpcheng = new PnlPlnrPrjHeadbar::DpchEngData();
		((PnlPlnrPrjHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRPRJLISTDATA) {
		*dpcheng = new PnlPlnrPrjList::DpchEngData();
		((PnlPlnrPrjList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRPRJMNTAPEOUTDATA) {
		*dpcheng = new PnlPlnrPrjMNTapeout::DpchEngData();
		((PnlPlnrPrjMNTapeout::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRPRJRECDATA) {
		*dpcheng = new PnlPlnrPrjRec::DpchEngData();
		((PnlPlnrPrjRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRPRSADETAILDATA) {
		*dpcheng = new PnlPlnrPrsADetail::DpchEngData();
		((PnlPlnrPrsADetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRPRSDATA) {
		*dpcheng = new CrdPlnrPrs::DpchEngData();
		((CrdPlnrPrs::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRPRSDETAILDATA) {
		*dpcheng = new PnlPlnrPrsDetail::DpchEngData();
		((PnlPlnrPrsDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRPRSHEADBARDATA) {
		*dpcheng = new PnlPlnrPrsHeadbar::DpchEngData();
		((PnlPlnrPrsHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRPRSLISTDATA) {
		*dpcheng = new PnlPlnrPrsList::DpchEngData();
		((PnlPlnrPrsList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRPRSRECDATA) {
		*dpcheng = new PnlPlnrPrsRec::DpchEngData();
		((PnlPlnrPrsRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRRTCDATA) {
		*dpcheng = new CrdPlnrRtc::DpchEngData();
		((CrdPlnrRtc::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRRTCDETAILDATA) {
		*dpcheng = new PnlPlnrRtcDetail::DpchEngData();
		((PnlPlnrRtcDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRRTCHEADBARDATA) {
		*dpcheng = new PnlPlnrRtcHeadbar::DpchEngData();
		((PnlPlnrRtcHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRRTCLISTDATA) {
		*dpcheng = new PnlPlnrRtcList::DpchEngData();
		((PnlPlnrRtcList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRRTCRECDATA) {
		*dpcheng = new PnlPlnrRtcRec::DpchEngData();
		((PnlPlnrRtcRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRSRU1NBLOCKDATA) {
		*dpcheng = new PnlPlnrSru1NBlock::DpchEngData();
		((PnlPlnrSru1NBlock::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRSRUDATA) {
		*dpcheng = new CrdPlnrSru::DpchEngData();
		((CrdPlnrSru::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRSRUDETAILDATA) {
		*dpcheng = new PnlPlnrSruDetail::DpchEngData();
		((PnlPlnrSruDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRSRUHEADBARDATA) {
		*dpcheng = new PnlPlnrSruHeadbar::DpchEngData();
		((PnlPlnrSruHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRSRULISTDATA) {
		*dpcheng = new PnlPlnrSruList::DpchEngData();
		((PnlPlnrSruList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRSRUMNLAYERDATA) {
		*dpcheng = new PnlPlnrSruMNLayer::DpchEngData();
		((PnlPlnrSruMNLayer::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRSRUMNSTACKDATA) {
		*dpcheng = new PnlPlnrSruMNStack::DpchEngData();
		((PnlPlnrSruMNStack::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRSRURECDATA) {
		*dpcheng = new PnlPlnrSruRec::DpchEngData();
		((PnlPlnrSruRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRSRUSRU1NFACEDATA) {
		*dpcheng = new PnlPlnrSruSru1NFace::DpchEngData();
		((PnlPlnrSruSru1NFace::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRSTKDATA) {
		*dpcheng = new CrdPlnrStk::DpchEngData();
		((CrdPlnrStk::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRSTKDETAILDATA) {
		*dpcheng = new PnlPlnrStkDetail::DpchEngData();
		((PnlPlnrStkDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRSTKHEADBARDATA) {
		*dpcheng = new PnlPlnrStkHeadbar::DpchEngData();
		((PnlPlnrStkHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRSTKHK1NLAYERDATA) {
		*dpcheng = new PnlPlnrStkHk1NLayer::DpchEngData();
		((PnlPlnrStkHk1NLayer::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRSTKHK1NLEVELDATA) {
		*dpcheng = new PnlPlnrStkHk1NLevel::DpchEngData();
		((PnlPlnrStkHk1NLevel::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRSTKLISTDATA) {
		*dpcheng = new PnlPlnrStkList::DpchEngData();
		((PnlPlnrStkList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRSTKMNSTRUCTUREDATA) {
		*dpcheng = new PnlPlnrStkMNStructure::DpchEngData();
		((PnlPlnrStkMNStructure::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRSTKPREDATA) {
		*dpcheng = new PnlPlnrStkPre::DpchEngData();
		((PnlPlnrStkPre::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRSTKRECDATA) {
		*dpcheng = new PnlPlnrStkRec::DpchEngData();
		((PnlPlnrStkRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRSTKVIEWDATA) {
		*dpcheng = new PnlPlnrStkView::DpchEngData();
		((PnlPlnrStkView::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRSUSPEND) {
		*dpcheng = new DpchEngPlnrSuspend();
		((DpchEngPlnrSuspend*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRTPO1NARRAYDATA) {
		*dpcheng = new PnlPlnrTpo1NArray::DpchEngData();
		((PnlPlnrTpo1NArray::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRTPODATA) {
		*dpcheng = new CrdPlnrTpo::DpchEngData();
		((CrdPlnrTpo::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRTPODETAILDATA) {
		*dpcheng = new PnlPlnrTpoDetail::DpchEngData();
		((PnlPlnrTpoDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRTPOFLOORPLANDATA) {
		*dpcheng = new PnlPlnrTpoFloorplan::DpchEngData();
		((PnlPlnrTpoFloorplan::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRTPOHEADBARDATA) {
		*dpcheng = new PnlPlnrTpoHeadbar::DpchEngData();
		((PnlPlnrTpoHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRTPOHK1NRETICLEDATA) {
		*dpcheng = new PnlPlnrTpoHk1NReticle::DpchEngData();
		((PnlPlnrTpoHk1NReticle::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRTPOLISTDATA) {
		*dpcheng = new PnlPlnrTpoList::DpchEngData();
		((PnlPlnrTpoList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRTPOMNPROJECTDATA) {
		*dpcheng = new PnlPlnrTpoMNProject::DpchEngData();
		((PnlPlnrTpoMNProject::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRTPORECDATA) {
		*dpcheng = new PnlPlnrTpoRec::DpchEngData();
		((PnlPlnrTpoRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRUSGAACCESSDATA) {
		*dpcheng = new PnlPlnrUsgAAccess::DpchEngData();
		((PnlPlnrUsgAAccess::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRUSGDATA) {
		*dpcheng = new CrdPlnrUsg::DpchEngData();
		((CrdPlnrUsg::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRUSGDETAILDATA) {
		*dpcheng = new PnlPlnrUsgDetail::DpchEngData();
		((PnlPlnrUsgDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRUSGHEADBARDATA) {
		*dpcheng = new PnlPlnrUsgHeadbar::DpchEngData();
		((PnlPlnrUsgHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRUSGLISTDATA) {
		*dpcheng = new PnlPlnrUsgList::DpchEngData();
		((PnlPlnrUsgList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRUSGMNUSERDATA) {
		*dpcheng = new PnlPlnrUsgMNUser::DpchEngData();
		((PnlPlnrUsgMNUser::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRUSGRECDATA) {
		*dpcheng = new PnlPlnrUsgRec::DpchEngData();
		((PnlPlnrUsgRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRUSR1NSESSIONDATA) {
		*dpcheng = new PnlPlnrUsr1NSession::DpchEngData();
		((PnlPlnrUsr1NSession::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRUSRAACCESSDATA) {
		*dpcheng = new PnlPlnrUsrAAccess::DpchEngData();
		((PnlPlnrUsrAAccess::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRUSRDATA) {
		*dpcheng = new CrdPlnrUsr::DpchEngData();
		((CrdPlnrUsr::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRUSRDETAILDATA) {
		*dpcheng = new PnlPlnrUsrDetail::DpchEngData();
		((PnlPlnrUsrDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRUSRHEADBARDATA) {
		*dpcheng = new PnlPlnrUsrHeadbar::DpchEngData();
		((PnlPlnrUsrHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRUSRLISTDATA) {
		*dpcheng = new PnlPlnrUsrList::DpchEngData();
		((PnlPlnrUsrList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRUSRMNUSERGROUPDATA) {
		*dpcheng = new PnlPlnrUsrMNUsergroup::DpchEngData();
		((PnlPlnrUsrMNUsergroup::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGPLNRUSRRECDATA) {
		*dpcheng = new PnlPlnrUsrRec::DpchEngData();
		((PnlPlnrUsrRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHENGSESSPLNRDATA) {
		*dpcheng = new SessPlnr::DpchEngData();
		((SessPlnr::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	};

	if (docctx) xmlXPathFreeContext(docctx);
	if (doc) xmlFreeDoc(doc);
	
	return ixPlnrVDpch;
};

void AppPlnr::writeDpchApp(
			DpchAppPlnr* dpchapp
			, char** buf
			, unsigned long& buflen
			, unsigned long ofs
		) {
	xmlBuffer* xbuf = NULL;
	xmlTextWriter* wr = NULL;

	startwriteBuffer(&wr, &xbuf);
		dpchapp->writeXML(wr);
	closewriteBuffer(wr);

	buflen = xbuf->use + ofs;
	*buf = new char[buflen];
	memcpy(&((*buf)[ofs]), xbuf->content, buflen-ofs);

	xmlBufferFree(xbuf);
};

