/**
  * \file PlnrQClcSup1NCalc.h
  * Dbs and XML wrapper for table TblPlnrQClcSup1NCalc (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQCLCSUP1NCALC_H
#define PLNRQCLCSUP1NCALC_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQClcSup1NCalc: record of TblPlnrQClcSup1NCalc
  */
class PlnrQClcSup1NCalc {

public:
	PlnrQClcSup1NCalc(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");

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
  * ListPlnrQClcSup1NCalc: recordset of TblPlnrQClcSup1NCalc
  */
class ListPlnrQClcSup1NCalc {

public:
	ListPlnrQClcSup1NCalc();
	ListPlnrQClcSup1NCalc(const ListPlnrQClcSup1NCalc& src);
	~ListPlnrQClcSup1NCalc();

	void clear();
	unsigned int size() const;
	void append(PlnrQClcSup1NCalc* rec);

	ListPlnrQClcSup1NCalc& operator=(const ListPlnrQClcSup1NCalc& src);

public:
	vector<PlnrQClcSup1NCalc*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblPlnrQClcSup1NCalc: C++ wrapper for table TblPlnrQClcSup1NCalc
  */
class TblPlnrQClcSup1NCalc {

public:
	TblPlnrQClcSup1NCalc();
	virtual ~TblPlnrQClcSup1NCalc();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrQClcSup1NCalc** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQClcSup1NCalc& rst);

	virtual void insertRec(PlnrQClcSup1NCalc* rec);
	ubigint insertNewRec(PlnrQClcSup1NCalc** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	ubigint appendNewRecToRst(ListPlnrQClcSup1NCalc& rst, PlnrQClcSup1NCalc** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	virtual void insertRst(ListPlnrQClcSup1NCalc& rst);
	virtual void updateRec(PlnrQClcSup1NCalc* rec);
	virtual void updateRst(ListPlnrQClcSup1NCalc& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, PlnrQClcSup1NCalc** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQClcSup1NCalc& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrQClcSup1NCalc: C++ wrapper for table TblPlnrQClcSup1NCalc (MySQL database)
  */
class MyTblPlnrQClcSup1NCalc : public TblPlnrQClcSup1NCalc, public MyTable {

public:
	MyTblPlnrQClcSup1NCalc();
	~MyTblPlnrQClcSup1NCalc();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQClcSup1NCalc** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQClcSup1NCalc& rst);

	void insertRec(PlnrQClcSup1NCalc* rec);
	void insertRst(ListPlnrQClcSup1NCalc& rst);
	void updateRec(PlnrQClcSup1NCalc* rec);
	void updateRst(ListPlnrQClcSup1NCalc& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQClcSup1NCalc** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQClcSup1NCalc& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrQClcSup1NCalc: C++ wrapper for table TblPlnrQClcSup1NCalc (PgSQL database)
  */
class PgTblPlnrQClcSup1NCalc : public TblPlnrQClcSup1NCalc, public PgTable {

public:
	PgTblPlnrQClcSup1NCalc();
	~PgTblPlnrQClcSup1NCalc();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrQClcSup1NCalc** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrQClcSup1NCalc& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrQClcSup1NCalc** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrQClcSup1NCalc& rst);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQClcSup1NCalc** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQClcSup1NCalc& rst);

	void insertRec(PlnrQClcSup1NCalc* rec);
	void insertRst(ListPlnrQClcSup1NCalc& rst);
	void updateRec(PlnrQClcSup1NCalc* rec);
	void updateRst(ListPlnrQClcSup1NCalc& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQClcSup1NCalc** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQClcSup1NCalc& rst);
};
// IP pgTbl --- END

#endif

