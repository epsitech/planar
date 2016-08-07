/**
  * \file PlnrExp_blks.cpp
  * invocation / return data blocks for operation pack PlnrExp (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrExp_blks.h"

/******************************************************************************
 class DpchInvPlnrExpColldev
 ******************************************************************************/

DpchInvPlnrExpColldev::DpchInvPlnrExpColldev(
			const ubigint oref
			, const ubigint jref
			, const ubigint refPlnrMDevice
		) : DpchInvPlnr(VecPlnrVDpch::DPCHINVPLNREXPCOLLDEV, oref, jref) {
	this->refPlnrMDevice = refPlnrMDevice;
};

void DpchInvPlnrExpColldev::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvPlnrExpColldev");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUbigintUclc(docctx, basexpath, "refPlnrMDevice", "", refPlnrMDevice)) add(REFPLNRMDEVICE);
	};
};

void DpchInvPlnrExpColldev::writeXML(
			pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvPlnrExpColldev");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		writeString(wr, "scrOref", Scr::scramble(mScr, scr, descr, oref));
		writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		writeUbigint(wr, "refPlnrMDevice", refPlnrMDevice);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchInvPlnrExpColldsn
 ******************************************************************************/

DpchInvPlnrExpColldsn::DpchInvPlnrExpColldsn(
			const ubigint oref
			, const ubigint jref
			, const ubigint refPlnrMDesign
		) : DpchInvPlnr(VecPlnrVDpch::DPCHINVPLNREXPCOLLDSN, oref, jref) {
	this->refPlnrMDesign = refPlnrMDesign;
};

void DpchInvPlnrExpColldsn::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvPlnrExpColldsn");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUbigintUclc(docctx, basexpath, "refPlnrMDesign", "", refPlnrMDesign)) add(REFPLNRMDESIGN);
	};
};

void DpchInvPlnrExpColldsn::writeXML(
			pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvPlnrExpColldsn");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		writeString(wr, "scrOref", Scr::scramble(mScr, scr, descr, oref));
		writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		writeUbigint(wr, "refPlnrMDesign", refPlnrMDesign);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchInvPlnrExpCollstk
 ******************************************************************************/

DpchInvPlnrExpCollstk::DpchInvPlnrExpCollstk(
			const ubigint oref
			, const ubigint jref
			, const ubigint refPlnrMStack
		) : DpchInvPlnr(VecPlnrVDpch::DPCHINVPLNREXPCOLLSTK, oref, jref) {
	this->refPlnrMStack = refPlnrMStack;
};

void DpchInvPlnrExpCollstk::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvPlnrExpCollstk");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUbigintUclc(docctx, basexpath, "refPlnrMStack", "", refPlnrMStack)) add(REFPLNRMSTACK);
	};
};

void DpchInvPlnrExpCollstk::writeXML(
			pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvPlnrExpCollstk");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		writeString(wr, "scrOref", Scr::scramble(mScr, scr, descr, oref));
		writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		writeUbigint(wr, "refPlnrMStack", refPlnrMStack);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchInvPlnrExpCorner
 ******************************************************************************/

DpchInvPlnrExpCorner::DpchInvPlnrExpCorner(
			const ubigint oref
			, const ubigint jref
			, const ubigint refPlnrMDevice
		) : DpchInvPlnr(VecPlnrVDpch::DPCHINVPLNREXPCORNER, oref, jref) {
	this->refPlnrMDevice = refPlnrMDevice;
};

void DpchInvPlnrExpCorner::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvPlnrExpCorner");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUbigintUclc(docctx, basexpath, "refPlnrMDevice", "", refPlnrMDevice)) add(REFPLNRMDEVICE);
	};
};

void DpchInvPlnrExpCorner::writeXML(
			pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvPlnrExpCorner");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		writeString(wr, "scrOref", Scr::scramble(mScr, scr, descr, oref));
		writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		writeUbigint(wr, "refPlnrMDevice", refPlnrMDevice);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchInvPlnrExpCross
 ******************************************************************************/

DpchInvPlnrExpCross::DpchInvPlnrExpCross(
			const ubigint oref
			, const ubigint jref
			, const ubigint refPlnrMDevice
		) : DpchInvPlnr(VecPlnrVDpch::DPCHINVPLNREXPCROSS, oref, jref) {
	this->refPlnrMDevice = refPlnrMDevice;
};

void DpchInvPlnrExpCross::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvPlnrExpCross");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUbigintUclc(docctx, basexpath, "refPlnrMDevice", "", refPlnrMDevice)) add(REFPLNRMDEVICE);
	};
};

