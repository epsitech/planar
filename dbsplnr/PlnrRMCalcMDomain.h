/**
  * \file PlnrRMCalcMDomain.h
  * database access for table TblPlnrRMCalcMDomain (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRRMCALCMDOMAIN_H
#define PLNRRMCALCMDOMAIN_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * PlnrRMCalcMDomain: record of TblPlnrRMCalcMDomain
  */
class PlnrRMCalcMDomain {

public:
	PlnrRMCalcMDomain(const ubigint ref = 0, const ubigint refPlnrMCalc = 0, const ubigint refPlnrMDomain = 0, const string srefPlnrKCalcdomprp = "");

public:
	ubigint ref;
	ubigint refPlnrMCalc;
	ubigint refPlnrMDomain;
	string srefPlnrKCalcdomprp;

public:
	bool operator==(const PlnrRMCalcMDomain& comp);
	bool operator!=(const PlnrRMCalcMDomain& comp);
};

/**
  * ListPlnrRMCalcMDomain: recordset of TblPlnrRMCalcMDomain
  */
class ListPlnrRMCalcMDomain {

public:
	ListPlnrRMCalcMDomain();
	ListPlnrRMCalcMDomain(const ListPlnrRMCalcMDomain& src);
	~ListPlnrRMCalcMDomain();

	void clear();
	unsigned int size() const;
	void append(PlnrRMCalcMDomain* rec);

	PlnrRMCalcMDomain* operator[](const uint ix);
	ListPlnrRMCalcMDomain& operator=(const ListPlnrRMCalcMDomain& src);
	bool operator==(const ListPlnrRMCalcMDomain& comp);
	bool operator!=(const ListPlnrRMCalcMDomain& comp);

public:
	vector<PlnrRMCalcMDomain*> nodes;
};

/**
  * TblPlnrRMCalcMDomain: C++ wrapper for table TblPlnrRMCalcMDomain
  */
class TblPlnrRMCalcMDomain {

public:
	TblPlnrRMCalcMDomain();
	virtual ~TblPlnrRMCalcMDomain();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrRMCalcMDomain** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrRMCalcMDomain& rst);

	virtual void insertRec(PlnrRMCalcMDomain* rec);
	ubigint insertNewRec(PlnrRMCalcMDomain** rec = NULL, const ubigint refPlnrMCalc = 0, const ubigint refPlnrMDomain = 0, const string srefPlnrKCalcdomprp = "");
	ubigint appendNewRecToRst(ListPlnrRMCalcMDomain& rst, PlnrRMCalcMDomain** rec = NULL, const ubigint refPlnrMCalc = 0, const ubigint refPlnrMDomain = 0, const string srefPlnrKCalcdomprp = "");
	virtual void insertRst(ListPlnrRMCalcMDomain& rst, bool transact = false);
	virtual void updateRec(PlnrRMCalcMDomain* rec);
	virtual void updateRst(ListPlnrRMCalcMDomain& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, PlnrRMCalcMDomain** rec);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListPlnrRMCalcMDomain& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrRMCalcMDomain: C++ wrapper for table TblPlnrRMCalcMDomain (MySQL database)
  */
class MyTblPlnrRMCalcMDomain : public TblPlnrRMCalcMDomain, public MyTable {

public:
	MyTblPlnrRMCalcMDomain();
	~MyTblPlnrRMCalcMDomain();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrRMCalcMDomain** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrRMCalcMDomain& rst);

	void insertRec(PlnrRMCalcMDomain* rec);
	void insertRst(ListPlnrRMCalcMDomain& rst, bool transact = false);
	void updateRec(PlnrRMCalcMDomain* rec);
	void updateRst(ListPlnrRMCalcMDomain& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrRMCalcMDomain** rec);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrRMCalcMDomain: C++ wrapper for table TblPlnrRMCalcMDomain (PgSQL database)
  */
class PgTblPlnrRMCalcMDomain : public TblPlnrRMCalcMDomain, public PgTable {

public:
	PgTblPlnrRMCalcMDomain();
	~PgTblPlnrRMCalcMDomain();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrRMCalcMDomain** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrRMCalcMDomain& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrRMCalcMDomain** rec);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrRMCalcMDomain** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrRMCalcMDomain& rst);

	void insertRec(PlnrRMCalcMDomain* rec);
	void insertRst(ListPlnrRMCalcMDomain& rst, bool transact = false);
	void updateRec(PlnrRMCalcMDomain* rec);
	void updateRst(ListPlnrRMCalcMDomain& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrRMCalcMDomain** rec);
};
// IP pgTbl --- END

#endif

