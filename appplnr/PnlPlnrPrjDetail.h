/**
  * \file PnlPlnrPrjDetail.h
  * app access code for job PnlPlnrPrjDetail (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PNLPLNRPRJDETAIL_H
#define PNLPLNRPRJDETAIL_H

#include "AppPlnr_blks.h"

/**
  * PnlPlnrPrjDetail
  */
namespace PnlPlnrPrjDetail {
	/**
		* VecVDo (full: VecVPlnrPrjDetailDo)
		*/
	class VecVDo {

	public:
		static const uint BUTSAVECLICK = 1;
		static const uint BUTJEDITCLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacPlnrPrjDetail)
	  */
	class ContIac : public Block {

	public:
		static const uint TXFTIT = 1;
		static const uint NUMFPUPJ = 2;
		static const uint NUMFPUPSTE = 3;
		static const uint TXFCMT = 4;

	public:
		ContIac(const string& TxfTit = "", const uint numFPupJ = 1, const uint numFPupSte = 1, const string& TxfCmt = "");

	public:
		string TxfTit;
		uint numFPupJ;
		uint numFPupSte;
		string TxfCmt;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * StatApp (full: StatAppPlnrPrjDetail)
	  */
	class StatApp : public Block {

	public:
		static const uint IXPLNRVEXPSTATE = 1;

	public:
		StatApp(const uint ixPlnrVExpstate = VecPlnrVExpstate::MIND);

	public:
		uint ixPlnrVExpstate;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatApp* comp);
		set<uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrPlnrPrjDetail)
	  */
	class StatShr : public Block {

	public:
		static const uint BUTSAVEAVAIL = 1;
		static const uint BUTSAVEACTIVE = 2;
		static const uint BUTJEDITAVAIL = 3;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool ButJEditAvail = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool ButJEditAvail;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagPlnrPrjDetail)
	  */
	class Tag : public Block {

	public:
		static const uint CPT = 1;
		static const uint CPTTIT = 2;
		static const uint CPTSTE = 3;
		static const uint CPTCMT = 4;

	public:
		Tag(const string& Cpt = "", const string& CptTit = "", const string& CptSte = "", const string& CptCmt = "");

	public:
		string Cpt;
		string CptTit;
		string CptSte;
		string CptCmt;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppPlnrPrjDetailData)
		*/
	class DpchAppData : public DpchAppPlnr {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTIAC = 2;
		static const uint ALL = 3;

	public:
		DpchAppData(const string& scrJref = "", ContIac* contiac = NULL, const set<uint>& mask = {NONE});

	public:
		ContIac contiac;

	public:
		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchAppDo (full: DpchAppPlnrPrjDetailDo)
		*/
	class DpchAppDo : public DpchAppPlnr {

	public:
		static const uint SCRJREF = 1;
		static const uint IXVDO = 2;
		static const uint ALL = 3;

	public:
		DpchAppDo(const string& scrJref = "", const uint ixVDo = 0, const set<uint>& mask = {NONE});

	public:
		uint ixVDo;

	public:
		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchEngData (full: DpchEngPlnrPrjDetailData)
		*/
	class DpchEngData : public DpchEngPlnr {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTIAC = 2;
		static const uint FEEDFPUPJ = 3;
		static const uint FEEDFPUPSTE = 4;
		static const uint STATAPP = 5;
		static const uint STATSHR = 6;
		static const uint TAG = 7;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		Feed feedFPupJ;
		Feed feedFPupSte;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

