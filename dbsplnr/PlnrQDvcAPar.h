/**
  * \file PlnrQDvcAPar.h
  * Dbs and XML wrapper for table TblPlnrQDvcAPar (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQDVCAPAR_H
#define PLNRQDVCAPAR_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQDvcAPar: record of TblPlnrQDvcAPar
  */
class PlnrQDvcAPar {

public:
	PlnrQDvcAPar(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const ubigint x1RefPlnrMDesign = 0, const string stubX1RefPlnrMDesign = "", const string x2SrefKKey = "", const string titX2SrefKKey = "", const ubigint refPlnrMFile = 0, const string stubRefPlnrMFile = "", const string Val = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	ubigint x1RefPlnrMDesign;
	string stubX1RefPlnrMDesign;
	string x2SrefKKey;
	string titX2SrefKKey;
	ubigint refPlnrMFile;
	string stubRefPlnrMFile;
	string Val;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListPlnrQDvcAPar: recordset of TblPlnrQDvcAPar
  */
class ListPlnrQDvcAPar {

public:
	ListPlnrQDvcAPar();
	ListPlnrQDvcAPar(const ListPlnrQDvcAPar& src);
	~ListPlnrQDvcAPar();

	void clear();
	unsigned int size() const;
	void append(PlnrQDvcAPar* rec);

	ListPlnrQDvcAPar& operator=(const ListPlnrQDvcAPar& src);

public:
	vector<PlnrQDvcAPar*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblPlnrQDvcAPar: C++ wrapper for table TblPlnrQDvcAPar
  */
class TblPlnrQDvcAPar {

public:
	TblPlnrQDvcAPar();
	virtual ~TblPlnrQDvcAPar();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrQDvcAPar** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQDvcAPar& rst);

	virtual void insertRec(PlnrQDvcAPar* rec);
	ubigint insertNewRec(PlnrQDvcAPar** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const ubigint x1RefPlnrMDesign = 0, const string stubX1RefPlnrMDesign = "", const string x2SrefKKey = "", const string titX2SrefKKey = "", const ubigint refPlnrMFile = 0, const string stubRefPlnrMFile = "", const string Val = "");
	ubigint appendNewRecToRst(ListPlnrQDvcAPar& rst, PlnrQDvcAPar** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const ubigint x1RefPlnrMDesign = 0, const string stubX1RefPlnrMDesign = "", const string x2SrefKKey = "", const string titX2SrefKKey = "", const ubigint refPlnrMFile = 0, const string stubRefPlnrMFile = "", const string Val = "");
	virtual void insertRst(ListPlnrQDvcAPar& rst);
	virtual void updateRec(PlnrQDvcAPar* rec);
	virtual void updateRst(ListPlnrQDvcAPar& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, PlnrQDvcAPar** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQDvcAPar& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrQDvcAPar: C++ wrapper for table TblPlnrQDvcAPar (MySQL database)
  */
class MyTblPlnrQDvcAPar : public TblPlnrQDvcAPar, public MyTable {

public:
	MyTblPlnrQDvcAPar();
	~MyTblPlnrQDvcAPar();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQDvcAPar** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQDvcAPar& rst);

	void insertRec(PlnrQDvcAPar* rec);
	void insertRst(ListPlnrQDvcAPar& rst);
	void updateRec(PlnrQDvcAPar* rec);
	void updateRst(ListPlnrQDvcAPar& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQDvcAPar** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQDvcAPar& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrQDvcAPar: C++ wrapper for table TblPlnrQDvcAPar (PgSQL database)
  */
class PgTblPlnrQDvcAPar : public TblPlnrQDvcAPar, public PgTable {

public:
	PgTblPlnrQDvcAPar();
	~PgTblPlnrQDvcAPar();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrQDvcAPar** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrQDvcAPar& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrQDvcAPar** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrQDvcAPar& rst);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQDvcAPar** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQDvcAPar& rst);

	void insertRec(PlnrQDvcAPar* rec);
	void insertRst(ListPlnrQDvcAPar& rst);
	void updateRec(PlnrQDvcAPar* rec);
	void updateRst(ListPlnrQDvcAPar& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQDvcAPar** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQDvcAPar& rst);
};
// IP pgTbl --- END

#endif

