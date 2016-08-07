/**
  * \file PlnrQCtpSup1NCalc.h
  * Dbs and XML wrapper for table TblPlnrQCtpSup1NCalc (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQCTPSUP1NCALC_H
#define PLNRQCTPSUP1NCALC_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQCtpSup1NCalc: record of TblPlnrQCtpSup1NCalc
  */
class PlnrQCtpSup1NCalc {

public:
	PlnrQCtpSup1NCalc(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");

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
  * ListPlnrQCtpSup1NCalc: recordset of TblPlnrQCtpSup1NCalc
  */
class ListPlnrQCtpSup1NCalc {

public:
	ListPlnrQCtpSup1NCalc();
	ListPlnrQCtpSup1NCalc(const ListPlnrQCtpSup1NCalc& src);
	~ListPlnrQCtpSup1NCalc();

	void clear();
	unsigned int size() const;
	void append(PlnrQCtpSup1NCalc* rec);

	ListPlnrQCtpSup1NCalc& operator=(const ListPlnrQCtpSup1NCalc& src);

public:
	vector<PlnrQCtpSup1NCalc*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblPlnrQCtpSup1NCalc: C++ wrapper for table TblPlnrQCtpSup1NCalc
  */
class TblPlnrQCtpSup1NCalc {

public:
	TblPlnrQCtpSup1NCalc();
	virtual ~TblPlnrQCtpSup1NCalc();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrQCtpSup1NCalc** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQCtpSup1NCalc& rst);

	virtual void insertRec(PlnrQCtpSup1NCalc* rec);
	ubigint insertNewRec(PlnrQCtpSup1NCalc** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	ubigint appendNewRecToRst(ListPlnrQCtpSup1NCalc& rst, PlnrQCtpSup1NCalc** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	virtual void insertRst(ListPlnrQCtpSup1NCalc& rst);
	virtual void updateRec(PlnrQCtpSup1NCalc* rec);
	virtual void updateRst(ListPlnrQCtpSup1NCalc& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, PlnrQCtpSup1NCalc** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQCtpSup1NCalc& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrQCtpSup1NCalc: C++ wrapper for table TblPlnrQCtpSup1NCalc (MySQL database)
  */
class MyTblPlnrQCtpSup1NCalc : public TblPlnrQCtpSup1NCalc, public MyTable {

public:
	MyTblPlnrQCtpSup1NCalc();
	~MyTblPlnrQCtpSup1NCalc();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQCtpSup1NCalc** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQCtpSup1NCalc& rst);

	void insertRec(PlnrQCtpSup1NCalc* rec);
	void insertRst(ListPlnrQCtpSup1NCalc& rst);
	void updateRec(PlnrQCtpSup1NCalc* rec);
	void updateRst(ListPlnrQCtpSup1NCalc& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQCtpSup1NCalc** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQCtpSup1NCalc& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrQCtpSup1NCalc: C++ wrapper for table TblPlnrQCtpSup1NCalc (PgSQL database)
  */
class PgTblPlnrQCtpSup1NCalc : public TblPlnrQCtpSup1NCalc, public PgTable {

public:
	PgTblPlnrQCtpSup1NCalc();
	~PgTblPlnrQCtpSup1NCalc();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrQCtpSup1NCalc** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrQCtpSup1NCalc& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrQCtpSup1NCalc** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrQCtpSup1NCalc& rst);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQCtpSup1NCalc** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQCtpSup1NCalc& rst);

	void insertRec(PlnrQCtpSup1NCalc* rec);
	void insertRst(ListPlnrQCtpSup1NCalc& rst);
	void updateRec(PlnrQCtpSup1NCalc* rec);
	void updateRst(ListPlnrQCtpSup1NCalc& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQCtpSup1NCalc** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQCtpSup1NCalc& rst);
};
// IP pgTbl --- END

#endif

