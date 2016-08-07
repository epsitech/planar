/**
  * \file PlnrQDsnDsn1NDevice.cpp
  * Dbs and XML wrapper for table TblPlnrQDsnDsn1NDevice (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQDsnDsn1NDevice.h"

/******************************************************************************
 class PlnrQDsnDsn1NDevice
 ******************************************************************************/

PlnrQDsnDsn1NDevice::PlnrQDsnDsn1NDevice(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
			, const uint dsnNum
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->stubRef = stubRef;
	this->dsnNum = dsnNum;
};

void PlnrQDsnDsn1NDevice::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "PlnrQDsnDsn1NDevice";

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
 class ListPlnrQDsnDsn1NDevice
 ******************************************************************************/

ListPlnrQDsnDsn1NDevice::ListPlnrQDsnDsn1NDevice() {
};

ListPlnrQDsnDsn1NDevice::ListPlnrQDsnDsn1NDevice(
			const ListPlnrQDsnDsn1NDevice& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQDsnDsn1NDevice(*(src.nodes[i]));
};

ListPlnrQDsnDsn1NDevice::~ListPlnrQDsnDsn1NDevice() {
	clear();
};

void ListPlnrQDsnDsn1NDevice::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrQDsnDsn1NDevice::size() const {
	return(nodes.size());
};

void ListPlnrQDsnDsn1NDevice::append(
			PlnrQDsnDsn1NDevice* rec
		) {
	nodes.push_back(rec);
};

ListPlnrQDsnDsn1NDevice& ListPlnrQDsnDsn1NDevice::operator=(
			const ListPlnrQDsnDsn1NDevice& src
		) {
	PlnrQDsnDsn1NDevice* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrQDsnDsn1NDevice(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListPlnrQDsnDsn1NDevice::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListPlnrQDsnDsn1NDevice";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblPlnrQDsnDsn1NDevice
 ******************************************************************************/

TblPlnrQDsnDsn1NDevice::TblPlnrQDsnDsn1NDevice() {
};

TblPlnrQDsnDsn1NDevice::~TblPlnrQDsnDsn1NDevice() {
};

bool TblPlnrQDsnDsn1NDevice::loadRecBySQL(
			const string& sqlstr
			, PlnrQDsnDsn1NDevice** rec
		) {
	return false;
};

ubigint TblPlnrQDsnDsn1NDevice::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQDsnDsn1NDevice& rst
		) {
	return 0;
};

void TblPlnrQDsnDsn1NDevice::insertRec(
			PlnrQDsnDsn1NDevice* rec
		) {
};

ubigint TblPlnrQDsnDsn1NDevice::insertNewRec(
			PlnrQDsnDsn1NDevice** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
			, const uint dsnNum
		) {
	ubigint retval = 0;
	PlnrQDsnDsn1NDevice* _rec = NULL;

	_rec = new PlnrQDsnDsn1NDevice(0, jref, jnum, ref, stubRef, dsnNum);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrQDsnDsn1NDevice::appendNewRecToRst(
			ListPlnrQDsnDsn1NDevice& rst
			, PlnrQDsnDsn1NDevice** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
			, const uint dsnNum
		) {
	ubigint retval = 0;
	PlnrQDsnDsn1NDevice* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, stubRef, dsnNum);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrQDsnDsn1NDevice::insertRst(
			ListPlnrQDsnDsn1NDevice& rst
		) {
};

void TblPlnrQDsnDsn1NDevice::updateRec(
			PlnrQDsnDsn1NDevice* rec
		) {
};

void TblPlnrQDsnDsn1NDevice::updateRst(
			ListPlnrQDsnDsn1NDevice& rst
		) {
};

void TblPlnrQDsnDsn1NDevice::removeRecByQref(
			ubigint qref
		) {
};

void TblPlnrQDsnDsn1NDevice::removeRstByJref(
			ubigint jref
		) {
};

bool TblPlnrQDsnDsn1NDevice::loadRecByQref(
			ubigint qref
			, PlnrQDsnDsn1NDevice** rec
		) {
	return false;
};

ubigint TblPlnrQDsnDsn1NDevice::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQDsnDsn1NDevice& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrQDsnDsn1NDevice
 ******************************************************************************/

MyTblPlnrQDsnDsn1NDevice::MyTblPlnrQDsnDsn1NDevice() : TblPlnrQDsnDsn1NDevice(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblPlnrQDsnDsn1NDevice::~MyTblPlnrQDsnDsn1NDevice() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblPlnrQDsnDsn1NDevice::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrQDsnDsn1NDevice (jref, jnum, ref, dsnNum) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrQDsnDsn1NDevice SET jref = ?, jnum = ?, ref = ?, dsnNum = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblPlnrQDsnDsn1NDevice WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblPlnrQDsnDsn1NDevice WHERE jref = ?", false);
};

bool MyTblPlnrQDsnDsn1NDevice::loadRecBySQL(
			const string& sqlstr
			, PlnrQDsnDsn1NDevice** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrQDsnDsn1NDevice* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQDsnDsn1NDevice / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrQDsnDsn1NDevice();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->dsnNum = atol((char*) dbrow[4]); else _rec->dsnNum = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrQDsnDsn1NDevice::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQDsnDsn1NDevice& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrQDsnDsn1NDevice* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQDsnDsn1NDevice / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrQDsnDsn1NDevice();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->dsnNum = atol((char*) dbrow[4]); else rec->dsnNum = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrQDsnDsn1NDevice::insertRec(
			PlnrQDsnDsn1NDevice* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->dsnNum,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQDsnDsn1NDevice / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQDsnDsn1NDevice / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblPlnrQDsnDsn1NDevice::insertRst(
			ListPlnrQDsnDsn1NDevice& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblPlnrQDsnDsn1NDevice::updateRec(
			PlnrQDsnDsn1NDevice* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])), 
		bindUint(&rec->dsnNum,&(l[3]),&(n[3]),&(e[3])), 
		bindUbigint(&rec->qref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQDsnDsn1NDevice / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQDsnDsn1NDevice / stmtUpdateRec)\n");
};

void MyTblPlnrQDsnDsn1NDevice::updateRst(
			ListPlnrQDsnDsn1NDevice& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblPlnrQDsnDsn1NDevice::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQDsnDsn1NDevice / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQDsnDsn1NDevice / stmtRemoveRecByQref)\n");
};

void MyTblPlnrQDsnDsn1NDevice::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQDsnDsn1NDevice / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQDsnDsn1NDevice / stmtRemoveRstByJref)\n");
};