void DpchInvPlnrExpCross::writeXML(
			pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvPlnrExpCross");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		writeString(wr, "scrOref", Scr::scramble(mScr, scr, descr, oref));
		writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		writeUbigint(wr, "refPlnrMDevice", refPlnrMDevice);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchInvPlnrExpDircoup
 ******************************************************************************/

DpchInvPlnrExpDircoup::DpchInvPlnrExpDircoup(
			const ubigint oref
			, const ubigint jref
			, const ubigint refPlnrMDevice
		) : DpchInvPlnr(VecPlnrVDpch::DPCHINVPLNREXPDIRCOUP, oref, jref) {
	this->refPlnrMDevice = refPlnrMDevice;
};

void DpchInvPlnrExpDircoup::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvPlnrExpDircoup");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUbigintUclc(docctx, basexpath, "refPlnrMDevice", "", refPlnrMDevice)) add(REFPLNRMDEVICE);
	};
};

void DpchInvPlnrExpDircoup::writeXML(
			pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvPlnrExpDircoup");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		writeString(wr, "scrOref", Scr::scramble(mScr, scr, descr, oref));
		writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		writeUbigint(wr, "refPlnrMDevice", refPlnrMDevice);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchInvPlnrExpDiscres
 ******************************************************************************/

DpchInvPlnrExpDiscres::DpchInvPlnrExpDiscres(
			const ubigint oref
			, const ubigint jref
			, const ubigint refPlnrMDevice
		) : DpchInvPlnr(VecPlnrVDpch::DPCHINVPLNREXPDISCRES, oref, jref) {
	this->refPlnrMDevice = refPlnrMDevice;
};

void DpchInvPlnrExpDiscres::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvPlnrExpDiscres");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUbigintUclc(docctx, basexpath, "refPlnrMDevice", "", refPlnrMDevice)) add(REFPLNRMDEVICE);
	};
};

void DpchInvPlnrExpDiscres::writeXML(
			pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvPlnrExpDiscres");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		writeString(wr, "scrOref", Scr::scramble(mScr, scr, descr, oref));
		writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		writeUbigint(wr, "refPlnrMDevice", refPlnrMDevice);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchInvPlnrExpDottext
 ******************************************************************************/

DpchInvPlnrExpDottext::DpchInvPlnrExpDottext(
			const ubigint oref
			, const ubigint jref
			, const ubigint refPlnrMDevice
		) : DpchInvPlnr(VecPlnrVDpch::DPCHINVPLNREXPDOTTEXT, oref, jref) {
	this->refPlnrMDevice = refPlnrMDevice;
};

void DpchInvPlnrExpDottext::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvPlnrExpDottext");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUbigintUclc(docctx, basexpath, "refPlnrMDevice", "", refPlnrMDevice)) add(REFPLNRMDEVICE);
	};
};

void DpchInvPlnrExpDottext::writeXML(
			pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvPlnrExpDottext");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		writeString(wr, "scrOref", Scr::scramble(mScr, scr, descr, oref));
		writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		writeUbigint(wr, "refPlnrMDevice", refPlnrMDevice);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchInvPlnrExpDsn
 ******************************************************************************/

DpchInvPlnrExpDsn::DpchInvPlnrExpDsn(
			const ubigint oref
			, const ubigint jref
			, const ubigint refPlnrMDesign
		) : DpchInvPlnr(VecPlnrVDpch::DPCHINVPLNREXPDSN, oref, jref) {
	this->refPlnrMDesign = refPlnrMDesign;
};

void DpchInvPlnrExpDsn::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvPlnrExpDsn");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUbigintUclc(docctx, basexpath, "refPlnrMDesign", "", refPlnrMDesign)) add(REFPLNRMDESIGN);
	};
};

void DpchInvPlnrExpDsn::writeXML(
			pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvPlnrExpDsn");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		writeString(wr, "scrOref", Scr::scramble(mScr, scr, descr, oref));
		writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		writeUbigint(wr, "refPlnrMDesign", refPlnrMDesign);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchInvPlnrExpGratcpl
 ******************************************************************************/

DpchInvPlnrExpGratcpl::DpchInvPlnrExpGratcpl(
			const ubigint oref
			, const ubigint jref
			, const ubigint refPlnrMDevice
		) : DpchInvPlnr(VecPlnrVDpch::DPCHINVPLNREXPGRATCPL, oref, jref) {
	this->refPlnrMDevice = refPlnrMDevice;
};

void DpchInvPlnrExpGratcpl::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvPlnrExpGratcpl");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUbigintUclc(docctx, basexpath, "refPlnrMDevice", "", refPlnrMDevice)) add(REFPLNRMDEVICE);
	};
};

void DpchInvPlnrExpGratcpl::writeXML(
			pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvPlnrExpGratcpl");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		writeString(wr, "scrOref", Scr::scramble(mScr, scr, descr, oref));
		writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		writeUbigint(wr, "refPlnrMDevice", refPlnrMDevice);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchInvPlnrExpGray
 ******************************************************************************/

DpchInvPlnrExpGray::DpchInvPlnrExpGray(
			const ubigint oref
			, const ubigint jref
			, const ubigint refPlnrMDevice
		) : DpchInvPlnr(VecPlnrVDpch::DPCHINVPLNREXPGRAY, oref, jref) {
	this->refPlnrMDevice = refPlnrMDevice;
};

void DpchInvPlnrExpGray::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvPlnrExpGray");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUbigintUclc(docctx, basexpath, "refPlnrMDevice", "", refPlnrMDevice)) add(REFPLNRMDEVICE);
	};
};

