/**
  * \file PlnrQCtpKEnvKey.h
  * Dbs and XML wrapper for table TblPlnrQCtpKEnvKey (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQCTPKENVKEY_H
#define PLNRQCTPKENVKEY_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQCtpKEnvKey: record of TblPlnrQCtpKEnvKey
  */
class PlnrQCtpKEnvKey {

public:
	PlnrQCtpKEnvKey(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const uint klsNum = 0, const string sref = "", const ubigint refJ = 0, const string Title = "", const string Comment = "");

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
  * ListPlnrQCtpKEnvKey: recordset of TblPlnrQCtpKEnvKey
  */
class ListPlnrQCtpKEnvKey {

public:
	ListPlnrQCtpKEnvKey();
	ListPlnrQCtpKEnvKey(const ListPlnrQCtpKEnvKey& src);
	~ListPlnrQCtpKEnvKey();

	void clear();
	unsigned int size() const;
	void append(PlnrQCtpKEnvKey* rec);

	ListPlnrQCtpKEnvKey& operator=(const ListPlnrQCtpKEnvKey& src);

public:
	vector<PlnrQCtpKEnvKey*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblPlnrQCtpKEnvKey: C++ wrapper for table TblPlnrQCtpKEnvKey
  */
class TblPlnrQCtpKEnvKey {

public:
	TblPlnrQCtpKEnvKey();
	virtual ~TblPlnrQCtpKEnvKey();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrQCtpKEnvKey** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQCtpKEnvKey& rst);

	virtual void insertRec(PlnrQCtpKEnvKey* rec);
	ubigint insertNewRec(PlnrQCtpKEnvKey** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const uint klsNum = 0, const string sref = "", const ubigint refJ = 0, const string Title = "", const string Comment = "");
	ubigint appendNewRecToRst(ListPlnrQCtpKEnvKey& rst, PlnrQCtpKEnvKey** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const uint klsNum = 0, const string sref = "", const ubigint refJ = 0, const string Title = "", const string Comment = "");
	virtual void insertRst(ListPlnrQCtpKEnvKey& rst);
	virtual void updateRec(PlnrQCtpKEnvKey* rec);
	virtual void updateRst(ListPlnrQCtpKEnvKey& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, PlnrQCtpKEnvKey** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQCtpKEnvKey& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrQCtpKEnvKey: C++ wrapper for table TblPlnrQCtpKEnvKey (MySQL database)
  */
class MyTblPlnrQCtpKEnvKey : public TblPlnrQCtpKEnvKey, public MyTable {

public:
	MyTblPlnrQCtpKEnvKey();
	~MyTblPlnrQCtpKEnvKey();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQCtpKEnvKey** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQCtpKEnvKey& rst);

	void insertRec(PlnrQCtpKEnvKey* rec);
	void insertRst(ListPlnrQCtpKEnvKey& rst);
	void updateRec(PlnrQCtpKEnvKey* rec);
	void updateRst(ListPlnrQCtpKEnvKey& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQCtpKEnvKey** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQCtpKEnvKey& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrQCtpKEnvKey: C++ wrapper for table TblPlnrQCtpKEnvKey (PgSQL database)
  */
class PgTblPlnrQCtpKEnvKey : public TblPlnrQCtpKEnvKey, public PgTable {

public:
	PgTblPlnrQCtpKEnvKey();
	~PgTblPlnrQCtpKEnvKey();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrQCtpKEnvKey** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrQCtpKEnvKey& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrQCtpKEnvKey** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrQCtpKEnvKey& rst);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQCtpKEnvKey** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQCtpKEnvKey& rst);

	void insertRec(PlnrQCtpKEnvKey* rec);
	void insertRst(ListPlnrQCtpKEnvKey& rst);
	void updateRec(PlnrQCtpKEnvKey* rec);
	void updateRst(ListPlnrQCtpKEnvKey& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQCtpKEnvKey** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQCtpKEnvKey& rst);
};
// IP pgTbl --- END

#endif

