/**
  * \file PlnrDevOMDeviceMLineguide.h
  * database access for table TblPlnrDevOMDeviceMLineguide (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRDEVOMDEVICEMLINEGUIDE_H
#define PLNRDEVOMDEVICEMLINEGUIDE_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * PlnrDevOMDeviceMLineguide: record of TblPlnrDevOMDeviceMLineguide
  */
class PlnrDevOMDeviceMLineguide {

public:
	PlnrDevOMDeviceMLineguide(const ubigint ref = 0, const ubigint refPlnrMDevice = 0, const ubigint x1RefPlnrMDevice = 0, const uint ixPlnrVLop = 0, const ubigint pr1RefM = 0);

public:
	ubigint ref;
	ubigint refPlnrMDevice;
	ubigint x1RefPlnrMDevice;
	uint ixPlnrVLop;
	ubigint pr1RefM;

public:
	bool operator==(const PlnrDevOMDeviceMLineguide& comp);
	bool operator!=(const PlnrDevOMDeviceMLineguide& comp);
};

/**
  * ListPlnrDevOMDeviceMLineguide: recordset of TblPlnrDevOMDeviceMLineguide
  */
class ListPlnrDevOMDeviceMLineguide {

public:
	ListPlnrDevOMDeviceMLineguide();
	ListPlnrDevOMDeviceMLineguide(const ListPlnrDevOMDeviceMLineguide& src);
	~ListPlnrDevOMDeviceMLineguide();

	void clear();
	unsigned int size() const;
	void append(PlnrDevOMDeviceMLineguide* rec);

	PlnrDevOMDeviceMLineguide* operator[](const uint ix);
	ListPlnrDevOMDeviceMLineguide& operator=(const ListPlnrDevOMDeviceMLineguide& src);
	bool operator==(const ListPlnrDevOMDeviceMLineguide& comp);
	bool operator!=(const ListPlnrDevOMDeviceMLineguide& comp);

public:
	vector<PlnrDevOMDeviceMLineguide*> nodes;
};

/**
  * TblPlnrDevOMDeviceMLineguide: C++ wrapper for table TblPlnrDevOMDeviceMLineguide
  */
class TblPlnrDevOMDeviceMLineguide {

public:
	TblPlnrDevOMDeviceMLineguide();
	virtual ~TblPlnrDevOMDeviceMLineguide();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrDevOMDeviceMLineguide** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrDevOMDeviceMLineguide& rst);

	virtual void insertRec(PlnrDevOMDeviceMLineguide* rec);
	ubigint insertNewRec(PlnrDevOMDeviceMLineguide** rec = NULL, const ubigint refPlnrMDevice = 0, const ubigint x1RefPlnrMDevice = 0, const uint ixPlnrVLop = 0, const ubigint pr1RefM = 0);
	ubigint appendNewRecToRst(ListPlnrDevOMDeviceMLineguide& rst, PlnrDevOMDeviceMLineguide** rec = NULL, const ubigint refPlnrMDevice = 0, const ubigint x1RefPlnrMDevice = 0, const uint ixPlnrVLop = 0, const ubigint pr1RefM = 0);
	virtual void insertRst(ListPlnrDevOMDeviceMLineguide& rst, bool transact = false);
	virtual void updateRec(PlnrDevOMDeviceMLineguide* rec);
	virtual void updateRst(ListPlnrDevOMDeviceMLineguide& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, PlnrDevOMDeviceMLineguide** rec);
	virtual ubigint loadRstByDevDv2(ubigint refPlnrMDevice, ubigint x1RefPlnrMDevice, const bool append, ListPlnrDevOMDeviceMLineguide& rst);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListPlnrDevOMDeviceMLineguide& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrDevOMDeviceMLineguide: C++ wrapper for table TblPlnrDevOMDeviceMLineguide (MySQL database)
  */
class MyTblPlnrDevOMDeviceMLineguide : public TblPlnrDevOMDeviceMLineguide, public MyTable {

public:
	MyTblPlnrDevOMDeviceMLineguide();
	~MyTblPlnrDevOMDeviceMLineguide();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrDevOMDeviceMLineguide** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrDevOMDeviceMLineguide& rst);

	void insertRec(PlnrDevOMDeviceMLineguide* rec);
	void insertRst(ListPlnrDevOMDeviceMLineguide& rst, bool transact = false);
	void updateRec(PlnrDevOMDeviceMLineguide* rec);
	void updateRst(ListPlnrDevOMDeviceMLineguide& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrDevOMDeviceMLineguide** rec);
	ubigint loadRstByDevDv2(ubigint refPlnrMDevice, ubigint x1RefPlnrMDevice, const bool append, ListPlnrDevOMDeviceMLineguide& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrDevOMDeviceMLineguide: C++ wrapper for table TblPlnrDevOMDeviceMLineguide (PgSQL database)
  */
class PgTblPlnrDevOMDeviceMLineguide : public TblPlnrDevOMDeviceMLineguide, public PgTable {

public:
	PgTblPlnrDevOMDeviceMLineguide();
	~PgTblPlnrDevOMDeviceMLineguide();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrDevOMDeviceMLineguide** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrDevOMDeviceMLineguide& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrDevOMDeviceMLineguide** rec);
// IP pgLoadRstByStmt --- BEGIN
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrDevOMDeviceMLineguide& rst);
// IP pgLoadRstByStmt --- END

public:
	bool loadRecBySQL(const string& sqlstr, PlnrDevOMDeviceMLineguide** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrDevOMDeviceMLineguide& rst);

	void insertRec(PlnrDevOMDeviceMLineguide* rec);
	void insertRst(ListPlnrDevOMDeviceMLineguide& rst, bool transact = false);
	void updateRec(PlnrDevOMDeviceMLineguide* rec);
	void updateRst(ListPlnrDevOMDeviceMLineguide& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrDevOMDeviceMLineguide** rec);
	ubigint loadRstByDevDv2(ubigint refPlnrMDevice, ubigint x1RefPlnrMDevice, const bool append, ListPlnrDevOMDeviceMLineguide& rst);
};
// IP pgTbl --- END

#endif

