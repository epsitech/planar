/**
  * \file PlnrMProject.h
  * database access for table TblPlnrMProject (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRMPROJECT_H
#define PLNRMPROJECT_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * PlnrMProject: record of TblPlnrMProject
  */
class PlnrMProject {

public:
	PlnrMProject(const ubigint ref = 0, const ubigint grp = 0, const ubigint own = 0, const string Title = "", const ubigint refJState = 0, const uint ixVState = 0, const string Comment = "");

public:
	ubigint ref;
	ubigint grp;
	ubigint own;
	string Title;
	ubigint refJState;
	uint ixVState;
	string Comment;

public:
	bool operator==(const PlnrMProject& comp);
	bool operator!=(const PlnrMProject& comp);
};

/**
  * ListPlnrMProject: recordset of TblPlnrMProject
  */
class ListPlnrMProject {

public:
	ListPlnrMProject();
	ListPlnrMProject(const ListPlnrMProject& src);
	~ListPlnrMProject();

	void clear();
	unsigned int size() const;
	void append(PlnrMProject* rec);

	PlnrMProject* operator[](const uint ix);
	ListPlnrMProject& operator=(const ListPlnrMProject& src);
	bool operator==(const ListPlnrMProject& comp);
	bool operator!=(const ListPlnrMProject& comp);

public:
	vector<PlnrMProject*> nodes;
};

/**
  * TblPlnrMProject: C++ wrapper for table TblPlnrMProject
  */
class TblPlnrMProject {

public:
	TblPlnrMProject();
	virtual ~TblPlnrMProject();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrMProject** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrMProject& rst);

	virtual void insertRec(PlnrMProject* rec);
	ubigint insertNewRec(PlnrMProject** rec = NULL, const ubigint grp = 0, const ubigint own = 0, const string Title = "", const ubigint refJState = 0, const uint ixVState = 0, const string Comment = "");
	ubigint appendNewRecToRst(ListPlnrMProject& rst, PlnrMProject** rec = NULL, const ubigint grp = 0, const ubigint own = 0, const string Title = "", const ubigint refJState = 0, const uint ixVState = 0, const string Comment = "");
	virtual void insertRst(ListPlnrMProject& rst, bool transact = false);
	virtual void updateRec(PlnrMProject* rec);
	virtual void updateRst(ListPlnrMProject& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, PlnrMProject** rec);
	virtual bool loadRefByTit(string Title, ubigint& val);
	virtual bool loadTitByRef(ubigint ref, string& val);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListPlnrMProject& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrMProject: C++ wrapper for table TblPlnrMProject (MySQL database)
  */
class MyTblPlnrMProject : public TblPlnrMProject, public MyTable {

public:
	MyTblPlnrMProject();
	~MyTblPlnrMProject();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrMProject** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrMProject& rst);

	void insertRec(PlnrMProject* rec);
	void insertRst(ListPlnrMProject& rst, bool transact = false);
	void updateRec(PlnrMProject* rec);
	void updateRst(ListPlnrMProject& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrMProject** rec);
	bool loadRefByTit(string Title, ubigint& val);
	bool loadTitByRef(ubigint ref, string& val);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrMProject: C++ wrapper for table TblPlnrMProject (PgSQL database)
  */
class PgTblPlnrMProject : public TblPlnrMProject, public PgTable {

public:
	PgTblPlnrMProject();
	~PgTblPlnrMProject();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrMProject** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrMProject& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrMProject** rec);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrMProject** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrMProject& rst);

	void insertRec(PlnrMProject* rec);
	void insertRst(ListPlnrMProject& rst, bool transact = false);
	void updateRec(PlnrMProject* rec);
	void updateRst(ListPlnrMProject& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrMProject** rec);
	bool loadRefByTit(string Title, ubigint& val);
	bool loadTitByRef(ubigint ref, string& val);
};
// IP pgTbl --- END

#endif

