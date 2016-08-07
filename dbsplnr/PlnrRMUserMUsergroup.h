/**
  * \file PlnrRMUserMUsergroup.h
  * database access for table TblPlnrRMUserMUsergroup (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRRMUSERMUSERGROUP_H
#define PLNRRMUSERMUSERGROUP_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * PlnrRMUserMUsergroup: record of TblPlnrRMUserMUsergroup
  */
class PlnrRMUserMUsergroup {

public:
	PlnrRMUserMUsergroup(const ubigint ref = 0, const ubigint refPlnrMUser = 0, const ubigint refPlnrMUsergroup = 0, const uint ixPlnrVUserlevel = 0);

public:
	ubigint ref;
	ubigint refPlnrMUser;
	ubigint refPlnrMUsergroup;
	uint ixPlnrVUserlevel;

public:
	bool operator==(const PlnrRMUserMUsergroup& comp);
	bool operator!=(const PlnrRMUserMUsergroup& comp);
};

/**
  * ListPlnrRMUserMUsergroup: recordset of TblPlnrRMUserMUsergroup
  */
class ListPlnrRMUserMUsergroup {

public:
	ListPlnrRMUserMUsergroup();
	ListPlnrRMUserMUsergroup(const ListPlnrRMUserMUsergroup& src);
	~ListPlnrRMUserMUsergroup();

	void clear();
	unsigned int size() const;
	void append(PlnrRMUserMUsergroup* rec);

	PlnrRMUserMUsergroup* operator[](const uint ix);
	ListPlnrRMUserMUsergroup& operator=(const ListPlnrRMUserMUsergroup& src);
	bool operator==(const ListPlnrRMUserMUsergroup& comp);
	bool operator!=(const ListPlnrRMUserMUsergroup& comp);

public:
	vector<PlnrRMUserMUsergroup*> nodes;
};

/**
  * TblPlnrRMUserMUsergroup: C++ wrapper for table TblPlnrRMUserMUsergroup
  */
class TblPlnrRMUserMUsergroup {

public:
	TblPlnrRMUserMUsergroup();
	virtual ~TblPlnrRMUserMUsergroup();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrRMUserMUsergroup** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrRMUserMUsergroup& rst);

	virtual void insertRec(PlnrRMUserMUsergroup* rec);
	ubigint insertNewRec(PlnrRMUserMUsergroup** rec = NULL, const ubigint refPlnrMUser = 0, const ubigint refPlnrMUsergroup = 0, const uint ixPlnrVUserlevel = 0);
	ubigint appendNewRecToRst(ListPlnrRMUserMUsergroup& rst, PlnrRMUserMUsergroup** rec = NULL, const ubigint refPlnrMUser = 0, const ubigint refPlnrMUsergroup = 0, const uint ixPlnrVUserlevel = 0);
	virtual void insertRst(ListPlnrRMUserMUsergroup& rst, bool transact = false);
	virtual void updateRec(PlnrRMUserMUsergroup* rec);
	virtual void updateRst(ListPlnrRMUserMUsergroup& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, PlnrRMUserMUsergroup** rec);
	virtual ubigint loadRstByUsg(ubigint refPlnrMUsergroup, const bool append, ListPlnrRMUserMUsergroup& rst);
	virtual ubigint loadRstByUsr(ubigint refPlnrMUser, const bool append, ListPlnrRMUserMUsergroup& rst);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListPlnrRMUserMUsergroup& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrRMUserMUsergroup: C++ wrapper for table TblPlnrRMUserMUsergroup (MySQL database)
  */
class MyTblPlnrRMUserMUsergroup : public TblPlnrRMUserMUsergroup, public MyTable {

public:
	MyTblPlnrRMUserMUsergroup();
	~MyTblPlnrRMUserMUsergroup();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrRMUserMUsergroup** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrRMUserMUsergroup& rst);

	void insertRec(PlnrRMUserMUsergroup* rec);
	void insertRst(ListPlnrRMUserMUsergroup& rst, bool transact = false);
	void updateRec(PlnrRMUserMUsergroup* rec);
	void updateRst(ListPlnrRMUserMUsergroup& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrRMUserMUsergroup** rec);
	ubigint loadRstByUsg(ubigint refPlnrMUsergroup, const bool append, ListPlnrRMUserMUsergroup& rst);
	ubigint loadRstByUsr(ubigint refPlnrMUser, const bool append, ListPlnrRMUserMUsergroup& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrRMUserMUsergroup: C++ wrapper for table TblPlnrRMUserMUsergroup (PgSQL database)
  */
class PgTblPlnrRMUserMUsergroup : public TblPlnrRMUserMUsergroup, public PgTable {

public:
	PgTblPlnrRMUserMUsergroup();
	~PgTblPlnrRMUserMUsergroup();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrRMUserMUsergroup** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrRMUserMUsergroup& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrRMUserMUsergroup** rec);
// IP pgLoadRstByStmt --- BEGIN
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrRMUserMUsergroup& rst);
// IP pgLoadRstByStmt --- END

public:
	bool loadRecBySQL(const string& sqlstr, PlnrRMUserMUsergroup** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrRMUserMUsergroup& rst);

	void insertRec(PlnrRMUserMUsergroup* rec);
	void insertRst(ListPlnrRMUserMUsergroup& rst, bool transact = false);
	void updateRec(PlnrRMUserMUsergroup* rec);
	void updateRst(ListPlnrRMUserMUsergroup& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrRMUserMUsergroup** rec);
	ubigint loadRstByUsg(ubigint refPlnrMUsergroup, const bool append, ListPlnrRMUserMUsergroup& rst);
	ubigint loadRstByUsr(ubigint refPlnrMUser, const bool append, ListPlnrRMUserMUsergroup& rst);
};
// IP pgTbl --- END

#endif

