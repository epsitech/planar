/**
  * \file PlnrQDomMNCalc.h
  * Dbs and XML wrapper for table TblPlnrQDomMNCalc (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQDOMMNCALC_H
#define PLNRQDOMMNCALC_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQDomMNCalc: record of TblPlnrQDomMNCalc
  */
class PlnrQDomMNCalc {

public:
	PlnrQDomMNCalc(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const string srefPlnrKCalcdomprp = "", const string titSrefPlnrKCalcdomprp = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint mref;
	string stubMref;
	ubigint ref;
	string srefPlnrKCalcdomprp;
	string titSrefPlnrKCalcdomprp;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListPlnrQDomMNCalc: recordset of TblPlnrQDomMNCalc
  */
class ListPlnrQDomMNCalc {

public:
	ListPlnrQDomMNCalc();
	ListPlnrQDomMNCalc(const ListPlnrQDomMNCalc& src);
	~ListPlnrQDomMNCalc();

	void clear();
	unsigned int size() const;
	void append(PlnrQDomMNCalc* rec);

	ListPlnrQDomMNCalc& operator=(const ListPlnrQDomMNCalc& src);

public:
	vector<PlnrQDomMNCalc*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblPlnrQDomMNCalc: C++ wrapper for table TblPlnrQDomMNCalc
  */
class TblPlnrQDomMNCalc {

public:
	TblPlnrQDomMNCalc();
	virtual ~TblPlnrQDomMNCalc();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrQDomMNCalc** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQDomMNCalc& rst);

	virtual void insertRec(PlnrQDomMNCalc* rec);
	ubigint insertNewRec(PlnrQDomMNCalc** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const string srefPlnrKCalcdomprp = "", const string titSrefPlnrKCalcdomprp = "");
	ubigint appendNewRecToRst(ListPlnrQDomMNCalc& rst, PlnrQDomMNCalc** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const string srefPlnrKCalcdomprp = "", const string titSrefPlnrKCalcdomprp = "");
	virtual void insertRst(ListPlnrQDomMNCalc& rst);
	virtual void updateRec(PlnrQDomMNCalc* rec);
	virtual void updateRst(ListPlnrQDomMNCalc& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, PlnrQDomMNCalc** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQDomMNCalc& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrQDomMNCalc: C++ wrapper for table TblPlnrQDomMNCalc (MySQL database)
  */
class MyTblPlnrQDomMNCalc : public TblPlnrQDomMNCalc, public MyTable {

public:
	MyTblPlnrQDomMNCalc();
	~MyTblPlnrQDomMNCalc();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQDomMNCalc** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQDomMNCalc& rst);

	void insertRec(PlnrQDomMNCalc* rec);
	void insertRst(ListPlnrQDomMNCalc& rst);
	void updateRec(PlnrQDomMNCalc* rec);
	void updateRst(ListPlnrQDomMNCalc& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQDomMNCalc** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQDomMNCalc& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrQDomMNCalc: C++ wrapper for table TblPlnrQDomMNCalc (PgSQL database)
  */
class PgTblPlnrQDomMNCalc : public TblPlnrQDomMNCalc, public PgTable {

public:
	PgTblPlnrQDomMNCalc();
	~PgTblPlnrQDomMNCalc();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrQDomMNCalc** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrQDomMNCalc& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrQDomMNCalc** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrQDomMNCalc& rst);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQDomMNCalc** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQDomMNCalc& rst);

	void insertRec(PlnrQDomMNCalc* rec);
	void insertRst(ListPlnrQDomMNCalc& rst);
	void updateRec(PlnrQDomMNCalc* rec);
	void updateRst(ListPlnrQDomMNCalc& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQDomMNCalc** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQDomMNCalc& rst);
};
// IP pgTbl --- END

#endif

