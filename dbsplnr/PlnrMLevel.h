/**
  * \file PlnrMLevel.h
  * database access for table TblPlnrMLevel (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRMLEVEL_H
#define PLNRMLEVEL_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * PlnrMLevel: record of TblPlnrMLevel
  */
class PlnrMLevel {

public:
	PlnrMLevel(const ubigint ref = 0, const ubigint x1RefPlnrMDesign = 0, const uint hkIxVTbl = 0, const ubigint hkUref = 0, const string sref = "", const double z = 0.0);

public:
	ubigint ref;
	ubigint x1RefPlnrMDesign;
	uint hkIxVTbl;
	ubigint hkUref;
	string sref;
	double z;

public:
	bool operator==(const PlnrMLevel& comp);
	bool operator!=(const PlnrMLevel& comp);
};

/**
  * ListPlnrMLevel: recordset of TblPlnrMLevel
  */
class ListPlnrMLevel {

public:
	ListPlnrMLevel();
	ListPlnrMLevel(const ListPlnrMLevel& src);
	~ListPlnrMLevel();

	void clear();
	unsigned int size() const;
	void append(PlnrMLevel* rec);

	PlnrMLevel* operator[](const uint ix);
	ListPlnrMLevel& operator=(const ListPlnrMLevel& src);
	bool operator==(const ListPlnrMLevel& comp);
	bool operator!=(const ListPlnrMLevel& comp);

public:
	vector<PlnrMLevel*> nodes;
};

/**
  * TblPlnrMLevel: C++ wrapper for table TblPlnrMLevel
  */
class TblPlnrMLevel {

public:
	TblPlnrMLevel();
	virtual ~TblPlnrMLevel();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrMLevel** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrMLevel& rst);

	virtual void insertRec(PlnrMLevel* rec);
	ubigint insertNewRec(PlnrMLevel** rec = NULL, const ubigint x1RefPlnrMDesign = 0, const uint hkIxVTbl = 0, const ubigint hkUref = 0, const string sref = "", const double z = 0.0);
	ubigint appendNewRecToRst(ListPlnrMLevel& rst, PlnrMLevel** rec = NULL, const ubigint x1RefPlnrMDesign = 0, const uint hkIxVTbl = 0, const ubigint hkUref = 0, const string sref = "", const double z = 0.0);
	virtual void insertRst(ListPlnrMLevel& rst, bool transact = false);
	virtual void updateRec(PlnrMLevel* rec);
	virtual void updateRst(ListPlnrMLevel& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, PlnrMLevel** rec);
	virtual ubigint countByDsnHktHku(ubigint x1RefPlnrMDesign, uint hkIxVTbl, ubigint hkUref);
	virtual ubigint countByHktHku(uint hkIxVTbl, ubigint hkUref);
	virtual bool loadRecByHktHkuSrf(uint hkIxVTbl, ubigint hkUref, string sref, PlnrMLevel** rec);
	virtual ubigint loadRstByDsnHktHku(ubigint x1RefPlnrMDesign, uint hkIxVTbl, ubigint hkUref, const bool append, ListPlnrMLevel& rst);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListPlnrMLevel& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrMLevel: C++ wrapper for table TblPlnrMLevel (MySQL database)
  */
class MyTblPlnrMLevel : public TblPlnrMLevel, public MyTable {

public:
	MyTblPlnrMLevel();
	~MyTblPlnrMLevel();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrMLevel** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrMLevel& rst);

	void insertRec(PlnrMLevel* rec);
	void insertRst(ListPlnrMLevel& rst, bool transact = false);
	void updateRec(PlnrMLevel* rec);
	void updateRst(ListPlnrMLevel& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrMLevel** rec);
	ubigint countByDsnHktHku(ubigint x1RefPlnrMDesign, uint hkIxVTbl, ubigint hkUref);
	ubigint countByHktHku(uint hkIxVTbl, ubigint hkUref);
	bool loadRecByHktHkuSrf(uint hkIxVTbl, ubigint hkUref, string sref, PlnrMLevel** rec);
	ubigint loadRstByDsnHktHku(ubigint x1RefPlnrMDesign, uint hkIxVTbl, ubigint hkUref, const bool append, ListPlnrMLevel& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrMLevel: C++ wrapper for table TblPlnrMLevel (PgSQL database)
  */
class PgTblPlnrMLevel : public TblPlnrMLevel, public PgTable {

public:
	PgTblPlnrMLevel();
	~PgTblPlnrMLevel();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrMLevel** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrMLevel& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrMLevel** rec);
// IP pgLoadRstByStmt --- BEGIN
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrMLevel& rst);
// IP pgLoadRstByStmt --- END

public:
	bool loadRecBySQL(const string& sqlstr, PlnrMLevel** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrMLevel& rst);

	void insertRec(PlnrMLevel* rec);
	void insertRst(ListPlnrMLevel& rst, bool transact = false);
	void updateRec(PlnrMLevel* rec);
	void updateRst(ListPlnrMLevel& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrMLevel** rec);
	ubigint countByDsnHktHku(ubigint x1RefPlnrMDesign, uint hkIxVTbl, ubigint hkUref);
	ubigint countByHktHku(uint hkIxVTbl, ubigint hkUref);
	bool loadRecByHktHkuSrf(uint hkIxVTbl, ubigint hkUref, string sref, PlnrMLevel** rec);
	ubigint loadRstByDsnHktHku(ubigint x1RefPlnrMDesign, uint hkIxVTbl, ubigint hkUref, const bool append, ListPlnrMLevel& rst);
};
// IP pgTbl --- END

#endif

