/**
  * \file PlnrMPerson.h
  * database access for table TblPlnrMPerson (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRMPERSON_H
#define PLNRMPERSON_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * PlnrMPerson: record of TblPlnrMPerson
  */
class PlnrMPerson {

public:
	PlnrMPerson(const ubigint ref = 0, const ubigint grp = 0, const ubigint own = 0, const uint ixWDerivate = 0, const uint ixVSex = 0, const string Title = "", const string Firstname = "", const ubigint refJLastname = 0, const string Lastname = "", const ubigint telRefADetail = 0, const string Tel = "", const ubigint emlRefADetail = 0, const string Eml = "", const string Salutation = "");

public:
	ubigint ref;
	ubigint grp;
	ubigint own;
	uint ixWDerivate;
	uint ixVSex;
	string Title;
	string Firstname;
	ubigint refJLastname;
	string Lastname;
	ubigint telRefADetail;
	string Tel;
	ubigint emlRefADetail;
	string Eml;
	string Salutation;

public:
	bool operator==(const PlnrMPerson& comp);
	bool operator!=(const PlnrMPerson& comp);
};

/**
  * ListPlnrMPerson: recordset of TblPlnrMPerson
  */
class ListPlnrMPerson {

public:
	ListPlnrMPerson();
	ListPlnrMPerson(const ListPlnrMPerson& src);
	~ListPlnrMPerson();

	void clear();
	unsigned int size() const;
	void append(PlnrMPerson* rec);

	PlnrMPerson* operator[](const uint ix);
	ListPlnrMPerson& operator=(const ListPlnrMPerson& src);
	bool operator==(const ListPlnrMPerson& comp);
	bool operator!=(const ListPlnrMPerson& comp);

public:
	vector<PlnrMPerson*> nodes;
};

/**
  * TblPlnrMPerson: C++ wrapper for table TblPlnrMPerson
  */
class TblPlnrMPerson {

public:
	TblPlnrMPerson();
	virtual ~TblPlnrMPerson();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrMPerson** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrMPerson& rst);

	virtual void insertRec(PlnrMPerson* rec);
	ubigint insertNewRec(PlnrMPerson** rec = NULL, const ubigint grp = 0, const ubigint own = 0, const uint ixWDerivate = 0, const uint ixVSex = 0, const string Title = "", const string Firstname = "", const ubigint refJLastname = 0, const string Lastname = "", const ubigint telRefADetail = 0, const string Tel = "", const ubigint emlRefADetail = 0, const string Eml = "", const string Salutation = "");
	ubigint appendNewRecToRst(ListPlnrMPerson& rst, PlnrMPerson** rec = NULL, const ubigint grp = 0, const ubigint own = 0, const uint ixWDerivate = 0, const uint ixVSex = 0, const string Title = "", const string Firstname = "", const ubigint refJLastname = 0, const string Lastname = "", const ubigint telRefADetail = 0, const string Tel = "", const ubigint emlRefADetail = 0, const string Eml = "", const string Salutation = "");
	virtual void insertRst(ListPlnrMPerson& rst, bool transact = false);
	virtual void updateRec(PlnrMPerson* rec);
	virtual void updateRst(ListPlnrMPerson& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, PlnrMPerson** rec);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListPlnrMPerson& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrMPerson: C++ wrapper for table TblPlnrMPerson (MySQL database)
  */
class MyTblPlnrMPerson : public TblPlnrMPerson, public MyTable {

public:
	MyTblPlnrMPerson();
	~MyTblPlnrMPerson();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrMPerson** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrMPerson& rst);

	void insertRec(PlnrMPerson* rec);
	void insertRst(ListPlnrMPerson& rst, bool transact = false);
	void updateRec(PlnrMPerson* rec);
	void updateRst(ListPlnrMPerson& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrMPerson** rec);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrMPerson: C++ wrapper for table TblPlnrMPerson (PgSQL database)
  */
class PgTblPlnrMPerson : public TblPlnrMPerson, public PgTable {

public:
	PgTblPlnrMPerson();
	~PgTblPlnrMPerson();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrMPerson** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrMPerson& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrMPerson** rec);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrMPerson** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrMPerson& rst);

	void insertRec(PlnrMPerson* rec);
	void insertRst(ListPlnrMPerson& rst, bool transact = false);
	void updateRec(PlnrMPerson* rec);
	void updateRst(ListPlnrMPerson& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrMPerson** rec);
};
// IP pgTbl --- END

#endif

