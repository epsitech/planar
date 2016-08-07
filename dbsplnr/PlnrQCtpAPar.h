/**
  * \file PlnrQCtpAPar.h
  * Dbs and XML wrapper for table TblPlnrQCtpAPar (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQCTPAPAR_H
#define PLNRQCTPAPAR_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQCtpAPar: record of TblPlnrQCtpAPar
  */
class PlnrQCtpAPar {

public:
	PlnrQCtpAPar(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const ubigint x1RefPlnrMCalcitem = 0, const string x2SrefKCat = "", const string titX2SrefKCat = "", const string x3SrefKProp = "", const string titX3SrefKProp = "", const string Val = "");

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
  * ListPlnrQCtpAPar: recordset of TblPlnrQCtpAPar
  */
class ListPlnrQCtpAPar {

public:
	ListPlnrQCtpAPar();
	ListPlnrQCtpAPar(const ListPlnrQCtpAPar& src);
	~ListPlnrQCtpAPar();

	void clear();
	unsigned int size() const;
	void append(PlnrQCtpAPar* rec);

	ListPlnrQCtpAPar& operator=(const ListPlnrQCtpAPar& src);

public:
	vector<PlnrQCtpAPar*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblPlnrQCtpAPar: C++ wrapper for table TblPlnrQCtpAPar
  */
class TblPlnrQCtpAPar {

public:
	TblPlnrQCtpAPar();
	virtual ~TblPlnrQCtpAPar();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrQCtpAPar** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQCtpAPar& rst);

	virtual void insertRec(PlnrQCtpAPar* rec);
	ubigint insertNewRec(PlnrQCtpAPar** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const ubigint x1RefPlnrMCalcitem = 0, const string x2SrefKCat = "", const string titX2SrefKCat = "", const string x3SrefKProp = "", const string titX3SrefKProp = "", const string Val = "");
	ubigint appendNewRecToRst(ListPlnrQCtpAPar& rst, PlnrQCtpAPar** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const ubigint x1RefPlnrMCalcitem = 0, const string x2SrefKCat = "", const string titX2SrefKCat = "", const string x3SrefKProp = "", const string titX3SrefKProp = "", const string Val = "");
	virtual void insertRst(ListPlnrQCtpAPar& rst);
	virtual void updateRec(PlnrQCtpAPar* rec);
	virtual void updateRst(ListPlnrQCtpAPar& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, PlnrQCtpAPar** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQCtpAPar& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrQCtpAPar: C++ wrapper for table TblPlnrQCtpAPar (MySQL database)
  */
class MyTblPlnrQCtpAPar : public TblPlnrQCtpAPar, public MyTable {

public:
	MyTblPlnrQCtpAPar();
	~MyTblPlnrQCtpAPar();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQCtpAPar** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQCtpAPar& rst);

	void insertRec(PlnrQCtpAPar* rec);
	void insertRst(ListPlnrQCtpAPar& rst);
	void updateRec(PlnrQCtpAPar* rec);
	void updateRst(ListPlnrQCtpAPar& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQCtpAPar** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQCtpAPar& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrQCtpAPar: C++ wrapper for table TblPlnrQCtpAPar (PgSQL database)
  */
class PgTblPlnrQCtpAPar : public TblPlnrQCtpAPar, public PgTable {

public:
	PgTblPlnrQCtpAPar();
	~PgTblPlnrQCtpAPar();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrQCtpAPar** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrQCtpAPar& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrQCtpAPar** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrQCtpAPar& rst);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQCtpAPar** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQCtpAPar& rst);

	void insertRec(PlnrQCtpAPar* rec);
	void insertRst(ListPlnrQCtpAPar& rst);
	void updateRec(PlnrQCtpAPar* rec);
	void updateRst(ListPlnrQCtpAPar& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQCtpAPar** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQCtpAPar& rst);
};
// IP pgTbl --- END

#endif

