/**
  * \file PlnrQAriAMArrayEnv.cpp
  * Dbs and XML wrapper for table TblPlnrQAriAMArrayEnv (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQAriAMArrayEnv.h"

/******************************************************************************
 class PlnrQAriAMArrayEnv
 ******************************************************************************/

PlnrQAriAMArrayEnv::PlnrQAriAMArrayEnv(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string x2SrefKKey
			, const string titX2SrefKKey
			, const string Val
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->x2SrefKKey = x2SrefKKey;
	this->titX2SrefKKey = titX2SrefKKey;
	this->Val = Val;
};

void PlnrQAriAMArrayEnv::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "PlnrQAriAMArrayEnv";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "key", x2SrefKKey);
		writeString(wr, "key2", titX2SrefKKey);
		writeString(wr, "val", Val);
	} else {
		writeString(wr, "x2SrefKKey", x2SrefKKey);
		writeString(wr, "titX2SrefKKey", titX2SrefKKey);
		writeString(wr, "Val", Val);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListPlnrQAriAMArrayEnv
 ******************************************************************************/

ListPlnrQAriAMArrayEnv::ListPlnrQAriAMArrayEnv() {
};

ListPlnrQAriAMArrayEnv::ListPlnrQAriAMArrayEnv(
			const ListPlnrQAriAMArrayEnv& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQAriAMArrayEnv(*(src.nodes[i]));
};

ListPlnrQAriAMArrayEnv::~ListPlnrQAriAMArrayEnv() {
	clear();
};

void ListPlnrQAriAMArrayEnv::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrQAriAMArrayEnv::size() const {
	return(nodes.size());
};

void ListPlnrQAriAMArrayEnv::append(
			PlnrQAriAMArrayEnv* rec
		) {
	nodes.push_back(rec);
};

ListPlnrQAriAMArrayEnv& ListPlnrQAriAMArrayEnv::operator=(
			const ListPlnrQAriAMArrayEnv& src
		) {
	PlnrQAriAMArrayEnv* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrQAriAMArrayEnv(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListPlnrQAriAMArrayEnv::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListPlnrQAriAMArrayEnv";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblPlnrQAriAMArrayEnv
 ******************************************************************************/

TblPlnrQAriAMArrayEnv::TblPlnrQAriAMArrayEnv() {
};

TblPlnrQAriAMArrayEnv::~TblPlnrQAriAMArrayEnv() {
};

bool TblPlnrQAriAMArrayEnv::loadRecBySQL(
			const string& sqlstr
			, PlnrQAriAMArrayEnv** rec
		) {
	return false;
};

ubigint TblPlnrQAriAMArrayEnv::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQAriAMArrayEnv& rst
		) {
	return 0;
};

void TblPlnrQAriAMArrayEnv::insertRec(
			PlnrQAriAMArrayEnv* rec
		) {
};

ubigint TblPlnrQAriAMArrayEnv::insertNewRec(
			PlnrQAriAMArrayEnv** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string x2SrefKKey
			, const string titX2SrefKKey
			, const string Val
		) {
	ubigint retval = 0;
	PlnrQAriAMArrayEnv* _rec = NULL;

	_rec = new PlnrQAriAMArrayEnv(0, jref, jnum, ref, x2SrefKKey, titX2SrefKKey, Val);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrQAriAMArrayEnv::appendNewRecToRst(
			ListPlnrQAriAMArrayEnv& rst
			, PlnrQAriAMArrayEnv** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string x2SrefKKey
			, const string titX2SrefKKey
			, const string Val
		) {
	ubigint retval = 0;
	PlnrQAriAMArrayEnv* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, x2SrefKKey, titX2SrefKKey, Val);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrQAriAMArrayEnv::insertRst(
			ListPlnrQAriAMArrayEnv& rst
		) {
};

void TblPlnrQAriAMArrayEnv::updateRec(
			PlnrQAriAMArrayEnv* rec
		) {
};

void TblPlnrQAriAMArrayEnv::updateRst(
			ListPlnrQAriAMArrayEnv& rst
		) {
};

void TblPlnrQAriAMArrayEnv::removeRecByQref(
			ubigint qref
		) {
};

void TblPlnrQAriAMArrayEnv::removeRstByJref(
			ubigint jref
		) {
};

bool TblPlnrQAriAMArrayEnv::loadRecByQref(
			ubigint qref
			, PlnrQAriAMArrayEnv** rec
		) {
	return false;
};

ubigint TblPlnrQAriAMArrayEnv::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQAriAMArrayEnv& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrQAriAMArrayEnv
 ******************************************************************************/

MyTblPlnrQAriAMArrayEnv::MyTblPlnrQAriAMArrayEnv() : TblPlnrQAriAMArrayEnv(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblPlnrQAriAMArrayEnv::~MyTblPlnrQAriAMArrayEnv() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblPlnrQAriAMArrayEnv::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrQAriAMArrayEnv (jref, jnum, ref, x2SrefKKey, Val) VALUES (?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrQAriAMArrayEnv SET jref = ?, jnum = ?, ref = ?, x2SrefKKey = ?, Val = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblPlnrQAriAMArrayEnv WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblPlnrQAriAMArrayEnv WHERE jref = ?", false);
};

bool MyTblPlnrQAriAMArrayEnv::loadRecBySQL(
			const string& sqlstr
			, PlnrQAriAMArrayEnv** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrQAriAMArrayEnv* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQAriAMArrayEnv / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrQAriAMArrayEnv();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->x2SrefKKey.assign(dbrow[4], dblengths[4]); else _rec->x2SrefKKey = "";
		if (dbrow[5]) _rec->Val.assign(dbrow[5], dblengths[5]); else _rec->Val = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrQAriAMArrayEnv::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQAriAMArrayEnv& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrQAriAMArrayEnv* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQAriAMArrayEnv / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrQAriAMArrayEnv();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->x2SrefKKey.assign(dbrow[4], dblengths[4]); else rec->x2SrefKKey = "";
			if (dbrow[5]) rec->Val.assign(dbrow[5], dblengths[5]); else rec->Val = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrQAriAMArrayEnv::insertRec(
			PlnrQAriAMArrayEnv* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[3] = rec->x2SrefKKey.length();
	l[4] = rec->Val.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->x2SrefKKey.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Val.c_str()),&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQAriAMArrayEnv / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQAriAMArrayEnv / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblPlnrQAriAMArrayEnv::insertRst(
			ListPlnrQAriAMArrayEnv& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblPlnrQAriAMArrayEnv::updateRec(
			PlnrQAriAMArrayEnv* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	l[3] = rec->x2SrefKKey.length();
	l[4] = rec->Val.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])), 
		bindCstring((char*) (rec->x2SrefKKey.c_str()),&(l[3]),&(n[3]),&(e[3])), 
		bindCstring((char*) (rec->Val.c_str()),&(l[4]),&(n[4]),&(e[4])), 
		bindUbigint(&rec->qref,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQAriAMArrayEnv / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQAriAMArrayEnv / stmtUpdateRec)\n");
};

void MyTblPlnrQAriAMArrayEnv::updateRst(
			ListPlnrQAriAMArrayEnv& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblPlnrQAriAMArrayEnv::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQAriAMArrayEnv / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQAriAMArrayEnv / stmtRemoveRecByQref)\n");
};

void MyTblPlnrQAriAMArrayEnv::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQAriAMArrayEnv / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQAriAMArrayEnv / stmtRemoveRstByJref)\n");
};

