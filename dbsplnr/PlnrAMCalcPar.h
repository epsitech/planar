/**
  * \file PlnrAMCalcPar.h
  * database access for table TblPlnrAMCalcPar (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRAMCALCPAR_H
#define PLNRAMCALCPAR_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * PlnrAMCalcPar: record of TblPlnrAMCalcPar
  */
class PlnrAMCalcPar {

public:
	PlnrAMCalcPar(const ubigint ref = 0, const ubigint refPlnrMCalc = 0, const ubigint x1RefPlnrMCalcitem = 0, const string x2SrefKCat = "", const string x3SrefKProp = "", const string Val = "");

public:
	ubigint ref;
	ubigint refPlnrMCalc;
	ubigint x1RefPlnrMCalcitem;
	string x2SrefKCat;
	string x3SrefKProp;
	string Val;

public:
	bool operator==(const PlnrAMCalcPar& comp);
	bool operator!=(const PlnrAMCalcPar& comp);
};

/**
  * ListPlnrAMCalcPar: recordset of TblPlnrAMCalcPar
  */
class ListPlnrAMCalcPar {

public:
	ListPlnrAMCalcPar();
	ListPlnrAMCalcPar(const ListPlnrAMCalcPar& src);
	~ListPlnrAMCalcPar();

	void clear();
	unsigned int size() const;
	void append(PlnrAMCalcPar* rec);

	PlnrAMCalcPar* operator[](const uint ix);
	ListPlnrAMCalcPar& operator=(const ListPlnrAMCalcPar& src);
	bool operator==(const ListPlnrAMCalcPar& comp);
	bool operator!=(const ListPlnrAMCalcPar& comp);

public:
	vector<PlnrAMCalcPar*> nodes;
};

/**
  * TblPlnrAMCalcPar: C++ wrapper for table TblPlnrAMCalcPar
  */
class TblPlnrAMCalcPar {

public:
	TblPlnrAMCalcPar();
	virtual ~TblPlnrAMCalcPar();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrAMCalcPar** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrAMCalcPar& rst);

	virtual void insertRec(PlnrAMCalcPar* rec);
	ubigint insertNewRec(PlnrAMCalcPar** rec = NULL, const ubigint refPlnrMCalc = 0, const ubigint x1RefPlnrMCalcitem = 0, const string x2SrefKCat = "", const string x3SrefKProp = "", const string Val = "");
	ubigint appendNewRecToRst(ListPlnrAMCalcPar& rst, PlnrAMCalcPar** rec = NULL, const ubigint refPlnrMCalc = 0, const ubigint x1RefPlnrMCalcitem = 0, const string x2SrefKCat = "", const string x3SrefKProp = "", const string Val = "");
	virtual void insertRst(ListPlnrAMCalcPar& rst, bool transact = false);
	virtual void updateRec(PlnrAMCalcPar* rec);
	virtual void updateRst(ListPlnrAMCalcPar& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, PlnrAMCalcPar** rec);
	virtual bool loadRecByCalCliCatPrp(ubigint refPlnrMCalc, ubigint x1RefPlnrMCalcitem, string x2SrefKCat, string x3SrefKProp, PlnrAMCalcPar** rec);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListPlnrAMCalcPar& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrAMCalcPar: C++ wrapper for table TblPlnrAMCalcPar (MySQL database)
  */
class MyTblPlnrAMCalcPar : public TblPlnrAMCalcPar, public MyTable {

public:
	MyTblPlnrAMCalcPar();
	~MyTblPlnrAMCalcPar();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrAMCalcPar** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrAMCalcPar& rst);

	void insertRec(PlnrAMCalcPar* rec);
	void insertRst(ListPlnrAMCalcPar& rst, bool transact = false);
	void updateRec(PlnrAMCalcPar* rec);
	void updateRst(ListPlnrAMCalcPar& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrAMCalcPar** rec);
	bool loadRecByCalCliCatPrp(ubigint refPlnrMCalc, ubigint x1RefPlnrMCalcitem, string x2SrefKCat, string x3SrefKProp, PlnrAMCalcPar** rec);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrAMCalcPar: C++ wrapper for table TblPlnrAMCalcPar (PgSQL database)
  */
class PgTblPlnrAMCalcPar : public TblPlnrAMCalcPar, public PgTable {

public:
	PgTblPlnrAMCalcPar();
	~PgTblPlnrAMCalcPar();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrAMCalcPar** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrAMCalcPar& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrAMCalcPar** rec);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrAMCalcPar** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrAMCalcPar& rst);

	void insertRec(PlnrAMCalcPar* rec);
	void insertRst(ListPlnrAMCalcPar& rst, bool transact = false);
	void updateRec(PlnrAMCalcPar* rec);
	void updateRst(ListPlnrAMCalcPar& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrAMCalcPar** rec);
	bool loadRecByCalCliCatPrp(ubigint refPlnrMCalc, ubigint x1RefPlnrMCalcitem, string x2SrefKCat, string x3SrefKProp, PlnrAMCalcPar** rec);
};
// IP pgTbl --- END

#endif

