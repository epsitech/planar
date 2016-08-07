/**
  * \file PlnrMArcguide.h
  * database access for table TblPlnrMArcguide (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRMARCGUIDE_H
#define PLNRMARCGUIDE_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * PlnrMArcguide: record of TblPlnrMArcguide
  */
class PlnrMArcguide {

public:
	PlnrMArcguide(const ubigint ref = 0, const ubigint x1RefPlnrMDesign = 0, const ubigint devRefPlnrMArcguide = 0, const uint hkIxPlnrVLat = 0, const uint hkIxVTbl = 0, const ubigint hkUref = 0, const string sref = "", const ubigint ctrRefPlnrMVertex = 0, const double r = 0.0);

public:
	ubigint ref;
	ubigint x1RefPlnrMDesign;
	ubigint devRefPlnrMArcguide;
	uint hkIxPlnrVLat;
	uint hkIxVTbl;
	ubigint hkUref;
	string sref;
	ubigint ctrRefPlnrMVertex;
	double r;

public:
	bool operator==(const PlnrMArcguide& comp);
	bool operator!=(const PlnrMArcguide& comp);
};

/**
  * ListPlnrMArcguide: recordset of TblPlnrMArcguide
  */
class ListPlnrMArcguide {

public:
	ListPlnrMArcguide();
	ListPlnrMArcguide(const ListPlnrMArcguide& src);
	~ListPlnrMArcguide();

	void clear();
	unsigned int size() const;
	void append(PlnrMArcguide* rec);

	PlnrMArcguide* operator[](const uint ix);
	ListPlnrMArcguide& operator=(const ListPlnrMArcguide& src);
	bool operator==(const ListPlnrMArcguide& comp);
	bool operator!=(const ListPlnrMArcguide& comp);

public:
	vector<PlnrMArcguide*> nodes;
};

/**
  * TblPlnrMArcguide: C++ wrapper for table TblPlnrMArcguide
  */
class TblPlnrMArcguide {

public:
	TblPlnrMArcguide();
	virtual ~TblPlnrMArcguide();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrMArcguide** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrMArcguide& rst);

	virtual void insertRec(PlnrMArcguide* rec);
	ubigint insertNewRec(PlnrMArcguide** rec = NULL, const ubigint x1RefPlnrMDesign = 0, const ubigint devRefPlnrMArcguide = 0, const uint hkIxPlnrVLat = 0, const uint hkIxVTbl = 0, const ubigint hkUref = 0, const string sref = "", const ubigint ctrRefPlnrMVertex = 0, const double r = 0.0);
	ubigint appendNewRecToRst(ListPlnrMArcguide& rst, PlnrMArcguide** rec = NULL, const ubigint x1RefPlnrMDesign = 0, const ubigint devRefPlnrMArcguide = 0, const uint hkIxPlnrVLat = 0, const uint hkIxVTbl = 0, const ubigint hkUref = 0, const string sref = "", const ubigint ctrRefPlnrMVertex = 0, const double r = 0.0);
	virtual void insertRst(ListPlnrMArcguide& rst, bool transact = false);
	virtual void updateRec(PlnrMArcguide* rec);
	virtual void updateRst(ListPlnrMArcguide& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, PlnrMArcguide** rec);
	virtual ubigint countByDsnHktHku(ubigint x1RefPlnrMDesign, uint hkIxVTbl, ubigint hkUref);
	virtual ubigint loadRstByDsnHktHku(ubigint x1RefPlnrMDesign, uint hkIxVTbl, ubigint hkUref, const bool append, ListPlnrMArcguide& rst);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListPlnrMArcguide& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrMArcguide: C++ wrapper for table TblPlnrMArcguide (MySQL database)
  */
class MyTblPlnrMArcguide : public TblPlnrMArcguide, public MyTable {

public:
	MyTblPlnrMArcguide();
	~MyTblPlnrMArcguide();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrMArcguide** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrMArcguide& rst);

	void insertRec(PlnrMArcguide* rec);
	void insertRst(ListPlnrMArcguide& rst, bool transact = false);
	void updateRec(PlnrMArcguide* rec);
	void updateRst(ListPlnrMArcguide& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrMArcguide** rec);
	ubigint countByDsnHktHku(ubigint x1RefPlnrMDesign, uint hkIxVTbl, ubigint hkUref);
	ubigint loadRstByDsnHktHku(ubigint x1RefPlnrMDesign, uint hkIxVTbl, ubigint hkUref, const bool append, ListPlnrMArcguide& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrMArcguide: C++ wrapper for table TblPlnrMArcguide (PgSQL database)
  */
class PgTblPlnrMArcguide : public TblPlnrMArcguide, public PgTable {

public:
	PgTblPlnrMArcguide();
	~PgTblPlnrMArcguide();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrMArcguide** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrMArcguide& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrMArcguide** rec);
// IP pgLoadRstByStmt --- BEGIN
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrMArcguide& rst);
// IP pgLoadRstByStmt --- END

public:
	bool loadRecBySQL(const string& sqlstr, PlnrMArcguide** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrMArcguide& rst);

	void insertRec(PlnrMArcguide* rec);
	void insertRst(ListPlnrMArcguide& rst, bool transact = false);
	void updateRec(PlnrMArcguide* rec);
	void updateRst(ListPlnrMArcguide& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrMArcguide** rec);
	ubigint countByDsnHktHku(ubigint x1RefPlnrMDesign, uint hkIxVTbl, ubigint hkUref);
	ubigint loadRstByDsnHktHku(ubigint x1RefPlnrMDesign, uint hkIxVTbl, ubigint hkUref, const bool append, ListPlnrMArcguide& rst);
};
// IP pgTbl --- END

#endif

