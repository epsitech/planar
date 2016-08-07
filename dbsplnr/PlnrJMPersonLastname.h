/**
  * \file PlnrJMPersonLastname.h
  * database access for table TblPlnrJMPersonLastname (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRJMPERSONLASTNAME_H
#define PLNRJMPERSONLASTNAME_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * PlnrJMPersonLastname: record of TblPlnrJMPersonLastname
  */
class PlnrJMPersonLastname {

public:
	PlnrJMPersonLastname(const ubigint ref = 0, const ubigint refPlnrMPerson = 0, const uint x1Startd = 0, const string Lastname = "");

public:
	ubigint ref;
	ubigint refPlnrMPerson;
	uint x1Startd;
	string Lastname;

public:
	bool operator==(const PlnrJMPersonLastname& comp);
	bool operator!=(const PlnrJMPersonLastname& comp);
};

/**
  * ListPlnrJMPersonLastname: recordset of TblPlnrJMPersonLastname
  */
class ListPlnrJMPersonLastname {

public:
	ListPlnrJMPersonLastname();
	ListPlnrJMPersonLastname(const ListPlnrJMPersonLastname& src);
	~ListPlnrJMPersonLastname();

	void clear();
	unsigned int size() const;
	void append(PlnrJMPersonLastname* rec);

	PlnrJMPersonLastname* operator[](const uint ix);
	ListPlnrJMPersonLastname& operator=(const ListPlnrJMPersonLastname& src);
	bool operator==(const ListPlnrJMPersonLastname& comp);
	bool operator!=(const ListPlnrJMPersonLastname& comp);

public:
	vector<PlnrJMPersonLastname*> nodes;
};

/**
  * TblPlnrJMPersonLastname: C++ wrapper for table TblPlnrJMPersonLastname
  */
class TblPlnrJMPersonLastname {

public:
	TblPlnrJMPersonLastname();
	virtual ~TblPlnrJMPersonLastname();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrJMPersonLastname** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrJMPersonLastname& rst);

	virtual void insertRec(PlnrJMPersonLastname* rec);
	ubigint insertNewRec(PlnrJMPersonLastname** rec = NULL, const ubigint refPlnrMPerson = 0, const uint x1Startd = 0, const string Lastname = "");
	ubigint appendNewRecToRst(ListPlnrJMPersonLastname& rst, PlnrJMPersonLastname** rec = NULL, const ubigint refPlnrMPerson = 0, const uint x1Startd = 0, const string Lastname = "");
	virtual void insertRst(ListPlnrJMPersonLastname& rst, bool transact = false);
	virtual void updateRec(PlnrJMPersonLastname* rec);
	virtual void updateRst(ListPlnrJMPersonLastname& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, PlnrJMPersonLastname** rec);
	virtual bool loadRecByPrsSta(ubigint refPlnrMPerson, uint x1Startd, PlnrJMPersonLastname** rec);
	virtual ubigint loadRefsByPrs(ubigint refPlnrMPerson, const bool append, vector<ubigint>& refs);
	virtual ubigint loadRstByPrs(ubigint refPlnrMPerson, const bool append, ListPlnrJMPersonLastname& rst);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListPlnrJMPersonLastname& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrJMPersonLastname: C++ wrapper for table TblPlnrJMPersonLastname (MySQL database)
  */
class MyTblPlnrJMPersonLastname : public TblPlnrJMPersonLastname, public MyTable {

public:
	MyTblPlnrJMPersonLastname();
	~MyTblPlnrJMPersonLastname();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrJMPersonLastname** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrJMPersonLastname& rst);

	void insertRec(PlnrJMPersonLastname* rec);
	void insertRst(ListPlnrJMPersonLastname& rst, bool transact = false);
	void updateRec(PlnrJMPersonLastname* rec);
	void updateRst(ListPlnrJMPersonLastname& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrJMPersonLastname** rec);
	bool loadRecByPrsSta(ubigint refPlnrMPerson, uint x1Startd, PlnrJMPersonLastname** rec);
	ubigint loadRefsByPrs(ubigint refPlnrMPerson, const bool append, vector<ubigint>& refs);
	ubigint loadRstByPrs(ubigint refPlnrMPerson, const bool append, ListPlnrJMPersonLastname& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrJMPersonLastname: C++ wrapper for table TblPlnrJMPersonLastname (PgSQL database)
  */
class PgTblPlnrJMPersonLastname : public TblPlnrJMPersonLastname, public PgTable {

public:
	PgTblPlnrJMPersonLastname();
	~PgTblPlnrJMPersonLastname();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrJMPersonLastname** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrJMPersonLastname& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrJMPersonLastname** rec);
// IP pgLoadRstByStmt --- BEGIN
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrJMPersonLastname& rst);
// IP pgLoadRstByStmt --- END

public:
	bool loadRecBySQL(const string& sqlstr, PlnrJMPersonLastname** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrJMPersonLastname& rst);

	void insertRec(PlnrJMPersonLastname* rec);
	void insertRst(ListPlnrJMPersonLastname& rst, bool transact = false);
	void updateRec(PlnrJMPersonLastname* rec);
	void updateRst(ListPlnrJMPersonLastname& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrJMPersonLastname** rec);
	bool loadRecByPrsSta(ubigint refPlnrMPerson, uint x1Startd, PlnrJMPersonLastname** rec);
	ubigint loadRefsByPrs(ubigint refPlnrMPerson, const bool append, vector<ubigint>& refs);
	ubigint loadRstByPrs(ubigint refPlnrMPerson, const bool append, ListPlnrJMPersonLastname& rst);
};
// IP pgTbl --- END

#endif

