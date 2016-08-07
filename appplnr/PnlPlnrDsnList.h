/**
  * \file PnlPlnrDsnList.h
  * app access code for job PnlPlnrDsnList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PNLPLNRDSNLIST_H
#define PNLPLNRDSNLIST_H

#include "AppPlnr_blks.h"

#include "PlnrQDsnList.h"

#include "QryPlnrDsnList.h"

/**
  * PnlPlnrDsnList
  */
namespace PnlPlnrDsnList {
	/**
		* VecVDo (full: VecVPlnrDsnListDo)
		*/
	class VecVDo {

	public:
		static const uint BUTMINIMIZECLICK = 1;
		static const uint BUTREGULARIZECLICK = 2;
		static const uint BUTNEWCLICK = 3;
		static const uint BUTDELETECLICK = 4;
		static const uint BUTFILTERCLICK = 5;
		static const uint BUTREFRESHCLICK = 6;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacPlnrDsnList)
	  */
	class ContIac : public Block {

	public:
		static const uint NUMFTOS = 1;

	public:
		ContIac(const uint numFTos = 1);

	public:
		uint numFTos;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfPlnrDsnList)
	  */
	class ContInf : public Block {

	public:
		static const uint TXTFOR = 1;
		static const uint TXTPRE = 2;
		static const uint BUTFILTERON = 3;
		static const uint NUMFCSIQST = 4;

	public:
		ContInf(const string& TxtFor = "", const string& TxtPre = "", const bool ButFilterOn = false, const uint numFCsiQst = 1);

	public:
		string TxtFor;
		string TxtPre;
		bool ButFilterOn;
		uint numFCsiQst;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
	  * StatShr (full: StatShrPlnrDsnList)
	  */
	class StatShr : public Block {

	public:
		static const uint IXPLNRVEXPSTATE = 1;
		static const uint BUTDELETEACTIVE = 2;

	public:
		StatShr(const uint ixPlnrVExpstate = VecPlnrVExpstate::MIND, const bool ButDeleteActive = true);

	public:
		uint ixPlnrVExpstate;
		bool ButDeleteActive;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * StgIac (full: StgIacPlnrDsnList)
	  */
	class StgIac : public Block {

	public:
		static const uint TCOTITWIDTH = 1;
		static const uint TCOTYPWIDTH = 2;
		static const uint TCODIMWIDTH = 3;
		static const uint TCORETWIDTH = 4;
		static const uint TCOREUWIDTH = 5;
		static const uint TCOPRJWIDTH = 6;
		static const uint TCOMTYWIDTH = 7;
		static const uint TCOMODWIDTH = 8;
		static const uint TCODRVWIDTH = 9;
		static const uint TCOMAJWIDTH = 10;
		static const uint TCOSUBWIDTH = 11;

	public:
		StgIac(const uint TcoTitWidth = 100, const uint TcoTypWidth = 100, const uint TcoDimWidth = 100, const uint TcoRetWidth = 100, const uint TcoReuWidth = 100, const uint TcoPrjWidth = 100, const uint TcoMtyWidth = 100, const uint TcoModWidth = 100, const uint TcoDrvWidth = 100, const uint TcoMajWidth = 100, const uint TcoSubWidth = 100);

	public:
		uint TcoTitWidth;
		uint TcoTypWidth;
		uint TcoDimWidth;
		uint TcoRetWidth;
		uint TcoReuWidth;
		uint TcoPrjWidth;
		uint TcoMtyWidth;
		uint TcoModWidth;
		uint TcoDrvWidth;
		uint TcoMajWidth;
		uint TcoSubWidth;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StgIac* comp);
		set<uint> diff(const StgIac* comp);
	};

	/**
	  * Tag (full: TagPlnrDsnList)
	  */
	class Tag : public Block {

	public:
		static const uint CPT = 1;
		static const uint TXTFOR = 2;
		static const uint TRS = 3;
		static const uint TXTSHOWING1 = 4;
		static const uint TXTSHOWING2 = 5;
		static const uint TCOTIT = 6;
		static const uint TCOTYP = 7;
		static const uint TCODIM = 8;
		static const uint TCORET = 9;
		static const uint TCOREU = 10;
		static const uint TCOPRJ = 11;
		static const uint TCOMTY = 12;
		static const uint TCOMOD = 13;
		static const uint TCODRV = 14;
		static const uint TCOMAJ = 15;
		static const uint TCOSUB = 16;

	public:
		Tag(const string& Cpt = "", const string& TxtFor = "", const string& Trs = "", const string& TxtShowing1 = "", const string& TxtShowing2 = "", const string& TcoTit = "", const string& TcoTyp = "", const string& TcoDim = "", const string& TcoRet = "", const string& TcoReu = "", const string& TcoPrj = "", const string& TcoMty = "", const string& TcoMod = "", const string& TcoDrv = "", const string& TcoMaj = "", const string& TcoSub = "");

	public:
		string Cpt;
		string TxtFor;
		string Trs;
		string TxtShowing1;
		string TxtShowing2;
		string TcoTit;
		string TcoTyp;
		string TcoDim;
		string TcoRet;
		string TcoReu;
		string TcoPrj;
		string TcoMty;
		string TcoMod;
		string TcoDrv;
		string TcoMaj;
		string TcoSub;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppPlnrDsnListData)
		*/
	class DpchAppData : public DpchAppPlnr {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTIAC = 2;
		static const uint STGIAC = 3;
		static const uint STGIACQRY = 4;
		static const uint ALL = 5;

	public:
		DpchAppData(const string& scrJref = "", ContIac* contiac = NULL, StgIac* stgiac = NULL, QryPlnrDsnList::StgIac* stgiacqry = NULL, const set<uint>& mask = {NONE});

	public:
		ContIac contiac;
		StgIac stgiac;
		QryPlnrDsnList::StgIac stgiacqry;

	public:
		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchAppDo (full: DpchAppPlnrDsnListDo)
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
		* DpchEngData (full: DpchEngPlnrDsnListData)
		*/
	class DpchEngData : public DpchEngPlnr {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTIAC = 2;
		static const uint CONTINF = 3;
		static const uint FEEDFCSIQST = 4;
		static const uint FEEDFTOS = 5;
		static const uint STATSHR = 6;
		static const uint STGIAC = 7;
		static const uint TAG = 8;
		static const uint RST = 9;
		static const uint STATAPPQRY = 10;
		static const uint STATSHRQRY = 11;
		static const uint STGIACQRY = 12;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Feed feedFCsiQst;
		Feed feedFTos;
		StatShr statshr;
		StgIac stgiac;
		Tag tag;
		ListPlnrQDsnList rst;
		QryPlnrDsnList::StatApp statappqry;
		QryPlnrDsnList::StatShr statshrqry;
		QryPlnrDsnList::StgIac stgiacqry;

	public:
		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

