/**
  * \file PlnrQArrList.h
  * Dbs and XML wrapper for table TblPlnrQArrList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQARRLIST_H
#define PLNRQARRLIST_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQArrList: record of TblPlnrQArrList
  */
class PlnrQArrList {

public:
	PlnrQArrList(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string sref = "", const ubigint refPlnrMTapeout = 0, const string stubRefPlnrMTapeout = "", const ubigint refPlnrMDesign = 0, const string stubRefPlnrMDesign = "", const usmallint I = 0, const usmallint J = 0, const usmallint K = 0, const usmallint L = 0, const usmallint M = 0, const usmallint N = 0);

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	string sref;
	ubigint refPlnrMTapeout;
	string stubRefPlnrMTapeout;
	ubigint refPlnrMDesign;
	string stubRefPlnrMDesign;
	usmallint I;
	usmallint J;
	usmallint K;
	usmallint L;
	usmallint M;
	usmallint N;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListPlnrQArrList: recordset of TblPlnrQArrList
  */
class ListPlnrQArrList {

public:
	ListPlnrQArrList();
	ListPlnrQArrList(const ListPlnrQArrList& src);
	~ListPlnrQArrList();

	void clear();
	unsigned int size() const;
	void append(PlnrQArrList* rec);

	ListPlnrQArrList& operator=(const ListPlnrQArrList& src);

public:
	vector<PlnrQArrList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblPlnrQArrList: C++ wrapper for table TblPlnrQArrList
  */
class TblPlnrQArrList {

public:
	TblPlnrQArrList();
	virtual ~TblPlnrQArrList();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrQArrList** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQArrList& rst);

	virtual void insertRec(PlnrQArrList* rec);
	ubigint insertNewRec(PlnrQArrList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string sref = "", const ubigint refPlnrMTapeout = 0, const string stubRefPlnrMTapeout = "", const ubigint refPlnrMDesign = 0, const string stubRefPlnrMDesign = "", const usmallint I = 0, const usmallint J = 0, const usmallint K = 0, const usmallint L = 0, const usmallint M = 0, const usmallint N = 0);
	ubigint appendNewRecToRst(ListPlnrQArrList& rst, PlnrQArrList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string sref = "", const ubigint refPlnrMTapeout = 0, const string stubRefPlnrMTapeout = "", const ubigint refPlnrMDesign = 0, const string stubRefPlnrMDesign = "", const usmallint I = 0, const usmallint J = 0, const usmallint K = 0, const usmallint L = 0, const usmallint M = 0, const usmallint N = 0);
	virtual void insertRst(ListPlnrQArrList& rst);
	virtual void updateRec(PlnrQArrList* rec);
	virtual void updateRst(ListPlnrQArrList& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, PlnrQArrList** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQArrList& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrQArrList: C++ wrapper for table TblPlnrQArrList (MySQL database)
  */
class MyTblPlnrQArrList : public TblPlnrQArrList, public MyTable {

public:
	MyTblPlnrQArrList();
	~MyTblPlnrQArrList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQArrList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQArrList& rst);

	void insertRec(PlnrQArrList* rec);
	void insertRst(ListPlnrQArrList& rst);
	void updateRec(PlnrQArrList* rec);
	void updateRst(ListPlnrQArrList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQArrList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQArrList& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrQArrList: C++ wrapper for table TblPlnrQArrList (PgSQL database)
  */
class PgTblPlnrQArrList : public TblPlnrQArrList, public PgTable {

public:
	PgTblPlnrQArrList();
	~PgTblPlnrQArrList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrQArrList** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrQArrList& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrQArrList** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrQArrList& rst);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQArrList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQArrList& rst);

	void insertRec(PlnrQArrList* rec);
	void insertRst(ListPlnrQArrList& rst);
	void updateRec(PlnrQArrList* rec);
	void updateRst(ListPlnrQArrList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQArrList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQArrList& rst);
};
// IP pgTbl --- END

#endif

