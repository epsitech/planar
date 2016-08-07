/**
  * \file PlnrLRMArcguideMVertex.h
  * database access for table TblPlnrLRMArcguideMVertex (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRLRMARCGUIDEMVERTEX_H
#define PLNRLRMARCGUIDEMVERTEX_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * PlnrLRMArcguideMVertex: record of TblPlnrLRMArcguideMVertex
  */
class PlnrLRMArcguideMVertex {

public:
	PlnrLRMArcguideMVertex(const ubigint ref = 0, const uint agdIxPlnrVLat = 0, const ubigint agdRefPlnrMArcguide = 0, const uint agdNum = 0, const ubigint refPlnrMVertex = 0);

public:
	ubigint ref;
	uint agdIxPlnrVLat;
	ubigint agdRefPlnrMArcguide;
	uint agdNum;
	ubigint refPlnrMVertex;

public:
	bool operator==(const PlnrLRMArcguideMVertex& comp);
	bool operator!=(const PlnrLRMArcguideMVertex& comp);
};

/**
  * ListPlnrLRMArcguideMVertex: recordset of TblPlnrLRMArcguideMVertex
  */
class ListPlnrLRMArcguideMVertex {

public:
	ListPlnrLRMArcguideMVertex();
	ListPlnrLRMArcguideMVertex(const ListPlnrLRMArcguideMVertex& src);
	~ListPlnrLRMArcguideMVertex();

	void clear();
	unsigned int size() const;
	void append(PlnrLRMArcguideMVertex* rec);

	PlnrLRMArcguideMVertex* operator[](const uint ix);
	ListPlnrLRMArcguideMVertex& operator=(const ListPlnrLRMArcguideMVertex& src);
	bool operator==(const ListPlnrLRMArcguideMVertex& comp);
	bool operator!=(const ListPlnrLRMArcguideMVertex& comp);

public:
	vector<PlnrLRMArcguideMVertex*> nodes;
};

/**
  * TblPlnrLRMArcguideMVertex: C++ wrapper for table TblPlnrLRMArcguideMVertex
  */
class TblPlnrLRMArcguideMVertex {

public:
	TblPlnrLRMArcguideMVertex();
	virtual ~TblPlnrLRMArcguideMVertex();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrLRMArcguideMVertex** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrLRMArcguideMVertex& rst);

	virtual void insertRec(PlnrLRMArcguideMVertex* rec);
	ubigint insertNewRec(PlnrLRMArcguideMVertex** rec = NULL, const uint agdIxPlnrVLat = 0, const ubigint agdRefPlnrMArcguide = 0, const uint agdNum = 0, const ubigint refPlnrMVertex = 0);
	ubigint appendNewRecToRst(ListPlnrLRMArcguideMVertex& rst, PlnrLRMArcguideMVertex** rec = NULL, const uint agdIxPlnrVLat = 0, const ubigint agdRefPlnrMArcguide = 0, const uint agdNum = 0, const ubigint refPlnrMVertex = 0);
	virtual void insertRst(ListPlnrLRMArcguideMVertex& rst, bool transact = false);
	virtual void updateRec(PlnrLRMArcguideMVertex* rec);
	virtual void updateRst(ListPlnrLRMArcguideMVertex& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, PlnrLRMArcguideMVertex** rec);
	virtual ubigint loadRstByAgd(ubigint agdRefPlnrMArcguide, const bool append, ListPlnrLRMArcguideMVertex& rst);
	virtual ubigint loadRstByVtx(ubigint refPlnrMVertex, const bool append, ListPlnrLRMArcguideMVertex& rst);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListPlnrLRMArcguideMVertex& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrLRMArcguideMVertex: C++ wrapper for table TblPlnrLRMArcguideMVertex (MySQL database)
  */
class MyTblPlnrLRMArcguideMVertex : public TblPlnrLRMArcguideMVertex, public MyTable {

public:
	MyTblPlnrLRMArcguideMVertex();
	~MyTblPlnrLRMArcguideMVertex();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrLRMArcguideMVertex** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrLRMArcguideMVertex& rst);

	void insertRec(PlnrLRMArcguideMVertex* rec);
	void insertRst(ListPlnrLRMArcguideMVertex& rst, bool transact = false);
	void updateRec(PlnrLRMArcguideMVertex* rec);
	void updateRst(ListPlnrLRMArcguideMVertex& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrLRMArcguideMVertex** rec);
	ubigint loadRstByAgd(ubigint agdRefPlnrMArcguide, const bool append, ListPlnrLRMArcguideMVertex& rst);
	ubigint loadRstByVtx(ubigint refPlnrMVertex, const bool append, ListPlnrLRMArcguideMVertex& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrLRMArcguideMVertex: C++ wrapper for table TblPlnrLRMArcguideMVertex (PgSQL database)
  */
class PgTblPlnrLRMArcguideMVertex : public TblPlnrLRMArcguideMVertex, public PgTable {

public:
	PgTblPlnrLRMArcguideMVertex();
	~PgTblPlnrLRMArcguideMVertex();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrLRMArcguideMVertex** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrLRMArcguideMVertex& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrLRMArcguideMVertex** rec);
// IP pgLoadRstByStmt --- BEGIN
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrLRMArcguideMVertex& rst);
// IP pgLoadRstByStmt --- END

public:
	bool loadRecBySQL(const string& sqlstr, PlnrLRMArcguideMVertex** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrLRMArcguideMVertex& rst);

	void insertRec(PlnrLRMArcguideMVertex* rec);
	void insertRst(ListPlnrLRMArcguideMVertex& rst, bool transact = false);
	void updateRec(PlnrLRMArcguideMVertex* rec);
	void updateRst(ListPlnrLRMArcguideMVertex& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrLRMArcguideMVertex** rec);
	ubigint loadRstByAgd(ubigint agdRefPlnrMArcguide, const bool append, ListPlnrLRMArcguideMVertex& rst);
	ubigint loadRstByVtx(ubigint refPlnrMVertex, const bool append, ListPlnrLRMArcguideMVertex& rst);
};
// IP pgTbl --- END

#endif

