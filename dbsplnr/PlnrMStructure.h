/**
  * \file PlnrMStructure.h
  * database access for table TblPlnrMStructure (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRMSTRUCTURE_H
#define PLNRMSTRUCTURE_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * PlnrMStructure: record of TblPlnrMStructure
  */
class PlnrMStructure {

public:
	PlnrMStructure(const ubigint ref = 0, const uint hkIxVTbl = 0, const ubigint hkUref = 0, const string sref = "", const double x0 = 0.0, const double x1 = 0.0, const double y0 = 0.0, const double y1 = 0.0);

public:
	ubigint ref;
	uint hkIxVTbl;
	ubigint hkUref;
	string sref;
	double x0;
	double x1;
	double y0;
	double y1;

public:
	bool operator==(const PlnrMStructure& comp);
	bool operator!=(const PlnrMStructure& comp);
};

/**
  * ListPlnrMStructure: recordset of TblPlnrMStructure
  */
class ListPlnrMStructure {

public:
	ListPlnrMStructure();
	ListPlnrMStructure(const ListPlnrMStructure& src);
	~ListPlnrMStructure();

	void clear();
	unsigned int size() const;
	void append(PlnrMStructure* rec);

	PlnrMStructure* operator[](const uint ix);
	ListPlnrMStructure& operator=(const ListPlnrMStructure& src);
	bool operator==(const ListPlnrMStructure& comp);
	bool operator!=(const ListPlnrMStructure& comp);

public:
	vector<PlnrMStructure*> nodes;
};

/**
  * TblPlnrMStructure: C++ wrapper for table TblPlnrMStructure
  */
class TblPlnrMStructure {

public:
	TblPlnrMStructure();
	virtual ~TblPlnrMStructure();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrMStructure** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrMStructure& rst);

	virtual void insertRec(PlnrMStructure* rec);
	ubigint insertNewRec(PlnrMStructure** rec = NULL, const uint hkIxVTbl = 0, const ubigint hkUref = 0, const string sref = "", const double x0 = 0.0, const double x1 = 0.0, const double y0 = 0.0, const double y1 = 0.0);
	ubigint appendNewRecToRst(ListPlnrMStructure& rst, PlnrMStructure** rec = NULL, const uint hkIxVTbl = 0, const ubigint hkUref = 0, const string sref = "", const double x0 = 0.0, const double x1 = 0.0, const double y0 = 0.0, const double y1 = 0.0);
	virtual void insertRst(ListPlnrMStructure& rst, bool transact = false);
	virtual void updateRec(PlnrMStructure* rec);
	virtual void updateRst(ListPlnrMStructure& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, PlnrMStructure** rec);
	virtual bool loadRefByHktHkuSrf(uint hkIxVTbl, ubigint hkUref, string sref, ubigint& val);
	virtual ubigint loadRefsByHktHku(uint hkIxVTbl, ubigint hkUref, const bool append, vector<ubigint>& refs);
	virtual ubigint loadRstByHktHku(uint hkIxVTbl, ubigint hkUref, const bool append, ListPlnrMStructure& rst);
	virtual bool loadSrfByRef(ubigint ref, string& val);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListPlnrMStructure& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrMStructure: C++ wrapper for table TblPlnrMStructure (MySQL database)
  */
class MyTblPlnrMStructure : public TblPlnrMStructure, public MyTable {

public:
	MyTblPlnrMStructure();
	~MyTblPlnrMStructure();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrMStructure** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrMStructure& rst);

	void insertRec(PlnrMStructure* rec);
	void insertRst(ListPlnrMStructure& rst, bool transact = false);
	void updateRec(PlnrMStructure* rec);
	void updateRst(ListPlnrMStructure& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrMStructure** rec);
	bool loadRefByHktHkuSrf(uint hkIxVTbl, ubigint hkUref, string sref, ubigint& val);
	ubigint loadRefsByHktHku(uint hkIxVTbl, ubigint hkUref, const bool append, vector<ubigint>& refs);
	ubigint loadRstByHktHku(uint hkIxVTbl, ubigint hkUref, const bool append, ListPlnrMStructure& rst);
	bool loadSrfByRef(ubigint ref, string& val);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrMStructure: C++ wrapper for table TblPlnrMStructure (PgSQL database)
  */
class PgTblPlnrMStructure : public TblPlnrMStructure, public PgTable {

public:
	PgTblPlnrMStructure();
	~PgTblPlnrMStructure();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrMStructure** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrMStructure& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrMStructure** rec);
// IP pgLoadRstByStmt --- BEGIN
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrMStructure& rst);
// IP pgLoadRstByStmt --- END

public:
	bool loadRecBySQL(const string& sqlstr, PlnrMStructure** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrMStructure& rst);

	void insertRec(PlnrMStructure* rec);
	void insertRst(ListPlnrMStructure& rst, bool transact = false);
	void updateRec(PlnrMStructure* rec);
	void updateRst(ListPlnrMStructure& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrMStructure** rec);
	bool loadRefByHktHkuSrf(uint hkIxVTbl, ubigint hkUref, string sref, ubigint& val);
	ubigint loadRefsByHktHku(uint hkIxVTbl, ubigint hkUref, const bool append, vector<ubigint>& refs);
	ubigint loadRstByHktHku(uint hkIxVTbl, ubigint hkUref, const bool append, ListPlnrMStructure& rst);
	bool loadSrfByRef(ubigint ref, string& val);
};
// IP pgTbl --- END

#endif

