/**
  * \file PnlPlnrLyrDetail.h
  * app access code for job PnlPlnrLyrDetail (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PNLPLNRLYRDETAIL_H
#define PNLPLNRLYRDETAIL_H

#include "AppPlnr_blks.h"

/**
  * PnlPlnrLyrDetail
  */
namespace PnlPlnrLyrDetail {
	/**
		* VecVDo (full: VecVPlnrLyrDetailDo)
		*/
	class VecVDo {

	public:
		static const uint BUTSAVECLICK = 1;
		static const uint BUTHKUVIEWCLICK = 2;
		static const uint BUTMATVIEWCLICK = 3;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacPlnrLyrDetail)
	  */
	class ContIac : public Block {

	public:
		static const uint NUMFPUPTYP = 1;
		static const uint NUMFPUPHKT = 2;
		static const uint NUMFPUPTTY = 3;
		static const uint TXFT = 4;
		static const uint TXFML = 5;

	public:
		ContIac(const uint numFPupTyp = 1, const uint numFPupHkt = 1, const uint numFPupTty = 1, const string& TxfT = "", const string& TxfMl = "");

	public:
		uint numFPupTyp;
		uint numFPupHkt;
		uint numFPupTty;
		string TxfT;
		string TxfMl;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfPlnrLyrDetail)
	  */
	class ContInf : public Block {

	public:
		static const uint TXTSRF = 1;
		static const uint TXTHKU = 2;
		static const uint TXTMAT = 3;
		static const uint TXTFLR = 4;
		static const uint TXTCTR = 5;
		static const uint TXTCEI = 6;

	public:
		ContInf(const string& TxtSrf = "", const string& TxtHku = "", const string& TxtMat = "", const string& TxtFlr = "", const string& TxtCtr = "", const string& TxtCei = "");

	public:
		string TxtSrf;
		string TxtHku;
		string TxtMat;
		string TxtFlr;
		string TxtCtr;
		string TxtCei;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppPlnrLyrDetail)
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
	  * StatShr (full: StatShrPlnrLyrDetail)
	  */
	class StatShr : public Block {

	public:
		static const uint BUTSAVEAVAIL = 1;
		static const uint BUTSAVEACTIVE = 2;
		static const uint BUTMATVIEWAVAIL = 3;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool ButMatViewAvail = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool ButMatViewAvail;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagPlnrLyrDetail)
	  */
	class Tag : public Block {

	public:
		static const uint CPT = 1;
		static const uint CPTSRF = 2;
		static const uint CPTTYP = 3;
		static const uint CPTHKU = 4;
		static const uint CPTMAT = 5;
		static const uint CPTTTY = 6;
		static const uint CPTFLR = 7;
		static const uint CPTCTR = 8;
		static const uint CPTCEI = 9;
		static const uint CPTT = 10;
		static const uint CPTML = 11;

	public:
		Tag(const string& Cpt = "", const string& CptSrf = "", const string& CptTyp = "", const string& CptHku = "", const string& CptMat = "", const string& CptTty = "", const string& CptFlr = "", const string& CptCtr = "", const string& CptCei = "", const string& CptT = "", const string& CptMl = "");

	public:
		string Cpt;
		string CptSrf;
		string CptTyp;
		string CptHku;
		string CptMat;
		string CptTty;
		string CptFlr;
		string CptCtr;
		string CptCei;
		string CptT;
		string CptMl;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppPlnrLyrDetailData)
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
		* DpchAppDo (full: DpchAppPlnrLyrDetailDo)
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
		* DpchEngData (full: DpchEngPlnrLyrDetailData)
		*/
	class DpchEngData : public DpchEngPlnr {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTIAC = 2;
		static const uint CONTINF = 3;
		static const uint FEEDFPUPHKT = 4;
		static const uint FEEDFPUPTTY = 5;
		static const uint FEEDFPUPTYP = 6;
		static const uint STATAPP = 7;
		static const uint STATSHR = 8;
		static const uint TAG = 9;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Feed feedFPupHkt;
		Feed feedFPupTty;
		Feed feedFPupTyp;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

