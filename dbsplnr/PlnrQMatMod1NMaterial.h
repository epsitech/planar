/**
  * \file PlnrQMatMod1NMaterial.h
  * Dbs and XML wrapper for table TblPlnrQMatMod1NMaterial (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQMATMOD1NMATERIAL_H
#define PLNRQMATMOD1NMATERIAL_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQMatMod1NMaterial: record of TblPlnrQMatMod1NMaterial
  */
class PlnrQMatMod1NMaterial {

public:
	PlnrQMatMod1NMaterial(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");

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
  * ListPlnrQMatMod1NMaterial: recordset of TblPlnrQMatMod1NMaterial
  */
class ListPlnrQMatMod1NMaterial {

public:
	ListPlnrQMatMod1NMaterial();
	ListPlnrQMatMod1NMaterial(const ListPlnrQMatMod1NMaterial& src);
	~ListPlnrQMatMod1NMaterial();

	void clear();
	unsigned int size() const;
	void append(PlnrQMatMod1NMaterial* rec);

	ListPlnrQMatMod1NMaterial& operator=(const ListPlnrQMatMod1NMaterial& src);

public:
	vector<PlnrQMatMod1NMaterial*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblPlnrQMatMod1NMaterial: C++ wrapper for table TblPlnrQMatMod1NMaterial
  */
class TblPlnrQMatMod1NMaterial {

public:
	TblPlnrQMatMod1NMaterial();
	virtual ~TblPlnrQMatMod1NMaterial();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrQMatMod1NMaterial** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQMatMod1NMaterial& rst);

	virtual void insertRec(PlnrQMatMod1NMaterial* rec);
	ubigint insertNewRec(PlnrQMatMod1NMaterial** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	ubigint appendNewRecToRst(ListPlnrQMatMod1NMaterial& rst, PlnrQMatMod1NMaterial** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	virtual void insertRst(ListPlnrQMatMod1NMaterial& rst);
	virtual void updateRec(PlnrQMatMod1NMaterial* rec);
	virtual void updateRst(ListPlnrQMatMod1NMaterial& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, PlnrQMatMod1NMaterial** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQMatMod1NMaterial& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrQMatMod1NMaterial: C++ wrapper for table TblPlnrQMatMod1NMaterial (MySQL database)
  */
class MyTblPlnrQMatMod1NMaterial : public TblPlnrQMatMod1NMaterial, public MyTable {

public:
	MyTblPlnrQMatMod1NMaterial();
	~MyTblPlnrQMatMod1NMaterial();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQMatMod1NMaterial** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQMatMod1NMaterial& rst);

	void insertRec(PlnrQMatMod1NMaterial* rec);
	void insertRst(ListPlnrQMatMod1NMaterial& rst);
	void updateRec(PlnrQMatMod1NMaterial* rec);
	void updateRst(ListPlnrQMatMod1NMaterial& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQMatMod1NMaterial** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQMatMod1NMaterial& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrQMatMod1NMaterial: C++ wrapper for table TblPlnrQMatMod1NMaterial (PgSQL database)
  */
class PgTblPlnrQMatMod1NMaterial : public TblPlnrQMatMod1NMaterial, public PgTable {

public:
	PgTblPlnrQMatMod1NMaterial();
	~PgTblPlnrQMatMod1NMaterial();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrQMatMod1NMaterial** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrQMatMod1NMaterial& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrQMatMod1NMaterial** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrQMatMod1NMaterial& rst);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQMatMod1NMaterial** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQMatMod1NMaterial& rst);

	void insertRec(PlnrQMatMod1NMaterial* rec);
	void insertRst(ListPlnrQMatMod1NMaterial& rst);
	void updateRec(PlnrQMatMod1NMaterial* rec);
	void updateRst(ListPlnrQMatMod1NMaterial& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQMatMod1NMaterial** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQMatMod1NMaterial& rst);
};
// IP pgTbl --- END

#endif

