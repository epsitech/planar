/**
  * \file PlnrQFilMNCalc.h
  * Dbs and XML wrapper for table TblPlnrQFilMNCalc (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQFILMNCALC_H
#define PLNRQFILMNCALC_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQFilMNCalc: record of TblPlnrQFilMNCalc
  */
class PlnrQFilMNCalc {

public:
	PlnrQFilMNCalc(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const ubigint x1RefPlnrMCalcitem = 0, const string stubX1RefPlnrMCalcitem = "", const uint ixVIo = 0, const string srefIxVIo = "", const string titIxVIo = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint mref;
	string stubMref;
	ubigint ref;
	ubigint x1RefPlnrMCalcitem;
	string stubX1RefPlnrMCalcitem;
	uint ixVIo;
	string srefIxVIo;
	string titIxVIo;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListPlnrQFilMNCalc: recordset of TblPlnrQFilMNCalc
  */
class ListPlnrQFilMNCalc {

public:
	ListPlnrQFilMNCalc();
	ListPlnrQFilMNCalc(const ListPlnrQFilMNCalc& src);
	~ListPlnrQFilMNCalc();

	void clear();
	unsigned int size() const;
	void append(PlnrQFilMNCalc* rec);

	ListPlnrQFilMNCalc& operator=(const ListPlnrQFilMNCalc& src);

public:
	vector<PlnrQFilMNCalc*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblPlnrQFilMNCalc: C++ wrapper for table TblPlnrQFilMNCalc
  */
class TblPlnrQFilMNCalc {

public:
	TblPlnrQFilMNCalc();
	virtual ~TblPlnrQFilMNCalc();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrQFilMNCalc** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQFilMNCalc& rst);

	virtual void insertRec(PlnrQFilMNCalc* rec);
	ubigint insertNewRec(PlnrQFilMNCalc** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const ubigint x1RefPlnrMCalcitem = 0, const string stubX1RefPlnrMCalcitem = "", const uint ixVIo = 0, const string srefIxVIo = "", const string titIxVIo = "");
	ubigint appendNewRecToRst(ListPlnrQFilMNCalc& rst, PlnrQFilMNCalc** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const ubigint x1RefPlnrMCalcitem = 0, const string stubX1RefPlnrMCalcitem = "", const uint ixVIo = 0, const string srefIxVIo = "", const string titIxVIo = "");
	virtual void insertRst(ListPlnrQFilMNCalc& rst);
	virtual void updateRec(PlnrQFilMNCalc* rec);
	virtual void updateRst(ListPlnrQFilMNCalc& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, PlnrQFilMNCalc** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQFilMNCalc& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrQFilMNCalc: C++ wrapper for table TblPlnrQFilMNCalc (MySQL database)
  */
class MyTblPlnrQFilMNCalc : public TblPlnrQFilMNCalc, public MyTable {

public:
	MyTblPlnrQFilMNCalc();
	~MyTblPlnrQFilMNCalc();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQFilMNCalc** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQFilMNCalc& rst);

	void insertRec(PlnrQFilMNCalc* rec);
	void insertRst(ListPlnrQFilMNCalc& rst);
	void updateRec(PlnrQFilMNCalc* rec);
	void updateRst(ListPlnrQFilMNCalc& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQFilMNCalc** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQFilMNCalc& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrQFilMNCalc: C++ wrapper for table TblPlnrQFilMNCalc (PgSQL database)
  */
class PgTblPlnrQFilMNCalc : public TblPlnrQFilMNCalc, public PgTable {

public:
	PgTblPlnrQFilMNCalc();
	~PgTblPlnrQFilMNCalc();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrQFilMNCalc** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrQFilMNCalc& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrQFilMNCalc** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrQFilMNCalc& rst);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQFilMNCalc** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQFilMNCalc& rst);

	void insertRec(PlnrQFilMNCalc* rec);
	void insertRst(ListPlnrQFilMNCalc& rst);
	void updateRec(PlnrQFilMNCalc* rec);
	void updateRst(ListPlnrQFilMNCalc& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQFilMNCalc** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQFilMNCalc& rst);
};
// IP pgTbl --- END

#endif

