/**
  * \file PlnrQDomMNCalc.cpp
  * Dbs and XML wrapper for table TblPlnrQDomMNCalc (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQDomMNCalc.h"

/******************************************************************************
 class PlnrQDomMNCalc
 ******************************************************************************/

PlnrQDomMNCalc::PlnrQDomMNCalc(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const string srefPlnrKCalcdomprp
			, const string titSrefPlnrKCalcdomprp
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->mref = mref;
	this->stubMref = stubMref;
	this->ref = ref;
	this->srefPlnrKCalcdomprp = srefPlnrKCalcdomprp;
	this->titSrefPlnrKCalcdomprp = titSrefPlnrKCalcdomprp;
};

void PlnrQDomMNCalc::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "PlnrQDomMNCalc";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "mref", stubMref);
		writeString(wr, "prp", srefPlnrKCalcdomprp);
		writeString(wr, "prp2", titSrefPlnrKCalcdomprp);
	} else {
		writeString(wr, "stubMref", stubMref);
		writeString(wr, "srefPlnrKCalcdomprp", srefPlnrKCalcdomprp);
		writeString(wr, "titSrefPlnrKCalcdomprp", titSrefPlnrKCalcdomprp);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListPlnrQDomMNCalc
 ******************************************************************************/

ListPlnrQDomMNCalc::ListPlnrQDomMNCalc() {
};

ListPlnrQDomMNCalc::ListPlnrQDomMNCalc(
			const ListPlnrQDomMNCalc& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQDomMNCalc(*(src.nodes[i]));
};

ListPlnrQDomMNCalc::~ListPlnrQDomMNCalc() {
	clear();
};

void ListPlnrQDomMNCalc::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrQDomMNCalc::size() const {
	return(nodes.size());
};

void ListPlnrQDomMNCalc::append(
			PlnrQDomMNCalc* rec
		) {
	nodes.push_back(rec);
};

ListPlnrQDomMNCalc& ListPlnrQDomMNCalc::operator=(
			const ListPlnrQDomMNCalc& src
		) {
	PlnrQDomMNCalc* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrQDomMNCalc(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListPlnrQDomMNCalc::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListPlnrQDomMNCalc";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblPlnrQDomMNCalc
 ******************************************************************************/

TblPlnrQDomMNCalc::TblPlnrQDomMNCalc() {
};

TblPlnrQDomMNCalc::~TblPlnrQDomMNCalc() {
};

bool TblPlnrQDomMNCalc::loadRecBySQL(
			const string& sqlstr
			, PlnrQDomMNCalc** rec
		) {
	return false;
};

ubigint TblPlnrQDomMNCalc::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQDomMNCalc& rst
		) {
	return 0;
};

void TblPlnrQDomMNCalc::insertRec(
			PlnrQDomMNCalc* rec
		) {
};

ubigint TblPlnrQDomMNCalc::insertNewRec(
			PlnrQDomMNCalc** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const string srefPlnrKCalcdomprp
			, const string titSrefPlnrKCalcdomprp
		) {
	ubigint retval = 0;
	PlnrQDomMNCalc* _rec = NULL;

	_rec = new PlnrQDomMNCalc(0, jref, jnum, mref, stubMref, ref, srefPlnrKCalcdomprp, titSrefPlnrKCalcdomprp);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrQDomMNCalc::appendNewRecToRst(
			ListPlnrQDomMNCalc& rst
			, PlnrQDomMNCalc** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const string srefPlnrKCalcdomprp
			, const string titSrefPlnrKCalcdomprp
		) {
	ubigint retval = 0;
	PlnrQDomMNCalc* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, mref, stubMref, ref, srefPlnrKCalcdomprp, titSrefPlnrKCalcdomprp);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrQDomMNCalc::insertRst(
			ListPlnrQDomMNCalc& rst
		) {
};

void TblPlnrQDomMNCalc::updateRec(
			PlnrQDomMNCalc* rec
		) {
};

void TblPlnrQDomMNCalc::updateRst(
			ListPlnrQDomMNCalc& rst
		) {
};

void TblPlnrQDomMNCalc::removeRecByQref(
			ubigint qref
		) {
};

void TblPlnrQDomMNCalc::removeRstByJref(
			ubigint jref
		) {
};

bool TblPlnrQDomMNCalc::loadRecByQref(
			ubigint qref
			, PlnrQDomMNCalc** rec
		) {
	return false;
};

ubigint TblPlnrQDomMNCalc::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQDomMNCalc& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrQDomMNCalc
 ******************************************************************************/

MyTblPlnrQDomMNCalc::MyTblPlnrQDomMNCalc() : TblPlnrQDomMNCalc(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblPlnrQDomMNCalc::~MyTblPlnrQDomMNCalc() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblPlnrQDomMNCalc::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrQDomMNCalc (jref, jnum, mref, ref, srefPlnrKCalcdomprp) VALUES (?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrQDomMNCalc SET jref = ?, jnum = ?, mref = ?, ref = ?, srefPlnrKCalcdomprp = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblPlnrQDomMNCalc WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblPlnrQDomMNCalc WHERE jref = ?", false);
};

bool MyTblPlnrQDomMNCalc::loadRecBySQL(
			const string& sqlstr
			, PlnrQDomMNCalc** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrQDomMNCalc* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQDomMNCalc / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrQDomMNCalc();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->mref = atoll((char*) dbrow[3]); else _rec->mref = 0;
		if (dbrow[4]) _rec->ref = atoll((char*) dbrow[4]); else _rec->ref = 0;
		if (dbrow[5]) _rec->srefPlnrKCalcdomprp.assign(dbrow[5], dblengths[5]); else _rec->srefPlnrKCalcdomprp = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrQDomMNCalc::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQDomMNCalc& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrQDomMNCalc* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQDomMNCalc / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrQDomMNCalc();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->mref = atoll((char*) dbrow[3]); else rec->mref = 0;
			if (dbrow[4]) rec->ref = atoll((char*) dbrow[4]); else rec->ref = 0;
			if (dbrow[5]) rec->srefPlnrKCalcdomprp.assign(dbrow[5], dblengths[5]); else rec->srefPlnrKCalcdomprp = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrQDomMNCalc::insertRec(
			PlnrQDomMNCalc* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[4] = rec->srefPlnrKCalcdomprp.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->mref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->srefPlnrKCalcdomprp.c_str()),&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQDomMNCalc / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQDomMNCalc / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblPlnrQDomMNCalc::insertRst(
			ListPlnrQDomMNCalc& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblPlnrQDomMNCalc::updateRec(
			PlnrQDomMNCalc* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	l[4] = rec->srefPlnrKCalcdomprp.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->mref,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3])), 
		bindCstring((char*) (rec->srefPlnrKCalcdomprp.c_str()),&(l[4]),&(n[4]),&(e[4])), 
		bindUbigint(&rec->qref,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQDomMNCalc / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQDomMNCalc / stmtUpdateRec)\n");
};

void MyTblPlnrQDomMNCalc::updateRst(
			ListPlnrQDomMNCalc& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblPlnrQDomMNCalc::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQDomMNCalc / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQDomMNCalc / stmtRemoveRecByQref)\n");
};

void MyTblPlnrQDomMNCalc::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQDomMNCalc / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQDomMNCalc / stmtRemoveRstByJref)\n");
};

