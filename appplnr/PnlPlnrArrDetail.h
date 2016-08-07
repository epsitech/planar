/**
  * \file PnlPlnrArrDetail.h
  * app access code for job PnlPlnrArrDetail (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PNLPLNRARRDETAIL_H
#define PNLPLNRARRDETAIL_H

#include "AppPlnr_blks.h"

/**
  * PnlPlnrArrDetail
  */
namespace PnlPlnrArrDetail {
	/**
		* VecVDo (full: VecVPlnrArrDetailDo)
		*/
	class VecVDo {

	public:
		static const uint BUTSAVECLICK = 1;
		static const uint BUTTPOVIEWCLICK = 2;
		static const uint BUTDSNVIEWCLICK = 3;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacPlnrArrDetail)
	  */
	class ContIac : public Block {

	public:
		static const uint TXFI = 1;
		static const uint TXFJ = 2;
		static const uint TXFDI = 3;
		static const uint TXFDJ = 4;
		static const uint TXFK = 5;
		static const uint TXFL = 6;
		static const uint TXFDK = 7;
		static const uint TXFDL = 8;
		static const uint TXFM = 9;
		static const uint TXFN = 10;
		static const uint TXFDM = 11;
		static const uint TXFDN = 12;

	public:
		ContIac(const string& TxfI = "", const string& TxfJ = "", const string& TxfDi = "", const string& TxfDj = "", const string& TxfK = "", const string& TxfL = "", const string& TxfDk = "", const string& TxfDl = "", const string& TxfM = "", const string& TxfN = "", const string& TxfDm = "", const string& TxfDn = "");

	public:
		string TxfI;
		string TxfJ;
		string TxfDi;
		string TxfDj;
		string TxfK;
		string TxfL;
		string TxfDk;
		string TxfDl;
		string TxfM;
		string TxfN;
		string TxfDm;
		string TxfDn;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfPlnrArrDetail)
	  */
	class ContInf : public Block {

	public:
		static const uint TXTSRF = 1;
		static const uint TXTTPO = 2;
		static const uint TXTDSN = 3;

	public:
		ContInf(const string& TxtSrf = "", const string& TxtTpo = "", const string& TxtDsn = "");

	public:
		string TxtSrf;
		string TxtTpo;
		string TxtDsn;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppPlnrArrDetail)
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
	  * StatShr (full: StatShrPlnrArrDetail)
	  */
	class StatShr : public Block {

	public:
		static const uint BUTSAVEAVAIL = 1;
		static const uint BUTSAVEACTIVE = 2;
		static const uint BUTTPOVIEWAVAIL = 3;
		static const uint BUTDSNVIEWAVAIL = 4;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool ButTpoViewAvail = true, const bool ButDsnViewAvail = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool ButTpoViewAvail;
		bool ButDsnViewAvail;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagPlnrArrDetail)
	  */
	class Tag : public Block {

	public:
		static const uint CPT = 1;
		static const uint CPTSRF = 2;
		static const uint CPTTPO = 3;
		static const uint CPTDSN = 4;
		static const uint CPTI = 5;
		static const uint CPTJ = 6;
		static const uint CPTDI = 7;
		static const uint CPTDJ = 8;
		static const uint CPTK = 9;
		static const uint CPTL = 10;
		static const uint CPTDK = 11;
		static const uint CPTDL = 12;
		static const uint CPTM = 13;
		static const uint CPTN = 14;
		static const uint CPTDM = 15;
		static const uint CPTDN = 16;

	public:
		Tag(const string& Cpt = "", const string& CptSrf = "", const string& CptTpo = "", const string& CptDsn = "", const string& CptI = "", const string& CptJ = "", const string& CptDi = "", const string& CptDj = "", const string& CptK = "", const string& CptL = "", const string& CptDk = "", const string& CptDl = "", const string& CptM = "", const string& CptN = "", const string& CptDm = "", const string& CptDn = "");

	public:
		string Cpt;
		string CptSrf;
		string CptTpo;
		string CptDsn;
		string CptI;
		string CptJ;
		string CptDi;
		string CptDj;
		string CptK;
		string CptL;
		string CptDk;
		string CptDl;
		string CptM;
		string CptN;
		string CptDm;
		string CptDn;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppPlnrArrDetailData)
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
		* DpchAppDo (full: DpchAppPlnrArrDetailDo)
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
		* DpchEngData (full: DpchEngPlnrArrDetailData)
		*/
	class DpchEngData : public DpchEngPlnr {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTIAC = 2;
		static const uint CONTINF = 3;
		static const uint STATAPP = 4;
		static const uint STATSHR = 5;
		static const uint TAG = 6;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