void DpchInvPlnrExpGray::writeXML(
			pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvPlnrExpGray");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		writeString(wr, "scrOref", Scr::scramble(mScr, scr, descr, oref));
		writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		writeUbigint(wr, "refPlnrMDevice", refPlnrMDevice);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchInvPlnrExpImage
 ******************************************************************************/

DpchInvPlnrExpImage::DpchInvPlnrExpImage(
			const ubigint oref
			, const ubigint jref
			, const ubigint refPlnrMDevice
		) : DpchInvPlnr(VecPlnrVDpch::DPCHINVPLNREXPIMAGE, oref, jref) {
	this->refPlnrMDevice = refPlnrMDevice;
};

void DpchInvPlnrExpImage::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvPlnrExpImage");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUbigintUclc(docctx, basexpath, "refPlnrMDevice", "", refPlnrMDevice)) add(REFPLNRMDEVICE);
	};
};

void DpchInvPlnrExpImage::writeXML(
			pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvPlnrExpImage");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		writeString(wr, "scrOref", Scr::scramble(mScr, scr, descr, oref));
		writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		writeUbigint(wr, "refPlnrMDevice", refPlnrMDevice);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchInvPlnrExpMarker
 ******************************************************************************/

DpchInvPlnrExpMarker::DpchInvPlnrExpMarker(
			const ubigint oref
			, const ubigint jref
			, const ubigint refPlnrMDevice
		) : DpchInvPlnr(VecPlnrVDpch::DPCHINVPLNREXPMARKER, oref, jref) {
	this->refPlnrMDevice = refPlnrMDevice;
};

void DpchInvPlnrExpMarker::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvPlnrExpMarker");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUbigintUclc(docctx, basexpath, "refPlnrMDevice", "", refPlnrMDevice)) add(REFPLNRMDEVICE);
	};
};

void DpchInvPlnrExpMarker::writeXML(
			pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvPlnrExpMarker");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		writeString(wr, "scrOref", Scr::scramble(mScr, scr, descr, oref));
		writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		writeUbigint(wr, "refPlnrMDevice", refPlnrMDevice);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchInvPlnrExpPad
 ******************************************************************************/

DpchInvPlnrExpPad::DpchInvPlnrExpPad(
			const ubigint oref
			, const ubigint jref
			, const ubigint refPlnrMDevice
		) : DpchInvPlnr(VecPlnrVDpch::DPCHINVPLNREXPPAD, oref, jref) {
	this->refPlnrMDevice = refPlnrMDevice;
};

void DpchInvPlnrExpPad::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvPlnrExpPad");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUbigintUclc(docctx, basexpath, "refPlnrMDevice", "", refPlnrMDevice)) add(REFPLNRMDEVICE);
	};
};

void DpchInvPlnrExpPad::writeXML(
			pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvPlnrExpPad");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		writeString(wr, "scrOref", Scr::scramble(mScr, scr, descr, oref));
		writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		writeUbigint(wr, "refPlnrMDevice", refPlnrMDevice);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchInvPlnrExpPhcsq
 ******************************************************************************/

DpchInvPlnrExpPhcsq::DpchInvPlnrExpPhcsq(
			const ubigint oref
			, const ubigint jref
			, const ubigint refPlnrMDevice
		) : DpchInvPlnr(VecPlnrVDpch::DPCHINVPLNREXPPHCSQ, oref, jref) {
	this->refPlnrMDevice = refPlnrMDevice;
};

void DpchInvPlnrExpPhcsq::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvPlnrExpPhcsq");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUbigintUclc(docctx, basexpath, "refPlnrMDevice", "", refPlnrMDevice)) add(REFPLNRMDEVICE);
	};
};

void DpchInvPlnrExpPhcsq::writeXML(
			pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvPlnrExpPhcsq");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		writeString(wr, "scrOref", Scr::scramble(mScr, scr, descr, oref));
		writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		writeUbigint(wr, "refPlnrMDevice", refPlnrMDevice);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchInvPlnrExpPhcsqneg
 ******************************************************************************/

DpchInvPlnrExpPhcsqneg::DpchInvPlnrExpPhcsqneg(
			const ubigint oref
			, const ubigint jref
			, const ubigint refPlnrMDevice
		) : DpchInvPlnr(VecPlnrVDpch::DPCHINVPLNREXPPHCSQNEG, oref, jref) {
	this->refPlnrMDevice = refPlnrMDevice;
};

void DpchInvPlnrExpPhcsqneg::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvPlnrExpPhcsqneg");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUbigintUclc(docctx, basexpath, "refPlnrMDevice", "", refPlnrMDevice)) add(REFPLNRMDEVICE);
	};
};

