/**
  * \file PlnrQDtpKParKey.h
  * Dbs and XML wrapper for table TblPlnrQDtpKParKey (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQDTPKPARKEY_H
#define PLNRQDTPKPARKEY_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQDtpKParKey: record of TblPlnrQDtpKParKey
  */
class PlnrQDtpKParKey {

public:
	PlnrQDtpKParKey(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const uint klsNum = 0, const string sref = "", const ubigint refJ = 0, const string Title = "", const string Comment = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	uint klsNum;
	string sref;
	ubigint refJ;
	string Title;
	string Comment;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListPlnrQDtpKParKey: recordset of TblPlnrQDtpKParKey
  */
class ListPlnrQDtpKParKey {

public:
	ListPlnrQDtpKParKey();
	ListPlnrQDtpKParKey(const ListPlnrQDtpKParKey& src);
	~ListPlnrQDtpKParKey();

	void clear();
	unsigned int size() const;
	void append(PlnrQDtpKParKey* rec);

	ListPlnrQDtpKParKey& operator=(const ListPlnrQDtpKParKey& src);

public:
	vector<PlnrQDtpKParKey*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblPlnrQDtpKParKey: C++ wrapper for table TblPlnrQDtpKParKey
  */
class TblPlnrQDtpKParKey {

public:
	TblPlnrQDtpKParKey();
	virtual ~TblPlnrQDtpKParKey();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrQDtpKParKey** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQDtpKParKey& rst);

	virtual void insertRec(PlnrQDtpKParKey* rec);
	ubigint insertNewRec(PlnrQDtpKParKey** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const uint klsNum = 0, const string sref = "", const ubigint refJ = 0, const string Title = "", const string Comment = "");
	ubigint appendNewRecToRst(ListPlnrQDtpKParKey& rst, PlnrQDtpKParKey** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const uint klsNum = 0, const string sref = "", const ubigint refJ = 0, const string Title = "", const string Comment = "");
	virtual void insertRst(ListPlnrQDtpKParKey& rst);
	virtual void updateRec(PlnrQDtpKParKey* rec);
	virtual void updateRst(ListPlnrQDtpKParKey& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, PlnrQDtpKParKey** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQDtpKParKey& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrQDtpKParKey: C++ wrapper for table TblPlnrQDtpKParKey (MySQL database)
  */
class MyTblPlnrQDtpKParKey : public TblPlnrQDtpKParKey, public MyTable {

public:
	MyTblPlnrQDtpKParKey();
	~MyTblPlnrQDtpKParKey();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQDtpKParKey** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQDtpKParKey& rst);

	void insertRec(PlnrQDtpKParKey* rec);
	void insertRst(ListPlnrQDtpKParKey& rst);
	void updateRec(PlnrQDtpKParKey* rec);
	void updateRst(ListPlnrQDtpKParKey& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQDtpKParKey** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQDtpKParKey& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrQDtpKParKey: C++ wrapper for table TblPlnrQDtpKParKey (PgSQL database)
  */
class PgTblPlnrQDtpKParKey : public TblPlnrQDtpKParKey, public PgTable {

public:
	PgTblPlnrQDtpKParKey();
	~PgTblPlnrQDtpKParKey();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrQDtpKParKey** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrQDtpKParKey& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrQDtpKParKey** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrQDtpKParKey& rst);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQDtpKParKey** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQDtpKParKey& rst);

	void insertRec(PlnrQDtpKParKey* rec);
	void insertRst(ListPlnrQDtpKParKey& rst);
	void updateRec(PlnrQDtpKParKey* rec);
	void updateRst(ListPlnrQDtpKParKey& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQDtpKParKey** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQDtpKParKey& rst);
};
// IP pgTbl --- END

#endif

