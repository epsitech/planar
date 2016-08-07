/**
  * \file PlnrMArray.h
  * database access for table TblPlnrMArray (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRMARRAY_H
#define PLNRMARRAY_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * PlnrMArray: record of TblPlnrMArray
  */
class PlnrMArray {

public:
	PlnrMArray(const ubigint ref = 0, const ubigint refPlnrMTapeout = 0, const ubigint refPlnrMDesign = 0, const string sref = "", const usmallint I = 0, const usmallint J = 0, const double di = 0.0, const double dj = 0.0, const usmallint K = 0, const usmallint L = 0, const double dk = 0.0, const double dl = 0.0, const usmallint M = 0, const usmallint N = 0, const double dm = 0.0, const double dn = 0.0);

public:
	ubigint ref;
	ubigint refPlnrMTapeout;
	ubigint refPlnrMDesign;
	string sref;
	usmallint I;
	usmallint J;
	double di;
	double dj;
	usmallint K;
	usmallint L;
	double dk;
	double dl;
	usmallint M;
	usmallint N;
	double dm;
	double dn;

public:
	bool operator==(const PlnrMArray& comp);
	bool operator!=(const PlnrMArray& comp);
};

/**
  * ListPlnrMArray: recordset of TblPlnrMArray
  */
class ListPlnrMArray {

public:
	ListPlnrMArray();
	ListPlnrMArray(const ListPlnrMArray& src);
	~ListPlnrMArray();

	void clear();
	unsigned int size() const;
	void append(PlnrMArray* rec);

	PlnrMArray* operator[](const uint ix);
	ListPlnrMArray& operator=(const ListPlnrMArray& src);
	bool operator==(const ListPlnrMArray& comp);
	bool operator!=(const ListPlnrMArray& comp);

public:
	vector<PlnrMArray*> nodes;
};

/**
  * TblPlnrMArray: C++ wrapper for table TblPlnrMArray
  */
class TblPlnrMArray {

public:
	TblPlnrMArray();
	virtual ~TblPlnrMArray();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrMArray** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrMArray& rst);

	virtual void insertRec(PlnrMArray* rec);
	ubigint insertNewRec(PlnrMArray** rec = NULL, const ubigint refPlnrMTapeout = 0, const ubigint refPlnrMDesign = 0, const string sref = "", const usmallint I = 0, const usmallint J = 0, const double di = 0.0, const double dj = 0.0, const usmallint K = 0, const usmallint L = 0, const double dk = 0.0, const double dl = 0.0, const usmallint M = 0, const usmallint N = 0, const double dm = 0.0, const double dn = 0.0);
	ubigint appendNewRecToRst(ListPlnrMArray& rst, PlnrMArray** rec = NULL, const ubigint refPlnrMTapeout = 0, const ubigint refPlnrMDesign = 0, const string sref = "", const usmallint I = 0, const usmallint J = 0, const double di = 0.0, const double dj = 0.0, const usmallint K = 0, const usmallint L = 0, const double dk = 0.0, const double dl = 0.0, const usmallint M = 0, const usmallint N = 0, const double dm = 0.0, const double dn = 0.0);
	virtual void insertRst(ListPlnrMArray& rst, bool transact = false);
	virtual void updateRec(PlnrMArray* rec);
	virtual void updateRst(ListPlnrMArray& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, PlnrMArray** rec);
	virtual bool loadSrfByRef(ubigint ref, string& val);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListPlnrMArray& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrMArray: C++ wrapper for table TblPlnrMArray (MySQL database)
  */
class MyTblPlnrMArray : public TblPlnrMArray, public MyTable {

public:
	MyTblPlnrMArray();
	~MyTblPlnrMArray();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrMArray** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrMArray& rst);

	void insertRec(PlnrMArray* rec);
	void insertRst(ListPlnrMArray& rst, bool transact = false);
	void updateRec(PlnrMArray* rec);
	void updateRst(ListPlnrMArray& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrMArray** rec);
	bool loadSrfByRef(ubigint ref, string& val);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrMArray: C++ wrapper for table TblPlnrMArray (PgSQL database)
  */
class PgTblPlnrMArray : public TblPlnrMArray, public PgTable {

public:
	PgTblPlnrMArray();
	~PgTblPlnrMArray();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrMArray** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrMArray& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrMArray** rec);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrMArray** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrMArray& rst);

	void insertRec(PlnrMArray* rec);
	void insertRst(ListPlnrMArray& rst, bool transact = false);
	void updateRec(PlnrMArray* rec);
	void updateRst(ListPlnrMArray& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrMArray** rec);
	bool loadSrfByRef(ubigint ref, string& val);
};
// IP pgTbl --- END

#endif

