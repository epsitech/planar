/**
  * \file PnlPlnrStkDetail.h
  * app access code for job PnlPlnrStkDetail (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PNLPLNRSTKDETAIL_H
#define PNLPLNRSTKDETAIL_H

#include "AppPlnr_blks.h"

/**
  * PnlPlnrStkDetail
  */
namespace PnlPlnrStkDetail {
	/**
		* VecVDo (full: VecVPlnrStkDetailDo)
		*/
	class VecVDo {

	public:
		static const uint BUTSAVECLICK = 1;
		static const uint BUTDSNVIEWCLICK = 2;
		static const uint BUTLYRVIEWCLICK = 3;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacPlnrStkDetail)
	  */
	class ContIac : public Block {

	public:
		static const uint NUMFPUPTYP = 1;
		static const uint NUMFPUPMTY = 2;
		static const uint NUMFPUPFAL = 3;
		static const uint TXFFLR = 4;
		static const uint TXFZFL = 5;
		static const uint NUMFPUPCAL = 6;
		static const uint TXFCIL = 7;
		static const uint TXFZCI = 8;
		static const uint NUMFLSTLYR = 9;
		static const uint TXFLYR = 10;
		static const uint TXFN = 11;

	public:
		ContIac(const uint numFPupTyp = 1, const uint numFPupMty = 1, const uint numFPupFal = 1, const string& TxfFlr = "", const string& TxfZfl = "", const uint numFPupCal = 1, const string& TxfCil = "", const string& TxfZci = "", const uint numFLstLyr = 1, const string& TxfLyr = "", const string& TxfN = "");

	public:
		uint numFPupTyp;
		uint numFPupMty;
		uint numFPupFal;
		string TxfFlr;
		string TxfZfl;
		uint numFPupCal;
		string TxfCil;
		string TxfZci;
		uint numFLstLyr;
		string TxfLyr;
		string TxfN;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfPlnrStkDetail)
	  */
	class ContInf : public Block {

	public:
		static const uint TXTSRF = 1;
		static const uint TXTDSN = 2;
		static const uint TXTFLR = 3;
		static const uint TXTCIL = 4;

	public:
		ContInf(const string& TxtSrf = "", const string& TxtDsn = "", const string& TxtFlr = "", const string& TxtCil = "");

	public:
		string TxtSrf;
		string TxtDsn;
		string TxtFlr;
		string TxtCil;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppPlnrStkDetail)
	  */
	class StatApp : public Block {

	public:
		static const uint IXPLNRVEXPSTATE = 1;
		static const uint TXTFLRALT = 2;
		static const uint TXTCILALT = 3;
		static const uint LSTLYRALT = 4;
		static const uint LSTLYRNUMFIRSTDISP = 5;

	public:
		StatApp(const uint ixPlnrVExpstate = VecPlnrVExpstate::MIND, const bool TxtFlrAlt = false, const bool TxtCilAlt = false, const bool LstLyrAlt = true, const uint LstLyrNumFirstdisp = 1);

	public:
		uint ixPlnrVExpstate;
		bool TxtFlrAlt;
		bool TxtCilAlt;
		bool LstLyrAlt;
		uint LstLyrNumFirstdisp;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatApp* comp);
		set<uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrPlnrStkDetail)
	  */
	class StatShr : public Block {

	public:
		static const uint TXFFLRVALID = 1;
		static const uint TXFCILVALID = 2;
		static const uint TXFLYRVALID = 3;
		static const uint BUTSAVEAVAIL = 4;
		static const uint BUTSAVEACTIVE = 5;
		static const uint BUTDSNVIEWAVAIL = 6;
		static const uint BUTLYRVIEWAVAIL = 7;
		static const uint BUTLYRVIEWACTIVE = 8;

	public:
		StatShr(const bool TxfFlrValid = false, const bool TxfCilValid = false, const bool TxfLyrValid = false, const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool ButDsnViewAvail = true, const bool ButLyrViewAvail = true, const bool ButLyrViewActive = true);

	public:
		bool TxfFlrValid;
		bool TxfCilValid;
		bool TxfLyrValid;
		bool ButSaveAvail;
		bool ButSaveActive;
		bool ButDsnViewAvail;
		bool ButLyrViewAvail;
		bool ButLyrViewActive;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagPlnrStkDetail)
	  */
	class Tag : public Block {

	public:
		static const uint CPT = 1;
		static const uint CPTSRF = 2;
		static const uint CPTTYP = 3;
		static const uint CPTDSN = 4;
		static const uint CPTMTY = 5;
		static const uint CPTFAL = 6;
		static const uint CPTFLR = 7;
		static const uint CPTZFL = 8;
		static const uint CPTCAL = 9;
		static const uint CPTCIL = 10;
		static const uint CPTZCI = 11;
		static const uint CPTLYR = 12;
		static const uint CPTN = 13;

	public:
		Tag(const string& Cpt = "", const string& CptSrf = "", const string& CptTyp = "", const string& CptDsn = "", const string& CptMty = "", const string& CptFal = "", const string& CptFlr = "", const string& CptZfl = "", const string& CptCal = "", const string& CptCil = "", const string& CptZci = "", const string& CptLyr = "", const string& CptN = "");

	public:
		string Cpt;
		string CptSrf;
		string CptTyp;
		string CptDsn;
		string CptMty;
		string CptFal;
		string CptFlr;
		string CptZfl;
		string CptCal;
		string CptCil;
		string CptZci;
		string CptLyr;
		string CptN;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppPlnrStkDetailData)
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
		* DpchAppDo (full: DpchAppPlnrStkDetailDo)
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
		* DpchEngData (full: DpchEngPlnrStkDetailData)
		*/
	class DpchEngData : public DpchEngPlnr {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTIAC = 2;
		static const uint CONTINF = 3;
		static const uint FEEDFLSTLYR = 4;
		static const uint FEEDFPUPCAL = 5;
		static const uint FEEDFPUPFAL = 6;
		static const uint FEEDFPUPMTY = 7;
		static const uint FEEDFPUPTYP = 8;
		static const uint STATAPP = 9;
		static const uint STATSHR = 10;
		static const uint TAG = 11;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Feed feedFLstLyr;
		Feed feedFPupCal;
		Feed feedFPupFal;
		Feed feedFPupMty;
		Feed feedFPupTyp;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

