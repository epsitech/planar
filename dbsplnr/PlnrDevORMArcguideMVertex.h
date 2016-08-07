/**
  * \file PlnrDevORMArcguideMVertex.h
  * database access for table TblPlnrDevORMArcguideMVertex (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRDEVORMARCGUIDEMVERTEX_H
#define PLNRDEVORMARCGUIDEMVERTEX_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * PlnrDevORMArcguideMVertex: record of TblPlnrDevORMArcguideMVertex
  */
class PlnrDevORMArcguideMVertex {

public:
	PlnrDevORMArcguideMVertex(const ubigint ref = 0, const ubigint refPlnrMArcguide = 0, const ubigint x1RefPlnrMDevice = 0, const uint ixPlnrVLop = 0, const ubigint pr1RefLR = 0);

public:
	ubigint ref;
	ubigint refPlnrMArcguide;
	ubigint x1RefPlnrMDevice;
	uint ixPlnrVLop;
	ubigint pr1RefLR;

public:
	bool operator==(const PlnrDevORMArcguideMVertex& comp);
	bool operator!=(const PlnrDevORMArcguideMVertex& comp);
};

/**
  * ListPlnrDevORMArcguideMVertex: recordset of TblPlnrDevORMArcguideMVertex
  */
class ListPlnrDevORMArcguideMVertex {

public:
	ListPlnrDevORMArcguideMVertex();
	ListPlnrDevORMArcguideMVertex(const ListPlnrDevORMArcguideMVertex& src);
	~ListPlnrDevORMArcguideMVertex();

	void clear();
	unsigned int size() const;
	void append(PlnrDevORMArcguideMVertex* rec);

	PlnrDevORMArcguideMVertex* operator[](const uint ix);
	ListPlnrDevORMArcguideMVertex& operator=(const ListPlnrDevORMArcguideMVertex& src);
	bool operator==(const ListPlnrDevORMArcguideMVertex& comp);
	bool operator!=(const ListPlnrDevORMArcguideMVertex& comp);

public:
	vector<PlnrDevORMArcguideMVertex*> nodes;
};

/**
  * TblPlnrDevORMArcguideMVertex: C++ wrapper for table TblPlnrDevORMArcguideMVertex
  */
class TblPlnrDevORMArcguideMVertex {

public:
	TblPlnrDevORMArcguideMVertex();
	virtual ~TblPlnrDevORMArcguideMVertex();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrDevORMArcguideMVertex** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrDevORMArcguideMVertex& rst);

	virtual void insertRec(PlnrDevORMArcguideMVertex* rec);
	ubigint insertNewRec(PlnrDevORMArcguideMVertex** rec = NULL, const ubigint refPlnrMArcguide = 0, const ubigint x1RefPlnrMDevice = 0, const uint ixPlnrVLop = 0, const ubigint pr1RefLR = 0);
	ubigint appendNewRecToRst(ListPlnrDevORMArcguideMVertex& rst, PlnrDevORMArcguideMVertex** rec = NULL, const ubigint refPlnrMArcguide = 0, const ubigint x1RefPlnrMDevice = 0, const uint ixPlnrVLop = 0, const ubigint pr1RefLR = 0);
	virtual void insertRst(ListPlnrDevORMArcguideMVertex& rst, bool transact = false);
	virtual void updateRec(PlnrDevORMArcguideMVertex* rec);
	virtual void updateRst(ListPlnrDevORMArcguideMVertex& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, PlnrDevORMArcguideMVertex** rec);
	virtual ubigint loadRstByAgdDev(ubigint refPlnrMArcguide, ubigint x1RefPlnrMDevice, const bool append, ListPlnrDevORMArcguideMVertex& rst);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListPlnrDevORMArcguideMVertex& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrDevORMArcguideMVertex: C++ wrapper for table TblPlnrDevORMArcguideMVertex (MySQL database)
  */
class MyTblPlnrDevORMArcguideMVertex : public TblPlnrDevORMArcguideMVertex, public MyTable {

public:
	MyTblPlnrDevORMArcguideMVertex();
	~MyTblPlnrDevORMArcguideMVertex();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrDevORMArcguideMVertex** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrDevORMArcguideMVertex& rst);

	void insertRec(PlnrDevORMArcguideMVertex* rec);
	void insertRst(ListPlnrDevORMArcguideMVertex& rst, bool transact = false);
	void updateRec(PlnrDevORMArcguideMVertex* rec);
	void updateRst(ListPlnrDevORMArcguideMVertex& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrDevORMArcguideMVertex** rec);
	ubigint loadRstByAgdDev(ubigint refPlnrMArcguide, ubigint x1RefPlnrMDevice, const bool append, ListPlnrDevORMArcguideMVertex& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrDevORMArcguideMVertex: C++ wrapper for table TblPlnrDevORMArcguideMVertex (PgSQL database)
  */
class PgTblPlnrDevORMArcguideMVertex : public TblPlnrDevORMArcguideMVertex, public PgTable {

public:
	PgTblPlnrDevORMArcguideMVertex();
	~PgTblPlnrDevORMArcguideMVertex();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrDevORMArcguideMVertex** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrDevORMArcguideMVertex& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrDevORMArcguideMVertex** rec);
// IP pgLoadRstByStmt --- BEGIN
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrDevORMArcguideMVertex& rst);
// IP pgLoadRstByStmt --- END

public:
	bool loadRecBySQL(const string& sqlstr, PlnrDevORMArcguideMVertex** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrDevORMArcguideMVertex& rst);

	void insertRec(PlnrDevORMArcguideMVertex* rec);
	void insertRst(ListPlnrDevORMArcguideMVertex& rst, bool transact = false);
	void updateRec(PlnrDevORMArcguideMVertex* rec);
	void updateRst(ListPlnrDevORMArcguideMVertex& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrDevORMArcguideMVertex** rec);
	ubigint loadRstByAgdDev(ubigint refPlnrMArcguide, ubigint x1RefPlnrMDevice, const bool append, ListPlnrDevORMArcguideMVertex& rst);
};
// IP pgTbl --- END

#endif

