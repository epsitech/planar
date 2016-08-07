/**
  * \file PlnrQCliAAMCalcPar.h
  * Dbs and XML wrapper for table TblPlnrQCliAAMCalcPar (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQCLIAAMCALCPAR_H
#define PLNRQCLIAAMCALCPAR_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQCliAAMCalcPar: record of TblPlnrQCliAAMCalcPar
  */
class PlnrQCliAAMCalcPar {

public:
	PlnrQCliAAMCalcPar(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string x2SrefKCat = "", const string titX2SrefKCat = "", const string x3SrefKProp = "", const string titX3SrefKProp = "", const string Val = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	string x2SrefKCat;
	string titX2SrefKCat;
	string x3SrefKProp;
	string titX3SrefKProp;
	string Val;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListPlnrQCliAAMCalcPar: recordset of TblPlnrQCliAAMCalcPar
  */
class ListPlnrQCliAAMCalcPar {

public:
	ListPlnrQCliAAMCalcPar();
	ListPlnrQCliAAMCalcPar(const ListPlnrQCliAAMCalcPar& src);
	~ListPlnrQCliAAMCalcPar();

	void clear();
	unsigned int size() const;
	void append(PlnrQCliAAMCalcPar* rec);

	ListPlnrQCliAAMCalcPar& operator=(const ListPlnrQCliAAMCalcPar& src);

public:
	vector<PlnrQCliAAMCalcPar*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblPlnrQCliAAMCalcPar: C++ wrapper for table TblPlnrQCliAAMCalcPar
  */
class TblPlnrQCliAAMCalcPar {

public:
	TblPlnrQCliAAMCalcPar();
	virtual ~TblPlnrQCliAAMCalcPar();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrQCliAAMCalcPar** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQCliAAMCalcPar& rst);

	virtual void insertRec(PlnrQCliAAMCalcPar* rec);
	ubigint insertNewRec(PlnrQCliAAMCalcPar** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string x2SrefKCat = "", const string titX2SrefKCat = "", const string x3SrefKProp = "", const string titX3SrefKProp = "", const string Val = "");
	ubigint appendNewRecToRst(ListPlnrQCliAAMCalcPar& rst, PlnrQCliAAMCalcPar** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string x2SrefKCat = "", const string titX2SrefKCat = "", const string x3SrefKProp = "", const string titX3SrefKProp = "", const string Val = "");
	virtual void insertRst(ListPlnrQCliAAMCalcPar& rst);
	virtual void updateRec(PlnrQCliAAMCalcPar* rec);
	virtual void updateRst(ListPlnrQCliAAMCalcPar& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, PlnrQCliAAMCalcPar** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQCliAAMCalcPar& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrQCliAAMCalcPar: C++ wrapper for table TblPlnrQCliAAMCalcPar (MySQL database)
  */
class MyTblPlnrQCliAAMCalcPar : public TblPlnrQCliAAMCalcPar, public MyTable {

public:
	MyTblPlnrQCliAAMCalcPar();
	~MyTblPlnrQCliAAMCalcPar();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQCliAAMCalcPar** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQCliAAMCalcPar& rst);

	void insertRec(PlnrQCliAAMCalcPar* rec);
	void insertRst(ListPlnrQCliAAMCalcPar& rst);
	void updateRec(PlnrQCliAAMCalcPar* rec);
	void updateRst(ListPlnrQCliAAMCalcPar& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQCliAAMCalcPar** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQCliAAMCalcPar& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrQCliAAMCalcPar: C++ wrapper for table TblPlnrQCliAAMCalcPar (PgSQL database)
  */
class PgTblPlnrQCliAAMCalcPar : public TblPlnrQCliAAMCalcPar, public PgTable {

public:
	PgTblPlnrQCliAAMCalcPar();
	~PgTblPlnrQCliAAMCalcPar();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrQCliAAMCalcPar** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrQCliAAMCalcPar& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrQCliAAMCalcPar** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrQCliAAMCalcPar& rst);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQCliAAMCalcPar** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQCliAAMCalcPar& rst);

	void insertRec(PlnrQCliAAMCalcPar* rec);
	void insertRst(ListPlnrQCliAAMCalcPar& rst);
	void updateRec(PlnrQCliAAMCalcPar* rec);
	void updateRst(ListPlnrQCliAAMCalcPar& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQCliAAMCalcPar** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQCliAAMCalcPar& rst);
};
// IP pgTbl --- END

#endif

