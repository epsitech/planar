/**
  * \file PlnrOMStructureMFace.h
  * database access for table TblPlnrOMStructureMFace (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNROMSTRUCTUREMFACE_H
#define PLNROMSTRUCTUREMFACE_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * PlnrOMStructureMFace: record of TblPlnrOMStructureMFace
  */
class PlnrOMStructureMFace {

public:
	PlnrOMStructureMFace(const ubigint ref = 0, const ubigint refPlnrMStructure = 0, const ubigint x1RefPlnrMDevice = 0, const uint ixPlnrVLop = 0, const ubigint pr1RefM = 0);

public:
	ubigint ref;
	ubigint refPlnrMStructure;
	ubigint x1RefPlnrMDevice;
	uint ixPlnrVLop;
	ubigint pr1RefM;

public:
	bool operator==(const PlnrOMStructureMFace& comp);
	bool operator!=(const PlnrOMStructureMFace& comp);
};

/**
  * ListPlnrOMStructureMFace: recordset of TblPlnrOMStructureMFace
  */
class ListPlnrOMStructureMFace {

public:
	ListPlnrOMStructureMFace();
	ListPlnrOMStructureMFace(const ListPlnrOMStructureMFace& src);
	~ListPlnrOMStructureMFace();

	void clear();
	unsigned int size() const;
	void append(PlnrOMStructureMFace* rec);

	PlnrOMStructureMFace* operator[](const uint ix);
	ListPlnrOMStructureMFace& operator=(const ListPlnrOMStructureMFace& src);
	bool operator==(const ListPlnrOMStructureMFace& comp);
	bool operator!=(const ListPlnrOMStructureMFace& comp);

public:
	vector<PlnrOMStructureMFace*> nodes;
};

/**
  * TblPlnrOMStructureMFace: C++ wrapper for table TblPlnrOMStructureMFace
  */
class TblPlnrOMStructureMFace {

public:
	TblPlnrOMStructureMFace();
	virtual ~TblPlnrOMStructureMFace();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrOMStructureMFace** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrOMStructureMFace& rst);

	virtual void insertRec(PlnrOMStructureMFace* rec);
	ubigint insertNewRec(PlnrOMStructureMFace** rec = NULL, const ubigint refPlnrMStructure = 0, const ubigint x1RefPlnrMDevice = 0, const uint ixPlnrVLop = 0, const ubigint pr1RefM = 0);
	ubigint appendNewRecToRst(ListPlnrOMStructureMFace& rst, PlnrOMStructureMFace** rec = NULL, const ubigint refPlnrMStructure = 0, const ubigint x1RefPlnrMDevice = 0, const uint ixPlnrVLop = 0, const ubigint pr1RefM = 0);
	virtual void insertRst(ListPlnrOMStructureMFace& rst, bool transact = false);
	virtual void updateRec(PlnrOMStructureMFace* rec);
	virtual void updateRst(ListPlnrOMStructureMFace& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, PlnrOMStructureMFace** rec);
	virtual ubigint loadRstBySruDev(ubigint refPlnrMStructure, ubigint x1RefPlnrMDevice, const bool append, ListPlnrOMStructureMFace& rst);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListPlnrOMStructureMFace& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrOMStructureMFace: C++ wrapper for table TblPlnrOMStructureMFace (MySQL database)
  */
class MyTblPlnrOMStructureMFace : public TblPlnrOMStructureMFace, public MyTable {

public:
	MyTblPlnrOMStructureMFace();
	~MyTblPlnrOMStructureMFace();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrOMStructureMFace** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrOMStructureMFace& rst);

	void insertRec(PlnrOMStructureMFace* rec);
	void insertRst(ListPlnrOMStructureMFace& rst, bool transact = false);
	void updateRec(PlnrOMStructureMFace* rec);
	void updateRst(ListPlnrOMStructureMFace& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrOMStructureMFace** rec);
	ubigint loadRstBySruDev(ubigint refPlnrMStructure, ubigint x1RefPlnrMDevice, const bool append, ListPlnrOMStructureMFace& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrOMStructureMFace: C++ wrapper for table TblPlnrOMStructureMFace (PgSQL database)
  */
class PgTblPlnrOMStructureMFace : public TblPlnrOMStructureMFace, public PgTable {

public:
	PgTblPlnrOMStructureMFace();
	~PgTblPlnrOMStructureMFace();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrOMStructureMFace** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrOMStructureMFace& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrOMStructureMFace** rec);
// IP pgLoadRstByStmt --- BEGIN
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrOMStructureMFace& rst);
// IP pgLoadRstByStmt --- END

public:
	bool loadRecBySQL(const string& sqlstr, PlnrOMStructureMFace** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrOMStructureMFace& rst);

	void insertRec(PlnrOMStructureMFace* rec);
	void insertRst(ListPlnrOMStructureMFace& rst, bool transact = false);
	void updateRec(PlnrOMStructureMFace* rec);
	void updateRst(ListPlnrOMStructureMFace& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrOMStructureMFace** rec);
	ubigint loadRstBySruDev(ubigint refPlnrMStructure, ubigint x1RefPlnrMDevice, const bool append, ListPlnrOMStructureMFace& rst);
};
// IP pgTbl --- END

#endif

