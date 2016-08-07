/**
  * \file PlnrDevOMDeviceMArcguide.h
  * database access for table TblPlnrDevOMDeviceMArcguide (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRDEVOMDEVICEMARCGUIDE_H
#define PLNRDEVOMDEVICEMARCGUIDE_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * PlnrDevOMDeviceMArcguide: record of TblPlnrDevOMDeviceMArcguide
  */
class PlnrDevOMDeviceMArcguide {

public:
	PlnrDevOMDeviceMArcguide(const ubigint ref = 0, const ubigint refPlnrMDevice = 0, const ubigint x1RefPlnrMDevice = 0, const uint ixPlnrVLop = 0, const ubigint pr1RefM = 0);

public:
	ubigint ref;
	ubigint refPlnrMDevice;
	ubigint x1RefPlnrMDevice;
	uint ixPlnrVLop;
	ubigint pr1RefM;

public:
	bool operator==(const PlnrDevOMDeviceMArcguide& comp);
	bool operator!=(const PlnrDevOMDeviceMArcguide& comp);
};

/**
  * ListPlnrDevOMDeviceMArcguide: recordset of TblPlnrDevOMDeviceMArcguide
  */
class ListPlnrDevOMDeviceMArcguide {

public:
	ListPlnrDevOMDeviceMArcguide();
	ListPlnrDevOMDeviceMArcguide(const ListPlnrDevOMDeviceMArcguide& src);
	~ListPlnrDevOMDeviceMArcguide();

	void clear();
	unsigned int size() const;
	void append(PlnrDevOMDeviceMArcguide* rec);

	PlnrDevOMDeviceMArcguide* operator[](const uint ix);
	ListPlnrDevOMDeviceMArcguide& operator=(const ListPlnrDevOMDeviceMArcguide& src);
	bool operator==(const ListPlnrDevOMDeviceMArcguide& comp);
	bool operator!=(const ListPlnrDevOMDeviceMArcguide& comp);

public:
	vector<PlnrDevOMDeviceMArcguide*> nodes;
};

/**
  * TblPlnrDevOMDeviceMArcguide: C++ wrapper for table TblPlnrDevOMDeviceMArcguide
  */
class TblPlnrDevOMDeviceMArcguide {

public:
	TblPlnrDevOMDeviceMArcguide();
	virtual ~TblPlnrDevOMDeviceMArcguide();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrDevOMDeviceMArcguide** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrDevOMDeviceMArcguide& rst);

	virtual void insertRec(PlnrDevOMDeviceMArcguide* rec);
	ubigint insertNewRec(PlnrDevOMDeviceMArcguide** rec = NULL, const ubigint refPlnrMDevice = 0, const ubigint x1RefPlnrMDevice = 0, const uint ixPlnrVLop = 0, const ubigint pr1RefM = 0);
	ubigint appendNewRecToRst(ListPlnrDevOMDeviceMArcguide& rst, PlnrDevOMDeviceMArcguide** rec = NULL, const ubigint refPlnrMDevice = 0, const ubigint x1RefPlnrMDevice = 0, const uint ixPlnrVLop = 0, const ubigint pr1RefM = 0);
	virtual void insertRst(ListPlnrDevOMDeviceMArcguide& rst, bool transact = false);
	virtual void updateRec(PlnrDevOMDeviceMArcguide* rec);
	virtual void updateRst(ListPlnrDevOMDeviceMArcguide& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, PlnrDevOMDeviceMArcguide** rec);
	virtual ubigint loadRstByDevDv2(ubigint refPlnrMDevice, ubigint x1RefPlnrMDevice, const bool append, ListPlnrDevOMDeviceMArcguide& rst);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListPlnrDevOMDeviceMArcguide& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrDevOMDeviceMArcguide: C++ wrapper for table TblPlnrDevOMDeviceMArcguide (MySQL database)
  */
class MyTblPlnrDevOMDeviceMArcguide : public TblPlnrDevOMDeviceMArcguide, public MyTable {

public:
	MyTblPlnrDevOMDeviceMArcguide();
	~MyTblPlnrDevOMDeviceMArcguide();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrDevOMDeviceMArcguide** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrDevOMDeviceMArcguide& rst);

	void insertRec(PlnrDevOMDeviceMArcguide* rec);
	void insertRst(ListPlnrDevOMDeviceMArcguide& rst, bool transact = false);
	void updateRec(PlnrDevOMDeviceMArcguide* rec);
	void updateRst(ListPlnrDevOMDeviceMArcguide& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrDevOMDeviceMArcguide** rec);
	ubigint loadRstByDevDv2(ubigint refPlnrMDevice, ubigint x1RefPlnrMDevice, const bool append, ListPlnrDevOMDeviceMArcguide& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrDevOMDeviceMArcguide: C++ wrapper for table TblPlnrDevOMDeviceMArcguide (PgSQL database)
  */
class PgTblPlnrDevOMDeviceMArcguide : public TblPlnrDevOMDeviceMArcguide, public PgTable {

public:
	PgTblPlnrDevOMDeviceMArcguide();
	~PgTblPlnrDevOMDeviceMArcguide();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrDevOMDeviceMArcguide** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrDevOMDeviceMArcguide& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrDevOMDeviceMArcguide** rec);
// IP pgLoadRstByStmt --- BEGIN
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrDevOMDeviceMArcguide& rst);
// IP pgLoadRstByStmt --- END

public:
	bool loadRecBySQL(const string& sqlstr, PlnrDevOMDeviceMArcguide** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrDevOMDeviceMArcguide& rst);

	void insertRec(PlnrDevOMDeviceMArcguide* rec);
	void insertRst(ListPlnrDevOMDeviceMArcguide& rst, bool transact = false);
	void updateRec(PlnrDevOMDeviceMArcguide* rec);
	void updateRst(ListPlnrDevOMDeviceMArcguide& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrDevOMDeviceMArcguide** rec);
	ubigint loadRstByDevDv2(ubigint refPlnrMDevice, ubigint x1RefPlnrMDevice, const bool append, ListPlnrDevOMDeviceMArcguide& rst);
};
// IP pgTbl --- END

#endif

