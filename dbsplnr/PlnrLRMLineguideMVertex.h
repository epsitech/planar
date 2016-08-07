/**
  * \file PlnrLRMLineguideMVertex.h
  * database access for table TblPlnrLRMLineguideMVertex (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRLRMLINEGUIDEMVERTEX_H
#define PLNRLRMLINEGUIDEMVERTEX_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * PlnrLRMLineguideMVertex: record of TblPlnrLRMLineguideMVertex
  */
class PlnrLRMLineguideMVertex {

public:
	PlnrLRMLineguideMVertex(const ubigint ref = 0, const uint lgdIxPlnrVLat = 0, const ubigint lgdRefPlnrMLineguide = 0, const uint lgdNum = 0, const ubigint refPlnrMVertex = 0);

public:
	ubigint ref;
	uint lgdIxPlnrVLat;
	ubigint lgdRefPlnrMLineguide;
	uint lgdNum;
	ubigint refPlnrMVertex;

public:
	bool operator==(const PlnrLRMLineguideMVertex& comp);
	bool operator!=(const PlnrLRMLineguideMVertex& comp);
};

/**
  * ListPlnrLRMLineguideMVertex: recordset of TblPlnrLRMLineguideMVertex
  */
class ListPlnrLRMLineguideMVertex {

public:
	ListPlnrLRMLineguideMVertex();
	ListPlnrLRMLineguideMVertex(const ListPlnrLRMLineguideMVertex& src);
	~ListPlnrLRMLineguideMVertex();

	void clear();
	unsigned int size() const;
	void append(PlnrLRMLineguideMVertex* rec);

	PlnrLRMLineguideMVertex* operator[](const uint ix);
	ListPlnrLRMLineguideMVertex& operator=(const ListPlnrLRMLineguideMVertex& src);
	bool operator==(const ListPlnrLRMLineguideMVertex& comp);
	bool operator!=(const ListPlnrLRMLineguideMVertex& comp);

public:
	vector<PlnrLRMLineguideMVertex*> nodes;
};

/**
  * TblPlnrLRMLineguideMVertex: C++ wrapper for table TblPlnrLRMLineguideMVertex
  */
class TblPlnrLRMLineguideMVertex {

public:
	TblPlnrLRMLineguideMVertex();
	virtual ~TblPlnrLRMLineguideMVertex();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrLRMLineguideMVertex** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrLRMLineguideMVertex& rst);

	virtual void insertRec(PlnrLRMLineguideMVertex* rec);
	ubigint insertNewRec(PlnrLRMLineguideMVertex** rec = NULL, const uint lgdIxPlnrVLat = 0, const ubigint lgdRefPlnrMLineguide = 0, const uint lgdNum = 0, const ubigint refPlnrMVertex = 0);
	ubigint appendNewRecToRst(ListPlnrLRMLineguideMVertex& rst, PlnrLRMLineguideMVertex** rec = NULL, const uint lgdIxPlnrVLat = 0, const ubigint lgdRefPlnrMLineguide = 0, const uint lgdNum = 0, const ubigint refPlnrMVertex = 0);
	virtual void insertRst(ListPlnrLRMLineguideMVertex& rst, bool transact = false);
	virtual void updateRec(PlnrLRMLineguideMVertex* rec);
	virtual void updateRst(ListPlnrLRMLineguideMVertex& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, PlnrLRMLineguideMVertex** rec);
	virtual bool loadRecByLgdVtx(ubigint lgdRefPlnrMLineguide, ubigint refPlnrMVertex, PlnrLRMLineguideMVertex** rec);
	virtual ubigint loadRstByLgd(ubigint lgdRefPlnrMLineguide, const bool append, ListPlnrLRMLineguideMVertex& rst);
	virtual ubigint loadRstByVtx(ubigint refPlnrMVertex, const bool append, ListPlnrLRMLineguideMVertex& rst);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListPlnrLRMLineguideMVertex& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrLRMLineguideMVertex: C++ wrapper for table TblPlnrLRMLineguideMVertex (MySQL database)
  */
class MyTblPlnrLRMLineguideMVertex : public TblPlnrLRMLineguideMVertex, public MyTable {

public:
	MyTblPlnrLRMLineguideMVertex();
	~MyTblPlnrLRMLineguideMVertex();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrLRMLineguideMVertex** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrLRMLineguideMVertex& rst);

	void insertRec(PlnrLRMLineguideMVertex* rec);
	void insertRst(ListPlnrLRMLineguideMVertex& rst, bool transact = false);
	void updateRec(PlnrLRMLineguideMVertex* rec);
	void updateRst(ListPlnrLRMLineguideMVertex& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrLRMLineguideMVertex** rec);
	bool loadRecByLgdVtx(ubigint lgdRefPlnrMLineguide, ubigint refPlnrMVertex, PlnrLRMLineguideMVertex** rec);
	ubigint loadRstByLgd(ubigint lgdRefPlnrMLineguide, const bool append, ListPlnrLRMLineguideMVertex& rst);
	ubigint loadRstByVtx(ubigint refPlnrMVertex, const bool append, ListPlnrLRMLineguideMVertex& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrLRMLineguideMVertex: C++ wrapper for table TblPlnrLRMLineguideMVertex (PgSQL database)
  */
class PgTblPlnrLRMLineguideMVertex : public TblPlnrLRMLineguideMVertex, public PgTable {

public:
	PgTblPlnrLRMLineguideMVertex();
	~PgTblPlnrLRMLineguideMVertex();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrLRMLineguideMVertex** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrLRMLineguideMVertex& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrLRMLineguideMVertex** rec);
// IP pgLoadRstByStmt --- BEGIN
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrLRMLineguideMVertex& rst);
// IP pgLoadRstByStmt --- END

public:
	bool loadRecBySQL(const string& sqlstr, PlnrLRMLineguideMVertex** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrLRMLineguideMVertex& rst);

	void insertRec(PlnrLRMLineguideMVertex* rec);
	void insertRst(ListPlnrLRMLineguideMVertex& rst, bool transact = false);
	void updateRec(PlnrLRMLineguideMVertex* rec);
	void updateRst(ListPlnrLRMLineguideMVertex& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrLRMLineguideMVertex** rec);
	bool loadRecByLgdVtx(ubigint lgdRefPlnrMLineguide, ubigint refPlnrMVertex, PlnrLRMLineguideMVertex** rec);
	ubigint loadRstByLgd(ubigint lgdRefPlnrMLineguide, const bool append, ListPlnrLRMLineguideMVertex& rst);
	ubigint loadRstByVtx(ubigint refPlnrMVertex, const bool append, ListPlnrLRMLineguideMVertex& rst);
};
// IP pgTbl --- END

#endif

