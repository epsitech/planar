/**
  * \file PnlPlnrDsnDetail.h
  * app access code for job PnlPlnrDsnDetail (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PNLPLNRDSNDETAIL_H
#define PNLPLNRDSNDETAIL_H

#include "AppPlnr_blks.h"

/**
  * PnlPlnrDsnDetail
  */
namespace PnlPlnrDsnDetail {
	/**
		* VecVDo (full: VecVPlnrDsnDetailDo)
		*/
	class VecVDo {

	public:
		static const uint BUTSAVECLICK = 1;
		static const uint BUTREUVIEWCLICK = 2;
		static const uint BUTPRJVIEWCLICK = 3;
		static const uint BUTMODVIEWCLICK = 4;
		static const uint BUTDRVVIEWCLICK = 5;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacPlnrDsnDetail)
	  */
	class ContIac : public Block {

	public:
		static const uint TXFTIT = 1;
		static const uint NUMFPUPTYP = 2;
		static const uint NUMFPUPDIM = 3;
		static const uint NUMFPUPRET = 4;
		static const uint NUMSFLSTMTY = 5;
		static const uint TXFMAJ = 6;
		static const uint TXFSUB = 7;
		static const uint TXFCMT = 8;

	public:
		ContIac(const string& TxfTit = "", const uint numFPupTyp = 1, const uint numFPupDim = 1, const uint numFPupRet = 1, const vector<uint>& numsFLstMty = {}, const string& TxfMaj = "", const string& TxfSub = "", const string& TxfCmt = "");

	public:
		string TxfTit;
		uint numFPupTyp;
		uint numFPupDim;
		uint numFPupRet;
		vector<uint> numsFLstMty;
		string TxfMaj;
		string TxfSub;
		string TxfCmt;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfPlnrDsnDetail)
	  */
	class ContInf : public Block {

	public:
		static const uint TXTREU = 1;
		static const uint TXTPRJ = 2;
		static const uint TXTMTY = 3;
		static const uint TXTMOD = 4;
		static const uint TXTDRV = 5;

	public:
		ContInf(const string& TxtReu = "", const string& TxtPrj = "", const string& TxtMty = "", const string& TxtMod = "", const string& TxtDrv = "");

	public:
		string TxtReu;
		string TxtPrj;
		string TxtMty;
		string TxtMod;
		string TxtDrv;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppPlnrDsnDetail)
	  */
	class StatApp : public Block {

	public:
		static const uint IXPLNRVEXPSTATE = 1;
		static const uint LSTMTYALT = 2;
		static const uint LSTMTYNUMFIRSTDISP = 3;

	public:
		StatApp(const uint ixPlnrVExpstate = VecPlnrVExpstate::MIND, const bool LstMtyAlt = true, const uint LstMtyNumFirstdisp = 1);

	public:
		uint ixPlnrVExpstate;
		bool LstMtyAlt;
		uint LstMtyNumFirstdisp;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatApp* comp);
		set<uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrPlnrDsnDetail)
	  */
	class StatShr : public Block {

	public:
		static const uint BUTSAVEAVAIL = 1;
		static const uint BUTSAVEACTIVE = 2;
		static const uint BUTPRJVIEWAVAIL = 3;
		static const uint BUTMODVIEWAVAIL = 4;
		static const uint BUTDRVVIEWAVAIL = 5;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool ButPrjViewAvail = true, const bool ButModViewAvail = true, const bool ButDrvViewAvail = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool ButPrjViewAvail;
		bool ButModViewAvail;
		bool ButDrvViewAvail;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagPlnrDsnDetail)
	  */
	class Tag : public Block {

	public:
		static const uint CPT = 1;
		static const uint CPTTIT = 2;
		static const uint CPTTYP = 3;
		static const uint CPTDIM = 4;
		static const uint CPTREU = 5;
		static const uint CPTPRJ = 6;
		static const uint CPTMTY = 7;
		static const uint CPTMOD = 8;
		static const uint CPTDRV = 9;
		static const uint CPTMAJ = 10;
		static const uint CPTSUB = 11;
		static const uint CPTCMT = 12;

	public:
		Tag(const string& Cpt = "", const string& CptTit = "", const string& CptTyp = "", const string& CptDim = "", const string& CptReu = "", const string& CptPrj = "", const string& CptMty = "", const string& CptMod = "", const string& CptDrv = "", const string& CptMaj = "", const string& CptSub = "", const string& CptCmt = "");

	public:
		string Cpt;
		string CptTit;
		string CptTyp;
		string CptDim;
		string CptReu;
		string CptPrj;
		string CptMty;
		string CptMod;
		string CptDrv;
		string CptMaj;
		string CptSub;
		string CptCmt;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppPlnrDsnDetailData)
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
		* DpchAppDo (full: DpchAppPlnrDsnDetailDo)
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
		* DpchEngData (full: DpchEngPlnrDsnDetailData)
		*/
	class DpchEngData : public DpchEngPlnr {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTIAC = 2;
		static const uint CONTINF = 3;
		static const uint FEEDFLSTMTY = 4;
		static const uint FEEDFPUPDIM = 5;
		static const uint FEEDFPUPRET = 6;
		static const uint FEEDFPUPTYP = 7;
		static const uint STATAPP = 8;
		static const uint STATSHR = 9;
		static const uint TAG = 10;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Feed feedFLstMty;
		Feed feedFPupDim;
		Feed feedFPupRet;
		Feed feedFPupTyp;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

