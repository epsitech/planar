/**
  * \file PlnrQDsn1NBlock.h
  * Dbs and XML wrapper for table TblPlnrQDsn1NBlock (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQDSN1NBLOCK_H
#define PLNRQDSN1NBLOCK_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQDsn1NBlock: record of TblPlnrQDsn1NBlock
  */
class PlnrQDsn1NBlock {

public:
	PlnrQDsn1NBlock(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");

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
  * ListPlnrQDsn1NBlock: recordset of TblPlnrQDsn1NBlock
  */
class ListPlnrQDsn1NBlock {

public:
	ListPlnrQDsn1NBlock();
	ListPlnrQDsn1NBlock(const ListPlnrQDsn1NBlock& src);
	~ListPlnrQDsn1NBlock();

	void clear();
	unsigned int size() const;
	void append(PlnrQDsn1NBlock* rec);

	ListPlnrQDsn1NBlock& operator=(const ListPlnrQDsn1NBlock& src);

public:
	vector<PlnrQDsn1NBlock*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblPlnrQDsn1NBlock: C++ wrapper for table TblPlnrQDsn1NBlock
  */
class TblPlnrQDsn1NBlock {

public:
	TblPlnrQDsn1NBlock();
	virtual ~TblPlnrQDsn1NBlock();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrQDsn1NBlock** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQDsn1NBlock& rst);

	virtual void insertRec(PlnrQDsn1NBlock* rec);
	ubigint insertNewRec(PlnrQDsn1NBlock** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	ubigint appendNewRecToRst(ListPlnrQDsn1NBlock& rst, PlnrQDsn1NBlock** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	virtual void insertRst(ListPlnrQDsn1NBlock& rst);
	virtual void updateRec(PlnrQDsn1NBlock* rec);
	virtual void updateRst(ListPlnrQDsn1NBlock& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, PlnrQDsn1NBlock** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQDsn1NBlock& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrQDsn1NBlock: C++ wrapper for table TblPlnrQDsn1NBlock (MySQL database)
  */
class MyTblPlnrQDsn1NBlock : public TblPlnrQDsn1NBlock, public MyTable {

public:
	MyTblPlnrQDsn1NBlock();
	~MyTblPlnrQDsn1NBlock();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQDsn1NBlock** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQDsn1NBlock& rst);

	void insertRec(PlnrQDsn1NBlock* rec);
	void insertRst(ListPlnrQDsn1NBlock& rst);
	void updateRec(PlnrQDsn1NBlock* rec);
	void updateRst(ListPlnrQDsn1NBlock& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQDsn1NBlock** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQDsn1NBlock& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrQDsn1NBlock: C++ wrapper for table TblPlnrQDsn1NBlock (PgSQL database)
  */
class PgTblPlnrQDsn1NBlock : public TblPlnrQDsn1NBlock, public PgTable {

public:
	PgTblPlnrQDsn1NBlock();
	~PgTblPlnrQDsn1NBlock();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrQDsn1NBlock** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrQDsn1NBlock& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrQDsn1NBlock** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrQDsn1NBlock& rst);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQDsn1NBlock** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQDsn1NBlock& rst);

	void insertRec(PlnrQDsn1NBlock* rec);
	void insertRst(ListPlnrQDsn1NBlock& rst);
	void updateRec(PlnrQDsn1NBlock* rec);
	void updateRst(ListPlnrQDsn1NBlock& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQDsn1NBlock** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQDsn1NBlock& rst);
};
// IP pgTbl --- END

#endif

