/**
  * \file PlnrRMVertexMVertex.h
  * database access for table TblPlnrRMVertexMVertex (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRRMVERTEXMVERTEX_H
#define PLNRRMVERTEXMVERTEX_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * PlnrRMVertexMVertex: record of TblPlnrRMVertexMVertex
  */
class PlnrRMVertexMVertex {

public:
	PlnrRMVertexMVertex(const ubigint ref = 0, const ubigint devRefPlnrMVertex = 0, const ubigint dsnRefPlnrMVertex = 0);

public:
	ubigint ref;
	ubigint devRefPlnrMVertex;
	ubigint dsnRefPlnrMVertex;

public:
	bool operator==(const PlnrRMVertexMVertex& comp);
	bool operator!=(const PlnrRMVertexMVertex& comp);
};

/**
  * ListPlnrRMVertexMVertex: recordset of TblPlnrRMVertexMVertex
  */
class ListPlnrRMVertexMVertex {

public:
	ListPlnrRMVertexMVertex();
	ListPlnrRMVertexMVertex(const ListPlnrRMVertexMVertex& src);
	~ListPlnrRMVertexMVertex();

	void clear();
	unsigned int size() const;
	void append(PlnrRMVertexMVertex* rec);

	PlnrRMVertexMVertex* operator[](const uint ix);
	ListPlnrRMVertexMVertex& operator=(const ListPlnrRMVertexMVertex& src);
	bool operator==(const ListPlnrRMVertexMVertex& comp);
	bool operator!=(const ListPlnrRMVertexMVertex& comp);

public:
	vector<PlnrRMVertexMVertex*> nodes;
};

/**
  * TblPlnrRMVertexMVertex: C++ wrapper for table TblPlnrRMVertexMVertex
  */
class TblPlnrRMVertexMVertex {

public:
	TblPlnrRMVertexMVertex();
	virtual ~TblPlnrRMVertexMVertex();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrRMVertexMVertex** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrRMVertexMVertex& rst);

	virtual void insertRec(PlnrRMVertexMVertex* rec);
	ubigint insertNewRec(PlnrRMVertexMVertex** rec = NULL, const ubigint devRefPlnrMVertex = 0, const ubigint dsnRefPlnrMVertex = 0);
	ubigint appendNewRecToRst(ListPlnrRMVertexMVertex& rst, PlnrRMVertexMVertex** rec = NULL, const ubigint devRefPlnrMVertex = 0, const ubigint dsnRefPlnrMVertex = 0);
	virtual void insertRst(ListPlnrRMVertexMVertex& rst, bool transact = false);
	virtual void updateRec(PlnrRMVertexMVertex* rec);
	virtual void updateRst(ListPlnrRMVertexMVertex& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, PlnrRMVertexMVertex** rec);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListPlnrRMVertexMVertex& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrRMVertexMVertex: C++ wrapper for table TblPlnrRMVertexMVertex (MySQL database)
  */
class MyTblPlnrRMVertexMVertex : public TblPlnrRMVertexMVertex, public MyTable {

public:
	MyTblPlnrRMVertexMVertex();
	~MyTblPlnrRMVertexMVertex();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrRMVertexMVertex** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrRMVertexMVertex& rst);

	void insertRec(PlnrRMVertexMVertex* rec);
	void insertRst(ListPlnrRMVertexMVertex& rst, bool transact = false);
	void updateRec(PlnrRMVertexMVertex* rec);
	void updateRst(ListPlnrRMVertexMVertex& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrRMVertexMVertex** rec);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrRMVertexMVertex: C++ wrapper for table TblPlnrRMVertexMVertex (PgSQL database)
  */
class PgTblPlnrRMVertexMVertex : public TblPlnrRMVertexMVertex, public PgTable {

public:
	PgTblPlnrRMVertexMVertex();
	~PgTblPlnrRMVertexMVertex();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrRMVertexMVertex** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrRMVertexMVertex& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrRMVertexMVertex** rec);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrRMVertexMVertex** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrRMVertexMVertex& rst);

	void insertRec(PlnrRMVertexMVertex* rec);
	void insertRst(ListPlnrRMVertexMVertex& rst, bool transact = false);
	void updateRec(PlnrRMVertexMVertex* rec);
	void updateRst(ListPlnrRMVertexMVertex& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrRMVertexMVertex** rec);
};
// IP pgTbl --- END

#endif

