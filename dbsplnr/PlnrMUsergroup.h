/**
  * \file PlnrMUsergroup.h
  * database access for table TblPlnrMUsergroup (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRMUSERGROUP_H
#define PLNRMUSERGROUP_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * PlnrMUsergroup: record of TblPlnrMUsergroup
  */
class PlnrMUsergroup {

public:
	PlnrMUsergroup(const ubigint ref = 0, const ubigint grp = 0, const ubigint own = 0, const string sref = "", const string Comment = "");

public:
	ubigint ref;
	ubigint grp;
	ubigint own;
	string sref;
	string Comment;

public:
	bool operator==(const PlnrMUsergroup& comp);
	bool operator!=(const PlnrMUsergroup& comp);
};

/**
  * ListPlnrMUsergroup: recordset of TblPlnrMUsergroup
  */
class ListPlnrMUsergroup {

public:
	ListPlnrMUsergroup();
	ListPlnrMUsergroup(const ListPlnrMUsergroup& src);
	~ListPlnrMUsergroup();

	void clear();
	unsigned int size() const;
	void append(PlnrMUsergroup* rec);

	PlnrMUsergroup* operator[](const uint ix);
	ListPlnrMUsergroup& operator=(const ListPlnrMUsergroup& src);
	bool operator==(const ListPlnrMUsergroup& comp);
	bool operator!=(const ListPlnrMUsergroup& comp);

public:
	vector<PlnrMUsergroup*> nodes;
};

/**
  * TblPlnrMUsergroup: C++ wrapper for table TblPlnrMUsergroup
  */
class TblPlnrMUsergroup {

public:
	TblPlnrMUsergroup();
	virtual ~TblPlnrMUsergroup();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrMUsergroup** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrMUsergroup& rst);

	virtual void insertRec(PlnrMUsergroup* rec);
	ubigint insertNewRec(PlnrMUsergroup** rec = NULL, const ubigint grp = 0, const ubigint own = 0, const string sref = "", const string Comment = "");
	ubigint appendNewRecToRst(ListPlnrMUsergroup& rst, PlnrMUsergroup** rec = NULL, const ubigint grp = 0, const ubigint own = 0, const string sref = "", const string Comment = "");
	virtual void insertRst(ListPlnrMUsergroup& rst, bool transact = false);
	virtual void updateRec(PlnrMUsergroup* rec);
	virtual void updateRst(ListPlnrMUsergroup& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, PlnrMUsergroup** rec);
	virtual bool loadSrfByRef(ubigint ref, string& val);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListPlnrMUsergroup& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrMUsergroup: C++ wrapper for table TblPlnrMUsergroup (MySQL database)
  */
class MyTblPlnrMUsergroup : public TblPlnrMUsergroup, public MyTable {

public:
	MyTblPlnrMUsergroup();
	~MyTblPlnrMUsergroup();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrMUsergroup** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrMUsergroup& rst);

	void insertRec(PlnrMUsergroup* rec);
	void insertRst(ListPlnrMUsergroup& rst, bool transact = false);
	void updateRec(PlnrMUsergroup* rec);
	void updateRst(ListPlnrMUsergroup& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrMUsergroup** rec);
	bool loadSrfByRef(ubigint ref, string& val);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrMUsergroup: C++ wrapper for table TblPlnrMUsergroup (PgSQL database)
  */
class PgTblPlnrMUsergroup : public TblPlnrMUsergroup, public PgTable {

public:
	PgTblPlnrMUsergroup();
	~PgTblPlnrMUsergroup();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrMUsergroup** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrMUsergroup& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrMUsergroup** rec);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrMUsergroup** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrMUsergroup& rst);

	void insertRec(PlnrMUsergroup* rec);
	void insertRst(ListPlnrMUsergroup& rst, bool transact = false);
	void updateRec(PlnrMUsergroup* rec);
	void updateRst(ListPlnrMUsergroup& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrMUsergroup** rec);
	bool loadSrfByRef(ubigint ref, string& val);
};
// IP pgTbl --- END

#endif

