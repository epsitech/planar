/**
  * \file PlnrQMatAPar.h
  * Dbs and XML wrapper for table TblPlnrQMatAPar (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQMATAPAR_H
#define PLNRQMATAPAR_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQMatAPar: record of TblPlnrQMatAPar
  */
class PlnrQMatAPar {

public:
	PlnrQMatAPar(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const ubigint x1RefPlnrMDesign = 0, const string stubX1RefPlnrMDesign = "", const string x2SrefKCat = "", const string titX2SrefKCat = "", const string x3SrefKProp = "", const string titX3SrefKProp = "", const ubigint refPlnrMFile = 0, const string stubRefPlnrMFile = "", const string Val = "", const string Comment = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	ubigint x1RefPlnrMDesign;
	string stubX1RefPlnrMDesign;
	string x2SrefKCat;
	string titX2SrefKCat;
	string x3SrefKProp;
	string titX3SrefKProp;
	ubigint refPlnrMFile;
	string stubRefPlnrMFile;
	string Val;
	string Comment;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListPlnrQMatAPar: recordset of TblPlnrQMatAPar
  */
class ListPlnrQMatAPar {

public:
	ListPlnrQMatAPar();
	ListPlnrQMatAPar(const ListPlnrQMatAPar& src);
	~ListPlnrQMatAPar();

	void clear();
	unsigned int size() const;
	void append(PlnrQMatAPar* rec);

	ListPlnrQMatAPar& operator=(const ListPlnrQMatAPar& src);

public:
	vector<PlnrQMatAPar*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblPlnrQMatAPar: C++ wrapper for table TblPlnrQMatAPar
  */
class TblPlnrQMatAPar {

public:
	TblPlnrQMatAPar();
	virtual ~TblPlnrQMatAPar();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrQMatAPar** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQMatAPar& rst);

	virtual void insertRec(PlnrQMatAPar* rec);
	ubigint insertNewRec(PlnrQMatAPar** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const ubigint x1RefPlnrMDesign = 0, const string stubX1RefPlnrMDesign = "", const string x2SrefKCat = "", const string titX2SrefKCat = "", const string x3SrefKProp = "", const string titX3SrefKProp = "", const ubigint refPlnrMFile = 0, const string stubRefPlnrMFile = "", const string Val = "", const string Comment = "");
	ubigint appendNewRecToRst(ListPlnrQMatAPar& rst, PlnrQMatAPar** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const ubigint x1RefPlnrMDesign = 0, const string stubX1RefPlnrMDesign = "", const string x2SrefKCat = "", const string titX2SrefKCat = "", const string x3SrefKProp = "", const string titX3SrefKProp = "", const ubigint refPlnrMFile = 0, const string stubRefPlnrMFile = "", const string Val = "", const string Comment = "");
	virtual void insertRst(ListPlnrQMatAPar& rst);
	virtual void updateRec(PlnrQMatAPar* rec);
	virtual void updateRst(ListPlnrQMatAPar& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, PlnrQMatAPar** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQMatAPar& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrQMatAPar: C++ wrapper for table TblPlnrQMatAPar (MySQL database)
  */
class MyTblPlnrQMatAPar : public TblPlnrQMatAPar, public MyTable {

public:
	MyTblPlnrQMatAPar();
	~MyTblPlnrQMatAPar();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQMatAPar** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQMatAPar& rst);

	void insertRec(PlnrQMatAPar* rec);
	void insertRst(ListPlnrQMatAPar& rst);
	void updateRec(PlnrQMatAPar* rec);
	void updateRst(ListPlnrQMatAPar& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQMatAPar** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQMatAPar& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrQMatAPar: C++ wrapper for table TblPlnrQMatAPar (PgSQL database)
  */
class PgTblPlnrQMatAPar : public TblPlnrQMatAPar, public PgTable {

public:
	PgTblPlnrQMatAPar();
	~PgTblPlnrQMatAPar();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrQMatAPar** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrQMatAPar& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrQMatAPar** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrQMatAPar& rst);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQMatAPar** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQMatAPar& rst);

	void insertRec(PlnrQMatAPar* rec);
	void insertRst(ListPlnrQMatAPar& rst);
	void updateRec(PlnrQMatAPar* rec);
	void updateRst(ListPlnrQMatAPar& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQMatAPar** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQMatAPar& rst);
};
// IP pgTbl --- END

#endif

