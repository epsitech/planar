/**
  * \file PlnrRMLineguideMLineguide.h
  * database access for table TblPlnrRMLineguideMLineguide (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRRMLINEGUIDEMLINEGUIDE_H
#define PLNRRMLINEGUIDEMLINEGUIDE_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * PlnrRMLineguideMLineguide: record of TblPlnrRMLineguideMLineguide
  */
class PlnrRMLineguideMLineguide {

public:
	PlnrRMLineguideMLineguide(const ubigint ref = 0, const ubigint devRefPlnrMLineguide = 0, const ubigint dsnRefPlnrMLineguide = 0);

public:
	ubigint ref;
	ubigint devRefPlnrMLineguide;
	ubigint dsnRefPlnrMLineguide;

public:
	bool operator==(const PlnrRMLineguideMLineguide& comp);
	bool operator!=(const PlnrRMLineguideMLineguide& comp);
};

/**
  * ListPlnrRMLineguideMLineguide: recordset of TblPlnrRMLineguideMLineguide
  */
class ListPlnrRMLineguideMLineguide {

public:
	ListPlnrRMLineguideMLineguide();
	ListPlnrRMLineguideMLineguide(const ListPlnrRMLineguideMLineguide& src);
	~ListPlnrRMLineguideMLineguide();

	void clear();
	unsigned int size() const;
	void append(PlnrRMLineguideMLineguide* rec);

	PlnrRMLineguideMLineguide* operator[](const uint ix);
	ListPlnrRMLineguideMLineguide& operator=(const ListPlnrRMLineguideMLineguide& src);
	bool operator==(const ListPlnrRMLineguideMLineguide& comp);
	bool operator!=(const ListPlnrRMLineguideMLineguide& comp);

public:
	vector<PlnrRMLineguideMLineguide*> nodes;
};

/**
  * TblPlnrRMLineguideMLineguide: C++ wrapper for table TblPlnrRMLineguideMLineguide
  */
class TblPlnrRMLineguideMLineguide {

public:
	TblPlnrRMLineguideMLineguide();
	virtual ~TblPlnrRMLineguideMLineguide();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrRMLineguideMLineguide** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrRMLineguideMLineguide& rst);

	virtual void insertRec(PlnrRMLineguideMLineguide* rec);
	ubigint insertNewRec(PlnrRMLineguideMLineguide** rec = NULL, const ubigint devRefPlnrMLineguide = 0, const ubigint dsnRefPlnrMLineguide = 0);
	ubigint appendNewRecToRst(ListPlnrRMLineguideMLineguide& rst, PlnrRMLineguideMLineguide** rec = NULL, const ubigint devRefPlnrMLineguide = 0, const ubigint dsnRefPlnrMLineguide = 0);
	virtual void insertRst(ListPlnrRMLineguideMLineguide& rst, bool transact = false);
	virtual void updateRec(PlnrRMLineguideMLineguide* rec);
	virtual void updateRst(ListPlnrRMLineguideMLineguide& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, PlnrRMLineguideMLineguide** rec);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListPlnrRMLineguideMLineguide& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrRMLineguideMLineguide: C++ wrapper for table TblPlnrRMLineguideMLineguide (MySQL database)
  */
class MyTblPlnrRMLineguideMLineguide : public TblPlnrRMLineguideMLineguide, public MyTable {

public:
	MyTblPlnrRMLineguideMLineguide();
	~MyTblPlnrRMLineguideMLineguide();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrRMLineguideMLineguide** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrRMLineguideMLineguide& rst);

	void insertRec(PlnrRMLineguideMLineguide* rec);
	void insertRst(ListPlnrRMLineguideMLineguide& rst, bool transact = false);
	void updateRec(PlnrRMLineguideMLineguide* rec);
	void updateRst(ListPlnrRMLineguideMLineguide& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrRMLineguideMLineguide** rec);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrRMLineguideMLineguide: C++ wrapper for table TblPlnrRMLineguideMLineguide (PgSQL database)
  */
class PgTblPlnrRMLineguideMLineguide : public TblPlnrRMLineguideMLineguide, public PgTable {

public:
	PgTblPlnrRMLineguideMLineguide();
	~PgTblPlnrRMLineguideMLineguide();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrRMLineguideMLineguide** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrRMLineguideMLineguide& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrRMLineguideMLineguide** rec);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrRMLineguideMLineguide** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrRMLineguideMLineguide& rst);

	void insertRec(PlnrRMLineguideMLineguide* rec);
	void insertRst(ListPlnrRMLineguideMLineguide& rst, bool transact = false);
	void updateRec(PlnrRMLineguideMLineguide* rec);
	void updateRst(ListPlnrRMLineguideMLineguide& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrRMLineguideMLineguide** rec);
};
// IP pgTbl --- END

#endif

