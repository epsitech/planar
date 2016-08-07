/**
  * \file PlnrMArrayitem.h
  * database access for table TblPlnrMArrayitem (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRMARRAYITEM_H
#define PLNRMARRAYITEM_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * PlnrMArrayitem: record of TblPlnrMArrayitem
  */
class PlnrMArrayitem {

public:
	PlnrMArrayitem(const ubigint ref = 0, const ubigint refPlnrMArray = 0, const ubigint refPlnrMDesign = 0, const usmallint i = 0, const usmallint j = 0, const usmallint k = 0, const usmallint l = 0, const usmallint m = 0, const usmallint n = 0, const double dx = 0.0, const double dy = 0.0);

public:
	ubigint ref;
	ubigint refPlnrMArray;
	ubigint refPlnrMDesign;
	usmallint i;
	usmallint j;
	usmallint k;
	usmallint l;
	usmallint m;
	usmallint n;
	double dx;
	double dy;

public:
	bool operator==(const PlnrMArrayitem& comp);
	bool operator!=(const PlnrMArrayitem& comp);
};

/**
  * ListPlnrMArrayitem: recordset of TblPlnrMArrayitem
  */
class ListPlnrMArrayitem {

public:
	ListPlnrMArrayitem();
	ListPlnrMArrayitem(const ListPlnrMArrayitem& src);
	~ListPlnrMArrayitem();

	void clear();
	unsigned int size() const;
	void append(PlnrMArrayitem* rec);

	PlnrMArrayitem* operator[](const uint ix);
	ListPlnrMArrayitem& operator=(const ListPlnrMArrayitem& src);
	bool operator==(const ListPlnrMArrayitem& comp);
	bool operator!=(const ListPlnrMArrayitem& comp);

public:
	vector<PlnrMArrayitem*> nodes;
};

/**
  * TblPlnrMArrayitem: C++ wrapper for table TblPlnrMArrayitem
  */
class TblPlnrMArrayitem {

public:
	TblPlnrMArrayitem();
	virtual ~TblPlnrMArrayitem();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrMArrayitem** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrMArrayitem& rst);

	virtual void insertRec(PlnrMArrayitem* rec);
	ubigint insertNewRec(PlnrMArrayitem** rec = NULL, const ubigint refPlnrMArray = 0, const ubigint refPlnrMDesign = 0, const usmallint i = 0, const usmallint j = 0, const usmallint k = 0, const usmallint l = 0, const usmallint m = 0, const usmallint n = 0, const double dx = 0.0, const double dy = 0.0);
	ubigint appendNewRecToRst(ListPlnrMArrayitem& rst, PlnrMArrayitem** rec = NULL, const ubigint refPlnrMArray = 0, const ubigint refPlnrMDesign = 0, const usmallint i = 0, const usmallint j = 0, const usmallint k = 0, const usmallint l = 0, const usmallint m = 0, const usmallint n = 0, const double dx = 0.0, const double dy = 0.0);
	virtual void insertRst(ListPlnrMArrayitem& rst, bool transact = false);
	virtual void updateRec(PlnrMArrayitem* rec);
	virtual void updateRst(ListPlnrMArrayitem& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, PlnrMArrayitem** rec);
	virtual ubigint loadRstByArr(ubigint refPlnrMArray, const bool append, ListPlnrMArrayitem& rst);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListPlnrMArrayitem& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrMArrayitem: C++ wrapper for table TblPlnrMArrayitem (MySQL database)
  */
class MyTblPlnrMArrayitem : public TblPlnrMArrayitem, public MyTable {

public:
	MyTblPlnrMArrayitem();
	~MyTblPlnrMArrayitem();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrMArrayitem** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrMArrayitem& rst);

	void insertRec(PlnrMArrayitem* rec);
	void insertRst(ListPlnrMArrayitem& rst, bool transact = false);
	void updateRec(PlnrMArrayitem* rec);
	void updateRst(ListPlnrMArrayitem& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrMArrayitem** rec);
	ubigint loadRstByArr(ubigint refPlnrMArray, const bool append, ListPlnrMArrayitem& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrMArrayitem: C++ wrapper for table TblPlnrMArrayitem (PgSQL database)
  */
class PgTblPlnrMArrayitem : public TblPlnrMArrayitem, public PgTable {

public:
	PgTblPlnrMArrayitem();
	~PgTblPlnrMArrayitem();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrMArrayitem** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrMArrayitem& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrMArrayitem** rec);
// IP pgLoadRstByStmt --- BEGIN
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrMArrayitem& rst);
// IP pgLoadRstByStmt --- END

public:
	bool loadRecBySQL(const string& sqlstr, PlnrMArrayitem** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrMArrayitem& rst);

	void insertRec(PlnrMArrayitem* rec);
	void insertRst(ListPlnrMArrayitem& rst, bool transact = false);
	void updateRec(PlnrMArrayitem* rec);
	void updateRst(ListPlnrMArrayitem& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrMArrayitem** rec);
	ubigint loadRstByArr(ubigint refPlnrMArray, const bool append, ListPlnrMArrayitem& rst);
};
// IP pgTbl --- END

#endif

