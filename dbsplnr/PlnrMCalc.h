/**
  * \file PlnrMCalc.h
  * database access for table TblPlnrMCalc (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRMCALC_H
#define PLNRMCALC_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * PlnrMCalc: record of TblPlnrMCalc
  */
class PlnrMCalc {

public:
	PlnrMCalc(const ubigint ref = 0, const ubigint grp = 0, const ubigint own = 0, const ubigint refPlnrMProject = 0, const uint ixVDim = 0, const ubigint tplRefPlnrMCalc = 0, const ubigint supRefPlnrMCalc = 0, const ubigint refPlnrMDesign = 0, const string Title = "", const uint start = 0, const string Comment = "");

public:
	ubigint ref;
	ubigint grp;
	ubigint own;
	ubigint refPlnrMProject;
	uint ixVDim;
	ubigint tplRefPlnrMCalc;
	ubigint supRefPlnrMCalc;
	ubigint refPlnrMDesign;
	string Title;
	uint start;
	string Comment;

public:
	bool operator==(const PlnrMCalc& comp);
	bool operator!=(const PlnrMCalc& comp);
};

/**
  * ListPlnrMCalc: recordset of TblPlnrMCalc
  */
class ListPlnrMCalc {

public:
	ListPlnrMCalc();
	ListPlnrMCalc(const ListPlnrMCalc& src);
	~ListPlnrMCalc();

	void clear();
	unsigned int size() const;
	void append(PlnrMCalc* rec);

	PlnrMCalc* operator[](const uint ix);
	ListPlnrMCalc& operator=(const ListPlnrMCalc& src);
	bool operator==(const ListPlnrMCalc& comp);
	bool operator!=(const ListPlnrMCalc& comp);

public:
	vector<PlnrMCalc*> nodes;
};

/**
  * TblPlnrMCalc: C++ wrapper for table TblPlnrMCalc
  */
class TblPlnrMCalc {

public:
	TblPlnrMCalc();
	virtual ~TblPlnrMCalc();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrMCalc** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrMCalc& rst);

	virtual void insertRec(PlnrMCalc* rec);
	ubigint insertNewRec(PlnrMCalc** rec = NULL, const ubigint grp = 0, const ubigint own = 0, const ubigint refPlnrMProject = 0, const uint ixVDim = 0, const ubigint tplRefPlnrMCalc = 0, const ubigint supRefPlnrMCalc = 0, const ubigint refPlnrMDesign = 0, const string Title = "", const uint start = 0, const string Comment = "");
	ubigint appendNewRecToRst(ListPlnrMCalc& rst, PlnrMCalc** rec = NULL, const ubigint grp = 0, const ubigint own = 0, const ubigint refPlnrMProject = 0, const uint ixVDim = 0, const ubigint tplRefPlnrMCalc = 0, const ubigint supRefPlnrMCalc = 0, const ubigint refPlnrMDesign = 0, const string Title = "", const uint start = 0, const string Comment = "");
	virtual void insertRst(ListPlnrMCalc& rst, bool transact = false);
	virtual void updateRec(PlnrMCalc* rec);
	virtual void updateRst(ListPlnrMCalc& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, PlnrMCalc** rec);
	virtual bool confirmByRef(ubigint ref);
	virtual bool loadRecByTplTit(ubigint tplRefPlnrMCalc, string Title, PlnrMCalc** rec);
	virtual ubigint loadRefsBySup(ubigint supRefPlnrMCalc, const bool append, vector<ubigint>& refs);
	virtual ubigint loadRstBySup(ubigint supRefPlnrMCalc, const bool append, ListPlnrMCalc& rst);
	virtual bool loadSupByRef(ubigint ref, ubigint& val);
	virtual bool loadTitByRef(ubigint ref, string& val);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListPlnrMCalc& rst);
// IP loadHrefsup --- BEGIN
	ubigint loadHrefsup(ubigint ref, vector<ubigint>& refs);
// IP loadHrefsup --- END
// IP loadHrefsdown --- BEGIN
	ubigint loadHrefsdown(ubigint ref, const bool append, vector<ubigint>& refs, unsigned int firstix = 0, unsigned int lastix = 0);
// IP loadHrefsdown --- END
// IP loadHrstup --- BEGIN
	ubigint loadHrstup(ubigint ref, ListPlnrMCalc& rst);
// IP loadHrstup --- END
// IP loadHrstdown --- BEGIN
	ubigint loadHrstdown(ubigint ref, const bool append, ListPlnrMCalc& rst, unsigned int firstix = 0, unsigned int lastix = 0);
// IP loadHrstdown --- END
};

// IP myTbl --- BEGIN
/**
  * MyPlnrMCalc: C++ wrapper for table TblPlnrMCalc (MySQL database)
  */
class MyTblPlnrMCalc : public TblPlnrMCalc, public MyTable {

public:
	MyTblPlnrMCalc();
	~MyTblPlnrMCalc();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrMCalc** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrMCalc& rst);

	void insertRec(PlnrMCalc* rec);
	void insertRst(ListPlnrMCalc& rst, bool transact = false);
	void updateRec(PlnrMCalc* rec);
	void updateRst(ListPlnrMCalc& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrMCalc** rec);
	bool confirmByRef(ubigint ref);
	bool loadRecByTplTit(ubigint tplRefPlnrMCalc, string Title, PlnrMCalc** rec);
	ubigint loadRefsBySup(ubigint supRefPlnrMCalc, const bool append, vector<ubigint>& refs);
	ubigint loadRstBySup(ubigint supRefPlnrMCalc, const bool append, ListPlnrMCalc& rst);
	bool loadSupByRef(ubigint ref, ubigint& val);
	bool loadTitByRef(ubigint ref, string& val);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrMCalc: C++ wrapper for table TblPlnrMCalc (PgSQL database)
  */
class PgTblPlnrMCalc : public TblPlnrMCalc, public PgTable {

public:
	PgTblPlnrMCalc();
	~PgTblPlnrMCalc();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrMCalc** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrMCalc& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrMCalc** rec);
// IP pgLoadRstByStmt --- BEGIN
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrMCalc& rst);
// IP pgLoadRstByStmt --- END

public:
	bool loadRecBySQL(const string& sqlstr, PlnrMCalc** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrMCalc& rst);

	void insertRec(PlnrMCalc* rec);
	void insertRst(ListPlnrMCalc& rst, bool transact = false);
	void updateRec(PlnrMCalc* rec);
	void updateRst(ListPlnrMCalc& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrMCalc** rec);
	bool confirmByRef(ubigint ref);
	bool loadRecByTplTit(ubigint tplRefPlnrMCalc, string Title, PlnrMCalc** rec);
	ubigint loadRefsBySup(ubigint supRefPlnrMCalc, const bool append, vector<ubigint>& refs);
	ubigint loadRstBySup(ubigint supRefPlnrMCalc, const bool append, ListPlnrMCalc& rst);
	bool loadSupByRef(ubigint ref, ubigint& val);
	bool loadTitByRef(ubigint ref, string& val);
};
// IP pgTbl --- END

#endif

