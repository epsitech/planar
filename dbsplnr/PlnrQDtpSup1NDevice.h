/**
  * \file PlnrQDtpSup1NDevice.h
  * Dbs and XML wrapper for table TblPlnrQDtpSup1NDevice (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQDTPSUP1NDEVICE_H
#define PLNRQDTPSUP1NDEVICE_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQDtpSup1NDevice: record of TblPlnrQDtpSup1NDevice
  */
class PlnrQDtpSup1NDevice {

public:
	PlnrQDtpSup1NDevice(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "", const uint supNum = 0);

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	string stubRef;
	uint supNum;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListPlnrQDtpSup1NDevice: recordset of TblPlnrQDtpSup1NDevice
  */
class ListPlnrQDtpSup1NDevice {

public:
	ListPlnrQDtpSup1NDevice();
	ListPlnrQDtpSup1NDevice(const ListPlnrQDtpSup1NDevice& src);
	~ListPlnrQDtpSup1NDevice();

	void clear();
	unsigned int size() const;
	void append(PlnrQDtpSup1NDevice* rec);

	ListPlnrQDtpSup1NDevice& operator=(const ListPlnrQDtpSup1NDevice& src);

public:
	vector<PlnrQDtpSup1NDevice*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblPlnrQDtpSup1NDevice: C++ wrapper for table TblPlnrQDtpSup1NDevice
  */
class TblPlnrQDtpSup1NDevice {

public:
	TblPlnrQDtpSup1NDevice();
	virtual ~TblPlnrQDtpSup1NDevice();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrQDtpSup1NDevice** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQDtpSup1NDevice& rst);

	virtual void insertRec(PlnrQDtpSup1NDevice* rec);
	ubigint insertNewRec(PlnrQDtpSup1NDevice** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "", const uint supNum = 0);
	ubigint appendNewRecToRst(ListPlnrQDtpSup1NDevice& rst, PlnrQDtpSup1NDevice** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "", const uint supNum = 0);
	virtual void insertRst(ListPlnrQDtpSup1NDevice& rst);
	virtual void updateRec(PlnrQDtpSup1NDevice* rec);
	virtual void updateRst(ListPlnrQDtpSup1NDevice& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, PlnrQDtpSup1NDevice** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQDtpSup1NDevice& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrQDtpSup1NDevice: C++ wrapper for table TblPlnrQDtpSup1NDevice (MySQL database)
  */
class MyTblPlnrQDtpSup1NDevice : public TblPlnrQDtpSup1NDevice, public MyTable {

public:
	MyTblPlnrQDtpSup1NDevice();
	~MyTblPlnrQDtpSup1NDevice();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQDtpSup1NDevice** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQDtpSup1NDevice& rst);

	void insertRec(PlnrQDtpSup1NDevice* rec);
	void insertRst(ListPlnrQDtpSup1NDevice& rst);
	void updateRec(PlnrQDtpSup1NDevice* rec);
	void updateRst(ListPlnrQDtpSup1NDevice& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQDtpSup1NDevice** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQDtpSup1NDevice& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrQDtpSup1NDevice: C++ wrapper for table TblPlnrQDtpSup1NDevice (PgSQL database)
  */
class PgTblPlnrQDtpSup1NDevice : public TblPlnrQDtpSup1NDevice, public PgTable {

public:
	PgTblPlnrQDtpSup1NDevice();
	~PgTblPlnrQDtpSup1NDevice();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrQDtpSup1NDevice** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrQDtpSup1NDevice& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrQDtpSup1NDevice** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrQDtpSup1NDevice& rst);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQDtpSup1NDevice** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQDtpSup1NDevice& rst);

	void insertRec(PlnrQDtpSup1NDevice* rec);
	void insertRst(ListPlnrQDtpSup1NDevice& rst);
	void updateRec(PlnrQDtpSup1NDevice* rec);
	void updateRst(ListPlnrQDtpSup1NDevice& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQDtpSup1NDevice** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQDtpSup1NDevice& rst);
};
// IP pgTbl --- END

#endif

