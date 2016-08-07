/**
  * \file PlnrJMStackModtype.h
  * database access for table TblPlnrJMStackModtype (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRJMSTACKMODTYPE_H
#define PLNRJMSTACKMODTYPE_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * PlnrJMStackModtype: record of TblPlnrJMStackModtype
  */
class PlnrJMStackModtype {

public:
	PlnrJMStackModtype(const ubigint ref = 0, const ubigint refPlnrMStack = 0, const ubigint x1RefPlnrMDesign = 0, const uint ixVModtype = 0);

public:
	ubigint ref;
	ubigint refPlnrMStack;
	ubigint x1RefPlnrMDesign;
	uint ixVModtype;

public:
	bool operator==(const PlnrJMStackModtype& comp);
	bool operator!=(const PlnrJMStackModtype& comp);
};

/**
  * ListPlnrJMStackModtype: recordset of TblPlnrJMStackModtype
  */
class ListPlnrJMStackModtype {

public:
	ListPlnrJMStackModtype();
	ListPlnrJMStackModtype(const ListPlnrJMStackModtype& src);
	~ListPlnrJMStackModtype();

	void clear();
	unsigned int size() const;
	void append(PlnrJMStackModtype* rec);

	PlnrJMStackModtype* operator[](const uint ix);
	ListPlnrJMStackModtype& operator=(const ListPlnrJMStackModtype& src);
	bool operator==(const ListPlnrJMStackModtype& comp);
	bool operator!=(const ListPlnrJMStackModtype& comp);

public:
	vector<PlnrJMStackModtype*> nodes;
};

/**
  * TblPlnrJMStackModtype: C++ wrapper for table TblPlnrJMStackModtype
  */
class TblPlnrJMStackModtype {

public:
	TblPlnrJMStackModtype();
	virtual ~TblPlnrJMStackModtype();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrJMStackModtype** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrJMStackModtype& rst);

	virtual void insertRec(PlnrJMStackModtype* rec);
	ubigint insertNewRec(PlnrJMStackModtype** rec = NULL, const ubigint refPlnrMStack = 0, const ubigint x1RefPlnrMDesign = 0, const uint ixVModtype = 0);
	ubigint appendNewRecToRst(ListPlnrJMStackModtype& rst, PlnrJMStackModtype** rec = NULL, const ubigint refPlnrMStack = 0, const ubigint x1RefPlnrMDesign = 0, const uint ixVModtype = 0);
	virtual void insertRst(ListPlnrJMStackModtype& rst, bool transact = false);
	virtual void updateRec(PlnrJMStackModtype* rec);
	virtual void updateRst(ListPlnrJMStackModtype& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, PlnrJMStackModtype** rec);
	virtual bool loadRecByStkDsn(ubigint refPlnrMStack, ubigint x1RefPlnrMDesign, PlnrJMStackModtype** rec);
	virtual ubigint loadRstByStk(ubigint refPlnrMStack, const bool append, ListPlnrJMStackModtype& rst);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListPlnrJMStackModtype& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrJMStackModtype: C++ wrapper for table TblPlnrJMStackModtype (MySQL database)
  */
class MyTblPlnrJMStackModtype : public TblPlnrJMStackModtype, public MyTable {

public:
	MyTblPlnrJMStackModtype();
	~MyTblPlnrJMStackModtype();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrJMStackModtype** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrJMStackModtype& rst);

	void insertRec(PlnrJMStackModtype* rec);
	void insertRst(ListPlnrJMStackModtype& rst, bool transact = false);
	void updateRec(PlnrJMStackModtype* rec);
	void updateRst(ListPlnrJMStackModtype& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrJMStackModtype** rec);
	bool loadRecByStkDsn(ubigint refPlnrMStack, ubigint x1RefPlnrMDesign, PlnrJMStackModtype** rec);
	ubigint loadRstByStk(ubigint refPlnrMStack, const bool append, ListPlnrJMStackModtype& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrJMStackModtype: C++ wrapper for table TblPlnrJMStackModtype (PgSQL database)
  */
class PgTblPlnrJMStackModtype : public TblPlnrJMStackModtype, public PgTable {

public:
	PgTblPlnrJMStackModtype();
	~PgTblPlnrJMStackModtype();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrJMStackModtype** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrJMStackModtype& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrJMStackModtype** rec);
// IP pgLoadRstByStmt --- BEGIN
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrJMStackModtype& rst);
// IP pgLoadRstByStmt --- END

public:
	bool loadRecBySQL(const string& sqlstr, PlnrJMStackModtype** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrJMStackModtype& rst);

	void insertRec(PlnrJMStackModtype* rec);
	void insertRst(ListPlnrJMStackModtype& rst, bool transact = false);
	void updateRec(PlnrJMStackModtype* rec);
	void updateRst(ListPlnrJMStackModtype& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrJMStackModtype** rec);
	bool loadRecByStkDsn(ubigint refPlnrMStack, ubigint x1RefPlnrMDesign, PlnrJMStackModtype** rec);
	ubigint loadRstByStk(ubigint refPlnrMStack, const bool append, ListPlnrJMStackModtype& rst);
};
// IP pgTbl --- END

#endif

