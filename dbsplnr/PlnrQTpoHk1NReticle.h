/**
  * \file PlnrQTpoHk1NReticle.h
  * Dbs and XML wrapper for table TblPlnrQTpoHk1NReticle (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQTPOHK1NRETICLE_H
#define PLNRQTPOHK1NRETICLE_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQTpoHk1NReticle: record of TblPlnrQTpoHk1NReticle
  */
class PlnrQTpoHk1NReticle {

public:
	PlnrQTpoHk1NReticle(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");

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
  * ListPlnrQTpoHk1NReticle: recordset of TblPlnrQTpoHk1NReticle
  */
class ListPlnrQTpoHk1NReticle {

public:
	ListPlnrQTpoHk1NReticle();
	ListPlnrQTpoHk1NReticle(const ListPlnrQTpoHk1NReticle& src);
	~ListPlnrQTpoHk1NReticle();

	void clear();
	unsigned int size() const;
	void append(PlnrQTpoHk1NReticle* rec);

	ListPlnrQTpoHk1NReticle& operator=(const ListPlnrQTpoHk1NReticle& src);

public:
	vector<PlnrQTpoHk1NReticle*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblPlnrQTpoHk1NReticle: C++ wrapper for table TblPlnrQTpoHk1NReticle
  */
class TblPlnrQTpoHk1NReticle {

public:
	TblPlnrQTpoHk1NReticle();
	virtual ~TblPlnrQTpoHk1NReticle();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrQTpoHk1NReticle** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQTpoHk1NReticle& rst);

	virtual void insertRec(PlnrQTpoHk1NReticle* rec);
	ubigint insertNewRec(PlnrQTpoHk1NReticle** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	ubigint appendNewRecToRst(ListPlnrQTpoHk1NReticle& rst, PlnrQTpoHk1NReticle** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	virtual void insertRst(ListPlnrQTpoHk1NReticle& rst);
	virtual void updateRec(PlnrQTpoHk1NReticle* rec);
	virtual void updateRst(ListPlnrQTpoHk1NReticle& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, PlnrQTpoHk1NReticle** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQTpoHk1NReticle& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrQTpoHk1NReticle: C++ wrapper for table TblPlnrQTpoHk1NReticle (MySQL database)
  */
class MyTblPlnrQTpoHk1NReticle : public TblPlnrQTpoHk1NReticle, public MyTable {

public:
	MyTblPlnrQTpoHk1NReticle();
	~MyTblPlnrQTpoHk1NReticle();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQTpoHk1NReticle** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQTpoHk1NReticle& rst);

	void insertRec(PlnrQTpoHk1NReticle* rec);
	void insertRst(ListPlnrQTpoHk1NReticle& rst);
	void updateRec(PlnrQTpoHk1NReticle* rec);
	void updateRst(ListPlnrQTpoHk1NReticle& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQTpoHk1NReticle** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQTpoHk1NReticle& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrQTpoHk1NReticle: C++ wrapper for table TblPlnrQTpoHk1NReticle (PgSQL database)
  */
class PgTblPlnrQTpoHk1NReticle : public TblPlnrQTpoHk1NReticle, public PgTable {

public:
	PgTblPlnrQTpoHk1NReticle();
	~PgTblPlnrQTpoHk1NReticle();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrQTpoHk1NReticle** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrQTpoHk1NReticle& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrQTpoHk1NReticle** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrQTpoHk1NReticle& rst);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQTpoHk1NReticle** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQTpoHk1NReticle& rst);

	void insertRec(PlnrQTpoHk1NReticle* rec);
	void insertRst(ListPlnrQTpoHk1NReticle& rst);
	void updateRec(PlnrQTpoHk1NReticle* rec);
	void updateRst(ListPlnrQTpoHk1NReticle& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQTpoHk1NReticle** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQTpoHk1NReticle& rst);
};
// IP pgTbl --- END

#endif

