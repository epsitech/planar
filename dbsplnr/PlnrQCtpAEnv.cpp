/**
  * \file PlnrQCtpAEnv.cpp
  * Dbs and XML wrapper for table TblPlnrQCtpAEnv (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQCtpAEnv.h"

/******************************************************************************
 class PlnrQCtpAEnv
 ******************************************************************************/

PlnrQCtpAEnv::PlnrQCtpAEnv(
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

void PlnrQCtpAEnv::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "PlnrQCtpAEnv";

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
 class ListPlnrQCtpAEnv
 ******************************************************************************/

ListPlnrQCtpAEnv::ListPlnrQCtpAEnv() {
};

ListPlnrQCtpAEnv::ListPlnrQCtpAEnv(
			const ListPlnrQCtpAEnv& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQCtpAEnv(*(src.nodes[i]));
};

ListPlnrQCtpAEnv::~ListPlnrQCtpAEnv() {
	clear();
};

void ListPlnrQCtpAEnv::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrQCtpAEnv::size() const {
	return(nodes.size());
};

void ListPlnrQCtpAEnv::append(
			PlnrQCtpAEnv* rec
		) {
	nodes.push_back(rec);
};

ListPlnrQCtpAEnv& ListPlnrQCtpAEnv::operator=(
			const ListPlnrQCtpAEnv& src
		) {
	PlnrQCtpAEnv* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrQCtpAEnv(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListPlnrQCtpAEnv::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListPlnrQCtpAEnv";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblPlnrQCtpAEnv
 ******************************************************************************/

TblPlnrQCtpAEnv::TblPlnrQCtpAEnv() {
};

TblPlnrQCtpAEnv::~TblPlnrQCtpAEnv() {
};

bool TblPlnrQCtpAEnv::loadRecBySQL(
			const string& sqlstr
			, PlnrQCtpAEnv** rec
		) {
	return false;
};

ubigint TblPlnrQCtpAEnv::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQCtpAEnv& rst
		) {
	return 0;
};

void TblPlnrQCtpAEnv::insertRec(
			PlnrQCtpAEnv* rec
		) {
};

ubigint TblPlnrQCtpAEnv::insertNewRec(
			PlnrQCtpAEnv** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint x1RefPlnrMCalcitem
			, const string x2SrefKKey
			, const string titX2SrefKKey
			, const string Val
		) {
	ubigint retval = 0;
	PlnrQCtpAEnv* _rec = NULL;

	_rec = new PlnrQCtpAEnv(0, jref, jnum, ref, x1RefPlnrMCalcitem, x2SrefKKey, titX2SrefKKey, Val);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrQCtpAEnv::appendNewRecToRst(
			ListPlnrQCtpAEnv& rst
			, PlnrQCtpAEnv** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint x1RefPlnrMCalcitem
			, const string x2SrefKKey
			, const string titX2SrefKKey
			, const string Val
		) {
	ubigint retval = 0;
	PlnrQCtpAEnv* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, x1RefPlnrMCalcitem, x2SrefKKey, titX2SrefKKey, Val);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrQCtpAEnv::insertRst(
			ListPlnrQCtpAEnv& rst
		) {
};

void TblPlnrQCtpAEnv::updateRec(
			PlnrQCtpAEnv* rec
		) {
};

void TblPlnrQCtpAEnv::updateRst(
			ListPlnrQCtpAEnv& rst
		) {
};

void TblPlnrQCtpAEnv::removeRecByQref(
			ubigint qref
		) {
};

void TblPlnrQCtpAEnv::removeRstByJref(
			ubigint jref
		) {
};

bool TblPlnrQCtpAEnv::loadRecByQref(
			ubigint qref
			, PlnrQCtpAEnv** rec
		) {
	return false;
};

ubigint TblPlnrQCtpAEnv::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQCtpAEnv& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrQCtpAEnv
 ******************************************************************************/

MyTblPlnrQCtpAEnv::MyTblPlnrQCtpAEnv() : TblPlnrQCtpAEnv(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblPlnrQCtpAEnv::~MyTblPlnrQCtpAEnv() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblPlnrQCtpAEnv::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrQCtpAEnv (jref, jnum, ref, x1RefPlnrMCalcitem, x2SrefKKey, Val) VALUES (?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrQCtpAEnv SET jref = ?, jnum = ?, ref = ?, x1RefPlnrMCalcitem = ?, x2SrefKKey = ?, Val = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblPlnrQCtpAEnv WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblPlnrQCtpAEnv WHERE jref = ?", false);
};

bool MyTblPlnrQCtpAEnv::loadRecBySQL(
			const string& sqlstr
			, PlnrQCtpAEnv** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrQCtpAEnv* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQCtpAEnv / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrQCtpAEnv();

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

ubigint MyTblPlnrQCtpAEnv::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQCtpAEnv& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrQCtpAEnv* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQCtpAEnv / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrQCtpAEnv();

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

void MyTblPlnrQCtpAEnv::insertRec(
			PlnrQCtpAEnv* rec
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

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQCtpAEnv / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQCtpAEnv / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblPlnrQCtpAEnv::insertRst(
			ListPlnrQCtpAEnv& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblPlnrQCtpAEnv::updateRec(
			PlnrQCtpAEnv* rec
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

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQCtpAEnv / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQCtpAEnv / stmtUpdateRec)\n");
};

void MyTblPlnrQCtpAEnv::updateRst(
			ListPlnrQCtpAEnv& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblPlnrQCtpAEnv::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQCtpAEnv / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQCtpAEnv / stmtRemoveRecByQref)\n");
};

void MyTblPlnrQCtpAEnv::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQCtpAEnv / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQCtpAEnv / stmtRemoveRstByJref)\n");
};

bool MyTblPlnrQCtpAEnv::loadRecByQref(
			ubigint qref
			, PlnrQCtpAEnv** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrQCtpAEnv WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblPlnrQCtpAEnv::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQCtpAEnv& rst
		) {
	return loadRstBySQL("SELECT * FROM TblPlnrQCtpAEnv WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrQCtpAEnv
 ******************************************************************************/

PgTblPlnrQCtpAEnv::PgTblPlnrQCtpAEnv() : TblPlnrQCtpAEnv(), PgTable() {
};

PgTblPlnrQCtpAEnv::~PgTblPlnrQCtpAEnv() {
};

void PgTblPlnrQCtpAEnv::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrQCtpAEnv_insertRec", "INSERT INTO TblPlnrQCtpAEnv (jref, jnum, ref, x1RefPlnrMCalcitem, x2SrefKKey, Val) VALUES ($1,$2,$3,$4,$5,$6) RETURNING qref", 6, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQCtpAEnv_updateRec", "UPDATE TblPlnrQCtpAEnv SET jref = $1, jnum = $2, ref = $3, x1RefPlnrMCalcitem = $4, x2SrefKKey = $5, Val = $6 WHERE qref = $7", 7, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQCtpAEnv_removeRecByQref", "DELETE FROM TblPlnrQCtpAEnv WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQCtpAEnv_removeRstByJref", "DELETE FROM TblPlnrQCtpAEnv WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrQCtpAEnv_loadRecByQref", "SELECT qref, jref, jnum, ref, x1RefPlnrMCalcitem, x2SrefKKey, Val FROM TblPlnrQCtpAEnv WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQCtpAEnv_loadRstByJref", "SELECT qref, jref, jnum, ref, x1RefPlnrMCalcitem, x2SrefKKey, Val FROM TblPlnrQCtpAEnv WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrQCtpAEnv::loadRec(
			PGresult* res
			, PlnrQCtpAEnv** rec
		) {
	char* ptr;

	PlnrQCtpAEnv* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrQCtpAEnv();

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

ubigint PgTblPlnrQCtpAEnv::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrQCtpAEnv& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrQCtpAEnv* rec;

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
			rec = new PlnrQCtpAEnv();

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

bool PgTblPlnrQCtpAEnv::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrQCtpAEnv** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQCtpAEnv / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQCtpAEnv::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrQCtpAEnv& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQCtpAEnv / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblPlnrQCtpAEnv::loadRecBySQL(
			const string& sqlstr
			, PlnrQCtpAEnv** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQCtpAEnv::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQCtpAEnv& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrQCtpAEnv::insertRec(
			PlnrQCtpAEnv* rec
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

	res = PQexecPrepared(dbs, "TblPlnrQCtpAEnv_insertRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQCtpAEnv_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblPlnrQCtpAEnv::insertRst(
			ListPlnrQCtpAEnv& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblPlnrQCtpAEnv::updateRec(
			PlnrQCtpAEnv* rec
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

	res = PQexecPrepared(dbs, "TblPlnrQCtpAEnv_updateRec", 7, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQCtpAEnv_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrQCtpAEnv::updateRst(
			ListPlnrQCtpAEnv& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblPlnrQCtpAEnv::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblPlnrQCtpAEnv_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQCtpAEnv_removeRecByQref)\n");

	PQclear(res);
};

void PgTblPlnrQCtpAEnv::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblPlnrQCtpAEnv_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQCtpAEnv_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblPlnrQCtpAEnv::loadRecByQref(
			ubigint qref
			, PlnrQCtpAEnv** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrQCtpAEnv_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblPlnrQCtpAEnv::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQCtpAEnv& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrQCtpAEnv_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

