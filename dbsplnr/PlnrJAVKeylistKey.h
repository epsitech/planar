/**
  * \file PlnrJAVKeylistKey.h
  * database access for table TblPlnrJAVKeylistKey (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRJAVKEYLISTKEY_H
#define PLNRJAVKEYLISTKEY_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * PlnrJAVKeylistKey: record of TblPlnrJAVKeylistKey
  */
class PlnrJAVKeylistKey {

public:
	PlnrJAVKeylistKey(const ubigint ref = 0, const ubigint refPlnrAVKeylistKey = 0, const uint x1IxPlnrVLocale = 0, const string Title = "", const string Comment = "");

public:
	ubigint ref;
	ubigint refPlnrAVKeylistKey;
	uint x1IxPlnrVLocale;
	string Title;
	string Comment;

public:
	bool operator==(const PlnrJAVKeylistKey& comp);
	bool operator!=(const PlnrJAVKeylistKey& comp);
};

/**
  * ListPlnrJAVKeylistKey: recordset of TblPlnrJAVKeylistKey
  */
class ListPlnrJAVKeylistKey {

public:
	ListPlnrJAVKeylistKey();
	ListPlnrJAVKeylistKey(const ListPlnrJAVKeylistKey& src);
	~ListPlnrJAVKeylistKey();

	void clear();
	unsigned int size() const;
	void append(PlnrJAVKeylistKey* rec);

	PlnrJAVKeylistKey* operator[](const uint ix);
	ListPlnrJAVKeylistKey& operator=(const ListPlnrJAVKeylistKey& src);
	bool operator==(const ListPlnrJAVKeylistKey& comp);
	bool operator!=(const ListPlnrJAVKeylistKey& comp);

public:
	vector<PlnrJAVKeylistKey*> nodes;
};

/**
  * TblPlnrJAVKeylistKey: C++ wrapper for table TblPlnrJAVKeylistKey
  */
class TblPlnrJAVKeylistKey {

public:
	TblPlnrJAVKeylistKey();
	virtual ~TblPlnrJAVKeylistKey();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrJAVKeylistKey** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrJAVKeylistKey& rst);

	virtual void insertRec(PlnrJAVKeylistKey* rec);
	ubigint insertNewRec(PlnrJAVKeylistKey** rec = NULL, const ubigint refPlnrAVKeylistKey = 0, const uint x1IxPlnrVLocale = 0, const string Title = "", const string Comment = "");
	ubigint appendNewRecToRst(ListPlnrJAVKeylistKey& rst, PlnrJAVKeylistKey** rec = NULL, const ubigint refPlnrAVKeylistKey = 0, const uint x1IxPlnrVLocale = 0, const string Title = "", const string Comment = "");
	virtual void insertRst(ListPlnrJAVKeylistKey& rst, bool transact = false);
	virtual void updateRec(PlnrJAVKeylistKey* rec);
	virtual void updateRst(ListPlnrJAVKeylistKey& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, PlnrJAVKeylistKey** rec);
	virtual bool loadRecByKlkLcl(ubigint refPlnrAVKeylistKey, uint x1IxPlnrVLocale, PlnrJAVKeylistKey** rec);
	virtual ubigint loadRefsByKlk(ubigint refPlnrAVKeylistKey, const bool append, vector<ubigint>& refs);
	virtual ubigint loadRstByKlk(ubigint refPlnrAVKeylistKey, const bool append, ListPlnrJAVKeylistKey& rst);
	virtual bool loadTitByKlkLcl(ubigint refPlnrAVKeylistKey, uint x1IxPlnrVLocale, string& val);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListPlnrJAVKeylistKey& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrJAVKeylistKey: C++ wrapper for table TblPlnrJAVKeylistKey (MySQL database)
  */
class MyTblPlnrJAVKeylistKey : public TblPlnrJAVKeylistKey, public MyTable {

public:
	MyTblPlnrJAVKeylistKey();
	~MyTblPlnrJAVKeylistKey();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrJAVKeylistKey** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrJAVKeylistKey& rst);

	void insertRec(PlnrJAVKeylistKey* rec);
	void insertRst(ListPlnrJAVKeylistKey& rst, bool transact = false);
	void updateRec(PlnrJAVKeylistKey* rec);
	void updateRst(ListPlnrJAVKeylistKey& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrJAVKeylistKey** rec);
	bool loadRecByKlkLcl(ubigint refPlnrAVKeylistKey, uint x1IxPlnrVLocale, PlnrJAVKeylistKey** rec);
	ubigint loadRefsByKlk(ubigint refPlnrAVKeylistKey, const bool append, vector<ubigint>& refs);
	ubigint loadRstByKlk(ubigint refPlnrAVKeylistKey, const bool append, ListPlnrJAVKeylistKey& rst);
	bool loadTitByKlkLcl(ubigint refPlnrAVKeylistKey, uint x1IxPlnrVLocale, string& val);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrJAVKeylistKey: C++ wrapper for table TblPlnrJAVKeylistKey (PgSQL database)
  */
class PgTblPlnrJAVKeylistKey : public TblPlnrJAVKeylistKey, public PgTable {

public:
	PgTblPlnrJAVKeylistKey();
	~PgTblPlnrJAVKeylistKey();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrJAVKeylistKey** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrJAVKeylistKey& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrJAVKeylistKey** rec);
// IP pgLoadRstByStmt --- BEGIN
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrJAVKeylistKey& rst);
// IP pgLoadRstByStmt --- END

public:
	bool loadRecBySQL(const string& sqlstr, PlnrJAVKeylistKey** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrJAVKeylistKey& rst);

	void insertRec(PlnrJAVKeylistKey* rec);
	void insertRst(ListPlnrJAVKeylistKey& rst, bool transact = false);
	void updateRec(PlnrJAVKeylistKey* rec);
	void updateRst(ListPlnrJAVKeylistKey& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrJAVKeylistKey** rec);
	bool loadRecByKlkLcl(ubigint refPlnrAVKeylistKey, uint x1IxPlnrVLocale, PlnrJAVKeylistKey** rec);
	ubigint loadRefsByKlk(ubigint refPlnrAVKeylistKey, const bool append, vector<ubigint>& refs);
	ubigint loadRstByKlk(ubigint refPlnrAVKeylistKey, const bool append, ListPlnrJAVKeylistKey& rst);
	bool loadTitByKlkLcl(ubigint refPlnrAVKeylistKey, uint x1IxPlnrVLocale, string& val);
};
// IP pgTbl --- END

#endif