void DpchInvPlnrExpPhcsqneg::writeXML(
			pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvPlnrExpPhcsqneg");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		writeString(wr, "scrOref", Scr::scramble(mScr, scr, descr, oref));
		writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		writeUbigint(wr, "refPlnrMDevice", refPlnrMDevice);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchInvPlnrExpPhctrig
 ******************************************************************************/

DpchInvPlnrExpPhctrig::DpchInvPlnrExpPhctrig(
			const ubigint oref
			, const ubigint jref
			, const ubigint refPlnrMDevice
		) : DpchInvPlnr(VecPlnrVDpch::DPCHINVPLNREXPPHCTRIG, oref, jref) {
	this->refPlnrMDevice = refPlnrMDevice;
};

void DpchInvPlnrExpPhctrig::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvPlnrExpPhctrig");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUbigintUclc(docctx, basexpath, "refPlnrMDevice", "", refPlnrMDevice)) add(REFPLNRMDEVICE);
	};
};

void DpchInvPlnrExpPhctrig::writeXML(
			pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvPlnrExpPhctrig");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		writeString(wr, "scrOref", Scr::scramble(mScr, scr, descr, oref));
		writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		writeUbigint(wr, "refPlnrMDevice", refPlnrMDevice);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchInvPlnrExpPhctrigneg
 ******************************************************************************/

DpchInvPlnrExpPhctrigneg::DpchInvPlnrExpPhctrigneg(
			const ubigint oref
			, const ubigint jref
			, const ubigint refPlnrMDevice
		) : DpchInvPlnr(VecPlnrVDpch::DPCHINVPLNREXPPHCTRIGNEG, oref, jref) {
	this->refPlnrMDevice = refPlnrMDevice;
};

void DpchInvPlnrExpPhctrigneg::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvPlnrExpPhctrigneg");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUbigintUclc(docctx, basexpath, "refPlnrMDevice", "", refPlnrMDevice)) add(REFPLNRMDEVICE);
	};
};

void DpchInvPlnrExpPhctrigneg::writeXML(
			pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvPlnrExpPhctrigneg");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		writeString(wr, "scrOref", Scr::scramble(mScr, scr, descr, oref));
		writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		writeUbigint(wr, "refPlnrMDevice", refPlnrMDevice);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchInvPlnrExpPhotdet
 ******************************************************************************/

DpchInvPlnrExpPhotdet::DpchInvPlnrExpPhotdet(
			const ubigint oref
			, const ubigint jref
			, const ubigint refPlnrMDevice
		) : DpchInvPlnr(VecPlnrVDpch::DPCHINVPLNREXPPHOTDET, oref, jref) {
	this->refPlnrMDevice = refPlnrMDevice;
};

void DpchInvPlnrExpPhotdet::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvPlnrExpPhotdet");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUbigintUclc(docctx, basexpath, "refPlnrMDevice", "", refPlnrMDevice)) add(REFPLNRMDEVICE);
	};
};

void DpchInvPlnrExpPhotdet::writeXML(
			pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvPlnrExpPhotdet");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		writeString(wr, "scrOref", Scr::scramble(mScr, scr, descr, oref));
		writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		writeUbigint(wr, "refPlnrMDevice", refPlnrMDevice);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchInvPlnrExpPie
 ******************************************************************************/

DpchInvPlnrExpPie::DpchInvPlnrExpPie(
			const ubigint oref
			, const ubigint jref
			, const ubigint refPlnrMDevice
		) : DpchInvPlnr(VecPlnrVDpch::DPCHINVPLNREXPPIE, oref, jref) {
	this->refPlnrMDevice = refPlnrMDevice;
};

void DpchInvPlnrExpPie::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvPlnrExpPie");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUbigintUclc(docctx, basexpath, "refPlnrMDevice", "", refPlnrMDevice)) add(REFPLNRMDEVICE);
	};
};

void DpchInvPlnrExpPie::writeXML(
			pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvPlnrExpPie");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		writeString(wr, "scrOref", Scr::scramble(mScr, scr, descr, oref));
		writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		writeUbigint(wr, "refPlnrMDevice", refPlnrMDevice);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchInvPlnrExpPinout
 ******************************************************************************/

DpchInvPlnrExpPinout::DpchInvPlnrExpPinout(
			const ubigint oref
			, const ubigint jref
			, const ubigint refPlnrMDevice
		) : DpchInvPlnr(VecPlnrVDpch::DPCHINVPLNREXPPINOUT, oref, jref) {
	this->refPlnrMDevice = refPlnrMDevice;
};

void DpchInvPlnrExpPinout::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvPlnrExpPinout");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUbigintUclc(docctx, basexpath, "refPlnrMDevice", "", refPlnrMDevice)) add(REFPLNRMDEVICE);
	};
};