bool MyTblPlnrQDomMNCalc::loadRecByQref(
			ubigint qref
			, PlnrQDomMNCalc** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrQDomMNCalc WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblPlnrQDomMNCalc::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQDomMNCalc& rst
		) {
	return loadRstBySQL("SELECT * FROM TblPlnrQDomMNCalc WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrQDomMNCalc
 ******************************************************************************/

PgTblPlnrQDomMNCalc::PgTblPlnrQDomMNCalc() : TblPlnrQDomMNCalc(), PgTable() {
};

PgTblPlnrQDomMNCalc::~PgTblPlnrQDomMNCalc() {
};

void PgTblPlnrQDomMNCalc::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrQDomMNCalc_insertRec", "INSERT INTO TblPlnrQDomMNCalc (jref, jnum, mref, ref, srefPlnrKCalcdomprp) VALUES ($1,$2,$3,$4,$5) RETURNING qref", 5, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQDomMNCalc_updateRec", "UPDATE TblPlnrQDomMNCalc SET jref = $1, jnum = $2, mref = $3, ref = $4, srefPlnrKCalcdomprp = $5 WHERE qref = $6", 6, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQDomMNCalc_removeRecByQref", "DELETE FROM TblPlnrQDomMNCalc WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQDomMNCalc_removeRstByJref", "DELETE FROM TblPlnrQDomMNCalc WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrQDomMNCalc_loadRecByQref", "SELECT qref, jref, jnum, mref, ref, srefPlnrKCalcdomprp FROM TblPlnrQDomMNCalc WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQDomMNCalc_loadRstByJref", "SELECT qref, jref, jnum, mref, ref, srefPlnrKCalcdomprp FROM TblPlnrQDomMNCalc WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrQDomMNCalc::loadRec(
			PGresult* res
			, PlnrQDomMNCalc** rec
		) {
	char* ptr;

	PlnrQDomMNCalc* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrQDomMNCalc();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "mref"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "srefplnrkcalcdomprp")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->mref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->srefPlnrKCalcdomprp.assign(ptr, PQgetlength(res, 0, fnum[5]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrQDomMNCalc::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrQDomMNCalc& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrQDomMNCalc* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "mref"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "srefplnrkcalcdomprp")
		};

		while (numread < numrow) {
			rec = new PlnrQDomMNCalc();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->mref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->srefPlnrKCalcdomprp.assign(ptr, PQgetlength(res, numread, fnum[5]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrQDomMNCalc::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrQDomMNCalc** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDomMNCalc / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQDomMNCalc::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrQDomMNCalc& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDomMNCalc / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblPlnrQDomMNCalc::loadRecBySQL(
			const string& sqlstr
			, PlnrQDomMNCalc** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQDomMNCalc::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQDomMNCalc& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrQDomMNCalc::insertRec(
			PlnrQDomMNCalc* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _mref = htonl64(rec->mref);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_mref,
		(char*) &_ref,
		rec->srefPlnrKCalcdomprp.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		0
	};
	const int f[] = {1, 1, 1, 1, 0};

	res = PQexecPrepared(dbs, "TblPlnrQDomMNCalc_insertRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDomMNCalc_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblPlnrQDomMNCalc::insertRst(
			ListPlnrQDomMNCalc& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblPlnrQDomMNCalc::updateRec(
			PlnrQDomMNCalc* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _mref = htonl64(rec->mref);
	ubigint _ref = htonl64(rec->ref);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_mref,
		(char*) &_ref,
		rec->srefPlnrKCalcdomprp.c_str(),
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblPlnrQDomMNCalc_updateRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDomMNCalc_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrQDomMNCalc::updateRst(
			ListPlnrQDomMNCalc& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblPlnrQDomMNCalc::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblPlnrQDomMNCalc_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDomMNCalc_removeRecByQref)\n");

	PQclear(res);
};

void PgTblPlnrQDomMNCalc::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblPlnrQDomMNCalc_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDomMNCalc_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblPlnrQDomMNCalc::loadRecByQref(
			ubigint qref
			, PlnrQDomMNCalc** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrQDomMNCalc_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblPlnrQDomMNCalc::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQDomMNCalc& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrQDomMNCalc_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

