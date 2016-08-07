/**
  * \file PlnrQCliList.h
  * Dbs and XML wrapper for table TblPlnrQCliList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQCLILIST_H
#define PLNRQCLILIST_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQCliList: record of TblPlnrQCliList
  */
class PlnrQCliList {

public:
	PlnrQCliList(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string Title = "", const ubigint calRefPlnrMCalc = 0, const string stubCalRefPlnrMCalc = "", const ubigint refPlnrMDesign = 0, const string stubRefPlnrMDesign = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	string Title;
	ubigint calRefPlnrMCalc;
	string stubCalRefPlnrMCalc;
	ubigint refPlnrMDesign;
	string stubRefPlnrMDesign;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListPlnrQCliList: recordset of TblPlnrQCliList
  */
class ListPlnrQCliList {

public:
	ListPlnrQCliList();
	ListPlnrQCliList(const ListPlnrQCliList& src);
	~ListPlnrQCliList();

	void clear();
	unsigned int size() const;
	void append(PlnrQCliList* rec);

	ListPlnrQCliList& operator=(const ListPlnrQCliList& src);

public:
	vector<PlnrQCliList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblPlnrQCliList: C++ wrapper for table TblPlnrQCliList
  */
class TblPlnrQCliList {

public:
	TblPlnrQCliList();
	virtual ~TblPlnrQCliList();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrQCliList** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQCliList& rst);

	virtual void insertRec(PlnrQCliList* rec);
	ubigint insertNewRec(PlnrQCliList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string Title = "", const ubigint calRefPlnrMCalc = 0, const string stubCalRefPlnrMCalc = "", const ubigint refPlnrMDesign = 0, const string stubRefPlnrMDesign = "");
	ubigint appendNewRecToRst(ListPlnrQCliList& rst, PlnrQCliList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string Title = "", const ubigint calRefPlnrMCalc = 0, const string stubCalRefPlnrMCalc = "", const ubigint refPlnrMDesign = 0, const string stubRefPlnrMDesign = "");
	virtual void insertRst(ListPlnrQCliList& rst);
	virtual void updateRec(PlnrQCliList* rec);
	virtual void updateRst(ListPlnrQCliList& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, PlnrQCliList** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQCliList& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrQCliList: C++ wrapper for table TblPlnrQCliList (MySQL database)
  */
class MyTblPlnrQCliList : public TblPlnrQCliList, public MyTable {

public:
	MyTblPlnrQCliList();
	~MyTblPlnrQCliList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQCliList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQCliList& rst);

	void insertRec(PlnrQCliList* rec);
	void insertRst(ListPlnrQCliList& rst);
	void updateRec(PlnrQCliList* rec);
	void updateRst(ListPlnrQCliList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQCliList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQCliList& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrQCliList: C++ wrapper for table TblPlnrQCliList (PgSQL database)
  */
class PgTblPlnrQCliList : public TblPlnrQCliList, public PgTable {

public:
	PgTblPlnrQCliList();
	~PgTblPlnrQCliList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrQCliList** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrQCliList& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrQCliList** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrQCliList& rst);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQCliList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQCliList& rst);

	void insertRec(PlnrQCliList* rec);
	void insertRst(ListPlnrQCliList& rst);
	void updateRec(PlnrQCliList* rec);
	void updateRst(ListPlnrQCliList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQCliList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQCliList& rst);
};
// IP pgTbl --- END

#endif

