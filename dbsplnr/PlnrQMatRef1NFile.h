/**
  * \file PlnrQMatRef1NFile.h
  * Dbs and XML wrapper for table TblPlnrQMatRef1NFile (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQMATREF1NFILE_H
#define PLNRQMATREF1NFILE_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQMatRef1NFile: record of TblPlnrQMatRef1NFile
  */
class PlnrQMatRef1NFile {

public:
	PlnrQMatRef1NFile(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");

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
  * ListPlnrQMatRef1NFile: recordset of TblPlnrQMatRef1NFile
  */
class ListPlnrQMatRef1NFile {

public:
	ListPlnrQMatRef1NFile();
	ListPlnrQMatRef1NFile(const ListPlnrQMatRef1NFile& src);
	~ListPlnrQMatRef1NFile();

	void clear();
	unsigned int size() const;
	void append(PlnrQMatRef1NFile* rec);

	ListPlnrQMatRef1NFile& operator=(const ListPlnrQMatRef1NFile& src);

public:
	vector<PlnrQMatRef1NFile*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblPlnrQMatRef1NFile: C++ wrapper for table TblPlnrQMatRef1NFile
  */
class TblPlnrQMatRef1NFile {

public:
	TblPlnrQMatRef1NFile();
	virtual ~TblPlnrQMatRef1NFile();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrQMatRef1NFile** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQMatRef1NFile& rst);

	virtual void insertRec(PlnrQMatRef1NFile* rec);
	ubigint insertNewRec(PlnrQMatRef1NFile** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	ubigint appendNewRecToRst(ListPlnrQMatRef1NFile& rst, PlnrQMatRef1NFile** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	virtual void insertRst(ListPlnrQMatRef1NFile& rst);
	virtual void updateRec(PlnrQMatRef1NFile* rec);
	virtual void updateRst(ListPlnrQMatRef1NFile& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, PlnrQMatRef1NFile** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQMatRef1NFile& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrQMatRef1NFile: C++ wrapper for table TblPlnrQMatRef1NFile (MySQL database)
  */
class MyTblPlnrQMatRef1NFile : public TblPlnrQMatRef1NFile, public MyTable {

public:
	MyTblPlnrQMatRef1NFile();
	~MyTblPlnrQMatRef1NFile();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQMatRef1NFile** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQMatRef1NFile& rst);

	void insertRec(PlnrQMatRef1NFile* rec);
	void insertRst(ListPlnrQMatRef1NFile& rst);
	void updateRec(PlnrQMatRef1NFile* rec);
	void updateRst(ListPlnrQMatRef1NFile& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQMatRef1NFile** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQMatRef1NFile& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrQMatRef1NFile: C++ wrapper for table TblPlnrQMatRef1NFile (PgSQL database)
  */
class PgTblPlnrQMatRef1NFile : public TblPlnrQMatRef1NFile, public PgTable {

public:
	PgTblPlnrQMatRef1NFile();
	~PgTblPlnrQMatRef1NFile();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrQMatRef1NFile** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrQMatRef1NFile& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrQMatRef1NFile** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrQMatRef1NFile& rst);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQMatRef1NFile** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQMatRef1NFile& rst);

	void insertRec(PlnrQMatRef1NFile* rec);
	void insertRst(ListPlnrQMatRef1NFile& rst);
	void updateRec(PlnrQMatRef1NFile* rec);
	void updateRst(ListPlnrQMatRef1NFile& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQMatRef1NFile** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQMatRef1NFile& rst);
};
// IP pgTbl --- END

#endif