void DpchInvPlnrExpPinout::writeXML(
			pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvPlnrExpPinout");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		writeString(wr, "scrOref", Scr::scramble(mScr, scr, descr, oref));
		writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		writeUbigint(wr, "refPlnrMDevice", refPlnrMDevice);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchInvPlnrExpRoicadp
 ******************************************************************************/

DpchInvPlnrExpRoicadp::DpchInvPlnrExpRoicadp(
			const ubigint oref
			, const ubigint jref
			, const ubigint refPlnrMDevice
		) : DpchInvPlnr(VecPlnrVDpch::DPCHINVPLNREXPROICADP, oref, jref) {
	this->refPlnrMDevice = refPlnrMDevice;
};

void DpchInvPlnrExpRoicadp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvPlnrExpRoicadp");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUbigintUclc(docctx, basexpath, "refPlnrMDevice", "", refPlnrMDevice)) add(REFPLNRMDEVICE);
	};
};

void DpchInvPlnrExpRoicadp::writeXML(
			pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvPlnrExpRoicadp");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		writeString(wr, "scrOref", Scr::scramble(mScr, scr, descr, oref));
		writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		writeUbigint(wr, "refPlnrMDevice", refPlnrMDevice);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchInvPlnrExpRtresneg
 ******************************************************************************/

DpchInvPlnrExpRtresneg::DpchInvPlnrExpRtresneg(
			const ubigint oref
			, const ubigint jref
			, const ubigint refPlnrMDevice
		) : DpchInvPlnr(VecPlnrVDpch::DPCHINVPLNREXPRTRESNEG, oref, jref) {
	this->refPlnrMDevice = refPlnrMDevice;
};

void DpchInvPlnrExpRtresneg::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvPlnrExpRtresneg");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUbigintUclc(docctx, basexpath, "refPlnrMDevice", "", refPlnrMDevice)) add(REFPLNRMDEVICE);
	};
};

void DpchInvPlnrExpRtresneg::writeXML(
			pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvPlnrExpRtresneg");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		writeString(wr, "scrOref", Scr::scramble(mScr, scr, descr, oref));
		writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		writeUbigint(wr, "refPlnrMDevice", refPlnrMDevice);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchInvPlnrExpSpring
 ******************************************************************************/

DpchInvPlnrExpSpring::DpchInvPlnrExpSpring(
			const ubigint oref
			, const ubigint jref
			, const ubigint refPlnrMDevice
		) : DpchInvPlnr(VecPlnrVDpch::DPCHINVPLNREXPSPRING, oref, jref) {
	this->refPlnrMDevice = refPlnrMDevice;
};

void DpchInvPlnrExpSpring::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvPlnrExpSpring");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUbigintUclc(docctx, basexpath, "refPlnrMDevice", "", refPlnrMDevice)) add(REFPLNRMDEVICE);
	};
};

void DpchInvPlnrExpSpring::writeXML(
			pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvPlnrExpSpring");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		writeString(wr, "scrOref", Scr::scramble(mScr, scr, descr, oref));
		writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		writeUbigint(wr, "refPlnrMDevice", refPlnrMDevice);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchInvPlnrExpStkpertpl
 ******************************************************************************/

DpchInvPlnrExpStkpertpl::DpchInvPlnrExpStkpertpl(
			const ubigint oref
			, const ubigint jref
			, const ubigint refPlnrMStack
		) : DpchInvPlnr(VecPlnrVDpch::DPCHINVPLNREXPSTKPERTPL, oref, jref) {
	this->refPlnrMStack = refPlnrMStack;
};

void DpchInvPlnrExpStkpertpl::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvPlnrExpStkpertpl");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUbigintUclc(docctx, basexpath, "refPlnrMStack", "", refPlnrMStack)) add(REFPLNRMSTACK);
	};
};

void DpchInvPlnrExpStkpertpl::writeXML(
			pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvPlnrExpStkpertpl");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		writeString(wr, "scrOref", Scr::scramble(mScr, scr, descr, oref));
		writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		writeUbigint(wr, "refPlnrMStack", refPlnrMStack);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchInvPlnrExpStkregfill
 ******************************************************************************/

DpchInvPlnrExpStkregfill::DpchInvPlnrExpStkregfill(
			const ubigint oref
			, const ubigint jref
			, const ubigint refPlnrMStack
		) : DpchInvPlnr(VecPlnrVDpch::DPCHINVPLNREXPSTKREGFILL, oref, jref) {
	this->refPlnrMStack = refPlnrMStack;
};

void DpchInvPlnrExpStkregfill::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvPlnrExpStkregfill");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUbigintUclc(docctx, basexpath, "refPlnrMStack", "", refPlnrMStack)) add(REFPLNRMSTACK);
	};
};

