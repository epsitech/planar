/**
  * \file PlnrMTapeout.h
  * database access for table TblPlnrMTapeout (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRMTAPEOUT_H
#define PLNRMTAPEOUT_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * PlnrMTapeout: record of TblPlnrMTapeout
  */
class PlnrMTapeout {

public:
	PlnrMTapeout(const ubigint ref = 0, const ubigint grp = 0, const ubigint own = 0, const uint ixVBasetype = 0, const string Title = "", const usmallint Major = 0, const usmallint Sub = 0, const ubigint refJState = 0, const uint ixVState = 0, const bool Hflip = false, const string Comment = "");

public:
	ubigint ref;
	ubigint grp;
	ubigint own;
	uint ixVBasetype;
	string Title;
	usmallint Major;
	usmallint Sub;
	ubigint refJState;
	uint ixVState;
	bool Hflip;
	string Comment;

public:
	bool operator==(const PlnrMTapeout& comp);
	bool operator!=(const PlnrMTapeout& comp);
};

/**
  * ListPlnrMTapeout: recordset of TblPlnrMTapeout
  */
class ListPlnrMTapeout {

public:
	ListPlnrMTapeout();
	ListPlnrMTapeout(const ListPlnrMTapeout& src);
	~ListPlnrMTapeout();

	void clear();
	unsigned int size() const;
	void append(PlnrMTapeout* rec);

	PlnrMTapeout* operator[](const uint ix);
	ListPlnrMTapeout& operator=(const ListPlnrMTapeout& src);
	bool operator==(const ListPlnrMTapeout& comp);
	bool operator!=(const ListPlnrMTapeout& comp);

public:
	vector<PlnrMTapeout*> nodes;
};

/**
  * TblPlnrMTapeout: C++ wrapper for table TblPlnrMTapeout
  */
class TblPlnrMTapeout {

public:
	TblPlnrMTapeout();
	virtual ~TblPlnrMTapeout();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrMTapeout** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrMTapeout& rst);

	virtual void insertRec(PlnrMTapeout* rec);
	ubigint insertNewRec(PlnrMTapeout** rec = NULL, const ubigint grp = 0, const ubigint own = 0, const uint ixVBasetype = 0, const string Title = "", const usmallint Major = 0, const usmallint Sub = 0, const ubigint refJState = 0, const uint ixVState = 0, const bool Hflip = false, const string Comment = "");
	ubigint appendNewRecToRst(ListPlnrMTapeout& rst, PlnrMTapeout** rec = NULL, const ubigint grp = 0, const ubigint own = 0, const uint ixVBasetype = 0, const string Title = "", const usmallint Major = 0, const usmallint Sub = 0, const ubigint refJState = 0, const uint ixVState = 0, const bool Hflip = false, const string Comment = "");
	virtual void insertRst(ListPlnrMTapeout& rst, bool transact = false);
	virtual void updateRec(PlnrMTapeout* rec);
	virtual void updateRst(ListPlnrMTapeout& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, PlnrMTapeout** rec);
	virtual bool loadTitByRef(ubigint ref, string& val);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListPlnrMTapeout& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrMTapeout: C++ wrapper for table TblPlnrMTapeout (MySQL database)
  */
class MyTblPlnrMTapeout : public TblPlnrMTapeout, public MyTable {

public:
	MyTblPlnrMTapeout();
	~MyTblPlnrMTapeout();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrMTapeout** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrMTapeout& rst);

	void insertRec(PlnrMTapeout* rec);
	void insertRst(ListPlnrMTapeout& rst, bool transact = false);
	void updateRec(PlnrMTapeout* rec);
	void updateRst(ListPlnrMTapeout& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrMTapeout** rec);
	bool loadTitByRef(ubigint ref, string& val);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrMTapeout: C++ wrapper for table TblPlnrMTapeout (PgSQL database)
  */
class PgTblPlnrMTapeout : public TblPlnrMTapeout, public PgTable {

public:
	PgTblPlnrMTapeout();
	~PgTblPlnrMTapeout();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrMTapeout** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrMTapeout& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrMTapeout** rec);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrMTapeout** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrMTapeout& rst);

	void insertRec(PlnrMTapeout* rec);
	void insertRst(ListPlnrMTapeout& rst, bool transact = false);
	void updateRec(PlnrMTapeout* rec);
	void updateRst(ListPlnrMTapeout& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrMTapeout** rec);
	bool loadTitByRef(ubigint ref, string& val);
};
// IP pgTbl --- END

#endif

