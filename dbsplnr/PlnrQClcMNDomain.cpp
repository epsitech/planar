/**
  * \file PlnrQClcMNDomain.cpp
  * Dbs and XML wrapper for table TblPlnrQClcMNDomain (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQClcMNDomain.h"

/******************************************************************************
 class PlnrQClcMNDomain
 ******************************************************************************/

PlnrQClcMNDomain::PlnrQClcMNDomain(
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

void PlnrQClcMNDomain::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "PlnrQClcMNDomain";

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
 class ListPlnrQClcMNDomain
 ******************************************************************************/

ListPlnrQClcMNDomain::ListPlnrQClcMNDomain() {
};

ListPlnrQClcMNDomain::ListPlnrQClcMNDomain(
			const ListPlnrQClcMNDomain& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQClcMNDomain(*(src.nodes[i]));
};

ListPlnrQClcMNDomain::~ListPlnrQClcMNDomain() {
	clear();
};

void ListPlnrQClcMNDomain::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrQClcMNDomain::size() const {
	return(nodes.size());
};

void ListPlnrQClcMNDomain::append(
			PlnrQClcMNDomain* rec
		) {
	nodes.push_back(rec);
};

ListPlnrQClcMNDomain& ListPlnrQClcMNDomain::operator=(
			const ListPlnrQClcMNDomain& src
		) {
	PlnrQClcMNDomain* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrQClcMNDomain(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListPlnrQClcMNDomain::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListPlnrQClcMNDomain";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblPlnrQClcMNDomain
 ******************************************************************************/

TblPlnrQClcMNDomain::TblPlnrQClcMNDomain() {
};

TblPlnrQClcMNDomain::~TblPlnrQClcMNDomain() {
};

bool TblPlnrQClcMNDomain::loadRecBySQL(
			const string& sqlstr
			, PlnrQClcMNDomain** rec
		) {
	return false;
};

ubigint TblPlnrQClcMNDomain::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQClcMNDomain& rst
		) {
	return 0;
};

void TblPlnrQClcMNDomain::insertRec(
			PlnrQClcMNDomain* rec
		) {
};

ubigint TblPlnrQClcMNDomain::insertNewRec(
			PlnrQClcMNDomain** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const string srefPlnrKCalcdomprp
			, const string titSrefPlnrKCalcdomprp
		) {
	ubigint retval = 0;
	PlnrQClcMNDomain* _rec = NULL;

	_rec = new PlnrQClcMNDomain(0, jref, jnum, mref, stubMref, ref, srefPlnrKCalcdomprp, titSrefPlnrKCalcdomprp);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrQClcMNDomain::appendNewRecToRst(
			ListPlnrQClcMNDomain& rst
			, PlnrQClcMNDomain** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const string srefPlnrKCalcdomprp
			, const string titSrefPlnrKCalcdomprp
		) {
	ubigint retval = 0;
	PlnrQClcMNDomain* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, mref, stubMref, ref, srefPlnrKCalcdomprp, titSrefPlnrKCalcdomprp);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrQClcMNDomain::insertRst(
			ListPlnrQClcMNDomain& rst
		) {
};

void TblPlnrQClcMNDomain::updateRec(
			PlnrQClcMNDomain* rec
		) {
};

void TblPlnrQClcMNDomain::updateRst(
			ListPlnrQClcMNDomain& rst
		) {
};

void TblPlnrQClcMNDomain::removeRecByQref(
			ubigint qref
		) {
};

void TblPlnrQClcMNDomain::removeRstByJref(
			ubigint jref
		) {
};

bool TblPlnrQClcMNDomain::loadRecByQref(
			ubigint qref
			, PlnrQClcMNDomain** rec
		) {
	return false;
};

ubigint TblPlnrQClcMNDomain::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQClcMNDomain& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrQClcMNDomain
 ******************************************************************************/

MyTblPlnrQClcMNDomain::MyTblPlnrQClcMNDomain() : TblPlnrQClcMNDomain(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblPlnrQClcMNDomain::~MyTblPlnrQClcMNDomain() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblPlnrQClcMNDomain::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrQClcMNDomain (jref, jnum, mref, ref, srefPlnrKCalcdomprp) VALUES (?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrQClcMNDomain SET jref = ?, jnum = ?, mref = ?, ref = ?, srefPlnrKCalcdomprp = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblPlnrQClcMNDomain WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblPlnrQClcMNDomain WHERE jref = ?", false);
};

bool MyTblPlnrQClcMNDomain::loadRecBySQL(
			const string& sqlstr
			, PlnrQClcMNDomain** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrQClcMNDomain* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQClcMNDomain / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrQClcMNDomain();

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

ubigint MyTblPlnrQClcMNDomain::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQClcMNDomain& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrQClcMNDomain* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQClcMNDomain / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrQClcMNDomain();

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

void MyTblPlnrQClcMNDomain::insertRec(
			PlnrQClcMNDomain* rec
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

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQClcMNDomain / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQClcMNDomain / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblPlnrQClcMNDomain::insertRst(
			ListPlnrQClcMNDomain& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblPlnrQClcMNDomain::updateRec(
			PlnrQClcMNDomain* rec
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

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQClcMNDomain / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQClcMNDomain / stmtUpdateRec)\n");
};

void MyTblPlnrQClcMNDomain::updateRst(
			ListPlnrQClcMNDomain& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblPlnrQClcMNDomain::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQClcMNDomain / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQClcMNDomain / stmtRemoveRecByQref)\n");
};

void MyTblPlnrQClcMNDomain::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQClcMNDomain / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQClcMNDomain / stmtRemoveRstByJref)\n");
};

bool MyTblPlnrQClcMNDomain::loadRecByQref(
			ubigint qref
			, PlnrQClcMNDomain** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrQClcMNDomain WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblPlnrQClcMNDomain::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQClcMNDomain& rst
		) {
	return loadRstBySQL("SELECT * FROM TblPlnrQClcMNDomain WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrQClcMNDomain
 ******************************************************************************/

PgTblPlnrQClcMNDomain::PgTblPlnrQClcMNDomain() : TblPlnrQClcMNDomain(), PgTable() {
};

PgTblPlnrQClcMNDomain::~PgTblPlnrQClcMNDomain() {
};

void PgTblPlnrQClcMNDomain::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrQClcMNDomain_insertRec", "INSERT INTO TblPlnrQClcMNDomain (jref, jnum, mref, ref, srefPlnrKCalcdomprp) VALUES ($1,$2,$3,$4,$5) RETURNING qref", 5, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQClcMNDomain_updateRec", "UPDATE TblPlnrQClcMNDomain SET jref = $1, jnum = $2, mref = $3, ref = $4, srefPlnrKCalcdomprp = $5 WHERE qref = $6", 6, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQClcMNDomain_removeRecByQref", "DELETE FROM TblPlnrQClcMNDomain WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQClcMNDomain_removeRstByJref", "DELETE FROM TblPlnrQClcMNDomain WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrQClcMNDomain_loadRecByQref", "SELECT qref, jref, jnum, mref, ref, srefPlnrKCalcdomprp FROM TblPlnrQClcMNDomain WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQClcMNDomain_loadRstByJref", "SELECT qref, jref, jnum, mref, ref, srefPlnrKCalcdomprp FROM TblPlnrQClcMNDomain WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrQClcMNDomain::loadRec(
			PGresult* res
			, PlnrQClcMNDomain** rec
		) {
	char* ptr;

	PlnrQClcMNDomain* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrQClcMNDomain();

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

ubigint PgTblPlnrQClcMNDomain::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrQClcMNDomain& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrQClcMNDomain* rec;

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
			rec = new PlnrQClcMNDomain();

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

bool PgTblPlnrQClcMNDomain::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrQClcMNDomain** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQClcMNDomain / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQClcMNDomain::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrQClcMNDomain& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQClcMNDomain / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblPlnrQClcMNDomain::loadRecBySQL(
			const string& sqlstr
			, PlnrQClcMNDomain** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQClcMNDomain::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQClcMNDomain& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrQClcMNDomain::insertRec(
			PlnrQClcMNDomain* rec
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

	res = PQexecPrepared(dbs, "TblPlnrQClcMNDomain_insertRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQClcMNDomain_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblPlnrQClcMNDomain::insertRst(
			ListPlnrQClcMNDomain& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblPlnrQClcMNDomain::updateRec(
			PlnrQClcMNDomain* rec
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

	res = PQexecPrepared(dbs, "TblPlnrQClcMNDomain_updateRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQClcMNDomain_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrQClcMNDomain::updateRst(
			ListPlnrQClcMNDomain& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblPlnrQClcMNDomain::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblPlnrQClcMNDomain_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQClcMNDomain_removeRecByQref)\n");

	PQclear(res);
};

void PgTblPlnrQClcMNDomain::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblPlnrQClcMNDomain_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQClcMNDomain_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblPlnrQClcMNDomain::loadRecByQref(
			ubigint qref
			, PlnrQClcMNDomain** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrQClcMNDomain_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblPlnrQClcMNDomain::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQClcMNDomain& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrQClcMNDomain_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

