/**
  * \file PlnrQCliAAMCalcEnv.h
  * Dbs and XML wrapper for table TblPlnrQCliAAMCalcEnv (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQCLIAAMCALCENV_H
#define PLNRQCLIAAMCALCENV_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQCliAAMCalcEnv: record of TblPlnrQCliAAMCalcEnv
  */
class PlnrQCliAAMCalcEnv {

public:
	PlnrQCliAAMCalcEnv(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string x2SrefKKey = "", const string titX2SrefKKey = "", const string Val = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	string x2SrefKKey;
	string titX2SrefKKey;
	string Val;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListPlnrQCliAAMCalcEnv: recordset of TblPlnrQCliAAMCalcEnv
  */
class ListPlnrQCliAAMCalcEnv {

public:
	ListPlnrQCliAAMCalcEnv();
	ListPlnrQCliAAMCalcEnv(const ListPlnrQCliAAMCalcEnv& src);
	~ListPlnrQCliAAMCalcEnv();

	void clear();
	unsigned int size() const;
	void append(PlnrQCliAAMCalcEnv* rec);

	ListPlnrQCliAAMCalcEnv& operator=(const ListPlnrQCliAAMCalcEnv& src);

public:
	vector<PlnrQCliAAMCalcEnv*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblPlnrQCliAAMCalcEnv: C++ wrapper for table TblPlnrQCliAAMCalcEnv
  */
class TblPlnrQCliAAMCalcEnv {

public:
	TblPlnrQCliAAMCalcEnv();
	virtual ~TblPlnrQCliAAMCalcEnv();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrQCliAAMCalcEnv** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQCliAAMCalcEnv& rst);

	virtual void insertRec(PlnrQCliAAMCalcEnv* rec);
	ubigint insertNewRec(PlnrQCliAAMCalcEnv** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string x2SrefKKey = "", const string titX2SrefKKey = "", const string Val = "");
	ubigint appendNewRecToRst(ListPlnrQCliAAMCalcEnv& rst, PlnrQCliAAMCalcEnv** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string x2SrefKKey = "", const string titX2SrefKKey = "", const string Val = "");
	virtual void insertRst(ListPlnrQCliAAMCalcEnv& rst);
	virtual void updateRec(PlnrQCliAAMCalcEnv* rec);
	virtual void updateRst(ListPlnrQCliAAMCalcEnv& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, PlnrQCliAAMCalcEnv** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQCliAAMCalcEnv& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrQCliAAMCalcEnv: C++ wrapper for table TblPlnrQCliAAMCalcEnv (MySQL database)
  */
class MyTblPlnrQCliAAMCalcEnv : public TblPlnrQCliAAMCalcEnv, public MyTable {

public:
	MyTblPlnrQCliAAMCalcEnv();
	~MyTblPlnrQCliAAMCalcEnv();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQCliAAMCalcEnv** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQCliAAMCalcEnv& rst);

	void insertRec(PlnrQCliAAMCalcEnv* rec);
	void insertRst(ListPlnrQCliAAMCalcEnv& rst);
	void updateRec(PlnrQCliAAMCalcEnv* rec);
	void updateRst(ListPlnrQCliAAMCalcEnv& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQCliAAMCalcEnv** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQCliAAMCalcEnv& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrQCliAAMCalcEnv: C++ wrapper for table TblPlnrQCliAAMCalcEnv (PgSQL database)
  */
class PgTblPlnrQCliAAMCalcEnv : public TblPlnrQCliAAMCalcEnv, public PgTable {

public:
	PgTblPlnrQCliAAMCalcEnv();
	~PgTblPlnrQCliAAMCalcEnv();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrQCliAAMCalcEnv** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrQCliAAMCalcEnv& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrQCliAAMCalcEnv** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrQCliAAMCalcEnv& rst);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQCliAAMCalcEnv** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQCliAAMCalcEnv& rst);

	void insertRec(PlnrQCliAAMCalcEnv* rec);
	void insertRst(ListPlnrQCliAAMCalcEnv& rst);
	void updateRec(PlnrQCliAAMCalcEnv* rec);
	void updateRst(ListPlnrQCliAAMCalcEnv& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQCliAAMCalcEnv** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQCliAAMCalcEnv& rst);
};
// IP pgTbl --- END

#endif

