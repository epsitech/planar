/**
  * \file PlnrQArrAEnv.cpp
  * Dbs and XML wrapper for table TblPlnrQArrAEnv (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQArrAEnv.h"

/******************************************************************************
 class PlnrQArrAEnv
 ******************************************************************************/

PlnrQArrAEnv::PlnrQArrAEnv(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint x1RefPlnrMArrayitem
			, const string x2SrefKKey
			, const string titX2SrefKKey
			, const string Val
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->x1RefPlnrMArrayitem = x1RefPlnrMArrayitem;
	this->x2SrefKKey = x2SrefKKey;
	this->titX2SrefKKey = titX2SrefKKey;
	this->Val = Val;
};

void PlnrQArrAEnv::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "PlnrQArrAEnv";

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
 class ListPlnrQArrAEnv
 ******************************************************************************/

ListPlnrQArrAEnv::ListPlnrQArrAEnv() {
};

ListPlnrQArrAEnv::ListPlnrQArrAEnv(
			const ListPlnrQArrAEnv& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQArrAEnv(*(src.nodes[i]));
};

ListPlnrQArrAEnv::~ListPlnrQArrAEnv() {
	clear();
};

void ListPlnrQArrAEnv::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrQArrAEnv::size() const {
	return(nodes.size());
};

void ListPlnrQArrAEnv::append(
			PlnrQArrAEnv* rec
		) {
	nodes.push_back(rec);
};

