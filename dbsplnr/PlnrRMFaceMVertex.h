/**
  * \file PlnrRMFaceMVertex.h
  * database access for table TblPlnrRMFaceMVertex (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRRMFACEMVERTEX_H
#define PLNRRMFACEMVERTEX_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * PlnrRMFaceMVertex: record of TblPlnrRMFaceMVertex
  */
class PlnrRMFaceMVertex {

public:
	PlnrRMFaceMVertex(const ubigint ref = 0, const ubigint fceRefPlnrMFace = 0, const uint fceNum = 0, const ubigint refPlnrMVertex = 0, const uint rteIxVTbl = 0, const ubigint rteUref = 0, const uint ixVDir = 0);

public:
	ubigint ref;
	ubigint fceRefPlnrMFace;
	uint fceNum;
	ubigint refPlnrMVertex;
	uint rteIxVTbl;
	ubigint rteUref;
	uint ixVDir;

public:
	bool operator==(const PlnrRMFaceMVertex& comp);
	bool operator!=(const PlnrRMFaceMVertex& comp);
};

/**
  * ListPlnrRMFaceMVertex: recordset of TblPlnrRMFaceMVertex
  */
class ListPlnrRMFaceMVertex {

public:
	ListPlnrRMFaceMVertex();
	ListPlnrRMFaceMVertex(const ListPlnrRMFaceMVertex& src);
	~ListPlnrRMFaceMVertex();

	void clear();
	unsigned int size() const;
	void append(PlnrRMFaceMVertex* rec);

	PlnrRMFaceMVertex* operator[](const uint ix);
	ListPlnrRMFaceMVertex& operator=(const ListPlnrRMFaceMVertex& src);
	bool operator==(const ListPlnrRMFaceMVertex& comp);
	bool operator!=(const ListPlnrRMFaceMVertex& comp);

public:
	vector<PlnrRMFaceMVertex*> nodes;
};

/**
  * TblPlnrRMFaceMVertex: C++ wrapper for table TblPlnrRMFaceMVertex
  */
class TblPlnrRMFaceMVertex {

public:
	TblPlnrRMFaceMVertex();
	virtual ~TblPlnrRMFaceMVertex();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrRMFaceMVertex** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrRMFaceMVertex& rst);

	virtual void insertRec(PlnrRMFaceMVertex* rec);
	ubigint insertNewRec(PlnrRMFaceMVertex** rec = NULL, const ubigint fceRefPlnrMFace = 0, const uint fceNum = 0, const ubigint refPlnrMVertex = 0, const uint rteIxVTbl = 0, const ubigint rteUref = 0, const uint ixVDir = 0);
	ubigint appendNewRecToRst(ListPlnrRMFaceMVertex& rst, PlnrRMFaceMVertex** rec = NULL, const ubigint fceRefPlnrMFace = 0, const uint fceNum = 0, const ubigint refPlnrMVertex = 0, const uint rteIxVTbl = 0, const ubigint rteUref = 0, const uint ixVDir = 0);
	virtual void insertRst(ListPlnrRMFaceMVertex& rst, bool transact = false);
	virtual void updateRec(PlnrRMFaceMVertex* rec);
	virtual void updateRst(ListPlnrRMFaceMVertex& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, PlnrRMFaceMVertex** rec);
	virtual ubigint loadRstByFce(ubigint fceRefPlnrMFace, const bool append, ListPlnrRMFaceMVertex& rst);
	virtual ubigint loadRstByRttRtu(uint rteIxVTbl, ubigint rteUref, const bool append, ListPlnrRMFaceMVertex& rst);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListPlnrRMFaceMVertex& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrRMFaceMVertex: C++ wrapper for table TblPlnrRMFaceMVertex (MySQL database)
  */
class MyTblPlnrRMFaceMVertex : public TblPlnrRMFaceMVertex, public MyTable {

public:
	MyTblPlnrRMFaceMVertex();
	~MyTblPlnrRMFaceMVertex();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrRMFaceMVertex** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrRMFaceMVertex& rst);

	void insertRec(PlnrRMFaceMVertex* rec);
	void insertRst(ListPlnrRMFaceMVertex& rst, bool transact = false);
	void updateRec(PlnrRMFaceMVertex* rec);
	void updateRst(ListPlnrRMFaceMVertex& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrRMFaceMVertex** rec);
	ubigint loadRstByFce(ubigint fceRefPlnrMFace, const bool append, ListPlnrRMFaceMVertex& rst);
	ubigint loadRstByRttRtu(uint rteIxVTbl, ubigint rteUref, const bool append, ListPlnrRMFaceMVertex& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrRMFaceMVertex: C++ wrapper for table TblPlnrRMFaceMVertex (PgSQL database)
  */
class PgTblPlnrRMFaceMVertex : public TblPlnrRMFaceMVertex, public PgTable {

public:
	PgTblPlnrRMFaceMVertex();
	~PgTblPlnrRMFaceMVertex();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrRMFaceMVertex** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrRMFaceMVertex& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrRMFaceMVertex** rec);
// IP pgLoadRstByStmt --- BEGIN
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrRMFaceMVertex& rst);
// IP pgLoadRstByStmt --- END

public:
	bool loadRecBySQL(const string& sqlstr, PlnrRMFaceMVertex** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrRMFaceMVertex& rst);

	void insertRec(PlnrRMFaceMVertex* rec);
	void insertRst(ListPlnrRMFaceMVertex& rst, bool transact = false);
	void updateRec(PlnrRMFaceMVertex* rec);
	void updateRst(ListPlnrRMFaceMVertex& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrRMFaceMVertex** rec);
	ubigint loadRstByFce(ubigint fceRefPlnrMFace, const bool append, ListPlnrRMFaceMVertex& rst);
	ubigint loadRstByRttRtu(uint rteIxVTbl, ubigint rteUref, const bool append, ListPlnrRMFaceMVertex& rst);
};
// IP pgTbl --- END

#endif

