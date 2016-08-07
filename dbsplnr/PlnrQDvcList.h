/**
  * \file PlnrQDvcList.h
  * Dbs and XML wrapper for table TblPlnrQDvcList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQDVCLIST_H
#define PLNRQDVCLIST_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQDvcList: record of TblPlnrQDvcList
  */
class PlnrQDvcList {

public:
	PlnrQDvcList(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string sref = "", const ubigint dsnRefPlnrMDesign = 0, const string stubDsnRefPlnrMDesign = "", const ubigint supRefPlnrMDevice = 0, const string stubSupRefPlnrMDevice = "", const ubigint tplRefPlnrMDevice = 0, const string stubTplRefPlnrMDevice = "", const uint ixVModtype = 0, const string srefIxVModtype = "", const string titIxVModtype = "", const uint ixVAligntype = 0, const string srefIxVAligntype = "", const string titIxVAligntype = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	string sref;
	ubigint dsnRefPlnrMDesign;
	string stubDsnRefPlnrMDesign;
	ubigint supRefPlnrMDevice;
	string stubSupRefPlnrMDevice;
	ubigint tplRefPlnrMDevice;
	string stubTplRefPlnrMDevice;
	uint ixVModtype;
	string srefIxVModtype;
	string titIxVModtype;
	uint ixVAligntype;
	string srefIxVAligntype;
	string titIxVAligntype;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListPlnrQDvcList: recordset of TblPlnrQDvcList
  */
class ListPlnrQDvcList {

public:
	ListPlnrQDvcList();
	ListPlnrQDvcList(const ListPlnrQDvcList& src);
	~ListPlnrQDvcList();

	void clear();
	unsigned int size() const;
	void append(PlnrQDvcList* rec);

	ListPlnrQDvcList& operator=(const ListPlnrQDvcList& src);

public:
	vector<PlnrQDvcList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblPlnrQDvcList: C++ wrapper for table TblPlnrQDvcList
  */
class TblPlnrQDvcList {

public:
	TblPlnrQDvcList();
	virtual ~TblPlnrQDvcList();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrQDvcList** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQDvcList& rst);

	virtual void insertRec(PlnrQDvcList* rec);
	ubigint insertNewRec(PlnrQDvcList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string sref = "", const ubigint dsnRefPlnrMDesign = 0, const string stubDsnRefPlnrMDesign = "", const ubigint supRefPlnrMDevice = 0, const string stubSupRefPlnrMDevice = "", const ubigint tplRefPlnrMDevice = 0, const string stubTplRefPlnrMDevice = "", const uint ixVModtype = 0, const string srefIxVModtype = "", const string titIxVModtype = "", const uint ixVAligntype = 0, const string srefIxVAligntype = "", const string titIxVAligntype = "");
	ubigint appendNewRecToRst(ListPlnrQDvcList& rst, PlnrQDvcList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string sref = "", const ubigint dsnRefPlnrMDesign = 0, const string stubDsnRefPlnrMDesign = "", const ubigint supRefPlnrMDevice = 0, const string stubSupRefPlnrMDevice = "", const ubigint tplRefPlnrMDevice = 0, const string stubTplRefPlnrMDevice = "", const uint ixVModtype = 0, const string srefIxVModtype = "", const string titIxVModtype = "", const uint ixVAligntype = 0, const string srefIxVAligntype = "", const string titIxVAligntype = "");
	virtual void insertRst(ListPlnrQDvcList& rst);
	virtual void updateRec(PlnrQDvcList* rec);
	virtual void updateRst(ListPlnrQDvcList& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, PlnrQDvcList** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQDvcList& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrQDvcList: C++ wrapper for table TblPlnrQDvcList (MySQL database)
  */
class MyTblPlnrQDvcList : public TblPlnrQDvcList, public MyTable {

public:
	MyTblPlnrQDvcList();
	~MyTblPlnrQDvcList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQDvcList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQDvcList& rst);

	void insertRec(PlnrQDvcList* rec);
	void insertRst(ListPlnrQDvcList& rst);
	void updateRec(PlnrQDvcList* rec);
	void updateRst(ListPlnrQDvcList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQDvcList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQDvcList& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrQDvcList: C++ wrapper for table TblPlnrQDvcList (PgSQL database)
  */
class PgTblPlnrQDvcList : public TblPlnrQDvcList, public PgTable {

public:
	PgTblPlnrQDvcList();
	~PgTblPlnrQDvcList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrQDvcList** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrQDvcList& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrQDvcList** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrQDvcList& rst);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQDvcList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQDvcList& rst);

	void insertRec(PlnrQDvcList* rec);
	void insertRst(ListPlnrQDvcList& rst);
	void updateRec(PlnrQDvcList* rec);
	void updateRst(ListPlnrQDvcList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQDvcList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQDvcList& rst);
};
// IP pgTbl --- END

#endif

