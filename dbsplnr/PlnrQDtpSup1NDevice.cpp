/**
  * \file PlnrQDtpSup1NDevice.cpp
  * Dbs and XML wrapper for table TblPlnrQDtpSup1NDevice (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQDtpSup1NDevice.h"

/******************************************************************************
 class PlnrQDtpSup1NDevice
 ******************************************************************************/

PlnrQDtpSup1NDevice::PlnrQDtpSup1NDevice(
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

void PlnrQDtpSup1NDevice::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "PlnrQDtpSup1NDevice";

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
 class ListPlnrQDtpSup1NDevice
 ******************************************************************************/

ListPlnrQDtpSup1NDevice::ListPlnrQDtpSup1NDevice() {
};

ListPlnrQDtpSup1NDevice::ListPlnrQDtpSup1NDevice(
			const ListPlnrQDtpSup1NDevice& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQDtpSup1NDevice(*(src.nodes[i]));
};

ListPlnrQDtpSup1NDevice::~ListPlnrQDtpSup1NDevice() {
	clear();
};

void ListPlnrQDtpSup1NDevice::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrQDtpSup1NDevice::size() const {
	return(nodes.size());
};

void ListPlnrQDtpSup1NDevice::append(
			PlnrQDtpSup1NDevice* rec
		) {
	nodes.push_back(rec);
};

ListPlnrQDtpSup1NDevice& ListPlnrQDtpSup1NDevice::operator=(
			const ListPlnrQDtpSup1NDevice& src
		) {
	PlnrQDtpSup1NDevice* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrQDtpSup1NDevice(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListPlnrQDtpSup1NDevice::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListPlnrQDtpSup1NDevice";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblPlnrQDtpSup1NDevice
 ******************************************************************************/

TblPlnrQDtpSup1NDevice::TblPlnrQDtpSup1NDevice() {
};

TblPlnrQDtpSup1NDevice::~TblPlnrQDtpSup1NDevice() {
};

bool TblPlnrQDtpSup1NDevice::loadRecBySQL(
			const string& sqlstr
			, PlnrQDtpSup1NDevice** rec
		) {
	return false;
};

ubigint TblPlnrQDtpSup1NDevice::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQDtpSup1NDevice& rst
		) {
	return 0;
};

void TblPlnrQDtpSup1NDevice::insertRec(
			PlnrQDtpSup1NDevice* rec
		) {
};

ubigint TblPlnrQDtpSup1NDevice::insertNewRec(
			PlnrQDtpSup1NDevice** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
			, const uint supNum
		) {
	ubigint retval = 0;
	PlnrQDtpSup1NDevice* _rec = NULL;

	_rec = new PlnrQDtpSup1NDevice(0, jref, jnum, ref, stubRef, supNum);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrQDtpSup1NDevice::appendNewRecToRst(
			ListPlnrQDtpSup1NDevice& rst
			, PlnrQDtpSup1NDevice** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
			, const uint supNum
		) {
	ubigint retval = 0;
	PlnrQDtpSup1NDevice* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, stubRef, supNum);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrQDtpSup1NDevice::insertRst(
			ListPlnrQDtpSup1NDevice& rst
		) {
};

void TblPlnrQDtpSup1NDevice::updateRec(
			PlnrQDtpSup1NDevice* rec
		) {
};

void TblPlnrQDtpSup1NDevice::updateRst(
			ListPlnrQDtpSup1NDevice& rst
		) {
};

void TblPlnrQDtpSup1NDevice::removeRecByQref(
			ubigint qref
		) {
};

void TblPlnrQDtpSup1NDevice::removeRstByJref(
			ubigint jref
		) {
};

bool TblPlnrQDtpSup1NDevice::loadRecByQref(
			ubigint qref
			, PlnrQDtpSup1NDevice** rec
		) {
	return false;
};

ubigint TblPlnrQDtpSup1NDevice::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQDtpSup1NDevice& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrQDtpSup1NDevice
 ******************************************************************************/

MyTblPlnrQDtpSup1NDevice::MyTblPlnrQDtpSup1NDevice() : TblPlnrQDtpSup1NDevice(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblPlnrQDtpSup1NDevice::~MyTblPlnrQDtpSup1NDevice() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblPlnrQDtpSup1NDevice::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrQDtpSup1NDevice (jref, jnum, ref, supNum) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrQDtpSup1NDevice SET jref = ?, jnum = ?, ref = ?, supNum = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblPlnrQDtpSup1NDevice WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblPlnrQDtpSup1NDevice WHERE jref = ?", false);
};

bool MyTblPlnrQDtpSup1NDevice::loadRecBySQL(
			const string& sqlstr
			, PlnrQDtpSup1NDevice** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrQDtpSup1NDevice* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQDtpSup1NDevice / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrQDtpSup1NDevice();

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

ubigint MyTblPlnrQDtpSup1NDevice::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQDtpSup1NDevice& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrQDtpSup1NDevice* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQDtpSup1NDevice / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrQDtpSup1NDevice();

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

void MyTblPlnrQDtpSup1NDevice::insertRec(
			PlnrQDtpSup1NDevice* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->supNum,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQDtpSup1NDevice / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQDtpSup1NDevice / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblPlnrQDtpSup1NDevice::insertRst(
			ListPlnrQDtpSup1NDevice& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblPlnrQDtpSup1NDevice::updateRec(
			PlnrQDtpSup1NDevice* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])), 
		bindUint(&rec->supNum,&(l[3]),&(n[3]),&(e[3])), 
		bindUbigint(&rec->qref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQDtpSup1NDevice / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQDtpSup1NDevice / stmtUpdateRec)\n");
};

void MyTblPlnrQDtpSup1NDevice::updateRst(
			ListPlnrQDtpSup1NDevice& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblPlnrQDtpSup1NDevice::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQDtpSup1NDevice / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQDtpSup1NDevice / stmtRemoveRecByQref)\n");
};

void MyTblPlnrQDtpSup1NDevice::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQDtpSup1NDevice / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQDtpSup1NDevice / stmtRemoveRstByJref)\n");
};

