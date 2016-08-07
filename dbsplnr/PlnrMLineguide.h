/**
  * \file PlnrMLineguide.h
  * database access for table TblPlnrMLineguide (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRMLINEGUIDE_H
#define PLNRMLINEGUIDE_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * PlnrMLineguide: record of TblPlnrMLineguide
  */
class PlnrMLineguide {

public:
	PlnrMLineguide(const ubigint ref = 0, const ubigint x1RefPlnrMDesign = 0, const uint hkIxPlnrVLat = 0, const uint hkIxVTbl = 0, const ubigint hkUref = 0, const string sref = "");

public:
	ubigint ref;
	ubigint x1RefPlnrMDesign;
	uint hkIxPlnrVLat;
	uint hkIxVTbl;
	ubigint hkUref;
	string sref;

public:
	bool operator==(const PlnrMLineguide& comp);
	bool operator!=(const PlnrMLineguide& comp);
};

/**
  * ListPlnrMLineguide: recordset of TblPlnrMLineguide
  */
class ListPlnrMLineguide {

public:
	ListPlnrMLineguide();
	ListPlnrMLineguide(const ListPlnrMLineguide& src);
	~ListPlnrMLineguide();

	void clear();
	unsigned int size() const;
	void append(PlnrMLineguide* rec);

	PlnrMLineguide* operator[](const uint ix);
	ListPlnrMLineguide& operator=(const ListPlnrMLineguide& src);
	bool operator==(const ListPlnrMLineguide& comp);
	bool operator!=(const ListPlnrMLineguide& comp);

public:
	vector<PlnrMLineguide*> nodes;
};

/**
  * TblPlnrMLineguide: C++ wrapper for table TblPlnrMLineguide
  */
class TblPlnrMLineguide {

public:
	TblPlnrMLineguide();
	virtual ~TblPlnrMLineguide();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrMLineguide** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrMLineguide& rst);

	virtual void insertRec(PlnrMLineguide* rec);
	ubigint insertNewRec(PlnrMLineguide** rec = NULL, const ubigint x1RefPlnrMDesign = 0, const uint hkIxPlnrVLat = 0, const uint hkIxVTbl = 0, const ubigint hkUref = 0, const string sref = "");
	ubigint appendNewRecToRst(ListPlnrMLineguide& rst, PlnrMLineguide** rec = NULL, const ubigint x1RefPlnrMDesign = 0, const uint hkIxPlnrVLat = 0, const uint hkIxVTbl = 0, const ubigint hkUref = 0, const string sref = "");
	virtual void insertRst(ListPlnrMLineguide& rst, bool transact = false);
	virtual void updateRec(PlnrMLineguide* rec);
	virtual void updateRst(ListPlnrMLineguide& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, PlnrMLineguide** rec);
	virtual ubigint countByDsnHktHku(ubigint x1RefPlnrMDesign, uint hkIxVTbl, ubigint hkUref);
	virtual ubigint loadRstByDsnHktHku(ubigint x1RefPlnrMDesign, uint hkIxVTbl, ubigint hkUref, const bool append, ListPlnrMLineguide& rst);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListPlnrMLineguide& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrMLineguide: C++ wrapper for table TblPlnrMLineguide (MySQL database)
  */
class MyTblPlnrMLineguide : public TblPlnrMLineguide, public MyTable {

public:
	MyTblPlnrMLineguide();
	~MyTblPlnrMLineguide();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrMLineguide** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrMLineguide& rst);

	void insertRec(PlnrMLineguide* rec);
	void insertRst(ListPlnrMLineguide& rst, bool transact = false);
	void updateRec(PlnrMLineguide* rec);
	void updateRst(ListPlnrMLineguide& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrMLineguide** rec);
	ubigint countByDsnHktHku(ubigint x1RefPlnrMDesign, uint hkIxVTbl, ubigint hkUref);
	ubigint loadRstByDsnHktHku(ubigint x1RefPlnrMDesign, uint hkIxVTbl, ubigint hkUref, const bool append, ListPlnrMLineguide& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrMLineguide: C++ wrapper for table TblPlnrMLineguide (PgSQL database)
  */
class PgTblPlnrMLineguide : public TblPlnrMLineguide, public PgTable {

public:
	PgTblPlnrMLineguide();
	~PgTblPlnrMLineguide();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrMLineguide** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrMLineguide& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrMLineguide** rec);
// IP pgLoadRstByStmt --- BEGIN
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrMLineguide& rst);
// IP pgLoadRstByStmt --- END

public:
	bool loadRecBySQL(const string& sqlstr, PlnrMLineguide** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrMLineguide& rst);

	void insertRec(PlnrMLineguide* rec);
	void insertRst(ListPlnrMLineguide& rst, bool transact = false);
	void updateRec(PlnrMLineguide* rec);
	void updateRst(ListPlnrMLineguide& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrMLineguide** rec);
	ubigint countByDsnHktHku(ubigint x1RefPlnrMDesign, uint hkIxVTbl, ubigint hkUref);
	ubigint loadRstByDsnHktHku(ubigint x1RefPlnrMDesign, uint hkIxVTbl, ubigint hkUref, const bool append, ListPlnrMLineguide& rst);
};
// IP pgTbl --- END

#endif

