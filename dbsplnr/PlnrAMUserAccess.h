/**
  * \file PlnrAMUserAccess.h
  * database access for table TblPlnrAMUserAccess (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRAMUSERACCESS_H
#define PLNRAMUSERACCESS_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * PlnrAMUserAccess: record of TblPlnrAMUserAccess
  */
class PlnrAMUserAccess {

public:
	PlnrAMUserAccess(const ubigint ref = 0, const ubigint refPlnrMUser = 0, const uint x1IxPlnrVCard = 0, const uint ixPlnrWUiaccess = 0);

public:
	ubigint ref;
	ubigint refPlnrMUser;
	uint x1IxPlnrVCard;
	uint ixPlnrWUiaccess;

public:
	bool operator==(const PlnrAMUserAccess& comp);
	bool operator!=(const PlnrAMUserAccess& comp);
};

/**
  * ListPlnrAMUserAccess: recordset of TblPlnrAMUserAccess
  */
class ListPlnrAMUserAccess {

public:
	ListPlnrAMUserAccess();
	ListPlnrAMUserAccess(const ListPlnrAMUserAccess& src);
	~ListPlnrAMUserAccess();

	void clear();
	unsigned int size() const;
	void append(PlnrAMUserAccess* rec);

	PlnrAMUserAccess* operator[](const uint ix);
	ListPlnrAMUserAccess& operator=(const ListPlnrAMUserAccess& src);
	bool operator==(const ListPlnrAMUserAccess& comp);
	bool operator!=(const ListPlnrAMUserAccess& comp);

public:
	vector<PlnrAMUserAccess*> nodes;
};

/**
  * TblPlnrAMUserAccess: C++ wrapper for table TblPlnrAMUserAccess
  */
class TblPlnrAMUserAccess {

public:
	TblPlnrAMUserAccess();
	virtual ~TblPlnrAMUserAccess();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrAMUserAccess** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrAMUserAccess& rst);

	virtual void insertRec(PlnrAMUserAccess* rec);
	ubigint insertNewRec(PlnrAMUserAccess** rec = NULL, const ubigint refPlnrMUser = 0, const uint x1IxPlnrVCard = 0, const uint ixPlnrWUiaccess = 0);
	ubigint appendNewRecToRst(ListPlnrAMUserAccess& rst, PlnrAMUserAccess** rec = NULL, const ubigint refPlnrMUser = 0, const uint x1IxPlnrVCard = 0, const uint ixPlnrWUiaccess = 0);
	virtual void insertRst(ListPlnrAMUserAccess& rst, bool transact = false);
	virtual void updateRec(PlnrAMUserAccess* rec);
	virtual void updateRst(ListPlnrAMUserAccess& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, PlnrAMUserAccess** rec);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListPlnrAMUserAccess& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrAMUserAccess: C++ wrapper for table TblPlnrAMUserAccess (MySQL database)
  */
class MyTblPlnrAMUserAccess : public TblPlnrAMUserAccess, public MyTable {

public:
	MyTblPlnrAMUserAccess();
	~MyTblPlnrAMUserAccess();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrAMUserAccess** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrAMUserAccess& rst);

	void insertRec(PlnrAMUserAccess* rec);
	void insertRst(ListPlnrAMUserAccess& rst, bool transact = false);
	void updateRec(PlnrAMUserAccess* rec);
	void updateRst(ListPlnrAMUserAccess& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrAMUserAccess** rec);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrAMUserAccess: C++ wrapper for table TblPlnrAMUserAccess (PgSQL database)
  */
class PgTblPlnrAMUserAccess : public TblPlnrAMUserAccess, public PgTable {

public:
	PgTblPlnrAMUserAccess();
	~PgTblPlnrAMUserAccess();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrAMUserAccess** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrAMUserAccess& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrAMUserAccess** rec);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrAMUserAccess** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrAMUserAccess& rst);

	void insertRec(PlnrAMUserAccess* rec);
	void insertRst(ListPlnrAMUserAccess& rst, bool transact = false);
	void updateRec(PlnrAMUserAccess* rec);
	void updateRst(ListPlnrAMUserAccess& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrAMUserAccess** rec);
};
// IP pgTbl --- END

#endif

