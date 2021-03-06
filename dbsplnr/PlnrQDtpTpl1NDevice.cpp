/**
  * \file PlnrQDtpTpl1NDevice.cpp
  * Dbs and XML wrapper for table TblPlnrQDtpTpl1NDevice (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQDtpTpl1NDevice.h"

/******************************************************************************
 class PlnrQDtpTpl1NDevice
 ******************************************************************************/

PlnrQDtpTpl1NDevice::PlnrQDtpTpl1NDevice(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->stubRef = stubRef;
};

void PlnrQDtpTpl1NDevice::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "PlnrQDtpTpl1NDevice";

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
 class ListPlnrQDtpTpl1NDevice
 ******************************************************************************/

ListPlnrQDtpTpl1NDevice::ListPlnrQDtpTpl1NDevice() {
};

ListPlnrQDtpTpl1NDevice::ListPlnrQDtpTpl1NDevice(
			const ListPlnrQDtpTpl1NDevice& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQDtpTpl1NDevice(*(src.nodes[i]));
};

ListPlnrQDtpTpl1NDevice::~ListPlnrQDtpTpl1NDevice() {
	clear();
};

void ListPlnrQDtpTpl1NDevice::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrQDtpTpl1NDevice::size() const {
	return(nodes.size());
};

void ListPlnrQDtpTpl1NDevice::append(
			PlnrQDtpTpl1NDevice* rec
		) {
	nodes.push_back(rec);
};

