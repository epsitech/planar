/**
  * \file PlnrMSession.h
  * database access for table TblPlnrMSession (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRMSESSION_H
#define PLNRMSESSION_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * PlnrMSession: record of TblPlnrMSession
  */
class PlnrMSession {

public:
	PlnrMSession(const ubigint ref = 0, const ubigint refPlnrMUser = 0, const uint start = 0, const uint stop = 0, const string Ip = "");

public:
	ubigint ref;
	ubigint refPlnrMUser;
	uint start;
	uint stop;
	string Ip;

public:
	bool operator==(const PlnrMSession& comp);
	bool operator!=(const PlnrMSession& comp);
};

/**
  * ListPlnrMSession: recordset of TblPlnrMSession
  */
class ListPlnrMSession {

public:
	ListPlnrMSession();
	ListPlnrMSession(const ListPlnrMSession& src);
	~ListPlnrMSession();

	void clear();
	unsigned int size() const;
	void append(PlnrMSession* rec);

	PlnrMSession* operator[](const uint ix);
	ListPlnrMSession& operator=(const ListPlnrMSession& src);
	bool operator==(const ListPlnrMSession& comp);
	bool operator!=(const ListPlnrMSession& comp);

public:
	vector<PlnrMSession*> nodes;
};

/**
  * TblPlnrMSession: C++ wrapper for table TblPlnrMSession
  */
class TblPlnrMSession {

public:
	TblPlnrMSession();
	virtual ~TblPlnrMSession();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrMSession** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrMSession& rst);

	virtual void insertRec(PlnrMSession* rec);
	ubigint insertNewRec(PlnrMSession** rec = NULL, const ubigint refPlnrMUser = 0, const uint start = 0, const uint stop = 0, const string Ip = "");
	ubigint appendNewRecToRst(ListPlnrMSession& rst, PlnrMSession** rec = NULL, const ubigint refPlnrMUser = 0, const uint start = 0, const uint stop = 0, const string Ip = "");
	virtual void insertRst(ListPlnrMSession& rst, bool transact = false);
	virtual void updateRec(PlnrMSession* rec);
	virtual void updateRst(ListPlnrMSession& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, PlnrMSession** rec);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListPlnrMSession& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrMSession: C++ wrapper for table TblPlnrMSession (MySQL database)
  */
class MyTblPlnrMSession : public TblPlnrMSession, public MyTable {

public:
	MyTblPlnrMSession();
	~MyTblPlnrMSession();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrMSession** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrMSession& rst);

	void insertRec(PlnrMSession* rec);
	void insertRst(ListPlnrMSession& rst, bool transact = false);
	void updateRec(PlnrMSession* rec);
	void updateRst(ListPlnrMSession& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrMSession** rec);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrMSession: C++ wrapper for table TblPlnrMSession (PgSQL database)
  */
class PgTblPlnrMSession : public TblPlnrMSession, public PgTable {

public:
	PgTblPlnrMSession();
	~PgTblPlnrMSession();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrMSession** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrMSession& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrMSession** rec);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrMSession** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrMSession& rst);

	void insertRec(PlnrMSession* rec);
	void insertRst(ListPlnrMSession& rst, bool transact = false);
	void updateRec(PlnrMSession* rec);
	void updateRst(ListPlnrMSession& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrMSession** rec);
};
// IP pgTbl --- END

#endif

