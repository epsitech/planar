/**
  * \file PlnrDevORMLineguideMVertex.h
  * database access for table TblPlnrDevORMLineguideMVertex (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRDEVORMLINEGUIDEMVERTEX_H
#define PLNRDEVORMLINEGUIDEMVERTEX_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * PlnrDevORMLineguideMVertex: record of TblPlnrDevORMLineguideMVertex
  */
class PlnrDevORMLineguideMVertex {

public:
	PlnrDevORMLineguideMVertex(const ubigint ref = 0, const ubigint refPlnrMLineguide = 0, const ubigint x1RefPlnrMDevice = 0, const uint ixPlnrVLop = 0, const ubigint pr1RefLR = 0);

public:
	ubigint ref;
	ubigint refPlnrMLineguide;
	ubigint x1RefPlnrMDevice;
	uint ixPlnrVLop;
	ubigint pr1RefLR;

public:
	bool operator==(const PlnrDevORMLineguideMVertex& comp);
	bool operator!=(const PlnrDevORMLineguideMVertex& comp);
};

/**
  * ListPlnrDevORMLineguideMVertex: recordset of TblPlnrDevORMLineguideMVertex
  */
class ListPlnrDevORMLineguideMVertex {

public:
	ListPlnrDevORMLineguideMVertex();
	ListPlnrDevORMLineguideMVertex(const ListPlnrDevORMLineguideMVertex& src);
	~ListPlnrDevORMLineguideMVertex();

	void clear();
	unsigned int size() const;
	void append(PlnrDevORMLineguideMVertex* rec);

	PlnrDevORMLineguideMVertex* operator[](const uint ix);
	ListPlnrDevORMLineguideMVertex& operator=(const ListPlnrDevORMLineguideMVertex& src);
	bool operator==(const ListPlnrDevORMLineguideMVertex& comp);
	bool operator!=(const ListPlnrDevORMLineguideMVertex& comp);

public:
	vector<PlnrDevORMLineguideMVertex*> nodes;
};

/**
  * TblPlnrDevORMLineguideMVertex: C++ wrapper for table TblPlnrDevORMLineguideMVertex
  */
class TblPlnrDevORMLineguideMVertex {

public:
	TblPlnrDevORMLineguideMVertex();
	virtual ~TblPlnrDevORMLineguideMVertex();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrDevORMLineguideMVertex** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrDevORMLineguideMVertex& rst);

	virtual void insertRec(PlnrDevORMLineguideMVertex* rec);
	ubigint insertNewRec(PlnrDevORMLineguideMVertex** rec = NULL, const ubigint refPlnrMLineguide = 0, const ubigint x1RefPlnrMDevice = 0, const uint ixPlnrVLop = 0, const ubigint pr1RefLR = 0);
	ubigint appendNewRecToRst(ListPlnrDevORMLineguideMVertex& rst, PlnrDevORMLineguideMVertex** rec = NULL, const ubigint refPlnrMLineguide = 0, const ubigint x1RefPlnrMDevice = 0, const uint ixPlnrVLop = 0, const ubigint pr1RefLR = 0);
	virtual void insertRst(ListPlnrDevORMLineguideMVertex& rst, bool transact = false);
	virtual void updateRec(PlnrDevORMLineguideMVertex* rec);
	virtual void updateRst(ListPlnrDevORMLineguideMVertex& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, PlnrDevORMLineguideMVertex** rec);
	virtual ubigint loadRstByLgdDev(ubigint refPlnrMLineguide, ubigint x1RefPlnrMDevice, const bool append, ListPlnrDevORMLineguideMVertex& rst);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListPlnrDevORMLineguideMVertex& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrDevORMLineguideMVertex: C++ wrapper for table TblPlnrDevORMLineguideMVertex (MySQL database)
  */
class MyTblPlnrDevORMLineguideMVertex : public TblPlnrDevORMLineguideMVertex, public MyTable {

public:
	MyTblPlnrDevORMLineguideMVertex();
	~MyTblPlnrDevORMLineguideMVertex();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrDevORMLineguideMVertex** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrDevORMLineguideMVertex& rst);

	void insertRec(PlnrDevORMLineguideMVertex* rec);
	void insertRst(ListPlnrDevORMLineguideMVertex& rst, bool transact = false);
	void updateRec(PlnrDevORMLineguideMVertex* rec);
	void updateRst(ListPlnrDevORMLineguideMVertex& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrDevORMLineguideMVertex** rec);
	ubigint loadRstByLgdDev(ubigint refPlnrMLineguide, ubigint x1RefPlnrMDevice, const bool append, ListPlnrDevORMLineguideMVertex& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrDevORMLineguideMVertex: C++ wrapper for table TblPlnrDevORMLineguideMVertex (PgSQL database)
  */
class PgTblPlnrDevORMLineguideMVertex : public TblPlnrDevORMLineguideMVertex, public PgTable {

public:
	PgTblPlnrDevORMLineguideMVertex();
	~PgTblPlnrDevORMLineguideMVertex();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrDevORMLineguideMVertex** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrDevORMLineguideMVertex& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrDevORMLineguideMVertex** rec);
// IP pgLoadRstByStmt --- BEGIN
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrDevORMLineguideMVertex& rst);
// IP pgLoadRstByStmt --- END

public:
	bool loadRecBySQL(const string& sqlstr, PlnrDevORMLineguideMVertex** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrDevORMLineguideMVertex& rst);

	void insertRec(PlnrDevORMLineguideMVertex* rec);
	void insertRst(ListPlnrDevORMLineguideMVertex& rst, bool transact = false);
	void updateRec(PlnrDevORMLineguideMVertex* rec);
	void updateRst(ListPlnrDevORMLineguideMVertex& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrDevORMLineguideMVertex** rec);
	ubigint loadRstByLgdDev(ubigint refPlnrMLineguide, ubigint x1RefPlnrMDevice, const bool append, ListPlnrDevORMLineguideMVertex& rst);
};
// IP pgTbl --- END

#endif

