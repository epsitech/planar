/**
  * \file PlnrAccRMUserUniversal.h
  * database access for table TblPlnrAccRMUserUniversal (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRACCRMUSERUNIVERSAL_H
#define PLNRACCRMUSERUNIVERSAL_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * PlnrAccRMUserUniversal: record of TblPlnrAccRMUserUniversal
  */
class PlnrAccRMUserUniversal {

public:
	PlnrAccRMUserUniversal(const ubigint ref = 0, const ubigint refPlnrMUser = 0, const uint unvIxPlnrVMaintable = 0, const ubigint unvUref = 0, const uint ixPlnrVAccess = 0);

public:
	ubigint ref;
	ubigint refPlnrMUser;
	uint unvIxPlnrVMaintable;
	ubigint unvUref;
	uint ixPlnrVAccess;

public:
	bool operator==(const PlnrAccRMUserUniversal& comp);
	bool operator!=(const PlnrAccRMUserUniversal& comp);
};

/**
  * ListPlnrAccRMUserUniversal: recordset of TblPlnrAccRMUserUniversal
  */
class ListPlnrAccRMUserUniversal {

public:
	ListPlnrAccRMUserUniversal();
	ListPlnrAccRMUserUniversal(const ListPlnrAccRMUserUniversal& src);
	~ListPlnrAccRMUserUniversal();

	void clear();
	unsigned int size() const;
	void append(PlnrAccRMUserUniversal* rec);

	PlnrAccRMUserUniversal* operator[](const uint ix);
	ListPlnrAccRMUserUniversal& operator=(const ListPlnrAccRMUserUniversal& src);
	bool operator==(const ListPlnrAccRMUserUniversal& comp);
	bool operator!=(const ListPlnrAccRMUserUniversal& comp);

public:
	vector<PlnrAccRMUserUniversal*> nodes;
};

/**
  * TblPlnrAccRMUserUniversal: C++ wrapper for table TblPlnrAccRMUserUniversal
  */
class TblPlnrAccRMUserUniversal {

public:
	TblPlnrAccRMUserUniversal();
	virtual ~TblPlnrAccRMUserUniversal();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrAccRMUserUniversal** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrAccRMUserUniversal& rst);

	virtual void insertRec(PlnrAccRMUserUniversal* rec);
	ubigint insertNewRec(PlnrAccRMUserUniversal** rec = NULL, const ubigint refPlnrMUser = 0, const uint unvIxPlnrVMaintable = 0, const ubigint unvUref = 0, const uint ixPlnrVAccess = 0);
	ubigint appendNewRecToRst(ListPlnrAccRMUserUniversal& rst, PlnrAccRMUserUniversal** rec = NULL, const ubigint refPlnrMUser = 0, const uint unvIxPlnrVMaintable = 0, const ubigint unvUref = 0, const uint ixPlnrVAccess = 0);
	virtual void insertRst(ListPlnrAccRMUserUniversal& rst, bool transact = false);
	virtual void updateRec(PlnrAccRMUserUniversal* rec);
	virtual void updateRst(ListPlnrAccRMUserUniversal& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, PlnrAccRMUserUniversal** rec);
	virtual bool loadRecByUsrMtbUnv(ubigint refPlnrMUser, uint unvIxPlnrVMaintable, ubigint unvUref, PlnrAccRMUserUniversal** rec);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListPlnrAccRMUserUniversal& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrAccRMUserUniversal: C++ wrapper for table TblPlnrAccRMUserUniversal (MySQL database)
  */
class MyTblPlnrAccRMUserUniversal : public TblPlnrAccRMUserUniversal, public MyTable {

public:
	MyTblPlnrAccRMUserUniversal();
	~MyTblPlnrAccRMUserUniversal();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrAccRMUserUniversal** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrAccRMUserUniversal& rst);

	void insertRec(PlnrAccRMUserUniversal* rec);
	void insertRst(ListPlnrAccRMUserUniversal& rst, bool transact = false);
	void updateRec(PlnrAccRMUserUniversal* rec);
	void updateRst(ListPlnrAccRMUserUniversal& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrAccRMUserUniversal** rec);
	bool loadRecByUsrMtbUnv(ubigint refPlnrMUser, uint unvIxPlnrVMaintable, ubigint unvUref, PlnrAccRMUserUniversal** rec);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrAccRMUserUniversal: C++ wrapper for table TblPlnrAccRMUserUniversal (PgSQL database)
  */
class PgTblPlnrAccRMUserUniversal : public TblPlnrAccRMUserUniversal, public PgTable {

public:
	PgTblPlnrAccRMUserUniversal();
	~PgTblPlnrAccRMUserUniversal();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrAccRMUserUniversal** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrAccRMUserUniversal& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrAccRMUserUniversal** rec);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrAccRMUserUniversal** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrAccRMUserUniversal& rst);

	void insertRec(PlnrAccRMUserUniversal* rec);
	void insertRst(ListPlnrAccRMUserUniversal& rst, bool transact = false);
	void updateRec(PlnrAccRMUserUniversal* rec);
	void updateRst(ListPlnrAccRMUserUniversal& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrAccRMUserUniversal** rec);
	bool loadRecByUsrMtbUnv(ubigint refPlnrMUser, uint unvIxPlnrVMaintable, ubigint unvUref, PlnrAccRMUserUniversal** rec);
};
// IP pgTbl --- END

#endif

