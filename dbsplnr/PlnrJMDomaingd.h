/**
  * \file PlnrJMDomaingd.h
  * database access for table TblPlnrJMDomaingd (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRJMDOMAINGD_H
#define PLNRJMDOMAINGD_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * PlnrJMDomaingd: record of TblPlnrJMDomaingd
  */
class PlnrJMDomaingd {

public:
	PlnrJMDomaingd(const ubigint ref = 0, const ubigint refPlnrMDomaingd = 0, const ubigint x1RefPlnrMDesign = 0, const string d = "", const string dphi = "");

public:
	ubigint ref;
	ubigint refPlnrMDomaingd;
	ubigint x1RefPlnrMDesign;
	string d;
	string dphi;

public:
	bool operator==(const PlnrJMDomaingd& comp);
	bool operator!=(const PlnrJMDomaingd& comp);
};

/**
  * ListPlnrJMDomaingd: recordset of TblPlnrJMDomaingd
  */
class ListPlnrJMDomaingd {

public:
	ListPlnrJMDomaingd();
	ListPlnrJMDomaingd(const ListPlnrJMDomaingd& src);
	~ListPlnrJMDomaingd();

	void clear();
	unsigned int size() const;
	void append(PlnrJMDomaingd* rec);

	PlnrJMDomaingd* operator[](const uint ix);
	ListPlnrJMDomaingd& operator=(const ListPlnrJMDomaingd& src);
	bool operator==(const ListPlnrJMDomaingd& comp);
	bool operator!=(const ListPlnrJMDomaingd& comp);

public:
	vector<PlnrJMDomaingd*> nodes;
};

/**
  * TblPlnrJMDomaingd: C++ wrapper for table TblPlnrJMDomaingd
  */
class TblPlnrJMDomaingd {

public:
	TblPlnrJMDomaingd();
	virtual ~TblPlnrJMDomaingd();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrJMDomaingd** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrJMDomaingd& rst);

	virtual void insertRec(PlnrJMDomaingd* rec);
	ubigint insertNewRec(PlnrJMDomaingd** rec = NULL, const ubigint refPlnrMDomaingd = 0, const ubigint x1RefPlnrMDesign = 0, const string d = "", const string dphi = "");
	ubigint appendNewRecToRst(ListPlnrJMDomaingd& rst, PlnrJMDomaingd** rec = NULL, const ubigint refPlnrMDomaingd = 0, const ubigint x1RefPlnrMDesign = 0, const string d = "", const string dphi = "");
	virtual void insertRst(ListPlnrJMDomaingd& rst, bool transact = false);
	virtual void updateRec(PlnrJMDomaingd* rec);
	virtual void updateRst(ListPlnrJMDomaingd& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, PlnrJMDomaingd** rec);
	virtual bool loadRecByDgdDsn(ubigint refPlnrMDomaingd, ubigint x1RefPlnrMDesign, PlnrJMDomaingd** rec);
	virtual ubigint loadRstByDgd(ubigint refPlnrMDomaingd, const bool append, ListPlnrJMDomaingd& rst);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListPlnrJMDomaingd& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrJMDomaingd: C++ wrapper for table TblPlnrJMDomaingd (MySQL database)
  */
class MyTblPlnrJMDomaingd : public TblPlnrJMDomaingd, public MyTable {

public:
	MyTblPlnrJMDomaingd();
	~MyTblPlnrJMDomaingd();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrJMDomaingd** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrJMDomaingd& rst);

	void insertRec(PlnrJMDomaingd* rec);
	void insertRst(ListPlnrJMDomaingd& rst, bool transact = false);
	void updateRec(PlnrJMDomaingd* rec);
	void updateRst(ListPlnrJMDomaingd& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrJMDomaingd** rec);
	bool loadRecByDgdDsn(ubigint refPlnrMDomaingd, ubigint x1RefPlnrMDesign, PlnrJMDomaingd** rec);
	ubigint loadRstByDgd(ubigint refPlnrMDomaingd, const bool append, ListPlnrJMDomaingd& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrJMDomaingd: C++ wrapper for table TblPlnrJMDomaingd (PgSQL database)
  */
class PgTblPlnrJMDomaingd : public TblPlnrJMDomaingd, public PgTable {

public:
	PgTblPlnrJMDomaingd();
	~PgTblPlnrJMDomaingd();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrJMDomaingd** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrJMDomaingd& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrJMDomaingd** rec);
// IP pgLoadRstByStmt --- BEGIN
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrJMDomaingd& rst);
// IP pgLoadRstByStmt --- END

public:
	bool loadRecBySQL(const string& sqlstr, PlnrJMDomaingd** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrJMDomaingd& rst);

	void insertRec(PlnrJMDomaingd* rec);
	void insertRst(ListPlnrJMDomaingd& rst, bool transact = false);
	void updateRec(PlnrJMDomaingd* rec);
	void updateRst(ListPlnrJMDomaingd& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrJMDomaingd** rec);
	bool loadRecByDgdDsn(ubigint refPlnrMDomaingd, ubigint x1RefPlnrMDesign, PlnrJMDomaingd** rec);
	ubigint loadRstByDgd(ubigint refPlnrMDomaingd, const bool append, ListPlnrJMDomaingd& rst);
};
// IP pgTbl --- END

#endif

