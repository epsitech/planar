/**
  * \file CrdPlnrNav.h
  * app access code for job CrdPlnrNav (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef CRDPLNRNAV_H
#define CRDPLNRNAV_H

#include "AppPlnr_blks.h"

/**
  * CrdPlnrNav
  */
namespace CrdPlnrNav {
	/**
		* VecVDo (full: VecVPlnrNavDo)
		*/
	class VecVDo {

	public:
		static const uint CLOSE = 1;
		static const uint MITAPPABTCLICK = 2;
		static const uint MITSESTRMCLICK = 3;
		static const uint MITCRDUSGCLICK = 4;
		static const uint MITCRDUSRCLICK = 5;
		static const uint MITCRDPRSCLICK = 6;
		static const uint MITCRDFILCLICK = 7;
		static const uint MITCRDDTPCLICK = 8;
		static const uint MITCRDCTPCLICK = 9;
		static const uint MITCRDMATCLICK = 10;
		static const uint MITCRDPRJCLICK = 11;
		static const uint MITCRDDSNCLICK = 12;
		static const uint MITCRDDOMCLICK = 13;
		static const uint MITCRDDGDCLICK = 14;
		static const uint MITCRDDVCCLICK = 15;
		static const uint MITCRDSRUCLICK = 16;
		static const uint MITCRDSTKCLICK = 17;
		static const uint MITCRDLYRCLICK = 18;
		static const uint MITCRDCLCCLICK = 19;
		static const uint MITCRDCLICLICK = 20;
		static const uint MITCRDTPOCLICK = 21;
		static const uint MITAPPLOICLICK = 22;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
		* VecVSge (full: VecVPlnrNavSge)
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
	  * ContInf (full: ContInfPlnrNav)
	  */
	class ContInf : public Block {

	public:
		static const uint NUMFSGE = 1;
		static const uint MRLAPPHLP = 2;
		static const uint MTXSESSES1 = 3;
		static const uint MTXSESSES2 = 4;
		static const uint MTXSESSES3 = 5;

	public:
		ContInf(const uint numFSge = 1, const string& MrlAppHlp = "", const string& MtxSesSes1 = "", const string& MtxSesSes2 = "", const string& MtxSesSes3 = "");

	public:
		uint numFSge;
		string MrlAppHlp;
		string MtxSesSes1;
		string MtxSesSes2;
		string MtxSesSes3;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppPlnrNav)
	  */
	class StatApp : public Block {

	public:
		static const uint IXPLNRVREQITMODE = 1;
		static const uint LATENCY = 2;
		static const uint SHORTMENU = 3;
		static const uint WIDTHMENU = 4;
		static const uint INITDONEHEADBAR = 5;
		static const uint INITDONEPRE = 6;
		static const uint INITDONEADMIN = 7;
		static const uint INITDONEGLOBAL = 8;
		static const uint INITDONEDESIGN = 9;
		static const uint INITDONECALC = 10;
		static const uint INITDONELAYOUT = 11;

	public:
		StatApp(const uint ixPlnrVReqitmode = VecPlnrVReqitmode::IDLE, const usmallint latency = 5, const string& shortMenu = "", const uint widthMenu = 0, const bool initdoneHeadbar = false, const bool initdonePre = false, const bool initdoneAdmin = false, const bool initdoneGlobal = false, const bool initdoneDesign = false, const bool initdoneCalc = false, const bool initdoneLayout = false);

	public:
		uint ixPlnrVReqitmode;
		usmallint latency;
		string shortMenu;
		uint widthMenu;
		bool initdoneHeadbar;
		bool initdonePre;
		bool initdoneAdmin;
		bool initdoneGlobal;
		bool initdoneDesign;
		bool initdoneCalc;
		bool initdoneLayout;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatApp* comp);
		set<uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrPlnrNav)
	  */
	class StatShr : public Block {

