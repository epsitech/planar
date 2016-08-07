/**
  * \file PnlPlnrMatDetail.h
  * app access code for job PnlPlnrMatDetail (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PNLPLNRMATDETAIL_H
#define PNLPLNRMATDETAIL_H

#include "AppPlnr_blks.h"

/**
  * PnlPlnrMatDetail
  */
namespace PnlPlnrMatDetail {
	/**
		* VecVDo (full: VecVPlnrMatDetailDo)
		*/
	class VecVDo {

	public:
		static const uint BUTSAVECLICK = 1;
		static const uint BUTSUPVIEWCLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacPlnrMatDetail)
	  */
	class ContIac : public Block {

	public:
		static const uint TXFTIT = 1;
		static const uint NUMFPUPTYP = 2;

	public:
		ContIac(const string& TxfTit = "", const uint numFPupTyp = 1);

	public:
		string TxfTit;
		uint numFPupTyp;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfPlnrMatDetail)
	  */
	class ContInf : public Block {

	public:
		static const uint TXTSRF = 1;
		static const uint TXTCAL = 2;
		static const uint TXTSUP = 3;

	public:
		ContInf(const string& TxtSrf = "", const string& TxtCal = "", const string& TxtSup = "");

	public:
		string TxtSrf;
		string TxtCal;
		string TxtSup;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppPlnrMatDetail)
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
	  * StatShr (full: StatShrPlnrMatDetail)
	  */
	class StatShr : public Block {

	public:
		static const uint BUTSAVEAVAIL = 1;
		static const uint BUTSAVEACTIVE = 2;
		static const uint BUTSUPVIEWAVAIL = 3;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool ButSupViewAvail = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool ButSupViewAvail;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagPlnrMatDetail)
	  */
	class Tag : public Block {

	public:
		static const uint CPT = 1;
		static const uint CPTSRF = 2;
		static const uint CPTTIT = 3;
		static const uint CPTTYP = 4;
		static const uint CPTCAL = 5;
		static const uint CPTSUP = 6;

	public:
		Tag(const string& Cpt = "", const string& CptSrf = "", const string& CptTit = "", const string& CptTyp = "", const string& CptCal = "", const string& CptSup = "");

	public:
		string Cpt;
		string CptSrf;
		string CptTit;
		string CptTyp;
		string CptCal;
		string CptSup;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppPlnrMatDetailData)
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
		* DpchAppDo (full: DpchAppPlnrMatDetailDo)
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
		* DpchEngData (full: DpchEngPlnrMatDetailData)
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

