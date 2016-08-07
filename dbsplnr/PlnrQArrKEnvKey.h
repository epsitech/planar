/**
  * \file PlnrQArrKEnvKey.h
  * Dbs and XML wrapper for table TblPlnrQArrKEnvKey (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQARRKENVKEY_H
#define PLNRQARRKENVKEY_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQArrKEnvKey: record of TblPlnrQArrKEnvKey
  */
class PlnrQArrKEnvKey {

public:
	PlnrQArrKEnvKey(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const uint klsNum = 0, const bool Fixed = false, const string yesnoFixed = "", const string sref = "", const string Avail = "", const string Implied = "", const ubigint refJ = 0, const string Title = "", const string Comment = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	uint klsNum;
	bool Fixed;
	string yesnoFixed;
	string sref;
	string Avail;
	string Implied;
	ubigint refJ;
	string Title;
	string Comment;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListPlnrQArrKEnvKey: recordset of TblPlnrQArrKEnvKey
  */
class ListPlnrQArrKEnvKey {

public:
	ListPlnrQArrKEnvKey();
	ListPlnrQArrKEnvKey(const ListPlnrQArrKEnvKey& src);
	~ListPlnrQArrKEnvKey();

	void clear();
	unsigned int size() const;
	void append(PlnrQArrKEnvKey* rec);

	ListPlnrQArrKEnvKey& operator=(const ListPlnrQArrKEnvKey& src);

public:
	vector<PlnrQArrKEnvKey*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblPlnrQArrKEnvKey: C++ wrapper for table TblPlnrQArrKEnvKey
  */
class TblPlnrQArrKEnvKey {

public:
	TblPlnrQArrKEnvKey();
	virtual ~TblPlnrQArrKEnvKey();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrQArrKEnvKey** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQArrKEnvKey& rst);

	virtual void insertRec(PlnrQArrKEnvKey* rec);
	ubigint insertNewRec(PlnrQArrKEnvKey** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const uint klsNum = 0, const bool Fixed = false, const string yesnoFixed = "", const string sref = "", const string Avail = "", const string Implied = "", const ubigint refJ = 0, const string Title = "", const string Comment = "");
	ubigint appendNewRecToRst(ListPlnrQArrKEnvKey& rst, PlnrQArrKEnvKey** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const uint klsNum = 0, const bool Fixed = false, const string yesnoFixed = "", const string sref = "", const string Avail = "", const string Implied = "", const ubigint refJ = 0, const string Title = "", const string Comment = "");
	virtual void insertRst(ListPlnrQArrKEnvKey& rst);
	virtual void updateRec(PlnrQArrKEnvKey* rec);
	virtual void updateRst(ListPlnrQArrKEnvKey& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, PlnrQArrKEnvKey** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQArrKEnvKey& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrQArrKEnvKey: C++ wrapper for table TblPlnrQArrKEnvKey (MySQL database)
  */
class MyTblPlnrQArrKEnvKey : public TblPlnrQArrKEnvKey, public MyTable {

public:
	MyTblPlnrQArrKEnvKey();
	~MyTblPlnrQArrKEnvKey();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQArrKEnvKey** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQArrKEnvKey& rst);

	void insertRec(PlnrQArrKEnvKey* rec);
	void insertRst(ListPlnrQArrKEnvKey& rst);
	void updateRec(PlnrQArrKEnvKey* rec);
	void updateRst(ListPlnrQArrKEnvKey& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQArrKEnvKey** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQArrKEnvKey& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrQArrKEnvKey: C++ wrapper for table TblPlnrQArrKEnvKey (PgSQL database)
  */
class PgTblPlnrQArrKEnvKey : public TblPlnrQArrKEnvKey, public PgTable {

public:
	PgTblPlnrQArrKEnvKey();
	~PgTblPlnrQArrKEnvKey();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrQArrKEnvKey** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrQArrKEnvKey& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrQArrKEnvKey** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrQArrKEnvKey& rst);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQArrKEnvKey** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQArrKEnvKey& rst);

	void insertRec(PlnrQArrKEnvKey* rec);
	void insertRst(ListPlnrQArrKEnvKey& rst);
	void updateRec(PlnrQArrKEnvKey* rec);
	void updateRst(ListPlnrQArrKEnvKey& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQArrKEnvKey** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQArrKEnvKey& rst);
};
// IP pgTbl --- END

#endif

