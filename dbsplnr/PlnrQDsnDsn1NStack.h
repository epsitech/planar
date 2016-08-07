/**
  * \file PlnrQDsnDsn1NStack.h
  * Dbs and XML wrapper for table TblPlnrQDsnDsn1NStack (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQDSNDSN1NSTACK_H
#define PLNRQDSNDSN1NSTACK_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQDsnDsn1NStack: record of TblPlnrQDsnDsn1NStack
  */
class PlnrQDsnDsn1NStack {

public:
	PlnrQDsnDsn1NStack(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "", const uint dsnNum = 0);

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	string stubRef;
	uint dsnNum;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListPlnrQDsnDsn1NStack: recordset of TblPlnrQDsnDsn1NStack
  */
class ListPlnrQDsnDsn1NStack {

public:
	ListPlnrQDsnDsn1NStack();
	ListPlnrQDsnDsn1NStack(const ListPlnrQDsnDsn1NStack& src);
	~ListPlnrQDsnDsn1NStack();

	void clear();
	unsigned int size() const;
	void append(PlnrQDsnDsn1NStack* rec);

	ListPlnrQDsnDsn1NStack& operator=(const ListPlnrQDsnDsn1NStack& src);

public:
	vector<PlnrQDsnDsn1NStack*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblPlnrQDsnDsn1NStack: C++ wrapper for table TblPlnrQDsnDsn1NStack
  */
class TblPlnrQDsnDsn1NStack {

public:
	TblPlnrQDsnDsn1NStack();
	virtual ~TblPlnrQDsnDsn1NStack();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrQDsnDsn1NStack** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQDsnDsn1NStack& rst);

	virtual void insertRec(PlnrQDsnDsn1NStack* rec);
	ubigint insertNewRec(PlnrQDsnDsn1NStack** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "", const uint dsnNum = 0);
	ubigint appendNewRecToRst(ListPlnrQDsnDsn1NStack& rst, PlnrQDsnDsn1NStack** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "", const uint dsnNum = 0);
	virtual void insertRst(ListPlnrQDsnDsn1NStack& rst);
	virtual void updateRec(PlnrQDsnDsn1NStack* rec);
	virtual void updateRst(ListPlnrQDsnDsn1NStack& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, PlnrQDsnDsn1NStack** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQDsnDsn1NStack& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrQDsnDsn1NStack: C++ wrapper for table TblPlnrQDsnDsn1NStack (MySQL database)
  */
class MyTblPlnrQDsnDsn1NStack : public TblPlnrQDsnDsn1NStack, public MyTable {

public:
	MyTblPlnrQDsnDsn1NStack();
	~MyTblPlnrQDsnDsn1NStack();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQDsnDsn1NStack** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQDsnDsn1NStack& rst);

	void insertRec(PlnrQDsnDsn1NStack* rec);
	void insertRst(ListPlnrQDsnDsn1NStack& rst);
	void updateRec(PlnrQDsnDsn1NStack* rec);
	void updateRst(ListPlnrQDsnDsn1NStack& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQDsnDsn1NStack** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQDsnDsn1NStack& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrQDsnDsn1NStack: C++ wrapper for table TblPlnrQDsnDsn1NStack (PgSQL database)
  */
class PgTblPlnrQDsnDsn1NStack : public TblPlnrQDsnDsn1NStack, public PgTable {

public:
	PgTblPlnrQDsnDsn1NStack();
	~PgTblPlnrQDsnDsn1NStack();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrQDsnDsn1NStack** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrQDsnDsn1NStack& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrQDsnDsn1NStack** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrQDsnDsn1NStack& rst);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQDsnDsn1NStack** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQDsnDsn1NStack& rst);

	void insertRec(PlnrQDsnDsn1NStack* rec);
	void insertRst(ListPlnrQDsnDsn1NStack& rst);
	void updateRec(PlnrQDsnDsn1NStack* rec);
	void updateRst(ListPlnrQDsnDsn1NStack& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQDsnDsn1NStack** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQDsnDsn1NStack& rst);
};
// IP pgTbl --- END

#endif

