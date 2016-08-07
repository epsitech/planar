/**
  * \file PlnrQDtpTpl1NDevice.h
  * Dbs and XML wrapper for table TblPlnrQDtpTpl1NDevice (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQDTPTPL1NDEVICE_H
#define PLNRQDTPTPL1NDEVICE_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQDtpTpl1NDevice: record of TblPlnrQDtpTpl1NDevice
  */
class PlnrQDtpTpl1NDevice {

public:
	PlnrQDtpTpl1NDevice(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");

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
  * ListPlnrQDtpTpl1NDevice: recordset of TblPlnrQDtpTpl1NDevice
  */
class ListPlnrQDtpTpl1NDevice {

public:
	ListPlnrQDtpTpl1NDevice();
	ListPlnrQDtpTpl1NDevice(const ListPlnrQDtpTpl1NDevice& src);
	~ListPlnrQDtpTpl1NDevice();

	void clear();
	unsigned int size() const;
	void append(PlnrQDtpTpl1NDevice* rec);

	ListPlnrQDtpTpl1NDevice& operator=(const ListPlnrQDtpTpl1NDevice& src);

public:
	vector<PlnrQDtpTpl1NDevice*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblPlnrQDtpTpl1NDevice: C++ wrapper for table TblPlnrQDtpTpl1NDevice
  */
class TblPlnrQDtpTpl1NDevice {

public:
	TblPlnrQDtpTpl1NDevice();
	virtual ~TblPlnrQDtpTpl1NDevice();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrQDtpTpl1NDevice** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQDtpTpl1NDevice& rst);

	virtual void insertRec(PlnrQDtpTpl1NDevice* rec);
	ubigint insertNewRec(PlnrQDtpTpl1NDevice** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	ubigint appendNewRecToRst(ListPlnrQDtpTpl1NDevice& rst, PlnrQDtpTpl1NDevice** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	virtual void insertRst(ListPlnrQDtpTpl1NDevice& rst);
	virtual void updateRec(PlnrQDtpTpl1NDevice* rec);
	virtual void updateRst(ListPlnrQDtpTpl1NDevice& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, PlnrQDtpTpl1NDevice** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQDtpTpl1NDevice& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrQDtpTpl1NDevice: C++ wrapper for table TblPlnrQDtpTpl1NDevice (MySQL database)
  */
class MyTblPlnrQDtpTpl1NDevice : public TblPlnrQDtpTpl1NDevice, public MyTable {

public:
	MyTblPlnrQDtpTpl1NDevice();
	~MyTblPlnrQDtpTpl1NDevice();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQDtpTpl1NDevice** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQDtpTpl1NDevice& rst);

	void insertRec(PlnrQDtpTpl1NDevice* rec);
	void insertRst(ListPlnrQDtpTpl1NDevice& rst);
	void updateRec(PlnrQDtpTpl1NDevice* rec);
	void updateRst(ListPlnrQDtpTpl1NDevice& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQDtpTpl1NDevice** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQDtpTpl1NDevice& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrQDtpTpl1NDevice: C++ wrapper for table TblPlnrQDtpTpl1NDevice (PgSQL database)
  */
class PgTblPlnrQDtpTpl1NDevice : public TblPlnrQDtpTpl1NDevice, public PgTable {

public:
	PgTblPlnrQDtpTpl1NDevice();
	~PgTblPlnrQDtpTpl1NDevice();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrQDtpTpl1NDevice** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrQDtpTpl1NDevice& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrQDtpTpl1NDevice** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrQDtpTpl1NDevice& rst);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQDtpTpl1NDevice** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQDtpTpl1NDevice& rst);

	void insertRec(PlnrQDtpTpl1NDevice* rec);
	void insertRst(ListPlnrQDtpTpl1NDevice& rst);
	void updateRec(PlnrQDtpTpl1NDevice* rec);
	void updateRst(ListPlnrQDtpTpl1NDevice& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQDtpTpl1NDevice** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQDtpTpl1NDevice& rst);
};
// IP pgTbl --- END

#endif