void DpchInvPlnrExpStkregfill::writeXML(
			pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvPlnrExpStkregfill");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		writeString(wr, "scrOref", Scr::scramble(mScr, scr, descr, oref));
		writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		writeUbigint(wr, "refPlnrMStack", refPlnrMStack);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchInvPlnrExpVanderpauw
 ******************************************************************************/

DpchInvPlnrExpVanderpauw::DpchInvPlnrExpVanderpauw(
			const ubigint oref
			, const ubigint jref
			, const ubigint refPlnrMDevice
		) : DpchInvPlnr(VecPlnrVDpch::DPCHINVPLNREXPVANDERPAUW, oref, jref) {
	this->refPlnrMDevice = refPlnrMDevice;
};

void DpchInvPlnrExpVanderpauw::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvPlnrExpVanderpauw");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUbigintUclc(docctx, basexpath, "refPlnrMDevice", "", refPlnrMDevice)) add(REFPLNRMDEVICE);
	};
};

void DpchInvPlnrExpVanderpauw::writeXML(
			pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvPlnrExpVanderpauw");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		writeString(wr, "scrOref", Scr::scramble(mScr, scr, descr, oref));
		writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		writeUbigint(wr, "refPlnrMDevice", refPlnrMDevice);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchInvPlnrExpWg
 ******************************************************************************/

DpchInvPlnrExpWg::DpchInvPlnrExpWg(
			const ubigint oref
			, const ubigint jref
			, const ubigint refPlnrMDevice
		) : DpchInvPlnr(VecPlnrVDpch::DPCHINVPLNREXPWG, oref, jref) {
	this->refPlnrMDevice = refPlnrMDevice;
};

void DpchInvPlnrExpWg::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvPlnrExpWg");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUbigintUclc(docctx, basexpath, "refPlnrMDevice", "", refPlnrMDevice)) add(REFPLNRMDEVICE);
	};
};

void DpchInvPlnrExpWg::writeXML(
			pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvPlnrExpWg");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		writeString(wr, "scrOref", Scr::scramble(mScr, scr, descr, oref));
		writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		writeUbigint(wr, "refPlnrMDevice", refPlnrMDevice);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchInvPlnrExpWgbend
 ******************************************************************************/

DpchInvPlnrExpWgbend::DpchInvPlnrExpWgbend(
			const ubigint oref
			, const ubigint jref
			, const ubigint refPlnrMDevice
		) : DpchInvPlnr(VecPlnrVDpch::DPCHINVPLNREXPWGBEND, oref, jref) {
	this->refPlnrMDevice = refPlnrMDevice;
};

void DpchInvPlnrExpWgbend::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvPlnrExpWgbend");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUbigintUclc(docctx, basexpath, "refPlnrMDevice", "", refPlnrMDevice)) add(REFPLNRMDEVICE);
	};
};

void DpchInvPlnrExpWgbend::writeXML(
			pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvPlnrExpWgbend");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		writeString(wr, "scrOref", Scr::scramble(mScr, scr, descr, oref));
		writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		writeUbigint(wr, "refPlnrMDevice", refPlnrMDevice);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchInvPlnrExpWgbendneg
 ******************************************************************************/

DpchInvPlnrExpWgbendneg::DpchInvPlnrExpWgbendneg(
			const ubigint oref
			, const ubigint jref
			, const ubigint refPlnrMDevice
		) : DpchInvPlnr(VecPlnrVDpch::DPCHINVPLNREXPWGBENDNEG, oref, jref) {
	this->refPlnrMDevice = refPlnrMDevice;
};

void DpchInvPlnrExpWgbendneg::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvPlnrExpWgbendneg");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUbigintUclc(docctx, basexpath, "refPlnrMDevice", "", refPlnrMDevice)) add(REFPLNRMDEVICE);
	};
};

void DpchInvPlnrExpWgbendneg::writeXML(
			pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvPlnrExpWgbendneg");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		writeString(wr, "scrOref", Scr::scramble(mScr, scr, descr, oref));
		writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		writeUbigint(wr, "refPlnrMDevice", refPlnrMDevice);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchInvPlnrExpWgneg
 ******************************************************************************/

DpchInvPlnrExpWgneg::DpchInvPlnrExpWgneg(
			const ubigint oref
			, const ubigint jref
			, const ubigint refPlnrMDevice
		) : DpchInvPlnr(VecPlnrVDpch::DPCHINVPLNREXPWGNEG, oref, jref) {
	this->refPlnrMDevice = refPlnrMDevice;
};

void DpchInvPlnrExpWgneg::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvPlnrExpWgneg");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUbigintUclc(docctx, basexpath, "refPlnrMDevice", "", refPlnrMDevice)) add(REFPLNRMDEVICE);
	};
};

