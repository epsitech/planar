/**
  * \file PlnrQCtpTpl1NCalc.h
  * Dbs and XML wrapper for table TblPlnrQCtpTpl1NCalc (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQCTPTPL1NCALC_H
#define PLNRQCTPTPL1NCALC_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQCtpTpl1NCalc: record of TblPlnrQCtpTpl1NCalc
  */
class PlnrQCtpTpl1NCalc {

public:
	PlnrQCtpTpl1NCalc(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");

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
  * ListPlnrQCtpTpl1NCalc: recordset of TblPlnrQCtpTpl1NCalc
  */
class ListPlnrQCtpTpl1NCalc {

public:
	ListPlnrQCtpTpl1NCalc();
	ListPlnrQCtpTpl1NCalc(const ListPlnrQCtpTpl1NCalc& src);
	~ListPlnrQCtpTpl1NCalc();

	void clear();
	unsigned int size() const;
	void append(PlnrQCtpTpl1NCalc* rec);

	ListPlnrQCtpTpl1NCalc& operator=(const ListPlnrQCtpTpl1NCalc& src);

public:
	vector<PlnrQCtpTpl1NCalc*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblPlnrQCtpTpl1NCalc: C++ wrapper for table TblPlnrQCtpTpl1NCalc
  */
class TblPlnrQCtpTpl1NCalc {

public:
	TblPlnrQCtpTpl1NCalc();
	virtual ~TblPlnrQCtpTpl1NCalc();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrQCtpTpl1NCalc** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQCtpTpl1NCalc& rst);

	virtual void insertRec(PlnrQCtpTpl1NCalc* rec);
	ubigint insertNewRec(PlnrQCtpTpl1NCalc** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	ubigint appendNewRecToRst(ListPlnrQCtpTpl1NCalc& rst, PlnrQCtpTpl1NCalc** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	virtual void insertRst(ListPlnrQCtpTpl1NCalc& rst);
	virtual void updateRec(PlnrQCtpTpl1NCalc* rec);
	virtual void updateRst(ListPlnrQCtpTpl1NCalc& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, PlnrQCtpTpl1NCalc** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQCtpTpl1NCalc& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrQCtpTpl1NCalc: C++ wrapper for table TblPlnrQCtpTpl1NCalc (MySQL database)
  */
class MyTblPlnrQCtpTpl1NCalc : public TblPlnrQCtpTpl1NCalc, public MyTable {

public:
	MyTblPlnrQCtpTpl1NCalc();
	~MyTblPlnrQCtpTpl1NCalc();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQCtpTpl1NCalc** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQCtpTpl1NCalc& rst);

	void insertRec(PlnrQCtpTpl1NCalc* rec);
	void insertRst(ListPlnrQCtpTpl1NCalc& rst);
	void updateRec(PlnrQCtpTpl1NCalc* rec);
	void updateRst(ListPlnrQCtpTpl1NCalc& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQCtpTpl1NCalc** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQCtpTpl1NCalc& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrQCtpTpl1NCalc: C++ wrapper for table TblPlnrQCtpTpl1NCalc (PgSQL database)
  */
class PgTblPlnrQCtpTpl1NCalc : public TblPlnrQCtpTpl1NCalc, public PgTable {

public:
	PgTblPlnrQCtpTpl1NCalc();
	~PgTblPlnrQCtpTpl1NCalc();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrQCtpTpl1NCalc** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrQCtpTpl1NCalc& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrQCtpTpl1NCalc** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrQCtpTpl1NCalc& rst);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQCtpTpl1NCalc** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQCtpTpl1NCalc& rst);

	void insertRec(PlnrQCtpTpl1NCalc* rec);
	void insertRst(ListPlnrQCtpTpl1NCalc& rst);
	void updateRec(PlnrQCtpTpl1NCalc* rec);
	void updateRst(ListPlnrQCtpTpl1NCalc& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQCtpTpl1NCalc** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQCtpTpl1NCalc& rst);
};
// IP pgTbl --- END

#endif

