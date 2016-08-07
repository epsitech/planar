/**
  * \file PlnrQTpoList.h
  * Dbs and XML wrapper for table TblPlnrQTpoList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQTPOLIST_H
#define PLNRQTPOLIST_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQTpoList: record of TblPlnrQTpoList
  */
class PlnrQTpoList {

public:
	PlnrQTpoList(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string Title = "", const uint ixVBasetype = 0, const string srefIxVBasetype = "", const string titIxVBasetype = "", const usmallint Major = 0, const usmallint Sub = 0, const uint ixVState = 0, const string srefIxVState = "", const string titIxVState = "", const bool Hflip = false, const string yesnoHflip = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	string Title;
	uint ixVBasetype;
	string srefIxVBasetype;
	string titIxVBasetype;
	usmallint Major;
	usmallint Sub;
	uint ixVState;
	string srefIxVState;
	string titIxVState;
	bool Hflip;
	string yesnoHflip;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListPlnrQTpoList: recordset of TblPlnrQTpoList
  */
class ListPlnrQTpoList {

public:
	ListPlnrQTpoList();
	ListPlnrQTpoList(const ListPlnrQTpoList& src);
	~ListPlnrQTpoList();

	void clear();
	unsigned int size() const;
	void append(PlnrQTpoList* rec);

	ListPlnrQTpoList& operator=(const ListPlnrQTpoList& src);

public:
	vector<PlnrQTpoList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblPlnrQTpoList: C++ wrapper for table TblPlnrQTpoList
  */
class TblPlnrQTpoList {

public:
	TblPlnrQTpoList();
	virtual ~TblPlnrQTpoList();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrQTpoList** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQTpoList& rst);

	virtual void insertRec(PlnrQTpoList* rec);
	ubigint insertNewRec(PlnrQTpoList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string Title = "", const uint ixVBasetype = 0, const string srefIxVBasetype = "", const string titIxVBasetype = "", const usmallint Major = 0, const usmallint Sub = 0, const uint ixVState = 0, const string srefIxVState = "", const string titIxVState = "", const bool Hflip = false, const string yesnoHflip = "");
	ubigint appendNewRecToRst(ListPlnrQTpoList& rst, PlnrQTpoList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string Title = "", const uint ixVBasetype = 0, const string srefIxVBasetype = "", const string titIxVBasetype = "", const usmallint Major = 0, const usmallint Sub = 0, const uint ixVState = 0, const string srefIxVState = "", const string titIxVState = "", const bool Hflip = false, const string yesnoHflip = "");
	virtual void insertRst(ListPlnrQTpoList& rst);
	virtual void updateRec(PlnrQTpoList* rec);
	virtual void updateRst(ListPlnrQTpoList& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, PlnrQTpoList** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQTpoList& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrQTpoList: C++ wrapper for table TblPlnrQTpoList (MySQL database)
  */
class MyTblPlnrQTpoList : public TblPlnrQTpoList, public MyTable {

public:
	MyTblPlnrQTpoList();
	~MyTblPlnrQTpoList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQTpoList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQTpoList& rst);

	void insertRec(PlnrQTpoList* rec);
	void insertRst(ListPlnrQTpoList& rst);
	void updateRec(PlnrQTpoList* rec);
	void updateRst(ListPlnrQTpoList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQTpoList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQTpoList& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrQTpoList: C++ wrapper for table TblPlnrQTpoList (PgSQL database)
  */
class PgTblPlnrQTpoList : public TblPlnrQTpoList, public PgTable {

public:
	PgTblPlnrQTpoList();
	~PgTblPlnrQTpoList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrQTpoList** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrQTpoList& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrQTpoList** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrQTpoList& rst);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQTpoList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQTpoList& rst);

	void insertRec(PlnrQTpoList* rec);
	void insertRst(ListPlnrQTpoList& rst);
	void updateRec(PlnrQTpoList* rec);
	void updateRst(ListPlnrQTpoList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQTpoList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQTpoList& rst);
};
// IP pgTbl --- END

#endif

