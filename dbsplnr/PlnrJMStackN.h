/**
  * \file PlnrJMStackN.h
  * database access for table TblPlnrJMStackN (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRJMSTACKN_H
#define PLNRJMSTACKN_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * PlnrJMStackN: record of TblPlnrJMStackN
  */
class PlnrJMStackN {

public:
	PlnrJMStackN(const ubigint ref = 0, const ubigint refPlnrMStack = 0, const ubigint x1RefPlnrMDesign = 0, const string N = "");

public:
	ubigint ref;
	ubigint refPlnrMStack;
	ubigint x1RefPlnrMDesign;
	string N;

public:
	bool operator==(const PlnrJMStackN& comp);
	bool operator!=(const PlnrJMStackN& comp);
};

/**
  * ListPlnrJMStackN: recordset of TblPlnrJMStackN
  */
class ListPlnrJMStackN {

public:
	ListPlnrJMStackN();
	ListPlnrJMStackN(const ListPlnrJMStackN& src);
	~ListPlnrJMStackN();

	void clear();
	unsigned int size() const;
	void append(PlnrJMStackN* rec);

	PlnrJMStackN* operator[](const uint ix);
	ListPlnrJMStackN& operator=(const ListPlnrJMStackN& src);
	bool operator==(const ListPlnrJMStackN& comp);
	bool operator!=(const ListPlnrJMStackN& comp);

public:
	vector<PlnrJMStackN*> nodes;
};

/**
  * TblPlnrJMStackN: C++ wrapper for table TblPlnrJMStackN
  */
class TblPlnrJMStackN {

public:
	TblPlnrJMStackN();
	virtual ~TblPlnrJMStackN();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrJMStackN** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrJMStackN& rst);

	virtual void insertRec(PlnrJMStackN* rec);
	ubigint insertNewRec(PlnrJMStackN** rec = NULL, const ubigint refPlnrMStack = 0, const ubigint x1RefPlnrMDesign = 0, const string N = "");
	ubigint appendNewRecToRst(ListPlnrJMStackN& rst, PlnrJMStackN** rec = NULL, const ubigint refPlnrMStack = 0, const ubigint x1RefPlnrMDesign = 0, const string N = "");
	virtual void insertRst(ListPlnrJMStackN& rst, bool transact = false);
	virtual void updateRec(PlnrJMStackN* rec);
	virtual void updateRst(ListPlnrJMStackN& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, PlnrJMStackN** rec);
	virtual bool loadRecByStkDsn(ubigint refPlnrMStack, ubigint x1RefPlnrMDesign, PlnrJMStackN** rec);
	virtual ubigint loadRstByStk(ubigint refPlnrMStack, const bool append, ListPlnrJMStackN& rst);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListPlnrJMStackN& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrJMStackN: C++ wrapper for table TblPlnrJMStackN (MySQL database)
  */
class MyTblPlnrJMStackN : public TblPlnrJMStackN, public MyTable {

public:
	MyTblPlnrJMStackN();
	~MyTblPlnrJMStackN();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrJMStackN** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrJMStackN& rst);

	void insertRec(PlnrJMStackN* rec);
	void insertRst(ListPlnrJMStackN& rst, bool transact = false);
	void updateRec(PlnrJMStackN* rec);
	void updateRst(ListPlnrJMStackN& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrJMStackN** rec);
	bool loadRecByStkDsn(ubigint refPlnrMStack, ubigint x1RefPlnrMDesign, PlnrJMStackN** rec);
	ubigint loadRstByStk(ubigint refPlnrMStack, const bool append, ListPlnrJMStackN& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrJMStackN: C++ wrapper for table TblPlnrJMStackN (PgSQL database)
  */
class PgTblPlnrJMStackN : public TblPlnrJMStackN, public PgTable {

public:
	PgTblPlnrJMStackN();
	~PgTblPlnrJMStackN();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrJMStackN** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrJMStackN& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrJMStackN** rec);
// IP pgLoadRstByStmt --- BEGIN
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrJMStackN& rst);
// IP pgLoadRstByStmt --- END

public:
	bool loadRecBySQL(const string& sqlstr, PlnrJMStackN** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrJMStackN& rst);

	void insertRec(PlnrJMStackN* rec);
	void insertRst(ListPlnrJMStackN& rst, bool transact = false);
	void updateRec(PlnrJMStackN* rec);
	void updateRst(ListPlnrJMStackN& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrJMStackN** rec);
	bool loadRecByStkDsn(ubigint refPlnrMStack, ubigint x1RefPlnrMDesign, PlnrJMStackN** rec);
	ubigint loadRstByStk(ubigint refPlnrMStack, const bool append, ListPlnrJMStackN& rst);
};
// IP pgTbl --- END

#endif

