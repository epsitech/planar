/**
  * \file PnlPlnrSruDetail.h
  * app access code for job PnlPlnrSruDetail (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PNLPLNRSRUDETAIL_H
#define PNLPLNRSRUDETAIL_H

#include "AppPlnr_blks.h"

/**
  * PnlPlnrSruDetail
  */
namespace PnlPlnrSruDetail {
	/**
		* VecVDo (full: VecVPlnrSruDetailDo)
		*/
	class VecVDo {

	public:
		static const uint BUTSAVECLICK = 1;
		static const uint BUTHKUVIEWCLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacPlnrSruDetail)
	  */
	class ContIac : public Block {

	public:
		static const uint NUMFPUPHKT = 1;
		static const uint TXFX0 = 2;
		static const uint TXFX1 = 3;
		static const uint TXFY0 = 4;
		static const uint TXFY1 = 5;

	public:
		ContIac(const uint numFPupHkt = 1, const string& TxfX0 = "", const string& TxfX1 = "", const string& TxfY0 = "", const string& TxfY1 = "");

	public:
		uint numFPupHkt;
		string TxfX0;
		string TxfX1;
		string TxfY0;
		string TxfY1;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfPlnrSruDetail)
	  */
	class ContInf : public Block {

	public:
		static const uint TXTSRF = 1;
		static const uint TXTHKU = 2;

	public:
		ContInf(const string& TxtSrf = "", const string& TxtHku = "");

	public:
		string TxtSrf;
		string TxtHku;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppPlnrSruDetail)
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
	  * StatShr (full: StatShrPlnrSruDetail)
	  */
	class StatShr : public Block {

	public:
		static const uint BUTSAVEAVAIL = 1;
		static const uint BUTSAVEACTIVE = 2;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagPlnrSruDetail)
	  */
	class Tag : public Block {

	public:
		static const uint CPT = 1;
		static const uint CPTSRF = 2;
		static const uint CPTHKU = 3;
		static const uint CPTX0 = 4;
		static const uint CPTX1 = 5;
		static const uint CPTY0 = 6;
		static const uint CPTY1 = 7;

	public:
		Tag(const string& Cpt = "", const string& CptSrf = "", const string& CptHku = "", const string& CptX0 = "", const string& CptX1 = "", const string& CptY0 = "", const string& CptY1 = "");

	public:
		string Cpt;
		string CptSrf;
		string CptHku;
		string CptX0;
		string CptX1;
		string CptY0;
		string CptY1;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppPlnrSruDetailData)
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
		* DpchAppDo (full: DpchAppPlnrSruDetailDo)
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
		* DpchEngData (full: DpchEngPlnrSruDetailData)
		*/
	class DpchEngData : public DpchEngPlnr {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTIAC = 2;
		static const uint CONTINF = 3;
		static const uint FEEDFPUPHKT = 4;
		static const uint STATAPP = 5;
		static const uint STATSHR = 6;
		static const uint TAG = 7;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Feed feedFPupHkt;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

