/**
  * \file PlnrJMTapeoutState.h
  * database access for table TblPlnrJMTapeoutState (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRJMTAPEOUTSTATE_H
#define PLNRJMTAPEOUTSTATE_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * PlnrJMTapeoutState: record of TblPlnrJMTapeoutState
  */
class PlnrJMTapeoutState {

public:
	PlnrJMTapeoutState(const ubigint ref = 0, const ubigint refPlnrMTapeout = 0, const uint x1Start = 0, const uint ixVState = 0);

public:
	ubigint ref;
	ubigint refPlnrMTapeout;
	uint x1Start;
	uint ixVState;

public:
	bool operator==(const PlnrJMTapeoutState& comp);
	bool operator!=(const PlnrJMTapeoutState& comp);
};

/**
  * ListPlnrJMTapeoutState: recordset of TblPlnrJMTapeoutState
  */
class ListPlnrJMTapeoutState {

public:
	ListPlnrJMTapeoutState();
	ListPlnrJMTapeoutState(const ListPlnrJMTapeoutState& src);
	~ListPlnrJMTapeoutState();

	void clear();
	unsigned int size() const;
	void append(PlnrJMTapeoutState* rec);

	PlnrJMTapeoutState* operator[](const uint ix);
	ListPlnrJMTapeoutState& operator=(const ListPlnrJMTapeoutState& src);
	bool operator==(const ListPlnrJMTapeoutState& comp);
	bool operator!=(const ListPlnrJMTapeoutState& comp);

public:
	vector<PlnrJMTapeoutState*> nodes;
};

/**
  * TblPlnrJMTapeoutState: C++ wrapper for table TblPlnrJMTapeoutState
  */
class TblPlnrJMTapeoutState {

public:
	TblPlnrJMTapeoutState();
	virtual ~TblPlnrJMTapeoutState();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrJMTapeoutState** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrJMTapeoutState& rst);

	virtual void insertRec(PlnrJMTapeoutState* rec);
	ubigint insertNewRec(PlnrJMTapeoutState** rec = NULL, const ubigint refPlnrMTapeout = 0, const uint x1Start = 0, const uint ixVState = 0);
	ubigint appendNewRecToRst(ListPlnrJMTapeoutState& rst, PlnrJMTapeoutState** rec = NULL, const ubigint refPlnrMTapeout = 0, const uint x1Start = 0, const uint ixVState = 0);
	virtual void insertRst(ListPlnrJMTapeoutState& rst, bool transact = false);
	virtual void updateRec(PlnrJMTapeoutState* rec);
	virtual void updateRst(ListPlnrJMTapeoutState& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, PlnrJMTapeoutState** rec);
	virtual bool loadRecByTpoSta(ubigint refPlnrMTapeout, uint x1Start, PlnrJMTapeoutState** rec);
	virtual ubigint loadRstByTpo(ubigint refPlnrMTapeout, const bool append, ListPlnrJMTapeoutState& rst);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListPlnrJMTapeoutState& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrJMTapeoutState: C++ wrapper for table TblPlnrJMTapeoutState (MySQL database)
  */
class MyTblPlnrJMTapeoutState : public TblPlnrJMTapeoutState, public MyTable {

public:
	MyTblPlnrJMTapeoutState();
	~MyTblPlnrJMTapeoutState();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrJMTapeoutState** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrJMTapeoutState& rst);

	void insertRec(PlnrJMTapeoutState* rec);
	void insertRst(ListPlnrJMTapeoutState& rst, bool transact = false);
	void updateRec(PlnrJMTapeoutState* rec);
	void updateRst(ListPlnrJMTapeoutState& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrJMTapeoutState** rec);
	bool loadRecByTpoSta(ubigint refPlnrMTapeout, uint x1Start, PlnrJMTapeoutState** rec);
	ubigint loadRstByTpo(ubigint refPlnrMTapeout, const bool append, ListPlnrJMTapeoutState& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrJMTapeoutState: C++ wrapper for table TblPlnrJMTapeoutState (PgSQL database)
  */
class PgTblPlnrJMTapeoutState : public TblPlnrJMTapeoutState, public PgTable {

public:
	PgTblPlnrJMTapeoutState();
	~PgTblPlnrJMTapeoutState();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrJMTapeoutState** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrJMTapeoutState& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrJMTapeoutState** rec);
// IP pgLoadRstByStmt --- BEGIN
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrJMTapeoutState& rst);
// IP pgLoadRstByStmt --- END

public:
	bool loadRecBySQL(const string& sqlstr, PlnrJMTapeoutState** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrJMTapeoutState& rst);

	void insertRec(PlnrJMTapeoutState* rec);
	void insertRst(ListPlnrJMTapeoutState& rst, bool transact = false);
	void updateRec(PlnrJMTapeoutState* rec);
	void updateRst(ListPlnrJMTapeoutState& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrJMTapeoutState** rec);
	bool loadRecByTpoSta(ubigint refPlnrMTapeout, uint x1Start, PlnrJMTapeoutState** rec);
	ubigint loadRstByTpo(ubigint refPlnrMTapeout, const bool append, ListPlnrJMTapeoutState& rst);
};
// IP pgTbl --- END

#endif

