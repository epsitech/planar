/**
  * \file PlnrQPrj1NDesign.h
  * Dbs and XML wrapper for table TblPlnrQPrj1NDesign (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQPRJ1NDESIGN_H
#define PLNRQPRJ1NDESIGN_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQPrj1NDesign: record of TblPlnrQPrj1NDesign
  */
class PlnrQPrj1NDesign {

public:
	PlnrQPrj1NDesign(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");

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
  * ListPlnrQPrj1NDesign: recordset of TblPlnrQPrj1NDesign
  */
class ListPlnrQPrj1NDesign {

public:
	ListPlnrQPrj1NDesign();
	ListPlnrQPrj1NDesign(const ListPlnrQPrj1NDesign& src);
	~ListPlnrQPrj1NDesign();

	void clear();
	unsigned int size() const;
	void append(PlnrQPrj1NDesign* rec);

	ListPlnrQPrj1NDesign& operator=(const ListPlnrQPrj1NDesign& src);

public:
	vector<PlnrQPrj1NDesign*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblPlnrQPrj1NDesign: C++ wrapper for table TblPlnrQPrj1NDesign
  */
class TblPlnrQPrj1NDesign {

public:
	TblPlnrQPrj1NDesign();
	virtual ~TblPlnrQPrj1NDesign();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrQPrj1NDesign** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQPrj1NDesign& rst);

	virtual void insertRec(PlnrQPrj1NDesign* rec);
	ubigint insertNewRec(PlnrQPrj1NDesign** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	ubigint appendNewRecToRst(ListPlnrQPrj1NDesign& rst, PlnrQPrj1NDesign** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	virtual void insertRst(ListPlnrQPrj1NDesign& rst);
	virtual void updateRec(PlnrQPrj1NDesign* rec);
	virtual void updateRst(ListPlnrQPrj1NDesign& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, PlnrQPrj1NDesign** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQPrj1NDesign& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrQPrj1NDesign: C++ wrapper for table TblPlnrQPrj1NDesign (MySQL database)
  */
class MyTblPlnrQPrj1NDesign : public TblPlnrQPrj1NDesign, public MyTable {

public:
	MyTblPlnrQPrj1NDesign();
	~MyTblPlnrQPrj1NDesign();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQPrj1NDesign** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQPrj1NDesign& rst);

	void insertRec(PlnrQPrj1NDesign* rec);
	void insertRst(ListPlnrQPrj1NDesign& rst);
	void updateRec(PlnrQPrj1NDesign* rec);
	void updateRst(ListPlnrQPrj1NDesign& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQPrj1NDesign** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQPrj1NDesign& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrQPrj1NDesign: C++ wrapper for table TblPlnrQPrj1NDesign (PgSQL database)
  */
class PgTblPlnrQPrj1NDesign : public TblPlnrQPrj1NDesign, public PgTable {

public:
	PgTblPlnrQPrj1NDesign();
	~PgTblPlnrQPrj1NDesign();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrQPrj1NDesign** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrQPrj1NDesign& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrQPrj1NDesign** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrQPrj1NDesign& rst);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQPrj1NDesign** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQPrj1NDesign& rst);

	void insertRec(PlnrQPrj1NDesign* rec);
	void insertRst(ListPlnrQPrj1NDesign& rst);
	void updateRec(PlnrQPrj1NDesign* rec);
	void updateRst(ListPlnrQPrj1NDesign& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQPrj1NDesign** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQPrj1NDesign& rst);
};
// IP pgTbl --- END

#endif

