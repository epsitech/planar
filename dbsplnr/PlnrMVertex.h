/**
  * \file PlnrMVertex.h
  * database access for table TblPlnrMVertex (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRMVERTEX_H
#define PLNRMVERTEX_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * PlnrMVertex: record of TblPlnrMVertex
  */
class PlnrMVertex {

public:
	PlnrMVertex(const ubigint ref = 0, const ubigint x1RefPlnrMDesign = 0, const uint hkIxPlnrVLat = 0, const uint hkIxVTbl = 0, const ubigint hkUref = 0, const string sref = "", const double x = 0.0, const double y = 0.0);

public:
	ubigint ref;
	ubigint x1RefPlnrMDesign;
	uint hkIxPlnrVLat;
	uint hkIxVTbl;
	ubigint hkUref;
	string sref;
	double x;
	double y;

public:
	bool operator==(const PlnrMVertex& comp);
	bool operator!=(const PlnrMVertex& comp);
};

/**
  * ListPlnrMVertex: recordset of TblPlnrMVertex
  */
class ListPlnrMVertex {

public:
	ListPlnrMVertex();
	ListPlnrMVertex(const ListPlnrMVertex& src);
	~ListPlnrMVertex();

	void clear();
	unsigned int size() const;
	void append(PlnrMVertex* rec);

	PlnrMVertex* operator[](const uint ix);
	ListPlnrMVertex& operator=(const ListPlnrMVertex& src);
	bool operator==(const ListPlnrMVertex& comp);
	bool operator!=(const ListPlnrMVertex& comp);

public:
	vector<PlnrMVertex*> nodes;
};

/**
  * TblPlnrMVertex: C++ wrapper for table TblPlnrMVertex
  */
class TblPlnrMVertex {

public:
	TblPlnrMVertex();
	virtual ~TblPlnrMVertex();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrMVertex** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrMVertex& rst);

	virtual void insertRec(PlnrMVertex* rec);
	ubigint insertNewRec(PlnrMVertex** rec = NULL, const ubigint x1RefPlnrMDesign = 0, const uint hkIxPlnrVLat = 0, const uint hkIxVTbl = 0, const ubigint hkUref = 0, const string sref = "", const double x = 0.0, const double y = 0.0);
	ubigint appendNewRecToRst(ListPlnrMVertex& rst, PlnrMVertex** rec = NULL, const ubigint x1RefPlnrMDesign = 0, const uint hkIxPlnrVLat = 0, const uint hkIxVTbl = 0, const ubigint hkUref = 0, const string sref = "", const double x = 0.0, const double y = 0.0);
	virtual void insertRst(ListPlnrMVertex& rst, bool transact = false);
	virtual void updateRec(PlnrMVertex* rec);
	virtual void updateRst(ListPlnrMVertex& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, PlnrMVertex** rec);
	virtual ubigint countByDsnHktHku(ubigint x1RefPlnrMDesign, uint hkIxVTbl, ubigint hkUref);
	virtual ubigint countByHktHku(uint hkIxVTbl, ubigint hkUref);
	virtual bool loadRecByHktHkuSrf(uint hkIxVTbl, ubigint hkUref, string sref, PlnrMVertex** rec);
	virtual ubigint loadRstByDsnHktHku(ubigint x1RefPlnrMDesign, uint hkIxVTbl, ubigint hkUref, const bool append, ListPlnrMVertex& rst);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListPlnrMVertex& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrMVertex: C++ wrapper for table TblPlnrMVertex (MySQL database)
  */
class MyTblPlnrMVertex : public TblPlnrMVertex, public MyTable {

public:
	MyTblPlnrMVertex();
	~MyTblPlnrMVertex();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrMVertex** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrMVertex& rst);

	void insertRec(PlnrMVertex* rec);
	void insertRst(ListPlnrMVertex& rst, bool transact = false);
	void updateRec(PlnrMVertex* rec);
	void updateRst(ListPlnrMVertex& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrMVertex** rec);
	ubigint countByDsnHktHku(ubigint x1RefPlnrMDesign, uint hkIxVTbl, ubigint hkUref);
	ubigint countByHktHku(uint hkIxVTbl, ubigint hkUref);
	bool loadRecByHktHkuSrf(uint hkIxVTbl, ubigint hkUref, string sref, PlnrMVertex** rec);
	ubigint loadRstByDsnHktHku(ubigint x1RefPlnrMDesign, uint hkIxVTbl, ubigint hkUref, const bool append, ListPlnrMVertex& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrMVertex: C++ wrapper for table TblPlnrMVertex (PgSQL database)
  */
class PgTblPlnrMVertex : public TblPlnrMVertex, public PgTable {

public:
	PgTblPlnrMVertex();
	~PgTblPlnrMVertex();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrMVertex** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrMVertex& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrMVertex** rec);
// IP pgLoadRstByStmt --- BEGIN
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrMVertex& rst);
// IP pgLoadRstByStmt --- END

public:
	bool loadRecBySQL(const string& sqlstr, PlnrMVertex** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrMVertex& rst);

	void insertRec(PlnrMVertex* rec);
	void insertRst(ListPlnrMVertex& rst, bool transact = false);
	void updateRec(PlnrMVertex* rec);
	void updateRst(ListPlnrMVertex& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrMVertex** rec);
	ubigint countByDsnHktHku(ubigint x1RefPlnrMDesign, uint hkIxVTbl, ubigint hkUref);
	ubigint countByHktHku(uint hkIxVTbl, ubigint hkUref);
	bool loadRecByHktHkuSrf(uint hkIxVTbl, ubigint hkUref, string sref, PlnrMVertex** rec);
	ubigint loadRstByDsnHktHku(ubigint x1RefPlnrMDesign, uint hkIxVTbl, ubigint hkUref, const bool append, ListPlnrMVertex& rst);
};
// IP pgTbl --- END

#endif

