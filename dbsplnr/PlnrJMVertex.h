/**
  * \file PlnrJMVertex.h
  * database access for table TblPlnrJMVertex (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRJMVERTEX_H
#define PLNRJMVERTEX_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * PlnrJMVertex: record of TblPlnrJMVertex
  */
class PlnrJMVertex {

public:
	PlnrJMVertex(const ubigint ref = 0, const ubigint refPlnrMVertex = 0, const ubigint x1RefPlnrMDesign = 0, const double x = 0.0, const double y = 0.0);

public:
	ubigint ref;
	ubigint refPlnrMVertex;
	ubigint x1RefPlnrMDesign;
	double x;
	double y;

public:
	bool operator==(const PlnrJMVertex& comp);
	bool operator!=(const PlnrJMVertex& comp);
};

/**
  * ListPlnrJMVertex: recordset of TblPlnrJMVertex
  */
class ListPlnrJMVertex {

public:
	ListPlnrJMVertex();
	ListPlnrJMVertex(const ListPlnrJMVertex& src);
	~ListPlnrJMVertex();

	void clear();
	unsigned int size() const;
	void append(PlnrJMVertex* rec);

	PlnrJMVertex* operator[](const uint ix);
	ListPlnrJMVertex& operator=(const ListPlnrJMVertex& src);
	bool operator==(const ListPlnrJMVertex& comp);
	bool operator!=(const ListPlnrJMVertex& comp);

public:
	vector<PlnrJMVertex*> nodes;
};

/**
  * TblPlnrJMVertex: C++ wrapper for table TblPlnrJMVertex
  */
class TblPlnrJMVertex {

public:
	TblPlnrJMVertex();
	virtual ~TblPlnrJMVertex();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrJMVertex** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrJMVertex& rst);

	virtual void insertRec(PlnrJMVertex* rec);
	ubigint insertNewRec(PlnrJMVertex** rec = NULL, const ubigint refPlnrMVertex = 0, const ubigint x1RefPlnrMDesign = 0, const double x = 0.0, const double y = 0.0);
	ubigint appendNewRecToRst(ListPlnrJMVertex& rst, PlnrJMVertex** rec = NULL, const ubigint refPlnrMVertex = 0, const ubigint x1RefPlnrMDesign = 0, const double x = 0.0, const double y = 0.0);
	virtual void insertRst(ListPlnrJMVertex& rst, bool transact = false);
	virtual void updateRec(PlnrJMVertex* rec);
	virtual void updateRst(ListPlnrJMVertex& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, PlnrJMVertex** rec);
	virtual bool loadRecByVtxDsn(ubigint refPlnrMVertex, ubigint x1RefPlnrMDesign, PlnrJMVertex** rec);
	virtual ubigint loadRstByVtx(ubigint refPlnrMVertex, const bool append, ListPlnrJMVertex& rst);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListPlnrJMVertex& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrJMVertex: C++ wrapper for table TblPlnrJMVertex (MySQL database)
  */
class MyTblPlnrJMVertex : public TblPlnrJMVertex, public MyTable {

public:
	MyTblPlnrJMVertex();
	~MyTblPlnrJMVertex();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrJMVertex** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrJMVertex& rst);

	void insertRec(PlnrJMVertex* rec);
	void insertRst(ListPlnrJMVertex& rst, bool transact = false);
	void updateRec(PlnrJMVertex* rec);
	void updateRst(ListPlnrJMVertex& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrJMVertex** rec);
	bool loadRecByVtxDsn(ubigint refPlnrMVertex, ubigint x1RefPlnrMDesign, PlnrJMVertex** rec);
	ubigint loadRstByVtx(ubigint refPlnrMVertex, const bool append, ListPlnrJMVertex& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrJMVertex: C++ wrapper for table TblPlnrJMVertex (PgSQL database)
  */
class PgTblPlnrJMVertex : public TblPlnrJMVertex, public PgTable {

public:
	PgTblPlnrJMVertex();
	~PgTblPlnrJMVertex();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrJMVertex** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrJMVertex& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrJMVertex** rec);
// IP pgLoadRstByStmt --- BEGIN
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrJMVertex& rst);
// IP pgLoadRstByStmt --- END

public:
	bool loadRecBySQL(const string& sqlstr, PlnrJMVertex** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrJMVertex& rst);

	void insertRec(PlnrJMVertex* rec);
	void insertRst(ListPlnrJMVertex& rst, bool transact = false);
	void updateRec(PlnrJMVertex* rec);
	void updateRst(ListPlnrJMVertex& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrJMVertex** rec);
	bool loadRecByVtxDsn(ubigint refPlnrMVertex, ubigint x1RefPlnrMDesign, PlnrJMVertex** rec);
	ubigint loadRstByVtx(ubigint refPlnrMVertex, const bool append, ListPlnrJMVertex& rst);
};
// IP pgTbl --- END

#endif

