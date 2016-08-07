/**
  * \file PlnrQDsnList.h
  * Dbs and XML wrapper for table TblPlnrQDsnList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQDSNLIST_H
#define PLNRQDSNLIST_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQDsnList: record of TblPlnrQDsnList
  */
class PlnrQDsnList {

public:
	PlnrQDsnList(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string Title = "", const uint ixVBasetype = 0, const string srefIxVBasetype = "", const string titIxVBasetype = "", const uint ixVDim = 0, const string srefIxVDim = "", const string titIxVDim = "", const uint refIxVTbl = 0, const string srefRefIxVTbl = "", const string titRefIxVTbl = "", const ubigint refUref = 0, const string stubRefUref = "", const ubigint refPlnrMProject = 0, const string stubRefPlnrMProject = "", const uint ixWModtype = 0, const string srefsIxWModtype = "", const string titsIxWModtype = "", const ubigint modRefPlnrMDesign = 0, const string stubModRefPlnrMDesign = "", const ubigint drvRefPlnrMDesign = 0, const string stubDrvRefPlnrMDesign = "", const usmallint Major = 0, const usmallint Sub = 0);

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	string Title;
	uint ixVBasetype;
	string srefIxVBasetype;
	string titIxVBasetype;
	uint ixVDim;
	string srefIxVDim;
	string titIxVDim;
	uint refIxVTbl;
	string srefRefIxVTbl;
	string titRefIxVTbl;
	ubigint refUref;
	string stubRefUref;
	ubigint refPlnrMProject;
	string stubRefPlnrMProject;
	uint ixWModtype;
	string srefsIxWModtype;
	string titsIxWModtype;
	ubigint modRefPlnrMDesign;
	string stubModRefPlnrMDesign;
	ubigint drvRefPlnrMDesign;
	string stubDrvRefPlnrMDesign;
	usmallint Major;
	usmallint Sub;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListPlnrQDsnList: recordset of TblPlnrQDsnList
  */
class ListPlnrQDsnList {

public:
	ListPlnrQDsnList();
	ListPlnrQDsnList(const ListPlnrQDsnList& src);
	~ListPlnrQDsnList();

	void clear();
	unsigned int size() const;
	void append(PlnrQDsnList* rec);

	ListPlnrQDsnList& operator=(const ListPlnrQDsnList& src);

public:
	vector<PlnrQDsnList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblPlnrQDsnList: C++ wrapper for table TblPlnrQDsnList
  */
class TblPlnrQDsnList {

public:
	TblPlnrQDsnList();
	virtual ~TblPlnrQDsnList();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrQDsnList** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQDsnList& rst);

	virtual void insertRec(PlnrQDsnList* rec);
	ubigint insertNewRec(PlnrQDsnList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string Title = "", const uint ixVBasetype = 0, const string srefIxVBasetype = "", const string titIxVBasetype = "", const uint ixVDim = 0, const string srefIxVDim = "", const string titIxVDim = "", const uint refIxVTbl = 0, const string srefRefIxVTbl = "", const string titRefIxVTbl = "", const ubigint refUref = 0, const string stubRefUref = "", const ubigint refPlnrMProject = 0, const string stubRefPlnrMProject = "", const uint ixWModtype = 0, const string srefsIxWModtype = "", const string titsIxWModtype = "", const ubigint modRefPlnrMDesign = 0, const string stubModRefPlnrMDesign = "", const ubigint drvRefPlnrMDesign = 0, const string stubDrvRefPlnrMDesign = "", const usmallint Major = 0, const usmallint Sub = 0);
	ubigint appendNewRecToRst(ListPlnrQDsnList& rst, PlnrQDsnList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string Title = "", const uint ixVBasetype = 0, const string srefIxVBasetype = "", const string titIxVBasetype = "", const uint ixVDim = 0, const string srefIxVDim = "", const string titIxVDim = "", const uint refIxVTbl = 0, const string srefRefIxVTbl = "", const string titRefIxVTbl = "", const ubigint refUref = 0, const string stubRefUref = "", const ubigint refPlnrMProject = 0, const string stubRefPlnrMProject = "", const uint ixWModtype = 0, const string srefsIxWModtype = "", const string titsIxWModtype = "", const ubigint modRefPlnrMDesign = 0, const string stubModRefPlnrMDesign = "", const ubigint drvRefPlnrMDesign = 0, const string stubDrvRefPlnrMDesign = "", const usmallint Major = 0, const usmallint Sub = 0);
	virtual void insertRst(ListPlnrQDsnList& rst);
	virtual void updateRec(PlnrQDsnList* rec);
	virtual void updateRst(ListPlnrQDsnList& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, PlnrQDsnList** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQDsnList& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrQDsnList: C++ wrapper for table TblPlnrQDsnList (MySQL database)
  */
class MyTblPlnrQDsnList : public TblPlnrQDsnList, public MyTable {

public:
	MyTblPlnrQDsnList();
	~MyTblPlnrQDsnList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQDsnList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQDsnList& rst);

	void insertRec(PlnrQDsnList* rec);
	void insertRst(ListPlnrQDsnList& rst);
	void updateRec(PlnrQDsnList* rec);
	void updateRst(ListPlnrQDsnList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQDsnList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQDsnList& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrQDsnList: C++ wrapper for table TblPlnrQDsnList (PgSQL database)
  */
class PgTblPlnrQDsnList : public TblPlnrQDsnList, public PgTable {

public:
	PgTblPlnrQDsnList();
	~PgTblPlnrQDsnList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrQDsnList** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrQDsnList& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrQDsnList** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrQDsnList& rst);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQDsnList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQDsnList& rst);

	void insertRec(PlnrQDsnList* rec);
	void insertRst(ListPlnrQDsnList& rst);
	void updateRec(PlnrQDsnList* rec);
	void updateRst(ListPlnrQDsnList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQDsnList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQDsnList& rst);
};
// IP pgTbl --- END

#endif

