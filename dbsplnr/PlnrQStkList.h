/**
  * \file PlnrQStkList.h
  * Dbs and XML wrapper for table TblPlnrQStkList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQSTKLIST_H
#define PLNRQSTKLIST_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQStkList: record of TblPlnrQStkList
  */
class PlnrQStkList {

public:
	PlnrQStkList(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string sref = "", const uint ixVBasetype = 0, const string srefIxVBasetype = "", const string titIxVBasetype = "", const ubigint dsnRefPlnrMDesign = 0, const string stubDsnRefPlnrMDesign = "", const uint ixVModtype = 0, const string srefIxVModtype = "", const string titIxVModtype = "", const uint ixVFlrAligntype = 0, const string srefIxVFlrAligntype = "", const string titIxVFlrAligntype = "", const uint ixVCeilAligntype = 0, const string srefIxVCeilAligntype = "", const string titIxVCeilAligntype = "");

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
	uint ixVModtype;
	string srefIxVModtype;
	string titIxVModtype;
	uint ixVFlrAligntype;
	string srefIxVFlrAligntype;
	string titIxVFlrAligntype;
	uint ixVCeilAligntype;
	string srefIxVCeilAligntype;
	string titIxVCeilAligntype;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListPlnrQStkList: recordset of TblPlnrQStkList
  */
class ListPlnrQStkList {

public:
	ListPlnrQStkList();
	ListPlnrQStkList(const ListPlnrQStkList& src);
	~ListPlnrQStkList();

	void clear();
	unsigned int size() const;
	void append(PlnrQStkList* rec);

	ListPlnrQStkList& operator=(const ListPlnrQStkList& src);

public:
	vector<PlnrQStkList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblPlnrQStkList: C++ wrapper for table TblPlnrQStkList
  */
class TblPlnrQStkList {

public:
	TblPlnrQStkList();
	virtual ~TblPlnrQStkList();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrQStkList** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQStkList& rst);

	virtual void insertRec(PlnrQStkList* rec);
	ubigint insertNewRec(PlnrQStkList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string sref = "", const uint ixVBasetype = 0, const string srefIxVBasetype = "", const string titIxVBasetype = "", const ubigint dsnRefPlnrMDesign = 0, const string stubDsnRefPlnrMDesign = "", const uint ixVModtype = 0, const string srefIxVModtype = "", const string titIxVModtype = "", const uint ixVFlrAligntype = 0, const string srefIxVFlrAligntype = "", const string titIxVFlrAligntype = "", const uint ixVCeilAligntype = 0, const string srefIxVCeilAligntype = "", const string titIxVCeilAligntype = "");
	ubigint appendNewRecToRst(ListPlnrQStkList& rst, PlnrQStkList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string sref = "", const uint ixVBasetype = 0, const string srefIxVBasetype = "", const string titIxVBasetype = "", const ubigint dsnRefPlnrMDesign = 0, const string stubDsnRefPlnrMDesign = "", const uint ixVModtype = 0, const string srefIxVModtype = "", const string titIxVModtype = "", const uint ixVFlrAligntype = 0, const string srefIxVFlrAligntype = "", const string titIxVFlrAligntype = "", const uint ixVCeilAligntype = 0, const string srefIxVCeilAligntype = "", const string titIxVCeilAligntype = "");
	virtual void insertRst(ListPlnrQStkList& rst);
	virtual void updateRec(PlnrQStkList* rec);
	virtual void updateRst(ListPlnrQStkList& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, PlnrQStkList** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQStkList& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrQStkList: C++ wrapper for table TblPlnrQStkList (MySQL database)
  */
class MyTblPlnrQStkList : public TblPlnrQStkList, public MyTable {

public:
	MyTblPlnrQStkList();
	~MyTblPlnrQStkList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQStkList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQStkList& rst);

	void insertRec(PlnrQStkList* rec);
	void insertRst(ListPlnrQStkList& rst);
	void updateRec(PlnrQStkList* rec);
	void updateRst(ListPlnrQStkList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQStkList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQStkList& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrQStkList: C++ wrapper for table TblPlnrQStkList (PgSQL database)
  */
class PgTblPlnrQStkList : public TblPlnrQStkList, public PgTable {

public:
	PgTblPlnrQStkList();
	~PgTblPlnrQStkList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrQStkList** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrQStkList& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrQStkList** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrQStkList& rst);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQStkList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQStkList& rst);

	void insertRec(PlnrQStkList* rec);
	void insertRst(ListPlnrQStkList& rst);
	void updateRec(PlnrQStkList* rec);
	void updateRst(ListPlnrQStkList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQStkList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQStkList& rst);
};
// IP pgTbl --- END

#endif