ListPlnrQArrAEnv& ListPlnrQArrAEnv::operator=(
			const ListPlnrQArrAEnv& src
		) {
	PlnrQArrAEnv* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrQArrAEnv(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListPlnrQArrAEnv::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListPlnrQArrAEnv";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblPlnrQArrAEnv
 ******************************************************************************/

TblPlnrQArrAEnv::TblPlnrQArrAEnv() {
};

TblPlnrQArrAEnv::~TblPlnrQArrAEnv() {
};

bool TblPlnrQArrAEnv::loadRecBySQL(
			const string& sqlstr
			, PlnrQArrAEnv** rec
		) {
	return false;
};

ubigint TblPlnrQArrAEnv::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQArrAEnv& rst
		) {
	return 0;
};

void TblPlnrQArrAEnv::insertRec(
			PlnrQArrAEnv* rec
		) {
};

ubigint TblPlnrQArrAEnv::insertNewRec(
			PlnrQArrAEnv** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint x1RefPlnrMArrayitem
			, const string x2SrefKKey
			, const string titX2SrefKKey
			, const string Val
		) {
	ubigint retval = 0;
	PlnrQArrAEnv* _rec = NULL;

	_rec = new PlnrQArrAEnv(0, jref, jnum, ref, x1RefPlnrMArrayitem, x2SrefKKey, titX2SrefKKey, Val);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrQArrAEnv::appendNewRecToRst(
			ListPlnrQArrAEnv& rst
			, PlnrQArrAEnv** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint x1RefPlnrMArrayitem
			, const string x2SrefKKey
			, const string titX2SrefKKey
			, const string Val
		) {
	ubigint retval = 0;
	PlnrQArrAEnv* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, x1RefPlnrMArrayitem, x2SrefKKey, titX2SrefKKey, Val);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrQArrAEnv::insertRst(
			ListPlnrQArrAEnv& rst
		) {
};

void TblPlnrQArrAEnv::updateRec(
			PlnrQArrAEnv* rec
		) {
};

void TblPlnrQArrAEnv::updateRst(
			ListPlnrQArrAEnv& rst
		) {
};

void TblPlnrQArrAEnv::removeRecByQref(
			ubigint qref
		) {
};

void TblPlnrQArrAEnv::removeRstByJref(
			ubigint jref
		) {
};

bool TblPlnrQArrAEnv::loadRecByQref(
			ubigint qref
			, PlnrQArrAEnv** rec
		) {
	return false;
};

ubigint TblPlnrQArrAEnv::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQArrAEnv& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrQArrAEnv
 ******************************************************************************/

MyTblPlnrQArrAEnv::MyTblPlnrQArrAEnv() : TblPlnrQArrAEnv(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblPlnrQArrAEnv::~MyTblPlnrQArrAEnv() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblPlnrQArrAEnv::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrQArrAEnv (jref, jnum, ref, x1RefPlnrMArrayitem, x2SrefKKey, Val) VALUES (?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrQArrAEnv SET jref = ?, jnum = ?, ref = ?, x1RefPlnrMArrayitem = ?, x2SrefKKey = ?, Val = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblPlnrQArrAEnv WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblPlnrQArrAEnv WHERE jref = ?", false);
};

bool MyTblPlnrQArrAEnv::loadRecBySQL(
			const string& sqlstr
			, PlnrQArrAEnv** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrQArrAEnv* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQArrAEnv / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrQArrAEnv();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->x1RefPlnrMArrayitem = atoll((char*) dbrow[4]); else _rec->x1RefPlnrMArrayitem = 0;
		if (dbrow[5]) _rec->x2SrefKKey.assign(dbrow[5], dblengths[5]); else _rec->x2SrefKKey = "";
		if (dbrow[6]) _rec->Val.assign(dbrow[6], dblengths[6]); else _rec->Val = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrQArrAEnv::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQArrAEnv& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrQArrAEnv* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQArrAEnv / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrQArrAEnv();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->x1RefPlnrMArrayitem = atoll((char*) dbrow[4]); else rec->x1RefPlnrMArrayitem = 0;
			if (dbrow[5]) rec->x2SrefKKey.assign(dbrow[5], dblengths[5]); else rec->x2SrefKKey = "";
			if (dbrow[6]) rec->Val.assign(dbrow[6], dblengths[6]); else rec->Val = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrQArrAEnv::insertRec(
			PlnrQArrAEnv* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	l[4] = rec->x2SrefKKey.length();
	l[5] = rec->Val.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->x1RefPlnrMArrayitem,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->x2SrefKKey.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->Val.c_str()),&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQArrAEnv / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQArrAEnv / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblPlnrQArrAEnv::insertRst(
			ListPlnrQArrAEnv& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblPlnrQArrAEnv::updateRec(
			PlnrQArrAEnv* rec
		) {
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	l[4] = rec->x2SrefKKey.length();
	l[5] = rec->Val.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->x1RefPlnrMArrayitem,&(l[3]),&(n[3]),&(e[3])), 
		bindCstring((char*) (rec->x2SrefKKey.c_str()),&(l[4]),&(n[4]),&(e[4])), 
		bindCstring((char*) (rec->Val.c_str()),&(l[5]),&(n[5]),&(e[5])), 
		bindUbigint(&rec->qref,&(l[6]),&(n[6]),&(e[6]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQArrAEnv / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQArrAEnv / stmtUpdateRec)\n");
};

void MyTblPlnrQArrAEnv::updateRst(
			ListPlnrQArrAEnv& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblPlnrQArrAEnv::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQArrAEnv / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQArrAEnv / stmtRemoveRecByQref)\n");
};

void MyTblPlnrQArrAEnv::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQArrAEnv / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQArrAEnv / stmtRemoveRstByJref)\n");
};

bool MyTblPlnrQArrAEnv::loadRecByQref(
			ubigint qref
			, PlnrQArrAEnv** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrQArrAEnv WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblPlnrQArrAEnv::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQArrAEnv& rst
		) {
	return loadRstBySQL("SELECT * FROM TblPlnrQArrAEnv WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrQArrAEnv
 ******************************************************************************/

PgTblPlnrQArrAEnv::PgTblPlnrQArrAEnv() : TblPlnrQArrAEnv(), PgTable() {
};

PgTblPlnrQArrAEnv::~PgTblPlnrQArrAEnv() {
};

void PgTblPlnrQArrAEnv::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrQArrAEnv_insertRec", "INSERT INTO TblPlnrQArrAEnv (jref, jnum, ref, x1RefPlnrMArrayitem, x2SrefKKey, Val) VALUES ($1,$2,$3,$4,$5,$6) RETURNING qref", 6, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQArrAEnv_updateRec", "UPDATE TblPlnrQArrAEnv SET jref = $1, jnum = $2, ref = $3, x1RefPlnrMArrayitem = $4, x2SrefKKey = $5, Val = $6 WHERE qref = $7", 7, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQArrAEnv_removeRecByQref", "DELETE FROM TblPlnrQArrAEnv WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQArrAEnv_removeRstByJref", "DELETE FROM TblPlnrQArrAEnv WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrQArrAEnv_loadRecByQref", "SELECT qref, jref, jnum, ref, x1RefPlnrMArrayitem, x2SrefKKey, Val FROM TblPlnrQArrAEnv WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQArrAEnv_loadRstByJref", "SELECT qref, jref, jnum, ref, x1RefPlnrMArrayitem, x2SrefKKey, Val FROM TblPlnrQArrAEnv WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrQArrAEnv::loadRec(
			PGresult* res
			, PlnrQArrAEnv** rec
		) {
	char* ptr;

	PlnrQArrAEnv* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrQArrAEnv();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1refplnrmarrayitem"),
			PQfnumber(res, "x2srefkkey"),
			PQfnumber(res, "val")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->x1RefPlnrMArrayitem = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->x2SrefKKey.assign(ptr, PQgetlength(res, 0, fnum[5]));
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->Val.assign(ptr, PQgetlength(res, 0, fnum[6]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrQArrAEnv::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrQArrAEnv& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrQArrAEnv* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1refplnrmarrayitem"),
			PQfnumber(res, "x2srefkkey"),
			PQfnumber(res, "val")
		};

		while (numread < numrow) {
			rec = new PlnrQArrAEnv();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->x1RefPlnrMArrayitem = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->x2SrefKKey.assign(ptr, PQgetlength(res, numread, fnum[5]));
			ptr = PQgetvalue(res, numread, fnum[6]); rec->Val.assign(ptr, PQgetlength(res, numread, fnum[6]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrQArrAEnv::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrQArrAEnv** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQArrAEnv / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQArrAEnv::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrQArrAEnv& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQArrAEnv / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblPlnrQArrAEnv::loadRecBySQL(
			const string& sqlstr
			, PlnrQArrAEnv** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQArrAEnv::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQArrAEnv& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrQArrAEnv::insertRec(
			PlnrQArrAEnv* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _x1RefPlnrMArrayitem = htonl64(rec->x1RefPlnrMArrayitem);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_x1RefPlnrMArrayitem,
		rec->x2SrefKKey.c_str(),
		rec->Val.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0
	};
	const int f[] = {1, 1, 1, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblPlnrQArrAEnv_insertRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQArrAEnv_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblPlnrQArrAEnv::insertRst(
			ListPlnrQArrAEnv& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblPlnrQArrAEnv::updateRec(
			PlnrQArrAEnv* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _x1RefPlnrMArrayitem = htonl64(rec->x1RefPlnrMArrayitem);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_x1RefPlnrMArrayitem,
		rec->x2SrefKKey.c_str(),
		rec->Val.c_str(),
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblPlnrQArrAEnv_updateRec", 7, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQArrAEnv_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrQArrAEnv::updateRst(
			ListPlnrQArrAEnv& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblPlnrQArrAEnv::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblPlnrQArrAEnv_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQArrAEnv_removeRecByQref)\n");

	PQclear(res);
};

void PgTblPlnrQArrAEnv::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblPlnrQArrAEnv_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQArrAEnv_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblPlnrQArrAEnv::loadRecByQref(
			ubigint qref
			, PlnrQArrAEnv** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrQArrAEnv_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblPlnrQArrAEnv::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQArrAEnv& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrQArrAEnv_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

