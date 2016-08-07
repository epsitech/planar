/**
  * \file PlnrMUser.h
  * database access for table TblPlnrMUser (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRMUSER_H
#define PLNRMUSER_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * PlnrMUser: record of TblPlnrMUser
  */
class PlnrMUser {

public:
	PlnrMUser(const ubigint ref = 0, const ubigint grp = 0, const ubigint own = 0, const ubigint refRUsergroup = 0, const ubigint refPlnrMUsergroup = 0, const ubigint refPlnrMPerson = 0, const string sref = "", const ubigint refJState = 0, const uint ixVState = 0, const uint ixPlnrVLocale = 0, const uint ixPlnrVUserlevel = 0, const string Password = "");

public:
	ubigint ref;
	ubigint grp;
	ubigint own;
	ubigint refRUsergroup;
	ubigint refPlnrMUsergroup;
	ubigint refPlnrMPerson;
	string sref;
	ubigint refJState;
	uint ixVState;
	uint ixPlnrVLocale;
	uint ixPlnrVUserlevel;
	string Password;

public:
	bool operator==(const PlnrMUser& comp);
	bool operator!=(const PlnrMUser& comp);
};

/**
  * ListPlnrMUser: recordset of TblPlnrMUser
  */
class ListPlnrMUser {

public:
	ListPlnrMUser();
	ListPlnrMUser(const ListPlnrMUser& src);
	~ListPlnrMUser();

	void clear();
	unsigned int size() const;
	void append(PlnrMUser* rec);

	PlnrMUser* operator[](const uint ix);
	ListPlnrMUser& operator=(const ListPlnrMUser& src);
	bool operator==(const ListPlnrMUser& comp);
	bool operator!=(const ListPlnrMUser& comp);

public:
	vector<PlnrMUser*> nodes;
};

/**
  * TblPlnrMUser: C++ wrapper for table TblPlnrMUser
  */
class TblPlnrMUser {

public:
	TblPlnrMUser();
	virtual ~TblPlnrMUser();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrMUser** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrMUser& rst);

	virtual void insertRec(PlnrMUser* rec);
	ubigint insertNewRec(PlnrMUser** rec = NULL, const ubigint grp = 0, const ubigint own = 0, const ubigint refRUsergroup = 0, const ubigint refPlnrMUsergroup = 0, const ubigint refPlnrMPerson = 0, const string sref = "", const ubigint refJState = 0, const uint ixVState = 0, const uint ixPlnrVLocale = 0, const uint ixPlnrVUserlevel = 0, const string Password = "");
	ubigint appendNewRecToRst(ListPlnrMUser& rst, PlnrMUser** rec = NULL, const ubigint grp = 0, const ubigint own = 0, const ubigint refRUsergroup = 0, const ubigint refPlnrMUsergroup = 0, const ubigint refPlnrMPerson = 0, const string sref = "", const ubigint refJState = 0, const uint ixVState = 0, const uint ixPlnrVLocale = 0, const uint ixPlnrVUserlevel = 0, const string Password = "");
	virtual void insertRst(ListPlnrMUser& rst, bool transact = false);
	virtual void updateRec(PlnrMUser* rec);
	virtual void updateRst(ListPlnrMUser& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, PlnrMUser** rec);
	virtual bool loadRefBySrfPwd(string sref, string Password, ubigint& ref);
	virtual bool loadSrfByRef(ubigint ref, string& val);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListPlnrMUser& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrMUser: C++ wrapper for table TblPlnrMUser (MySQL database)
  */
class MyTblPlnrMUser : public TblPlnrMUser, public MyTable {

public:
	MyTblPlnrMUser();
	~MyTblPlnrMUser();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrMUser** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrMUser& rst);

	void insertRec(PlnrMUser* rec);
	void insertRst(ListPlnrMUser& rst, bool transact = false);
	void updateRec(PlnrMUser* rec);
	void updateRst(ListPlnrMUser& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrMUser** rec);
	bool loadRefBySrfPwd(string sref, string Password, ubigint& ref);
	bool loadSrfByRef(ubigint ref, string& val);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrMUser: C++ wrapper for table TblPlnrMUser (PgSQL database)
  */
class PgTblPlnrMUser : public TblPlnrMUser, public PgTable {

public:
	PgTblPlnrMUser();
	~PgTblPlnrMUser();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrMUser** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrMUser& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrMUser** rec);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrMUser** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrMUser& rst);

	void insertRec(PlnrMUser* rec);
	void insertRst(ListPlnrMUser& rst, bool transact = false);
	void updateRec(PlnrMUser* rec);
	void updateRst(ListPlnrMUser& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrMUser** rec);
	bool loadRefBySrfPwd(string sref, string Password, ubigint& ref);
	bool loadSrfByRef(ubigint ref, string& val);
};
// IP pgTbl --- END

#endif

