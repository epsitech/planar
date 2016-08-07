/**
  * \file PlnrJMUserState.h
  * database access for table TblPlnrJMUserState (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRJMUSERSTATE_H
#define PLNRJMUSERSTATE_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * PlnrJMUserState: record of TblPlnrJMUserState
  */
class PlnrJMUserState {

public:
	PlnrJMUserState(const ubigint ref = 0, const ubigint refPlnrMUser = 0, const uint x1Startd = 0, const uint ixVState = 0);

public:
	ubigint ref;
	ubigint refPlnrMUser;
	uint x1Startd;
	uint ixVState;

public:
	bool operator==(const PlnrJMUserState& comp);
	bool operator!=(const PlnrJMUserState& comp);
};

/**
  * ListPlnrJMUserState: recordset of TblPlnrJMUserState
  */
class ListPlnrJMUserState {

public:
	ListPlnrJMUserState();
	ListPlnrJMUserState(const ListPlnrJMUserState& src);
	~ListPlnrJMUserState();

	void clear();
	unsigned int size() const;
	void append(PlnrJMUserState* rec);

	PlnrJMUserState* operator[](const uint ix);
	ListPlnrJMUserState& operator=(const ListPlnrJMUserState& src);
	bool operator==(const ListPlnrJMUserState& comp);
	bool operator!=(const ListPlnrJMUserState& comp);

public:
	vector<PlnrJMUserState*> nodes;
};

/**
  * TblPlnrJMUserState: C++ wrapper for table TblPlnrJMUserState
  */
class TblPlnrJMUserState {

public:
	TblPlnrJMUserState();
	virtual ~TblPlnrJMUserState();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrJMUserState** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrJMUserState& rst);

	virtual void insertRec(PlnrJMUserState* rec);
	ubigint insertNewRec(PlnrJMUserState** rec = NULL, const ubigint refPlnrMUser = 0, const uint x1Startd = 0, const uint ixVState = 0);
	ubigint appendNewRecToRst(ListPlnrJMUserState& rst, PlnrJMUserState** rec = NULL, const ubigint refPlnrMUser = 0, const uint x1Startd = 0, const uint ixVState = 0);
	virtual void insertRst(ListPlnrJMUserState& rst, bool transact = false);
	virtual void updateRec(PlnrJMUserState* rec);
	virtual void updateRst(ListPlnrJMUserState& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, PlnrJMUserState** rec);
	virtual bool loadRecByUsrSta(ubigint refPlnrMUser, uint x1Startd, PlnrJMUserState** rec);
	virtual ubigint loadRefsByUsr(ubigint refPlnrMUser, const bool append, vector<ubigint>& refs);
	virtual ubigint loadRstByUsr(ubigint refPlnrMUser, const bool append, ListPlnrJMUserState& rst);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListPlnrJMUserState& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrJMUserState: C++ wrapper for table TblPlnrJMUserState (MySQL database)
  */
class MyTblPlnrJMUserState : public TblPlnrJMUserState, public MyTable {

public:
	MyTblPlnrJMUserState();
	~MyTblPlnrJMUserState();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrJMUserState** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrJMUserState& rst);

	void insertRec(PlnrJMUserState* rec);
	void insertRst(ListPlnrJMUserState& rst, bool transact = false);
	void updateRec(PlnrJMUserState* rec);
	void updateRst(ListPlnrJMUserState& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrJMUserState** rec);
	bool loadRecByUsrSta(ubigint refPlnrMUser, uint x1Startd, PlnrJMUserState** rec);
	ubigint loadRefsByUsr(ubigint refPlnrMUser, const bool append, vector<ubigint>& refs);
	ubigint loadRstByUsr(ubigint refPlnrMUser, const bool append, ListPlnrJMUserState& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrJMUserState: C++ wrapper for table TblPlnrJMUserState (PgSQL database)
  */
class PgTblPlnrJMUserState : public TblPlnrJMUserState, public PgTable {

public:
	PgTblPlnrJMUserState();
	~PgTblPlnrJMUserState();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrJMUserState** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrJMUserState& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrJMUserState** rec);
// IP pgLoadRstByStmt --- BEGIN
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrJMUserState& rst);
// IP pgLoadRstByStmt --- END

public:
	bool loadRecBySQL(const string& sqlstr, PlnrJMUserState** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrJMUserState& rst);

	void insertRec(PlnrJMUserState* rec);
	void insertRst(ListPlnrJMUserState& rst, bool transact = false);
	void updateRec(PlnrJMUserState* rec);
	void updateRst(ListPlnrJMUserState& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrJMUserState** rec);
	bool loadRecByUsrSta(ubigint refPlnrMUser, uint x1Startd, PlnrJMUserState** rec);
	ubigint loadRefsByUsr(ubigint refPlnrMUser, const bool append, vector<ubigint>& refs);
	ubigint loadRstByUsr(ubigint refPlnrMUser, const bool append, ListPlnrJMUserState& rst);
};
// IP pgTbl --- END

#endif

