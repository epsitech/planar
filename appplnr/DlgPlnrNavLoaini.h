/**
  * \file DlgPlnrNavLoaini.h
  * app access code for job DlgPlnrNavLoaini (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef DLGPLNRNAVLOAINI_H
#define DLGPLNRNAVLOAINI_H

#include "AppPlnr_blks.h"

/**
  * DlgPlnrNavLoaini
  */
namespace DlgPlnrNavLoaini {
	/**
		* VecVDit (full: VecVDlgPlnrNavLoainiDit)
		*/
	class VecVDit {

	public:
		static const uint IFI = 1;
		static const uint IMP = 2;
		static const uint ACV = 3;
		static const uint PPR = 4;
		static const uint LFI = 5;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
		* VecVDo (full: VecVDlgPlnrNavLoainiDo)
		*/
	class VecVDo {

	public:
		static const uint BUTDNECLICK = 1;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
		* VecVDoImp (full: VecVDlgPlnrNavLoainiDoImp)
		*/
	class VecVDoImp {

	public:
		static const uint BUTRUNCLICK = 1;
		static const uint BUTSTOCLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
		* VecVDoPpr (full: VecVDlgPlnrNavLoainiDoPpr)
		*/
	class VecVDoPpr {

	public:
		static const uint BUTRUNCLICK = 1;
		static const uint BUTSTOCLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
		* VecVSge (full: VecVDlgPlnrNavLoainiSge)
		*/
	class VecVSge {

	public:
		static const uint IDLE = 1;
		static const uint PRSIDLE = 2;
		static const uint PARSE = 3;
		static const uint ALRPLNRPER = 4;
		static const uint PRSDONE = 5;
		static const uint IMPIDLE = 6;
		static const uint IMPORT = 7;
		static const uint IMPDONE = 8;
		static const uint UPKIDLE = 9;
		static const uint UNPACK = 10;
		static const uint UPKDONE = 11;
		static const uint POSTPRC = 12;
		static const uint DONE = 13;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacDlgPlnrNavLoaini)
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
	  * ContInf (full: ContInfDlgPlnrNavLoaini)
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
	  * ContInfImp (full: ContInfDlgPlnrNavLoainiImp)
	  */
	class ContInfImp : public Block {

	public:
		static const uint TXTPRG = 1;

	public:
		ContInfImp(const string& TxtPrg = "");

	public:
		string TxtPrg;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const ContInfImp* comp);
		set<uint> diff(const ContInfImp* comp);
	};

	/**
	  * ContInfPpr (full: ContInfDlgPlnrNavLoainiPpr)
	  */
	class ContInfPpr : public Block {

	public:
		static const uint TXTPRG = 1;

	public:
		ContInfPpr(const string& TxtPrg = "");

	public:
		string TxtPrg;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const ContInfPpr* comp);
		set<uint> diff(const ContInfPpr* comp);
	};

	/**
	  * StatApp (full: StatAppDlgPlnrNavLoaini)
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
	  * StatShr (full: StatShrDlgPlnrNavLoaini)
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
	  * StatShrAcv (full: StatShrDlgPlnrNavLoainiAcv)
	  */
	class StatShrAcv : public Block {

	public:
		static const uint ULDACTIVE = 1;

	public:
		StatShrAcv(const bool UldActive = true);

	public:
		bool UldActive;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShrAcv* comp);
		set<uint> diff(const StatShrAcv* comp);
	};

	/**
	  * StatShrIfi (full: StatShrDlgPlnrNavLoainiIfi)
	  */
	class StatShrIfi : public Block {

	public:
		static const uint ULDACTIVE = 1;

	public:
		StatShrIfi(const bool UldActive = true);

	public:
		bool UldActive;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShrIfi* comp);
		set<uint> diff(const StatShrIfi* comp);
	};

	/**
	  * StatShrImp (full: StatShrDlgPlnrNavLoainiImp)
	  */
	class StatShrImp : public Block {

	public:
		static const uint BUTRUNACTIVE = 1;
		static const uint BUTSTOACTIVE = 2;

	public:
		StatShrImp(const bool ButRunActive = true, const bool ButStoActive = true);

