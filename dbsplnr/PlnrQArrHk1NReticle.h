/**
  * \file PlnrQArrHk1NReticle.h
  * Dbs and XML wrapper for table TblPlnrQArrHk1NReticle (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQARRHK1NRETICLE_H
#define PLNRQARRHK1NRETICLE_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQArrHk1NReticle: record of TblPlnrQArrHk1NReticle
  */
class PlnrQArrHk1NReticle {

public:
	PlnrQArrHk1NReticle(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");

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
  * ListPlnrQArrHk1NReticle: recordset of TblPlnrQArrHk1NReticle
  */
class ListPlnrQArrHk1NReticle {

public:
	ListPlnrQArrHk1NReticle();
	ListPlnrQArrHk1NReticle(const ListPlnrQArrHk1NReticle& src);
	~ListPlnrQArrHk1NReticle();

	void clear();
	unsigned int size() const;
	void append(PlnrQArrHk1NReticle* rec);

	ListPlnrQArrHk1NReticle& operator=(const ListPlnrQArrHk1NReticle& src);

public:
	vector<PlnrQArrHk1NReticle*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblPlnrQArrHk1NReticle: C++ wrapper for table TblPlnrQArrHk1NReticle
  */
class TblPlnrQArrHk1NReticle {

public:
	TblPlnrQArrHk1NReticle();
	virtual ~TblPlnrQArrHk1NReticle();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrQArrHk1NReticle** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQArrHk1NReticle& rst);

	virtual void insertRec(PlnrQArrHk1NReticle* rec);
	ubigint insertNewRec(PlnrQArrHk1NReticle** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	ubigint appendNewRecToRst(ListPlnrQArrHk1NReticle& rst, PlnrQArrHk1NReticle** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	virtual void insertRst(ListPlnrQArrHk1NReticle& rst);
	virtual void updateRec(PlnrQArrHk1NReticle* rec);
	virtual void updateRst(ListPlnrQArrHk1NReticle& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, PlnrQArrHk1NReticle** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQArrHk1NReticle& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrQArrHk1NReticle: C++ wrapper for table TblPlnrQArrHk1NReticle (MySQL database)
  */
class MyTblPlnrQArrHk1NReticle : public TblPlnrQArrHk1NReticle, public MyTable {

public:
	MyTblPlnrQArrHk1NReticle();
	~MyTblPlnrQArrHk1NReticle();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQArrHk1NReticle** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQArrHk1NReticle& rst);

	void insertRec(PlnrQArrHk1NReticle* rec);
	void insertRst(ListPlnrQArrHk1NReticle& rst);
	void updateRec(PlnrQArrHk1NReticle* rec);
	void updateRst(ListPlnrQArrHk1NReticle& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQArrHk1NReticle** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQArrHk1NReticle& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrQArrHk1NReticle: C++ wrapper for table TblPlnrQArrHk1NReticle (PgSQL database)
  */
class PgTblPlnrQArrHk1NReticle : public TblPlnrQArrHk1NReticle, public PgTable {

public:
	PgTblPlnrQArrHk1NReticle();
	~PgTblPlnrQArrHk1NReticle();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrQArrHk1NReticle** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrQArrHk1NReticle& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrQArrHk1NReticle** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrQArrHk1NReticle& rst);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQArrHk1NReticle** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQArrHk1NReticle& rst);

	void insertRec(PlnrQArrHk1NReticle* rec);
	void insertRst(ListPlnrQArrHk1NReticle& rst);
	void updateRec(PlnrQArrHk1NReticle* rec);
	void updateRst(ListPlnrQArrHk1NReticle& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQArrHk1NReticle** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQArrHk1NReticle& rst);
};
// IP pgTbl --- END

#endif

