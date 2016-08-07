/**
  * \file PlnrQUsr1NSession.h
  * Dbs and XML wrapper for table TblPlnrQUsr1NSession (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQUSR1NSESSION_H
#define PLNRQUSR1NSESSION_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQUsr1NSession: record of TblPlnrQUsr1NSession
  */
class PlnrQUsr1NSession {

public:
	PlnrQUsr1NSession(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");

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
  * ListPlnrQUsr1NSession: recordset of TblPlnrQUsr1NSession
  */
class ListPlnrQUsr1NSession {

public:
	ListPlnrQUsr1NSession();
	ListPlnrQUsr1NSession(const ListPlnrQUsr1NSession& src);
	~ListPlnrQUsr1NSession();

	void clear();
	unsigned int size() const;
	void append(PlnrQUsr1NSession* rec);

	ListPlnrQUsr1NSession& operator=(const ListPlnrQUsr1NSession& src);

public:
	vector<PlnrQUsr1NSession*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblPlnrQUsr1NSession: C++ wrapper for table TblPlnrQUsr1NSession
  */
class TblPlnrQUsr1NSession {

public:
	TblPlnrQUsr1NSession();
	virtual ~TblPlnrQUsr1NSession();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrQUsr1NSession** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQUsr1NSession& rst);

	virtual void insertRec(PlnrQUsr1NSession* rec);
	ubigint insertNewRec(PlnrQUsr1NSession** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	ubigint appendNewRecToRst(ListPlnrQUsr1NSession& rst, PlnrQUsr1NSession** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	virtual void insertRst(ListPlnrQUsr1NSession& rst);
	virtual void updateRec(PlnrQUsr1NSession* rec);
	virtual void updateRst(ListPlnrQUsr1NSession& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, PlnrQUsr1NSession** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQUsr1NSession& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrQUsr1NSession: C++ wrapper for table TblPlnrQUsr1NSession (MySQL database)
  */
class MyTblPlnrQUsr1NSession : public TblPlnrQUsr1NSession, public MyTable {

public:
	MyTblPlnrQUsr1NSession();
	~MyTblPlnrQUsr1NSession();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQUsr1NSession** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQUsr1NSession& rst);

	void insertRec(PlnrQUsr1NSession* rec);
	void insertRst(ListPlnrQUsr1NSession& rst);
	void updateRec(PlnrQUsr1NSession* rec);
	void updateRst(ListPlnrQUsr1NSession& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQUsr1NSession** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQUsr1NSession& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrQUsr1NSession: C++ wrapper for table TblPlnrQUsr1NSession (PgSQL database)
  */
class PgTblPlnrQUsr1NSession : public TblPlnrQUsr1NSession, public PgTable {

public:
	PgTblPlnrQUsr1NSession();
	~PgTblPlnrQUsr1NSession();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrQUsr1NSession** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrQUsr1NSession& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrQUsr1NSession** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrQUsr1NSession& rst);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQUsr1NSession** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQUsr1NSession& rst);

	void insertRec(PlnrQUsr1NSession* rec);
	void insertRst(ListPlnrQUsr1NSession& rst);
	void updateRec(PlnrQUsr1NSession* rec);
	void updateRst(ListPlnrQUsr1NSession& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQUsr1NSession** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQUsr1NSession& rst);
};
// IP pgTbl --- END

#endif

