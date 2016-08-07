/**
  * \file PlnrAMArrayEnv.h
  * database access for table TblPlnrAMArrayEnv (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRAMARRAYENV_H
#define PLNRAMARRAYENV_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * PlnrAMArrayEnv: record of TblPlnrAMArrayEnv
  */
class PlnrAMArrayEnv {

public:
	PlnrAMArrayEnv(const ubigint ref = 0, const ubigint refPlnrMArray = 0, const ubigint x1RefPlnrMArrayitem = 0, const string x2SrefKKey = "", const string Val = "");

public:
	ubigint ref;
	ubigint refPlnrMArray;
	ubigint x1RefPlnrMArrayitem;
	string x2SrefKKey;
	string Val;

public:
	bool operator==(const PlnrAMArrayEnv& comp);
	bool operator!=(const PlnrAMArrayEnv& comp);
};

/**
  * ListPlnrAMArrayEnv: recordset of TblPlnrAMArrayEnv
  */
class ListPlnrAMArrayEnv {

public:
	ListPlnrAMArrayEnv();
	ListPlnrAMArrayEnv(const ListPlnrAMArrayEnv& src);
	~ListPlnrAMArrayEnv();

	void clear();
	unsigned int size() const;
	void append(PlnrAMArrayEnv* rec);

	PlnrAMArrayEnv* operator[](const uint ix);
	ListPlnrAMArrayEnv& operator=(const ListPlnrAMArrayEnv& src);
	bool operator==(const ListPlnrAMArrayEnv& comp);
	bool operator!=(const ListPlnrAMArrayEnv& comp);

public:
	vector<PlnrAMArrayEnv*> nodes;
};

/**
  * TblPlnrAMArrayEnv: C++ wrapper for table TblPlnrAMArrayEnv
  */
class TblPlnrAMArrayEnv {

public:
	TblPlnrAMArrayEnv();
	virtual ~TblPlnrAMArrayEnv();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrAMArrayEnv** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrAMArrayEnv& rst);

	virtual void insertRec(PlnrAMArrayEnv* rec);
	ubigint insertNewRec(PlnrAMArrayEnv** rec = NULL, const ubigint refPlnrMArray = 0, const ubigint x1RefPlnrMArrayitem = 0, const string x2SrefKKey = "", const string Val = "");
	ubigint appendNewRecToRst(ListPlnrAMArrayEnv& rst, PlnrAMArrayEnv** rec = NULL, const ubigint refPlnrMArray = 0, const ubigint x1RefPlnrMArrayitem = 0, const string x2SrefKKey = "", const string Val = "");
	virtual void insertRst(ListPlnrAMArrayEnv& rst, bool transact = false);
	virtual void updateRec(PlnrAMArrayEnv* rec);
	virtual void updateRst(ListPlnrAMArrayEnv& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, PlnrAMArrayEnv** rec);
	virtual ubigint loadRstByArrAri(ubigint refPlnrMArray, ubigint x1RefPlnrMArrayitem, const bool append, ListPlnrAMArrayEnv& rst);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListPlnrAMArrayEnv& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrAMArrayEnv: C++ wrapper for table TblPlnrAMArrayEnv (MySQL database)
  */
class MyTblPlnrAMArrayEnv : public TblPlnrAMArrayEnv, public MyTable {

public:
	MyTblPlnrAMArrayEnv();
	~MyTblPlnrAMArrayEnv();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrAMArrayEnv** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrAMArrayEnv& rst);

	void insertRec(PlnrAMArrayEnv* rec);
	void insertRst(ListPlnrAMArrayEnv& rst, bool transact = false);
	void updateRec(PlnrAMArrayEnv* rec);
	void updateRst(ListPlnrAMArrayEnv& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrAMArrayEnv** rec);
	ubigint loadRstByArrAri(ubigint refPlnrMArray, ubigint x1RefPlnrMArrayitem, const bool append, ListPlnrAMArrayEnv& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrAMArrayEnv: C++ wrapper for table TblPlnrAMArrayEnv (PgSQL database)
  */
class PgTblPlnrAMArrayEnv : public TblPlnrAMArrayEnv, public PgTable {

public:
	PgTblPlnrAMArrayEnv();
	~PgTblPlnrAMArrayEnv();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrAMArrayEnv** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrAMArrayEnv& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrAMArrayEnv** rec);
// IP pgLoadRstByStmt --- BEGIN
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrAMArrayEnv& rst);
// IP pgLoadRstByStmt --- END

public:
	bool loadRecBySQL(const string& sqlstr, PlnrAMArrayEnv** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrAMArrayEnv& rst);

	void insertRec(PlnrAMArrayEnv* rec);
	void insertRst(ListPlnrAMArrayEnv& rst, bool transact = false);
	void updateRec(PlnrAMArrayEnv* rec);
	void updateRst(ListPlnrAMArrayEnv& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrAMArrayEnv** rec);
	ubigint loadRstByArrAri(ubigint refPlnrMArray, ubigint x1RefPlnrMArrayitem, const bool append, ListPlnrAMArrayEnv& rst);
};
// IP pgTbl --- END

#endif

