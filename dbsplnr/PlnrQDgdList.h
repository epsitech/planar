/**
  * \file PlnrQDgdList.h
  * Dbs and XML wrapper for table TblPlnrQDgdList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQDGDLIST_H
#define PLNRQDGDLIST_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQDgdList: record of TblPlnrQDgdList
  */
class PlnrQDgdList {

public:
	PlnrQDgdList(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string sref = "", const uint ixVBasetype = 0, const string srefIxVBasetype = "", const string titIxVBasetype = "", const ubigint dsnRefPlnrMDesign = 0, const string stubDsnRefPlnrMDesign = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	string sref;
	uint ixVBasetype;
	string srefIxVBasetype;
	string titIxVBasetype;
	ubigint dsnRefPlnrMDesign;
	string stubDsnRefPlnrMDesign;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListPlnrQDgdList: recordset of TblPlnrQDgdList
  */
class ListPlnrQDgdList {

public:
	ListPlnrQDgdList();
	ListPlnrQDgdList(const ListPlnrQDgdList& src);
	~ListPlnrQDgdList();

	void clear();
	unsigned int size() const;
	void append(PlnrQDgdList* rec);

	ListPlnrQDgdList& operator=(const ListPlnrQDgdList& src);

public:
	vector<PlnrQDgdList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblPlnrQDgdList: C++ wrapper for table TblPlnrQDgdList
  */
class TblPlnrQDgdList {

public:
	TblPlnrQDgdList();
	virtual ~TblPlnrQDgdList();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrQDgdList** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQDgdList& rst);

	virtual void insertRec(PlnrQDgdList* rec);
	ubigint insertNewRec(PlnrQDgdList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string sref = "", const uint ixVBasetype = 0, const string srefIxVBasetype = "", const string titIxVBasetype = "", const ubigint dsnRefPlnrMDesign = 0, const string stubDsnRefPlnrMDesign = "");
	ubigint appendNewRecToRst(ListPlnrQDgdList& rst, PlnrQDgdList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string sref = "", const uint ixVBasetype = 0, const string srefIxVBasetype = "", const string titIxVBasetype = "", const ubigint dsnRefPlnrMDesign = 0, const string stubDsnRefPlnrMDesign = "");
	virtual void insertRst(ListPlnrQDgdList& rst);
	virtual void updateRec(PlnrQDgdList* rec);
	virtual void updateRst(ListPlnrQDgdList& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, PlnrQDgdList** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQDgdList& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrQDgdList: C++ wrapper for table TblPlnrQDgdList (MySQL database)
  */
class MyTblPlnrQDgdList : public TblPlnrQDgdList, public MyTable {

public:
	MyTblPlnrQDgdList();
	~MyTblPlnrQDgdList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQDgdList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQDgdList& rst);

	void insertRec(PlnrQDgdList* rec);
	void insertRst(ListPlnrQDgdList& rst);
	void updateRec(PlnrQDgdList* rec);
	void updateRst(ListPlnrQDgdList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQDgdList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQDgdList& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrQDgdList: C++ wrapper for table TblPlnrQDgdList (PgSQL database)
  */
class PgTblPlnrQDgdList : public TblPlnrQDgdList, public PgTable {

public:
	PgTblPlnrQDgdList();
	~PgTblPlnrQDgdList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrQDgdList** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrQDgdList& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrQDgdList** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrQDgdList& rst);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQDgdList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQDgdList& rst);

	void insertRec(PlnrQDgdList* rec);
	void insertRst(ListPlnrQDgdList& rst);
	void updateRec(PlnrQDgdList* rec);
	void updateRst(ListPlnrQDgdList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQDgdList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQDgdList& rst);
};
// IP pgTbl --- END

#endif

