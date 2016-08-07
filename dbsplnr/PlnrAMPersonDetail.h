/**
  * \file PlnrAMPersonDetail.h
  * database access for table TblPlnrAMPersonDetail (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRAMPERSONDETAIL_H
#define PLNRAMPERSONDETAIL_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * PlnrAMPersonDetail: record of TblPlnrAMPersonDetail
  */
class PlnrAMPersonDetail {

public:
	PlnrAMPersonDetail(const ubigint ref = 0, const ubigint refPlnrMPerson = 0, const string x1SrefKType = "", const string Val = "");

public:
	ubigint ref;
	ubigint refPlnrMPerson;
	string x1SrefKType;
	string Val;

public:
	bool operator==(const PlnrAMPersonDetail& comp);
	bool operator!=(const PlnrAMPersonDetail& comp);
};

/**
  * ListPlnrAMPersonDetail: recordset of TblPlnrAMPersonDetail
  */
class ListPlnrAMPersonDetail {

public:
	ListPlnrAMPersonDetail();
	ListPlnrAMPersonDetail(const ListPlnrAMPersonDetail& src);
	~ListPlnrAMPersonDetail();

	void clear();
	unsigned int size() const;
	void append(PlnrAMPersonDetail* rec);

	PlnrAMPersonDetail* operator[](const uint ix);
	ListPlnrAMPersonDetail& operator=(const ListPlnrAMPersonDetail& src);
	bool operator==(const ListPlnrAMPersonDetail& comp);
	bool operator!=(const ListPlnrAMPersonDetail& comp);

public:
	vector<PlnrAMPersonDetail*> nodes;
};

/**
  * TblPlnrAMPersonDetail: C++ wrapper for table TblPlnrAMPersonDetail
  */
class TblPlnrAMPersonDetail {

public:
	TblPlnrAMPersonDetail();
	virtual ~TblPlnrAMPersonDetail();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrAMPersonDetail** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrAMPersonDetail& rst);

	virtual void insertRec(PlnrAMPersonDetail* rec);
	ubigint insertNewRec(PlnrAMPersonDetail** rec = NULL, const ubigint refPlnrMPerson = 0, const string x1SrefKType = "", const string Val = "");
	ubigint appendNewRecToRst(ListPlnrAMPersonDetail& rst, PlnrAMPersonDetail** rec = NULL, const ubigint refPlnrMPerson = 0, const string x1SrefKType = "", const string Val = "");
	virtual void insertRst(ListPlnrAMPersonDetail& rst, bool transact = false);
	virtual void updateRec(PlnrAMPersonDetail* rec);
	virtual void updateRst(ListPlnrAMPersonDetail& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, PlnrAMPersonDetail** rec);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListPlnrAMPersonDetail& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrAMPersonDetail: C++ wrapper for table TblPlnrAMPersonDetail (MySQL database)
  */
class MyTblPlnrAMPersonDetail : public TblPlnrAMPersonDetail, public MyTable {

public:
	MyTblPlnrAMPersonDetail();
	~MyTblPlnrAMPersonDetail();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrAMPersonDetail** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrAMPersonDetail& rst);

	void insertRec(PlnrAMPersonDetail* rec);
	void insertRst(ListPlnrAMPersonDetail& rst, bool transact = false);
	void updateRec(PlnrAMPersonDetail* rec);
	void updateRst(ListPlnrAMPersonDetail& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrAMPersonDetail** rec);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrAMPersonDetail: C++ wrapper for table TblPlnrAMPersonDetail (PgSQL database)
  */
class PgTblPlnrAMPersonDetail : public TblPlnrAMPersonDetail, public PgTable {

public:
	PgTblPlnrAMPersonDetail();
	~PgTblPlnrAMPersonDetail();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrAMPersonDetail** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrAMPersonDetail& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrAMPersonDetail** rec);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrAMPersonDetail** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrAMPersonDetail& rst);

	void insertRec(PlnrAMPersonDetail* rec);
	void insertRst(ListPlnrAMPersonDetail& rst, bool transact = false);
	void updateRec(PlnrAMPersonDetail* rec);
	void updateRst(ListPlnrAMPersonDetail& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrAMPersonDetail** rec);
};
// IP pgTbl --- END

#endif