bool MyTblPlnrQAriAMArrayEnv::loadRecByQref(
			ubigint qref
			, PlnrQAriAMArrayEnv** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrQAriAMArrayEnv WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblPlnrQAriAMArrayEnv::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQAriAMArrayEnv& rst
		) {
	return loadRstBySQL("SELECT * FROM TblPlnrQAriAMArrayEnv WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrQAriAMArrayEnv
 ******************************************************************************/

PgTblPlnrQAriAMArrayEnv::PgTblPlnrQAriAMArrayEnv() : TblPlnrQAriAMArrayEnv(), PgTable() {
};

PgTblPlnrQAriAMArrayEnv::~PgTblPlnrQAriAMArrayEnv() {
};

void PgTblPlnrQAriAMArrayEnv::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrQAriAMArrayEnv_insertRec", "INSERT INTO TblPlnrQAriAMArrayEnv (jref, jnum, ref, x2SrefKKey, Val) VALUES ($1,$2,$3,$4,$5) RETURNING qref", 5, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQAriAMArrayEnv_updateRec", "UPDATE TblPlnrQAriAMArrayEnv SET jref = $1, jnum = $2, ref = $3, x2SrefKKey = $4, Val = $5 WHERE qref = $6", 6, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQAriAMArrayEnv_removeRecByQref", "DELETE FROM TblPlnrQAriAMArrayEnv WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQAriAMArrayEnv_removeRstByJref", "DELETE FROM TblPlnrQAriAMArrayEnv WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrQAriAMArrayEnv_loadRecByQref", "SELECT qref, jref, jnum, ref, x2SrefKKey, Val FROM TblPlnrQAriAMArrayEnv WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQAriAMArrayEnv_loadRstByJref", "SELECT qref, jref, jnum, ref, x2SrefKKey, Val FROM TblPlnrQAriAMArrayEnv WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrQAriAMArrayEnv::loadRec(
			PGresult* res
			, PlnrQAriAMArrayEnv** rec
		) {
	char* ptr;

	PlnrQAriAMArrayEnv* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrQAriAMArrayEnv();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "x2srefkkey"),
			PQfnumber(res, "val")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->x2SrefKKey.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->Val.assign(ptr, PQgetlength(res, 0, fnum[5]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrQAriAMArrayEnv::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrQAriAMArrayEnv& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrQAriAMArrayEnv* rec;

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
			PQfnumber(res, "val")
		};

		while (numread < numrow) {
			rec = new PlnrQAriAMArrayEnv();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->x2SrefKKey.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->Val.assign(ptr, PQgetlength(res, numread, fnum[5]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrQAriAMArrayEnv::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrQAriAMArrayEnv** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQAriAMArrayEnv / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQAriAMArrayEnv::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrQAriAMArrayEnv& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQAriAMArrayEnv / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblPlnrQAriAMArrayEnv::loadRecBySQL(
			const string& sqlstr
			, PlnrQAriAMArrayEnv** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQAriAMArrayEnv::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQAriAMArrayEnv& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrQAriAMArrayEnv::insertRec(
			PlnrQAriAMArrayEnv* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->x2SrefKKey.c_str(),
		rec->Val.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		0
	};
	const int f[] = {1, 1, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblPlnrQAriAMArrayEnv_insertRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQAriAMArrayEnv_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblPlnrQAriAMArrayEnv::insertRst(
			ListPlnrQAriAMArrayEnv& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblPlnrQAriAMArrayEnv::updateRec(
			PlnrQAriAMArrayEnv* rec
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
		rec->x2SrefKKey.c_str(),
		rec->Val.c_str(),
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblPlnrQAriAMArrayEnv_updateRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQAriAMArrayEnv_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrQAriAMArrayEnv::updateRst(
			ListPlnrQAriAMArrayEnv& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblPlnrQAriAMArrayEnv::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblPlnrQAriAMArrayEnv_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQAriAMArrayEnv_removeRecByQref)\n");

	PQclear(res);
};

void PgTblPlnrQAriAMArrayEnv::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblPlnrQAriAMArrayEnv_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQAriAMArrayEnv_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblPlnrQAriAMArrayEnv::loadRecByQref(
			ubigint qref
			, PlnrQAriAMArrayEnv** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrQAriAMArrayEnv_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblPlnrQAriAMArrayEnv::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQAriAMArrayEnv& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrQAriAMArrayEnv_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

