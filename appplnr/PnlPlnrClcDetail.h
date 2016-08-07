/**
  * \file PnlPlnrClcDetail.h
  * app access code for job PnlPlnrClcDetail (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PNLPLNRCLCDETAIL_H
#define PNLPLNRCLCDETAIL_H

#include "AppPlnr_blks.h"

/**
  * PnlPlnrClcDetail
  */
namespace PnlPlnrClcDetail {
	/**
		* VecVDo (full: VecVPlnrClcDetailDo)
		*/
	class VecVDo {

	public:
		static const uint BUTSAVECLICK = 1;
		static const uint BUTPRJVIEWCLICK = 2;
		static const uint BUTDSNVIEWCLICK = 3;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacPlnrClcDetail)
	  */
	class ContIac : public Block {

	public:
		static const uint TXFTIT = 1;
		static const uint NUMFPUPDIM = 2;
		static const uint TXFSTA = 3;
		static const uint TXFCMT = 4;

	public:
		ContIac(const string& TxfTit = "", const uint numFPupDim = 1, const string& TxfSta = "", const string& TxfCmt = "");

	public:
		string TxfTit;
		uint numFPupDim;
		string TxfSta;
		string TxfCmt;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfPlnrClcDetail)
	  */
	class ContInf : public Block {

	public:
		static const uint TXTPRJ = 1;
		static const uint TXTTPL = 2;
		static const uint TXTSUP = 3;
		static const uint TXTDSN = 4;

	public:
		ContInf(const string& TxtPrj = "", const string& TxtTpl = "", const string& TxtSup = "", const string& TxtDsn = "");

	public:
		string TxtPrj;
		string TxtTpl;
		string TxtSup;
		string TxtDsn;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppPlnrClcDetail)
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
	  * StatShr (full: StatShrPlnrClcDetail)
	  */
	class StatShr : public Block {

	public:
		static const uint BUTSAVEAVAIL = 1;
		static const uint BUTSAVEACTIVE = 2;
		static const uint BUTPRJVIEWAVAIL = 3;
		static const uint BUTDSNVIEWAVAIL = 4;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool ButPrjViewAvail = true, const bool ButDsnViewAvail = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool ButPrjViewAvail;
		bool ButDsnViewAvail;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagPlnrClcDetail)
	  */
	class Tag : public Block {

	public:
		static const uint CPT = 1;
		static const uint CPTTIT = 2;
		static const uint CPTPRJ = 3;
		static const uint CPTDIM = 4;
		static const uint CPTTPL = 5;
		static const uint CPTSUP = 6;
		static const uint CPTDSN = 7;
		static const uint CPTSTA = 8;
		static const uint CPTCMT = 9;

	public:
		Tag(const string& Cpt = "", const string& CptTit = "", const string& CptPrj = "", const string& CptDim = "", const string& CptTpl = "", const string& CptSup = "", const string& CptDsn = "", const string& CptSta = "", const string& CptCmt = "");

	public:
		string Cpt;
		string CptTit;
		string CptPrj;
		string CptDim;
		string CptTpl;
		string CptSup;
		string CptDsn;
		string CptSta;
		string CptCmt;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppPlnrClcDetailData)
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
		* DpchAppDo (full: DpchAppPlnrClcDetailDo)
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
		* DpchEngData (full: DpchEngPlnrClcDetailData)
		*/
	class DpchEngData : public DpchEngPlnr {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTIAC = 2;
		static const uint CONTINF = 3;
		static const uint FEEDFPUPDIM = 4;
		static const uint STATAPP = 5;
		static const uint STATSHR = 6;
		static const uint TAG = 7;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Feed feedFPupDim;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