bool MyTblPlnrQDtpSup1NDevice::loadRecByQref(
			ubigint qref
			, PlnrQDtpSup1NDevice** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrQDtpSup1NDevice WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblPlnrQDtpSup1NDevice::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQDtpSup1NDevice& rst
		) {
	return loadRstBySQL("SELECT * FROM TblPlnrQDtpSup1NDevice WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrQDtpSup1NDevice
 ******************************************************************************/

PgTblPlnrQDtpSup1NDevice::PgTblPlnrQDtpSup1NDevice() : TblPlnrQDtpSup1NDevice(), PgTable() {
};

PgTblPlnrQDtpSup1NDevice::~PgTblPlnrQDtpSup1NDevice() {
};

void PgTblPlnrQDtpSup1NDevice::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrQDtpSup1NDevice_insertRec", "INSERT INTO TblPlnrQDtpSup1NDevice (jref, jnum, ref, supNum) VALUES ($1,$2,$3,$4) RETURNING qref", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQDtpSup1NDevice_updateRec", "UPDATE TblPlnrQDtpSup1NDevice SET jref = $1, jnum = $2, ref = $3, supNum = $4 WHERE qref = $5", 5, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQDtpSup1NDevice_removeRecByQref", "DELETE FROM TblPlnrQDtpSup1NDevice WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQDtpSup1NDevice_removeRstByJref", "DELETE FROM TblPlnrQDtpSup1NDevice WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrQDtpSup1NDevice_loadRecByQref", "SELECT qref, jref, jnum, ref, supNum FROM TblPlnrQDtpSup1NDevice WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQDtpSup1NDevice_loadRstByJref", "SELECT qref, jref, jnum, ref, supNum FROM TblPlnrQDtpSup1NDevice WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrQDtpSup1NDevice::loadRec(
			PGresult* res
			, PlnrQDtpSup1NDevice** rec
		) {
	char* ptr;

	PlnrQDtpSup1NDevice* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrQDtpSup1NDevice();

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

ubigint PgTblPlnrQDtpSup1NDevice::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrQDtpSup1NDevice& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrQDtpSup1NDevice* rec;

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
			rec = new PlnrQDtpSup1NDevice();

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

bool PgTblPlnrQDtpSup1NDevice::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrQDtpSup1NDevice** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDtpSup1NDevice / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQDtpSup1NDevice::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrQDtpSup1NDevice& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDtpSup1NDevice / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblPlnrQDtpSup1NDevice::loadRecBySQL(
			const string& sqlstr
			, PlnrQDtpSup1NDevice** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQDtpSup1NDevice::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQDtpSup1NDevice& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrQDtpSup1NDevice::insertRec(
			PlnrQDtpSup1NDevice* rec
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

	res = PQexecPrepared(dbs, "TblPlnrQDtpSup1NDevice_insertRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDtpSup1NDevice_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblPlnrQDtpSup1NDevice::insertRst(
			ListPlnrQDtpSup1NDevice& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblPlnrQDtpSup1NDevice::updateRec(
			PlnrQDtpSup1NDevice* rec
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

	res = PQexecPrepared(dbs, "TblPlnrQDtpSup1NDevice_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDtpSup1NDevice_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrQDtpSup1NDevice::updateRst(
			ListPlnrQDtpSup1NDevice& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblPlnrQDtpSup1NDevice::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblPlnrQDtpSup1NDevice_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDtpSup1NDevice_removeRecByQref)\n");

	PQclear(res);
};

void PgTblPlnrQDtpSup1NDevice::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblPlnrQDtpSup1NDevice_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDtpSup1NDevice_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblPlnrQDtpSup1NDevice::loadRecByQref(
			ubigint qref
			, PlnrQDtpSup1NDevice** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrQDtpSup1NDevice_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblPlnrQDtpSup1NDevice::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQDtpSup1NDevice& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrQDtpSup1NDevice_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

