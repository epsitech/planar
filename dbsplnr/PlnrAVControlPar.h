/**
  * \file PlnrAVControlPar.h
  * database access for table TblPlnrAVControlPar (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRAVCONTROLPAR_H
#define PLNRAVCONTROLPAR_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * PlnrAVControlPar: record of TblPlnrAVControlPar
  */
class PlnrAVControlPar {

public:
	PlnrAVControlPar(const ubigint ref = 0, const uint ixPlnrVControl = 0, const ubigint x1RefPlnrMUser = 0, const uint x2IxPlnrVLocale = 0, const string Par = "", const string Val = "");

public:
	ubigint ref;
	uint ixPlnrVControl;
	ubigint x1RefPlnrMUser;
	uint x2IxPlnrVLocale;
	string Par;
	string Val;

public:
	bool operator==(const PlnrAVControlPar& comp);
	bool operator!=(const PlnrAVControlPar& comp);
};

/**
  * ListPlnrAVControlPar: recordset of TblPlnrAVControlPar
  */
class ListPlnrAVControlPar {

public:
	ListPlnrAVControlPar();
	ListPlnrAVControlPar(const ListPlnrAVControlPar& src);
	~ListPlnrAVControlPar();

	void clear();
	unsigned int size() const;
	void append(PlnrAVControlPar* rec);

	PlnrAVControlPar* operator[](const uint ix);
	ListPlnrAVControlPar& operator=(const ListPlnrAVControlPar& src);
	bool operator==(const ListPlnrAVControlPar& comp);
	bool operator!=(const ListPlnrAVControlPar& comp);

public:
	vector<PlnrAVControlPar*> nodes;
};

/**
  * TblPlnrAVControlPar: C++ wrapper for table TblPlnrAVControlPar
  */
class TblPlnrAVControlPar {

public:
	TblPlnrAVControlPar();
	virtual ~TblPlnrAVControlPar();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrAVControlPar** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrAVControlPar& rst);

	virtual void insertRec(PlnrAVControlPar* rec);
	ubigint insertNewRec(PlnrAVControlPar** rec = NULL, const uint ixPlnrVControl = 0, const ubigint x1RefPlnrMUser = 0, const uint x2IxPlnrVLocale = 0, const string Par = "", const string Val = "");
	ubigint appendNewRecToRst(ListPlnrAVControlPar& rst, PlnrAVControlPar** rec = NULL, const uint ixPlnrVControl = 0, const ubigint x1RefPlnrMUser = 0, const uint x2IxPlnrVLocale = 0, const string Par = "", const string Val = "");
	virtual void insertRst(ListPlnrAVControlPar& rst, bool transact = false);
	virtual void updateRec(PlnrAVControlPar* rec);
	virtual void updateRst(ListPlnrAVControlPar& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, PlnrAVControlPar** rec);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListPlnrAVControlPar& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrAVControlPar: C++ wrapper for table TblPlnrAVControlPar (MySQL database)
  */
class MyTblPlnrAVControlPar : public TblPlnrAVControlPar, public MyTable {

public:
	MyTblPlnrAVControlPar();
	~MyTblPlnrAVControlPar();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrAVControlPar** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrAVControlPar& rst);

	void insertRec(PlnrAVControlPar* rec);
	void insertRst(ListPlnrAVControlPar& rst, bool transact = false);
	void updateRec(PlnrAVControlPar* rec);
	void updateRst(ListPlnrAVControlPar& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrAVControlPar** rec);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrAVControlPar: C++ wrapper for table TblPlnrAVControlPar (PgSQL database)
  */
class PgTblPlnrAVControlPar : public TblPlnrAVControlPar, public PgTable {

public:
	PgTblPlnrAVControlPar();
	~PgTblPlnrAVControlPar();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrAVControlPar** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrAVControlPar& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrAVControlPar** rec);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrAVControlPar** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrAVControlPar& rst);

	void insertRec(PlnrAVControlPar* rec);
	void insertRst(ListPlnrAVControlPar& rst, bool transact = false);
	void updateRec(PlnrAVControlPar* rec);
	void updateRst(ListPlnrAVControlPar& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrAVControlPar** rec);
};
// IP pgTbl --- END

#endif

