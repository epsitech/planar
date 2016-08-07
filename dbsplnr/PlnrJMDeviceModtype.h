/**
  * \file PlnrJMDeviceModtype.h
  * database access for table TblPlnrJMDeviceModtype (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRJMDEVICEMODTYPE_H
#define PLNRJMDEVICEMODTYPE_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * PlnrJMDeviceModtype: record of TblPlnrJMDeviceModtype
  */
class PlnrJMDeviceModtype {

public:
	PlnrJMDeviceModtype(const ubigint ref = 0, const ubigint refPlnrMDevice = 0, const ubigint x1RefPlnrMDesign = 0, const uint ixVModtype = 0);

public:
	ubigint ref;
	ubigint refPlnrMDevice;
	ubigint x1RefPlnrMDesign;
	uint ixVModtype;

public:
	bool operator==(const PlnrJMDeviceModtype& comp);
	bool operator!=(const PlnrJMDeviceModtype& comp);
};

/**
  * ListPlnrJMDeviceModtype: recordset of TblPlnrJMDeviceModtype
  */
class ListPlnrJMDeviceModtype {

public:
	ListPlnrJMDeviceModtype();
	ListPlnrJMDeviceModtype(const ListPlnrJMDeviceModtype& src);
	~ListPlnrJMDeviceModtype();

	void clear();
	unsigned int size() const;
	void append(PlnrJMDeviceModtype* rec);

	PlnrJMDeviceModtype* operator[](const uint ix);
	ListPlnrJMDeviceModtype& operator=(const ListPlnrJMDeviceModtype& src);
	bool operator==(const ListPlnrJMDeviceModtype& comp);
	bool operator!=(const ListPlnrJMDeviceModtype& comp);

public:
	vector<PlnrJMDeviceModtype*> nodes;
};

/**
  * TblPlnrJMDeviceModtype: C++ wrapper for table TblPlnrJMDeviceModtype
  */
class TblPlnrJMDeviceModtype {

public:
	TblPlnrJMDeviceModtype();
	virtual ~TblPlnrJMDeviceModtype();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrJMDeviceModtype** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrJMDeviceModtype& rst);

	virtual void insertRec(PlnrJMDeviceModtype* rec);
	ubigint insertNewRec(PlnrJMDeviceModtype** rec = NULL, const ubigint refPlnrMDevice = 0, const ubigint x1RefPlnrMDesign = 0, const uint ixVModtype = 0);
	ubigint appendNewRecToRst(ListPlnrJMDeviceModtype& rst, PlnrJMDeviceModtype** rec = NULL, const ubigint refPlnrMDevice = 0, const ubigint x1RefPlnrMDesign = 0, const uint ixVModtype = 0);
	virtual void insertRst(ListPlnrJMDeviceModtype& rst, bool transact = false);
	virtual void updateRec(PlnrJMDeviceModtype* rec);
	virtual void updateRst(ListPlnrJMDeviceModtype& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, PlnrJMDeviceModtype** rec);
	virtual bool loadRecByDevDsn(ubigint refPlnrMDevice, ubigint x1RefPlnrMDesign, PlnrJMDeviceModtype** rec);
	virtual ubigint loadRstByDev(ubigint refPlnrMDevice, const bool append, ListPlnrJMDeviceModtype& rst);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListPlnrJMDeviceModtype& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrJMDeviceModtype: C++ wrapper for table TblPlnrJMDeviceModtype (MySQL database)
  */
class MyTblPlnrJMDeviceModtype : public TblPlnrJMDeviceModtype, public MyTable {

public:
	MyTblPlnrJMDeviceModtype();
	~MyTblPlnrJMDeviceModtype();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrJMDeviceModtype** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrJMDeviceModtype& rst);

	void insertRec(PlnrJMDeviceModtype* rec);
	void insertRst(ListPlnrJMDeviceModtype& rst, bool transact = false);
	void updateRec(PlnrJMDeviceModtype* rec);
	void updateRst(ListPlnrJMDeviceModtype& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrJMDeviceModtype** rec);
	bool loadRecByDevDsn(ubigint refPlnrMDevice, ubigint x1RefPlnrMDesign, PlnrJMDeviceModtype** rec);
	ubigint loadRstByDev(ubigint refPlnrMDevice, const bool append, ListPlnrJMDeviceModtype& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrJMDeviceModtype: C++ wrapper for table TblPlnrJMDeviceModtype (PgSQL database)
  */
class PgTblPlnrJMDeviceModtype : public TblPlnrJMDeviceModtype, public PgTable {

public:
	PgTblPlnrJMDeviceModtype();
	~PgTblPlnrJMDeviceModtype();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrJMDeviceModtype** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrJMDeviceModtype& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrJMDeviceModtype** rec);
// IP pgLoadRstByStmt --- BEGIN
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrJMDeviceModtype& rst);
// IP pgLoadRstByStmt --- END

public:
	bool loadRecBySQL(const string& sqlstr, PlnrJMDeviceModtype** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrJMDeviceModtype& rst);

	void insertRec(PlnrJMDeviceModtype* rec);
	void insertRst(ListPlnrJMDeviceModtype& rst, bool transact = false);
	void updateRec(PlnrJMDeviceModtype* rec);
	void updateRst(ListPlnrJMDeviceModtype& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrJMDeviceModtype** rec);
	bool loadRecByDevDsn(ubigint refPlnrMDevice, ubigint x1RefPlnrMDesign, PlnrJMDeviceModtype** rec);
	ubigint loadRstByDev(ubigint refPlnrMDevice, const bool append, ListPlnrJMDeviceModtype& rst);
};
// IP pgTbl --- END

#endif

