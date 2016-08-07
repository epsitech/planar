/**
  * \file PlnrMBlock.h
  * database access for table TblPlnrMBlock (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRMBLOCK_H
#define PLNRMBLOCK_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * PlnrMBlock: record of TblPlnrMBlock
  */
class PlnrMBlock {

public:
	PlnrMBlock(const ubigint ref = 0, const ubigint refPlnrMDesign = 0, const ubigint refPlnrMStructure = 0, const ubigint refPlnrMLayer = 0);

public:
	ubigint ref;
	ubigint refPlnrMDesign;
	ubigint refPlnrMStructure;
	ubigint refPlnrMLayer;

public:
	bool operator==(const PlnrMBlock& comp);
	bool operator!=(const PlnrMBlock& comp);
};

/**
  * ListPlnrMBlock: recordset of TblPlnrMBlock
  */
class ListPlnrMBlock {

public:
	ListPlnrMBlock();
	ListPlnrMBlock(const ListPlnrMBlock& src);
	~ListPlnrMBlock();

	void clear();
	unsigned int size() const;
	void append(PlnrMBlock* rec);

	PlnrMBlock* operator[](const uint ix);
	ListPlnrMBlock& operator=(const ListPlnrMBlock& src);
	bool operator==(const ListPlnrMBlock& comp);
	bool operator!=(const ListPlnrMBlock& comp);

public:
	vector<PlnrMBlock*> nodes;
};

/**
  * TblPlnrMBlock: C++ wrapper for table TblPlnrMBlock
  */
class TblPlnrMBlock {

public:
	TblPlnrMBlock();
	virtual ~TblPlnrMBlock();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrMBlock** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrMBlock& rst);

	virtual void insertRec(PlnrMBlock* rec);
	ubigint insertNewRec(PlnrMBlock** rec = NULL, const ubigint refPlnrMDesign = 0, const ubigint refPlnrMStructure = 0, const ubigint refPlnrMLayer = 0);
	ubigint appendNewRecToRst(ListPlnrMBlock& rst, PlnrMBlock** rec = NULL, const ubigint refPlnrMDesign = 0, const ubigint refPlnrMStructure = 0, const ubigint refPlnrMLayer = 0);
	virtual void insertRst(ListPlnrMBlock& rst, bool transact = false);
	virtual void updateRec(PlnrMBlock* rec);
	virtual void updateRst(ListPlnrMBlock& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, PlnrMBlock** rec);
	virtual ubigint loadRstByDsn(ubigint refPlnrMDesign, const bool append, ListPlnrMBlock& rst);
	virtual ubigint loadRstByDsnLyr(ubigint refPlnrMDesign, ubigint refPlnrMLayer, const bool append, ListPlnrMBlock& rst);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListPlnrMBlock& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrMBlock: C++ wrapper for table TblPlnrMBlock (MySQL database)
  */
class MyTblPlnrMBlock : public TblPlnrMBlock, public MyTable {

public:
	MyTblPlnrMBlock();
	~MyTblPlnrMBlock();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrMBlock** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrMBlock& rst);

	void insertRec(PlnrMBlock* rec);
	void insertRst(ListPlnrMBlock& rst, bool transact = false);
	void updateRec(PlnrMBlock* rec);
	void updateRst(ListPlnrMBlock& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrMBlock** rec);
	ubigint loadRstByDsn(ubigint refPlnrMDesign, const bool append, ListPlnrMBlock& rst);
	ubigint loadRstByDsnLyr(ubigint refPlnrMDesign, ubigint refPlnrMLayer, const bool append, ListPlnrMBlock& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrMBlock: C++ wrapper for table TblPlnrMBlock (PgSQL database)
  */
class PgTblPlnrMBlock : public TblPlnrMBlock, public PgTable {

public:
	PgTblPlnrMBlock();
	~PgTblPlnrMBlock();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrMBlock** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrMBlock& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrMBlock** rec);
// IP pgLoadRstByStmt --- BEGIN
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrMBlock& rst);
// IP pgLoadRstByStmt --- END

public:
	bool loadRecBySQL(const string& sqlstr, PlnrMBlock** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrMBlock& rst);

	void insertRec(PlnrMBlock* rec);
	void insertRst(ListPlnrMBlock& rst, bool transact = false);
	void updateRec(PlnrMBlock* rec);
	void updateRst(ListPlnrMBlock& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrMBlock** rec);
	ubigint loadRstByDsn(ubigint refPlnrMDesign, const bool append, ListPlnrMBlock& rst);
	ubigint loadRstByDsnLyr(ubigint refPlnrMDesign, ubigint refPlnrMLayer, const bool append, ListPlnrMBlock& rst);
};
// IP pgTbl --- END

#endif

