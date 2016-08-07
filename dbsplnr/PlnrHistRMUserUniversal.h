/**
  * \file PlnrHistRMUserUniversal.h
  * database access for table TblPlnrHistRMUserUniversal (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRHISTRMUSERUNIVERSAL_H
#define PLNRHISTRMUSERUNIVERSAL_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * PlnrHistRMUserUniversal: record of TblPlnrHistRMUserUniversal
  */
class PlnrHistRMUserUniversal {

public:
	PlnrHistRMUserUniversal(const ubigint ref = 0, const ubigint refPlnrMUser = 0, const uint unvIxPlnrVMaintable = 0, const ubigint unvUref = 0, const uint ixPlnrVCard = 0, const uint ixPlnrVPreset = 0, const uint preIxPlnrVMaintable = 0, const ubigint preUref = 0, const uint start = 0);

public:
	ubigint ref;
	ubigint refPlnrMUser;
	uint unvIxPlnrVMaintable;
	ubigint unvUref;
	uint ixPlnrVCard;
	uint ixPlnrVPreset;
	uint preIxPlnrVMaintable;
	ubigint preUref;
	uint start;

public:
	bool operator==(const PlnrHistRMUserUniversal& comp);
	bool operator!=(const PlnrHistRMUserUniversal& comp);
};

/**
  * ListPlnrHistRMUserUniversal: recordset of TblPlnrHistRMUserUniversal
  */
class ListPlnrHistRMUserUniversal {

public:
	ListPlnrHistRMUserUniversal();
	ListPlnrHistRMUserUniversal(const ListPlnrHistRMUserUniversal& src);
	~ListPlnrHistRMUserUniversal();

	void clear();
	unsigned int size() const;
	void append(PlnrHistRMUserUniversal* rec);

	PlnrHistRMUserUniversal* operator[](const uint ix);
	ListPlnrHistRMUserUniversal& operator=(const ListPlnrHistRMUserUniversal& src);
	bool operator==(const ListPlnrHistRMUserUniversal& comp);
	bool operator!=(const ListPlnrHistRMUserUniversal& comp);

public:
	vector<PlnrHistRMUserUniversal*> nodes;
};

/**
  * TblPlnrHistRMUserUniversal: C++ wrapper for table TblPlnrHistRMUserUniversal
  */
class TblPlnrHistRMUserUniversal {

public:
	TblPlnrHistRMUserUniversal();
	virtual ~TblPlnrHistRMUserUniversal();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrHistRMUserUniversal** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrHistRMUserUniversal& rst);

	virtual void insertRec(PlnrHistRMUserUniversal* rec);
	ubigint insertNewRec(PlnrHistRMUserUniversal** rec = NULL, const ubigint refPlnrMUser = 0, const uint unvIxPlnrVMaintable = 0, const ubigint unvUref = 0, const uint ixPlnrVCard = 0, const uint ixPlnrVPreset = 0, const uint preIxPlnrVMaintable = 0, const ubigint preUref = 0, const uint start = 0);
	ubigint appendNewRecToRst(ListPlnrHistRMUserUniversal& rst, PlnrHistRMUserUniversal** rec = NULL, const ubigint refPlnrMUser = 0, const uint unvIxPlnrVMaintable = 0, const ubigint unvUref = 0, const uint ixPlnrVCard = 0, const uint ixPlnrVPreset = 0, const uint preIxPlnrVMaintable = 0, const ubigint preUref = 0, const uint start = 0);
	virtual void insertRst(ListPlnrHistRMUserUniversal& rst, bool transact = false);
	virtual void updateRec(PlnrHistRMUserUniversal* rec);
	virtual void updateRst(ListPlnrHistRMUserUniversal& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, PlnrHistRMUserUniversal** rec);
	virtual ubigint loadRstByUsrCrd(ubigint refPlnrMUser, uint ixPlnrVCard, const bool append, ListPlnrHistRMUserUniversal& rst);
	virtual bool loadUnuByRef(ubigint ref, ubigint& val);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListPlnrHistRMUserUniversal& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrHistRMUserUniversal: C++ wrapper for table TblPlnrHistRMUserUniversal (MySQL database)
  */
class MyTblPlnrHistRMUserUniversal : public TblPlnrHistRMUserUniversal, public MyTable {

public:
	MyTblPlnrHistRMUserUniversal();
	~MyTblPlnrHistRMUserUniversal();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrHistRMUserUniversal** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrHistRMUserUniversal& rst);

	void insertRec(PlnrHistRMUserUniversal* rec);
	void insertRst(ListPlnrHistRMUserUniversal& rst, bool transact = false);
	void updateRec(PlnrHistRMUserUniversal* rec);
	void updateRst(ListPlnrHistRMUserUniversal& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrHistRMUserUniversal** rec);
	ubigint loadRstByUsrCrd(ubigint refPlnrMUser, uint ixPlnrVCard, const bool append, ListPlnrHistRMUserUniversal& rst);
	bool loadUnuByRef(ubigint ref, ubigint& val);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrHistRMUserUniversal: C++ wrapper for table TblPlnrHistRMUserUniversal (PgSQL database)
  */
class PgTblPlnrHistRMUserUniversal : public TblPlnrHistRMUserUniversal, public PgTable {

public:
	PgTblPlnrHistRMUserUniversal();
	~PgTblPlnrHistRMUserUniversal();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrHistRMUserUniversal** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrHistRMUserUniversal& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrHistRMUserUniversal** rec);
// IP pgLoadRstByStmt --- BEGIN
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrHistRMUserUniversal& rst);
// IP pgLoadRstByStmt --- END

public:
	bool loadRecBySQL(const string& sqlstr, PlnrHistRMUserUniversal** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrHistRMUserUniversal& rst);

	void insertRec(PlnrHistRMUserUniversal* rec);
	void insertRst(ListPlnrHistRMUserUniversal& rst, bool transact = false);
	void updateRec(PlnrHistRMUserUniversal* rec);
	void updateRst(ListPlnrHistRMUserUniversal& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrHistRMUserUniversal** rec);
	ubigint loadRstByUsrCrd(ubigint refPlnrMUser, uint ixPlnrVCard, const bool append, ListPlnrHistRMUserUniversal& rst);
	bool loadUnuByRef(ubigint ref, ubigint& val);
};
// IP pgTbl --- END

#endif