	public:
		bool ButRunActive;
		bool ButStoActive;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShrImp* comp);
		set<uint> diff(const StatShrImp* comp);
	};

	/**
	  * StatShrLfi (full: StatShrDlgPlnrNavLoainiLfi)
	  */
	class StatShrLfi : public Block {

	public:
		static const uint DLDACTIVE = 1;

	public:
		StatShrLfi(const bool DldActive = true);

	public:
		bool DldActive;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShrLfi* comp);
		set<uint> diff(const StatShrLfi* comp);
	};

	/**
	  * StatShrPpr (full: StatShrDlgPlnrNavLoainiPpr)
	  */
	class StatShrPpr : public Block {

	public:
		static const uint BUTRUNACTIVE = 1;
		static const uint BUTSTOACTIVE = 2;

	public:
		StatShrPpr(const bool ButRunActive = true, const bool ButStoActive = true);

	public:
		bool ButRunActive;
		bool ButStoActive;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShrPpr* comp);
		set<uint> diff(const StatShrPpr* comp);
	};

	/**
	  * Tag (full: TagDlgPlnrNavLoaini)
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
	  * TagAcv (full: TagDlgPlnrNavLoainiAcv)
	  */
	class TagAcv : public Block {

	public:
		static const uint ULD = 1;
		static const uint CPT = 2;

	public:
		TagAcv(const string& Uld = "", const string& Cpt = "");

	public:
		string Uld;
		string Cpt;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
	  * TagIfi (full: TagDlgPlnrNavLoainiIfi)
	  */
	class TagIfi : public Block {

	public:
		static const uint ULD = 1;
		static const uint CPT = 2;

	public:
		TagIfi(const string& Uld = "", const string& Cpt = "");

	public:
		string Uld;
		string Cpt;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
	  * TagImp (full: TagDlgPlnrNavLoainiImp)
	  */
	class TagImp : public Block {

	public:
		static const uint CPTPRG = 1;
		static const uint BUTRUN = 2;
		static const uint BUTSTO = 3;

	public:
		TagImp(const string& CptPrg = "", const string& ButRun = "", const string& ButSto = "");

	public:
		string CptPrg;
		string ButRun;
		string ButSto;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
	  * TagLfi (full: TagDlgPlnrNavLoainiLfi)
	  */
	class TagLfi : public Block {

	public:
		static const uint DLD = 1;

	public:
		TagLfi(const string& Dld = "");

	public:
		string Dld;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
	  * TagPpr (full: TagDlgPlnrNavLoainiPpr)
	  */
	class TagPpr : public Block {

	public:
		static const uint CPTPRG = 1;
		static const uint BUTRUN = 2;
		static const uint BUTSTO = 3;

	public:
		TagPpr(const string& CptPrg = "", const string& ButRun = "", const string& ButSto = "");

	public:
		string CptPrg;
		string ButRun;
		string ButSto;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppDlgPlnrNavLoainiData)
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
		* DpchAppDo (full: DpchAppDlgPlnrNavLoainiDo)
		*/
	class DpchAppDo : public DpchAppPlnr {

	public:
		static const uint SCRJREF = 1;
		static const uint IXVDO = 2;
		static const uint IXVDOIMP = 3;
		static const uint IXVDOPPR = 4;
		static const uint ALL = 5;

	public:
		DpchAppDo(const string& scrJref = "", const uint ixVDo = 0, const uint ixVDoImp = 0, const uint ixVDoPpr = 0, const set<uint>& mask = {NONE});

	public:
		uint ixVDo;
		uint ixVDoImp;
		uint ixVDoPpr;

	public:
		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchEngData (full: DpchEngDlgPlnrNavLoainiData)
		*/
	class DpchEngData : public DpchEngPlnr {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTIAC = 2;
		static const uint CONTINF = 3;
		static const uint CONTINFIMP = 4;
		static const uint CONTINFPPR = 5;
		static const uint FEEDFDSE = 6;
		static const uint FEEDFSGE = 7;
		static const uint STATAPP = 8;
		static const uint STATSHR = 9;
		static const uint STATSHRACV = 10;
		static const uint STATSHRIFI = 11;
		static const uint STATSHRIMP = 12;
		static const uint STATSHRLFI = 13;
		static const uint STATSHRPPR = 14;
		static const uint TAG = 15;
		static const uint TAGACV = 16;
		static const uint TAGIFI = 17;
		static const uint TAGIMP = 18;
		static const uint TAGLFI = 19;
		static const uint TAGPPR = 20;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		ContInfImp continfimp;
		ContInfPpr continfppr;
		Feed feedFDse;
		Feed feedFSge;
		StatApp statapp;
		StatShr statshr;
		StatShrAcv statshracv;
		StatShrIfi statshrifi;
		StatShrImp statshrimp;
		StatShrLfi statshrlfi;
		StatShrPpr statshrppr;
		Tag tag;
		TagAcv tagacv;
		TagIfi tagifi;
		TagImp tagimp;
		TagLfi taglfi;
		TagPpr tagppr;

	public:
		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

