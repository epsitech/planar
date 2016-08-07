/**
  * \file PlnrRMUsergroupUniversal.h
  * database access for table TblPlnrRMUsergroupUniversal (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRRMUSERGROUPUNIVERSAL_H
#define PLNRRMUSERGROUPUNIVERSAL_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * PlnrRMUsergroupUniversal: record of TblPlnrRMUsergroupUniversal
  */
class PlnrRMUsergroupUniversal {

public:
	PlnrRMUsergroupUniversal(const ubigint ref = 0, const ubigint refPlnrMUsergroup = 0, const uint unvIxPlnrVMaintable = 0, const ubigint unvUref = 0, const uint ixPlnrVAccess = 0);

public:
	ubigint ref;
	ubigint refPlnrMUsergroup;
	uint unvIxPlnrVMaintable;
	ubigint unvUref;
	uint ixPlnrVAccess;

public:
	bool operator==(const PlnrRMUsergroupUniversal& comp);
	bool operator!=(const PlnrRMUsergroupUniversal& comp);
};

/**
  * ListPlnrRMUsergroupUniversal: recordset of TblPlnrRMUsergroupUniversal
  */
class ListPlnrRMUsergroupUniversal {

public:
	ListPlnrRMUsergroupUniversal();
	ListPlnrRMUsergroupUniversal(const ListPlnrRMUsergroupUniversal& src);
	~ListPlnrRMUsergroupUniversal();

	void clear();
	unsigned int size() const;
	void append(PlnrRMUsergroupUniversal* rec);

	PlnrRMUsergroupUniversal* operator[](const uint ix);
	ListPlnrRMUsergroupUniversal& operator=(const ListPlnrRMUsergroupUniversal& src);
	bool operator==(const ListPlnrRMUsergroupUniversal& comp);
	bool operator!=(const ListPlnrRMUsergroupUniversal& comp);

public:
	vector<PlnrRMUsergroupUniversal*> nodes;
};

/**
  * TblPlnrRMUsergroupUniversal: C++ wrapper for table TblPlnrRMUsergroupUniversal
  */
class TblPlnrRMUsergroupUniversal {

public:
	TblPlnrRMUsergroupUniversal();
	virtual ~TblPlnrRMUsergroupUniversal();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrRMUsergroupUniversal** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrRMUsergroupUniversal& rst);

	virtual void insertRec(PlnrRMUsergroupUniversal* rec);
	ubigint insertNewRec(PlnrRMUsergroupUniversal** rec = NULL, const ubigint refPlnrMUsergroup = 0, const uint unvIxPlnrVMaintable = 0, const ubigint unvUref = 0, const uint ixPlnrVAccess = 0);
	ubigint appendNewRecToRst(ListPlnrRMUsergroupUniversal& rst, PlnrRMUsergroupUniversal** rec = NULL, const ubigint refPlnrMUsergroup = 0, const uint unvIxPlnrVMaintable = 0, const ubigint unvUref = 0, const uint ixPlnrVAccess = 0);
	virtual void insertRst(ListPlnrRMUsergroupUniversal& rst, bool transact = false);
	virtual void updateRec(PlnrRMUsergroupUniversal* rec);
	virtual void updateRst(ListPlnrRMUsergroupUniversal& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, PlnrRMUsergroupUniversal** rec);
	virtual bool loadRecByUsgMtbUnv(ubigint refPlnrMUsergroup, uint unvIxPlnrVMaintable, ubigint unvUref, PlnrRMUsergroupUniversal** rec);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListPlnrRMUsergroupUniversal& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrRMUsergroupUniversal: C++ wrapper for table TblPlnrRMUsergroupUniversal (MySQL database)
  */
class MyTblPlnrRMUsergroupUniversal : public TblPlnrRMUsergroupUniversal, public MyTable {

public:
	MyTblPlnrRMUsergroupUniversal();
	~MyTblPlnrRMUsergroupUniversal();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrRMUsergroupUniversal** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrRMUsergroupUniversal& rst);

	void insertRec(PlnrRMUsergroupUniversal* rec);
	void insertRst(ListPlnrRMUsergroupUniversal& rst, bool transact = false);
	void updateRec(PlnrRMUsergroupUniversal* rec);
	void updateRst(ListPlnrRMUsergroupUniversal& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrRMUsergroupUniversal** rec);
	bool loadRecByUsgMtbUnv(ubigint refPlnrMUsergroup, uint unvIxPlnrVMaintable, ubigint unvUref, PlnrRMUsergroupUniversal** rec);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrRMUsergroupUniversal: C++ wrapper for table TblPlnrRMUsergroupUniversal (PgSQL database)
  */
class PgTblPlnrRMUsergroupUniversal : public TblPlnrRMUsergroupUniversal, public PgTable {

public:
	PgTblPlnrRMUsergroupUniversal();
	~PgTblPlnrRMUsergroupUniversal();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrRMUsergroupUniversal** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrRMUsergroupUniversal& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrRMUsergroupUniversal** rec);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrRMUsergroupUniversal** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrRMUsergroupUniversal& rst);

	void insertRec(PlnrRMUsergroupUniversal* rec);
	void insertRst(ListPlnrRMUsergroupUniversal& rst, bool transact = false);
	void updateRec(PlnrRMUsergroupUniversal* rec);
	void updateRst(ListPlnrRMUsergroupUniversal& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrRMUsergroupUniversal** rec);
	bool loadRecByUsgMtbUnv(ubigint refPlnrMUsergroup, uint unvIxPlnrVMaintable, ubigint unvUref, PlnrRMUsergroupUniversal** rec);
};
// IP pgTbl --- END

#endif