bool MyTblPlnrQDsnDsn1NDevice::loadRecByQref(
			ubigint qref
			, PlnrQDsnDsn1NDevice** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrQDsnDsn1NDevice WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblPlnrQDsnDsn1NDevice::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQDsnDsn1NDevice& rst
		) {
	return loadRstBySQL("SELECT * FROM TblPlnrQDsnDsn1NDevice WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrQDsnDsn1NDevice
 ******************************************************************************/

PgTblPlnrQDsnDsn1NDevice::PgTblPlnrQDsnDsn1NDevice() : TblPlnrQDsnDsn1NDevice(), PgTable() {
};

PgTblPlnrQDsnDsn1NDevice::~PgTblPlnrQDsnDsn1NDevice() {
};

void PgTblPlnrQDsnDsn1NDevice::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrQDsnDsn1NDevice_insertRec", "INSERT INTO TblPlnrQDsnDsn1NDevice (jref, jnum, ref, dsnNum) VALUES ($1,$2,$3,$4) RETURNING qref", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQDsnDsn1NDevice_updateRec", "UPDATE TblPlnrQDsnDsn1NDevice SET jref = $1, jnum = $2, ref = $3, dsnNum = $4 WHERE qref = $5", 5, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQDsnDsn1NDevice_removeRecByQref", "DELETE FROM TblPlnrQDsnDsn1NDevice WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQDsnDsn1NDevice_removeRstByJref", "DELETE FROM TblPlnrQDsnDsn1NDevice WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrQDsnDsn1NDevice_loadRecByQref", "SELECT qref, jref, jnum, ref, dsnNum FROM TblPlnrQDsnDsn1NDevice WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQDsnDsn1NDevice_loadRstByJref", "SELECT qref, jref, jnum, ref, dsnNum FROM TblPlnrQDsnDsn1NDevice WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrQDsnDsn1NDevice::loadRec(
			PGresult* res
			, PlnrQDsnDsn1NDevice** rec
		) {
	char* ptr;

	PlnrQDsnDsn1NDevice* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrQDsnDsn1NDevice();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "dsnnum")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->dsnNum = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrQDsnDsn1NDevice::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrQDsnDsn1NDevice& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrQDsnDsn1NDevice* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "dsnnum")
		};

		while (numread < numrow) {
			rec = new PlnrQDsnDsn1NDevice();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->dsnNum = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrQDsnDsn1NDevice::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrQDsnDsn1NDevice** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDsnDsn1NDevice / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQDsnDsn1NDevice::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrQDsnDsn1NDevice& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDsnDsn1NDevice / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblPlnrQDsnDsn1NDevice::loadRecBySQL(
			const string& sqlstr
			, PlnrQDsnDsn1NDevice** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQDsnDsn1NDevice::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQDsnDsn1NDevice& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrQDsnDsn1NDevice::insertRec(
			PlnrQDsnDsn1NDevice* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _dsnNum = htonl(rec->dsnNum);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_dsnNum
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblPlnrQDsnDsn1NDevice_insertRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDsnDsn1NDevice_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblPlnrQDsnDsn1NDevice::insertRst(
			ListPlnrQDsnDsn1NDevice& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblPlnrQDsnDsn1NDevice::updateRec(
			PlnrQDsnDsn1NDevice* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _dsnNum = htonl(rec->dsnNum);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_dsnNum,
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

	res = PQexecPrepared(dbs, "TblPlnrQDsnDsn1NDevice_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDsnDsn1NDevice_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrQDsnDsn1NDevice::updateRst(
			ListPlnrQDsnDsn1NDevice& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblPlnrQDsnDsn1NDevice::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblPlnrQDsnDsn1NDevice_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDsnDsn1NDevice_removeRecByQref)\n");

	PQclear(res);
};

void PgTblPlnrQDsnDsn1NDevice::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblPlnrQDsnDsn1NDevice_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDsnDsn1NDevice_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblPlnrQDsnDsn1NDevice::loadRecByQref(
			ubigint qref
			, PlnrQDsnDsn1NDevice** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrQDsnDsn1NDevice_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblPlnrQDsnDsn1NDevice::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQDsnDsn1NDevice& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrQDsnDsn1NDevice_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

