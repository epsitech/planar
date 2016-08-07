/**
  * \file PlnrQDtpAPar.cpp
  * Dbs and XML wrapper for table TblPlnrQDtpAPar (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQDtpAPar.h"

/******************************************************************************
 class PlnrQDtpAPar
 ******************************************************************************/

PlnrQDtpAPar::PlnrQDtpAPar(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string x2SrefKKey
			, const string titX2SrefKKey
			, const ubigint refPlnrMFile
			, const string stubRefPlnrMFile
			, const string Val
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->x2SrefKKey = x2SrefKKey;
	this->titX2SrefKKey = titX2SrefKKey;
	this->refPlnrMFile = refPlnrMFile;
	this->stubRefPlnrMFile = stubRefPlnrMFile;
	this->Val = Val;
};

void PlnrQDtpAPar::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "PlnrQDtpAPar";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "key", x2SrefKKey);
		writeString(wr, "key2", titX2SrefKKey);
		writeString(wr, "fil", stubRefPlnrMFile);
		writeString(wr, "val", Val);
	} else {
		writeString(wr, "x2SrefKKey", x2SrefKKey);
		writeString(wr, "titX2SrefKKey", titX2SrefKKey);
		writeString(wr, "stubRefPlnrMFile", stubRefPlnrMFile);
		writeString(wr, "Val", Val);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListPlnrQDtpAPar
 ******************************************************************************/

ListPlnrQDtpAPar::ListPlnrQDtpAPar() {
};

ListPlnrQDtpAPar::ListPlnrQDtpAPar(
			const ListPlnrQDtpAPar& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQDtpAPar(*(src.nodes[i]));
};

ListPlnrQDtpAPar::~ListPlnrQDtpAPar() {
	clear();
};

void ListPlnrQDtpAPar::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrQDtpAPar::size() const {
	return(nodes.size());
};

void ListPlnrQDtpAPar::append(
			PlnrQDtpAPar* rec
		) {
	nodes.push_back(rec);
};

ListPlnrQDtpAPar& ListPlnrQDtpAPar::operator=(
			const ListPlnrQDtpAPar& src
		) {
	PlnrQDtpAPar* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrQDtpAPar(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListPlnrQDtpAPar::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListPlnrQDtpAPar";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblPlnrQDtpAPar
 ******************************************************************************/

TblPlnrQDtpAPar::TblPlnrQDtpAPar() {
};

TblPlnrQDtpAPar::~TblPlnrQDtpAPar() {
};

bool TblPlnrQDtpAPar::loadRecBySQL(
			const string& sqlstr
			, PlnrQDtpAPar** rec
		) {
	return false;
};

ubigint TblPlnrQDtpAPar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQDtpAPar& rst
		) {
	return 0;
};

void TblPlnrQDtpAPar::insertRec(
			PlnrQDtpAPar* rec
		) {
};

ubigint TblPlnrQDtpAPar::insertNewRec(
			PlnrQDtpAPar** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string x2SrefKKey
			, const string titX2SrefKKey
			, const ubigint refPlnrMFile
			, const string stubRefPlnrMFile
			, const string Val
		) {
	ubigint retval = 0;
	PlnrQDtpAPar* _rec = NULL;

	_rec = new PlnrQDtpAPar(0, jref, jnum, ref, x2SrefKKey, titX2SrefKKey, refPlnrMFile, stubRefPlnrMFile, Val);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrQDtpAPar::appendNewRecToRst(
			ListPlnrQDtpAPar& rst
			, PlnrQDtpAPar** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string x2SrefKKey
			, const string titX2SrefKKey
			, const ubigint refPlnrMFile
			, const string stubRefPlnrMFile
			, const string Val
		) {
	ubigint retval = 0;
	PlnrQDtpAPar* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, x2SrefKKey, titX2SrefKKey, refPlnrMFile, stubRefPlnrMFile, Val);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrQDtpAPar::insertRst(
			ListPlnrQDtpAPar& rst
		) {
};

void TblPlnrQDtpAPar::updateRec(
			PlnrQDtpAPar* rec
		) {
};

void TblPlnrQDtpAPar::updateRst(
			ListPlnrQDtpAPar& rst
		) {
};

void TblPlnrQDtpAPar::removeRecByQref(
			ubigint qref
		) {
};

void TblPlnrQDtpAPar::removeRstByJref(
			ubigint jref
		) {
};

bool TblPlnrQDtpAPar::loadRecByQref(
			ubigint qref
			, PlnrQDtpAPar** rec
		) {
	return false;
};

ubigint TblPlnrQDtpAPar::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQDtpAPar& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrQDtpAPar
 ******************************************************************************/

MyTblPlnrQDtpAPar::MyTblPlnrQDtpAPar() : TblPlnrQDtpAPar(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblPlnrQDtpAPar::~MyTblPlnrQDtpAPar() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblPlnrQDtpAPar::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrQDtpAPar (jref, jnum, ref, x2SrefKKey, refPlnrMFile, Val) VALUES (?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrQDtpAPar SET jref = ?, jnum = ?, ref = ?, x2SrefKKey = ?, refPlnrMFile = ?, Val = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblPlnrQDtpAPar WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblPlnrQDtpAPar WHERE jref = ?", false);
};

bool MyTblPlnrQDtpAPar::loadRecBySQL(
			const string& sqlstr
			, PlnrQDtpAPar** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrQDtpAPar* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQDtpAPar / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrQDtpAPar();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->x2SrefKKey.assign(dbrow[4], dblengths[4]); else _rec->x2SrefKKey = "";
		if (dbrow[5]) _rec->refPlnrMFile = atoll((char*) dbrow[5]); else _rec->refPlnrMFile = 0;
		if (dbrow[6]) _rec->Val.assign(dbrow[6], dblengths[6]); else _rec->Val = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrQDtpAPar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQDtpAPar& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrQDtpAPar* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQDtpAPar / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrQDtpAPar();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->x2SrefKKey.assign(dbrow[4], dblengths[4]); else rec->x2SrefKKey = "";
			if (dbrow[5]) rec->refPlnrMFile = atoll((char*) dbrow[5]); else rec->refPlnrMFile = 0;
			if (dbrow[6]) rec->Val.assign(dbrow[6], dblengths[6]); else rec->Val = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrQDtpAPar::insertRec(
			PlnrQDtpAPar* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	l[3] = rec->x2SrefKKey.length();
	l[5] = rec->Val.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->x2SrefKKey.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->refPlnrMFile,&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->Val.c_str()),&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQDtpAPar / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQDtpAPar / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblPlnrQDtpAPar::insertRst(
			ListPlnrQDtpAPar& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblPlnrQDtpAPar::updateRec(
			PlnrQDtpAPar* rec
		) {
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	l[3] = rec->x2SrefKKey.length();
	l[5] = rec->Val.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])), 
		bindCstring((char*) (rec->x2SrefKKey.c_str()),&(l[3]),&(n[3]),&(e[3])), 
		bindUbigint(&rec->refPlnrMFile,&(l[4]),&(n[4]),&(e[4])), 
		bindCstring((char*) (rec->Val.c_str()),&(l[5]),&(n[5]),&(e[5])), 
		bindUbigint(&rec->qref,&(l[6]),&(n[6]),&(e[6]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQDtpAPar / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQDtpAPar / stmtUpdateRec)\n");
};

void MyTblPlnrQDtpAPar::updateRst(
			ListPlnrQDtpAPar& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblPlnrQDtpAPar::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQDtpAPar / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQDtpAPar / stmtRemoveRecByQref)\n");
};

void MyTblPlnrQDtpAPar::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQDtpAPar / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQDtpAPar / stmtRemoveRstByJref)\n");
};

bool MyTblPlnrQDtpAPar::loadRecByQref(
			ubigint qref
			, PlnrQDtpAPar** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrQDtpAPar WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblPlnrQDtpAPar::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQDtpAPar& rst
		) {
	return loadRstBySQL("SELECT * FROM TblPlnrQDtpAPar WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrQDtpAPar
 ******************************************************************************/

PgTblPlnrQDtpAPar::PgTblPlnrQDtpAPar() : TblPlnrQDtpAPar(), PgTable() {
};

PgTblPlnrQDtpAPar::~PgTblPlnrQDtpAPar() {
};

void PgTblPlnrQDtpAPar::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrQDtpAPar_insertRec", "INSERT INTO TblPlnrQDtpAPar (jref, jnum, ref, x2SrefKKey, refPlnrMFile, Val) VALUES ($1,$2,$3,$4,$5,$6) RETURNING qref", 6, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQDtpAPar_updateRec", "UPDATE TblPlnrQDtpAPar SET jref = $1, jnum = $2, ref = $3, x2SrefKKey = $4, refPlnrMFile = $5, Val = $6 WHERE qref = $7", 7, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQDtpAPar_removeRecByQref", "DELETE FROM TblPlnrQDtpAPar WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQDtpAPar_removeRstByJref", "DELETE FROM TblPlnrQDtpAPar WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrQDtpAPar_loadRecByQref", "SELECT qref, jref, jnum, ref, x2SrefKKey, refPlnrMFile, Val FROM TblPlnrQDtpAPar WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQDtpAPar_loadRstByJref", "SELECT qref, jref, jnum, ref, x2SrefKKey, refPlnrMFile, Val FROM TblPlnrQDtpAPar WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrQDtpAPar::loadRec(
			PGresult* res
			, PlnrQDtpAPar** rec
		) {
	char* ptr;

	PlnrQDtpAPar* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrQDtpAPar();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "x2srefkkey"),
			PQfnumber(res, "refplnrmfile"),
			PQfnumber(res, "val")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->x2SrefKKey.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->refPlnrMFile = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->Val.assign(ptr, PQgetlength(res, 0, fnum[6]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrQDtpAPar::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrQDtpAPar& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrQDtpAPar* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "x2srefkkey"),
			PQfnumber(res, "refplnrmfile"),
			PQfnumber(res, "val")
		};

		while (numread < numrow) {
			rec = new PlnrQDtpAPar();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->x2SrefKKey.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->refPlnrMFile = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->Val.assign(ptr, PQgetlength(res, numread, fnum[6]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrQDtpAPar::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrQDtpAPar** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDtpAPar / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQDtpAPar::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrQDtpAPar& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDtpAPar / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblPlnrQDtpAPar::loadRecBySQL(
			const string& sqlstr
			, PlnrQDtpAPar** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQDtpAPar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQDtpAPar& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrQDtpAPar::insertRec(
			PlnrQDtpAPar* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _refPlnrMFile = htonl64(rec->refPlnrMFile);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->x2SrefKKey.c_str(),
		(char*) &_refPlnrMFile,
		rec->Val.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		0
	};
	const int f[] = {1, 1, 1, 0, 1, 0};

	res = PQexecPrepared(dbs, "TblPlnrQDtpAPar_insertRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDtpAPar_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblPlnrQDtpAPar::insertRst(
			ListPlnrQDtpAPar& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblPlnrQDtpAPar::updateRec(
			PlnrQDtpAPar* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _refPlnrMFile = htonl64(rec->refPlnrMFile);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->x2SrefKKey.c_str(),
		(char*) &_refPlnrMFile,
		rec->Val.c_str(),
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblPlnrQDtpAPar_updateRec", 7, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDtpAPar_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrQDtpAPar::updateRst(
			ListPlnrQDtpAPar& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblPlnrQDtpAPar::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblPlnrQDtpAPar_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDtpAPar_removeRecByQref)\n");

	PQclear(res);
};

void PgTblPlnrQDtpAPar::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblPlnrQDtpAPar_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDtpAPar_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblPlnrQDtpAPar::loadRecByQref(
			ubigint qref
			, PlnrQDtpAPar** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrQDtpAPar_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblPlnrQDtpAPar::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQDtpAPar& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrQDtpAPar_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

