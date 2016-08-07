/**
  * \file PlnrQSruMNLayer.h
  * Dbs and XML wrapper for table TblPlnrQSruMNLayer (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQSRUMNLAYER_H
#define PLNRQSRUMNLAYER_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQSruMNLayer: record of TblPlnrQSruMNLayer
  */
class PlnrQSruMNLayer {

public:
	PlnrQSruMNLayer(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0);

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint mref;
	string stubMref;
	ubigint ref;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListPlnrQSruMNLayer: recordset of TblPlnrQSruMNLayer
  */
class ListPlnrQSruMNLayer {

public:
	ListPlnrQSruMNLayer();
	ListPlnrQSruMNLayer(const ListPlnrQSruMNLayer& src);
	~ListPlnrQSruMNLayer();

	void clear();
	unsigned int size() const;
	void append(PlnrQSruMNLayer* rec);

	ListPlnrQSruMNLayer& operator=(const ListPlnrQSruMNLayer& src);

public:
	vector<PlnrQSruMNLayer*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblPlnrQSruMNLayer: C++ wrapper for table TblPlnrQSruMNLayer
  */
class TblPlnrQSruMNLayer {

public:
	TblPlnrQSruMNLayer();
	virtual ~TblPlnrQSruMNLayer();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrQSruMNLayer** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQSruMNLayer& rst);

	virtual void insertRec(PlnrQSruMNLayer* rec);
	ubigint insertNewRec(PlnrQSruMNLayer** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0);
	ubigint appendNewRecToRst(ListPlnrQSruMNLayer& rst, PlnrQSruMNLayer** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0);
	virtual void insertRst(ListPlnrQSruMNLayer& rst);
	virtual void updateRec(PlnrQSruMNLayer* rec);
	virtual void updateRst(ListPlnrQSruMNLayer& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, PlnrQSruMNLayer** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQSruMNLayer& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrQSruMNLayer: C++ wrapper for table TblPlnrQSruMNLayer (MySQL database)
  */
class MyTblPlnrQSruMNLayer : public TblPlnrQSruMNLayer, public MyTable {

public:
	MyTblPlnrQSruMNLayer();
	~MyTblPlnrQSruMNLayer();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQSruMNLayer** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQSruMNLayer& rst);

	void insertRec(PlnrQSruMNLayer* rec);
	void insertRst(ListPlnrQSruMNLayer& rst);
	void updateRec(PlnrQSruMNLayer* rec);
	void updateRst(ListPlnrQSruMNLayer& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQSruMNLayer** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQSruMNLayer& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrQSruMNLayer: C++ wrapper for table TblPlnrQSruMNLayer (PgSQL database)
  */
class PgTblPlnrQSruMNLayer : public TblPlnrQSruMNLayer, public PgTable {

public:
	PgTblPlnrQSruMNLayer();
	~PgTblPlnrQSruMNLayer();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrQSruMNLayer** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrQSruMNLayer& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrQSruMNLayer** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrQSruMNLayer& rst);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQSruMNLayer** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQSruMNLayer& rst);

	void insertRec(PlnrQSruMNLayer* rec);
	void insertRst(ListPlnrQSruMNLayer& rst);
	void updateRec(PlnrQSruMNLayer* rec);
	void updateRst(ListPlnrQSruMNLayer& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQSruMNLayer** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQSruMNLayer& rst);
};
// IP pgTbl --- END

#endif

