/**
  * \file PlnrQLyrList.h
  * Dbs and XML wrapper for table TblPlnrQLyrList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQLYRLIST_H
#define PLNRQLYRLIST_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQLyrList: record of TblPlnrQLyrList
  */
class PlnrQLyrList {

public:
	PlnrQLyrList(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string sref = "", const ubigint x1RefPlnrMDesign = 0, const uint ixVBasetype = 0, const string srefIxVBasetype = "", const string titIxVBasetype = "", const uint hkIxVTbl = 0, const string srefHkIxVTbl = "", const string titHkIxVTbl = "", const ubigint hkUref = 0, const string stubHkUref = "", const ubigint refPlnrMMaterial = 0, const string stubRefPlnrMMaterial = "", const uint ixVTtype = 0, const string srefIxVTtype = "", const string titIxVTtype = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	string sref;
	ubigint x1RefPlnrMDesign;
	uint ixVBasetype;
	string srefIxVBasetype;
	string titIxVBasetype;
	uint hkIxVTbl;
	string srefHkIxVTbl;
	string titHkIxVTbl;
	ubigint hkUref;
	string stubHkUref;
	ubigint refPlnrMMaterial;
	string stubRefPlnrMMaterial;
	uint ixVTtype;
	string srefIxVTtype;
	string titIxVTtype;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListPlnrQLyrList: recordset of TblPlnrQLyrList
  */
class ListPlnrQLyrList {

public:
	ListPlnrQLyrList();
	ListPlnrQLyrList(const ListPlnrQLyrList& src);
	~ListPlnrQLyrList();

	void clear();
	unsigned int size() const;
	void append(PlnrQLyrList* rec);

	ListPlnrQLyrList& operator=(const ListPlnrQLyrList& src);

public:
	vector<PlnrQLyrList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblPlnrQLyrList: C++ wrapper for table TblPlnrQLyrList
  */
class TblPlnrQLyrList {

public:
	TblPlnrQLyrList();
	virtual ~TblPlnrQLyrList();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrQLyrList** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQLyrList& rst);

	virtual void insertRec(PlnrQLyrList* rec);
	ubigint insertNewRec(PlnrQLyrList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string sref = "", const ubigint x1RefPlnrMDesign = 0, const uint ixVBasetype = 0, const string srefIxVBasetype = "", const string titIxVBasetype = "", const uint hkIxVTbl = 0, const string srefHkIxVTbl = "", const string titHkIxVTbl = "", const ubigint hkUref = 0, const string stubHkUref = "", const ubigint refPlnrMMaterial = 0, const string stubRefPlnrMMaterial = "", const uint ixVTtype = 0, const string srefIxVTtype = "", const string titIxVTtype = "");
	ubigint appendNewRecToRst(ListPlnrQLyrList& rst, PlnrQLyrList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string sref = "", const ubigint x1RefPlnrMDesign = 0, const uint ixVBasetype = 0, const string srefIxVBasetype = "", const string titIxVBasetype = "", const uint hkIxVTbl = 0, const string srefHkIxVTbl = "", const string titHkIxVTbl = "", const ubigint hkUref = 0, const string stubHkUref = "", const ubigint refPlnrMMaterial = 0, const string stubRefPlnrMMaterial = "", const uint ixVTtype = 0, const string srefIxVTtype = "", const string titIxVTtype = "");
	virtual void insertRst(ListPlnrQLyrList& rst);
	virtual void updateRec(PlnrQLyrList* rec);
	virtual void updateRst(ListPlnrQLyrList& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, PlnrQLyrList** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQLyrList& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrQLyrList: C++ wrapper for table TblPlnrQLyrList (MySQL database)
  */
class MyTblPlnrQLyrList : public TblPlnrQLyrList, public MyTable {

public:
	MyTblPlnrQLyrList();
	~MyTblPlnrQLyrList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQLyrList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQLyrList& rst);

	void insertRec(PlnrQLyrList* rec);
	void insertRst(ListPlnrQLyrList& rst);
	void updateRec(PlnrQLyrList* rec);
	void updateRst(ListPlnrQLyrList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQLyrList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQLyrList& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrQLyrList: C++ wrapper for table TblPlnrQLyrList (PgSQL database)
  */
class PgTblPlnrQLyrList : public TblPlnrQLyrList, public PgTable {

public:
	PgTblPlnrQLyrList();
	~PgTblPlnrQLyrList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrQLyrList** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrQLyrList& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrQLyrList** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrQLyrList& rst);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQLyrList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQLyrList& rst);

	void insertRec(PlnrQLyrList* rec);
	void insertRst(ListPlnrQLyrList& rst);
	void updateRec(PlnrQLyrList* rec);
	void updateRst(ListPlnrQLyrList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQLyrList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQLyrList& rst);
};
// IP pgTbl --- END

#endif

