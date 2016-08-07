/**
  * \file PlnrQClcList.h
  * Dbs and XML wrapper for table TblPlnrQClcList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQCLCLIST_H
#define PLNRQCLCLIST_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQClcList: record of TblPlnrQClcList
  */
class PlnrQClcList {

public:
	PlnrQClcList(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string Title = "", const ubigint refPlnrMProject = 0, const string stubRefPlnrMProject = "", const uint ixVDim = 0, const string srefIxVDim = "", const string titIxVDim = "", const ubigint tplRefPlnrMCalc = 0, const string stubTplRefPlnrMCalc = "", const ubigint supRefPlnrMCalc = 0, const string stubSupRefPlnrMCalc = "", const ubigint refPlnrMDesign = 0, const string stubRefPlnrMDesign = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	string Title;
	ubigint refPlnrMProject;
	string stubRefPlnrMProject;
	uint ixVDim;
	string srefIxVDim;
	string titIxVDim;
	ubigint tplRefPlnrMCalc;
	string stubTplRefPlnrMCalc;
	ubigint supRefPlnrMCalc;
	string stubSupRefPlnrMCalc;
	ubigint refPlnrMDesign;
	string stubRefPlnrMDesign;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListPlnrQClcList: recordset of TblPlnrQClcList
  */
class ListPlnrQClcList {

public:
	ListPlnrQClcList();
	ListPlnrQClcList(const ListPlnrQClcList& src);
	~ListPlnrQClcList();

	void clear();
	unsigned int size() const;
	void append(PlnrQClcList* rec);

	ListPlnrQClcList& operator=(const ListPlnrQClcList& src);

public:
	vector<PlnrQClcList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblPlnrQClcList: C++ wrapper for table TblPlnrQClcList
  */
class TblPlnrQClcList {

public:
	TblPlnrQClcList();
	virtual ~TblPlnrQClcList();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrQClcList** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQClcList& rst);

	virtual void insertRec(PlnrQClcList* rec);
	ubigint insertNewRec(PlnrQClcList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string Title = "", const ubigint refPlnrMProject = 0, const string stubRefPlnrMProject = "", const uint ixVDim = 0, const string srefIxVDim = "", const string titIxVDim = "", const ubigint tplRefPlnrMCalc = 0, const string stubTplRefPlnrMCalc = "", const ubigint supRefPlnrMCalc = 0, const string stubSupRefPlnrMCalc = "", const ubigint refPlnrMDesign = 0, const string stubRefPlnrMDesign = "");
	ubigint appendNewRecToRst(ListPlnrQClcList& rst, PlnrQClcList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string Title = "", const ubigint refPlnrMProject = 0, const string stubRefPlnrMProject = "", const uint ixVDim = 0, const string srefIxVDim = "", const string titIxVDim = "", const ubigint tplRefPlnrMCalc = 0, const string stubTplRefPlnrMCalc = "", const ubigint supRefPlnrMCalc = 0, const string stubSupRefPlnrMCalc = "", const ubigint refPlnrMDesign = 0, const string stubRefPlnrMDesign = "");
	virtual void insertRst(ListPlnrQClcList& rst);
	virtual void updateRec(PlnrQClcList* rec);
	virtual void updateRst(ListPlnrQClcList& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, PlnrQClcList** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQClcList& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrQClcList: C++ wrapper for table TblPlnrQClcList (MySQL database)
  */
class MyTblPlnrQClcList : public TblPlnrQClcList, public MyTable {

public:
	MyTblPlnrQClcList();
	~MyTblPlnrQClcList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQClcList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQClcList& rst);

	void insertRec(PlnrQClcList* rec);
	void insertRst(ListPlnrQClcList& rst);
	void updateRec(PlnrQClcList* rec);
	void updateRst(ListPlnrQClcList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQClcList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQClcList& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrQClcList: C++ wrapper for table TblPlnrQClcList (PgSQL database)
  */
class PgTblPlnrQClcList : public TblPlnrQClcList, public PgTable {

public:
	PgTblPlnrQClcList();
	~PgTblPlnrQClcList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrQClcList** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrQClcList& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrQClcList** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrQClcList& rst);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQClcList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQClcList& rst);

	void insertRec(PlnrQClcList* rec);
	void insertRst(ListPlnrQClcList& rst);
	void updateRec(PlnrQClcList* rec);
	void updateRst(ListPlnrQClcList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQClcList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQClcList& rst);
};
// IP pgTbl --- END

#endif

