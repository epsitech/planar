/**
  * \file PlnrAMDevicePar.h
  * database access for table TblPlnrAMDevicePar (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRAMDEVICEPAR_H
#define PLNRAMDEVICEPAR_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * PlnrAMDevicePar: record of TblPlnrAMDevicePar
  */
class PlnrAMDevicePar {

public:
	PlnrAMDevicePar(const ubigint ref = 0, const ubigint refPlnrMDevice = 0, const ubigint x1RefPlnrMDesign = 0, const string x2SrefKKey = "", const ubigint refPlnrMFile = 0, const string Val = "");

public:
	ubigint ref;
	ubigint refPlnrMDevice;
	ubigint x1RefPlnrMDesign;
	string x2SrefKKey;
	ubigint refPlnrMFile;
	string Val;

public:
	bool operator==(const PlnrAMDevicePar& comp);
	bool operator!=(const PlnrAMDevicePar& comp);
};

/**
  * ListPlnrAMDevicePar: recordset of TblPlnrAMDevicePar
  */
class ListPlnrAMDevicePar {

public:
	ListPlnrAMDevicePar();
	ListPlnrAMDevicePar(const ListPlnrAMDevicePar& src);
	~ListPlnrAMDevicePar();

	void clear();
	unsigned int size() const;
	void append(PlnrAMDevicePar* rec);

	PlnrAMDevicePar* operator[](const uint ix);
	ListPlnrAMDevicePar& operator=(const ListPlnrAMDevicePar& src);
	bool operator==(const ListPlnrAMDevicePar& comp);
	bool operator!=(const ListPlnrAMDevicePar& comp);

public:
	vector<PlnrAMDevicePar*> nodes;
};

/**
  * TblPlnrAMDevicePar: C++ wrapper for table TblPlnrAMDevicePar
  */
class TblPlnrAMDevicePar {

public:
	TblPlnrAMDevicePar();
	virtual ~TblPlnrAMDevicePar();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrAMDevicePar** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrAMDevicePar& rst);

	virtual void insertRec(PlnrAMDevicePar* rec);
	ubigint insertNewRec(PlnrAMDevicePar** rec = NULL, const ubigint refPlnrMDevice = 0, const ubigint x1RefPlnrMDesign = 0, const string x2SrefKKey = "", const ubigint refPlnrMFile = 0, const string Val = "");
	ubigint appendNewRecToRst(ListPlnrAMDevicePar& rst, PlnrAMDevicePar** rec = NULL, const ubigint refPlnrMDevice = 0, const ubigint x1RefPlnrMDesign = 0, const string x2SrefKKey = "", const ubigint refPlnrMFile = 0, const string Val = "");
	virtual void insertRst(ListPlnrAMDevicePar& rst, bool transact = false);
	virtual void updateRec(PlnrAMDevicePar* rec);
	virtual void updateRst(ListPlnrAMDevicePar& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, PlnrAMDevicePar** rec);
	virtual bool confirmByDevDsnKey(ubigint refPlnrMDevice, ubigint x1RefPlnrMDesign, string x2SrefKKey);
	virtual bool loadRecByDevDsnKey(ubigint refPlnrMDevice, ubigint x1RefPlnrMDesign, string x2SrefKKey, PlnrAMDevicePar** rec);
	virtual ubigint loadRefsByDev(ubigint refPlnrMDevice, const bool append, vector<ubigint>& refs);
	virtual ubigint loadRstByDev(ubigint refPlnrMDevice, const bool append, ListPlnrAMDevicePar& rst);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListPlnrAMDevicePar& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrAMDevicePar: C++ wrapper for table TblPlnrAMDevicePar (MySQL database)
  */
class MyTblPlnrAMDevicePar : public TblPlnrAMDevicePar, public MyTable {

public:
	MyTblPlnrAMDevicePar();
	~MyTblPlnrAMDevicePar();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrAMDevicePar** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrAMDevicePar& rst);

	void insertRec(PlnrAMDevicePar* rec);
	void insertRst(ListPlnrAMDevicePar& rst, bool transact = false);
	void updateRec(PlnrAMDevicePar* rec);
	void updateRst(ListPlnrAMDevicePar& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrAMDevicePar** rec);
	bool confirmByDevDsnKey(ubigint refPlnrMDevice, ubigint x1RefPlnrMDesign, string x2SrefKKey);
	bool loadRecByDevDsnKey(ubigint refPlnrMDevice, ubigint x1RefPlnrMDesign, string x2SrefKKey, PlnrAMDevicePar** rec);
	ubigint loadRefsByDev(ubigint refPlnrMDevice, const bool append, vector<ubigint>& refs);
	ubigint loadRstByDev(ubigint refPlnrMDevice, const bool append, ListPlnrAMDevicePar& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrAMDevicePar: C++ wrapper for table TblPlnrAMDevicePar (PgSQL database)
  */
class PgTblPlnrAMDevicePar : public TblPlnrAMDevicePar, public PgTable {

public:
	PgTblPlnrAMDevicePar();
	~PgTblPlnrAMDevicePar();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrAMDevicePar** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrAMDevicePar& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrAMDevicePar** rec);
// IP pgLoadRstByStmt --- BEGIN
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrAMDevicePar& rst);
// IP pgLoadRstByStmt --- END

public:
	bool loadRecBySQL(const string& sqlstr, PlnrAMDevicePar** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrAMDevicePar& rst);

	void insertRec(PlnrAMDevicePar* rec);
	void insertRst(ListPlnrAMDevicePar& rst, bool transact = false);
	void updateRec(PlnrAMDevicePar* rec);
	void updateRst(ListPlnrAMDevicePar& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrAMDevicePar** rec);
	bool confirmByDevDsnKey(ubigint refPlnrMDevice, ubigint x1RefPlnrMDesign, string x2SrefKKey);
	bool loadRecByDevDsnKey(ubigint refPlnrMDevice, ubigint x1RefPlnrMDesign, string x2SrefKKey, PlnrAMDevicePar** rec);
	ubigint loadRefsByDev(ubigint refPlnrMDevice, const bool append, vector<ubigint>& refs);
	ubigint loadRstByDev(ubigint refPlnrMDevice, const bool append, ListPlnrAMDevicePar& rst);
};
// IP pgTbl --- END

#endif