void DpchInvPlnrExpWgneg::writeXML(
			pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvPlnrExpWgneg");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		writeString(wr, "scrOref", Scr::scramble(mScr, scr, descr, oref));
		writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		writeUbigint(wr, "refPlnrMDevice", refPlnrMDevice);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchInvPlnrExpWgsusp
 ******************************************************************************/

DpchInvPlnrExpWgsusp::DpchInvPlnrExpWgsusp(
			const ubigint oref
			, const ubigint jref
			, const ubigint refPlnrMDevice
		) : DpchInvPlnr(VecPlnrVDpch::DPCHINVPLNREXPWGSUSP, oref, jref) {
	this->refPlnrMDevice = refPlnrMDevice;
};

void DpchInvPlnrExpWgsusp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvPlnrExpWgsusp");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUbigintUclc(docctx, basexpath, "refPlnrMDevice", "", refPlnrMDevice)) add(REFPLNRMDEVICE);
	};
};

void DpchInvPlnrExpWgsusp::writeXML(
			pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvPlnrExpWgsusp");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		writeString(wr, "scrOref", Scr::scramble(mScr, scr, descr, oref));
		writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		writeUbigint(wr, "refPlnrMDevice", refPlnrMDevice);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchInvPlnrExpWgtap
 ******************************************************************************/

DpchInvPlnrExpWgtap::DpchInvPlnrExpWgtap(
			const ubigint oref
			, const ubigint jref
			, const ubigint refPlnrMDevice
		) : DpchInvPlnr(VecPlnrVDpch::DPCHINVPLNREXPWGTAP, oref, jref) {
	this->refPlnrMDevice = refPlnrMDevice;
};

void DpchInvPlnrExpWgtap::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvPlnrExpWgtap");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUbigintUclc(docctx, basexpath, "refPlnrMDevice", "", refPlnrMDevice)) add(REFPLNRMDEVICE);
	};
};

void DpchInvPlnrExpWgtap::writeXML(
			pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvPlnrExpWgtap");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		writeString(wr, "scrOref", Scr::scramble(mScr, scr, descr, oref));
		writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		writeUbigint(wr, "refPlnrMDevice", refPlnrMDevice);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchInvPlnrExpWgtapneg
 ******************************************************************************/

DpchInvPlnrExpWgtapneg::DpchInvPlnrExpWgtapneg(
			const ubigint oref
			, const ubigint jref
			, const ubigint refPlnrMDevice
		) : DpchInvPlnr(VecPlnrVDpch::DPCHINVPLNREXPWGTAPNEG, oref, jref) {
	this->refPlnrMDevice = refPlnrMDevice;
};

void DpchInvPlnrExpWgtapneg::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvPlnrExpWgtapneg");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUbigintUclc(docctx, basexpath, "refPlnrMDevice", "", refPlnrMDevice)) add(REFPLNRMDEVICE);
	};
};

void DpchInvPlnrExpWgtapneg::writeXML(
			pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvPlnrExpWgtapneg");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		writeString(wr, "scrOref", Scr::scramble(mScr, scr, descr, oref));
		writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		writeUbigint(wr, "refPlnrMDevice", refPlnrMDevice);
	xmlTextWriterEndElement(wr);
};

// IP cust --- IBEGIN
/******************************************************************************
 namespace PlnrExp_blks
 ******************************************************************************/

