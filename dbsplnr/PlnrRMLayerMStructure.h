/**
  * \file PlnrRMLayerMStructure.h
  * database access for table TblPlnrRMLayerMStructure (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRRMLAYERMSTRUCTURE_H
#define PLNRRMLAYERMSTRUCTURE_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * PlnrRMLayerMStructure: record of TblPlnrRMLayerMStructure
  */
class PlnrRMLayerMStructure {

public:
	PlnrRMLayerMStructure(const ubigint ref = 0, const ubigint refPlnrMLayer = 0, const ubigint refPlnrMStructure = 0);

public:
	ubigint ref;
	ubigint refPlnrMLayer;
	ubigint refPlnrMStructure;

public:
	bool operator==(const PlnrRMLayerMStructure& comp);
	bool operator!=(const PlnrRMLayerMStructure& comp);
};

/**
  * ListPlnrRMLayerMStructure: recordset of TblPlnrRMLayerMStructure
  */
class ListPlnrRMLayerMStructure {

public:
	ListPlnrRMLayerMStructure();
	ListPlnrRMLayerMStructure(const ListPlnrRMLayerMStructure& src);
	~ListPlnrRMLayerMStructure();

	void clear();
	unsigned int size() const;
	void append(PlnrRMLayerMStructure* rec);

	PlnrRMLayerMStructure* operator[](const uint ix);
	ListPlnrRMLayerMStructure& operator=(const ListPlnrRMLayerMStructure& src);
	bool operator==(const ListPlnrRMLayerMStructure& comp);
	bool operator!=(const ListPlnrRMLayerMStructure& comp);

public:
	vector<PlnrRMLayerMStructure*> nodes;
};

/**
  * TblPlnrRMLayerMStructure: C++ wrapper for table TblPlnrRMLayerMStructure
  */
class TblPlnrRMLayerMStructure {

public:
	TblPlnrRMLayerMStructure();
	virtual ~TblPlnrRMLayerMStructure();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrRMLayerMStructure** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrRMLayerMStructure& rst);

	virtual void insertRec(PlnrRMLayerMStructure* rec);
	ubigint insertNewRec(PlnrRMLayerMStructure** rec = NULL, const ubigint refPlnrMLayer = 0, const ubigint refPlnrMStructure = 0);
	ubigint appendNewRecToRst(ListPlnrRMLayerMStructure& rst, PlnrRMLayerMStructure** rec = NULL, const ubigint refPlnrMLayer = 0, const ubigint refPlnrMStructure = 0);
	virtual void insertRst(ListPlnrRMLayerMStructure& rst, bool transact = false);
	virtual void updateRec(PlnrRMLayerMStructure* rec);
	virtual void updateRst(ListPlnrRMLayerMStructure& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, PlnrRMLayerMStructure** rec);
	virtual ubigint loadRstByLyr(ubigint refPlnrMLayer, const bool append, ListPlnrRMLayerMStructure& rst);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListPlnrRMLayerMStructure& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrRMLayerMStructure: C++ wrapper for table TblPlnrRMLayerMStructure (MySQL database)
  */
class MyTblPlnrRMLayerMStructure : public TblPlnrRMLayerMStructure, public MyTable {

public:
	MyTblPlnrRMLayerMStructure();
	~MyTblPlnrRMLayerMStructure();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrRMLayerMStructure** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrRMLayerMStructure& rst);

	void insertRec(PlnrRMLayerMStructure* rec);
	void insertRst(ListPlnrRMLayerMStructure& rst, bool transact = false);
	void updateRec(PlnrRMLayerMStructure* rec);
	void updateRst(ListPlnrRMLayerMStructure& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrRMLayerMStructure** rec);
	ubigint loadRstByLyr(ubigint refPlnrMLayer, const bool append, ListPlnrRMLayerMStructure& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrRMLayerMStructure: C++ wrapper for table TblPlnrRMLayerMStructure (PgSQL database)
  */
class PgTblPlnrRMLayerMStructure : public TblPlnrRMLayerMStructure, public PgTable {

public:
	PgTblPlnrRMLayerMStructure();
	~PgTblPlnrRMLayerMStructure();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrRMLayerMStructure** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrRMLayerMStructure& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrRMLayerMStructure** rec);
// IP pgLoadRstByStmt --- BEGIN
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrRMLayerMStructure& rst);
// IP pgLoadRstByStmt --- END

public:
	bool loadRecBySQL(const string& sqlstr, PlnrRMLayerMStructure** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrRMLayerMStructure& rst);

	void insertRec(PlnrRMLayerMStructure* rec);
	void insertRst(ListPlnrRMLayerMStructure& rst, bool transact = false);
	void updateRec(PlnrRMLayerMStructure* rec);
	void updateRst(ListPlnrRMLayerMStructure& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrRMLayerMStructure** rec);
	ubigint loadRstByLyr(ubigint refPlnrMLayer, const bool append, ListPlnrRMLayerMStructure& rst);
};
// IP pgTbl --- END

#endif

