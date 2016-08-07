/**
  * \file PlnrDevOMDeviceMVertex.h
  * database access for table TblPlnrDevOMDeviceMVertex (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRDEVOMDEVICEMVERTEX_H
#define PLNRDEVOMDEVICEMVERTEX_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * PlnrDevOMDeviceMVertex: record of TblPlnrDevOMDeviceMVertex
  */
class PlnrDevOMDeviceMVertex {

public:
	PlnrDevOMDeviceMVertex(const ubigint ref = 0, const ubigint refPlnrMDevice = 0, const ubigint x1RefPlnrMDevice = 0, const uint ixPlnrVLop = 0, const ubigint pr1RefM = 0);

public:
	ubigint ref;
	ubigint refPlnrMDevice;
	ubigint x1RefPlnrMDevice;
	uint ixPlnrVLop;
	ubigint pr1RefM;

public:
	bool operator==(const PlnrDevOMDeviceMVertex& comp);
	bool operator!=(const PlnrDevOMDeviceMVertex& comp);
};

/**
  * ListPlnrDevOMDeviceMVertex: recordset of TblPlnrDevOMDeviceMVertex
  */
class ListPlnrDevOMDeviceMVertex {

public:
	ListPlnrDevOMDeviceMVertex();
	ListPlnrDevOMDeviceMVertex(const ListPlnrDevOMDeviceMVertex& src);
	~ListPlnrDevOMDeviceMVertex();

	void clear();
	unsigned int size() const;
	void append(PlnrDevOMDeviceMVertex* rec);

	PlnrDevOMDeviceMVertex* operator[](const uint ix);
	ListPlnrDevOMDeviceMVertex& operator=(const ListPlnrDevOMDeviceMVertex& src);
	bool operator==(const ListPlnrDevOMDeviceMVertex& comp);
	bool operator!=(const ListPlnrDevOMDeviceMVertex& comp);

public:
	vector<PlnrDevOMDeviceMVertex*> nodes;
};

/**
  * TblPlnrDevOMDeviceMVertex: C++ wrapper for table TblPlnrDevOMDeviceMVertex
  */
class TblPlnrDevOMDeviceMVertex {

public:
	TblPlnrDevOMDeviceMVertex();
	virtual ~TblPlnrDevOMDeviceMVertex();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrDevOMDeviceMVertex** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrDevOMDeviceMVertex& rst);

	virtual void insertRec(PlnrDevOMDeviceMVertex* rec);
	ubigint insertNewRec(PlnrDevOMDeviceMVertex** rec = NULL, const ubigint refPlnrMDevice = 0, const ubigint x1RefPlnrMDevice = 0, const uint ixPlnrVLop = 0, const ubigint pr1RefM = 0);
	ubigint appendNewRecToRst(ListPlnrDevOMDeviceMVertex& rst, PlnrDevOMDeviceMVertex** rec = NULL, const ubigint refPlnrMDevice = 0, const ubigint x1RefPlnrMDevice = 0, const uint ixPlnrVLop = 0, const ubigint pr1RefM = 0);
	virtual void insertRst(ListPlnrDevOMDeviceMVertex& rst, bool transact = false);
	virtual void updateRec(PlnrDevOMDeviceMVertex* rec);
	virtual void updateRst(ListPlnrDevOMDeviceMVertex& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, PlnrDevOMDeviceMVertex** rec);
	virtual ubigint loadRstByDevDv2(ubigint refPlnrMDevice, ubigint x1RefPlnrMDevice, const bool append, ListPlnrDevOMDeviceMVertex& rst);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListPlnrDevOMDeviceMVertex& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrDevOMDeviceMVertex: C++ wrapper for table TblPlnrDevOMDeviceMVertex (MySQL database)
  */
class MyTblPlnrDevOMDeviceMVertex : public TblPlnrDevOMDeviceMVertex, public MyTable {

public:
	MyTblPlnrDevOMDeviceMVertex();
	~MyTblPlnrDevOMDeviceMVertex();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrDevOMDeviceMVertex** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrDevOMDeviceMVertex& rst);

	void insertRec(PlnrDevOMDeviceMVertex* rec);
	void insertRst(ListPlnrDevOMDeviceMVertex& rst, bool transact = false);
	void updateRec(PlnrDevOMDeviceMVertex* rec);
	void updateRst(ListPlnrDevOMDeviceMVertex& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrDevOMDeviceMVertex** rec);
	ubigint loadRstByDevDv2(ubigint refPlnrMDevice, ubigint x1RefPlnrMDevice, const bool append, ListPlnrDevOMDeviceMVertex& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrDevOMDeviceMVertex: C++ wrapper for table TblPlnrDevOMDeviceMVertex (PgSQL database)
  */
class PgTblPlnrDevOMDeviceMVertex : public TblPlnrDevOMDeviceMVertex, public PgTable {

public:
	PgTblPlnrDevOMDeviceMVertex();
	~PgTblPlnrDevOMDeviceMVertex();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrDevOMDeviceMVertex** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrDevOMDeviceMVertex& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrDevOMDeviceMVertex** rec);
// IP pgLoadRstByStmt --- BEGIN
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrDevOMDeviceMVertex& rst);
// IP pgLoadRstByStmt --- END

public:
	bool loadRecBySQL(const string& sqlstr, PlnrDevOMDeviceMVertex** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrDevOMDeviceMVertex& rst);

	void insertRec(PlnrDevOMDeviceMVertex* rec);
	void insertRst(ListPlnrDevOMDeviceMVertex& rst, bool transact = false);
	void updateRec(PlnrDevOMDeviceMVertex* rec);
	void updateRst(ListPlnrDevOMDeviceMVertex& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrDevOMDeviceMVertex** rec);
	ubigint loadRstByDevDv2(ubigint refPlnrMDevice, ubigint x1RefPlnrMDevice, const bool append, ListPlnrDevOMDeviceMVertex& rst);
};
// IP pgTbl --- END

#endif

