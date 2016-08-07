/**
  * \file PlnrQDsnMod1NDesign.h
  * Dbs and XML wrapper for table TblPlnrQDsnMod1NDesign (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQDSNMOD1NDESIGN_H
#define PLNRQDSNMOD1NDESIGN_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQDsnMod1NDesign: record of TblPlnrQDsnMod1NDesign
  */
class PlnrQDsnMod1NDesign {

public:
	PlnrQDsnMod1NDesign(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");

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
  * ListPlnrQDsnMod1NDesign: recordset of TblPlnrQDsnMod1NDesign
  */
class ListPlnrQDsnMod1NDesign {

public:
	ListPlnrQDsnMod1NDesign();
	ListPlnrQDsnMod1NDesign(const ListPlnrQDsnMod1NDesign& src);
	~ListPlnrQDsnMod1NDesign();

	void clear();
	unsigned int size() const;
	void append(PlnrQDsnMod1NDesign* rec);

	ListPlnrQDsnMod1NDesign& operator=(const ListPlnrQDsnMod1NDesign& src);

public:
	vector<PlnrQDsnMod1NDesign*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblPlnrQDsnMod1NDesign: C++ wrapper for table TblPlnrQDsnMod1NDesign
  */
class TblPlnrQDsnMod1NDesign {

public:
	TblPlnrQDsnMod1NDesign();
	virtual ~TblPlnrQDsnMod1NDesign();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrQDsnMod1NDesign** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQDsnMod1NDesign& rst);

	virtual void insertRec(PlnrQDsnMod1NDesign* rec);
	ubigint insertNewRec(PlnrQDsnMod1NDesign** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	ubigint appendNewRecToRst(ListPlnrQDsnMod1NDesign& rst, PlnrQDsnMod1NDesign** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	virtual void insertRst(ListPlnrQDsnMod1NDesign& rst);
	virtual void updateRec(PlnrQDsnMod1NDesign* rec);
	virtual void updateRst(ListPlnrQDsnMod1NDesign& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, PlnrQDsnMod1NDesign** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQDsnMod1NDesign& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrQDsnMod1NDesign: C++ wrapper for table TblPlnrQDsnMod1NDesign (MySQL database)
  */
class MyTblPlnrQDsnMod1NDesign : public TblPlnrQDsnMod1NDesign, public MyTable {

public:
	MyTblPlnrQDsnMod1NDesign();
	~MyTblPlnrQDsnMod1NDesign();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQDsnMod1NDesign** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQDsnMod1NDesign& rst);

	void insertRec(PlnrQDsnMod1NDesign* rec);
	void insertRst(ListPlnrQDsnMod1NDesign& rst);
	void updateRec(PlnrQDsnMod1NDesign* rec);
	void updateRst(ListPlnrQDsnMod1NDesign& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQDsnMod1NDesign** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQDsnMod1NDesign& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrQDsnMod1NDesign: C++ wrapper for table TblPlnrQDsnMod1NDesign (PgSQL database)
  */
class PgTblPlnrQDsnMod1NDesign : public TblPlnrQDsnMod1NDesign, public PgTable {

public:
	PgTblPlnrQDsnMod1NDesign();
	~PgTblPlnrQDsnMod1NDesign();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrQDsnMod1NDesign** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrQDsnMod1NDesign& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrQDsnMod1NDesign** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrQDsnMod1NDesign& rst);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQDsnMod1NDesign** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQDsnMod1NDesign& rst);

	void insertRec(PlnrQDsnMod1NDesign* rec);
	void insertRst(ListPlnrQDsnMod1NDesign& rst);
	void updateRec(PlnrQDsnMod1NDesign* rec);
	void updateRst(ListPlnrQDsnMod1NDesign& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQDsnMod1NDesign** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQDsnMod1NDesign& rst);
};
// IP pgTbl --- END

#endif

