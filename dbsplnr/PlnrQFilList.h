/**
  * \file PlnrQFilList.h
  * Dbs and XML wrapper for table TblPlnrQFilList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQFILLIST_H
#define PLNRQFILLIST_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQFilList: record of TblPlnrQFilList
  */
class PlnrQFilList {

public:
	PlnrQFilList(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string Filename = "", const uint refIxVTbl = 0, const string srefRefIxVTbl = "", const string titRefIxVTbl = "", const ubigint refUref = 0, const string stubRefUref = "", const string osrefKContent = "", const string titOsrefKContent = "", const string srefKMimetype = "", const string titSrefKMimetype = "", const uint Size = 0);

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	string Filename;
	uint refIxVTbl;
	string srefRefIxVTbl;
	string titRefIxVTbl;
	ubigint refUref;
	string stubRefUref;
	string osrefKContent;
	string titOsrefKContent;
	string srefKMimetype;
	string titSrefKMimetype;
	uint Size;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListPlnrQFilList: recordset of TblPlnrQFilList
  */
class ListPlnrQFilList {

public:
	ListPlnrQFilList();
	ListPlnrQFilList(const ListPlnrQFilList& src);
	~ListPlnrQFilList();

	void clear();
	unsigned int size() const;
	void append(PlnrQFilList* rec);

	ListPlnrQFilList& operator=(const ListPlnrQFilList& src);

public:
	vector<PlnrQFilList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblPlnrQFilList: C++ wrapper for table TblPlnrQFilList
  */
class TblPlnrQFilList {

public:
	TblPlnrQFilList();
	virtual ~TblPlnrQFilList();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrQFilList** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQFilList& rst);

	virtual void insertRec(PlnrQFilList* rec);
	ubigint insertNewRec(PlnrQFilList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string Filename = "", const uint refIxVTbl = 0, const string srefRefIxVTbl = "", const string titRefIxVTbl = "", const ubigint refUref = 0, const string stubRefUref = "", const string osrefKContent = "", const string titOsrefKContent = "", const string srefKMimetype = "", const string titSrefKMimetype = "", const uint Size = 0);
	ubigint appendNewRecToRst(ListPlnrQFilList& rst, PlnrQFilList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string Filename = "", const uint refIxVTbl = 0, const string srefRefIxVTbl = "", const string titRefIxVTbl = "", const ubigint refUref = 0, const string stubRefUref = "", const string osrefKContent = "", const string titOsrefKContent = "", const string srefKMimetype = "", const string titSrefKMimetype = "", const uint Size = 0);
	virtual void insertRst(ListPlnrQFilList& rst);
	virtual void updateRec(PlnrQFilList* rec);
	virtual void updateRst(ListPlnrQFilList& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, PlnrQFilList** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQFilList& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrQFilList: C++ wrapper for table TblPlnrQFilList (MySQL database)
  */
class MyTblPlnrQFilList : public TblPlnrQFilList, public MyTable {

public:
	MyTblPlnrQFilList();
	~MyTblPlnrQFilList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQFilList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQFilList& rst);

	void insertRec(PlnrQFilList* rec);
	void insertRst(ListPlnrQFilList& rst);
	void updateRec(PlnrQFilList* rec);
	void updateRst(ListPlnrQFilList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQFilList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQFilList& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrQFilList: C++ wrapper for table TblPlnrQFilList (PgSQL database)
  */
class PgTblPlnrQFilList : public TblPlnrQFilList, public PgTable {

public:
	PgTblPlnrQFilList();
	~PgTblPlnrQFilList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrQFilList** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrQFilList& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrQFilList** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrQFilList& rst);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQFilList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQFilList& rst);

	void insertRec(PlnrQFilList* rec);
	void insertRst(ListPlnrQFilList& rst);
	void updateRec(PlnrQFilList* rec);
	void updateRst(ListPlnrQFilList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQFilList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQFilList& rst);
};
// IP pgTbl --- END

#endif

