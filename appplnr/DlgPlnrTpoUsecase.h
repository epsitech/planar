/**
  * \file DlgPlnrTpoUsecase.h
  * app access code for job DlgPlnrTpoUsecase (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef DLGPLNRTPOUSECASE_H
#define DLGPLNRTPOUSECASE_H

#include "AppPlnr_blks.h"

/**
  * DlgPlnrTpoUsecase
  */
namespace DlgPlnrTpoUsecase {
	/**
		* VecVDit (full: VecVDlgPlnrTpoUsecaseDit)
		*/
	class VecVDit {

	public:
		static const uint PRP = 1;
		static const uint GEN = 2;
		static const uint CFI = 3;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
		* VecVDo (full: VecVDlgPlnrTpoUsecaseDo)
		*/
	class VecVDo {

	public:
		static const uint BUTDNECLICK = 1;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
		* VecVDoGen (full: VecVDlgPlnrTpoUsecaseDoGen)
		*/
	class VecVDoGen {

	public:
		static const uint BUTRUNCLICK = 1;
		static const uint BUTSTOCLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
		* VecVDoPrp (full: VecVDlgPlnrTpoUsecaseDoPrp)
		*/
	class VecVDoPrp {

	public:
		static const uint BUTCRECLICK = 1;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
		* VecVSge (full: VecVDlgPlnrTpoUsecaseSge)
		*/
	class VecVSge {

	public:
		static const uint IDLE = 1;
		static const uint CREATE = 2;
		static const uint CREDONE = 3;
		static const uint RUN = 4;
		static const uint DONE = 5;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
		* VecVUcs (full: VecVDlgPlnrTpoUsecaseUcs)
		*/
	class VecVUcs {

	public:
		static const uint EXAMPLES = 1;
		static const uint ICABATCH1 = 2;
		static const uint ICABATCH2 = 3;
		static const uint ICABATCH3 = 4;
		static const uint UVSLIDES = 5;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacDlgPlnrTpoUsecase)
	  */
	class ContIac : public Block {

	public:
		static const uint NUMFDSE = 1;

	public:
		ContIac(const uint numFDse = 1);

	public:
		uint numFDse;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * ContIacPrp (full: ContIacDlgPlnrTpoUsecasePrp)
	  */
	class ContIacPrp : public Block {

	public:
		static const uint TXFPTI = 1;
		static const uint NUMFPUPUCS = 2;

	public:
		ContIacPrp(const string& TxfPti = "", const uint numFPupUcs = 1);

	public:
		string TxfPti;
		uint numFPupUcs;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIacPrp* comp);
		set<uint> diff(const ContIacPrp* comp);
	};

	/**
	  * ContInf (full: ContInfDlgPlnrTpoUsecase)
	  */
	class ContInf : public Block {

	public:
		static const uint NUMFSGE = 1;

	public:
		ContInf(const uint numFSge = 1);

	public:
		uint numFSge;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
	  * ContInfGen (full: ContInfDlgPlnrTpoUsecaseGen)
	  */
	class ContInfGen : public Block {

	public:
		static const uint TXTPRG = 1;

	public:
		ContInfGen(const string& TxtPrg = "");

	public:
		string TxtPrg;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const ContInfGen* comp);
		set<uint> diff(const ContInfGen* comp);
	};

	/**
	  * StatApp (full: StatAppDlgPlnrTpoUsecase)
	  */
	class StatApp : public Block {

	public:
		static const uint INITDONE = 1;
		static const uint SHORTMENU = 2;

	public:
		StatApp(const bool initdone = false, const string& shortMenu = "");

	public:
		bool initdone;
		string shortMenu;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatApp* comp);
		set<uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrDlgPlnrTpoUsecase)
	  */
	class StatShr : public Block {

	public:
		static const uint BUTDNEACTIVE = 1;

	public:
		StatShr(const bool ButDneActive = true);

	public:
		bool ButDneActive;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * StatShrCfi (full: StatShrDlgPlnrTpoUsecaseCfi)
	  */
	class StatShrCfi : public Block {

	public:
		static const uint DLDACTIVE = 1;

	public:
		StatShrCfi(const bool DldActive = true);

	public:
		bool DldActive;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShrCfi* comp);
		set<uint> diff(const StatShrCfi* comp);
	};

	/**
	  * StatShrGen (full: StatShrDlgPlnrTpoUsecaseGen)
	  */
	class StatShrGen : public Block {

	public:
		static const uint BUTRUNACTIVE = 1;
		static const uint BUTSTOACTIVE = 2;