	public:
		static const uint SCRJREFDLGLOAINI = 1;
		static const uint SCRJREFHEADBAR = 2;
		static const uint SCRJREFPRE = 3;
		static const uint PNLPREAVAIL = 4;
		static const uint SCRJREFADMIN = 5;
		static const uint PNLADMINAVAIL = 6;
		static const uint SCRJREFGLOBAL = 7;
		static const uint PNLGLOBALAVAIL = 8;
		static const uint SCRJREFDESIGN = 9;
		static const uint PNLDESIGNAVAIL = 10;
		static const uint SCRJREFCALC = 11;
		static const uint PNLCALCAVAIL = 12;
		static const uint SCRJREFLAYOUT = 13;
		static const uint PNLLAYOUTAVAIL = 14;
		static const uint MSPCRD1AVAIL = 15;
		static const uint MITCRDUSGAVAIL = 16;
		static const uint MITCRDUSRAVAIL = 17;
		static const uint MITCRDPRSAVAIL = 18;
		static const uint MITCRDFILAVAIL = 19;
		static const uint MSPCRD2AVAIL = 20;
		static const uint MITCRDDTPAVAIL = 21;
		static const uint MITCRDCTPAVAIL = 22;
		static const uint MITCRDMATAVAIL = 23;
		static const uint MSPCRD3AVAIL = 24;
		static const uint MITCRDPRJAVAIL = 25;
		static const uint MITCRDDSNAVAIL = 26;
		static const uint MITCRDDOMAVAIL = 27;
		static const uint MITCRDDOMACTIVE = 28;
		static const uint MITCRDDGDAVAIL = 29;
		static const uint MITCRDDGDACTIVE = 30;
		static const uint MITCRDDVCAVAIL = 31;
		static const uint MITCRDDVCACTIVE = 32;
		static const uint MITCRDSRUAVAIL = 33;
		static const uint MITCRDSRUACTIVE = 34;
		static const uint MITCRDSTKAVAIL = 35;
		static const uint MITCRDSTKACTIVE = 36;
		static const uint MITCRDLYRAVAIL = 37;
		static const uint MITCRDLYRACTIVE = 38;
		static const uint MSPCRD4AVAIL = 39;
		static const uint MITCRDCLCAVAIL = 40;
		static const uint MITCRDCLCACTIVE = 41;
		static const uint MITCRDCLIAVAIL = 42;
		static const uint MITCRDCLIACTIVE = 43;
		static const uint MSPCRD5AVAIL = 44;
		static const uint MITCRDTPOAVAIL = 45;
		static const uint MSPAPP2AVAIL = 46;
		static const uint MITAPPLOIAVAIL = 47;

	public:
		StatShr(const string& scrJrefDlgloaini = "", const string& scrJrefHeadbar = "", const string& scrJrefPre = "", const bool pnlpreAvail = false, const string& scrJrefAdmin = "", const bool pnladminAvail = false, const string& scrJrefGlobal = "", const bool pnlglobalAvail = false, const string& scrJrefDesign = "", const bool pnldesignAvail = false, const string& scrJrefCalc = "", const bool pnlcalcAvail = false, const string& scrJrefLayout = "", const bool pnllayoutAvail = false, const bool MspCrd1Avail = true, const bool MitCrdUsgAvail = true, const bool MitCrdUsrAvail = true, const bool MitCrdPrsAvail = true, const bool MitCrdFilAvail = true, const bool MspCrd2Avail = true, const bool MitCrdDtpAvail = true, const bool MitCrdCtpAvail = true, const bool MitCrdMatAvail = true, const bool MspCrd3Avail = true, const bool MitCrdPrjAvail = true, const bool MitCrdDsnAvail = true, const bool MitCrdDomAvail = true, const bool MitCrdDomActive = true, const bool MitCrdDgdAvail = true, const bool MitCrdDgdActive = true, const bool MitCrdDvcAvail = true, const bool MitCrdDvcActive = true, const bool MitCrdSruAvail = true, const bool MitCrdSruActive = true, const bool MitCrdStkAvail = true, const bool MitCrdStkActive = true, const bool MitCrdLyrAvail = true, const bool MitCrdLyrActive = true, const bool MspCrd4Avail = true, const bool MitCrdClcAvail = true, const bool MitCrdClcActive = true, const bool MitCrdCliAvail = true, const bool MitCrdCliActive = true, const bool MspCrd5Avail = true, const bool MitCrdTpoAvail = true, const bool MspApp2Avail = true, const bool MitAppLoiAvail = true);

