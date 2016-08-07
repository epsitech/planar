/**
  * \file PnlPlnrFilDetail.h
  * app access code for job PnlPlnrFilDetail (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PNLPLNRFILDETAIL_H
#define PNLPLNRFILDETAIL_H

#include "AppPlnr_blks.h"

/**
  * PnlPlnrFilDetail
  */
namespace PnlPlnrFilDetail {
	/**
		* VecVDo (full: VecVPlnrFilDetailDo)
		*/
	class VecVDo {

	public:
		static const uint BUTSAVECLICK = 1;
		static const uint BUTCLUVIEWCLICK = 2;
		static const uint BUTCLUCLUSTERCLICK = 3;
		static const uint BUTCLUUNCLUSTERCLICK = 4;
		static const uint BUTREUVIEWCLICK = 5;
		static const uint BUTCNTEDITCLICK = 6;
		static const uint BUTMIMEDITCLICK = 7;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacPlnrFilDetail)
	  */
	class ContIac : public Block {

	public:
		static const uint TXFFNM = 1;
		static const uint NUMFLSTCLU = 2;
		static const uint NUMFPUPRET = 3;
		static const uint NUMFPUPCNT = 4;
		static const uint TXFCNT = 5;
		static const uint TXFACV = 6;
		static const uint TXFANM = 7;
		static const uint NUMFPUPMIM = 8;
		static const uint TXFMIM = 9;
		static const uint TXFSIZ = 10;
		static const uint TXFCMT = 11;

	public:
		ContIac(const string& TxfFnm = "", const uint numFLstClu = 1, const uint numFPupRet = 1, const uint numFPupCnt = 1, const string& TxfCnt = "", const string& TxfAcv = "", const string& TxfAnm = "", const uint numFPupMim = 1, const string& TxfMim = "", const string& TxfSiz = "", const string& TxfCmt = "");

	public:
		string TxfFnm;
		uint numFLstClu;
		uint numFPupRet;
		uint numFPupCnt;
		string TxfCnt;
		string TxfAcv;
		string TxfAnm;
		uint numFPupMim;
		string TxfMim;
		string TxfSiz;
		string TxfCmt;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfPlnrFilDetail)
	  */
	class ContInf : public Block {

	public:
		static const uint TXTCLU = 1;
		static const uint TXTREU = 2;

	public:
		ContInf(const string& TxtClu = "", const string& TxtReu = "");

	public:
		string TxtClu;
		string TxtReu;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppPlnrFilDetail)
	  */
	class StatApp : public Block {

	public:
		static const uint IXPLNRVEXPSTATE = 1;
		static const uint LSTCLUALT = 2;
		static const uint PUPCNTALT = 3;
		static const uint PUPMIMALT = 4;
		static const uint LSTCLUNUMFIRSTDISP = 5;

	public:
		StatApp(const uint ixPlnrVExpstate = VecPlnrVExpstate::MIND, const bool LstCluAlt = true, const bool PupCntAlt = false, const bool PupMimAlt = false, const uint LstCluNumFirstdisp = 1);

	public:
		uint ixPlnrVExpstate;
		bool LstCluAlt;
		bool PupCntAlt;
		bool PupMimAlt;
		uint LstCluNumFirstdisp;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatApp* comp);
		set<uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrPlnrFilDetail)
	  */
	class StatShr : public Block {

	public:
		static const uint TXFCNTVALID = 1;
		static const uint TXFMIMVALID = 2;
		static const uint BUTSAVEAVAIL = 3;
		static const uint BUTSAVEACTIVE = 4;
		static const uint BUTCLUVIEWACTIVE = 5;
		static const uint BUTCLUCLUSTERAVAIL = 6;
		static const uint BUTCLUUNCLUSTERAVAIL = 7;
		static const uint BUTCNTEDITAVAIL = 8;
		static const uint BUTMIMEDITAVAIL = 9;

	public:
		StatShr(const bool TxfCntValid = false, const bool TxfMimValid = false, const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool ButCluViewActive = true, const bool ButCluClusterAvail = true, const bool ButCluUnclusterAvail = true, const bool ButCntEditAvail = true, const bool ButMimEditAvail = true);

	public:
		bool TxfCntValid;
		bool TxfMimValid;
		bool ButSaveAvail;
		bool ButSaveActive;
		bool ButCluViewActive;
		bool ButCluClusterAvail;
		bool ButCluUnclusterAvail;
		bool ButCntEditAvail;
		bool ButMimEditAvail;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagPlnrFilDetail)
	  */
	class Tag : public Block {

	public:
		static const uint CPT = 1;
		static const uint CPTFNM = 2;
		static const uint CPTCLU = 3;
		static const uint CPTREU = 4;
		static const uint CPTCNT = 5;
		static const uint CPTACV = 6;
		static const uint CPTANM = 7;
		static const uint CPTMIM = 8;
		static const uint CPTSIZ = 9;
		static const uint CPTCMT = 10;

	public:
		Tag(const string& Cpt = "", const string& CptFnm = "", const string& CptClu = "", const string& CptReu = "", const string& CptCnt = "", const string& CptAcv = "", const string& CptAnm = "", const string& CptMim = "", const string& CptSiz = "", const string& CptCmt = "");

	public:
		string Cpt;
		string CptFnm;
		string CptClu;
		string CptReu;
		string CptCnt;
		string CptAcv;
		string CptAnm;
		string CptMim;
		string CptSiz;
		string CptCmt;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppPlnrFilDetailData)
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
		* DpchAppDo (full: DpchAppPlnrFilDetailDo)
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
		* DpchEngData (full: DpchEngPlnrFilDetailData)
		*/
	class DpchEngData : public DpchEngPlnr {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTIAC = 2;
		static const uint CONTINF = 3;
		static const uint FEEDFLSTCLU = 4;
		static const uint FEEDFPUPCNT = 5;
		static const uint FEEDFPUPMIM = 6;
		static const uint FEEDFPUPRET = 7;
		static const uint STATAPP = 8;
		static const uint STATSHR = 9;
		static const uint TAG = 10;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Feed feedFLstClu;
		Feed feedFPupCnt;
		Feed feedFPupMim;
		Feed feedFPupRet;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

