/**
  * \file PlnrQPrsList.h
  * Dbs and XML wrapper for table TblPlnrQPrsList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQPRSLIST_H
#define PLNRQPRSLIST_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQPrsList: record of TblPlnrQPrsList
  */
class PlnrQPrsList {

public:
	PlnrQPrsList(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string Title = "", const string Firstname = "", const string Lastname = "", const ubigint grp = 0, const string stubGrp = "", const ubigint own = 0, const string stubOwn = "", const uint ixVSex = 0, const string srefIxVSex = "", const string titIxVSex = "", const string Tel = "", const string Eml = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	string Title;
	string Firstname;
	string Lastname;
	ubigint grp;
	string stubGrp;
	ubigint own;
	string stubOwn;
	uint ixVSex;
	string srefIxVSex;
	string titIxVSex;
	string Tel;
	string Eml;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListPlnrQPrsList: recordset of TblPlnrQPrsList
  */
class ListPlnrQPrsList {

public:
	ListPlnrQPrsList();
	ListPlnrQPrsList(const ListPlnrQPrsList& src);
	~ListPlnrQPrsList();

	void clear();
	unsigned int size() const;
	void append(PlnrQPrsList* rec);

	ListPlnrQPrsList& operator=(const ListPlnrQPrsList& src);

public:
	vector<PlnrQPrsList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblPlnrQPrsList: C++ wrapper for table TblPlnrQPrsList
  */
class TblPlnrQPrsList {

public:
	TblPlnrQPrsList();
	virtual ~TblPlnrQPrsList();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrQPrsList** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQPrsList& rst);

	virtual void insertRec(PlnrQPrsList* rec);
	ubigint insertNewRec(PlnrQPrsList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string Title = "", const string Firstname = "", const string Lastname = "", const ubigint grp = 0, const string stubGrp = "", const ubigint own = 0, const string stubOwn = "", const uint ixVSex = 0, const string srefIxVSex = "", const string titIxVSex = "", const string Tel = "", const string Eml = "");
	ubigint appendNewRecToRst(ListPlnrQPrsList& rst, PlnrQPrsList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string Title = "", const string Firstname = "", const string Lastname = "", const ubigint grp = 0, const string stubGrp = "", const ubigint own = 0, const string stubOwn = "", const uint ixVSex = 0, const string srefIxVSex = "", const string titIxVSex = "", const string Tel = "", const string Eml = "");
	virtual void insertRst(ListPlnrQPrsList& rst);
	virtual void updateRec(PlnrQPrsList* rec);
	virtual void updateRst(ListPlnrQPrsList& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, PlnrQPrsList** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQPrsList& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrQPrsList: C++ wrapper for table TblPlnrQPrsList (MySQL database)
  */
class MyTblPlnrQPrsList : public TblPlnrQPrsList, public MyTable {

public:
	MyTblPlnrQPrsList();
	~MyTblPlnrQPrsList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQPrsList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQPrsList& rst);

	void insertRec(PlnrQPrsList* rec);
	void insertRst(ListPlnrQPrsList& rst);
	void updateRec(PlnrQPrsList* rec);
	void updateRst(ListPlnrQPrsList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQPrsList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQPrsList& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrQPrsList: C++ wrapper for table TblPlnrQPrsList (PgSQL database)
  */
class PgTblPlnrQPrsList : public TblPlnrQPrsList, public PgTable {

public:
	PgTblPlnrQPrsList();
	~PgTblPlnrQPrsList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrQPrsList** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrQPrsList& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrQPrsList** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrQPrsList& rst);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQPrsList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQPrsList& rst);

	void insertRec(PlnrQPrsList* rec);
	void insertRst(ListPlnrQPrsList& rst);
	void updateRec(PlnrQPrsList* rec);
	void updateRst(ListPlnrQPrsList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQPrsList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQPrsList& rst);
};
// IP pgTbl --- END

#endif

