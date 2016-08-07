/**
  * \file PlnrQTpoMNProject.h
  * Dbs and XML wrapper for table TblPlnrQTpoMNProject (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQTPOMNPROJECT_H
#define PLNRQTPOMNPROJECT_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQTpoMNProject: record of TblPlnrQTpoMNProject
  */
class PlnrQTpoMNProject {

public:
	PlnrQTpoMNProject(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0);

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
  * ListPlnrQTpoMNProject: recordset of TblPlnrQTpoMNProject
  */
class ListPlnrQTpoMNProject {

public:
	ListPlnrQTpoMNProject();
	ListPlnrQTpoMNProject(const ListPlnrQTpoMNProject& src);
	~ListPlnrQTpoMNProject();

	void clear();
	unsigned int size() const;
	void append(PlnrQTpoMNProject* rec);

	ListPlnrQTpoMNProject& operator=(const ListPlnrQTpoMNProject& src);

public:
	vector<PlnrQTpoMNProject*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblPlnrQTpoMNProject: C++ wrapper for table TblPlnrQTpoMNProject
  */
class TblPlnrQTpoMNProject {

public:
	TblPlnrQTpoMNProject();
	virtual ~TblPlnrQTpoMNProject();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrQTpoMNProject** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQTpoMNProject& rst);

	virtual void insertRec(PlnrQTpoMNProject* rec);
	ubigint insertNewRec(PlnrQTpoMNProject** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0);
	ubigint appendNewRecToRst(ListPlnrQTpoMNProject& rst, PlnrQTpoMNProject** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0);
	virtual void insertRst(ListPlnrQTpoMNProject& rst);
	virtual void updateRec(PlnrQTpoMNProject* rec);
	virtual void updateRst(ListPlnrQTpoMNProject& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, PlnrQTpoMNProject** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQTpoMNProject& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrQTpoMNProject: C++ wrapper for table TblPlnrQTpoMNProject (MySQL database)
  */
class MyTblPlnrQTpoMNProject : public TblPlnrQTpoMNProject, public MyTable {

public:
	MyTblPlnrQTpoMNProject();
	~MyTblPlnrQTpoMNProject();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQTpoMNProject** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQTpoMNProject& rst);

	void insertRec(PlnrQTpoMNProject* rec);
	void insertRst(ListPlnrQTpoMNProject& rst);
	void updateRec(PlnrQTpoMNProject* rec);
	void updateRst(ListPlnrQTpoMNProject& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQTpoMNProject** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQTpoMNProject& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrQTpoMNProject: C++ wrapper for table TblPlnrQTpoMNProject (PgSQL database)
  */
class PgTblPlnrQTpoMNProject : public TblPlnrQTpoMNProject, public PgTable {

public:
	PgTblPlnrQTpoMNProject();
	~PgTblPlnrQTpoMNProject();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrQTpoMNProject** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrQTpoMNProject& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrQTpoMNProject** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrQTpoMNProject& rst);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQTpoMNProject** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQTpoMNProject& rst);

	void insertRec(PlnrQTpoMNProject* rec);
	void insertRst(ListPlnrQTpoMNProject& rst);
	void updateRec(PlnrQTpoMNProject* rec);
	void updateRst(ListPlnrQTpoMNProject& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQTpoMNProject** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQTpoMNProject& rst);
};
// IP pgTbl --- END

#endif

