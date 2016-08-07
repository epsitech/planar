/**
  * \file PlnrQCliAAMCalcEnv.cpp
  * Dbs and XML wrapper for table TblPlnrQCliAAMCalcEnv (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQCliAAMCalcEnv.h"

/******************************************************************************
 class PlnrQCliAAMCalcEnv
 ******************************************************************************/

PlnrQCliAAMCalcEnv::PlnrQCliAAMCalcEnv(
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

void PlnrQCliAAMCalcEnv::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "PlnrQCliAAMCalcEnv";

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
 class ListPlnrQCliAAMCalcEnv
 ******************************************************************************/

ListPlnrQCliAAMCalcEnv::ListPlnrQCliAAMCalcEnv() {
};

ListPlnrQCliAAMCalcEnv::ListPlnrQCliAAMCalcEnv(
			const ListPlnrQCliAAMCalcEnv& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQCliAAMCalcEnv(*(src.nodes[i]));
};

ListPlnrQCliAAMCalcEnv::~ListPlnrQCliAAMCalcEnv() {
	clear();
};

void ListPlnrQCliAAMCalcEnv::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrQCliAAMCalcEnv::size() const {
	return(nodes.size());
};

void ListPlnrQCliAAMCalcEnv::append(
			PlnrQCliAAMCalcEnv* rec
		) {
	nodes.push_back(rec);
};

ListPlnrQCliAAMCalcEnv& ListPlnrQCliAAMCalcEnv::operator=(
			const ListPlnrQCliAAMCalcEnv& src
		) {
	PlnrQCliAAMCalcEnv* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrQCliAAMCalcEnv(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListPlnrQCliAAMCalcEnv::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListPlnrQCliAAMCalcEnv";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblPlnrQCliAAMCalcEnv
 ******************************************************************************/

TblPlnrQCliAAMCalcEnv::TblPlnrQCliAAMCalcEnv() {
};

TblPlnrQCliAAMCalcEnv::~TblPlnrQCliAAMCalcEnv() {
};

bool TblPlnrQCliAAMCalcEnv::loadRecBySQL(
			const string& sqlstr
			, PlnrQCliAAMCalcEnv** rec
		) {
	return false;
};

ubigint TblPlnrQCliAAMCalcEnv::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQCliAAMCalcEnv& rst
		) {
	return 0;
};

void TblPlnrQCliAAMCalcEnv::insertRec(
			PlnrQCliAAMCalcEnv* rec
		) {
};

ubigint TblPlnrQCliAAMCalcEnv::insertNewRec(
			PlnrQCliAAMCalcEnv** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string x2SrefKKey
			, const string titX2SrefKKey
			, const string Val
		) {
	ubigint retval = 0;
	PlnrQCliAAMCalcEnv* _rec = NULL;

	_rec = new PlnrQCliAAMCalcEnv(0, jref, jnum, ref, x2SrefKKey, titX2SrefKKey, Val);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrQCliAAMCalcEnv::appendNewRecToRst(
			ListPlnrQCliAAMCalcEnv& rst
			, PlnrQCliAAMCalcEnv** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string x2SrefKKey
			, const string titX2SrefKKey
			, const string Val
		) {
	ubigint retval = 0;
	PlnrQCliAAMCalcEnv* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, x2SrefKKey, titX2SrefKKey, Val);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrQCliAAMCalcEnv::insertRst(
			ListPlnrQCliAAMCalcEnv& rst
		) {
};

void TblPlnrQCliAAMCalcEnv::updateRec(
			PlnrQCliAAMCalcEnv* rec
		) {
};

void TblPlnrQCliAAMCalcEnv::updateRst(
			ListPlnrQCliAAMCalcEnv& rst
		) {
};

void TblPlnrQCliAAMCalcEnv::removeRecByQref(
			ubigint qref
		) {
};

void TblPlnrQCliAAMCalcEnv::removeRstByJref(
			ubigint jref
		) {
};

bool TblPlnrQCliAAMCalcEnv::loadRecByQref(
			ubigint qref
			, PlnrQCliAAMCalcEnv** rec
		) {
	return false;
};

ubigint TblPlnrQCliAAMCalcEnv::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQCliAAMCalcEnv& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrQCliAAMCalcEnv
 ******************************************************************************/

MyTblPlnrQCliAAMCalcEnv::MyTblPlnrQCliAAMCalcEnv() : TblPlnrQCliAAMCalcEnv(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblPlnrQCliAAMCalcEnv::~MyTblPlnrQCliAAMCalcEnv() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblPlnrQCliAAMCalcEnv::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrQCliAAMCalcEnv (jref, jnum, ref, x2SrefKKey, Val) VALUES (?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrQCliAAMCalcEnv SET jref = ?, jnum = ?, ref = ?, x2SrefKKey = ?, Val = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblPlnrQCliAAMCalcEnv WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblPlnrQCliAAMCalcEnv WHERE jref = ?", false);
};

bool MyTblPlnrQCliAAMCalcEnv::loadRecBySQL(
			const string& sqlstr
			, PlnrQCliAAMCalcEnv** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrQCliAAMCalcEnv* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQCliAAMCalcEnv / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrQCliAAMCalcEnv();

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

ubigint MyTblPlnrQCliAAMCalcEnv::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQCliAAMCalcEnv& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrQCliAAMCalcEnv* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQCliAAMCalcEnv / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrQCliAAMCalcEnv();

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

void MyTblPlnrQCliAAMCalcEnv::insertRec(
			PlnrQCliAAMCalcEnv* rec
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

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQCliAAMCalcEnv / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQCliAAMCalcEnv / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblPlnrQCliAAMCalcEnv::insertRst(
			ListPlnrQCliAAMCalcEnv& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblPlnrQCliAAMCalcEnv::updateRec(
			PlnrQCliAAMCalcEnv* rec
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

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQCliAAMCalcEnv / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQCliAAMCalcEnv / stmtUpdateRec)\n");
};

void MyTblPlnrQCliAAMCalcEnv::updateRst(
			ListPlnrQCliAAMCalcEnv& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblPlnrQCliAAMCalcEnv::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQCliAAMCalcEnv / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQCliAAMCalcEnv / stmtRemoveRecByQref)\n");
};

void MyTblPlnrQCliAAMCalcEnv::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQCliAAMCalcEnv / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQCliAAMCalcEnv / stmtRemoveRstByJref)\n");
};

bool MyTblPlnrQCliAAMCalcEnv::loadRecByQref(
			ubigint qref
			, PlnrQCliAAMCalcEnv** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrQCliAAMCalcEnv WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblPlnrQCliAAMCalcEnv::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQCliAAMCalcEnv& rst
		) {
	return loadRstBySQL("SELECT * FROM TblPlnrQCliAAMCalcEnv WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrQCliAAMCalcEnv
 ******************************************************************************/

PgTblPlnrQCliAAMCalcEnv::PgTblPlnrQCliAAMCalcEnv() : TblPlnrQCliAAMCalcEnv(), PgTable() {
};

PgTblPlnrQCliAAMCalcEnv::~PgTblPlnrQCliAAMCalcEnv() {
};

void PgTblPlnrQCliAAMCalcEnv::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrQCliAAMCalcEnv_insertRec", "INSERT INTO TblPlnrQCliAAMCalcEnv (jref, jnum, ref, x2SrefKKey, Val) VALUES ($1,$2,$3,$4,$5) RETURNING qref", 5, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQCliAAMCalcEnv_updateRec", "UPDATE TblPlnrQCliAAMCalcEnv SET jref = $1, jnum = $2, ref = $3, x2SrefKKey = $4, Val = $5 WHERE qref = $6", 6, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQCliAAMCalcEnv_removeRecByQref", "DELETE FROM TblPlnrQCliAAMCalcEnv WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQCliAAMCalcEnv_removeRstByJref", "DELETE FROM TblPlnrQCliAAMCalcEnv WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrQCliAAMCalcEnv_loadRecByQref", "SELECT qref, jref, jnum, ref, x2SrefKKey, Val FROM TblPlnrQCliAAMCalcEnv WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQCliAAMCalcEnv_loadRstByJref", "SELECT qref, jref, jnum, ref, x2SrefKKey, Val FROM TblPlnrQCliAAMCalcEnv WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrQCliAAMCalcEnv::loadRec(
			PGresult* res
			, PlnrQCliAAMCalcEnv** rec
		) {
	char* ptr;

	PlnrQCliAAMCalcEnv* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrQCliAAMCalcEnv();

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

ubigint PgTblPlnrQCliAAMCalcEnv::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrQCliAAMCalcEnv& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrQCliAAMCalcEnv* rec;

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
			rec = new PlnrQCliAAMCalcEnv();

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

bool PgTblPlnrQCliAAMCalcEnv::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrQCliAAMCalcEnv** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQCliAAMCalcEnv / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQCliAAMCalcEnv::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrQCliAAMCalcEnv& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQCliAAMCalcEnv / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblPlnrQCliAAMCalcEnv::loadRecBySQL(
			const string& sqlstr
			, PlnrQCliAAMCalcEnv** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQCliAAMCalcEnv::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQCliAAMCalcEnv& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrQCliAAMCalcEnv::insertRec(
			PlnrQCliAAMCalcEnv* rec
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

	res = PQexecPrepared(dbs, "TblPlnrQCliAAMCalcEnv_insertRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQCliAAMCalcEnv_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblPlnrQCliAAMCalcEnv::insertRst(
			ListPlnrQCliAAMCalcEnv& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblPlnrQCliAAMCalcEnv::updateRec(
			PlnrQCliAAMCalcEnv* rec
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

	res = PQexecPrepared(dbs, "TblPlnrQCliAAMCalcEnv_updateRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQCliAAMCalcEnv_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrQCliAAMCalcEnv::updateRst(
			ListPlnrQCliAAMCalcEnv& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblPlnrQCliAAMCalcEnv::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblPlnrQCliAAMCalcEnv_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQCliAAMCalcEnv_removeRecByQref)\n");

	PQclear(res);
};

void PgTblPlnrQCliAAMCalcEnv::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblPlnrQCliAAMCalcEnv_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQCliAAMCalcEnv_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblPlnrQCliAAMCalcEnv::loadRecByQref(
			ubigint qref
			, PlnrQCliAAMCalcEnv** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrQCliAAMCalcEnv_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblPlnrQCliAAMCalcEnv::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQCliAAMCalcEnv& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrQCliAAMCalcEnv_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

