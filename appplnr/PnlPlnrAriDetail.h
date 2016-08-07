/**
  * \file PnlPlnrAriDetail.h
  * app access code for job PnlPlnrAriDetail (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PNLPLNRARIDETAIL_H
#define PNLPLNRARIDETAIL_H

#include "AppPlnr_blks.h"

/**
  * PnlPlnrAriDetail
  */
namespace PnlPlnrAriDetail {
	/**
		* VecVDo (full: VecVPlnrAriDetailDo)
		*/
	class VecVDo {

	public:
		static const uint BUTSAVECLICK = 1;
		static const uint BUTARRVIEWCLICK = 2;
		static const uint BUTDSNVIEWCLICK = 3;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacPlnrAriDetail)
	  */
	class ContIac : public Block {

	public:
		static const uint TXFI = 1;
		static const uint TXFJ = 2;
		static const uint TXFK = 3;
		static const uint TXFL = 4;
		static const uint TXFM = 5;
		static const uint TXFN = 6;
		static const uint TXFDX = 7;
		static const uint TXFDY = 8;

	public:
		ContIac(const string& TxfI = "", const string& TxfJ = "", const string& TxfK = "", const string& TxfL = "", const string& TxfM = "", const string& TxfN = "", const string& TxfDx = "", const string& TxfDy = "");

	public:
		string TxfI;
		string TxfJ;
		string TxfK;
		string TxfL;
		string TxfM;
		string TxfN;
		string TxfDx;
		string TxfDy;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfPlnrAriDetail)
	  */
	class ContInf : public Block {

	public:
		static const uint TXTARR = 1;
		static const uint TXTDSN = 2;

	public:
		ContInf(const string& TxtArr = "", const string& TxtDsn = "");

	public:
		string TxtArr;
		string TxtDsn;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppPlnrAriDetail)
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
	  * StatShr (full: StatShrPlnrAriDetail)
	  */
	class StatShr : public Block {

	public:
		static const uint BUTSAVEAVAIL = 1;
		static const uint BUTSAVEACTIVE = 2;
		static const uint BUTARRVIEWAVAIL = 3;
		static const uint BUTDSNVIEWAVAIL = 4;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool ButArrViewAvail = true, const bool ButDsnViewAvail = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool ButArrViewAvail;
		bool ButDsnViewAvail;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagPlnrAriDetail)
	  */
	class Tag : public Block {

	public:
		static const uint CPT = 1;
		static const uint CPTI = 2;
		static const uint CPTJ = 3;
		static const uint CPTK = 4;
		static const uint CPTL = 5;
		static const uint CPTM = 6;
		static const uint CPTN = 7;
		static const uint CPTARR = 8;
		static const uint CPTDSN = 9;
		static const uint CPTDX = 10;
		static const uint CPTDY = 11;

	public:
		Tag(const string& Cpt = "", const string& CptI = "", const string& CptJ = "", const string& CptK = "", const string& CptL = "", const string& CptM = "", const string& CptN = "", const string& CptArr = "", const string& CptDsn = "", const string& CptDx = "", const string& CptDy = "");

	public:
		string Cpt;
		string CptI;
		string CptJ;
		string CptK;
		string CptL;
		string CptM;
		string CptN;
		string CptArr;
		string CptDsn;
		string CptDx;
		string CptDy;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppPlnrAriDetailData)
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
		* DpchAppDo (full: DpchAppPlnrAriDetailDo)
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
		* DpchEngData (full: DpchEngPlnrAriDetailData)
		*/
	class DpchEngData : public DpchEngPlnr {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTIAC = 2;
		static const uint CONTINF = 3;
		static const uint STATAPP = 4;
		static const uint STATSHR = 5;
		static const uint TAG = 6;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

