/**
  * \file PlnrQDsn1NReticle.h
  * Dbs and XML wrapper for table TblPlnrQDsn1NReticle (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQDSN1NRETICLE_H
#define PLNRQDSN1NRETICLE_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQDsn1NReticle: record of TblPlnrQDsn1NReticle
  */
class PlnrQDsn1NReticle {

public:
	PlnrQDsn1NReticle(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");

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
  * ListPlnrQDsn1NReticle: recordset of TblPlnrQDsn1NReticle
  */
class ListPlnrQDsn1NReticle {

public:
	ListPlnrQDsn1NReticle();
	ListPlnrQDsn1NReticle(const ListPlnrQDsn1NReticle& src);
	~ListPlnrQDsn1NReticle();

	void clear();
	unsigned int size() const;
	void append(PlnrQDsn1NReticle* rec);

	ListPlnrQDsn1NReticle& operator=(const ListPlnrQDsn1NReticle& src);

public:
	vector<PlnrQDsn1NReticle*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblPlnrQDsn1NReticle: C++ wrapper for table TblPlnrQDsn1NReticle
  */
class TblPlnrQDsn1NReticle {

public:
	TblPlnrQDsn1NReticle();
	virtual ~TblPlnrQDsn1NReticle();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrQDsn1NReticle** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQDsn1NReticle& rst);

	virtual void insertRec(PlnrQDsn1NReticle* rec);
	ubigint insertNewRec(PlnrQDsn1NReticle** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	ubigint appendNewRecToRst(ListPlnrQDsn1NReticle& rst, PlnrQDsn1NReticle** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	virtual void insertRst(ListPlnrQDsn1NReticle& rst);
	virtual void updateRec(PlnrQDsn1NReticle* rec);
	virtual void updateRst(ListPlnrQDsn1NReticle& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, PlnrQDsn1NReticle** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQDsn1NReticle& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrQDsn1NReticle: C++ wrapper for table TblPlnrQDsn1NReticle (MySQL database)
  */
class MyTblPlnrQDsn1NReticle : public TblPlnrQDsn1NReticle, public MyTable {

public:
	MyTblPlnrQDsn1NReticle();
	~MyTblPlnrQDsn1NReticle();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQDsn1NReticle** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQDsn1NReticle& rst);

	void insertRec(PlnrQDsn1NReticle* rec);
	void insertRst(ListPlnrQDsn1NReticle& rst);
	void updateRec(PlnrQDsn1NReticle* rec);
	void updateRst(ListPlnrQDsn1NReticle& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQDsn1NReticle** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQDsn1NReticle& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrQDsn1NReticle: C++ wrapper for table TblPlnrQDsn1NReticle (PgSQL database)
  */
class PgTblPlnrQDsn1NReticle : public TblPlnrQDsn1NReticle, public PgTable {

public:
	PgTblPlnrQDsn1NReticle();
	~PgTblPlnrQDsn1NReticle();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrQDsn1NReticle** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrQDsn1NReticle& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrQDsn1NReticle** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrQDsn1NReticle& rst);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQDsn1NReticle** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQDsn1NReticle& rst);

	void insertRec(PlnrQDsn1NReticle* rec);
	void insertRst(ListPlnrQDsn1NReticle& rst);
	void updateRec(PlnrQDsn1NReticle* rec);
	void updateRst(ListPlnrQDsn1NReticle& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQDsn1NReticle** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQDsn1NReticle& rst);
};
// IP pgTbl --- END

#endif

