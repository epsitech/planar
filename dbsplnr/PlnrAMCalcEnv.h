/**
  * \file PlnrAMCalcEnv.h
  * database access for table TblPlnrAMCalcEnv (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRAMCALCENV_H
#define PLNRAMCALCENV_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * PlnrAMCalcEnv: record of TblPlnrAMCalcEnv
  */
class PlnrAMCalcEnv {

public:
	PlnrAMCalcEnv(const ubigint ref = 0, const ubigint refPlnrMCalc = 0, const ubigint x1RefPlnrMCalcitem = 0, const string x2SrefKKey = "", const string Val = "");

public:
	ubigint ref;
	ubigint refPlnrMCalc;
	ubigint x1RefPlnrMCalcitem;
	string x2SrefKKey;
	string Val;

public:
	bool operator==(const PlnrAMCalcEnv& comp);
	bool operator!=(const PlnrAMCalcEnv& comp);
};

/**
  * ListPlnrAMCalcEnv: recordset of TblPlnrAMCalcEnv
  */
class ListPlnrAMCalcEnv {

public:
	ListPlnrAMCalcEnv();
	ListPlnrAMCalcEnv(const ListPlnrAMCalcEnv& src);
	~ListPlnrAMCalcEnv();

	void clear();
	unsigned int size() const;
	void append(PlnrAMCalcEnv* rec);

	PlnrAMCalcEnv* operator[](const uint ix);
	ListPlnrAMCalcEnv& operator=(const ListPlnrAMCalcEnv& src);
	bool operator==(const ListPlnrAMCalcEnv& comp);
	bool operator!=(const ListPlnrAMCalcEnv& comp);

public:
	vector<PlnrAMCalcEnv*> nodes;
};

/**
  * TblPlnrAMCalcEnv: C++ wrapper for table TblPlnrAMCalcEnv
  */
class TblPlnrAMCalcEnv {

public:
	TblPlnrAMCalcEnv();
	virtual ~TblPlnrAMCalcEnv();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrAMCalcEnv** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrAMCalcEnv& rst);

	virtual void insertRec(PlnrAMCalcEnv* rec);
	ubigint insertNewRec(PlnrAMCalcEnv** rec = NULL, const ubigint refPlnrMCalc = 0, const ubigint x1RefPlnrMCalcitem = 0, const string x2SrefKKey = "", const string Val = "");
	ubigint appendNewRecToRst(ListPlnrAMCalcEnv& rst, PlnrAMCalcEnv** rec = NULL, const ubigint refPlnrMCalc = 0, const ubigint x1RefPlnrMCalcitem = 0, const string x2SrefKKey = "", const string Val = "");
	virtual void insertRst(ListPlnrAMCalcEnv& rst, bool transact = false);
	virtual void updateRec(PlnrAMCalcEnv* rec);
	virtual void updateRst(ListPlnrAMCalcEnv& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, PlnrAMCalcEnv** rec);
	virtual ubigint loadRstByCalCli(ubigint refPlnrMCalc, ubigint x1RefPlnrMCalcitem, const bool append, ListPlnrAMCalcEnv& rst);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListPlnrAMCalcEnv& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrAMCalcEnv: C++ wrapper for table TblPlnrAMCalcEnv (MySQL database)
  */
class MyTblPlnrAMCalcEnv : public TblPlnrAMCalcEnv, public MyTable {

public:
	MyTblPlnrAMCalcEnv();
	~MyTblPlnrAMCalcEnv();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrAMCalcEnv** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrAMCalcEnv& rst);

	void insertRec(PlnrAMCalcEnv* rec);
	void insertRst(ListPlnrAMCalcEnv& rst, bool transact = false);
	void updateRec(PlnrAMCalcEnv* rec);
	void updateRst(ListPlnrAMCalcEnv& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrAMCalcEnv** rec);
	ubigint loadRstByCalCli(ubigint refPlnrMCalc, ubigint x1RefPlnrMCalcitem, const bool append, ListPlnrAMCalcEnv& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrAMCalcEnv: C++ wrapper for table TblPlnrAMCalcEnv (PgSQL database)
  */
class PgTblPlnrAMCalcEnv : public TblPlnrAMCalcEnv, public PgTable {

public:
	PgTblPlnrAMCalcEnv();
	~PgTblPlnrAMCalcEnv();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrAMCalcEnv** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrAMCalcEnv& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrAMCalcEnv** rec);
// IP pgLoadRstByStmt --- BEGIN
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrAMCalcEnv& rst);
// IP pgLoadRstByStmt --- END

public:
	bool loadRecBySQL(const string& sqlstr, PlnrAMCalcEnv** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrAMCalcEnv& rst);

	void insertRec(PlnrAMCalcEnv* rec);
	void insertRst(ListPlnrAMCalcEnv& rst, bool transact = false);
	void updateRec(PlnrAMCalcEnv* rec);
	void updateRst(ListPlnrAMCalcEnv& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrAMCalcEnv** rec);
	ubigint loadRstByCalCli(ubigint refPlnrMCalc, ubigint x1RefPlnrMCalcitem, const bool append, ListPlnrAMCalcEnv& rst);
};
// IP pgTbl --- END

#endif

