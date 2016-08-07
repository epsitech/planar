/**
  * \file PlnrJMLayerMaterial.h
  * database access for table TblPlnrJMLayerMaterial (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRJMLAYERMATERIAL_H
#define PLNRJMLAYERMATERIAL_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * PlnrJMLayerMaterial: record of TblPlnrJMLayerMaterial
  */
class PlnrJMLayerMaterial {

public:
	PlnrJMLayerMaterial(const ubigint ref = 0, const ubigint refPlnrMLayer = 0, const ubigint x1RefPlnrMDesign = 0, const ubigint refPlnrMMaterial = 0);

public:
	ubigint ref;
	ubigint refPlnrMLayer;
	ubigint x1RefPlnrMDesign;
	ubigint refPlnrMMaterial;

public:
	bool operator==(const PlnrJMLayerMaterial& comp);
	bool operator!=(const PlnrJMLayerMaterial& comp);
};

/**
  * ListPlnrJMLayerMaterial: recordset of TblPlnrJMLayerMaterial
  */
class ListPlnrJMLayerMaterial {

public:
	ListPlnrJMLayerMaterial();
	ListPlnrJMLayerMaterial(const ListPlnrJMLayerMaterial& src);
	~ListPlnrJMLayerMaterial();

	void clear();
	unsigned int size() const;
	void append(PlnrJMLayerMaterial* rec);

	PlnrJMLayerMaterial* operator[](const uint ix);
	ListPlnrJMLayerMaterial& operator=(const ListPlnrJMLayerMaterial& src);
	bool operator==(const ListPlnrJMLayerMaterial& comp);
	bool operator!=(const ListPlnrJMLayerMaterial& comp);

public:
	vector<PlnrJMLayerMaterial*> nodes;
};

/**
  * TblPlnrJMLayerMaterial: C++ wrapper for table TblPlnrJMLayerMaterial
  */
class TblPlnrJMLayerMaterial {

public:
	TblPlnrJMLayerMaterial();
	virtual ~TblPlnrJMLayerMaterial();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrJMLayerMaterial** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrJMLayerMaterial& rst);

	virtual void insertRec(PlnrJMLayerMaterial* rec);
	ubigint insertNewRec(PlnrJMLayerMaterial** rec = NULL, const ubigint refPlnrMLayer = 0, const ubigint x1RefPlnrMDesign = 0, const ubigint refPlnrMMaterial = 0);
	ubigint appendNewRecToRst(ListPlnrJMLayerMaterial& rst, PlnrJMLayerMaterial** rec = NULL, const ubigint refPlnrMLayer = 0, const ubigint x1RefPlnrMDesign = 0, const ubigint refPlnrMMaterial = 0);
	virtual void insertRst(ListPlnrJMLayerMaterial& rst, bool transact = false);
	virtual void updateRec(PlnrJMLayerMaterial* rec);
	virtual void updateRst(ListPlnrJMLayerMaterial& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, PlnrJMLayerMaterial** rec);
	virtual bool loadRecByLyrDsn(ubigint refPlnrMLayer, ubigint x1RefPlnrMDesign, PlnrJMLayerMaterial** rec);
	virtual ubigint loadRstByLyr(ubigint refPlnrMLayer, const bool append, ListPlnrJMLayerMaterial& rst);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListPlnrJMLayerMaterial& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrJMLayerMaterial: C++ wrapper for table TblPlnrJMLayerMaterial (MySQL database)
  */
class MyTblPlnrJMLayerMaterial : public TblPlnrJMLayerMaterial, public MyTable {

public:
	MyTblPlnrJMLayerMaterial();
	~MyTblPlnrJMLayerMaterial();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrJMLayerMaterial** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrJMLayerMaterial& rst);

	void insertRec(PlnrJMLayerMaterial* rec);
	void insertRst(ListPlnrJMLayerMaterial& rst, bool transact = false);
	void updateRec(PlnrJMLayerMaterial* rec);
	void updateRst(ListPlnrJMLayerMaterial& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrJMLayerMaterial** rec);
	bool loadRecByLyrDsn(ubigint refPlnrMLayer, ubigint x1RefPlnrMDesign, PlnrJMLayerMaterial** rec);
	ubigint loadRstByLyr(ubigint refPlnrMLayer, const bool append, ListPlnrJMLayerMaterial& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrJMLayerMaterial: C++ wrapper for table TblPlnrJMLayerMaterial (PgSQL database)
  */
class PgTblPlnrJMLayerMaterial : public TblPlnrJMLayerMaterial, public PgTable {

public:
	PgTblPlnrJMLayerMaterial();
	~PgTblPlnrJMLayerMaterial();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrJMLayerMaterial** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrJMLayerMaterial& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrJMLayerMaterial** rec);
// IP pgLoadRstByStmt --- BEGIN
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrJMLayerMaterial& rst);
// IP pgLoadRstByStmt --- END

public:
	bool loadRecBySQL(const string& sqlstr, PlnrJMLayerMaterial** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrJMLayerMaterial& rst);

	void insertRec(PlnrJMLayerMaterial* rec);
	void insertRst(ListPlnrJMLayerMaterial& rst, bool transact = false);
	void updateRec(PlnrJMLayerMaterial* rec);
	void updateRst(ListPlnrJMLayerMaterial& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrJMLayerMaterial** rec);
	bool loadRecByLyrDsn(ubigint refPlnrMLayer, ubigint x1RefPlnrMDesign, PlnrJMLayerMaterial** rec);
	ubigint loadRstByLyr(ubigint refPlnrMLayer, const bool append, ListPlnrJMLayerMaterial& rst);
};
// IP pgTbl --- END

#endif

