/**
  * \file PlnrAMMaterialPar.h
  * database access for table TblPlnrAMMaterialPar (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRAMMATERIALPAR_H
#define PLNRAMMATERIALPAR_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * PlnrAMMaterialPar: record of TblPlnrAMMaterialPar
  */
class PlnrAMMaterialPar {

public:
	PlnrAMMaterialPar(const ubigint ref = 0, const ubigint refPlnrMMaterial = 0, const ubigint x1RefPlnrMDesign = 0, const string x2SrefKCat = "", const string x3SrefKProp = "", const ubigint refPlnrMFile = 0, const string Val = "", const string Comment = "");

public:
	ubigint ref;
	ubigint refPlnrMMaterial;
	ubigint x1RefPlnrMDesign;
	string x2SrefKCat;
	string x3SrefKProp;
	ubigint refPlnrMFile;
	string Val;
	string Comment;

public:
	bool operator==(const PlnrAMMaterialPar& comp);
	bool operator!=(const PlnrAMMaterialPar& comp);
};

/**
  * ListPlnrAMMaterialPar: recordset of TblPlnrAMMaterialPar
  */
class ListPlnrAMMaterialPar {

public:
	ListPlnrAMMaterialPar();
	ListPlnrAMMaterialPar(const ListPlnrAMMaterialPar& src);
	~ListPlnrAMMaterialPar();

	void clear();
	unsigned int size() const;
	void append(PlnrAMMaterialPar* rec);

	PlnrAMMaterialPar* operator[](const uint ix);
	ListPlnrAMMaterialPar& operator=(const ListPlnrAMMaterialPar& src);
	bool operator==(const ListPlnrAMMaterialPar& comp);
	bool operator!=(const ListPlnrAMMaterialPar& comp);

public:
	vector<PlnrAMMaterialPar*> nodes;
};

/**
  * TblPlnrAMMaterialPar: C++ wrapper for table TblPlnrAMMaterialPar
  */
class TblPlnrAMMaterialPar {

public:
	TblPlnrAMMaterialPar();
	virtual ~TblPlnrAMMaterialPar();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrAMMaterialPar** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrAMMaterialPar& rst);

	virtual void insertRec(PlnrAMMaterialPar* rec);
	ubigint insertNewRec(PlnrAMMaterialPar** rec = NULL, const ubigint refPlnrMMaterial = 0, const ubigint x1RefPlnrMDesign = 0, const string x2SrefKCat = "", const string x3SrefKProp = "", const ubigint refPlnrMFile = 0, const string Val = "", const string Comment = "");
	ubigint appendNewRecToRst(ListPlnrAMMaterialPar& rst, PlnrAMMaterialPar** rec = NULL, const ubigint refPlnrMMaterial = 0, const ubigint x1RefPlnrMDesign = 0, const string x2SrefKCat = "", const string x3SrefKProp = "", const ubigint refPlnrMFile = 0, const string Val = "", const string Comment = "");
	virtual void insertRst(ListPlnrAMMaterialPar& rst, bool transact = false);
	virtual void updateRec(PlnrAMMaterialPar* rec);
	virtual void updateRst(ListPlnrAMMaterialPar& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, PlnrAMMaterialPar** rec);
	virtual ubigint loadRefsByMat(ubigint refPlnrMMaterial, const bool append, vector<ubigint>& refs);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListPlnrAMMaterialPar& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrAMMaterialPar: C++ wrapper for table TblPlnrAMMaterialPar (MySQL database)
  */
class MyTblPlnrAMMaterialPar : public TblPlnrAMMaterialPar, public MyTable {

public:
	MyTblPlnrAMMaterialPar();
	~MyTblPlnrAMMaterialPar();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrAMMaterialPar** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrAMMaterialPar& rst);

	void insertRec(PlnrAMMaterialPar* rec);
	void insertRst(ListPlnrAMMaterialPar& rst, bool transact = false);
	void updateRec(PlnrAMMaterialPar* rec);
	void updateRst(ListPlnrAMMaterialPar& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrAMMaterialPar** rec);
	ubigint loadRefsByMat(ubigint refPlnrMMaterial, const bool append, vector<ubigint>& refs);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrAMMaterialPar: C++ wrapper for table TblPlnrAMMaterialPar (PgSQL database)
  */
class PgTblPlnrAMMaterialPar : public TblPlnrAMMaterialPar, public PgTable {

public:
	PgTblPlnrAMMaterialPar();
	~PgTblPlnrAMMaterialPar();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrAMMaterialPar** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrAMMaterialPar& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrAMMaterialPar** rec);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrAMMaterialPar** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrAMMaterialPar& rst);

	void insertRec(PlnrAMMaterialPar* rec);
	void insertRst(ListPlnrAMMaterialPar& rst, bool transact = false);
	void updateRec(PlnrAMMaterialPar* rec);
	void updateRst(ListPlnrAMMaterialPar& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrAMMaterialPar** rec);
	ubigint loadRefsByMat(ubigint refPlnrMMaterial, const bool append, vector<ubigint>& refs);
};
// IP pgTbl --- END

#endif

