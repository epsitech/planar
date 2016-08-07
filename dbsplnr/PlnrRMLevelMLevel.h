/**
  * \file PlnrRMLevelMLevel.h
  * database access for table TblPlnrRMLevelMLevel (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRRMLEVELMLEVEL_H
#define PLNRRMLEVELMLEVEL_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * PlnrRMLevelMLevel: record of TblPlnrRMLevelMLevel
  */
class PlnrRMLevelMLevel {

public:
	PlnrRMLevelMLevel(const ubigint ref = 0, const ubigint stkRefPlnrMLevel = 0, const ubigint dsnRefPlnrMLevel = 0);

public:
	ubigint ref;
	ubigint stkRefPlnrMLevel;
	ubigint dsnRefPlnrMLevel;

public:
	bool operator==(const PlnrRMLevelMLevel& comp);
	bool operator!=(const PlnrRMLevelMLevel& comp);
};

/**
  * ListPlnrRMLevelMLevel: recordset of TblPlnrRMLevelMLevel
  */
class ListPlnrRMLevelMLevel {

public:
	ListPlnrRMLevelMLevel();
	ListPlnrRMLevelMLevel(const ListPlnrRMLevelMLevel& src);
	~ListPlnrRMLevelMLevel();

	void clear();
	unsigned int size() const;
	void append(PlnrRMLevelMLevel* rec);

	PlnrRMLevelMLevel* operator[](const uint ix);
	ListPlnrRMLevelMLevel& operator=(const ListPlnrRMLevelMLevel& src);
	bool operator==(const ListPlnrRMLevelMLevel& comp);
	bool operator!=(const ListPlnrRMLevelMLevel& comp);

public:
	vector<PlnrRMLevelMLevel*> nodes;
};

/**
  * TblPlnrRMLevelMLevel: C++ wrapper for table TblPlnrRMLevelMLevel
  */
class TblPlnrRMLevelMLevel {

public:
	TblPlnrRMLevelMLevel();
	virtual ~TblPlnrRMLevelMLevel();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrRMLevelMLevel** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrRMLevelMLevel& rst);

	virtual void insertRec(PlnrRMLevelMLevel* rec);
	ubigint insertNewRec(PlnrRMLevelMLevel** rec = NULL, const ubigint stkRefPlnrMLevel = 0, const ubigint dsnRefPlnrMLevel = 0);
	ubigint appendNewRecToRst(ListPlnrRMLevelMLevel& rst, PlnrRMLevelMLevel** rec = NULL, const ubigint stkRefPlnrMLevel = 0, const ubigint dsnRefPlnrMLevel = 0);
	virtual void insertRst(ListPlnrRMLevelMLevel& rst, bool transact = false);
	virtual void updateRec(PlnrRMLevelMLevel* rec);
	virtual void updateRst(ListPlnrRMLevelMLevel& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, PlnrRMLevelMLevel** rec);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListPlnrRMLevelMLevel& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrRMLevelMLevel: C++ wrapper for table TblPlnrRMLevelMLevel (MySQL database)
  */
class MyTblPlnrRMLevelMLevel : public TblPlnrRMLevelMLevel, public MyTable {

public:
	MyTblPlnrRMLevelMLevel();
	~MyTblPlnrRMLevelMLevel();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrRMLevelMLevel** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrRMLevelMLevel& rst);

	void insertRec(PlnrRMLevelMLevel* rec);
	void insertRst(ListPlnrRMLevelMLevel& rst, bool transact = false);
	void updateRec(PlnrRMLevelMLevel* rec);
	void updateRst(ListPlnrRMLevelMLevel& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrRMLevelMLevel** rec);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrRMLevelMLevel: C++ wrapper for table TblPlnrRMLevelMLevel (PgSQL database)
  */
class PgTblPlnrRMLevelMLevel : public TblPlnrRMLevelMLevel, public PgTable {

public:
	PgTblPlnrRMLevelMLevel();
	~PgTblPlnrRMLevelMLevel();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrRMLevelMLevel** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrRMLevelMLevel& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrRMLevelMLevel** rec);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrRMLevelMLevel** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrRMLevelMLevel& rst);

	void insertRec(PlnrRMLevelMLevel* rec);
	void insertRst(ListPlnrRMLevelMLevel& rst, bool transact = false);
	void updateRec(PlnrRMLevelMLevel* rec);
	void updateRst(ListPlnrRMLevelMLevel& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrRMLevelMLevel** rec);
};
// IP pgTbl --- END

#endif

