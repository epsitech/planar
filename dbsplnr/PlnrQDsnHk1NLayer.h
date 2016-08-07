/**
  * \file PlnrQDsnHk1NLayer.h
  * Dbs and XML wrapper for table TblPlnrQDsnHk1NLayer (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQDSNHK1NLAYER_H
#define PLNRQDSNHK1NLAYER_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQDsnHk1NLayer: record of TblPlnrQDsnHk1NLayer
  */
class PlnrQDsnHk1NLayer {

public:
	PlnrQDsnHk1NLayer(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "", const uint hkNum = 0);

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
  * ListPlnrQDsnHk1NLayer: recordset of TblPlnrQDsnHk1NLayer
  */
class ListPlnrQDsnHk1NLayer {

public:
	ListPlnrQDsnHk1NLayer();
	ListPlnrQDsnHk1NLayer(const ListPlnrQDsnHk1NLayer& src);
	~ListPlnrQDsnHk1NLayer();

	void clear();
	unsigned int size() const;
	void append(PlnrQDsnHk1NLayer* rec);

	ListPlnrQDsnHk1NLayer& operator=(const ListPlnrQDsnHk1NLayer& src);

public:
	vector<PlnrQDsnHk1NLayer*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblPlnrQDsnHk1NLayer: C++ wrapper for table TblPlnrQDsnHk1NLayer
  */
class TblPlnrQDsnHk1NLayer {

public:
	TblPlnrQDsnHk1NLayer();
	virtual ~TblPlnrQDsnHk1NLayer();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrQDsnHk1NLayer** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQDsnHk1NLayer& rst);

	virtual void insertRec(PlnrQDsnHk1NLayer* rec);
	ubigint insertNewRec(PlnrQDsnHk1NLayer** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "", const uint hkNum = 0);
	ubigint appendNewRecToRst(ListPlnrQDsnHk1NLayer& rst, PlnrQDsnHk1NLayer** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "", const uint hkNum = 0);
	virtual void insertRst(ListPlnrQDsnHk1NLayer& rst);
	virtual void updateRec(PlnrQDsnHk1NLayer* rec);
	virtual void updateRst(ListPlnrQDsnHk1NLayer& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, PlnrQDsnHk1NLayer** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQDsnHk1NLayer& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrQDsnHk1NLayer: C++ wrapper for table TblPlnrQDsnHk1NLayer (MySQL database)
  */
class MyTblPlnrQDsnHk1NLayer : public TblPlnrQDsnHk1NLayer, public MyTable {

public:
	MyTblPlnrQDsnHk1NLayer();
	~MyTblPlnrQDsnHk1NLayer();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQDsnHk1NLayer** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQDsnHk1NLayer& rst);

	void insertRec(PlnrQDsnHk1NLayer* rec);
	void insertRst(ListPlnrQDsnHk1NLayer& rst);
	void updateRec(PlnrQDsnHk1NLayer* rec);
	void updateRst(ListPlnrQDsnHk1NLayer& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQDsnHk1NLayer** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQDsnHk1NLayer& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrQDsnHk1NLayer: C++ wrapper for table TblPlnrQDsnHk1NLayer (PgSQL database)
  */
class PgTblPlnrQDsnHk1NLayer : public TblPlnrQDsnHk1NLayer, public PgTable {

public:
	PgTblPlnrQDsnHk1NLayer();
	~PgTblPlnrQDsnHk1NLayer();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrQDsnHk1NLayer** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrQDsnHk1NLayer& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrQDsnHk1NLayer** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrQDsnHk1NLayer& rst);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQDsnHk1NLayer** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQDsnHk1NLayer& rst);

	void insertRec(PlnrQDsnHk1NLayer* rec);
	void insertRst(ListPlnrQDsnHk1NLayer& rst);
	void updateRec(PlnrQDsnHk1NLayer* rec);
	void updateRst(ListPlnrQDsnHk1NLayer& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQDsnHk1NLayer** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQDsnHk1NLayer& rst);
};
// IP pgTbl --- END

#endif

