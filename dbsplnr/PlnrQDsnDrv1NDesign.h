/**
  * \file PlnrQDsnDrv1NDesign.h
  * Dbs and XML wrapper for table TblPlnrQDsnDrv1NDesign (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQDSNDRV1NDESIGN_H
#define PLNRQDSNDRV1NDESIGN_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQDsnDrv1NDesign: record of TblPlnrQDsnDrv1NDesign
  */
class PlnrQDsnDrv1NDesign {

public:
	PlnrQDsnDrv1NDesign(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	string stubRef;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListPlnrQDsnDrv1NDesign: recordset of TblPlnrQDsnDrv1NDesign
  */
class ListPlnrQDsnDrv1NDesign {

public:
	ListPlnrQDsnDrv1NDesign();
	ListPlnrQDsnDrv1NDesign(const ListPlnrQDsnDrv1NDesign& src);
	~ListPlnrQDsnDrv1NDesign();

	void clear();
	unsigned int size() const;
	void append(PlnrQDsnDrv1NDesign* rec);

	ListPlnrQDsnDrv1NDesign& operator=(const ListPlnrQDsnDrv1NDesign& src);

public:
	vector<PlnrQDsnDrv1NDesign*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblPlnrQDsnDrv1NDesign: C++ wrapper for table TblPlnrQDsnDrv1NDesign
  */
class TblPlnrQDsnDrv1NDesign {

public:
	TblPlnrQDsnDrv1NDesign();
	virtual ~TblPlnrQDsnDrv1NDesign();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrQDsnDrv1NDesign** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQDsnDrv1NDesign& rst);

	virtual void insertRec(PlnrQDsnDrv1NDesign* rec);
	ubigint insertNewRec(PlnrQDsnDrv1NDesign** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	ubigint appendNewRecToRst(ListPlnrQDsnDrv1NDesign& rst, PlnrQDsnDrv1NDesign** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	virtual void insertRst(ListPlnrQDsnDrv1NDesign& rst);
	virtual void updateRec(PlnrQDsnDrv1NDesign* rec);
	virtual void updateRst(ListPlnrQDsnDrv1NDesign& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, PlnrQDsnDrv1NDesign** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQDsnDrv1NDesign& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrQDsnDrv1NDesign: C++ wrapper for table TblPlnrQDsnDrv1NDesign (MySQL database)
  */
class MyTblPlnrQDsnDrv1NDesign : public TblPlnrQDsnDrv1NDesign, public MyTable {

public:
	MyTblPlnrQDsnDrv1NDesign();
	~MyTblPlnrQDsnDrv1NDesign();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQDsnDrv1NDesign** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQDsnDrv1NDesign& rst);

	void insertRec(PlnrQDsnDrv1NDesign* rec);
	void insertRst(ListPlnrQDsnDrv1NDesign& rst);
	void updateRec(PlnrQDsnDrv1NDesign* rec);
	void updateRst(ListPlnrQDsnDrv1NDesign& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQDsnDrv1NDesign** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQDsnDrv1NDesign& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrQDsnDrv1NDesign: C++ wrapper for table TblPlnrQDsnDrv1NDesign (PgSQL database)
  */
class PgTblPlnrQDsnDrv1NDesign : public TblPlnrQDsnDrv1NDesign, public PgTable {

public:
	PgTblPlnrQDsnDrv1NDesign();
	~PgTblPlnrQDsnDrv1NDesign();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrQDsnDrv1NDesign** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrQDsnDrv1NDesign& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrQDsnDrv1NDesign** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrQDsnDrv1NDesign& rst);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQDsnDrv1NDesign** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQDsnDrv1NDesign& rst);

	void insertRec(PlnrQDsnDrv1NDesign* rec);
	void insertRst(ListPlnrQDsnDrv1NDesign& rst);
	void updateRec(PlnrQDsnDrv1NDesign* rec);
	void updateRst(ListPlnrQDsnDrv1NDesign& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQDsnDrv1NDesign** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQDsnDrv1NDesign& rst);
};
// IP pgTbl --- END

#endif

