/**
  * \file PlnrQPrjList.h
  * Dbs and XML wrapper for table TblPlnrQPrjList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQPRJLIST_H
#define PLNRQPRJLIST_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQPrjList: record of TblPlnrQPrjList
  */
class PlnrQPrjList {

public:
	PlnrQPrjList(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string Title = "", const uint ixVState = 0, const string srefIxVState = "", const string titIxVState = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	string Title;
	uint ixVState;
	string srefIxVState;
	string titIxVState;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListPlnrQPrjList: recordset of TblPlnrQPrjList
  */
class ListPlnrQPrjList {

public:
	ListPlnrQPrjList();
	ListPlnrQPrjList(const ListPlnrQPrjList& src);
	~ListPlnrQPrjList();

	void clear();
	unsigned int size() const;
	void append(PlnrQPrjList* rec);

	ListPlnrQPrjList& operator=(const ListPlnrQPrjList& src);

public:
	vector<PlnrQPrjList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblPlnrQPrjList: C++ wrapper for table TblPlnrQPrjList
  */
class TblPlnrQPrjList {

public:
	TblPlnrQPrjList();
	virtual ~TblPlnrQPrjList();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrQPrjList** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQPrjList& rst);

	virtual void insertRec(PlnrQPrjList* rec);
	ubigint insertNewRec(PlnrQPrjList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string Title = "", const uint ixVState = 0, const string srefIxVState = "", const string titIxVState = "");
	ubigint appendNewRecToRst(ListPlnrQPrjList& rst, PlnrQPrjList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string Title = "", const uint ixVState = 0, const string srefIxVState = "", const string titIxVState = "");
	virtual void insertRst(ListPlnrQPrjList& rst);
	virtual void updateRec(PlnrQPrjList* rec);
	virtual void updateRst(ListPlnrQPrjList& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, PlnrQPrjList** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQPrjList& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrQPrjList: C++ wrapper for table TblPlnrQPrjList (MySQL database)
  */
class MyTblPlnrQPrjList : public TblPlnrQPrjList, public MyTable {

public:
	MyTblPlnrQPrjList();
	~MyTblPlnrQPrjList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQPrjList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQPrjList& rst);

	void insertRec(PlnrQPrjList* rec);
	void insertRst(ListPlnrQPrjList& rst);
	void updateRec(PlnrQPrjList* rec);
	void updateRst(ListPlnrQPrjList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQPrjList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQPrjList& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrQPrjList: C++ wrapper for table TblPlnrQPrjList (PgSQL database)
  */
class PgTblPlnrQPrjList : public TblPlnrQPrjList, public PgTable {

public:
	PgTblPlnrQPrjList();
	~PgTblPlnrQPrjList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrQPrjList** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrQPrjList& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrQPrjList** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrQPrjList& rst);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQPrjList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQPrjList& rst);

	void insertRec(PlnrQPrjList* rec);
	void insertRst(ListPlnrQPrjList& rst);
	void updateRec(PlnrQPrjList* rec);
	void updateRst(ListPlnrQPrjList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQPrjList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQPrjList& rst);
};
// IP pgTbl --- END

#endif

