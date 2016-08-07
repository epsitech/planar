/**
  * \file PlnrMReticle.h
  * database access for table TblPlnrMReticle (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRMRETICLE_H
#define PLNRMRETICLE_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * PlnrMReticle: record of TblPlnrMReticle
  */
class PlnrMReticle {

public:
	PlnrMReticle(const ubigint ref = 0, const uint hkIxVTbl = 0, const ubigint hkUref = 0, const ubigint refPlnrMDesign = 0, const ubigint refPlnrMLayer = 0, const string sref = "", const double x0 = 0.0, const double y0 = 0.0, const double phi = 0.0);

public:
	ubigint ref;
	uint hkIxVTbl;
	ubigint hkUref;
	ubigint refPlnrMDesign;
	ubigint refPlnrMLayer;
	string sref;
	double x0;
	double y0;
	double phi;

public:
	bool operator==(const PlnrMReticle& comp);
	bool operator!=(const PlnrMReticle& comp);
};

/**
  * ListPlnrMReticle: recordset of TblPlnrMReticle
  */
class ListPlnrMReticle {

public:
	ListPlnrMReticle();
	ListPlnrMReticle(const ListPlnrMReticle& src);
	~ListPlnrMReticle();

	void clear();
	unsigned int size() const;
	void append(PlnrMReticle* rec);

	PlnrMReticle* operator[](const uint ix);
	ListPlnrMReticle& operator=(const ListPlnrMReticle& src);
	bool operator==(const ListPlnrMReticle& comp);
	bool operator!=(const ListPlnrMReticle& comp);

public:
	vector<PlnrMReticle*> nodes;
};

/**
  * TblPlnrMReticle: C++ wrapper for table TblPlnrMReticle
  */
class TblPlnrMReticle {

public:
	TblPlnrMReticle();
	virtual ~TblPlnrMReticle();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrMReticle** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrMReticle& rst);

	virtual void insertRec(PlnrMReticle* rec);
	ubigint insertNewRec(PlnrMReticle** rec = NULL, const uint hkIxVTbl = 0, const ubigint hkUref = 0, const ubigint refPlnrMDesign = 0, const ubigint refPlnrMLayer = 0, const string sref = "", const double x0 = 0.0, const double y0 = 0.0, const double phi = 0.0);
	ubigint appendNewRecToRst(ListPlnrMReticle& rst, PlnrMReticle** rec = NULL, const uint hkIxVTbl = 0, const ubigint hkUref = 0, const ubigint refPlnrMDesign = 0, const ubigint refPlnrMLayer = 0, const string sref = "", const double x0 = 0.0, const double y0 = 0.0, const double phi = 0.0);
	virtual void insertRst(ListPlnrMReticle& rst, bool transact = false);
	virtual void updateRec(PlnrMReticle* rec);
	virtual void updateRst(ListPlnrMReticle& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, PlnrMReticle** rec);
	virtual ubigint loadRstByHktHku(uint hkIxVTbl, ubigint hkUref, const bool append, ListPlnrMReticle& rst);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListPlnrMReticle& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrMReticle: C++ wrapper for table TblPlnrMReticle (MySQL database)
  */
class MyTblPlnrMReticle : public TblPlnrMReticle, public MyTable {

public:
	MyTblPlnrMReticle();
	~MyTblPlnrMReticle();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrMReticle** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrMReticle& rst);

	void insertRec(PlnrMReticle* rec);
	void insertRst(ListPlnrMReticle& rst, bool transact = false);
	void updateRec(PlnrMReticle* rec);
	void updateRst(ListPlnrMReticle& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrMReticle** rec);
	ubigint loadRstByHktHku(uint hkIxVTbl, ubigint hkUref, const bool append, ListPlnrMReticle& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrMReticle: C++ wrapper for table TblPlnrMReticle (PgSQL database)
  */
class PgTblPlnrMReticle : public TblPlnrMReticle, public PgTable {

public:
	PgTblPlnrMReticle();
	~PgTblPlnrMReticle();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrMReticle** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrMReticle& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrMReticle** rec);
// IP pgLoadRstByStmt --- BEGIN
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrMReticle& rst);
// IP pgLoadRstByStmt --- END

public:
	bool loadRecBySQL(const string& sqlstr, PlnrMReticle** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrMReticle& rst);

	void insertRec(PlnrMReticle* rec);
	void insertRst(ListPlnrMReticle& rst, bool transact = false);
	void updateRec(PlnrMReticle* rec);
	void updateRst(ListPlnrMReticle& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrMReticle** rec);
	ubigint loadRstByHktHku(uint hkIxVTbl, ubigint hkUref, const bool append, ListPlnrMReticle& rst);
};
// IP pgTbl --- END

#endif

