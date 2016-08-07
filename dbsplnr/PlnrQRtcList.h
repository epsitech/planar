/**
  * \file PlnrQRtcList.h
  * Dbs and XML wrapper for table TblPlnrQRtcList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQRTCLIST_H
#define PLNRQRTCLIST_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQRtcList: record of TblPlnrQRtcList
  */
class PlnrQRtcList {

public:
	PlnrQRtcList(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string sref = "", const uint hkIxVTbl = 0, const string srefHkIxVTbl = "", const string titHkIxVTbl = "", const ubigint hkUref = 0, const string stubHkUref = "", const ubigint refPlnrMDesign = 0, const string stubRefPlnrMDesign = "", const ubigint refPlnrMLayer = 0, const string stubRefPlnrMLayer = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	string sref;
	uint hkIxVTbl;
	string srefHkIxVTbl;
	string titHkIxVTbl;
	ubigint hkUref;
	string stubHkUref;
	ubigint refPlnrMDesign;
	string stubRefPlnrMDesign;
	ubigint refPlnrMLayer;
	string stubRefPlnrMLayer;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListPlnrQRtcList: recordset of TblPlnrQRtcList
  */
class ListPlnrQRtcList {

public:
	ListPlnrQRtcList();
	ListPlnrQRtcList(const ListPlnrQRtcList& src);
	~ListPlnrQRtcList();

	void clear();
	unsigned int size() const;
	void append(PlnrQRtcList* rec);

	ListPlnrQRtcList& operator=(const ListPlnrQRtcList& src);

public:
	vector<PlnrQRtcList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblPlnrQRtcList: C++ wrapper for table TblPlnrQRtcList
  */
class TblPlnrQRtcList {

public:
	TblPlnrQRtcList();
	virtual ~TblPlnrQRtcList();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrQRtcList** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQRtcList& rst);

	virtual void insertRec(PlnrQRtcList* rec);
	ubigint insertNewRec(PlnrQRtcList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string sref = "", const uint hkIxVTbl = 0, const string srefHkIxVTbl = "", const string titHkIxVTbl = "", const ubigint hkUref = 0, const string stubHkUref = "", const ubigint refPlnrMDesign = 0, const string stubRefPlnrMDesign = "", const ubigint refPlnrMLayer = 0, const string stubRefPlnrMLayer = "");
	ubigint appendNewRecToRst(ListPlnrQRtcList& rst, PlnrQRtcList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string sref = "", const uint hkIxVTbl = 0, const string srefHkIxVTbl = "", const string titHkIxVTbl = "", const ubigint hkUref = 0, const string stubHkUref = "", const ubigint refPlnrMDesign = 0, const string stubRefPlnrMDesign = "", const ubigint refPlnrMLayer = 0, const string stubRefPlnrMLayer = "");
	virtual void insertRst(ListPlnrQRtcList& rst);
	virtual void updateRec(PlnrQRtcList* rec);
	virtual void updateRst(ListPlnrQRtcList& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, PlnrQRtcList** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQRtcList& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrQRtcList: C++ wrapper for table TblPlnrQRtcList (MySQL database)
  */
class MyTblPlnrQRtcList : public TblPlnrQRtcList, public MyTable {

public:
	MyTblPlnrQRtcList();
	~MyTblPlnrQRtcList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQRtcList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQRtcList& rst);

	void insertRec(PlnrQRtcList* rec);
	void insertRst(ListPlnrQRtcList& rst);
	void updateRec(PlnrQRtcList* rec);
	void updateRst(ListPlnrQRtcList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQRtcList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQRtcList& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrQRtcList: C++ wrapper for table TblPlnrQRtcList (PgSQL database)
  */
class PgTblPlnrQRtcList : public TblPlnrQRtcList, public PgTable {

public:
	PgTblPlnrQRtcList();
	~PgTblPlnrQRtcList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrQRtcList** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrQRtcList& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrQRtcList** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrQRtcList& rst);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQRtcList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQRtcList& rst);

	void insertRec(PlnrQRtcList* rec);
	void insertRst(ListPlnrQRtcList& rst);
	void updateRec(PlnrQRtcList* rec);
	void updateRst(ListPlnrQRtcList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQRtcList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQRtcList& rst);
};
// IP pgTbl --- END

#endif

