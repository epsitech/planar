/**
  * \file PlnrAVValuelistVal.h
  * database access for table TblPlnrAVValuelistVal (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRAVVALUELISTVAL_H
#define PLNRAVVALUELISTVAL_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * PlnrAVValuelistVal: record of TblPlnrAVValuelistVal
  */
class PlnrAVValuelistVal {

public:
	PlnrAVValuelistVal(const ubigint ref = 0, const uint vlsIxPlnrVValuelist = 0, const uint vlsNum = 0, const uint x1IxPlnrVLocale = 0, const string Val = "");

public:
	ubigint ref;
	uint vlsIxPlnrVValuelist;
	uint vlsNum;
	uint x1IxPlnrVLocale;
	string Val;

public:
	bool operator==(const PlnrAVValuelistVal& comp);
	bool operator!=(const PlnrAVValuelistVal& comp);
};

/**
  * ListPlnrAVValuelistVal: recordset of TblPlnrAVValuelistVal
  */
class ListPlnrAVValuelistVal {

public:
	ListPlnrAVValuelistVal();
	ListPlnrAVValuelistVal(const ListPlnrAVValuelistVal& src);
	~ListPlnrAVValuelistVal();

	void clear();
	unsigned int size() const;
	void append(PlnrAVValuelistVal* rec);

	PlnrAVValuelistVal* operator[](const uint ix);
	ListPlnrAVValuelistVal& operator=(const ListPlnrAVValuelistVal& src);
	bool operator==(const ListPlnrAVValuelistVal& comp);
	bool operator!=(const ListPlnrAVValuelistVal& comp);

public:
	vector<PlnrAVValuelistVal*> nodes;
};

/**
  * TblPlnrAVValuelistVal: C++ wrapper for table TblPlnrAVValuelistVal
  */
class TblPlnrAVValuelistVal {

public:
	TblPlnrAVValuelistVal();
	virtual ~TblPlnrAVValuelistVal();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrAVValuelistVal** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrAVValuelistVal& rst);

	virtual void insertRec(PlnrAVValuelistVal* rec);
	ubigint insertNewRec(PlnrAVValuelistVal** rec = NULL, const uint vlsIxPlnrVValuelist = 0, const uint vlsNum = 0, const uint x1IxPlnrVLocale = 0, const string Val = "");
	ubigint appendNewRecToRst(ListPlnrAVValuelistVal& rst, PlnrAVValuelistVal** rec = NULL, const uint vlsIxPlnrVValuelist = 0, const uint vlsNum = 0, const uint x1IxPlnrVLocale = 0, const string Val = "");
	virtual void insertRst(ListPlnrAVValuelistVal& rst, bool transact = false);
	virtual void updateRec(PlnrAVValuelistVal* rec);
	virtual void updateRst(ListPlnrAVValuelistVal& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, PlnrAVValuelistVal** rec);
	virtual ubigint loadRstByVlsLcl(uint vlsIxPlnrVValuelist, uint x1IxPlnrVLocale, const bool append, ListPlnrAVValuelistVal& rst);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListPlnrAVValuelistVal& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrAVValuelistVal: C++ wrapper for table TblPlnrAVValuelistVal (MySQL database)
  */
class MyTblPlnrAVValuelistVal : public TblPlnrAVValuelistVal, public MyTable {

public:
	MyTblPlnrAVValuelistVal();
	~MyTblPlnrAVValuelistVal();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrAVValuelistVal** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrAVValuelistVal& rst);

	void insertRec(PlnrAVValuelistVal* rec);
	void insertRst(ListPlnrAVValuelistVal& rst, bool transact = false);
	void updateRec(PlnrAVValuelistVal* rec);
	void updateRst(ListPlnrAVValuelistVal& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrAVValuelistVal** rec);
	ubigint loadRstByVlsLcl(uint vlsIxPlnrVValuelist, uint x1IxPlnrVLocale, const bool append, ListPlnrAVValuelistVal& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrAVValuelistVal: C++ wrapper for table TblPlnrAVValuelistVal (PgSQL database)
  */
class PgTblPlnrAVValuelistVal : public TblPlnrAVValuelistVal, public PgTable {

public:
	PgTblPlnrAVValuelistVal();
	~PgTblPlnrAVValuelistVal();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrAVValuelistVal** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrAVValuelistVal& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrAVValuelistVal** rec);
// IP pgLoadRstByStmt --- BEGIN
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrAVValuelistVal& rst);
// IP pgLoadRstByStmt --- END

public:
	bool loadRecBySQL(const string& sqlstr, PlnrAVValuelistVal** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrAVValuelistVal& rst);

	void insertRec(PlnrAVValuelistVal* rec);
	void insertRst(ListPlnrAVValuelistVal& rst, bool transact = false);
	void updateRec(PlnrAVValuelistVal* rec);
	void updateRst(ListPlnrAVValuelistVal& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrAVValuelistVal** rec);
	ubigint loadRstByVlsLcl(uint vlsIxPlnrVValuelist, uint x1IxPlnrVLocale, const bool append, ListPlnrAVValuelistVal& rst);
};
// IP pgTbl --- END

#endif

