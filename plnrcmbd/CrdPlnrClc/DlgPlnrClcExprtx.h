/**
  * \file DlgPlnrClcExprtx.h
  * job handler for job DlgPlnrClcExprtx (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef DLGPLNRCLCEXPRTX_H
#define DLGPLNRCLCEXPRTX_H

// IP custInclude --- INSERT

/**
  * DlgPlnrClcExprtx
  */
class DlgPlnrClcExprtx : public JobPlnr {

public:
	/**
		* VecVDo (full: VecVDlgPlnrClcExprtxDo)
		*/
	class VecVDo {

	public:
		static const uint BUTDNECLICK = 1;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
		* StatApp (full: StatAppDlgPlnrClcExprtx)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const string& shortMenu = "");
	};

	/**
		* Tag (full: TagDlgPlnrClcExprtx)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixPlnrVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppDlgPlnrClcExprtxDo)
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
		* DpchEngData (full: DpchEngDlgPlnrClcExprtxData)
		*/
	class DpchEngData : public DpchEngPlnr {

	public:
		static const uint JREF = 1;
		static const uint STATAPP = 2;
		static const uint TAG = 3;
		static const uint ALL = 4;

	public:
		DpchEngData(const ubigint jref = 0, const set<uint>& mask = {NONE});

	public:

	public:
		void merge(DpchEngPlnr* dpcheng);
		void writeXML(const uint ixPlnrVLocale, pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
	};

public:
// IP constructor --- BEGIN
	DlgPlnrClcExprtx(XchgPlnr* xchg, DbsPlnr* dbsplnr, const ubigint jrefSup, const uint ixPlnrVLocale);
// IP constructor --- END
	~DlgPlnrClcExprtx();

public:

	bool muteRefresh;

// IP custVar --- INSERT

public:
// IP cust --- INSERT

public:
	DpchEngPlnr* getNewDpchEng(set<uint> items);

	void refresh(DbsPlnr* dbsplnr, set<uint>& moditems);

public:

	void handleRequest(DbsPlnr* dbsplnr, ReqPlnr* req);

	void handleDpchAppPlnrInit(DbsPlnr* dbsplnr, DpchAppPlnrInit* dpchappplnrinit, DpchEngPlnr** dpcheng);

	void handleDpchAppDoButDneClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);

};

#endif


