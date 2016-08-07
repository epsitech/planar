/**
  * \file PlnrQStkHk1NLayer.h
  * Dbs and XML wrapper for table TblPlnrQStkHk1NLayer (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQSTKHK1NLAYER_H
#define PLNRQSTKHK1NLAYER_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQStkHk1NLayer: record of TblPlnrQStkHk1NLayer
  */
class PlnrQStkHk1NLayer {

public:
	PlnrQStkHk1NLayer(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "", const uint hkNum = 0);

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	string stubRef;
	uint hkNum;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListPlnrQStkHk1NLayer: recordset of TblPlnrQStkHk1NLayer
  */
class ListPlnrQStkHk1NLayer {

public:
	ListPlnrQStkHk1NLayer();
	ListPlnrQStkHk1NLayer(const ListPlnrQStkHk1NLayer& src);
	~ListPlnrQStkHk1NLayer();

	void clear();
	unsigned int size() const;
	void append(PlnrQStkHk1NLayer* rec);

	ListPlnrQStkHk1NLayer& operator=(const ListPlnrQStkHk1NLayer& src);

public:
	vector<PlnrQStkHk1NLayer*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblPlnrQStkHk1NLayer: C++ wrapper for table TblPlnrQStkHk1NLayer
  */
class TblPlnrQStkHk1NLayer {

public:
	TblPlnrQStkHk1NLayer();
	virtual ~TblPlnrQStkHk1NLayer();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrQStkHk1NLayer** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQStkHk1NLayer& rst);

	virtual void insertRec(PlnrQStkHk1NLayer* rec);
	ubigint insertNewRec(PlnrQStkHk1NLayer** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "", const uint hkNum = 0);
	ubigint appendNewRecToRst(ListPlnrQStkHk1NLayer& rst, PlnrQStkHk1NLayer** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "", const uint hkNum = 0);
	virtual void insertRst(ListPlnrQStkHk1NLayer& rst);
	virtual void updateRec(PlnrQStkHk1NLayer* rec);
	virtual void updateRst(ListPlnrQStkHk1NLayer& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, PlnrQStkHk1NLayer** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQStkHk1NLayer& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrQStkHk1NLayer: C++ wrapper for table TblPlnrQStkHk1NLayer (MySQL database)
  */
class MyTblPlnrQStkHk1NLayer : public TblPlnrQStkHk1NLayer, public MyTable {

public:
	MyTblPlnrQStkHk1NLayer();
	~MyTblPlnrQStkHk1NLayer();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQStkHk1NLayer** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQStkHk1NLayer& rst);

	void insertRec(PlnrQStkHk1NLayer* rec);
	void insertRst(ListPlnrQStkHk1NLayer& rst);
	void updateRec(PlnrQStkHk1NLayer* rec);
	void updateRst(ListPlnrQStkHk1NLayer& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQStkHk1NLayer** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQStkHk1NLayer& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrQStkHk1NLayer: C++ wrapper for table TblPlnrQStkHk1NLayer (PgSQL database)
  */
class PgTblPlnrQStkHk1NLayer : public TblPlnrQStkHk1NLayer, public PgTable {

public:
	PgTblPlnrQStkHk1NLayer();
	~PgTblPlnrQStkHk1NLayer();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrQStkHk1NLayer** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrQStkHk1NLayer& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrQStkHk1NLayer** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrQStkHk1NLayer& rst);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQStkHk1NLayer** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQStkHk1NLayer& rst);

	void insertRec(PlnrQStkHk1NLayer* rec);
	void insertRst(ListPlnrQStkHk1NLayer& rst);
	void updateRec(PlnrQStkHk1NLayer* rec);
	void updateRst(ListPlnrQStkHk1NLayer& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQStkHk1NLayer** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQStkHk1NLayer& rst);
};
// IP pgTbl --- END

#endif

