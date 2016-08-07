/**
  * \file PnlPlnrDomDetail.h
  * app access code for job PnlPlnrDomDetail (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PNLPLNRDOMDETAIL_H
#define PNLPLNRDOMDETAIL_H

#include "AppPlnr_blks.h"

/**
  * PnlPlnrDomDetail
  */
namespace PnlPlnrDomDetail {
	/**
		* VecVDo (full: VecVPlnrDomDetailDo)
		*/
	class VecVDo {

	public:
		static const uint BUTSAVECLICK = 1;
		static const uint BUTDSNVIEWCLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacPlnrDomDetail)
	  */
	class ContIac : public Block {

	public:
		static const uint NUMFPUPTYP = 1;
		static const uint TXFFLR = 2;
		static const uint TXFCEI = 3;
		static const uint TXFVX1 = 4;
		static const uint TXFLG1 = 5;
		static const uint TXFVX2 = 6;
		static const uint TXFLG2 = 7;
		static const uint TXFVX3 = 8;
		static const uint TXFLG3 = 9;
		static const uint TXFVX4 = 10;
		static const uint TXFLG4 = 11;
		static const uint TXFDX = 12;
		static const uint TXFDY = 13;
		static const uint TXFDXY = 14;
		static const uint TXFDZ = 15;

	public:
		ContIac(const uint numFPupTyp = 1, const string& TxfFlr = "", const string& TxfCei = "", const string& TxfVx1 = "", const string& TxfLg1 = "", const string& TxfVx2 = "", const string& TxfLg2 = "", const string& TxfVx3 = "", const string& TxfLg3 = "", const string& TxfVx4 = "", const string& TxfLg4 = "", const string& TxfDx = "", const string& TxfDy = "", const string& TxfDxy = "", const string& TxfDz = "");

	public:
		uint numFPupTyp;
		string TxfFlr;
		string TxfCei;
		string TxfVx1;
		string TxfLg1;
		string TxfVx2;
		string TxfLg2;
		string TxfVx3;
		string TxfLg3;
		string TxfVx4;
		string TxfLg4;
		string TxfDx;
		string TxfDy;
		string TxfDxy;
		string TxfDz;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfPlnrDomDetail)
	  */
	class ContInf : public Block {

	public:
		static const uint TXTSRF = 1;
		static const uint TXTDSN = 2;
		static const uint TXTFLR = 3;
		static const uint TXTCEI = 4;
		static const uint TXTVX1 = 5;
		static const uint TXTLG1 = 6;
		static const uint TXTVX2 = 7;
		static const uint TXTLG2 = 8;
		static const uint TXTVX3 = 9;
		static const uint TXTLG3 = 10;
		static const uint TXTVX4 = 11;
		static const uint TXTLG4 = 12;

	public:
		ContInf(const string& TxtSrf = "", const string& TxtDsn = "", const string& TxtFlr = "", const string& TxtCei = "", const string& TxtVx1 = "", const string& TxtLg1 = "", const string& TxtVx2 = "", const string& TxtLg2 = "", const string& TxtVx3 = "", const string& TxtLg3 = "", const string& TxtVx4 = "", const string& TxtLg4 = "");

	public:
		string TxtSrf;
		string TxtDsn;
		string TxtFlr;
		string TxtCei;
		string TxtVx1;
		string TxtLg1;
		string TxtVx2;
		string TxtLg2;
		string TxtVx3;
		string TxtLg3;
		string TxtVx4;
		string TxtLg4;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppPlnrDomDetail)
	  */
	class StatApp : public Block {

	public:
		static const uint IXPLNRVEXPSTATE = 1;
		static const uint TXTFLRALT = 2;
		static const uint TXTCEIALT = 3;
		static const uint TXTVX1ALT = 4;
		static const uint TXTLG1ALT = 5;
		static const uint TXTVX2ALT = 6;
		static const uint TXTLG2ALT = 7;
		static const uint TXTVX3ALT = 8;
		static const uint TXTLG3ALT = 9;
		static const uint TXTVX4ALT = 10;
		static const uint TXTLG4ALT = 11;

	public:
		StatApp(const uint ixPlnrVExpstate = VecPlnrVExpstate::MIND, const bool TxtFlrAlt = false, const bool TxtCeiAlt = false, const bool TxtVx1Alt = false, const bool TxtLg1Alt = false, const bool TxtVx2Alt = false, const bool TxtLg2Alt = false, const bool TxtVx3Alt = false, const bool TxtLg3Alt = false, const bool TxtVx4Alt = false, const bool TxtLg4Alt = false);

