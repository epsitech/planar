/**
  * \file PlnrQCliRef1NFile.h
  * Dbs and XML wrapper for table TblPlnrQCliRef1NFile (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQCLIREF1NFILE_H
#define PLNRQCLIREF1NFILE_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQCliRef1NFile: record of TblPlnrQCliRef1NFile
  */
class PlnrQCliRef1NFile {

public:
	PlnrQCliRef1NFile(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");

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
  * ListPlnrQCliRef1NFile: recordset of TblPlnrQCliRef1NFile
  */
class ListPlnrQCliRef1NFile {

public:
	ListPlnrQCliRef1NFile();
	ListPlnrQCliRef1NFile(const ListPlnrQCliRef1NFile& src);
	~ListPlnrQCliRef1NFile();

	void clear();
	unsigned int size() const;
	void append(PlnrQCliRef1NFile* rec);

	ListPlnrQCliRef1NFile& operator=(const ListPlnrQCliRef1NFile& src);

public:
	vector<PlnrQCliRef1NFile*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblPlnrQCliRef1NFile: C++ wrapper for table TblPlnrQCliRef1NFile
  */
class TblPlnrQCliRef1NFile {

public:
	TblPlnrQCliRef1NFile();
	virtual ~TblPlnrQCliRef1NFile();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrQCliRef1NFile** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQCliRef1NFile& rst);

	virtual void insertRec(PlnrQCliRef1NFile* rec);
	ubigint insertNewRec(PlnrQCliRef1NFile** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	ubigint appendNewRecToRst(ListPlnrQCliRef1NFile& rst, PlnrQCliRef1NFile** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	virtual void insertRst(ListPlnrQCliRef1NFile& rst);
	virtual void updateRec(PlnrQCliRef1NFile* rec);
	virtual void updateRst(ListPlnrQCliRef1NFile& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, PlnrQCliRef1NFile** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQCliRef1NFile& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrQCliRef1NFile: C++ wrapper for table TblPlnrQCliRef1NFile (MySQL database)
  */
class MyTblPlnrQCliRef1NFile : public TblPlnrQCliRef1NFile, public MyTable {

public:
	MyTblPlnrQCliRef1NFile();
	~MyTblPlnrQCliRef1NFile();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQCliRef1NFile** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQCliRef1NFile& rst);

	void insertRec(PlnrQCliRef1NFile* rec);
	void insertRst(ListPlnrQCliRef1NFile& rst);
	void updateRec(PlnrQCliRef1NFile* rec);
	void updateRst(ListPlnrQCliRef1NFile& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQCliRef1NFile** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQCliRef1NFile& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrQCliRef1NFile: C++ wrapper for table TblPlnrQCliRef1NFile (PgSQL database)
  */
class PgTblPlnrQCliRef1NFile : public TblPlnrQCliRef1NFile, public PgTable {

public:
	PgTblPlnrQCliRef1NFile();
	~PgTblPlnrQCliRef1NFile();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrQCliRef1NFile** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrQCliRef1NFile& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrQCliRef1NFile** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrQCliRef1NFile& rst);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQCliRef1NFile** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQCliRef1NFile& rst);

	void insertRec(PlnrQCliRef1NFile* rec);
	void insertRst(ListPlnrQCliRef1NFile& rst);
	void updateRec(PlnrQCliRef1NFile* rec);
	void updateRst(ListPlnrQCliRef1NFile& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQCliRef1NFile** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQCliRef1NFile& rst);
};
// IP pgTbl --- END

#endif

