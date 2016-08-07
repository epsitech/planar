/**
  * \file PlnrQMatList.h
  * Dbs and XML wrapper for table TblPlnrQMatList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQMATLIST_H
#define PLNRQMATLIST_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQMatList: record of TblPlnrQMatList
  */
class PlnrQMatList {

public:
	PlnrQMatList(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string sref = "", const string Title = "", const uint ixVBasetype = 0, const string srefIxVBasetype = "", const string titIxVBasetype = "", const ubigint refPlnrMCalc = 0, const string stubRefPlnrMCalc = "", const ubigint modRefPlnrMMaterial = 0, const string stubModRefPlnrMMaterial = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	string sref;
	string Title;
	uint ixVBasetype;
	string srefIxVBasetype;
	string titIxVBasetype;
	ubigint refPlnrMCalc;
	string stubRefPlnrMCalc;
	ubigint modRefPlnrMMaterial;
	string stubModRefPlnrMMaterial;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListPlnrQMatList: recordset of TblPlnrQMatList
  */
class ListPlnrQMatList {

public:
	ListPlnrQMatList();
	ListPlnrQMatList(const ListPlnrQMatList& src);
	~ListPlnrQMatList();

	void clear();
	unsigned int size() const;
	void append(PlnrQMatList* rec);

	ListPlnrQMatList& operator=(const ListPlnrQMatList& src);

public:
	vector<PlnrQMatList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblPlnrQMatList: C++ wrapper for table TblPlnrQMatList
  */
class TblPlnrQMatList {

public:
	TblPlnrQMatList();
	virtual ~TblPlnrQMatList();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrQMatList** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQMatList& rst);

	virtual void insertRec(PlnrQMatList* rec);
	ubigint insertNewRec(PlnrQMatList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string sref = "", const string Title = "", const uint ixVBasetype = 0, const string srefIxVBasetype = "", const string titIxVBasetype = "", const ubigint refPlnrMCalc = 0, const string stubRefPlnrMCalc = "", const ubigint modRefPlnrMMaterial = 0, const string stubModRefPlnrMMaterial = "");
	ubigint appendNewRecToRst(ListPlnrQMatList& rst, PlnrQMatList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string sref = "", const string Title = "", const uint ixVBasetype = 0, const string srefIxVBasetype = "", const string titIxVBasetype = "", const ubigint refPlnrMCalc = 0, const string stubRefPlnrMCalc = "", const ubigint modRefPlnrMMaterial = 0, const string stubModRefPlnrMMaterial = "");
	virtual void insertRst(ListPlnrQMatList& rst);
	virtual void updateRec(PlnrQMatList* rec);
	virtual void updateRst(ListPlnrQMatList& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, PlnrQMatList** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQMatList& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrQMatList: C++ wrapper for table TblPlnrQMatList (MySQL database)
  */
class MyTblPlnrQMatList : public TblPlnrQMatList, public MyTable {

public:
	MyTblPlnrQMatList();
	~MyTblPlnrQMatList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQMatList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQMatList& rst);

	void insertRec(PlnrQMatList* rec);
	void insertRst(ListPlnrQMatList& rst);
	void updateRec(PlnrQMatList* rec);
	void updateRst(ListPlnrQMatList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQMatList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQMatList& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrQMatList: C++ wrapper for table TblPlnrQMatList (PgSQL database)
  */
class PgTblPlnrQMatList : public TblPlnrQMatList, public PgTable {

public:
	PgTblPlnrQMatList();
	~PgTblPlnrQMatList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrQMatList** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrQMatList& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrQMatList** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrQMatList& rst);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQMatList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQMatList& rst);

	void insertRec(PlnrQMatList* rec);
	void insertRst(ListPlnrQMatList& rst);
	void updateRec(PlnrQMatList* rec);
	void updateRst(ListPlnrQMatList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQMatList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQMatList& rst);
};
// IP pgTbl --- END

#endif

