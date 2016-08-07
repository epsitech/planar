/**
  * \file PlnrQMat1NLayer.h
  * Dbs and XML wrapper for table TblPlnrQMat1NLayer (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQMAT1NLAYER_H
#define PLNRQMAT1NLAYER_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQMat1NLayer: record of TblPlnrQMat1NLayer
  */
class PlnrQMat1NLayer {

public:
	PlnrQMat1NLayer(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");

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
  * ListPlnrQMat1NLayer: recordset of TblPlnrQMat1NLayer
  */
class ListPlnrQMat1NLayer {

public:
	ListPlnrQMat1NLayer();
	ListPlnrQMat1NLayer(const ListPlnrQMat1NLayer& src);
	~ListPlnrQMat1NLayer();

	void clear();
	unsigned int size() const;
	void append(PlnrQMat1NLayer* rec);

	ListPlnrQMat1NLayer& operator=(const ListPlnrQMat1NLayer& src);

public:
	vector<PlnrQMat1NLayer*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblPlnrQMat1NLayer: C++ wrapper for table TblPlnrQMat1NLayer
  */
class TblPlnrQMat1NLayer {

public:
	TblPlnrQMat1NLayer();
	virtual ~TblPlnrQMat1NLayer();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrQMat1NLayer** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQMat1NLayer& rst);

	virtual void insertRec(PlnrQMat1NLayer* rec);
	ubigint insertNewRec(PlnrQMat1NLayer** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	ubigint appendNewRecToRst(ListPlnrQMat1NLayer& rst, PlnrQMat1NLayer** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	virtual void insertRst(ListPlnrQMat1NLayer& rst);
	virtual void updateRec(PlnrQMat1NLayer* rec);
	virtual void updateRst(ListPlnrQMat1NLayer& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, PlnrQMat1NLayer** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQMat1NLayer& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrQMat1NLayer: C++ wrapper for table TblPlnrQMat1NLayer (MySQL database)
  */
class MyTblPlnrQMat1NLayer : public TblPlnrQMat1NLayer, public MyTable {

public:
	MyTblPlnrQMat1NLayer();
	~MyTblPlnrQMat1NLayer();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQMat1NLayer** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQMat1NLayer& rst);

	void insertRec(PlnrQMat1NLayer* rec);
	void insertRst(ListPlnrQMat1NLayer& rst);
	void updateRec(PlnrQMat1NLayer* rec);
	void updateRst(ListPlnrQMat1NLayer& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQMat1NLayer** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQMat1NLayer& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrQMat1NLayer: C++ wrapper for table TblPlnrQMat1NLayer (PgSQL database)
  */
class PgTblPlnrQMat1NLayer : public TblPlnrQMat1NLayer, public PgTable {

public:
	PgTblPlnrQMat1NLayer();
	~PgTblPlnrQMat1NLayer();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrQMat1NLayer** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrQMat1NLayer& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrQMat1NLayer** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrQMat1NLayer& rst);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQMat1NLayer** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQMat1NLayer& rst);

	void insertRec(PlnrQMat1NLayer* rec);
	void insertRst(ListPlnrQMat1NLayer& rst);
	void updateRec(PlnrQMat1NLayer* rec);
	void updateRst(ListPlnrQMat1NLayer& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQMat1NLayer** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQMat1NLayer& rst);
};
// IP pgTbl --- END

#endif

