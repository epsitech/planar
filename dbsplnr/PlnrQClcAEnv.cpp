/**
  * \file PlnrQClcAEnv.cpp
  * Dbs and XML wrapper for table TblPlnrQClcAEnv (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQClcAEnv.h"

/******************************************************************************
 class PlnrQClcAEnv
 ******************************************************************************/

PlnrQClcAEnv::PlnrQClcAEnv(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint x1RefPlnrMCalcitem
			, const string x2SrefKKey
			, const string titX2SrefKKey
			, const string Val
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->x1RefPlnrMCalcitem = x1RefPlnrMCalcitem;
	this->x2SrefKKey = x2SrefKKey;
	this->titX2SrefKKey = titX2SrefKKey;
	this->Val = Val;
};

void PlnrQClcAEnv::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "PlnrQClcAEnv";

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
 class ListPlnrQClcAEnv
 ******************************************************************************/

ListPlnrQClcAEnv::ListPlnrQClcAEnv() {
};

ListPlnrQClcAEnv::ListPlnrQClcAEnv(
			const ListPlnrQClcAEnv& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQClcAEnv(*(src.nodes[i]));
};

ListPlnrQClcAEnv::~ListPlnrQClcAEnv() {
	clear();
};

void ListPlnrQClcAEnv::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrQClcAEnv::size() const {
	return(nodes.size());
};

void ListPlnrQClcAEnv::append(
			PlnrQClcAEnv* rec
		) {
	nodes.push_back(rec);
};

