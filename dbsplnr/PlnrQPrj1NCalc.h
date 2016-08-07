/**
  * \file PlnrQPrj1NCalc.h
  * Dbs and XML wrapper for table TblPlnrQPrj1NCalc (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQPRJ1NCALC_H
#define PLNRQPRJ1NCALC_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQPrj1NCalc: record of TblPlnrQPrj1NCalc
  */
class PlnrQPrj1NCalc {

public:
	PlnrQPrj1NCalc(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	string stubRef;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListPlnrQPrj1NCalc: recordset of TblPlnrQPrj1NCalc
  */
class ListPlnrQPrj1NCalc {

public:
	ListPlnrQPrj1NCalc();
	ListPlnrQPrj1NCalc(const ListPlnrQPrj1NCalc& src);
	~ListPlnrQPrj1NCalc();

	void clear();
	unsigned int size() const;
	void append(PlnrQPrj1NCalc* rec);

	ListPlnrQPrj1NCalc& operator=(const ListPlnrQPrj1NCalc& src);

public:
	vector<PlnrQPrj1NCalc*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblPlnrQPrj1NCalc: C++ wrapper for table TblPlnrQPrj1NCalc
  */
class TblPlnrQPrj1NCalc {

public:
	TblPlnrQPrj1NCalc();
	virtual ~TblPlnrQPrj1NCalc();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrQPrj1NCalc** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQPrj1NCalc& rst);

	virtual void insertRec(PlnrQPrj1NCalc* rec);
	ubigint insertNewRec(PlnrQPrj1NCalc** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	ubigint appendNewRecToRst(ListPlnrQPrj1NCalc& rst, PlnrQPrj1NCalc** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	virtual void insertRst(ListPlnrQPrj1NCalc& rst);
	virtual void updateRec(PlnrQPrj1NCalc* rec);
	virtual void updateRst(ListPlnrQPrj1NCalc& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, PlnrQPrj1NCalc** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQPrj1NCalc& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrQPrj1NCalc: C++ wrapper for table TblPlnrQPrj1NCalc (MySQL database)
  */
class MyTblPlnrQPrj1NCalc : public TblPlnrQPrj1NCalc, public MyTable {

public:
	MyTblPlnrQPrj1NCalc();
	~MyTblPlnrQPrj1NCalc();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQPrj1NCalc** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQPrj1NCalc& rst);

	void insertRec(PlnrQPrj1NCalc* rec);
	void insertRst(ListPlnrQPrj1NCalc& rst);
	void updateRec(PlnrQPrj1NCalc* rec);
	void updateRst(ListPlnrQPrj1NCalc& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQPrj1NCalc** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQPrj1NCalc& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrQPrj1NCalc: C++ wrapper for table TblPlnrQPrj1NCalc (PgSQL database)
  */
class PgTblPlnrQPrj1NCalc : public TblPlnrQPrj1NCalc, public PgTable {

public:
	PgTblPlnrQPrj1NCalc();
	~PgTblPlnrQPrj1NCalc();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrQPrj1NCalc** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrQPrj1NCalc& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrQPrj1NCalc** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrQPrj1NCalc& rst);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQPrj1NCalc** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQPrj1NCalc& rst);

	void insertRec(PlnrQPrj1NCalc* rec);
	void insertRst(ListPlnrQPrj1NCalc& rst);
	void updateRec(PlnrQPrj1NCalc* rec);
	void updateRst(ListPlnrQPrj1NCalc& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQPrj1NCalc** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQPrj1NCalc& rst);
};
// IP pgTbl --- END

#endif

