/**
  * \file PlnrMCalcitem.h
  * database access for table TblPlnrMCalcitem (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRMCALCITEM_H
#define PLNRMCALCITEM_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * PlnrMCalcitem: record of TblPlnrMCalcitem
  */
class PlnrMCalcitem {

public:
	PlnrMCalcitem(const ubigint ref = 0, const ubigint calRefPlnrMCalc = 0, const uint calNum = 0, const ubigint refPlnrMDesign = 0, const string Title = "");

public:
	ubigint ref;
	ubigint calRefPlnrMCalc;
	uint calNum;
	ubigint refPlnrMDesign;
	string Title;

public:
	bool operator==(const PlnrMCalcitem& comp);
	bool operator!=(const PlnrMCalcitem& comp);
};

/**
  * ListPlnrMCalcitem: recordset of TblPlnrMCalcitem
  */
class ListPlnrMCalcitem {

public:
	ListPlnrMCalcitem();
	ListPlnrMCalcitem(const ListPlnrMCalcitem& src);
	~ListPlnrMCalcitem();

	void clear();
	unsigned int size() const;
	void append(PlnrMCalcitem* rec);

	PlnrMCalcitem* operator[](const uint ix);
	ListPlnrMCalcitem& operator=(const ListPlnrMCalcitem& src);
	bool operator==(const ListPlnrMCalcitem& comp);
	bool operator!=(const ListPlnrMCalcitem& comp);

public:
	vector<PlnrMCalcitem*> nodes;
};

/**
  * TblPlnrMCalcitem: C++ wrapper for table TblPlnrMCalcitem
  */
class TblPlnrMCalcitem {

public:
	TblPlnrMCalcitem();
	virtual ~TblPlnrMCalcitem();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrMCalcitem** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrMCalcitem& rst);

	virtual void insertRec(PlnrMCalcitem* rec);
	ubigint insertNewRec(PlnrMCalcitem** rec = NULL, const ubigint calRefPlnrMCalc = 0, const uint calNum = 0, const ubigint refPlnrMDesign = 0, const string Title = "");
	ubigint appendNewRecToRst(ListPlnrMCalcitem& rst, PlnrMCalcitem** rec = NULL, const ubigint calRefPlnrMCalc = 0, const uint calNum = 0, const ubigint refPlnrMDesign = 0, const string Title = "");
	virtual void insertRst(ListPlnrMCalcitem& rst, bool transact = false);
	virtual void updateRec(PlnrMCalcitem* rec);
	virtual void updateRst(ListPlnrMCalcitem& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, PlnrMCalcitem** rec);
	virtual ubigint loadRstByCal(ubigint calRefPlnrMCalc, const bool append, ListPlnrMCalcitem& rst);
	virtual bool loadTitByRef(ubigint ref, string& val);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListPlnrMCalcitem& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrMCalcitem: C++ wrapper for table TblPlnrMCalcitem (MySQL database)
  */
class MyTblPlnrMCalcitem : public TblPlnrMCalcitem, public MyTable {

public:
	MyTblPlnrMCalcitem();
	~MyTblPlnrMCalcitem();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrMCalcitem** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrMCalcitem& rst);

	void insertRec(PlnrMCalcitem* rec);
	void insertRst(ListPlnrMCalcitem& rst, bool transact = false);
	void updateRec(PlnrMCalcitem* rec);
	void updateRst(ListPlnrMCalcitem& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrMCalcitem** rec);
	ubigint loadRstByCal(ubigint calRefPlnrMCalc, const bool append, ListPlnrMCalcitem& rst);
	bool loadTitByRef(ubigint ref, string& val);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrMCalcitem: C++ wrapper for table TblPlnrMCalcitem (PgSQL database)
  */
class PgTblPlnrMCalcitem : public TblPlnrMCalcitem, public PgTable {

public:
	PgTblPlnrMCalcitem();
	~PgTblPlnrMCalcitem();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrMCalcitem** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrMCalcitem& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrMCalcitem** rec);
// IP pgLoadRstByStmt --- BEGIN
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrMCalcitem& rst);
// IP pgLoadRstByStmt --- END

public:
	bool loadRecBySQL(const string& sqlstr, PlnrMCalcitem** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrMCalcitem& rst);

	void insertRec(PlnrMCalcitem* rec);
	void insertRst(ListPlnrMCalcitem& rst, bool transact = false);
	void updateRec(PlnrMCalcitem* rec);
	void updateRst(ListPlnrMCalcitem& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrMCalcitem** rec);
	ubigint loadRstByCal(ubigint calRefPlnrMCalc, const bool append, ListPlnrMCalcitem& rst);
	bool loadTitByRef(ubigint ref, string& val);
};
// IP pgTbl --- END

#endif

