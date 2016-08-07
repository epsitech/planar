/**
  * \file PnlPlnrArrKEnvKey.h
  * app access code for job PnlPlnrArrKEnvKey (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PNLPLNRARRKENVKEY_H
#define PNLPLNRARRKENVKEY_H

#include "AppPlnr_blks.h"

#include "PlnrQArrKEnvKey.h"

#include "QryPlnrArrKEnvKey.h"

/**
  * PnlPlnrArrKEnvKey
  */
namespace PnlPlnrArrKEnvKey {
	/**
		* VecVDo (full: VecVPlnrArrKEnvKeyDo)
		*/
	class VecVDo {

	public:
		static const uint BUTUPCLICK = 1;
		static const uint BUTDOWNCLICK = 2;
		static const uint BUTNEWCLICK = 3;
		static const uint BUTDUPLICATECLICK = 4;
		static const uint BUTDELETECLICK = 5;
		static const uint BUTREFRESHCLICK = 6;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContInf (full: ContInfPlnrArrKEnvKey)
	  */
	class ContInf : public Block {

	public:
		static const uint NUMFCSIQST = 1;

	public:
		ContInf(const uint numFCsiQst = 1);

	public:
		uint numFCsiQst;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppPlnrArrKEnvKey)
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
	  * StatShr (full: StatShrPlnrArrKEnvKey)
	  */
	class StatShr : public Block {

	public:
		static const uint BUTUPACTIVE = 1;
		static const uint BUTDOWNACTIVE = 2;
		static const uint BUTDUPLICATEACTIVE = 3;
		static const uint BUTDELETEACTIVE = 4;

	public:
		StatShr(const bool ButUpActive = true, const bool ButDownActive = true, const bool ButDuplicateActive = true, const bool ButDeleteActive = true);

	public:
		bool ButUpActive;
		bool ButDownActive;
		bool ButDuplicateActive;
		bool ButDeleteActive;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * StgIac (full: StgIacPlnrArrKEnvKey)
	  */
	class StgIac : public Block {

	public:
		static const uint TCOFIXWIDTH = 1;
		static const uint TCOSRFWIDTH = 2;
		static const uint TCOAVLWIDTH = 3;
		static const uint TCOIMPWIDTH = 4;
		static const uint TCOTITWIDTH = 5;
		static const uint TCOCMTWIDTH = 6;

	public:
		StgIac(const uint TcoFixWidth = 100, const uint TcoSrfWidth = 100, const uint TcoAvlWidth = 100, const uint TcoImpWidth = 100, const uint TcoTitWidth = 100, const uint TcoCmtWidth = 100);

	public:
		uint TcoFixWidth;
		uint TcoSrfWidth;
		uint TcoAvlWidth;
		uint TcoImpWidth;
		uint TcoTitWidth;
		uint TcoCmtWidth;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StgIac* comp);
		set<uint> diff(const StgIac* comp);
	};

	/**
	  * Tag (full: TagPlnrArrKEnvKey)
	  */
	class Tag : public Block {

	public:
		static const uint CPT = 1;
		static const uint TRS = 2;
		static const uint TXTSHOWING1 = 3;
		static const uint TXTSHOWING2 = 4;
		static const uint TCOFIX = 5;
		static const uint TCOSRF = 6;
		static const uint TCOAVL = 7;
		static const uint TCOIMP = 8;
		static const uint TCOTIT = 9;
		static const uint TCOCMT = 10;

	public:
		Tag(const string& Cpt = "", const string& Trs = "", const string& TxtShowing1 = "", const string& TxtShowing2 = "", const string& TcoFix = "", const string& TcoSrf = "", const string& TcoAvl = "", const string& TcoImp = "", const string& TcoTit = "", const string& TcoCmt = "");

	public:
		string Cpt;
		string Trs;
		string TxtShowing1;
		string TxtShowing2;
		string TcoFix;
		string TcoSrf;
		string TcoAvl;
		string TcoImp;
		string TcoTit;
		string TcoCmt;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppPlnrArrKEnvKeyData)
		*/
	class DpchAppData : public DpchAppPlnr {

	public:
		static const uint SCRJREF = 1;
		static const uint STGIAC = 2;
		static const uint STGIACQRY = 3;
		static const uint ALL = 4;

	public:
		DpchAppData(const string& scrJref = "", StgIac* stgiac = NULL, QryPlnrArrKEnvKey::StgIac* stgiacqry = NULL, const set<uint>& mask = {NONE});

	public:
		StgIac stgiac;
		QryPlnrArrKEnvKey::StgIac stgiacqry;

	public:
		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchAppDo (full: DpchAppPlnrArrKEnvKeyDo)
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
		* DpchEngData (full: DpchEngPlnrArrKEnvKeyData)
		*/
	class DpchEngData : public DpchEngPlnr {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTINF = 2;
		static const uint FEEDFCSIQST = 3;
		static const uint STATAPP = 4;
		static const uint STATSHR = 5;
		static const uint STGIAC = 6;
		static const uint TAG = 7;
		static const uint RST = 8;
		static const uint STATAPPQRY = 9;
		static const uint STATSHRQRY = 10;
		static const uint STGIACQRY = 11;

	public:
		DpchEngData();

	public:
		ContInf continf;
		Feed feedFCsiQst;
		StatApp statapp;
		StatShr statshr;
		StgIac stgiac;
		Tag tag;
		ListPlnrQArrKEnvKey rst;
		QryPlnrArrKEnvKey::StatApp statappqry;
		QryPlnrArrKEnvKey::StatShr statshrqry;
		QryPlnrArrKEnvKey::StgIac stgiacqry;

	public:
		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

