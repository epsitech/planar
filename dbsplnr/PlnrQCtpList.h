/**
  * \file PlnrQCtpList.h
  * Dbs and XML wrapper for table TblPlnrQCtpList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQCTPLIST_H
#define PLNRQCTPLIST_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQCtpList: record of TblPlnrQCtpList
  */
class PlnrQCtpList {

public:
	PlnrQCtpList(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string Title = "", const uint ixVDim = 0, const string srefIxVDim = "", const string titIxVDim = "", const ubigint supRefPlnrMCalc = 0, const string stubSupRefPlnrMCalc = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	string Title;
	uint ixVDim;
	string srefIxVDim;
	string titIxVDim;
	ubigint supRefPlnrMCalc;
	string stubSupRefPlnrMCalc;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListPlnrQCtpList: recordset of TblPlnrQCtpList
  */
class ListPlnrQCtpList {

public:
	ListPlnrQCtpList();
	ListPlnrQCtpList(const ListPlnrQCtpList& src);
	~ListPlnrQCtpList();

	void clear();
	unsigned int size() const;
	void append(PlnrQCtpList* rec);

	ListPlnrQCtpList& operator=(const ListPlnrQCtpList& src);

public:
	vector<PlnrQCtpList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblPlnrQCtpList: C++ wrapper for table TblPlnrQCtpList
  */
class TblPlnrQCtpList {

public:
	TblPlnrQCtpList();
	virtual ~TblPlnrQCtpList();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrQCtpList** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQCtpList& rst);

	virtual void insertRec(PlnrQCtpList* rec);
	ubigint insertNewRec(PlnrQCtpList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string Title = "", const uint ixVDim = 0, const string srefIxVDim = "", const string titIxVDim = "", const ubigint supRefPlnrMCalc = 0, const string stubSupRefPlnrMCalc = "");
	ubigint appendNewRecToRst(ListPlnrQCtpList& rst, PlnrQCtpList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string Title = "", const uint ixVDim = 0, const string srefIxVDim = "", const string titIxVDim = "", const ubigint supRefPlnrMCalc = 0, const string stubSupRefPlnrMCalc = "");
	virtual void insertRst(ListPlnrQCtpList& rst);
	virtual void updateRec(PlnrQCtpList* rec);
	virtual void updateRst(ListPlnrQCtpList& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, PlnrQCtpList** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQCtpList& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrQCtpList: C++ wrapper for table TblPlnrQCtpList (MySQL database)
  */
class MyTblPlnrQCtpList : public TblPlnrQCtpList, public MyTable {

public:
	MyTblPlnrQCtpList();
	~MyTblPlnrQCtpList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQCtpList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQCtpList& rst);

	void insertRec(PlnrQCtpList* rec);
	void insertRst(ListPlnrQCtpList& rst);
	void updateRec(PlnrQCtpList* rec);
	void updateRst(ListPlnrQCtpList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQCtpList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQCtpList& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrQCtpList: C++ wrapper for table TblPlnrQCtpList (PgSQL database)
  */
class PgTblPlnrQCtpList : public TblPlnrQCtpList, public PgTable {

public:
	PgTblPlnrQCtpList();
	~PgTblPlnrQCtpList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrQCtpList** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrQCtpList& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrQCtpList** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrQCtpList& rst);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQCtpList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQCtpList& rst);

	void insertRec(PlnrQCtpList* rec);
	void insertRst(ListPlnrQCtpList& rst);
	void updateRec(PlnrQCtpList* rec);
	void updateRst(ListPlnrQCtpList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQCtpList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQCtpList& rst);
};
// IP pgTbl --- END

#endif

