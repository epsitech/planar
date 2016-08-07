/**
  * \file PlnrJMDomain.h
  * database access for table TblPlnrJMDomain (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRJMDOMAIN_H
#define PLNRJMDOMAIN_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * PlnrJMDomain: record of TblPlnrJMDomain
  */
class PlnrJMDomain {

public:
	PlnrJMDomain(const ubigint ref = 0, const ubigint refPlnrMDomain = 0, const ubigint x1RefPlnrMDesign = 0, const string dx = "", const string dy = "", const string dxy = "", const string dz = "");

public:
	ubigint ref;
	ubigint refPlnrMDomain;
	ubigint x1RefPlnrMDesign;
	string dx;
	string dy;
	string dxy;
	string dz;

public:
	bool operator==(const PlnrJMDomain& comp);
	bool operator!=(const PlnrJMDomain& comp);
};

/**
  * ListPlnrJMDomain: recordset of TblPlnrJMDomain
  */
class ListPlnrJMDomain {

public:
	ListPlnrJMDomain();
	ListPlnrJMDomain(const ListPlnrJMDomain& src);
	~ListPlnrJMDomain();

	void clear();
	unsigned int size() const;
	void append(PlnrJMDomain* rec);

	PlnrJMDomain* operator[](const uint ix);
	ListPlnrJMDomain& operator=(const ListPlnrJMDomain& src);
	bool operator==(const ListPlnrJMDomain& comp);
	bool operator!=(const ListPlnrJMDomain& comp);

public:
	vector<PlnrJMDomain*> nodes;
};

/**
  * TblPlnrJMDomain: C++ wrapper for table TblPlnrJMDomain
  */
class TblPlnrJMDomain {

public:
	TblPlnrJMDomain();
	virtual ~TblPlnrJMDomain();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrJMDomain** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrJMDomain& rst);

	virtual void insertRec(PlnrJMDomain* rec);
	ubigint insertNewRec(PlnrJMDomain** rec = NULL, const ubigint refPlnrMDomain = 0, const ubigint x1RefPlnrMDesign = 0, const string dx = "", const string dy = "", const string dxy = "", const string dz = "");
	ubigint appendNewRecToRst(ListPlnrJMDomain& rst, PlnrJMDomain** rec = NULL, const ubigint refPlnrMDomain = 0, const ubigint x1RefPlnrMDesign = 0, const string dx = "", const string dy = "", const string dxy = "", const string dz = "");
	virtual void insertRst(ListPlnrJMDomain& rst, bool transact = false);
	virtual void updateRec(PlnrJMDomain* rec);
	virtual void updateRst(ListPlnrJMDomain& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, PlnrJMDomain** rec);
	virtual bool loadRecByDomDsn(ubigint refPlnrMDomain, ubigint x1RefPlnrMDesign, PlnrJMDomain** rec);
	virtual ubigint loadRstByDom(ubigint refPlnrMDomain, const bool append, ListPlnrJMDomain& rst);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListPlnrJMDomain& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrJMDomain: C++ wrapper for table TblPlnrJMDomain (MySQL database)
  */
class MyTblPlnrJMDomain : public TblPlnrJMDomain, public MyTable {

public:
	MyTblPlnrJMDomain();
	~MyTblPlnrJMDomain();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrJMDomain** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrJMDomain& rst);

	void insertRec(PlnrJMDomain* rec);
	void insertRst(ListPlnrJMDomain& rst, bool transact = false);
	void updateRec(PlnrJMDomain* rec);
	void updateRst(ListPlnrJMDomain& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrJMDomain** rec);
	bool loadRecByDomDsn(ubigint refPlnrMDomain, ubigint x1RefPlnrMDesign, PlnrJMDomain** rec);
	ubigint loadRstByDom(ubigint refPlnrMDomain, const bool append, ListPlnrJMDomain& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrJMDomain: C++ wrapper for table TblPlnrJMDomain (PgSQL database)
  */
class PgTblPlnrJMDomain : public TblPlnrJMDomain, public PgTable {

public:
	PgTblPlnrJMDomain();
	~PgTblPlnrJMDomain();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrJMDomain** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrJMDomain& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrJMDomain** rec);
// IP pgLoadRstByStmt --- BEGIN
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrJMDomain& rst);
// IP pgLoadRstByStmt --- END

public:
	bool loadRecBySQL(const string& sqlstr, PlnrJMDomain** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrJMDomain& rst);

	void insertRec(PlnrJMDomain* rec);
	void insertRst(ListPlnrJMDomain& rst, bool transact = false);
	void updateRec(PlnrJMDomain* rec);
	void updateRst(ListPlnrJMDomain& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrJMDomain** rec);
	bool loadRecByDomDsn(ubigint refPlnrMDomain, ubigint x1RefPlnrMDesign, PlnrJMDomain** rec);
	ubigint loadRstByDom(ubigint refPlnrMDomain, const bool append, ListPlnrJMDomain& rst);
};
// IP pgTbl --- END

#endif