	public:
		uint ixPlnrVExpstate;
		bool TxtFlrAlt;
		bool TxtCeiAlt;
		bool TxtVx1Alt;
		bool TxtLg1Alt;
		bool TxtVx2Alt;
		bool TxtLg2Alt;
		bool TxtVx3Alt;
		bool TxtLg3Alt;
		bool TxtVx4Alt;
		bool TxtLg4Alt;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatApp* comp);
		set<uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrPlnrDomDetail)
	  */
	class StatShr : public Block {

	public:
		static const uint TXFFLRVALID = 1;
		static const uint TXFCEIVALID = 2;
		static const uint TXFVX1VALID = 3;
		static const uint TXFLG1VALID = 4;
		static const uint TXFVX2VALID = 5;
		static const uint TXFLG2VALID = 6;
		static const uint TXFVX3VALID = 7;
		static const uint TXFLG3VALID = 8;
		static const uint TXFVX4VALID = 9;
		static const uint TXFLG4VALID = 10;
		static const uint BUTSAVEAVAIL = 11;
		static const uint BUTSAVEACTIVE = 12;
		static const uint BUTDSNVIEWAVAIL = 13;

	public:
		StatShr(const bool TxfFlrValid = false, const bool TxfCeiValid = false, const bool TxfVx1Valid = false, const bool TxfLg1Valid = false, const bool TxfVx2Valid = false, const bool TxfLg2Valid = false, const bool TxfVx3Valid = false, const bool TxfLg3Valid = false, const bool TxfVx4Valid = false, const bool TxfLg4Valid = false, const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool ButDsnViewAvail = true);

	public:
		bool TxfFlrValid;
		bool TxfCeiValid;
		bool TxfVx1Valid;
		bool TxfLg1Valid;
		bool TxfVx2Valid;
		bool TxfLg2Valid;
		bool TxfVx3Valid;
		bool TxfLg3Valid;
		bool TxfVx4Valid;
		bool TxfLg4Valid;
		bool ButSaveAvail;
		bool ButSaveActive;
		bool ButDsnViewAvail;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagPlnrDomDetail)
	  */
	class Tag : public Block {

	public:
		static const uint CPT = 1;
		static const uint CPTSRF = 2;
		static const uint CPTTYP = 3;
		static const uint CPTDSN = 4;
		static const uint CPTFLR = 5;
		static const uint CPTCEI = 6;
		static const uint CPTVX1 = 7;
		static const uint CPTLG1 = 8;
		static const uint CPTVX2 = 9;
		static const uint CPTLG2 = 10;
		static const uint CPTVX3 = 11;
		static const uint CPTLG3 = 12;
		static const uint CPTVX4 = 13;
		static const uint CPTLG4 = 14;
		static const uint CPTDX = 15;
		static const uint CPTDY = 16;
		static const uint CPTDXY = 17;
		static const uint CPTDZ = 18;

	public:
		Tag(const string& Cpt = "", const string& CptSrf = "", const string& CptTyp = "", const string& CptDsn = "", const string& CptFlr = "", const string& CptCei = "", const string& CptVx1 = "", const string& CptLg1 = "", const string& CptVx2 = "", const string& CptLg2 = "", const string& CptVx3 = "", const string& CptLg3 = "", const string& CptVx4 = "", const string& CptLg4 = "", const string& CptDx = "", const string& CptDy = "", const string& CptDxy = "", const string& CptDz = "");

	public:
		string Cpt;
		string CptSrf;
		string CptTyp;
		string CptDsn;
		string CptFlr;
		string CptCei;
		string CptVx1;
		string CptLg1;
		string CptVx2;
		string CptLg2;
		string CptVx3;
		string CptLg3;
		string CptVx4;
		string CptLg4;
		string CptDx;
		string CptDy;
		string CptDxy;
		string CptDz;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppPlnrDomDetailData)
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
		* DpchAppDo (full: DpchAppPlnrDomDetailDo)
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
		* DpchEngData (full: DpchEngPlnrDomDetailData)
		*/
	class DpchEngData : public DpchEngPlnr {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTIAC = 2;
		static const uint CONTINF = 3;
		static const uint FEEDFPUPTYP = 4;
		static const uint STATAPP = 5;
		static const uint STATSHR = 6;
		static const uint TAG = 7;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Feed feedFPupTyp;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

