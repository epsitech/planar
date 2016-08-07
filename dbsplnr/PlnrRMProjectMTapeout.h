/**
  * \file PlnrRMProjectMTapeout.h
  * database access for table TblPlnrRMProjectMTapeout (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRRMPROJECTMTAPEOUT_H
#define PLNRRMPROJECTMTAPEOUT_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * PlnrRMProjectMTapeout: record of TblPlnrRMProjectMTapeout
  */
class PlnrRMProjectMTapeout {

public:
	PlnrRMProjectMTapeout(const ubigint ref = 0, const ubigint refPlnrMProject = 0, const ubigint refPlnrMTapeout = 0);

public:
	ubigint ref;
	ubigint refPlnrMProject;
	ubigint refPlnrMTapeout;

public:
	bool operator==(const PlnrRMProjectMTapeout& comp);
	bool operator!=(const PlnrRMProjectMTapeout& comp);
};

/**
  * ListPlnrRMProjectMTapeout: recordset of TblPlnrRMProjectMTapeout
  */
class ListPlnrRMProjectMTapeout {

public:
	ListPlnrRMProjectMTapeout();
	ListPlnrRMProjectMTapeout(const ListPlnrRMProjectMTapeout& src);
	~ListPlnrRMProjectMTapeout();

	void clear();
	unsigned int size() const;
	void append(PlnrRMProjectMTapeout* rec);

	PlnrRMProjectMTapeout* operator[](const uint ix);
	ListPlnrRMProjectMTapeout& operator=(const ListPlnrRMProjectMTapeout& src);
	bool operator==(const ListPlnrRMProjectMTapeout& comp);
	bool operator!=(const ListPlnrRMProjectMTapeout& comp);

public:
	vector<PlnrRMProjectMTapeout*> nodes;
};

/**
  * TblPlnrRMProjectMTapeout: C++ wrapper for table TblPlnrRMProjectMTapeout
  */
class TblPlnrRMProjectMTapeout {

public:
	TblPlnrRMProjectMTapeout();
	virtual ~TblPlnrRMProjectMTapeout();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrRMProjectMTapeout** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrRMProjectMTapeout& rst);

	virtual void insertRec(PlnrRMProjectMTapeout* rec);
	ubigint insertNewRec(PlnrRMProjectMTapeout** rec = NULL, const ubigint refPlnrMProject = 0, const ubigint refPlnrMTapeout = 0);
	ubigint appendNewRecToRst(ListPlnrRMProjectMTapeout& rst, PlnrRMProjectMTapeout** rec = NULL, const ubigint refPlnrMProject = 0, const ubigint refPlnrMTapeout = 0);
	virtual void insertRst(ListPlnrRMProjectMTapeout& rst, bool transact = false);
	virtual void updateRec(PlnrRMProjectMTapeout* rec);
	virtual void updateRst(ListPlnrRMProjectMTapeout& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, PlnrRMProjectMTapeout** rec);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListPlnrRMProjectMTapeout& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrRMProjectMTapeout: C++ wrapper for table TblPlnrRMProjectMTapeout (MySQL database)
  */
class MyTblPlnrRMProjectMTapeout : public TblPlnrRMProjectMTapeout, public MyTable {

public:
	MyTblPlnrRMProjectMTapeout();
	~MyTblPlnrRMProjectMTapeout();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrRMProjectMTapeout** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrRMProjectMTapeout& rst);

	void insertRec(PlnrRMProjectMTapeout* rec);
	void insertRst(ListPlnrRMProjectMTapeout& rst, bool transact = false);
	void updateRec(PlnrRMProjectMTapeout* rec);
	void updateRst(ListPlnrRMProjectMTapeout& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrRMProjectMTapeout** rec);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrRMProjectMTapeout: C++ wrapper for table TblPlnrRMProjectMTapeout (PgSQL database)
  */
class PgTblPlnrRMProjectMTapeout : public TblPlnrRMProjectMTapeout, public PgTable {

public:
	PgTblPlnrRMProjectMTapeout();
	~PgTblPlnrRMProjectMTapeout();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrRMProjectMTapeout** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrRMProjectMTapeout& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrRMProjectMTapeout** rec);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrRMProjectMTapeout** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrRMProjectMTapeout& rst);

	void insertRec(PlnrRMProjectMTapeout* rec);
	void insertRst(ListPlnrRMProjectMTapeout& rst, bool transact = false);
	void updateRec(PlnrRMProjectMTapeout* rec);
	void updateRst(ListPlnrRMProjectMTapeout& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrRMProjectMTapeout** rec);
};
// IP pgTbl --- END

#endif