ListPlnrQDtpTpl1NDevice& ListPlnrQDtpTpl1NDevice::operator=(
			const ListPlnrQDtpTpl1NDevice& src
		) {
	PlnrQDtpTpl1NDevice* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrQDtpTpl1NDevice(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListPlnrQDtpTpl1NDevice::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListPlnrQDtpTpl1NDevice";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblPlnrQDtpTpl1NDevice
 ******************************************************************************/

TblPlnrQDtpTpl1NDevice::TblPlnrQDtpTpl1NDevice() {
};

TblPlnrQDtpTpl1NDevice::~TblPlnrQDtpTpl1NDevice() {
};

bool TblPlnrQDtpTpl1NDevice::loadRecBySQL(
			const string& sqlstr
			, PlnrQDtpTpl1NDevice** rec
		) {
	return false;
};

ubigint TblPlnrQDtpTpl1NDevice::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQDtpTpl1NDevice& rst
		) {
	return 0;
};

void TblPlnrQDtpTpl1NDevice::insertRec(
			PlnrQDtpTpl1NDevice* rec
		) {
};

ubigint TblPlnrQDtpTpl1NDevice::insertNewRec(
			PlnrQDtpTpl1NDevice** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	PlnrQDtpTpl1NDevice* _rec = NULL;

	_rec = new PlnrQDtpTpl1NDevice(0, jref, jnum, ref, stubRef);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrQDtpTpl1NDevice::appendNewRecToRst(
			ListPlnrQDtpTpl1NDevice& rst
			, PlnrQDtpTpl1NDevice** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	PlnrQDtpTpl1NDevice* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, stubRef);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrQDtpTpl1NDevice::insertRst(
			ListPlnrQDtpTpl1NDevice& rst
		) {
};

void TblPlnrQDtpTpl1NDevice::updateRec(
			PlnrQDtpTpl1NDevice* rec
		) {
};

void TblPlnrQDtpTpl1NDevice::updateRst(
			ListPlnrQDtpTpl1NDevice& rst
		) {
};

void TblPlnrQDtpTpl1NDevice::removeRecByQref(
			ubigint qref
		) {
};

void TblPlnrQDtpTpl1NDevice::removeRstByJref(
			ubigint jref
		) {
};

bool TblPlnrQDtpTpl1NDevice::loadRecByQref(
			ubigint qref
			, PlnrQDtpTpl1NDevice** rec
		) {
	return false;
};

ubigint TblPlnrQDtpTpl1NDevice::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQDtpTpl1NDevice& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrQDtpTpl1NDevice
 ******************************************************************************/

MyTblPlnrQDtpTpl1NDevice::MyTblPlnrQDtpTpl1NDevice() : TblPlnrQDtpTpl1NDevice(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblPlnrQDtpTpl1NDevice::~MyTblPlnrQDtpTpl1NDevice() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblPlnrQDtpTpl1NDevice::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrQDtpTpl1NDevice (jref, jnum, ref) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrQDtpTpl1NDevice SET jref = ?, jnum = ?, ref = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblPlnrQDtpTpl1NDevice WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblPlnrQDtpTpl1NDevice WHERE jref = ?", false);
};

bool MyTblPlnrQDtpTpl1NDevice::loadRecBySQL(
			const string& sqlstr
			, PlnrQDtpTpl1NDevice** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrQDtpTpl1NDevice* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQDtpTpl1NDevice / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrQDtpTpl1NDevice();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrQDtpTpl1NDevice::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQDtpTpl1NDevice& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrQDtpTpl1NDevice* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQDtpTpl1NDevice / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrQDtpTpl1NDevice();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrQDtpTpl1NDevice::insertRec(
			PlnrQDtpTpl1NDevice* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQDtpTpl1NDevice / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQDtpTpl1NDevice / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblPlnrQDtpTpl1NDevice::insertRst(
			ListPlnrQDtpTpl1NDevice& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblPlnrQDtpTpl1NDevice::updateRec(
			PlnrQDtpTpl1NDevice* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->qref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQDtpTpl1NDevice / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQDtpTpl1NDevice / stmtUpdateRec)\n");
};

void MyTblPlnrQDtpTpl1NDevice::updateRst(
			ListPlnrQDtpTpl1NDevice& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblPlnrQDtpTpl1NDevice::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQDtpTpl1NDevice / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQDtpTpl1NDevice / stmtRemoveRecByQref)\n");
};

void MyTblPlnrQDtpTpl1NDevice::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQDtpTpl1NDevice / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQDtpTpl1NDevice / stmtRemoveRstByJref)\n");
};

bool MyTblPlnrQDtpTpl1NDevice::loadRecByQref(
			ubigint qref
			, PlnrQDtpTpl1NDevice** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrQDtpTpl1NDevice WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblPlnrQDtpTpl1NDevice::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQDtpTpl1NDevice& rst
		) {
	return loadRstBySQL("SELECT * FROM TblPlnrQDtpTpl1NDevice WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrQDtpTpl1NDevice
 ******************************************************************************/

PgTblPlnrQDtpTpl1NDevice::PgTblPlnrQDtpTpl1NDevice() : TblPlnrQDtpTpl1NDevice(), PgTable() {
};

PgTblPlnrQDtpTpl1NDevice::~PgTblPlnrQDtpTpl1NDevice() {
};

void PgTblPlnrQDtpTpl1NDevice::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrQDtpTpl1NDevice_insertRec", "INSERT INTO TblPlnrQDtpTpl1NDevice (jref, jnum, ref) VALUES ($1,$2,$3) RETURNING qref", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQDtpTpl1NDevice_updateRec", "UPDATE TblPlnrQDtpTpl1NDevice SET jref = $1, jnum = $2, ref = $3 WHERE qref = $4", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQDtpTpl1NDevice_removeRecByQref", "DELETE FROM TblPlnrQDtpTpl1NDevice WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQDtpTpl1NDevice_removeRstByJref", "DELETE FROM TblPlnrQDtpTpl1NDevice WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrQDtpTpl1NDevice_loadRecByQref", "SELECT qref, jref, jnum, ref FROM TblPlnrQDtpTpl1NDevice WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQDtpTpl1NDevice_loadRstByJref", "SELECT qref, jref, jnum, ref FROM TblPlnrQDtpTpl1NDevice WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrQDtpTpl1NDevice::loadRec(
			PGresult* res
			, PlnrQDtpTpl1NDevice** rec
		) {
	char* ptr;

	PlnrQDtpTpl1NDevice* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrQDtpTpl1NDevice();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrQDtpTpl1NDevice::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrQDtpTpl1NDevice& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrQDtpTpl1NDevice* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref")
		};

		while (numread < numrow) {
			rec = new PlnrQDtpTpl1NDevice();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrQDtpTpl1NDevice::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrQDtpTpl1NDevice** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDtpTpl1NDevice / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQDtpTpl1NDevice::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrQDtpTpl1NDevice& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDtpTpl1NDevice / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblPlnrQDtpTpl1NDevice::loadRecBySQL(
			const string& sqlstr
			, PlnrQDtpTpl1NDevice** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQDtpTpl1NDevice::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQDtpTpl1NDevice& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrQDtpTpl1NDevice::insertRec(
			PlnrQDtpTpl1NDevice* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1};

	res = PQexecPrepared(dbs, "TblPlnrQDtpTpl1NDevice_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDtpTpl1NDevice_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblPlnrQDtpTpl1NDevice::insertRst(
			ListPlnrQDtpTpl1NDevice& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblPlnrQDtpTpl1NDevice::updateRec(
			PlnrQDtpTpl1NDevice* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblPlnrQDtpTpl1NDevice_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDtpTpl1NDevice_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrQDtpTpl1NDevice::updateRst(
			ListPlnrQDtpTpl1NDevice& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblPlnrQDtpTpl1NDevice::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblPlnrQDtpTpl1NDevice_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDtpTpl1NDevice_removeRecByQref)\n");

	PQclear(res);
};

void PgTblPlnrQDtpTpl1NDevice::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblPlnrQDtpTpl1NDevice_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDtpTpl1NDevice_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblPlnrQDtpTpl1NDevice::loadRecByQref(
			ubigint qref
			, PlnrQDtpTpl1NDevice** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrQDtpTpl1NDevice_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblPlnrQDtpTpl1NDevice::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQDtpTpl1NDevice& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrQDtpTpl1NDevice_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

