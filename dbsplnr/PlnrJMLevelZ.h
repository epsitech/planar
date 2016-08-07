/**
  * \file PlnrJMLevelZ.h
  * database access for table TblPlnrJMLevelZ (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRJMLEVELZ_H
#define PLNRJMLEVELZ_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * PlnrJMLevelZ: record of TblPlnrJMLevelZ
  */
class PlnrJMLevelZ {

public:
	PlnrJMLevelZ(const ubigint ref = 0, const ubigint refPlnrMLevel = 0, const ubigint x1RefPlnrMDesign = 0, const double z = 0.0);

public:
	ubigint ref;
	ubigint refPlnrMLevel;
	ubigint x1RefPlnrMDesign;
	double z;

public:
	bool operator==(const PlnrJMLevelZ& comp);
	bool operator!=(const PlnrJMLevelZ& comp);
};

/**
  * ListPlnrJMLevelZ: recordset of TblPlnrJMLevelZ
  */
class ListPlnrJMLevelZ {

public:
	ListPlnrJMLevelZ();
	ListPlnrJMLevelZ(const ListPlnrJMLevelZ& src);
	~ListPlnrJMLevelZ();

	void clear();
	unsigned int size() const;
	void append(PlnrJMLevelZ* rec);

	PlnrJMLevelZ* operator[](const uint ix);
	ListPlnrJMLevelZ& operator=(const ListPlnrJMLevelZ& src);
	bool operator==(const ListPlnrJMLevelZ& comp);
	bool operator!=(const ListPlnrJMLevelZ& comp);

public:
	vector<PlnrJMLevelZ*> nodes;
};

/**
  * TblPlnrJMLevelZ: C++ wrapper for table TblPlnrJMLevelZ
  */
class TblPlnrJMLevelZ {

public:
	TblPlnrJMLevelZ();
	virtual ~TblPlnrJMLevelZ();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrJMLevelZ** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrJMLevelZ& rst);

	virtual void insertRec(PlnrJMLevelZ* rec);
	ubigint insertNewRec(PlnrJMLevelZ** rec = NULL, const ubigint refPlnrMLevel = 0, const ubigint x1RefPlnrMDesign = 0, const double z = 0.0);
	ubigint appendNewRecToRst(ListPlnrJMLevelZ& rst, PlnrJMLevelZ** rec = NULL, const ubigint refPlnrMLevel = 0, const ubigint x1RefPlnrMDesign = 0, const double z = 0.0);
	virtual void insertRst(ListPlnrJMLevelZ& rst, bool transact = false);
	virtual void updateRec(PlnrJMLevelZ* rec);
	virtual void updateRst(ListPlnrJMLevelZ& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, PlnrJMLevelZ** rec);
	virtual bool loadRecByLvlDsn(ubigint refPlnrMLevel, ubigint x1RefPlnrMDesign, PlnrJMLevelZ** rec);
	virtual ubigint loadRstByLvl(ubigint refPlnrMLevel, const bool append, ListPlnrJMLevelZ& rst);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListPlnrJMLevelZ& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrJMLevelZ: C++ wrapper for table TblPlnrJMLevelZ (MySQL database)
  */
class MyTblPlnrJMLevelZ : public TblPlnrJMLevelZ, public MyTable {

public:
	MyTblPlnrJMLevelZ();
	~MyTblPlnrJMLevelZ();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrJMLevelZ** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrJMLevelZ& rst);

	void insertRec(PlnrJMLevelZ* rec);
	void insertRst(ListPlnrJMLevelZ& rst, bool transact = false);
	void updateRec(PlnrJMLevelZ* rec);
	void updateRst(ListPlnrJMLevelZ& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrJMLevelZ** rec);
	bool loadRecByLvlDsn(ubigint refPlnrMLevel, ubigint x1RefPlnrMDesign, PlnrJMLevelZ** rec);
	ubigint loadRstByLvl(ubigint refPlnrMLevel, const bool append, ListPlnrJMLevelZ& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrJMLevelZ: C++ wrapper for table TblPlnrJMLevelZ (PgSQL database)
  */
class PgTblPlnrJMLevelZ : public TblPlnrJMLevelZ, public PgTable {

public:
	PgTblPlnrJMLevelZ();
	~PgTblPlnrJMLevelZ();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrJMLevelZ** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrJMLevelZ& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrJMLevelZ** rec);
// IP pgLoadRstByStmt --- BEGIN
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrJMLevelZ& rst);
// IP pgLoadRstByStmt --- END

public:
	bool loadRecBySQL(const string& sqlstr, PlnrJMLevelZ** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrJMLevelZ& rst);

	void insertRec(PlnrJMLevelZ* rec);
	void insertRst(ListPlnrJMLevelZ& rst, bool transact = false);
	void updateRec(PlnrJMLevelZ* rec);
	void updateRst(ListPlnrJMLevelZ& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrJMLevelZ** rec);
	bool loadRecByLvlDsn(ubigint refPlnrMLevel, ubigint x1RefPlnrMDesign, PlnrJMLevelZ** rec);
	ubigint loadRstByLvl(ubigint refPlnrMLevel, const bool append, ListPlnrJMLevelZ& rst);
};
// IP pgTbl --- END

#endif

