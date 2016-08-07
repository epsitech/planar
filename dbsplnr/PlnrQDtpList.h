/**
  * \file PlnrQDtpList.h
  * Dbs and XML wrapper for table TblPlnrQDtpList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQDTPLIST_H
#define PLNRQDTPLIST_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQDtpList: record of TblPlnrQDtpList
  */
class PlnrQDtpList {

public:
	PlnrQDtpList(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string sref = "", const ubigint supRefPlnrMDevice = 0, const string stubSupRefPlnrMDevice = "", const uint ixVAligntype = 0);

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	string sref;
	ubigint supRefPlnrMDevice;
	string stubSupRefPlnrMDevice;
	uint ixVAligntype;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListPlnrQDtpList: recordset of TblPlnrQDtpList
  */
class ListPlnrQDtpList {

public:
	ListPlnrQDtpList();
	ListPlnrQDtpList(const ListPlnrQDtpList& src);
	~ListPlnrQDtpList();

	void clear();
	unsigned int size() const;
	void append(PlnrQDtpList* rec);

	ListPlnrQDtpList& operator=(const ListPlnrQDtpList& src);

public:
	vector<PlnrQDtpList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblPlnrQDtpList: C++ wrapper for table TblPlnrQDtpList
  */
class TblPlnrQDtpList {

public:
	TblPlnrQDtpList();
	virtual ~TblPlnrQDtpList();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrQDtpList** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQDtpList& rst);

	virtual void insertRec(PlnrQDtpList* rec);
	ubigint insertNewRec(PlnrQDtpList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string sref = "", const ubigint supRefPlnrMDevice = 0, const string stubSupRefPlnrMDevice = "", const uint ixVAligntype = 0);
	ubigint appendNewRecToRst(ListPlnrQDtpList& rst, PlnrQDtpList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string sref = "", const ubigint supRefPlnrMDevice = 0, const string stubSupRefPlnrMDevice = "", const uint ixVAligntype = 0);
	virtual void insertRst(ListPlnrQDtpList& rst);
	virtual void updateRec(PlnrQDtpList* rec);
	virtual void updateRst(ListPlnrQDtpList& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, PlnrQDtpList** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQDtpList& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrQDtpList: C++ wrapper for table TblPlnrQDtpList (MySQL database)
  */
class MyTblPlnrQDtpList : public TblPlnrQDtpList, public MyTable {

public:
	MyTblPlnrQDtpList();
	~MyTblPlnrQDtpList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQDtpList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQDtpList& rst);

	void insertRec(PlnrQDtpList* rec);
	void insertRst(ListPlnrQDtpList& rst);
	void updateRec(PlnrQDtpList* rec);
	void updateRst(ListPlnrQDtpList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQDtpList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQDtpList& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrQDtpList: C++ wrapper for table TblPlnrQDtpList (PgSQL database)
  */
class PgTblPlnrQDtpList : public TblPlnrQDtpList, public PgTable {

public:
	PgTblPlnrQDtpList();
	~PgTblPlnrQDtpList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrQDtpList** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrQDtpList& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrQDtpList** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrQDtpList& rst);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQDtpList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQDtpList& rst);

	void insertRec(PlnrQDtpList* rec);
	void insertRst(ListPlnrQDtpList& rst);
	void updateRec(PlnrQDtpList* rec);
	void updateRst(ListPlnrQDtpList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQDtpList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQDtpList& rst);
};
// IP pgTbl --- END

#endif

