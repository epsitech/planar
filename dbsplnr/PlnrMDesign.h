/**
  * \file PlnrMDesign.h
  * database access for table TblPlnrMDesign (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRMDESIGN_H
#define PLNRMDESIGN_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * PlnrMDesign: record of TblPlnrMDesign
  */
class PlnrMDesign {

public:
	PlnrMDesign(const ubigint ref = 0, const ubigint grp = 0, const ubigint own = 0, const uint ixVBasetype = 0, const uint ixVDim = 0, const uint refIxVTbl = 0, const ubigint refUref = 0, const ubigint refPlnrMProject = 0, const uint ixWModtype = 0, const ubigint modRefPlnrMDesign = 0, const ubigint drvRefPlnrMDesign = 0, const string Title = "", const usmallint Major = 0, const usmallint Sub = 0, const string Comment = "");

public:
	ubigint ref;
	ubigint grp;
	ubigint own;
	uint ixVBasetype;
	uint ixVDim;
	uint refIxVTbl;
	ubigint refUref;
	ubigint refPlnrMProject;
	uint ixWModtype;
	ubigint modRefPlnrMDesign;
	ubigint drvRefPlnrMDesign;
	string Title;
	usmallint Major;
	usmallint Sub;
	string Comment;

public:
	bool operator==(const PlnrMDesign& comp);
	bool operator!=(const PlnrMDesign& comp);
};

/**
  * ListPlnrMDesign: recordset of TblPlnrMDesign
  */
class ListPlnrMDesign {

public:
	ListPlnrMDesign();
	ListPlnrMDesign(const ListPlnrMDesign& src);
	~ListPlnrMDesign();

	void clear();
	unsigned int size() const;
	void append(PlnrMDesign* rec);

	PlnrMDesign* operator[](const uint ix);
	ListPlnrMDesign& operator=(const ListPlnrMDesign& src);
	bool operator==(const ListPlnrMDesign& comp);
	bool operator!=(const ListPlnrMDesign& comp);

public:
	vector<PlnrMDesign*> nodes;
};

/**
  * TblPlnrMDesign: C++ wrapper for table TblPlnrMDesign
  */
class TblPlnrMDesign {

public:
	TblPlnrMDesign();
	virtual ~TblPlnrMDesign();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrMDesign** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrMDesign& rst);

	virtual void insertRec(PlnrMDesign* rec);
	ubigint insertNewRec(PlnrMDesign** rec = NULL, const ubigint grp = 0, const ubigint own = 0, const uint ixVBasetype = 0, const uint ixVDim = 0, const uint refIxVTbl = 0, const ubigint refUref = 0, const ubigint refPlnrMProject = 0, const uint ixWModtype = 0, const ubigint modRefPlnrMDesign = 0, const ubigint drvRefPlnrMDesign = 0, const string Title = "", const usmallint Major = 0, const usmallint Sub = 0, const string Comment = "");
	ubigint appendNewRecToRst(ListPlnrMDesign& rst, PlnrMDesign** rec = NULL, const ubigint grp = 0, const ubigint own = 0, const uint ixVBasetype = 0, const uint ixVDim = 0, const uint refIxVTbl = 0, const ubigint refUref = 0, const ubigint refPlnrMProject = 0, const uint ixWModtype = 0, const ubigint modRefPlnrMDesign = 0, const ubigint drvRefPlnrMDesign = 0, const string Title = "", const usmallint Major = 0, const usmallint Sub = 0, const string Comment = "");
	virtual void insertRst(ListPlnrMDesign& rst, bool transact = false);
	virtual void updateRec(PlnrMDesign* rec);
	virtual void updateRst(ListPlnrMDesign& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, PlnrMDesign** rec);
	virtual bool loadRecByRetReu(uint refIxVTbl, ubigint refUref, PlnrMDesign** rec);
	virtual ubigint loadRefsByMod(ubigint modRefPlnrMDesign, const bool append, vector<ubigint>& refs);
	virtual bool loadTitByRef(ubigint ref, string& val);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListPlnrMDesign& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrMDesign: C++ wrapper for table TblPlnrMDesign (MySQL database)
  */
class MyTblPlnrMDesign : public TblPlnrMDesign, public MyTable {

public:
	MyTblPlnrMDesign();
	~MyTblPlnrMDesign();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrMDesign** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrMDesign& rst);

	void insertRec(PlnrMDesign* rec);
	void insertRst(ListPlnrMDesign& rst, bool transact = false);
	void updateRec(PlnrMDesign* rec);
	void updateRst(ListPlnrMDesign& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrMDesign** rec);
	bool loadRecByRetReu(uint refIxVTbl, ubigint refUref, PlnrMDesign** rec);
	ubigint loadRefsByMod(ubigint modRefPlnrMDesign, const bool append, vector<ubigint>& refs);
	bool loadTitByRef(ubigint ref, string& val);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrMDesign: C++ wrapper for table TblPlnrMDesign (PgSQL database)
  */
class PgTblPlnrMDesign : public TblPlnrMDesign, public PgTable {

public:
	PgTblPlnrMDesign();
	~PgTblPlnrMDesign();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrMDesign** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrMDesign& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrMDesign** rec);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrMDesign** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrMDesign& rst);

	void insertRec(PlnrMDesign* rec);
	void insertRst(ListPlnrMDesign& rst, bool transact = false);
	void updateRec(PlnrMDesign* rec);
	void updateRst(ListPlnrMDesign& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrMDesign** rec);
	bool loadRecByRetReu(uint refIxVTbl, ubigint refUref, PlnrMDesign** rec);
	ubigint loadRefsByMod(ubigint modRefPlnrMDesign, const bool append, vector<ubigint>& refs);
	bool loadTitByRef(ubigint ref, string& val);
};
// IP pgTbl --- END

#endif

