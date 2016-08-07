/**
  * \file PlnrMMaterial.h
  * database access for table TblPlnrMMaterial (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRMMATERIAL_H
#define PLNRMMATERIAL_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * PlnrMMaterial: record of TblPlnrMMaterial
  */
class PlnrMMaterial {

public:
	PlnrMMaterial(const ubigint ref = 0, const ubigint grp = 0, const ubigint own = 0, const uint ixVBasetype = 0, const ubigint refPlnrMCalc = 0, const ubigint modRefPlnrMMaterial = 0, const usmallint modLvl = 0, const string sref = "", const string Title = "");

public:
	ubigint ref;
	ubigint grp;
	ubigint own;
	uint ixVBasetype;
	ubigint refPlnrMCalc;
	ubigint modRefPlnrMMaterial;
	usmallint modLvl;
	string sref;
	string Title;

public:
	bool operator==(const PlnrMMaterial& comp);
	bool operator!=(const PlnrMMaterial& comp);
};

/**
  * ListPlnrMMaterial: recordset of TblPlnrMMaterial
  */
class ListPlnrMMaterial {

public:
	ListPlnrMMaterial();
	ListPlnrMMaterial(const ListPlnrMMaterial& src);
	~ListPlnrMMaterial();

	void clear();
	unsigned int size() const;
	void append(PlnrMMaterial* rec);

	PlnrMMaterial* operator[](const uint ix);
	ListPlnrMMaterial& operator=(const ListPlnrMMaterial& src);
	bool operator==(const ListPlnrMMaterial& comp);
	bool operator!=(const ListPlnrMMaterial& comp);

public:
	vector<PlnrMMaterial*> nodes;
};

/**
  * TblPlnrMMaterial: C++ wrapper for table TblPlnrMMaterial
  */
class TblPlnrMMaterial {

public:
	TblPlnrMMaterial();
	virtual ~TblPlnrMMaterial();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrMMaterial** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrMMaterial& rst);

	virtual void insertRec(PlnrMMaterial* rec);
	ubigint insertNewRec(PlnrMMaterial** rec = NULL, const ubigint grp = 0, const ubigint own = 0, const uint ixVBasetype = 0, const ubigint refPlnrMCalc = 0, const ubigint modRefPlnrMMaterial = 0, const usmallint modLvl = 0, const string sref = "", const string Title = "");
	ubigint appendNewRecToRst(ListPlnrMMaterial& rst, PlnrMMaterial** rec = NULL, const ubigint grp = 0, const ubigint own = 0, const uint ixVBasetype = 0, const ubigint refPlnrMCalc = 0, const ubigint modRefPlnrMMaterial = 0, const usmallint modLvl = 0, const string sref = "", const string Title = "");
	virtual void insertRst(ListPlnrMMaterial& rst, bool transact = false);
	virtual void updateRec(PlnrMMaterial* rec);
	virtual void updateRst(ListPlnrMMaterial& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, PlnrMMaterial** rec);
	virtual bool confirmByRef(ubigint ref);
	virtual bool loadRefBySupSrf(ubigint modRefPlnrMMaterial, string sref, ubigint& val);
	virtual ubigint loadRefsBySup(ubigint modRefPlnrMMaterial, const bool append, vector<ubigint>& refs);
	virtual ubigint loadRstBySup(ubigint modRefPlnrMMaterial, const bool append, ListPlnrMMaterial& rst);
	virtual bool loadSupByRef(ubigint ref, ubigint& val);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListPlnrMMaterial& rst);
// IP loadHrefsup --- BEGIN
	ubigint loadHrefsup(ubigint ref, vector<ubigint>& refs);
// IP loadHrefsup --- END
// IP loadHrefsdown --- BEGIN
	ubigint loadHrefsdown(ubigint ref, const bool append, vector<ubigint>& refs, unsigned int firstix = 0, unsigned int lastix = 0);
// IP loadHrefsdown --- END
// IP loadHrstup --- BEGIN
	ubigint loadHrstup(ubigint ref, ListPlnrMMaterial& rst);
// IP loadHrstup --- END
// IP loadHrstdown --- BEGIN
	ubigint loadHrstdown(ubigint ref, const bool append, ListPlnrMMaterial& rst, unsigned int firstix = 0, unsigned int lastix = 0);
// IP loadHrstdown --- END
};

// IP myTbl --- BEGIN
/**
  * MyPlnrMMaterial: C++ wrapper for table TblPlnrMMaterial (MySQL database)
  */
class MyTblPlnrMMaterial : public TblPlnrMMaterial, public MyTable {

public:
	MyTblPlnrMMaterial();
	~MyTblPlnrMMaterial();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrMMaterial** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrMMaterial& rst);

	void insertRec(PlnrMMaterial* rec);
	void insertRst(ListPlnrMMaterial& rst, bool transact = false);
	void updateRec(PlnrMMaterial* rec);
	void updateRst(ListPlnrMMaterial& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrMMaterial** rec);
	bool confirmByRef(ubigint ref);
	bool loadRefBySupSrf(ubigint modRefPlnrMMaterial, string sref, ubigint& val);
	ubigint loadRefsBySup(ubigint modRefPlnrMMaterial, const bool append, vector<ubigint>& refs);
	ubigint loadRstBySup(ubigint modRefPlnrMMaterial, const bool append, ListPlnrMMaterial& rst);
	bool loadSupByRef(ubigint ref, ubigint& val);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrMMaterial: C++ wrapper for table TblPlnrMMaterial (PgSQL database)
  */
class PgTblPlnrMMaterial : public TblPlnrMMaterial, public PgTable {

public:
	PgTblPlnrMMaterial();
	~PgTblPlnrMMaterial();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrMMaterial** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrMMaterial& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrMMaterial** rec);
// IP pgLoadRstByStmt --- BEGIN
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrMMaterial& rst);
// IP pgLoadRstByStmt --- END

public:
	bool loadRecBySQL(const string& sqlstr, PlnrMMaterial** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrMMaterial& rst);

	void insertRec(PlnrMMaterial* rec);
	void insertRst(ListPlnrMMaterial& rst, bool transact = false);
	void updateRec(PlnrMMaterial* rec);
	void updateRst(ListPlnrMMaterial& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrMMaterial** rec);
	bool confirmByRef(ubigint ref);
	bool loadRefBySupSrf(ubigint modRefPlnrMMaterial, string sref, ubigint& val);
	ubigint loadRefsBySup(ubigint modRefPlnrMMaterial, const bool append, vector<ubigint>& refs);
	ubigint loadRstBySup(ubigint modRefPlnrMMaterial, const bool append, ListPlnrMMaterial& rst);
	bool loadSupByRef(ubigint ref, ubigint& val);
};
// IP pgTbl --- END

#endif

