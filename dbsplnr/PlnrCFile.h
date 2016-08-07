/**
  * \file PlnrCFile.h
  * Dbs and XML wrapper for table TblPlnrCFile (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRCFILE_H
#define PLNRCFILE_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * TblPlnrCFile: C++ wrapper for table TblPlnrCFile
  */
class TblPlnrCFile {

public:
	TblPlnrCFile();
	virtual ~TblPlnrCFile();

public:
	virtual ubigint getNewRef();
};

// IP myTbl --- BEGIN
/**
  * MyTblPlnrCFile: C++ wrapper for table TblPlnrCFile (MySQL database)
  */
class MyTblPlnrCFile : public TblPlnrCFile, public MyTable {

public:
	MyTblPlnrCFile();
	~MyTblPlnrCFile();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtGetNewRef;

public:
	ubigint getNewRef();
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgTblPlnrCFile: C++ wrapper for table TblPlnrCFile (PgSQL database)
  */
class PgTblPlnrCFile : public TblPlnrCFile, public PgTable {

public:
	PgTblPlnrCFile();
	~PgTblPlnrCFile();

public:
	void initStatements();

public:
	ubigint getNewRef();
};
// IP pgTbl --- END

#endif

