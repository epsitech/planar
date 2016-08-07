/**
  * \file CrdPlnrClc.h
  * app access code for job CrdPlnrClc (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef CRDPLNRCLC_H
#define CRDPLNRCLC_H

#include "AppPlnr_blks.h"

/**
  * CrdPlnrClc
  */
namespace CrdPlnrClc {
	/**
		* VecVDo (full: VecVPlnrClcDo)
		*/
	class VecVDo {

	public:
		static const uint CLOSE = 1;
		static const uint MITAPPABTCLICK = 2;
		static const uint MITCRDUCSCLICK = 3;
		static const uint MITCRDGPVCLICK = 4;
		static const uint MITCRDETXCLICK = 5;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
		* VecVSge (full: VecVPlnrClcSge)
		*/
	class VecVSge {

	public:
		static const uint IDLE = 1;
		static const uint ALRPLNRABT = 2;
		static const uint CLOSE = 3;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContInf (full: ContInfPlnrClc)
	  */
	class ContInf : public Block {

	public:
		static const uint NUMFSGE = 1;
		static const uint MRLAPPHLP = 2;
		static const uint MTXCRDCLC = 3;

	public:
		ContInf(const uint numFSge = 1, const string& MrlAppHlp = "", const string& MtxCrdClc = "");

	public:
		uint numFSge;
		string MrlAppHlp;
		string MtxCrdClc;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppPlnrClc)
	  */
	class StatApp : public Block {

	public:
		static const uint IXPLNRVREQITMODE = 1;
		static const uint LATENCY = 2;
		static const uint SHORTMENU = 3;
		static const uint WIDTHMENU = 4;
		static const uint INITDONEHEADBAR = 5;
		static const uint INITDONELIST = 6;
		static const uint INITDONEREC = 7;

	public:
		StatApp(const uint ixPlnrVReqitmode = VecPlnrVReqitmode::IDLE, const usmallint latency = 5, const string& shortMenu = "", const uint widthMenu = 0, const bool initdoneHeadbar = false, const bool initdoneList = false, const bool initdoneRec = false);

	public:
		uint ixPlnrVReqitmode;
		usmallint latency;
		string shortMenu;
		uint widthMenu;
		bool initdoneHeadbar;
		bool initdoneList;
		bool initdoneRec;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatApp* comp);
		set<uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrPlnrClc)
	  */
	class StatShr : public Block {

	public:
		static const uint SCRJREFDLGEXPRTX = 1;
		static const uint SCRJREFDLGGENRPV = 2;
		static const uint SCRJREFDLGUSECASE = 3;
		static const uint SCRJREFHEADBAR = 4;
		static const uint SCRJREFLIST = 5;
		static const uint SCRJREFREC = 6;
		static const uint MSPCRD1AVAIL = 7;
		static const uint MITCRDUCSAVAIL = 8;
		static const uint MITCRDGPVAVAIL = 9;
		static const uint MITCRDGPVACTIVE = 10;
		static const uint MITCRDETXAVAIL = 11;
		static const uint MITCRDETXACTIVE = 12;

	public:
		StatShr(const string& scrJrefDlgexprtx = "", const string& scrJrefDlggenrpv = "", const string& scrJrefDlgusecase = "", const string& scrJrefHeadbar = "", const string& scrJrefList = "", const string& scrJrefRec = "", const bool MspCrd1Avail = true, const bool MitCrdUcsAvail = true, const bool MitCrdGpvAvail = true, const bool MitCrdGpvActive = true, const bool MitCrdEtxAvail = true, const bool MitCrdEtxActive = true);

	public:
		string scrJrefDlgexprtx;
		string scrJrefDlggenrpv;
		string scrJrefDlgusecase;
		string scrJrefHeadbar;
		string scrJrefList;
		string scrJrefRec;
		bool MspCrd1Avail;
		bool MitCrdUcsAvail;
		bool MitCrdGpvAvail;
		bool MitCrdGpvActive;
		bool MitCrdEtxAvail;
		bool MitCrdEtxActive;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagPlnrClc)
	  */
	class Tag : public Block {

	public:
		static const uint MITAPPABT = 1;
		static const uint MRLAPPHLP = 2;
		static const uint MITCRDUCS = 3;
		static const uint MITCRDGPV = 4;
		static const uint MITCRDETX = 5;

	public:
		Tag(const string& MitAppAbt = "", const string& MrlAppHlp = "", const string& MitCrdUcs = "", const string& MitCrdGpv = "", const string& MitCrdEtx = "");

	public:
		string MitAppAbt;
		string MrlAppHlp;
		string MitCrdUcs;
		string MitCrdGpv;
		string MitCrdEtx;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppPlnrClcDo)
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
		* DpchEngData (full: DpchEngPlnrClcData)
		*/
	class DpchEngData : public DpchEngPlnr {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTINF = 2;
		static const uint FEEDFSGE = 3;
		static const uint STATAPP = 4;
		static const uint STATSHR = 5;
		static const uint TAG = 6;

	public:
		DpchEngData();

	public:
		ContInf continf;
		Feed feedFSge;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

