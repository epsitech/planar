/**
  * \file PlnrJMProjectState.h
  * database access for table TblPlnrJMProjectState (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRJMPROJECTSTATE_H
#define PLNRJMPROJECTSTATE_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * PlnrJMProjectState: record of TblPlnrJMProjectState
  */
class PlnrJMProjectState {

public:
	PlnrJMProjectState(const ubigint ref = 0, const ubigint refPlnrMProject = 0, const uint x1Start = 0, const uint ixVState = 0);

public:
	ubigint ref;
	ubigint refPlnrMProject;
	uint x1Start;
	uint ixVState;

public:
	bool operator==(const PlnrJMProjectState& comp);
	bool operator!=(const PlnrJMProjectState& comp);
};

/**
  * ListPlnrJMProjectState: recordset of TblPlnrJMProjectState
  */
class ListPlnrJMProjectState {

public:
	ListPlnrJMProjectState();
	ListPlnrJMProjectState(const ListPlnrJMProjectState& src);
	~ListPlnrJMProjectState();

	void clear();
	unsigned int size() const;
	void append(PlnrJMProjectState* rec);

	PlnrJMProjectState* operator[](const uint ix);
	ListPlnrJMProjectState& operator=(const ListPlnrJMProjectState& src);
	bool operator==(const ListPlnrJMProjectState& comp);
	bool operator!=(const ListPlnrJMProjectState& comp);

public:
	vector<PlnrJMProjectState*> nodes;
};

/**
  * TblPlnrJMProjectState: C++ wrapper for table TblPlnrJMProjectState
  */
class TblPlnrJMProjectState {

public:
	TblPlnrJMProjectState();
	virtual ~TblPlnrJMProjectState();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrJMProjectState** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrJMProjectState& rst);

	virtual void insertRec(PlnrJMProjectState* rec);
	ubigint insertNewRec(PlnrJMProjectState** rec = NULL, const ubigint refPlnrMProject = 0, const uint x1Start = 0, const uint ixVState = 0);
	ubigint appendNewRecToRst(ListPlnrJMProjectState& rst, PlnrJMProjectState** rec = NULL, const ubigint refPlnrMProject = 0, const uint x1Start = 0, const uint ixVState = 0);
	virtual void insertRst(ListPlnrJMProjectState& rst, bool transact = false);
	virtual void updateRec(PlnrJMProjectState* rec);
	virtual void updateRst(ListPlnrJMProjectState& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, PlnrJMProjectState** rec);
	virtual bool loadRecByPrjSta(ubigint refPlnrMProject, uint x1Start, PlnrJMProjectState** rec);
	virtual ubigint loadRstByPrj(ubigint refPlnrMProject, const bool append, ListPlnrJMProjectState& rst);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListPlnrJMProjectState& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrJMProjectState: C++ wrapper for table TblPlnrJMProjectState (MySQL database)
  */
class MyTblPlnrJMProjectState : public TblPlnrJMProjectState, public MyTable {

public:
	MyTblPlnrJMProjectState();
	~MyTblPlnrJMProjectState();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrJMProjectState** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrJMProjectState& rst);

	void insertRec(PlnrJMProjectState* rec);
	void insertRst(ListPlnrJMProjectState& rst, bool transact = false);
	void updateRec(PlnrJMProjectState* rec);
	void updateRst(ListPlnrJMProjectState& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrJMProjectState** rec);
	bool loadRecByPrjSta(ubigint refPlnrMProject, uint x1Start, PlnrJMProjectState** rec);
	ubigint loadRstByPrj(ubigint refPlnrMProject, const bool append, ListPlnrJMProjectState& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrJMProjectState: C++ wrapper for table TblPlnrJMProjectState (PgSQL database)
  */
class PgTblPlnrJMProjectState : public TblPlnrJMProjectState, public PgTable {

public:
	PgTblPlnrJMProjectState();
	~PgTblPlnrJMProjectState();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrJMProjectState** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrJMProjectState& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrJMProjectState** rec);
// IP pgLoadRstByStmt --- BEGIN
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrJMProjectState& rst);
// IP pgLoadRstByStmt --- END

public:
	bool loadRecBySQL(const string& sqlstr, PlnrJMProjectState** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrJMProjectState& rst);

	void insertRec(PlnrJMProjectState* rec);
	void insertRst(ListPlnrJMProjectState& rst, bool transact = false);
	void updateRec(PlnrJMProjectState* rec);
	void updateRst(ListPlnrJMProjectState& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrJMProjectState** rec);
	bool loadRecByPrjSta(ubigint refPlnrMProject, uint x1Start, PlnrJMProjectState** rec);
	ubigint loadRstByPrj(ubigint refPlnrMProject, const bool append, ListPlnrJMProjectState& rst);
};
// IP pgTbl --- END

#endif

