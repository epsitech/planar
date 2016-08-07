/**
  * \file PlnrQDsnDsn1NDomain.h
  * Dbs and XML wrapper for table TblPlnrQDsnDsn1NDomain (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQDSNDSN1NDOMAIN_H
#define PLNRQDSNDSN1NDOMAIN_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQDsnDsn1NDomain: record of TblPlnrQDsnDsn1NDomain
  */
class PlnrQDsnDsn1NDomain {

public:
	PlnrQDsnDsn1NDomain(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "", const uint dsnNum = 0);

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
  * ListPlnrQDsnDsn1NDomain: recordset of TblPlnrQDsnDsn1NDomain
  */
class ListPlnrQDsnDsn1NDomain {

public:
	ListPlnrQDsnDsn1NDomain();
	ListPlnrQDsnDsn1NDomain(const ListPlnrQDsnDsn1NDomain& src);
	~ListPlnrQDsnDsn1NDomain();

	void clear();
	unsigned int size() const;
	void append(PlnrQDsnDsn1NDomain* rec);

	ListPlnrQDsnDsn1NDomain& operator=(const ListPlnrQDsnDsn1NDomain& src);

public:
	vector<PlnrQDsnDsn1NDomain*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblPlnrQDsnDsn1NDomain: C++ wrapper for table TblPlnrQDsnDsn1NDomain
  */
class TblPlnrQDsnDsn1NDomain {

public:
	TblPlnrQDsnDsn1NDomain();
	virtual ~TblPlnrQDsnDsn1NDomain();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrQDsnDsn1NDomain** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQDsnDsn1NDomain& rst);

	virtual void insertRec(PlnrQDsnDsn1NDomain* rec);
	ubigint insertNewRec(PlnrQDsnDsn1NDomain** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "", const uint dsnNum = 0);
	ubigint appendNewRecToRst(ListPlnrQDsnDsn1NDomain& rst, PlnrQDsnDsn1NDomain** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "", const uint dsnNum = 0);
	virtual void insertRst(ListPlnrQDsnDsn1NDomain& rst);
	virtual void updateRec(PlnrQDsnDsn1NDomain* rec);
	virtual void updateRst(ListPlnrQDsnDsn1NDomain& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, PlnrQDsnDsn1NDomain** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQDsnDsn1NDomain& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrQDsnDsn1NDomain: C++ wrapper for table TblPlnrQDsnDsn1NDomain (MySQL database)
  */
class MyTblPlnrQDsnDsn1NDomain : public TblPlnrQDsnDsn1NDomain, public MyTable {

public:
	MyTblPlnrQDsnDsn1NDomain();
	~MyTblPlnrQDsnDsn1NDomain();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQDsnDsn1NDomain** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQDsnDsn1NDomain& rst);

	void insertRec(PlnrQDsnDsn1NDomain* rec);
	void insertRst(ListPlnrQDsnDsn1NDomain& rst);
	void updateRec(PlnrQDsnDsn1NDomain* rec);
	void updateRst(ListPlnrQDsnDsn1NDomain& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQDsnDsn1NDomain** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQDsnDsn1NDomain& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrQDsnDsn1NDomain: C++ wrapper for table TblPlnrQDsnDsn1NDomain (PgSQL database)
  */
class PgTblPlnrQDsnDsn1NDomain : public TblPlnrQDsnDsn1NDomain, public PgTable {

public:
	PgTblPlnrQDsnDsn1NDomain();
	~PgTblPlnrQDsnDsn1NDomain();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrQDsnDsn1NDomain** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrQDsnDsn1NDomain& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrQDsnDsn1NDomain** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrQDsnDsn1NDomain& rst);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQDsnDsn1NDomain** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQDsnDsn1NDomain& rst);

	void insertRec(PlnrQDsnDsn1NDomain* rec);
	void insertRst(ListPlnrQDsnDsn1NDomain& rst);
	void updateRec(PlnrQDsnDsn1NDomain* rec);
	void updateRst(ListPlnrQDsnDsn1NDomain& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQDsnDsn1NDomain** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQDsnDsn1NDomain& rst);
};
// IP pgTbl --- END

#endif

