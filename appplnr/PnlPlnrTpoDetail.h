/**
  * \file PnlPlnrTpoDetail.h
  * app access code for job PnlPlnrTpoDetail (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PNLPLNRTPODETAIL_H
#define PNLPLNRTPODETAIL_H

#include "AppPlnr_blks.h"

/**
  * PnlPlnrTpoDetail
  */
namespace PnlPlnrTpoDetail {
	/**
		* VecVDo (full: VecVPlnrTpoDetailDo)
		*/
	class VecVDo {

	public:
		static const uint BUTSAVECLICK = 1;
		static const uint BUTJEDITCLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacPlnrTpoDetail)
	  */
	class ContIac : public Block {

	public:
		static const uint TXFTIT = 1;
		static const uint NUMFPUPTYP = 2;
		static const uint TXFMAJ = 3;
		static const uint TXFSUB = 4;
		static const uint NUMFPUPJ = 5;
		static const uint NUMFPUPSTE = 6;
		static const uint CHKFLI = 7;
		static const uint TXFCMT = 8;

	public:
		ContIac(const string& TxfTit = "", const uint numFPupTyp = 1, const string& TxfMaj = "", const string& TxfSub = "", const uint numFPupJ = 1, const uint numFPupSte = 1, const bool ChkFli = false, const string& TxfCmt = "");

	public:
		string TxfTit;
		uint numFPupTyp;
		string TxfMaj;
		string TxfSub;
		uint numFPupJ;
		uint numFPupSte;
		bool ChkFli;
		string TxfCmt;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * StatApp (full: StatAppPlnrTpoDetail)
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
	  * StatShr (full: StatShrPlnrTpoDetail)
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
	  * Tag (full: TagPlnrTpoDetail)
	  */
	class Tag : public Block {

	public:
		static const uint CPT = 1;
		static const uint CPTTIT = 2;
		static const uint CPTTYP = 3;
		static const uint CPTMAJ = 4;
		static const uint CPTSUB = 5;
		static const uint CPTSTE = 6;
		static const uint CPTFLI = 7;
		static const uint CPTCMT = 8;

	public:
		Tag(const string& Cpt = "", const string& CptTit = "", const string& CptTyp = "", const string& CptMaj = "", const string& CptSub = "", const string& CptSte = "", const string& CptFli = "", const string& CptCmt = "");

	public:
		string Cpt;
		string CptTit;
		string CptTyp;
		string CptMaj;
		string CptSub;
		string CptSte;
		string CptFli;
		string CptCmt;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppPlnrTpoDetailData)
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
		* DpchAppDo (full: DpchAppPlnrTpoDetailDo)
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
		* DpchEngData (full: DpchEngPlnrTpoDetailData)
		*/
	class DpchEngData : public DpchEngPlnr {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTIAC = 2;
		static const uint FEEDFPUPJ = 3;
		static const uint FEEDFPUPSTE = 4;
		static const uint FEEDFPUPTYP = 5;
		static const uint STATAPP = 6;
		static const uint STATSHR = 7;
		static const uint TAG = 8;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		Feed feedFPupJ;
		Feed feedFPupSte;
		Feed feedFPupTyp;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

