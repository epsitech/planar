/**
  * \file PlnrQClcAPar.h
  * Dbs and XML wrapper for table TblPlnrQClcAPar (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQCLCAPAR_H
#define PLNRQCLCAPAR_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQClcAPar: record of TblPlnrQClcAPar
  */
class PlnrQClcAPar {

public:
	PlnrQClcAPar(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const ubigint x1RefPlnrMCalcitem = 0, const string x2SrefKCat = "", const string titX2SrefKCat = "", const string x3SrefKProp = "", const string titX3SrefKProp = "", const string Val = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	ubigint x1RefPlnrMCalcitem;
	string x2SrefKCat;
	string titX2SrefKCat;
	string x3SrefKProp;
	string titX3SrefKProp;
	string Val;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListPlnrQClcAPar: recordset of TblPlnrQClcAPar
  */
class ListPlnrQClcAPar {

public:
	ListPlnrQClcAPar();
	ListPlnrQClcAPar(const ListPlnrQClcAPar& src);
	~ListPlnrQClcAPar();

	void clear();
	unsigned int size() const;
	void append(PlnrQClcAPar* rec);

	ListPlnrQClcAPar& operator=(const ListPlnrQClcAPar& src);

public:
	vector<PlnrQClcAPar*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblPlnrQClcAPar: C++ wrapper for table TblPlnrQClcAPar
  */
class TblPlnrQClcAPar {

public:
	TblPlnrQClcAPar();
	virtual ~TblPlnrQClcAPar();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrQClcAPar** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQClcAPar& rst);

	virtual void insertRec(PlnrQClcAPar* rec);
	ubigint insertNewRec(PlnrQClcAPar** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const ubigint x1RefPlnrMCalcitem = 0, const string x2SrefKCat = "", const string titX2SrefKCat = "", const string x3SrefKProp = "", const string titX3SrefKProp = "", const string Val = "");
	ubigint appendNewRecToRst(ListPlnrQClcAPar& rst, PlnrQClcAPar** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const ubigint x1RefPlnrMCalcitem = 0, const string x2SrefKCat = "", const string titX2SrefKCat = "", const string x3SrefKProp = "", const string titX3SrefKProp = "", const string Val = "");
	virtual void insertRst(ListPlnrQClcAPar& rst);
	virtual void updateRec(PlnrQClcAPar* rec);
	virtual void updateRst(ListPlnrQClcAPar& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, PlnrQClcAPar** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQClcAPar& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrQClcAPar: C++ wrapper for table TblPlnrQClcAPar (MySQL database)
  */
class MyTblPlnrQClcAPar : public TblPlnrQClcAPar, public MyTable {

public:
	MyTblPlnrQClcAPar();
	~MyTblPlnrQClcAPar();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQClcAPar** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQClcAPar& rst);

	void insertRec(PlnrQClcAPar* rec);
	void insertRst(ListPlnrQClcAPar& rst);
	void updateRec(PlnrQClcAPar* rec);
	void updateRst(ListPlnrQClcAPar& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQClcAPar** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQClcAPar& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrQClcAPar: C++ wrapper for table TblPlnrQClcAPar (PgSQL database)
  */
class PgTblPlnrQClcAPar : public TblPlnrQClcAPar, public PgTable {

public:
	PgTblPlnrQClcAPar();
	~PgTblPlnrQClcAPar();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrQClcAPar** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrQClcAPar& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrQClcAPar** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrQClcAPar& rst);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQClcAPar** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQClcAPar& rst);

	void insertRec(PlnrQClcAPar* rec);
	void insertRst(ListPlnrQClcAPar& rst);
	void updateRec(PlnrQClcAPar* rec);
	void updateRst(ListPlnrQClcAPar& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQClcAPar** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQClcAPar& rst);
};
// IP pgTbl --- END

#endif

