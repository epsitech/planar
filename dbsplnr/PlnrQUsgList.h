/**
  * \file PlnrQUsgList.h
  * Dbs and XML wrapper for table TblPlnrQUsgList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQUSGLIST_H
#define PLNRQUSGLIST_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQUsgList: record of TblPlnrQUsgList
  */
class PlnrQUsgList {

public:
	PlnrQUsgList(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string sref = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	string sref;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListPlnrQUsgList: recordset of TblPlnrQUsgList
  */
class ListPlnrQUsgList {

public:
	ListPlnrQUsgList();
	ListPlnrQUsgList(const ListPlnrQUsgList& src);
	~ListPlnrQUsgList();

	void clear();
	unsigned int size() const;
	void append(PlnrQUsgList* rec);

	ListPlnrQUsgList& operator=(const ListPlnrQUsgList& src);

public:
	vector<PlnrQUsgList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblPlnrQUsgList: C++ wrapper for table TblPlnrQUsgList
  */
class TblPlnrQUsgList {

public:
	TblPlnrQUsgList();
	virtual ~TblPlnrQUsgList();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrQUsgList** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQUsgList& rst);

	virtual void insertRec(PlnrQUsgList* rec);
	ubigint insertNewRec(PlnrQUsgList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string sref = "");
	ubigint appendNewRecToRst(ListPlnrQUsgList& rst, PlnrQUsgList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string sref = "");
	virtual void insertRst(ListPlnrQUsgList& rst);
	virtual void updateRec(PlnrQUsgList* rec);
	virtual void updateRst(ListPlnrQUsgList& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, PlnrQUsgList** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQUsgList& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrQUsgList: C++ wrapper for table TblPlnrQUsgList (MySQL database)
  */
class MyTblPlnrQUsgList : public TblPlnrQUsgList, public MyTable {

public:
	MyTblPlnrQUsgList();
	~MyTblPlnrQUsgList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQUsgList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQUsgList& rst);

	void insertRec(PlnrQUsgList* rec);
	void insertRst(ListPlnrQUsgList& rst);
	void updateRec(PlnrQUsgList* rec);
	void updateRst(ListPlnrQUsgList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQUsgList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQUsgList& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrQUsgList: C++ wrapper for table TblPlnrQUsgList (PgSQL database)
  */
class PgTblPlnrQUsgList : public TblPlnrQUsgList, public PgTable {

public:
	PgTblPlnrQUsgList();
	~PgTblPlnrQUsgList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrQUsgList** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrQUsgList& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrQUsgList** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrQUsgList& rst);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQUsgList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQUsgList& rst);

	void insertRec(PlnrQUsgList* rec);
	void insertRst(ListPlnrQUsgList& rst);
	void updateRec(PlnrQUsgList* rec);
	void updateRst(ListPlnrQUsgList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQUsgList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQUsgList& rst);
};
// IP pgTbl --- END

#endif

