/**
  * \file PlnrQClc1NMaterial.h
  * Dbs and XML wrapper for table TblPlnrQClc1NMaterial (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQCLC1NMATERIAL_H
#define PLNRQCLC1NMATERIAL_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQClc1NMaterial: record of TblPlnrQClc1NMaterial
  */
class PlnrQClc1NMaterial {

public:
	PlnrQClc1NMaterial(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");

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
  * ListPlnrQClc1NMaterial: recordset of TblPlnrQClc1NMaterial
  */
class ListPlnrQClc1NMaterial {

public:
	ListPlnrQClc1NMaterial();
	ListPlnrQClc1NMaterial(const ListPlnrQClc1NMaterial& src);
	~ListPlnrQClc1NMaterial();

	void clear();
	unsigned int size() const;
	void append(PlnrQClc1NMaterial* rec);

	ListPlnrQClc1NMaterial& operator=(const ListPlnrQClc1NMaterial& src);

public:
	vector<PlnrQClc1NMaterial*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblPlnrQClc1NMaterial: C++ wrapper for table TblPlnrQClc1NMaterial
  */
class TblPlnrQClc1NMaterial {

public:
	TblPlnrQClc1NMaterial();
	virtual ~TblPlnrQClc1NMaterial();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrQClc1NMaterial** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQClc1NMaterial& rst);

	virtual void insertRec(PlnrQClc1NMaterial* rec);
	ubigint insertNewRec(PlnrQClc1NMaterial** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	ubigint appendNewRecToRst(ListPlnrQClc1NMaterial& rst, PlnrQClc1NMaterial** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	virtual void insertRst(ListPlnrQClc1NMaterial& rst);
	virtual void updateRec(PlnrQClc1NMaterial* rec);
	virtual void updateRst(ListPlnrQClc1NMaterial& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, PlnrQClc1NMaterial** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQClc1NMaterial& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrQClc1NMaterial: C++ wrapper for table TblPlnrQClc1NMaterial (MySQL database)
  */
class MyTblPlnrQClc1NMaterial : public TblPlnrQClc1NMaterial, public MyTable {

public:
	MyTblPlnrQClc1NMaterial();
	~MyTblPlnrQClc1NMaterial();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQClc1NMaterial** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQClc1NMaterial& rst);

	void insertRec(PlnrQClc1NMaterial* rec);
	void insertRst(ListPlnrQClc1NMaterial& rst);
	void updateRec(PlnrQClc1NMaterial* rec);
	void updateRst(ListPlnrQClc1NMaterial& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQClc1NMaterial** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQClc1NMaterial& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrQClc1NMaterial: C++ wrapper for table TblPlnrQClc1NMaterial (PgSQL database)
  */
class PgTblPlnrQClc1NMaterial : public TblPlnrQClc1NMaterial, public PgTable {

public:
	PgTblPlnrQClc1NMaterial();
	~PgTblPlnrQClc1NMaterial();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrQClc1NMaterial** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrQClc1NMaterial& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrQClc1NMaterial** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrQClc1NMaterial& rst);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQClc1NMaterial** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQClc1NMaterial& rst);

	void insertRec(PlnrQClc1NMaterial* rec);
	void insertRst(ListPlnrQClc1NMaterial& rst);
	void updateRec(PlnrQClc1NMaterial* rec);
	void updateRst(ListPlnrQClc1NMaterial& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQClc1NMaterial** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQClc1NMaterial& rst);
};
// IP pgTbl --- END

#endif

