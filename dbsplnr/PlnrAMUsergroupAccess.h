/**
  * \file PlnrAMUsergroupAccess.h
  * database access for table TblPlnrAMUsergroupAccess (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRAMUSERGROUPACCESS_H
#define PLNRAMUSERGROUPACCESS_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * PlnrAMUsergroupAccess: record of TblPlnrAMUsergroupAccess
  */
class PlnrAMUsergroupAccess {

public:
	PlnrAMUsergroupAccess(const ubigint ref = 0, const ubigint refPlnrMUsergroup = 0, const uint x1IxPlnrVCard = 0, const uint ixPlnrWUiaccess = 0);

public:
	ubigint ref;
	ubigint refPlnrMUsergroup;
	uint x1IxPlnrVCard;
	uint ixPlnrWUiaccess;

public:
	bool operator==(const PlnrAMUsergroupAccess& comp);
	bool operator!=(const PlnrAMUsergroupAccess& comp);
};

/**
  * ListPlnrAMUsergroupAccess: recordset of TblPlnrAMUsergroupAccess
  */
class ListPlnrAMUsergroupAccess {

public:
	ListPlnrAMUsergroupAccess();
	ListPlnrAMUsergroupAccess(const ListPlnrAMUsergroupAccess& src);
	~ListPlnrAMUsergroupAccess();

	void clear();
	unsigned int size() const;
	void append(PlnrAMUsergroupAccess* rec);

	PlnrAMUsergroupAccess* operator[](const uint ix);
	ListPlnrAMUsergroupAccess& operator=(const ListPlnrAMUsergroupAccess& src);
	bool operator==(const ListPlnrAMUsergroupAccess& comp);
	bool operator!=(const ListPlnrAMUsergroupAccess& comp);

public:
	vector<PlnrAMUsergroupAccess*> nodes;
};

/**
  * TblPlnrAMUsergroupAccess: C++ wrapper for table TblPlnrAMUsergroupAccess
  */
class TblPlnrAMUsergroupAccess {

public:
	TblPlnrAMUsergroupAccess();
	virtual ~TblPlnrAMUsergroupAccess();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrAMUsergroupAccess** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrAMUsergroupAccess& rst);

	virtual void insertRec(PlnrAMUsergroupAccess* rec);
	ubigint insertNewRec(PlnrAMUsergroupAccess** rec = NULL, const ubigint refPlnrMUsergroup = 0, const uint x1IxPlnrVCard = 0, const uint ixPlnrWUiaccess = 0);
	ubigint appendNewRecToRst(ListPlnrAMUsergroupAccess& rst, PlnrAMUsergroupAccess** rec = NULL, const ubigint refPlnrMUsergroup = 0, const uint x1IxPlnrVCard = 0, const uint ixPlnrWUiaccess = 0);
	virtual void insertRst(ListPlnrAMUsergroupAccess& rst, bool transact = false);
	virtual void updateRec(PlnrAMUsergroupAccess* rec);
	virtual void updateRst(ListPlnrAMUsergroupAccess& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, PlnrAMUsergroupAccess** rec);
	virtual ubigint loadRefsByUsg(ubigint refPlnrMUsergroup, const bool append, vector<ubigint>& refs);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListPlnrAMUsergroupAccess& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrAMUsergroupAccess: C++ wrapper for table TblPlnrAMUsergroupAccess (MySQL database)
  */
class MyTblPlnrAMUsergroupAccess : public TblPlnrAMUsergroupAccess, public MyTable {

public:
	MyTblPlnrAMUsergroupAccess();
	~MyTblPlnrAMUsergroupAccess();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrAMUsergroupAccess** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrAMUsergroupAccess& rst);

	void insertRec(PlnrAMUsergroupAccess* rec);
	void insertRst(ListPlnrAMUsergroupAccess& rst, bool transact = false);
	void updateRec(PlnrAMUsergroupAccess* rec);
	void updateRst(ListPlnrAMUsergroupAccess& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrAMUsergroupAccess** rec);
	ubigint loadRefsByUsg(ubigint refPlnrMUsergroup, const bool append, vector<ubigint>& refs);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrAMUsergroupAccess: C++ wrapper for table TblPlnrAMUsergroupAccess (PgSQL database)
  */
class PgTblPlnrAMUsergroupAccess : public TblPlnrAMUsergroupAccess, public PgTable {

public:
	PgTblPlnrAMUsergroupAccess();
	~PgTblPlnrAMUsergroupAccess();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrAMUsergroupAccess** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrAMUsergroupAccess& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrAMUsergroupAccess** rec);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrAMUsergroupAccess** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrAMUsergroupAccess& rst);

	void insertRec(PlnrAMUsergroupAccess* rec);
	void insertRst(ListPlnrAMUsergroupAccess& rst, bool transact = false);
	void updateRec(PlnrAMUsergroupAccess* rec);
	void updateRst(ListPlnrAMUsergroupAccess& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrAMUsergroupAccess** rec);
	ubigint loadRefsByUsg(ubigint refPlnrMUsergroup, const bool append, vector<ubigint>& refs);
};
// IP pgTbl --- END

#endif

