/**
  * \file PlnrRMStackMStructure.h
  * database access for table TblPlnrRMStackMStructure (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRRMSTACKMSTRUCTURE_H
#define PLNRRMSTACKMSTRUCTURE_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * PlnrRMStackMStructure: record of TblPlnrRMStackMStructure
  */
class PlnrRMStackMStructure {

public:
	PlnrRMStackMStructure(const ubigint ref = 0, const ubigint refPlnrMStack = 0, const ubigint refPlnrMStructure = 0, const string fromSrefPlnrMLayer = "", const string toSrefPlnrMLayer = "");

public:
	ubigint ref;
	ubigint refPlnrMStack;
	ubigint refPlnrMStructure;
	string fromSrefPlnrMLayer;
	string toSrefPlnrMLayer;

public:
	bool operator==(const PlnrRMStackMStructure& comp);
	bool operator!=(const PlnrRMStackMStructure& comp);
};

/**
  * ListPlnrRMStackMStructure: recordset of TblPlnrRMStackMStructure
  */
class ListPlnrRMStackMStructure {

public:
	ListPlnrRMStackMStructure();
	ListPlnrRMStackMStructure(const ListPlnrRMStackMStructure& src);
	~ListPlnrRMStackMStructure();

	void clear();
	unsigned int size() const;
	void append(PlnrRMStackMStructure* rec);

	PlnrRMStackMStructure* operator[](const uint ix);
	ListPlnrRMStackMStructure& operator=(const ListPlnrRMStackMStructure& src);
	bool operator==(const ListPlnrRMStackMStructure& comp);
	bool operator!=(const ListPlnrRMStackMStructure& comp);

public:
	vector<PlnrRMStackMStructure*> nodes;
};

/**
  * TblPlnrRMStackMStructure: C++ wrapper for table TblPlnrRMStackMStructure
  */
class TblPlnrRMStackMStructure {

public:
	TblPlnrRMStackMStructure();
	virtual ~TblPlnrRMStackMStructure();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrRMStackMStructure** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrRMStackMStructure& rst);

	virtual void insertRec(PlnrRMStackMStructure* rec);
	ubigint insertNewRec(PlnrRMStackMStructure** rec = NULL, const ubigint refPlnrMStack = 0, const ubigint refPlnrMStructure = 0, const string fromSrefPlnrMLayer = "", const string toSrefPlnrMLayer = "");
	ubigint appendNewRecToRst(ListPlnrRMStackMStructure& rst, PlnrRMStackMStructure** rec = NULL, const ubigint refPlnrMStack = 0, const ubigint refPlnrMStructure = 0, const string fromSrefPlnrMLayer = "", const string toSrefPlnrMLayer = "");
	virtual void insertRst(ListPlnrRMStackMStructure& rst, bool transact = false);
	virtual void updateRec(PlnrRMStackMStructure* rec);
	virtual void updateRst(ListPlnrRMStackMStructure& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, PlnrRMStackMStructure** rec);
	virtual ubigint loadRstByStk(ubigint refPlnrMStack, const bool append, ListPlnrRMStackMStructure& rst);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListPlnrRMStackMStructure& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrRMStackMStructure: C++ wrapper for table TblPlnrRMStackMStructure (MySQL database)
  */
class MyTblPlnrRMStackMStructure : public TblPlnrRMStackMStructure, public MyTable {

public:
	MyTblPlnrRMStackMStructure();
	~MyTblPlnrRMStackMStructure();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrRMStackMStructure** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrRMStackMStructure& rst);

	void insertRec(PlnrRMStackMStructure* rec);
	void insertRst(ListPlnrRMStackMStructure& rst, bool transact = false);
	void updateRec(PlnrRMStackMStructure* rec);
	void updateRst(ListPlnrRMStackMStructure& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrRMStackMStructure** rec);
	ubigint loadRstByStk(ubigint refPlnrMStack, const bool append, ListPlnrRMStackMStructure& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrRMStackMStructure: C++ wrapper for table TblPlnrRMStackMStructure (PgSQL database)
  */
class PgTblPlnrRMStackMStructure : public TblPlnrRMStackMStructure, public PgTable {

public:
	PgTblPlnrRMStackMStructure();
	~PgTblPlnrRMStackMStructure();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrRMStackMStructure** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrRMStackMStructure& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrRMStackMStructure** rec);
// IP pgLoadRstByStmt --- BEGIN
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrRMStackMStructure& rst);
// IP pgLoadRstByStmt --- END

public:
	bool loadRecBySQL(const string& sqlstr, PlnrRMStackMStructure** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrRMStackMStructure& rst);

	void insertRec(PlnrRMStackMStructure* rec);
	void insertRst(ListPlnrRMStackMStructure& rst, bool transact = false);
	void updateRec(PlnrRMStackMStructure* rec);
	void updateRst(ListPlnrRMStackMStructure& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrRMStackMStructure** rec);
	ubigint loadRstByStk(ubigint refPlnrMStack, const bool append, ListPlnrRMStackMStructure& rst);
};
// IP pgTbl --- END

#endif

