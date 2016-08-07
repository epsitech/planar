/**
  * \file PlnrQDomList.h
  * Dbs and XML wrapper for table TblPlnrQDomList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQDOMLIST_H
#define PLNRQDOMLIST_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQDomList: record of TblPlnrQDomList
  */
class PlnrQDomList {

public:
	PlnrQDomList(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string sref = "", const uint ixVBasetype = 0, const string srefIxVBasetype = "", const string titIxVBasetype = "", const ubigint dsnRefPlnrMDesign = 0, const string stubDsnRefPlnrMDesign = "");

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
  * ListPlnrQDomList: recordset of TblPlnrQDomList
  */
class ListPlnrQDomList {

public:
	ListPlnrQDomList();
	ListPlnrQDomList(const ListPlnrQDomList& src);
	~ListPlnrQDomList();

	void clear();
	unsigned int size() const;
	void append(PlnrQDomList* rec);

	ListPlnrQDomList& operator=(const ListPlnrQDomList& src);

public:
	vector<PlnrQDomList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblPlnrQDomList: C++ wrapper for table TblPlnrQDomList
  */
class TblPlnrQDomList {

public:
	TblPlnrQDomList();
	virtual ~TblPlnrQDomList();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrQDomList** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQDomList& rst);

	virtual void insertRec(PlnrQDomList* rec);
	ubigint insertNewRec(PlnrQDomList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string sref = "", const uint ixVBasetype = 0, const string srefIxVBasetype = "", const string titIxVBasetype = "", const ubigint dsnRefPlnrMDesign = 0, const string stubDsnRefPlnrMDesign = "");
	ubigint appendNewRecToRst(ListPlnrQDomList& rst, PlnrQDomList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string sref = "", const uint ixVBasetype = 0, const string srefIxVBasetype = "", const string titIxVBasetype = "", const ubigint dsnRefPlnrMDesign = 0, const string stubDsnRefPlnrMDesign = "");
	virtual void insertRst(ListPlnrQDomList& rst);
	virtual void updateRec(PlnrQDomList* rec);
	virtual void updateRst(ListPlnrQDomList& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, PlnrQDomList** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQDomList& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrQDomList: C++ wrapper for table TblPlnrQDomList (MySQL database)
  */
class MyTblPlnrQDomList : public TblPlnrQDomList, public MyTable {

public:
	MyTblPlnrQDomList();
	~MyTblPlnrQDomList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQDomList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQDomList& rst);

	void insertRec(PlnrQDomList* rec);
	void insertRst(ListPlnrQDomList& rst);
	void updateRec(PlnrQDomList* rec);
	void updateRst(ListPlnrQDomList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQDomList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQDomList& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrQDomList: C++ wrapper for table TblPlnrQDomList (PgSQL database)
  */
class PgTblPlnrQDomList : public TblPlnrQDomList, public PgTable {

public:
	PgTblPlnrQDomList();
	~PgTblPlnrQDomList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrQDomList** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrQDomList& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrQDomList** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrQDomList& rst);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQDomList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQDomList& rst);

	void insertRec(PlnrQDomList* rec);
	void insertRst(ListPlnrQDomList& rst);
	void updateRec(PlnrQDomList* rec);
	void updateRst(ListPlnrQDomList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQDomList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQDomList& rst);
};
// IP pgTbl --- END

#endif

