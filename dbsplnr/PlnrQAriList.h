/**
  * \file PlnrQAriList.h
  * Dbs and XML wrapper for table TblPlnrQAriList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQARILIST_H
#define PLNRQARILIST_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQAriList: record of TblPlnrQAriList
  */
class PlnrQAriList {

public:
	PlnrQAriList(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const usmallint i = 0, const usmallint j = 0, const usmallint k = 0, const usmallint l = 0, const usmallint m = 0, const usmallint n = 0, const ubigint refPlnrMArray = 0, const string stubRefPlnrMArray = "", const ubigint refPlnrMDesign = 0, const string stubRefPlnrMDesign = "", const double dx = 0.0, const double dy = 0.0);

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	usmallint i;
	usmallint j;
	usmallint k;
	usmallint l;
	usmallint m;
	usmallint n;
	ubigint refPlnrMArray;
	string stubRefPlnrMArray;
	ubigint refPlnrMDesign;
	string stubRefPlnrMDesign;
	double dx;
	double dy;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListPlnrQAriList: recordset of TblPlnrQAriList
  */
class ListPlnrQAriList {

public:
	ListPlnrQAriList();
	ListPlnrQAriList(const ListPlnrQAriList& src);
	~ListPlnrQAriList();

	void clear();
	unsigned int size() const;
	void append(PlnrQAriList* rec);

	ListPlnrQAriList& operator=(const ListPlnrQAriList& src);

public:
	vector<PlnrQAriList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblPlnrQAriList: C++ wrapper for table TblPlnrQAriList
  */
class TblPlnrQAriList {

public:
	TblPlnrQAriList();
	virtual ~TblPlnrQAriList();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrQAriList** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQAriList& rst);

	virtual void insertRec(PlnrQAriList* rec);
	ubigint insertNewRec(PlnrQAriList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const usmallint i = 0, const usmallint j = 0, const usmallint k = 0, const usmallint l = 0, const usmallint m = 0, const usmallint n = 0, const ubigint refPlnrMArray = 0, const string stubRefPlnrMArray = "", const ubigint refPlnrMDesign = 0, const string stubRefPlnrMDesign = "", const double dx = 0.0, const double dy = 0.0);
	ubigint appendNewRecToRst(ListPlnrQAriList& rst, PlnrQAriList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const usmallint i = 0, const usmallint j = 0, const usmallint k = 0, const usmallint l = 0, const usmallint m = 0, const usmallint n = 0, const ubigint refPlnrMArray = 0, const string stubRefPlnrMArray = "", const ubigint refPlnrMDesign = 0, const string stubRefPlnrMDesign = "", const double dx = 0.0, const double dy = 0.0);
	virtual void insertRst(ListPlnrQAriList& rst);
	virtual void updateRec(PlnrQAriList* rec);
	virtual void updateRst(ListPlnrQAriList& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, PlnrQAriList** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQAriList& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrQAriList: C++ wrapper for table TblPlnrQAriList (MySQL database)
  */
class MyTblPlnrQAriList : public TblPlnrQAriList, public MyTable {

public:
	MyTblPlnrQAriList();
	~MyTblPlnrQAriList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQAriList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQAriList& rst);

	void insertRec(PlnrQAriList* rec);
	void insertRst(ListPlnrQAriList& rst);
	void updateRec(PlnrQAriList* rec);
	void updateRst(ListPlnrQAriList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQAriList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQAriList& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrQAriList: C++ wrapper for table TblPlnrQAriList (PgSQL database)
  */
class PgTblPlnrQAriList : public TblPlnrQAriList, public PgTable {

public:
	PgTblPlnrQAriList();
	~PgTblPlnrQAriList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrQAriList** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrQAriList& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrQAriList** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrQAriList& rst);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQAriList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQAriList& rst);

	void insertRec(PlnrQAriList* rec);
	void insertRst(ListPlnrQAriList& rst);
	void updateRec(PlnrQAriList* rec);
	void updateRst(ListPlnrQAriList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQAriList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQAriList& rst);
};
// IP pgTbl --- END

#endif

