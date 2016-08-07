/**
  * \file PlnrQLyr1NReticle.h
  * Dbs and XML wrapper for table TblPlnrQLyr1NReticle (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQLYR1NRETICLE_H
#define PLNRQLYR1NRETICLE_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQLyr1NReticle: record of TblPlnrQLyr1NReticle
  */
class PlnrQLyr1NReticle {

public:
	PlnrQLyr1NReticle(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");

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
  * ListPlnrQLyr1NReticle: recordset of TblPlnrQLyr1NReticle
  */
class ListPlnrQLyr1NReticle {

public:
	ListPlnrQLyr1NReticle();
	ListPlnrQLyr1NReticle(const ListPlnrQLyr1NReticle& src);
	~ListPlnrQLyr1NReticle();

	void clear();
	unsigned int size() const;
	void append(PlnrQLyr1NReticle* rec);

	ListPlnrQLyr1NReticle& operator=(const ListPlnrQLyr1NReticle& src);

public:
	vector<PlnrQLyr1NReticle*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblPlnrQLyr1NReticle: C++ wrapper for table TblPlnrQLyr1NReticle
  */
class TblPlnrQLyr1NReticle {

public:
	TblPlnrQLyr1NReticle();
	virtual ~TblPlnrQLyr1NReticle();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrQLyr1NReticle** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQLyr1NReticle& rst);

	virtual void insertRec(PlnrQLyr1NReticle* rec);
	ubigint insertNewRec(PlnrQLyr1NReticle** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	ubigint appendNewRecToRst(ListPlnrQLyr1NReticle& rst, PlnrQLyr1NReticle** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	virtual void insertRst(ListPlnrQLyr1NReticle& rst);
	virtual void updateRec(PlnrQLyr1NReticle* rec);
	virtual void updateRst(ListPlnrQLyr1NReticle& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, PlnrQLyr1NReticle** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQLyr1NReticle& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrQLyr1NReticle: C++ wrapper for table TblPlnrQLyr1NReticle (MySQL database)
  */
class MyTblPlnrQLyr1NReticle : public TblPlnrQLyr1NReticle, public MyTable {

public:
	MyTblPlnrQLyr1NReticle();
	~MyTblPlnrQLyr1NReticle();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQLyr1NReticle** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQLyr1NReticle& rst);

	void insertRec(PlnrQLyr1NReticle* rec);
	void insertRst(ListPlnrQLyr1NReticle& rst);
	void updateRec(PlnrQLyr1NReticle* rec);
	void updateRst(ListPlnrQLyr1NReticle& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQLyr1NReticle** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQLyr1NReticle& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrQLyr1NReticle: C++ wrapper for table TblPlnrQLyr1NReticle (PgSQL database)
  */
class PgTblPlnrQLyr1NReticle : public TblPlnrQLyr1NReticle, public PgTable {

public:
	PgTblPlnrQLyr1NReticle();
	~PgTblPlnrQLyr1NReticle();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrQLyr1NReticle** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrQLyr1NReticle& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrQLyr1NReticle** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrQLyr1NReticle& rst);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQLyr1NReticle** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQLyr1NReticle& rst);

	void insertRec(PlnrQLyr1NReticle* rec);
	void insertRst(ListPlnrQLyr1NReticle& rst);
	void updateRec(PlnrQLyr1NReticle* rec);
	void updateRst(ListPlnrQLyr1NReticle& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQLyr1NReticle** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQLyr1NReticle& rst);
};
// IP pgTbl --- END

#endif

