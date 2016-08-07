/**
  * \file PlnrQUsrList.h
  * Dbs and XML wrapper for table TblPlnrQUsrList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQUSRLIST_H
#define PLNRQUSRLIST_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQUsrList: record of TblPlnrQUsrList
  */
class PlnrQUsrList {

public:
	PlnrQUsrList(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const ubigint refPlnrMPerson = 0, const string stubRefPlnrMPerson = "", const string sref = "", const ubigint refPlnrMUsergroup = 0, const string stubRefPlnrMUsergroup = "", const uint ixVState = 0, const string srefIxVState = "", const string titIxVState = "", const uint ixPlnrVLocale = 0, const string srefIxPlnrVLocale = "", const string titIxPlnrVLocale = "", const uint ixPlnrVUserlevel = 0, const string srefIxPlnrVUserlevel = "", const string titIxPlnrVUserlevel = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	ubigint refPlnrMPerson;
	string stubRefPlnrMPerson;
	string sref;
	ubigint refPlnrMUsergroup;
	string stubRefPlnrMUsergroup;
	uint ixVState;
	string srefIxVState;
	string titIxVState;
	uint ixPlnrVLocale;
	string srefIxPlnrVLocale;
	string titIxPlnrVLocale;
	uint ixPlnrVUserlevel;
	string srefIxPlnrVUserlevel;
	string titIxPlnrVUserlevel;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListPlnrQUsrList: recordset of TblPlnrQUsrList
  */
class ListPlnrQUsrList {

public:
	ListPlnrQUsrList();
	ListPlnrQUsrList(const ListPlnrQUsrList& src);
	~ListPlnrQUsrList();

	void clear();
	unsigned int size() const;
	void append(PlnrQUsrList* rec);

	ListPlnrQUsrList& operator=(const ListPlnrQUsrList& src);

public:
	vector<PlnrQUsrList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblPlnrQUsrList: C++ wrapper for table TblPlnrQUsrList
  */
class TblPlnrQUsrList {

public:
	TblPlnrQUsrList();
	virtual ~TblPlnrQUsrList();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrQUsrList** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQUsrList& rst);

	virtual void insertRec(PlnrQUsrList* rec);
	ubigint insertNewRec(PlnrQUsrList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const ubigint refPlnrMPerson = 0, const string stubRefPlnrMPerson = "", const string sref = "", const ubigint refPlnrMUsergroup = 0, const string stubRefPlnrMUsergroup = "", const uint ixVState = 0, const string srefIxVState = "", const string titIxVState = "", const uint ixPlnrVLocale = 0, const string srefIxPlnrVLocale = "", const string titIxPlnrVLocale = "", const uint ixPlnrVUserlevel = 0, const string srefIxPlnrVUserlevel = "", const string titIxPlnrVUserlevel = "");
	ubigint appendNewRecToRst(ListPlnrQUsrList& rst, PlnrQUsrList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const ubigint refPlnrMPerson = 0, const string stubRefPlnrMPerson = "", const string sref = "", const ubigint refPlnrMUsergroup = 0, const string stubRefPlnrMUsergroup = "", const uint ixVState = 0, const string srefIxVState = "", const string titIxVState = "", const uint ixPlnrVLocale = 0, const string srefIxPlnrVLocale = "", const string titIxPlnrVLocale = "", const uint ixPlnrVUserlevel = 0, const string srefIxPlnrVUserlevel = "", const string titIxPlnrVUserlevel = "");
	virtual void insertRst(ListPlnrQUsrList& rst);
	virtual void updateRec(PlnrQUsrList* rec);
	virtual void updateRst(ListPlnrQUsrList& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, PlnrQUsrList** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQUsrList& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrQUsrList: C++ wrapper for table TblPlnrQUsrList (MySQL database)
  */
class MyTblPlnrQUsrList : public TblPlnrQUsrList, public MyTable {

public:
	MyTblPlnrQUsrList();
	~MyTblPlnrQUsrList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQUsrList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQUsrList& rst);

	void insertRec(PlnrQUsrList* rec);
	void insertRst(ListPlnrQUsrList& rst);
	void updateRec(PlnrQUsrList* rec);
	void updateRst(ListPlnrQUsrList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQUsrList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQUsrList& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrQUsrList: C++ wrapper for table TblPlnrQUsrList (PgSQL database)
  */
class PgTblPlnrQUsrList : public TblPlnrQUsrList, public PgTable {

public:
	PgTblPlnrQUsrList();
	~PgTblPlnrQUsrList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrQUsrList** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrQUsrList& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrQUsrList** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrQUsrList& rst);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQUsrList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQUsrList& rst);

	void insertRec(PlnrQUsrList* rec);
	void insertRst(ListPlnrQUsrList& rst);
	void updateRec(PlnrQUsrList* rec);
	void updateRst(ListPlnrQUsrList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQUsrList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQUsrList& rst);
};
// IP pgTbl --- END

#endif

