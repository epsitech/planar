/**
  * \file PlnrQDvcSup1NDevice.cpp
  * Dbs and XML wrapper for table TblPlnrQDvcSup1NDevice (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQDvcSup1NDevice.h"

/******************************************************************************
 class PlnrQDvcSup1NDevice
 ******************************************************************************/

PlnrQDvcSup1NDevice::PlnrQDvcSup1NDevice(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
			, const uint supNum
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->stubRef = stubRef;
	this->supNum = supNum;
};

void PlnrQDvcSup1NDevice::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "PlnrQDvcSup1NDevice";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "ref", stubRef);
	} else {
		writeString(wr, "stubRef", stubRef);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListPlnrQDvcSup1NDevice
 ******************************************************************************/

ListPlnrQDvcSup1NDevice::ListPlnrQDvcSup1NDevice() {
};

ListPlnrQDvcSup1NDevice::ListPlnrQDvcSup1NDevice(
			const ListPlnrQDvcSup1NDevice& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQDvcSup1NDevice(*(src.nodes[i]));
};

ListPlnrQDvcSup1NDevice::~ListPlnrQDvcSup1NDevice() {
	clear();
};

void ListPlnrQDvcSup1NDevice::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrQDvcSup1NDevice::size() const {
	return(nodes.size());
};

void ListPlnrQDvcSup1NDevice::append(
			PlnrQDvcSup1NDevice* rec
		) {
	nodes.push_back(rec);
};

ListPlnrQDvcSup1NDevice& ListPlnrQDvcSup1NDevice::operator=(
			const ListPlnrQDvcSup1NDevice& src
		) {
	PlnrQDvcSup1NDevice* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrQDvcSup1NDevice(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListPlnrQDvcSup1NDevice::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListPlnrQDvcSup1NDevice";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblPlnrQDvcSup1NDevice
 ******************************************************************************/

TblPlnrQDvcSup1NDevice::TblPlnrQDvcSup1NDevice() {
};

TblPlnrQDvcSup1NDevice::~TblPlnrQDvcSup1NDevice() {
};

bool TblPlnrQDvcSup1NDevice::loadRecBySQL(
			const string& sqlstr
			, PlnrQDvcSup1NDevice** rec
		) {
	return false;
};

ubigint TblPlnrQDvcSup1NDevice::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQDvcSup1NDevice& rst
		) {
	return 0;
};

void TblPlnrQDvcSup1NDevice::insertRec(
			PlnrQDvcSup1NDevice* rec
		) {
};

ubigint TblPlnrQDvcSup1NDevice::insertNewRec(
			PlnrQDvcSup1NDevice** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
			, const uint supNum
		) {
	ubigint retval = 0;
	PlnrQDvcSup1NDevice* _rec = NULL;

	_rec = new PlnrQDvcSup1NDevice(0, jref, jnum, ref, stubRef, supNum);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrQDvcSup1NDevice::appendNewRecToRst(
			ListPlnrQDvcSup1NDevice& rst
			, PlnrQDvcSup1NDevice** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
			, const uint supNum
		) {
	ubigint retval = 0;
	PlnrQDvcSup1NDevice* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, stubRef, supNum);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrQDvcSup1NDevice::insertRst(
			ListPlnrQDvcSup1NDevice& rst
		) {
};

void TblPlnrQDvcSup1NDevice::updateRec(
			PlnrQDvcSup1NDevice* rec
		) {
};

void TblPlnrQDvcSup1NDevice::updateRst(
			ListPlnrQDvcSup1NDevice& rst
		) {
};

void TblPlnrQDvcSup1NDevice::removeRecByQref(
			ubigint qref
		) {
};

void TblPlnrQDvcSup1NDevice::removeRstByJref(
			ubigint jref
		) {
};

bool TblPlnrQDvcSup1NDevice::loadRecByQref(
			ubigint qref
			, PlnrQDvcSup1NDevice** rec
		) {
	return false;
};

ubigint TblPlnrQDvcSup1NDevice::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQDvcSup1NDevice& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrQDvcSup1NDevice
 ******************************************************************************/

MyTblPlnrQDvcSup1NDevice::MyTblPlnrQDvcSup1NDevice() : TblPlnrQDvcSup1NDevice(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblPlnrQDvcSup1NDevice::~MyTblPlnrQDvcSup1NDevice() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblPlnrQDvcSup1NDevice::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrQDvcSup1NDevice (jref, jnum, ref, supNum) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrQDvcSup1NDevice SET jref = ?, jnum = ?, ref = ?, supNum = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblPlnrQDvcSup1NDevice WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblPlnrQDvcSup1NDevice WHERE jref = ?", false);
};

bool MyTblPlnrQDvcSup1NDevice::loadRecBySQL(
			const string& sqlstr
			, PlnrQDvcSup1NDevice** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrQDvcSup1NDevice* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQDvcSup1NDevice / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrQDvcSup1NDevice();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->supNum = atol((char*) dbrow[4]); else _rec->supNum = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrQDvcSup1NDevice::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQDvcSup1NDevice& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrQDvcSup1NDevice* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQDvcSup1NDevice / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrQDvcSup1NDevice();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->supNum = atol((char*) dbrow[4]); else rec->supNum = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrQDvcSup1NDevice::insertRec(
			PlnrQDvcSup1NDevice* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->supNum,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQDvcSup1NDevice / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQDvcSup1NDevice / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblPlnrQDvcSup1NDevice::insertRst(
			ListPlnrQDvcSup1NDevice& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblPlnrQDvcSup1NDevice::updateRec(
			PlnrQDvcSup1NDevice* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])), 
		bindUint(&rec->supNum,&(l[3]),&(n[3]),&(e[3])), 
		bindUbigint(&rec->qref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQDvcSup1NDevice / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQDvcSup1NDevice / stmtUpdateRec)\n");
};

void MyTblPlnrQDvcSup1NDevice::updateRst(
			ListPlnrQDvcSup1NDevice& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblPlnrQDvcSup1NDevice::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQDvcSup1NDevice / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQDvcSup1NDevice / stmtRemoveRecByQref)\n");
};

void MyTblPlnrQDvcSup1NDevice::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQDvcSup1NDevice / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQDvcSup1NDevice / stmtRemoveRstByJref)\n");
};