ListPlnrQClcAEnv& ListPlnrQClcAEnv::operator=(
			const ListPlnrQClcAEnv& src
		) {
	PlnrQClcAEnv* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrQClcAEnv(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListPlnrQClcAEnv::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListPlnrQClcAEnv";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblPlnrQClcAEnv
 ******************************************************************************/

TblPlnrQClcAEnv::TblPlnrQClcAEnv() {
};

TblPlnrQClcAEnv::~TblPlnrQClcAEnv() {
};

bool TblPlnrQClcAEnv::loadRecBySQL(
			const string& sqlstr
			, PlnrQClcAEnv** rec
		) {
	return false;
};

ubigint TblPlnrQClcAEnv::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQClcAEnv& rst
		) {
	return 0;
};

void TblPlnrQClcAEnv::insertRec(
			PlnrQClcAEnv* rec
		) {
};

ubigint TblPlnrQClcAEnv::insertNewRec(
			PlnrQClcAEnv** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint x1RefPlnrMCalcitem
			, const string x2SrefKKey
			, const string titX2SrefKKey
			, const string Val
		) {
	ubigint retval = 0;
	PlnrQClcAEnv* _rec = NULL;

	_rec = new PlnrQClcAEnv(0, jref, jnum, ref, x1RefPlnrMCalcitem, x2SrefKKey, titX2SrefKKey, Val);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrQClcAEnv::appendNewRecToRst(
			ListPlnrQClcAEnv& rst
			, PlnrQClcAEnv** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint x1RefPlnrMCalcitem
			, const string x2SrefKKey
			, const string titX2SrefKKey
			, const string Val
		) {
	ubigint retval = 0;
	PlnrQClcAEnv* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, x1RefPlnrMCalcitem, x2SrefKKey, titX2SrefKKey, Val);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrQClcAEnv::insertRst(
			ListPlnrQClcAEnv& rst
		) {
};

void TblPlnrQClcAEnv::updateRec(
			PlnrQClcAEnv* rec
		) {
};

void TblPlnrQClcAEnv::updateRst(
			ListPlnrQClcAEnv& rst
		) {
};

void TblPlnrQClcAEnv::removeRecByQref(
			ubigint qref
		) {
};

void TblPlnrQClcAEnv::removeRstByJref(
			ubigint jref
		) {
};

bool TblPlnrQClcAEnv::loadRecByQref(
			ubigint qref
			, PlnrQClcAEnv** rec
		) {
	return false;
};

ubigint TblPlnrQClcAEnv::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQClcAEnv& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrQClcAEnv
 ******************************************************************************/

MyTblPlnrQClcAEnv::MyTblPlnrQClcAEnv() : TblPlnrQClcAEnv(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblPlnrQClcAEnv::~MyTblPlnrQClcAEnv() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblPlnrQClcAEnv::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrQClcAEnv (jref, jnum, ref, x1RefPlnrMCalcitem, x2SrefKKey, Val) VALUES (?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrQClcAEnv SET jref = ?, jnum = ?, ref = ?, x1RefPlnrMCalcitem = ?, x2SrefKKey = ?, Val = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblPlnrQClcAEnv WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblPlnrQClcAEnv WHERE jref = ?", false);
};

bool MyTblPlnrQClcAEnv::loadRecBySQL(
			const string& sqlstr
			, PlnrQClcAEnv** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrQClcAEnv* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQClcAEnv / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrQClcAEnv();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->x1RefPlnrMCalcitem = atoll((char*) dbrow[4]); else _rec->x1RefPlnrMCalcitem = 0;
		if (dbrow[5]) _rec->x2SrefKKey.assign(dbrow[5], dblengths[5]); else _rec->x2SrefKKey = "";
		if (dbrow[6]) _rec->Val.assign(dbrow[6], dblengths[6]); else _rec->Val = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrQClcAEnv::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQClcAEnv& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrQClcAEnv* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQClcAEnv / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrQClcAEnv();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->x1RefPlnrMCalcitem = atoll((char*) dbrow[4]); else rec->x1RefPlnrMCalcitem = 0;
			if (dbrow[5]) rec->x2SrefKKey.assign(dbrow[5], dblengths[5]); else rec->x2SrefKKey = "";
			if (dbrow[6]) rec->Val.assign(dbrow[6], dblengths[6]); else rec->Val = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrQClcAEnv::insertRec(
			PlnrQClcAEnv* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	l[4] = rec->x2SrefKKey.length();
	l[5] = rec->Val.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->x1RefPlnrMCalcitem,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->x2SrefKKey.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->Val.c_str()),&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQClcAEnv / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQClcAEnv / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblPlnrQClcAEnv::insertRst(
			ListPlnrQClcAEnv& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblPlnrQClcAEnv::updateRec(
			PlnrQClcAEnv* rec
		) {
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	l[4] = rec->x2SrefKKey.length();
	l[5] = rec->Val.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->x1RefPlnrMCalcitem,&(l[3]),&(n[3]),&(e[3])), 
		bindCstring((char*) (rec->x2SrefKKey.c_str()),&(l[4]),&(n[4]),&(e[4])), 
		bindCstring((char*) (rec->Val.c_str()),&(l[5]),&(n[5]),&(e[5])), 
		bindUbigint(&rec->qref,&(l[6]),&(n[6]),&(e[6]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQClcAEnv / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQClcAEnv / stmtUpdateRec)\n");
};

void MyTblPlnrQClcAEnv::updateRst(
			ListPlnrQClcAEnv& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblPlnrQClcAEnv::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQClcAEnv / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQClcAEnv / stmtRemoveRecByQref)\n");
};

void MyTblPlnrQClcAEnv::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQClcAEnv / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQClcAEnv / stmtRemoveRstByJref)\n");
};

bool MyTblPlnrQClcAEnv::loadRecByQref(
			ubigint qref
			, PlnrQClcAEnv** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrQClcAEnv WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblPlnrQClcAEnv::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQClcAEnv& rst
		) {
	return loadRstBySQL("SELECT * FROM TblPlnrQClcAEnv WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrQClcAEnv
 ******************************************************************************/

PgTblPlnrQClcAEnv::PgTblPlnrQClcAEnv() : TblPlnrQClcAEnv(), PgTable() {
};

PgTblPlnrQClcAEnv::~PgTblPlnrQClcAEnv() {
};

void PgTblPlnrQClcAEnv::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrQClcAEnv_insertRec", "INSERT INTO TblPlnrQClcAEnv (jref, jnum, ref, x1RefPlnrMCalcitem, x2SrefKKey, Val) VALUES ($1,$2,$3,$4,$5,$6) RETURNING qref", 6, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQClcAEnv_updateRec", "UPDATE TblPlnrQClcAEnv SET jref = $1, jnum = $2, ref = $3, x1RefPlnrMCalcitem = $4, x2SrefKKey = $5, Val = $6 WHERE qref = $7", 7, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQClcAEnv_removeRecByQref", "DELETE FROM TblPlnrQClcAEnv WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQClcAEnv_removeRstByJref", "DELETE FROM TblPlnrQClcAEnv WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrQClcAEnv_loadRecByQref", "SELECT qref, jref, jnum, ref, x1RefPlnrMCalcitem, x2SrefKKey, Val FROM TblPlnrQClcAEnv WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQClcAEnv_loadRstByJref", "SELECT qref, jref, jnum, ref, x1RefPlnrMCalcitem, x2SrefKKey, Val FROM TblPlnrQClcAEnv WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrQClcAEnv::loadRec(
			PGresult* res
			, PlnrQClcAEnv** rec
		) {
	char* ptr;

	PlnrQClcAEnv* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrQClcAEnv();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1refplnrmcalcitem"),
			PQfnumber(res, "x2srefkkey"),
			PQfnumber(res, "val")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->x1RefPlnrMCalcitem = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->x2SrefKKey.assign(ptr, PQgetlength(res, 0, fnum[5]));
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->Val.assign(ptr, PQgetlength(res, 0, fnum[6]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrQClcAEnv::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrQClcAEnv& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrQClcAEnv* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1refplnrmcalcitem"),
			PQfnumber(res, "x2srefkkey"),
			PQfnumber(res, "val")
		};

		while (numread < numrow) {
			rec = new PlnrQClcAEnv();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->x1RefPlnrMCalcitem = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->x2SrefKKey.assign(ptr, PQgetlength(res, numread, fnum[5]));
			ptr = PQgetvalue(res, numread, fnum[6]); rec->Val.assign(ptr, PQgetlength(res, numread, fnum[6]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrQClcAEnv::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrQClcAEnv** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQClcAEnv / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQClcAEnv::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrQClcAEnv& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQClcAEnv / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblPlnrQClcAEnv::loadRecBySQL(
			const string& sqlstr
			, PlnrQClcAEnv** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQClcAEnv::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQClcAEnv& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrQClcAEnv::insertRec(
			PlnrQClcAEnv* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _x1RefPlnrMCalcitem = htonl64(rec->x1RefPlnrMCalcitem);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_x1RefPlnrMCalcitem,
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

	res = PQexecPrepared(dbs, "TblPlnrQClcAEnv_insertRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQClcAEnv_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblPlnrQClcAEnv::insertRst(
			ListPlnrQClcAEnv& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblPlnrQClcAEnv::updateRec(
			PlnrQClcAEnv* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _x1RefPlnrMCalcitem = htonl64(rec->x1RefPlnrMCalcitem);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_x1RefPlnrMCalcitem,
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

	res = PQexecPrepared(dbs, "TblPlnrQClcAEnv_updateRec", 7, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQClcAEnv_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrQClcAEnv::updateRst(
			ListPlnrQClcAEnv& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblPlnrQClcAEnv::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblPlnrQClcAEnv_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQClcAEnv_removeRecByQref)\n");

	PQclear(res);
};

void PgTblPlnrQClcAEnv::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblPlnrQClcAEnv_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQClcAEnv_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblPlnrQClcAEnv::loadRecByQref(
			ubigint qref
			, PlnrQClcAEnv** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrQClcAEnv_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblPlnrQClcAEnv::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQClcAEnv& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrQClcAEnv_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

