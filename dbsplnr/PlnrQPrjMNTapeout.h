/**
  * \file PlnrQPrjMNTapeout.h
  * Dbs and XML wrapper for table TblPlnrQPrjMNTapeout (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQPRJMNTAPEOUT_H
#define PLNRQPRJMNTAPEOUT_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQPrjMNTapeout: record of TblPlnrQPrjMNTapeout
  */
class PlnrQPrjMNTapeout {

public:
	PlnrQPrjMNTapeout(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0);

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
  * ListPlnrQPrjMNTapeout: recordset of TblPlnrQPrjMNTapeout
  */
class ListPlnrQPrjMNTapeout {

public:
	ListPlnrQPrjMNTapeout();
	ListPlnrQPrjMNTapeout(const ListPlnrQPrjMNTapeout& src);
	~ListPlnrQPrjMNTapeout();

	void clear();
	unsigned int size() const;
	void append(PlnrQPrjMNTapeout* rec);

	ListPlnrQPrjMNTapeout& operator=(const ListPlnrQPrjMNTapeout& src);

public:
	vector<PlnrQPrjMNTapeout*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblPlnrQPrjMNTapeout: C++ wrapper for table TblPlnrQPrjMNTapeout
  */
class TblPlnrQPrjMNTapeout {

public:
	TblPlnrQPrjMNTapeout();
	virtual ~TblPlnrQPrjMNTapeout();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrQPrjMNTapeout** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQPrjMNTapeout& rst);

	virtual void insertRec(PlnrQPrjMNTapeout* rec);
	ubigint insertNewRec(PlnrQPrjMNTapeout** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0);
	ubigint appendNewRecToRst(ListPlnrQPrjMNTapeout& rst, PlnrQPrjMNTapeout** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0);
	virtual void insertRst(ListPlnrQPrjMNTapeout& rst);
	virtual void updateRec(PlnrQPrjMNTapeout* rec);
	virtual void updateRst(ListPlnrQPrjMNTapeout& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, PlnrQPrjMNTapeout** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQPrjMNTapeout& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrQPrjMNTapeout: C++ wrapper for table TblPlnrQPrjMNTapeout (MySQL database)
  */
class MyTblPlnrQPrjMNTapeout : public TblPlnrQPrjMNTapeout, public MyTable {

public:
	MyTblPlnrQPrjMNTapeout();
	~MyTblPlnrQPrjMNTapeout();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQPrjMNTapeout** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQPrjMNTapeout& rst);

	void insertRec(PlnrQPrjMNTapeout* rec);
	void insertRst(ListPlnrQPrjMNTapeout& rst);
	void updateRec(PlnrQPrjMNTapeout* rec);
	void updateRst(ListPlnrQPrjMNTapeout& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQPrjMNTapeout** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQPrjMNTapeout& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrQPrjMNTapeout: C++ wrapper for table TblPlnrQPrjMNTapeout (PgSQL database)
  */
class PgTblPlnrQPrjMNTapeout : public TblPlnrQPrjMNTapeout, public PgTable {

public:
	PgTblPlnrQPrjMNTapeout();
	~PgTblPlnrQPrjMNTapeout();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrQPrjMNTapeout** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrQPrjMNTapeout& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrQPrjMNTapeout** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrQPrjMNTapeout& rst);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQPrjMNTapeout** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQPrjMNTapeout& rst);

	void insertRec(PlnrQPrjMNTapeout* rec);
	void insertRst(ListPlnrQPrjMNTapeout& rst);
	void updateRec(PlnrQPrjMNTapeout* rec);
	void updateRst(ListPlnrQPrjMNTapeout& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQPrjMNTapeout** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQPrjMNTapeout& rst);
};
// IP pgTbl --- END

#endif

