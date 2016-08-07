/**
  * \file PlnrQUsgAAccess.cpp
  * Dbs and XML wrapper for table TblPlnrQUsgAAccess (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQUsgAAccess.h"

/******************************************************************************
 class PlnrQUsgAAccess
 ******************************************************************************/

PlnrQUsgAAccess::PlnrQUsgAAccess(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint x1IxPlnrVCard
			, const string srefX1IxPlnrVCard
			, const string titX1IxPlnrVCard
			, const uint ixPlnrWUiaccess
			, const string srefsIxPlnrWUiaccess
			, const string titsIxPlnrWUiaccess
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->x1IxPlnrVCard = x1IxPlnrVCard;
	this->srefX1IxPlnrVCard = srefX1IxPlnrVCard;
	this->titX1IxPlnrVCard = titX1IxPlnrVCard;
	this->ixPlnrWUiaccess = ixPlnrWUiaccess;
	this->srefsIxPlnrWUiaccess = srefsIxPlnrWUiaccess;
	this->titsIxPlnrWUiaccess = titsIxPlnrWUiaccess;
};

void PlnrQUsgAAccess::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "PlnrQUsgAAccess";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "crd", srefX1IxPlnrVCard);
		writeString(wr, "crd2", titX1IxPlnrVCard);
		writeString(wr, "uac", srefsIxPlnrWUiaccess);
		writeString(wr, "uac2", titsIxPlnrWUiaccess);
	} else {
		writeString(wr, "srefX1IxPlnrVCard", srefX1IxPlnrVCard);
		writeString(wr, "titX1IxPlnrVCard", titX1IxPlnrVCard);
		writeString(wr, "srefsIxPlnrWUiaccess", srefsIxPlnrWUiaccess);
		writeString(wr, "titsIxPlnrWUiaccess", titsIxPlnrWUiaccess);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListPlnrQUsgAAccess
 ******************************************************************************/

ListPlnrQUsgAAccess::ListPlnrQUsgAAccess() {
};

ListPlnrQUsgAAccess::ListPlnrQUsgAAccess(
			const ListPlnrQUsgAAccess& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQUsgAAccess(*(src.nodes[i]));
};

ListPlnrQUsgAAccess::~ListPlnrQUsgAAccess() {
	clear();
};

void ListPlnrQUsgAAccess::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrQUsgAAccess::size() const {
	return(nodes.size());
};

void ListPlnrQUsgAAccess::append(
			PlnrQUsgAAccess* rec
		) {
	nodes.push_back(rec);
};

ListPlnrQUsgAAccess& ListPlnrQUsgAAccess::operator=(
			const ListPlnrQUsgAAccess& src
		) {
	PlnrQUsgAAccess* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrQUsgAAccess(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListPlnrQUsgAAccess::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListPlnrQUsgAAccess";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblPlnrQUsgAAccess
 ******************************************************************************/

TblPlnrQUsgAAccess::TblPlnrQUsgAAccess() {
};

TblPlnrQUsgAAccess::~TblPlnrQUsgAAccess() {
};

bool TblPlnrQUsgAAccess::loadRecBySQL(
			const string& sqlstr
			, PlnrQUsgAAccess** rec
		) {
	return false;
};

ubigint TblPlnrQUsgAAccess::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQUsgAAccess& rst
		) {
	return 0;
};

void TblPlnrQUsgAAccess::insertRec(
			PlnrQUsgAAccess* rec
		) {
};

ubigint TblPlnrQUsgAAccess::insertNewRec(
			PlnrQUsgAAccess** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint x1IxPlnrVCard
			, const string srefX1IxPlnrVCard
			, const string titX1IxPlnrVCard
			, const uint ixPlnrWUiaccess
			, const string srefsIxPlnrWUiaccess
			, const string titsIxPlnrWUiaccess
		) {
	ubigint retval = 0;
	PlnrQUsgAAccess* _rec = NULL;

	_rec = new PlnrQUsgAAccess(0, jref, jnum, ref, x1IxPlnrVCard, srefX1IxPlnrVCard, titX1IxPlnrVCard, ixPlnrWUiaccess, srefsIxPlnrWUiaccess, titsIxPlnrWUiaccess);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrQUsgAAccess::appendNewRecToRst(
			ListPlnrQUsgAAccess& rst
			, PlnrQUsgAAccess** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint x1IxPlnrVCard
			, const string srefX1IxPlnrVCard
			, const string titX1IxPlnrVCard
			, const uint ixPlnrWUiaccess
			, const string srefsIxPlnrWUiaccess
			, const string titsIxPlnrWUiaccess
		) {
	ubigint retval = 0;
	PlnrQUsgAAccess* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, x1IxPlnrVCard, srefX1IxPlnrVCard, titX1IxPlnrVCard, ixPlnrWUiaccess, srefsIxPlnrWUiaccess, titsIxPlnrWUiaccess);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrQUsgAAccess::insertRst(
			ListPlnrQUsgAAccess& rst
		) {
};

void TblPlnrQUsgAAccess::updateRec(
			PlnrQUsgAAccess* rec
		) {
};

void TblPlnrQUsgAAccess::updateRst(
			ListPlnrQUsgAAccess& rst
		) {
};

void TblPlnrQUsgAAccess::removeRecByQref(
			ubigint qref
		) {
};

void TblPlnrQUsgAAccess::removeRstByJref(
			ubigint jref
		) {
};

bool TblPlnrQUsgAAccess::loadRecByQref(
			ubigint qref
			, PlnrQUsgAAccess** rec
		) {
	return false;
};

ubigint TblPlnrQUsgAAccess::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQUsgAAccess& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrQUsgAAccess
 ******************************************************************************/

MyTblPlnrQUsgAAccess::MyTblPlnrQUsgAAccess() : TblPlnrQUsgAAccess(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblPlnrQUsgAAccess::~MyTblPlnrQUsgAAccess() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblPlnrQUsgAAccess::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrQUsgAAccess (jref, jnum, ref, x1IxPlnrVCard, ixPlnrWUiaccess) VALUES (?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrQUsgAAccess SET jref = ?, jnum = ?, ref = ?, x1IxPlnrVCard = ?, ixPlnrWUiaccess = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblPlnrQUsgAAccess WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblPlnrQUsgAAccess WHERE jref = ?", false);
};

bool MyTblPlnrQUsgAAccess::loadRecBySQL(
			const string& sqlstr
			, PlnrQUsgAAccess** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrQUsgAAccess* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQUsgAAccess / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrQUsgAAccess();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->x1IxPlnrVCard = atol((char*) dbrow[4]); else _rec->x1IxPlnrVCard = 0;
		if (dbrow[5]) _rec->ixPlnrWUiaccess = atol((char*) dbrow[5]); else _rec->ixPlnrWUiaccess = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrQUsgAAccess::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQUsgAAccess& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrQUsgAAccess* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQUsgAAccess / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrQUsgAAccess();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->x1IxPlnrVCard = atol((char*) dbrow[4]); else rec->x1IxPlnrVCard = 0;
			if (dbrow[5]) rec->ixPlnrWUiaccess = atol((char*) dbrow[5]); else rec->ixPlnrWUiaccess = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrQUsgAAccess::insertRec(
			PlnrQUsgAAccess* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->x1IxPlnrVCard,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->ixPlnrWUiaccess,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQUsgAAccess / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQUsgAAccess / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblPlnrQUsgAAccess::insertRst(
			ListPlnrQUsgAAccess& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblPlnrQUsgAAccess::updateRec(
			PlnrQUsgAAccess* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])), 
		bindUint(&rec->x1IxPlnrVCard,&(l[3]),&(n[3]),&(e[3])), 
		bindUint(&rec->ixPlnrWUiaccess,&(l[4]),&(n[4]),&(e[4])), 
		bindUbigint(&rec->qref,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQUsgAAccess / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQUsgAAccess / stmtUpdateRec)\n");
};

void MyTblPlnrQUsgAAccess::updateRst(
			ListPlnrQUsgAAccess& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblPlnrQUsgAAccess::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQUsgAAccess / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQUsgAAccess / stmtRemoveRecByQref)\n");
};

void MyTblPlnrQUsgAAccess::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQUsgAAccess / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQUsgAAccess / stmtRemoveRstByJref)\n");
};

bool MyTblPlnrQUsgAAccess::loadRecByQref(
			ubigint qref
			, PlnrQUsgAAccess** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrQUsgAAccess WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblPlnrQUsgAAccess::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQUsgAAccess& rst
		) {
	return loadRstBySQL("SELECT * FROM TblPlnrQUsgAAccess WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrQUsgAAccess
 ******************************************************************************/

PgTblPlnrQUsgAAccess::PgTblPlnrQUsgAAccess() : TblPlnrQUsgAAccess(), PgTable() {
};

PgTblPlnrQUsgAAccess::~PgTblPlnrQUsgAAccess() {
};

void PgTblPlnrQUsgAAccess::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrQUsgAAccess_insertRec", "INSERT INTO TblPlnrQUsgAAccess (jref, jnum, ref, x1IxPlnrVCard, ixPlnrWUiaccess) VALUES ($1,$2,$3,$4,$5) RETURNING qref", 5, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQUsgAAccess_updateRec", "UPDATE TblPlnrQUsgAAccess SET jref = $1, jnum = $2, ref = $3, x1IxPlnrVCard = $4, ixPlnrWUiaccess = $5 WHERE qref = $6", 6, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQUsgAAccess_removeRecByQref", "DELETE FROM TblPlnrQUsgAAccess WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQUsgAAccess_removeRstByJref", "DELETE FROM TblPlnrQUsgAAccess WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrQUsgAAccess_loadRecByQref", "SELECT qref, jref, jnum, ref, x1IxPlnrVCard, ixPlnrWUiaccess FROM TblPlnrQUsgAAccess WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQUsgAAccess_loadRstByJref", "SELECT qref, jref, jnum, ref, x1IxPlnrVCard, ixPlnrWUiaccess FROM TblPlnrQUsgAAccess WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrQUsgAAccess::loadRec(
			PGresult* res
			, PlnrQUsgAAccess** rec
		) {
	char* ptr;

	PlnrQUsgAAccess* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrQUsgAAccess();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1ixplnrvcard"),
			PQfnumber(res, "ixplnrwuiaccess")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->x1IxPlnrVCard = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->ixPlnrWUiaccess = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrQUsgAAccess::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrQUsgAAccess& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrQUsgAAccess* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1ixplnrvcard"),
			PQfnumber(res, "ixplnrwuiaccess")
		};

		while (numread < numrow) {
			rec = new PlnrQUsgAAccess();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->x1IxPlnrVCard = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->ixPlnrWUiaccess = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrQUsgAAccess::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrQUsgAAccess** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQUsgAAccess / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQUsgAAccess::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrQUsgAAccess& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQUsgAAccess / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblPlnrQUsgAAccess::loadRecBySQL(
			const string& sqlstr
			, PlnrQUsgAAccess** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQUsgAAccess::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQUsgAAccess& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrQUsgAAccess::insertRec(
			PlnrQUsgAAccess* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _x1IxPlnrVCard = htonl(rec->x1IxPlnrVCard);
	uint _ixPlnrWUiaccess = htonl(rec->ixPlnrWUiaccess);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_x1IxPlnrVCard,
		(char*) &_ixPlnrWUiaccess
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblPlnrQUsgAAccess_insertRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQUsgAAccess_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblPlnrQUsgAAccess::insertRst(
			ListPlnrQUsgAAccess& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblPlnrQUsgAAccess::updateRec(
			PlnrQUsgAAccess* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _x1IxPlnrVCard = htonl(rec->x1IxPlnrVCard);
	uint _ixPlnrWUiaccess = htonl(rec->ixPlnrWUiaccess);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_x1IxPlnrVCard,
		(char*) &_ixPlnrWUiaccess,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblPlnrQUsgAAccess_updateRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQUsgAAccess_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrQUsgAAccess::updateRst(
			ListPlnrQUsgAAccess& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblPlnrQUsgAAccess::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblPlnrQUsgAAccess_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQUsgAAccess_removeRecByQref)\n");

	PQclear(res);
};

void PgTblPlnrQUsgAAccess::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblPlnrQUsgAAccess_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQUsgAAccess_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblPlnrQUsgAAccess::loadRecByQref(
			ubigint qref
			, PlnrQUsgAAccess** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrQUsgAAccess_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblPlnrQUsgAAccess::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQUsgAAccess& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrQUsgAAccess_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