void PlnrExp_blks::getInvs(
			DbsPlnr* dbsplnr
			, map<string, ubigint>& refsDtp
			, const ubigint refDsn
			, vector<DpchInvPlnr*>& dpchinvs
		) {
	// prepare invocation dispatches for all devices and stacks of a base design (respective ops will take care of expanding eventual design modifications)

	ListPlnrMDevice devs;
	PlnrMDevice* dev = NULL;

	map<ubigint, string> srefsDtp;
	map<ubigint, string>::iterator ix;
	string srefDtp;

	ListPlnrMStack stks;
	PlnrMStack* stk = NULL;

	// --- devices
	// invert refsDtp
	for (map<string, ubigint>::iterator i=refsDtp.begin();i!=refsDtp.end();++i) srefsDtp[i->second] = i->first;

	dbsplnr->tblplnrmdevice->loadRstByDsn(refDsn, false, devs);
	for (unsigned int i=0;i<devs.nodes.size();i++) {
		dev = devs.nodes[i];

		if (refDsn == 0) {
			// special case dtp expansion
			ix = srefsDtp.find(dev->ref);
		} else {
			ix = srefsDtp.find(dev->tplRefPlnrMDevice);
		};

		if (ix == srefsDtp.end()) {
			srefDtp = "";
		} else {
			srefDtp = ix->second;
		};

		if (srefDtp.length() > 0) {
			if (srefDtp.compare("corner") == 0) dpchinvs.push_back(new DpchInvPlnrExpCorner(0, 0, dev->ref));
			else if (srefDtp.compare("cross") == 0) dpchinvs.push_back(new DpchInvPlnrExpCross(0, 0, dev->ref));
			else if (srefDtp.compare("dircoup") == 0) dpchinvs.push_back(new DpchInvPlnrExpDircoup(0, 0, dev->ref));
			else if (srefDtp.compare("discres") == 0) dpchinvs.push_back(new DpchInvPlnrExpDiscres(0, 0, dev->ref));
			else if (srefDtp.compare("dottext") == 0) dpchinvs.push_back(new DpchInvPlnrExpDottext(0, 0, dev->ref));
			else if (srefDtp.compare("gratcpl") == 0) dpchinvs.push_back(new DpchInvPlnrExpGratcpl(0, 0, dev->ref));
			else if (srefDtp.compare("gray") == 0) dpchinvs.push_back(new DpchInvPlnrExpGray(0, 0, dev->ref));
			else if (srefDtp.compare("image") == 0) dpchinvs.push_back(new DpchInvPlnrExpImage(0, 0, dev->ref));
			else if (srefDtp.compare("marker") == 0) dpchinvs.push_back(new DpchInvPlnrExpMarker(0, 0, dev->ref));
			else if (srefDtp.compare("pad") == 0) dpchinvs.push_back(new DpchInvPlnrExpPad(0, 0, dev->ref));
			else if (srefDtp.compare("phcsq") == 0) dpchinvs.push_back(new DpchInvPlnrExpPhcsq(0, 0, dev->ref));
			else if (srefDtp.compare("phcsqneg") == 0) dpchinvs.push_back(new DpchInvPlnrExpPhcsqneg(0, 0, dev->ref));
			else if (srefDtp.compare("phctrig") == 0) dpchinvs.push_back(new DpchInvPlnrExpPhctrig(0, 0, dev->ref));
			else if (srefDtp.compare("phctrigneg") == 0) dpchinvs.push_back(new DpchInvPlnrExpPhctrigneg(0, 0, dev->ref));
			else if (srefDtp.compare("photdet") == 0) dpchinvs.push_back(new DpchInvPlnrExpPhotdet(0, 0, dev->ref));
			else if (srefDtp.compare("pie") == 0) dpchinvs.push_back(new DpchInvPlnrExpPie(0, 0, dev->ref));
			else if (srefDtp.compare("pinout") == 0) dpchinvs.push_back(new DpchInvPlnrExpPinout(0, 0, dev->ref));
			else if (srefDtp.compare("roicadp") == 0) dpchinvs.push_back(new DpchInvPlnrExpRoicadp(0, 0, dev->ref));
			else if (srefDtp.compare("rtresneg") == 0) dpchinvs.push_back(new DpchInvPlnrExpRtresneg(0, 0, dev->ref));
			else if (srefDtp.compare("spring") == 0) dpchinvs.push_back(new DpchInvPlnrExpSpring(0, 0, dev->ref));
			else if (srefDtp.compare("vanderpauw") == 0) dpchinvs.push_back(new DpchInvPlnrExpVanderpauw(0, 0, dev->ref));
			else if (srefDtp.compare("wg") == 0) dpchinvs.push_back(new DpchInvPlnrExpWg(0, 0, dev->ref));
			else if (srefDtp.compare("wgbend") == 0) dpchinvs.push_back(new DpchInvPlnrExpWgbend(0, 0, dev->ref));
			else if (srefDtp.compare("wgbendneg") == 0) dpchinvs.push_back(new DpchInvPlnrExpWgbendneg(0, 0, dev->ref));
			else if (srefDtp.compare("wgneg") == 0) dpchinvs.push_back(new DpchInvPlnrExpWgneg(0, 0, dev->ref));
			else if (srefDtp.compare("wgsusp") == 0) dpchinvs.push_back(new DpchInvPlnrExpWgsusp(0, 0, dev->ref));
			else if (srefDtp.compare("wgtap") == 0) dpchinvs.push_back(new DpchInvPlnrExpWgtap(0, 0, dev->ref));
			else if (srefDtp.compare("wgtapneg") == 0) dpchinvs.push_back(new DpchInvPlnrExpWgtapneg(0, 0, dev->ref));
		};
	};

	// --- stacks (flat stacks need no expansion)
	dbsplnr->tblplnrmstack->loadRstByDsn(refDsn, false, stks);
	for (unsigned int i=0;i<stks.nodes.size();i++) {
		stk = stks.nodes[i];

		if ((stk->ixVBasetype == VecPlnrVMStackBasetype::REG) || (stk->ixVBasetype == VecPlnrVMStackBasetype::FILL)) {
			dpchinvs.push_back(new DpchInvPlnrExpStkregfill(0, 0, stk->ref));
		} else if (stk->ixVBasetype == VecPlnrVMStackBasetype::PERTPL) {
			dpchinvs.push_back(new DpchInvPlnrExpStkpertpl(0, 0, stk->ref));
		};
	};
};
// IP cust --- IEND


