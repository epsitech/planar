/**
  * \file PlnrQClcMNFile.h
  * Dbs and XML wrapper for table TblPlnrQClcMNFile (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQCLCMNFILE_H
#define PLNRQCLCMNFILE_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQClcMNFile: record of TblPlnrQClcMNFile
  */
class PlnrQClcMNFile {

public:
	PlnrQClcMNFile(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const ubigint x1RefPlnrMCalcitem = 0, const string stubX1RefPlnrMCalcitem = "", const uint ixVIo = 0, const string srefIxVIo = "", const string titIxVIo = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint mref;
	string stubMref;
	ubigint ref;
	ubigint x1RefPlnrMCalcitem;
	string stubX1RefPlnrMCalcitem;
	uint ixVIo;
	string srefIxVIo;
	string titIxVIo;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListPlnrQClcMNFile: recordset of TblPlnrQClcMNFile
  */
class ListPlnrQClcMNFile {

public:
	ListPlnrQClcMNFile();
	ListPlnrQClcMNFile(const ListPlnrQClcMNFile& src);
	~ListPlnrQClcMNFile();

	void clear();
	unsigned int size() const;
	void append(PlnrQClcMNFile* rec);

	ListPlnrQClcMNFile& operator=(const ListPlnrQClcMNFile& src);

public:
	vector<PlnrQClcMNFile*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblPlnrQClcMNFile: C++ wrapper for table TblPlnrQClcMNFile
  */
class TblPlnrQClcMNFile {

public:
	TblPlnrQClcMNFile();
	virtual ~TblPlnrQClcMNFile();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrQClcMNFile** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQClcMNFile& rst);

	virtual void insertRec(PlnrQClcMNFile* rec);
	ubigint insertNewRec(PlnrQClcMNFile** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const ubigint x1RefPlnrMCalcitem = 0, const string stubX1RefPlnrMCalcitem = "", const uint ixVIo = 0, const string srefIxVIo = "", const string titIxVIo = "");
	ubigint appendNewRecToRst(ListPlnrQClcMNFile& rst, PlnrQClcMNFile** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const ubigint x1RefPlnrMCalcitem = 0, const string stubX1RefPlnrMCalcitem = "", const uint ixVIo = 0, const string srefIxVIo = "", const string titIxVIo = "");
	virtual void insertRst(ListPlnrQClcMNFile& rst);
	virtual void updateRec(PlnrQClcMNFile* rec);
	virtual void updateRst(ListPlnrQClcMNFile& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, PlnrQClcMNFile** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQClcMNFile& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrQClcMNFile: C++ wrapper for table TblPlnrQClcMNFile (MySQL database)
  */
class MyTblPlnrQClcMNFile : public TblPlnrQClcMNFile, public MyTable {

public:
	MyTblPlnrQClcMNFile();
	~MyTblPlnrQClcMNFile();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQClcMNFile** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQClcMNFile& rst);

	void insertRec(PlnrQClcMNFile* rec);
	void insertRst(ListPlnrQClcMNFile& rst);
	void updateRec(PlnrQClcMNFile* rec);
	void updateRst(ListPlnrQClcMNFile& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQClcMNFile** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQClcMNFile& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrQClcMNFile: C++ wrapper for table TblPlnrQClcMNFile (PgSQL database)
  */
class PgTblPlnrQClcMNFile : public TblPlnrQClcMNFile, public PgTable {

public:
	PgTblPlnrQClcMNFile();
	~PgTblPlnrQClcMNFile();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrQClcMNFile** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrQClcMNFile& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrQClcMNFile** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrQClcMNFile& rst);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQClcMNFile** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQClcMNFile& rst);

	void insertRec(PlnrQClcMNFile* rec);
	void insertRst(ListPlnrQClcMNFile& rst);
	void updateRec(PlnrQClcMNFile* rec);
	void updateRst(ListPlnrQClcMNFile& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQClcMNFile** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQClcMNFile& rst);
};
// IP pgTbl --- END

#endif

