/**
  * \file PlnrMLayer.h
  * database access for table TblPlnrMLayer (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRMLAYER_H
#define PLNRMLAYER_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * PlnrMLayer: record of TblPlnrMLayer
  */
class PlnrMLayer {

public:
	PlnrMLayer(const ubigint ref = 0, const ubigint x1RefPlnrMDesign = 0, const uint ixVBasetype = 0, const uint hkIxVTbl = 0, const ubigint hkUref = 0, const uint hkNum = 0, const ubigint refPlnrMMaterial = 0, const uint ixVTtype = 0, const string sref = "", const ubigint flrRefPlnrMLevel = 0, const ubigint ctrRefPlnrMLevel = 0, const ubigint ceilRefPlnrMLevel = 0, const string t = "", const string ML = "");

public:
	ubigint ref;
	ubigint x1RefPlnrMDesign;
	uint ixVBasetype;
	uint hkIxVTbl;
	ubigint hkUref;
	uint hkNum;
	ubigint refPlnrMMaterial;
	uint ixVTtype;
	string sref;
	ubigint flrRefPlnrMLevel;
	ubigint ctrRefPlnrMLevel;
	ubigint ceilRefPlnrMLevel;
	string t;
	string ML;

public:
	bool operator==(const PlnrMLayer& comp);
	bool operator!=(const PlnrMLayer& comp);
};

/**
  * ListPlnrMLayer: recordset of TblPlnrMLayer
  */
class ListPlnrMLayer {

public:
	ListPlnrMLayer();
	ListPlnrMLayer(const ListPlnrMLayer& src);
	~ListPlnrMLayer();

	void clear();
	unsigned int size() const;
	void append(PlnrMLayer* rec);

	PlnrMLayer* operator[](const uint ix);
	ListPlnrMLayer& operator=(const ListPlnrMLayer& src);
	bool operator==(const ListPlnrMLayer& comp);
	bool operator!=(const ListPlnrMLayer& comp);

public:
	vector<PlnrMLayer*> nodes;
};

/**
  * TblPlnrMLayer: C++ wrapper for table TblPlnrMLayer
  */
class TblPlnrMLayer {

public:
	TblPlnrMLayer();
	virtual ~TblPlnrMLayer();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrMLayer** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrMLayer& rst);

	virtual void insertRec(PlnrMLayer* rec);
	ubigint insertNewRec(PlnrMLayer** rec = NULL, const ubigint x1RefPlnrMDesign = 0, const uint ixVBasetype = 0, const uint hkIxVTbl = 0, const ubigint hkUref = 0, const uint hkNum = 0, const ubigint refPlnrMMaterial = 0, const uint ixVTtype = 0, const string sref = "", const ubigint flrRefPlnrMLevel = 0, const ubigint ctrRefPlnrMLevel = 0, const ubigint ceilRefPlnrMLevel = 0, const string t = "", const string ML = "");
	ubigint appendNewRecToRst(ListPlnrMLayer& rst, PlnrMLayer** rec = NULL, const ubigint x1RefPlnrMDesign = 0, const uint ixVBasetype = 0, const uint hkIxVTbl = 0, const ubigint hkUref = 0, const uint hkNum = 0, const ubigint refPlnrMMaterial = 0, const uint ixVTtype = 0, const string sref = "", const ubigint flrRefPlnrMLevel = 0, const ubigint ctrRefPlnrMLevel = 0, const ubigint ceilRefPlnrMLevel = 0, const string t = "", const string ML = "");
	virtual void insertRst(ListPlnrMLayer& rst, bool transact = false);
	virtual void updateRec(PlnrMLayer* rec);
	virtual void updateRst(ListPlnrMLayer& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, PlnrMLayer** rec);
	virtual ubigint countByDsnHktHku(ubigint x1RefPlnrMDesign, uint hkIxVTbl, ubigint hkUref);
	virtual bool loadRefByHktHkuSrf(uint hkIxVTbl, ubigint hkUref, string sref, ubigint& val);
	virtual ubigint loadRstByDsnHktHku(ubigint x1RefPlnrMDesign, uint hkIxVTbl, ubigint hkUref, const bool append, ListPlnrMLayer& rst);
	virtual ubigint loadRstByDsnTypHktHku(ubigint x1RefPlnrMDesign, uint ixVBasetype, uint hkIxVTbl, ubigint hkUref, const bool append, ListPlnrMLayer& rst);
	virtual ubigint loadRstByHktHku(uint hkIxVTbl, ubigint hkUref, const bool append, ListPlnrMLayer& rst);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListPlnrMLayer& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrMLayer: C++ wrapper for table TblPlnrMLayer (MySQL database)
  */
class MyTblPlnrMLayer : public TblPlnrMLayer, public MyTable {

public:
	MyTblPlnrMLayer();
	~MyTblPlnrMLayer();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrMLayer** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrMLayer& rst);

	void insertRec(PlnrMLayer* rec);
	void insertRst(ListPlnrMLayer& rst, bool transact = false);
	void updateRec(PlnrMLayer* rec);
	void updateRst(ListPlnrMLayer& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrMLayer** rec);
	ubigint countByDsnHktHku(ubigint x1RefPlnrMDesign, uint hkIxVTbl, ubigint hkUref);
	bool loadRefByHktHkuSrf(uint hkIxVTbl, ubigint hkUref, string sref, ubigint& val);
	ubigint loadRstByDsnHktHku(ubigint x1RefPlnrMDesign, uint hkIxVTbl, ubigint hkUref, const bool append, ListPlnrMLayer& rst);
	ubigint loadRstByDsnTypHktHku(ubigint x1RefPlnrMDesign, uint ixVBasetype, uint hkIxVTbl, ubigint hkUref, const bool append, ListPlnrMLayer& rst);
	ubigint loadRstByHktHku(uint hkIxVTbl, ubigint hkUref, const bool append, ListPlnrMLayer& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrMLayer: C++ wrapper for table TblPlnrMLayer (PgSQL database)
  */
class PgTblPlnrMLayer : public TblPlnrMLayer, public PgTable {

public:
	PgTblPlnrMLayer();
	~PgTblPlnrMLayer();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrMLayer** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrMLayer& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrMLayer** rec);
// IP pgLoadRstByStmt --- BEGIN
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrMLayer& rst);
// IP pgLoadRstByStmt --- END

public:
	bool loadRecBySQL(const string& sqlstr, PlnrMLayer** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrMLayer& rst);

	void insertRec(PlnrMLayer* rec);
	void insertRst(ListPlnrMLayer& rst, bool transact = false);
	void updateRec(PlnrMLayer* rec);
	void updateRst(ListPlnrMLayer& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrMLayer** rec);
	ubigint countByDsnHktHku(ubigint x1RefPlnrMDesign, uint hkIxVTbl, ubigint hkUref);
	bool loadRefByHktHkuSrf(uint hkIxVTbl, ubigint hkUref, string sref, ubigint& val);
	ubigint loadRstByDsnHktHku(ubigint x1RefPlnrMDesign, uint hkIxVTbl, ubigint hkUref, const bool append, ListPlnrMLayer& rst);
	ubigint loadRstByDsnTypHktHku(ubigint x1RefPlnrMDesign, uint ixVBasetype, uint hkIxVTbl, ubigint hkUref, const bool append, ListPlnrMLayer& rst);
	ubigint loadRstByHktHku(uint hkIxVTbl, ubigint hkUref, const bool append, ListPlnrMLayer& rst);
};
// IP pgTbl --- END

#endif

