/**
  * \file PnlPlnrUsrDetail.h
  * app access code for job PnlPlnrUsrDetail (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PNLPLNRUSRDETAIL_H
#define PNLPLNRUSRDETAIL_H

#include "AppPlnr_blks.h"

/**
  * PnlPlnrUsrDetail
  */
namespace PnlPlnrUsrDetail {
	/**
		* VecVDo (full: VecVPlnrUsrDetailDo)
		*/
	class VecVDo {

	public:
		static const uint BUTSAVECLICK = 1;
		static const uint BUTPRSVIEWCLICK = 2;
		static const uint BUTUSGVIEWCLICK = 3;
		static const uint BUTJEDITCLICK = 4;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacPlnrUsrDetail)
	  */
	class ContIac : public Block {

	public:
		static const uint NUMFPUPJ = 1;
		static const uint NUMFPUPSTE = 2;
		static const uint NUMFPUPLCL = 3;
		static const uint NUMFPUPULV = 4;
		static const uint TXFPWD = 5;

	public:
		ContIac(const uint numFPupJ = 1, const uint numFPupSte = 1, const uint numFPupLcl = 1, const uint numFPupUlv = 1, const string& TxfPwd = "");

	public:
		uint numFPupJ;
		uint numFPupSte;
		uint numFPupLcl;
		uint numFPupUlv;
		string TxfPwd;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfPlnrUsrDetail)
	  */
	class ContInf : public Block {

	public:
		static const uint TXTPRS = 1;
		static const uint TXTSRF = 2;
		static const uint TXTUSG = 3;

	public:
		ContInf(const string& TxtPrs = "", const string& TxtSrf = "", const string& TxtUsg = "");

	public:
		string TxtPrs;
		string TxtSrf;
		string TxtUsg;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppPlnrUsrDetail)
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
	  * StatShr (full: StatShrPlnrUsrDetail)
	  */
	class StatShr : public Block {

	public:
		static const uint BUTSAVEAVAIL = 1;
		static const uint BUTSAVEACTIVE = 2;
		static const uint BUTPRSVIEWAVAIL = 3;
		static const uint BUTUSGVIEWAVAIL = 4;
		static const uint BUTJEDITAVAIL = 5;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool ButPrsViewAvail = true, const bool ButUsgViewAvail = true, const bool ButJEditAvail = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool ButPrsViewAvail;
		bool ButUsgViewAvail;
		bool ButJEditAvail;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagPlnrUsrDetail)
	  */
	class Tag : public Block {

	public:
		static const uint CPT = 1;
		static const uint CPTPRS = 2;
		static const uint CPTSRF = 3;
		static const uint CPTUSG = 4;
		static const uint CPTSTE = 5;
		static const uint CPTLCL = 6;
		static const uint CPTULV = 7;
		static const uint CPTPWD = 8;

	public:
		Tag(const string& Cpt = "", const string& CptPrs = "", const string& CptSrf = "", const string& CptUsg = "", const string& CptSte = "", const string& CptLcl = "", const string& CptUlv = "", const string& CptPwd = "");

	public:
		string Cpt;
		string CptPrs;
		string CptSrf;
		string CptUsg;
		string CptSte;
		string CptLcl;
		string CptUlv;
		string CptPwd;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppPlnrUsrDetailData)
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
		* DpchAppDo (full: DpchAppPlnrUsrDetailDo)
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
		* DpchEngData (full: DpchEngPlnrUsrDetailData)
		*/
	class DpchEngData : public DpchEngPlnr {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTIAC = 2;
		static const uint CONTINF = 3;
		static const uint FEEDFPUPJ = 4;
		static const uint FEEDFPUPLCL = 5;
		static const uint FEEDFPUPSTE = 6;
		static const uint FEEDFPUPULV = 7;
		static const uint STATAPP = 8;
		static const uint STATSHR = 9;
		static const uint TAG = 10;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Feed feedFPupJ;
		Feed feedFPupLcl;
		Feed feedFPupSte;
		Feed feedFPupUlv;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

