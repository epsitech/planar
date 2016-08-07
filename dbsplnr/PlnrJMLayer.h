/**
  * \file PlnrJMLayer.h
  * database access for table TblPlnrJMLayer (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRJMLAYER_H
#define PLNRJMLAYER_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * PlnrJMLayer: record of TblPlnrJMLayer
  */
class PlnrJMLayer {

public:
	PlnrJMLayer(const ubigint ref = 0, const ubigint refPlnrMLayer = 0, const ubigint x1RefPlnrMDesign = 0, const string t = "", const string ML = "");

public:
	ubigint ref;
	ubigint refPlnrMLayer;
	ubigint x1RefPlnrMDesign;
	string t;
	string ML;

public:
	bool operator==(const PlnrJMLayer& comp);
	bool operator!=(const PlnrJMLayer& comp);
};

/**
  * ListPlnrJMLayer: recordset of TblPlnrJMLayer
  */
class ListPlnrJMLayer {

public:
	ListPlnrJMLayer();
	ListPlnrJMLayer(const ListPlnrJMLayer& src);
	~ListPlnrJMLayer();

	void clear();
	unsigned int size() const;
	void append(PlnrJMLayer* rec);

	PlnrJMLayer* operator[](const uint ix);
	ListPlnrJMLayer& operator=(const ListPlnrJMLayer& src);
	bool operator==(const ListPlnrJMLayer& comp);
	bool operator!=(const ListPlnrJMLayer& comp);

public:
	vector<PlnrJMLayer*> nodes;
};

/**
  * TblPlnrJMLayer: C++ wrapper for table TblPlnrJMLayer
  */
class TblPlnrJMLayer {

public:
	TblPlnrJMLayer();
	virtual ~TblPlnrJMLayer();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrJMLayer** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrJMLayer& rst);

	virtual void insertRec(PlnrJMLayer* rec);
	ubigint insertNewRec(PlnrJMLayer** rec = NULL, const ubigint refPlnrMLayer = 0, const ubigint x1RefPlnrMDesign = 0, const string t = "", const string ML = "");
	ubigint appendNewRecToRst(ListPlnrJMLayer& rst, PlnrJMLayer** rec = NULL, const ubigint refPlnrMLayer = 0, const ubigint x1RefPlnrMDesign = 0, const string t = "", const string ML = "");
	virtual void insertRst(ListPlnrJMLayer& rst, bool transact = false);
	virtual void updateRec(PlnrJMLayer* rec);
	virtual void updateRst(ListPlnrJMLayer& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, PlnrJMLayer** rec);
	virtual bool loadRecByLyrDsn(ubigint refPlnrMLayer, ubigint x1RefPlnrMDesign, PlnrJMLayer** rec);
	virtual ubigint loadRstByLyr(ubigint refPlnrMLayer, const bool append, ListPlnrJMLayer& rst);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListPlnrJMLayer& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrJMLayer: C++ wrapper for table TblPlnrJMLayer (MySQL database)
  */
class MyTblPlnrJMLayer : public TblPlnrJMLayer, public MyTable {

public:
	MyTblPlnrJMLayer();
	~MyTblPlnrJMLayer();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrJMLayer** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrJMLayer& rst);

	void insertRec(PlnrJMLayer* rec);
	void insertRst(ListPlnrJMLayer& rst, bool transact = false);
	void updateRec(PlnrJMLayer* rec);
	void updateRst(ListPlnrJMLayer& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrJMLayer** rec);
	bool loadRecByLyrDsn(ubigint refPlnrMLayer, ubigint x1RefPlnrMDesign, PlnrJMLayer** rec);
	ubigint loadRstByLyr(ubigint refPlnrMLayer, const bool append, ListPlnrJMLayer& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrJMLayer: C++ wrapper for table TblPlnrJMLayer (PgSQL database)
  */
class PgTblPlnrJMLayer : public TblPlnrJMLayer, public PgTable {

public:
	PgTblPlnrJMLayer();
	~PgTblPlnrJMLayer();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrJMLayer** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrJMLayer& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrJMLayer** rec);
// IP pgLoadRstByStmt --- BEGIN
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrJMLayer& rst);
// IP pgLoadRstByStmt --- END

public:
	bool loadRecBySQL(const string& sqlstr, PlnrJMLayer** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrJMLayer& rst);

	void insertRec(PlnrJMLayer* rec);
	void insertRst(ListPlnrJMLayer& rst, bool transact = false);
	void updateRec(PlnrJMLayer* rec);
	void updateRst(ListPlnrJMLayer& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrJMLayer** rec);
	bool loadRecByLyrDsn(ubigint refPlnrMLayer, ubigint x1RefPlnrMDesign, PlnrJMLayer** rec);
	ubigint loadRstByLyr(ubigint refPlnrMLayer, const bool append, ListPlnrJMLayer& rst);
};
// IP pgTbl --- END

#endif

