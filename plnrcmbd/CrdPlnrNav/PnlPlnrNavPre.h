/**
  * \file PnlPlnrNavPre.h
  * job handler for job PnlPlnrNavPre (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PNLPLNRNAVPRE_H
#define PNLPLNRNAVPRE_H

// IP custInclude --- INSERT

/**
  * PnlPlnrNavPre
  */
class PnlPlnrNavPre : public JobPlnr {

public:
	/**
		* VecVDo (full: VecVPlnrNavPreDo)
		*/
	class VecVDo {

	public:
		static const uint BUTDSNREMOVECLICK = 1;
		static const uint BUTPRJREMOVECLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContInf (full: ContInfPlnrNavPre)
	  */
	class ContInf : public Block {

	public:
		static const uint TXTDSN = 1;
		static const uint TXTPRJ = 2;

	public:
		ContInf(const string& TxtDsn = "", const string& TxtPrj = "");

	public:
		string TxtDsn;
		string TxtPrj;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
		* StatShr (full: StatShrPlnrNavPre)
		*/
	class StatShr : public Block {

	public:
		static const uint TXTDSNAVAIL = 1;
		static const uint TXTPRJAVAIL = 2;

	public:
		StatShr(const bool TxtDsnAvail = true, const bool TxtPrjAvail = true);

	public:
		bool TxtDsnAvail;
		bool TxtPrjAvail;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagPlnrNavPre)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixPlnrVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppPlnrNavPreDo)
		*/
	class DpchAppDo : public DpchAppPlnr {

	public:
		static const uint JREF = 1;
		static const uint IXVDO = 2;

	public:
		DpchAppDo();

	public:
		uint ixVDo;

	public:
		void readXML(pthread_mutex_t* mScr, map<string,ubigint>& descr, xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngData (full: DpchEngPlnrNavPreData)
		*/
	class DpchEngData : public DpchEngPlnr {

	public:
		static const uint JREF = 1;
		static const uint CONTINF = 2;
		static const uint STATSHR = 3;
		static const uint TAG = 4;
		static const uint ALL = 5;

	public:
		DpchEngData(const ubigint jref = 0, ContInf* continf = NULL, StatShr* statshr = NULL, const set<uint>& mask = {NONE});

	public:
		ContInf continf;
		StatShr statshr;

	public:
		void merge(DpchEngPlnr* dpcheng);
		void writeXML(const uint ixPlnrVLocale, pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
	};

	bool evalTxtDsnAvail(DbsPlnr* dbsplnr);
	bool evalTxtPrjAvail(DbsPlnr* dbsplnr);

public:
// IP constructor --- BEGIN
	PnlPlnrNavPre(XchgPlnr* xchg, DbsPlnr* dbsplnr, const ubigint jrefSup, const uint ixPlnrVLocale);
// IP constructor --- END
	~PnlPlnrNavPre();

public:
	ContInf continf;
	StatShr statshr;

	bool muteRefresh;

// IP custVar --- INSERT

public:
// IP cust --- INSERT

public:
	DpchEngPlnr* getNewDpchEng(set<uint> items);

	void refresh(DbsPlnr* dbsplnr, set<uint>& moditems);

	void updatePreset(DbsPlnr* dbsplnr, const uint ixPlnrVPreset, const ubigint jrefTrig, const bool notif = false);

public:

	void handleRequest(DbsPlnr* dbsplnr, ReqPlnr* req);

	void handleDpchAppPlnrInit(DbsPlnr* dbsplnr, DpchAppPlnrInit* dpchappplnrinit, DpchEngPlnr** dpcheng);

	void handleDpchAppDoButDsnRemoveClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);
	void handleDpchAppDoButPrjRemoveClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);

};

#endif