	public:
		StatShrGen(const bool ButRunActive = true, const bool ButStoActive = true);

	public:
		bool ButRunActive;
		bool ButStoActive;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShrGen* comp);
		set<uint> diff(const StatShrGen* comp);
	};

	/**
	  * StatShrPrp (full: StatShrDlgPlnrTpoUsecasePrp)
	  */
	class StatShrPrp : public Block {

	public:
		static const uint BUTCREACTIVE = 1;

	public:
		StatShrPrp(const bool ButCreActive = true);

	public:
		bool ButCreActive;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShrPrp* comp);
		set<uint> diff(const StatShrPrp* comp);
	};

	/**
	  * Tag (full: TagDlgPlnrTpoUsecase)
	  */
	class Tag : public Block {

	public:
		static const uint CPT = 1;
		static const uint BUTDNE = 2;

	public:
		Tag(const string& Cpt = "", const string& ButDne = "");

	public:
		string Cpt;
		string ButDne;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
	  * TagCfi (full: TagDlgPlnrTpoUsecaseCfi)
	  */
	class TagCfi : public Block {

	public:
		static const uint DLD = 1;

	public:
		TagCfi(const string& Dld = "");

	public:
		string Dld;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
	  * TagGen (full: TagDlgPlnrTpoUsecaseGen)
	  */
	class TagGen : public Block {

	public:
		static const uint CPTPRG = 1;
		static const uint BUTRUN = 2;
		static const uint BUTSTO = 3;

	public:
		TagGen(const string& CptPrg = "", const string& ButRun = "", const string& ButSto = "");

	public:
		string CptPrg;
		string ButRun;
		string ButSto;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
	  * TagPrp (full: TagDlgPlnrTpoUsecasePrp)
	  */
	class TagPrp : public Block {

	public:
		static const uint CPTPTI = 1;
		static const uint CPTUCS = 2;
		static const uint BUTCRE = 3;

	public:
		TagPrp(const string& CptPti = "", const string& CptUcs = "", const string& ButCre = "");

	public:
		string CptPti;
		string CptUcs;
		string ButCre;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppDlgPlnrTpoUsecaseData)
		*/
	class DpchAppData : public DpchAppPlnr {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTIAC = 2;
		static const uint CONTIACPRP = 3;
		static const uint ALL = 4;

	public:
		DpchAppData(const string& scrJref = "", ContIac* contiac = NULL, ContIacPrp* contiacprp = NULL, const set<uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContIacPrp contiacprp;

	public:
		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchAppDo (full: DpchAppDlgPlnrTpoUsecaseDo)
		*/
	class DpchAppDo : public DpchAppPlnr {

	public:
		static const uint SCRJREF = 1;
		static const uint IXVDO = 2;
		static const uint IXVDOGEN = 3;
		static const uint IXVDOPRP = 4;
		static const uint ALL = 5;

	public:
		DpchAppDo(const string& scrJref = "", const uint ixVDo = 0, const uint ixVDoGen = 0, const uint ixVDoPrp = 0, const set<uint>& mask = {NONE});

	public:
		uint ixVDo;
		uint ixVDoGen;
		uint ixVDoPrp;

	public:
		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchEngData (full: DpchEngDlgPlnrTpoUsecaseData)
		*/
	class DpchEngData : public DpchEngPlnr {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTIAC = 2;
		static const uint CONTIACPRP = 3;
		static const uint CONTINF = 4;
		static const uint CONTINFGEN = 5;
		static const uint FEEDFDSE = 6;
		static const uint FEEDFPRPPUPUCS = 7;
		static const uint FEEDFSGE = 8;
		static const uint STATAPP = 9;
		static const uint STATSHR = 10;
		static const uint STATSHRCFI = 11;
		static const uint STATSHRGEN = 12;
		static const uint STATSHRPRP = 13;
		static const uint TAG = 14;
		static const uint TAGCFI = 15;
		static const uint TAGGEN = 16;
		static const uint TAGPRP = 17;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContIacPrp contiacprp;
		ContInf continf;
		ContInfGen continfgen;
		Feed feedFDse;
		Feed feedFPrpPupUcs;
		Feed feedFSge;
		StatApp statapp;
		StatShr statshr;
		StatShrCfi statshrcfi;
		StatShrGen statshrgen;
		StatShrPrp statshrprp;
		Tag tag;
		TagCfi tagcfi;
		TagGen taggen;
		TagPrp tagprp;

	public:
		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