bool MyTblPlnrQDvcSup1NDevice::loadRecByQref(
			ubigint qref
			, PlnrQDvcSup1NDevice** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrQDvcSup1NDevice WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblPlnrQDvcSup1NDevice::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQDvcSup1NDevice& rst
		) {
	return loadRstBySQL("SELECT * FROM TblPlnrQDvcSup1NDevice WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrQDvcSup1NDevice
 ******************************************************************************/

PgTblPlnrQDvcSup1NDevice::PgTblPlnrQDvcSup1NDevice() : TblPlnrQDvcSup1NDevice(), PgTable() {
};

PgTblPlnrQDvcSup1NDevice::~PgTblPlnrQDvcSup1NDevice() {
};

void PgTblPlnrQDvcSup1NDevice::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrQDvcSup1NDevice_insertRec", "INSERT INTO TblPlnrQDvcSup1NDevice (jref, jnum, ref, supNum) VALUES ($1,$2,$3,$4) RETURNING qref", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQDvcSup1NDevice_updateRec", "UPDATE TblPlnrQDvcSup1NDevice SET jref = $1, jnum = $2, ref = $3, supNum = $4 WHERE qref = $5", 5, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQDvcSup1NDevice_removeRecByQref", "DELETE FROM TblPlnrQDvcSup1NDevice WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQDvcSup1NDevice_removeRstByJref", "DELETE FROM TblPlnrQDvcSup1NDevice WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrQDvcSup1NDevice_loadRecByQref", "SELECT qref, jref, jnum, ref, supNum FROM TblPlnrQDvcSup1NDevice WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQDvcSup1NDevice_loadRstByJref", "SELECT qref, jref, jnum, ref, supNum FROM TblPlnrQDvcSup1NDevice WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrQDvcSup1NDevice::loadRec(
			PGresult* res
			, PlnrQDvcSup1NDevice** rec
		) {
	char* ptr;

	PlnrQDvcSup1NDevice* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrQDvcSup1NDevice();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "supnum")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->supNum = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrQDvcSup1NDevice::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrQDvcSup1NDevice& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrQDvcSup1NDevice* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "supnum")
		};

		while (numread < numrow) {
			rec = new PlnrQDvcSup1NDevice();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->supNum = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrQDvcSup1NDevice::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrQDvcSup1NDevice** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDvcSup1NDevice / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQDvcSup1NDevice::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrQDvcSup1NDevice& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDvcSup1NDevice / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblPlnrQDvcSup1NDevice::loadRecBySQL(
			const string& sqlstr
			, PlnrQDvcSup1NDevice** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQDvcSup1NDevice::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQDvcSup1NDevice& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrQDvcSup1NDevice::insertRec(
			PlnrQDvcSup1NDevice* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _supNum = htonl(rec->supNum);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_supNum
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblPlnrQDvcSup1NDevice_insertRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDvcSup1NDevice_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblPlnrQDvcSup1NDevice::insertRst(
			ListPlnrQDvcSup1NDevice& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblPlnrQDvcSup1NDevice::updateRec(
			PlnrQDvcSup1NDevice* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _supNum = htonl(rec->supNum);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_supNum,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblPlnrQDvcSup1NDevice_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDvcSup1NDevice_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrQDvcSup1NDevice::updateRst(
			ListPlnrQDvcSup1NDevice& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblPlnrQDvcSup1NDevice::removeRecByQref(
			ubigint qref
		) {
	PGresult* res;

	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	res = PQexecPrepared(dbs, "TblPlnrQDvcSup1NDevice_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDvcSup1NDevice_removeRecByQref)\n");

	PQclear(res);
};

void PgTblPlnrQDvcSup1NDevice::removeRstByJref(
			ubigint jref
		) {
	PGresult* res;

	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	res = PQexecPrepared(dbs, "TblPlnrQDvcSup1NDevice_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDvcSup1NDevice_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblPlnrQDvcSup1NDevice::loadRecByQref(
			ubigint qref
			, PlnrQDvcSup1NDevice** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrQDvcSup1NDevice_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblPlnrQDvcSup1NDevice::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQDvcSup1NDevice& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrQDvcSup1NDevice_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

