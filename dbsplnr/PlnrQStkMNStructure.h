/**
  * \file PlnrQStkMNStructure.h
  * Dbs and XML wrapper for table TblPlnrQStkMNStructure (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQSTKMNSTRUCTURE_H
#define PLNRQSTKMNSTRUCTURE_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQStkMNStructure: record of TblPlnrQStkMNStructure
  */
class PlnrQStkMNStructure {

public:
	PlnrQStkMNStructure(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const string fromSrefPlnrMLayer = "", const string toSrefPlnrMLayer = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint mref;
	string stubMref;
	ubigint ref;
	string fromSrefPlnrMLayer;
	string toSrefPlnrMLayer;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListPlnrQStkMNStructure: recordset of TblPlnrQStkMNStructure
  */
class ListPlnrQStkMNStructure {

public:
	ListPlnrQStkMNStructure();
	ListPlnrQStkMNStructure(const ListPlnrQStkMNStructure& src);
	~ListPlnrQStkMNStructure();

	void clear();
	unsigned int size() const;
	void append(PlnrQStkMNStructure* rec);

	ListPlnrQStkMNStructure& operator=(const ListPlnrQStkMNStructure& src);

public:
	vector<PlnrQStkMNStructure*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblPlnrQStkMNStructure: C++ wrapper for table TblPlnrQStkMNStructure
  */
class TblPlnrQStkMNStructure {

public:
	TblPlnrQStkMNStructure();
	virtual ~TblPlnrQStkMNStructure();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrQStkMNStructure** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQStkMNStructure& rst);

	virtual void insertRec(PlnrQStkMNStructure* rec);
	ubigint insertNewRec(PlnrQStkMNStructure** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const string fromSrefPlnrMLayer = "", const string toSrefPlnrMLayer = "");
	ubigint appendNewRecToRst(ListPlnrQStkMNStructure& rst, PlnrQStkMNStructure** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const string fromSrefPlnrMLayer = "", const string toSrefPlnrMLayer = "");
	virtual void insertRst(ListPlnrQStkMNStructure& rst);
	virtual void updateRec(PlnrQStkMNStructure* rec);
	virtual void updateRst(ListPlnrQStkMNStructure& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, PlnrQStkMNStructure** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQStkMNStructure& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrQStkMNStructure: C++ wrapper for table TblPlnrQStkMNStructure (MySQL database)
  */
class MyTblPlnrQStkMNStructure : public TblPlnrQStkMNStructure, public MyTable {

public:
	MyTblPlnrQStkMNStructure();
	~MyTblPlnrQStkMNStructure();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQStkMNStructure** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQStkMNStructure& rst);

	void insertRec(PlnrQStkMNStructure* rec);
	void insertRst(ListPlnrQStkMNStructure& rst);
	void updateRec(PlnrQStkMNStructure* rec);
	void updateRst(ListPlnrQStkMNStructure& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQStkMNStructure** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQStkMNStructure& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrQStkMNStructure: C++ wrapper for table TblPlnrQStkMNStructure (PgSQL database)
  */
class PgTblPlnrQStkMNStructure : public TblPlnrQStkMNStructure, public PgTable {

public:
	PgTblPlnrQStkMNStructure();
	~PgTblPlnrQStkMNStructure();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrQStkMNStructure** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrQStkMNStructure& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrQStkMNStructure** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrQStkMNStructure& rst);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQStkMNStructure** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQStkMNStructure& rst);

	void insertRec(PlnrQStkMNStructure* rec);
	void insertRst(ListPlnrQStkMNStructure& rst);
	void updateRec(PlnrQStkMNStructure* rec);
	void updateRst(ListPlnrQStkMNStructure& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQStkMNStructure** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQStkMNStructure& rst);
};
// IP pgTbl --- END

#endif