	public:
		string scrJrefDlgloaini;
		string scrJrefHeadbar;
		string scrJrefPre;
		bool pnlpreAvail;
		string scrJrefAdmin;
		bool pnladminAvail;
		string scrJrefGlobal;
		bool pnlglobalAvail;
		string scrJrefDesign;
		bool pnldesignAvail;
		string scrJrefCalc;
		bool pnlcalcAvail;
		string scrJrefLayout;
		bool pnllayoutAvail;
		bool MspCrd1Avail;
		bool MitCrdUsgAvail;
		bool MitCrdUsrAvail;
		bool MitCrdPrsAvail;
		bool MitCrdFilAvail;
		bool MspCrd2Avail;
		bool MitCrdDtpAvail;
		bool MitCrdCtpAvail;
		bool MitCrdMatAvail;
		bool MspCrd3Avail;
		bool MitCrdPrjAvail;
		bool MitCrdDsnAvail;
		bool MitCrdDomAvail;
		bool MitCrdDomActive;
		bool MitCrdDgdAvail;
		bool MitCrdDgdActive;
		bool MitCrdDvcAvail;
		bool MitCrdDvcActive;
		bool MitCrdSruAvail;
		bool MitCrdSruActive;
		bool MitCrdStkAvail;
		bool MitCrdStkActive;
		bool MitCrdLyrAvail;
		bool MitCrdLyrActive;
		bool MspCrd4Avail;
		bool MitCrdClcAvail;
		bool MitCrdClcActive;
		bool MitCrdCliAvail;
		bool MitCrdCliActive;
		bool MspCrd5Avail;
		bool MitCrdTpoAvail;
		bool MspApp2Avail;
		bool MitAppLoiAvail;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagPlnrNav)
	  */
	class Tag : public Block {

	public:
		static const uint MITAPPABT = 1;
		static const uint MRLAPPHLP = 2;
		static const uint MITSESTRM = 3;
		static const uint MITCRDUSG = 4;
		static const uint MITCRDUSR = 5;
		static const uint MITCRDPRS = 6;
		static const uint MITCRDFIL = 7;
		static const uint MITCRDDTP = 8;
		static const uint MITCRDCTP = 9;
		static const uint MITCRDMAT = 10;
		static const uint MITCRDPRJ = 11;
		static const uint MITCRDDSN = 12;
		static const uint MITCRDDOM = 13;
		static const uint MITCRDDGD = 14;
		static const uint MITCRDDVC = 15;
		static const uint MITCRDSRU = 16;
		static const uint MITCRDSTK = 17;
		static const uint MITCRDLYR = 18;
		static const uint MITCRDCLC = 19;
		static const uint MITCRDCLI = 20;
		static const uint MITCRDTPO = 21;
		static const uint MITAPPLOI = 22;

	public:
		Tag(const string& MitAppAbt = "", const string& MrlAppHlp = "", const string& MitSesTrm = "", const string& MitCrdUsg = "", const string& MitCrdUsr = "", const string& MitCrdPrs = "", const string& MitCrdFil = "", const string& MitCrdDtp = "", const string& MitCrdCtp = "", const string& MitCrdMat = "", const string& MitCrdPrj = "", const string& MitCrdDsn = "", const string& MitCrdDom = "", const string& MitCrdDgd = "", const string& MitCrdDvc = "", const string& MitCrdSru = "", const string& MitCrdStk = "", const string& MitCrdLyr = "", const string& MitCrdClc = "", const string& MitCrdCli = "", const string& MitCrdTpo = "", const string& MitAppLoi = "");

	public:
		string MitAppAbt;
		string MrlAppHlp;
		string MitSesTrm;
		string MitCrdUsg;
		string MitCrdUsr;
		string MitCrdPrs;
		string MitCrdFil;
		string MitCrdDtp;
		string MitCrdCtp;
		string MitCrdMat;
		string MitCrdPrj;
		string MitCrdDsn;
		string MitCrdDom;
		string MitCrdDgd;
		string MitCrdDvc;
		string MitCrdSru;
		string MitCrdStk;
		string MitCrdLyr;
		string MitCrdClc;
		string MitCrdCli;
		string MitCrdTpo;
		string MitAppLoi;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppPlnrNavDo)
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
		* DpchEngData (full: DpchEngPlnrNavData)
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

