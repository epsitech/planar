/**
  * \file PlnrQUsrAAccess.cpp
  * Dbs and XML wrapper for table TblPlnrQUsrAAccess (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQUsrAAccess.h"

/******************************************************************************
 class PlnrQUsrAAccess
 ******************************************************************************/

PlnrQUsrAAccess::PlnrQUsrAAccess(
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

void PlnrQUsrAAccess::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "PlnrQUsrAAccess";

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
 class ListPlnrQUsrAAccess
 ******************************************************************************/

ListPlnrQUsrAAccess::ListPlnrQUsrAAccess() {
};

ListPlnrQUsrAAccess::ListPlnrQUsrAAccess(
			const ListPlnrQUsrAAccess& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQUsrAAccess(*(src.nodes[i]));
};

ListPlnrQUsrAAccess::~ListPlnrQUsrAAccess() {
	clear();
};

void ListPlnrQUsrAAccess::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrQUsrAAccess::size() const {
	return(nodes.size());
};

void ListPlnrQUsrAAccess::append(
			PlnrQUsrAAccess* rec
		) {
	nodes.push_back(rec);
};

ListPlnrQUsrAAccess& ListPlnrQUsrAAccess::operator=(
			const ListPlnrQUsrAAccess& src
		) {
	PlnrQUsrAAccess* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrQUsrAAccess(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListPlnrQUsrAAccess::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListPlnrQUsrAAccess";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblPlnrQUsrAAccess
 ******************************************************************************/

TblPlnrQUsrAAccess::TblPlnrQUsrAAccess() {
};

TblPlnrQUsrAAccess::~TblPlnrQUsrAAccess() {
};

bool TblPlnrQUsrAAccess::loadRecBySQL(
			const string& sqlstr
			, PlnrQUsrAAccess** rec
		) {
	return false;
};

ubigint TblPlnrQUsrAAccess::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQUsrAAccess& rst
		) {
	return 0;
};

void TblPlnrQUsrAAccess::insertRec(
			PlnrQUsrAAccess* rec
		) {
};

ubigint TblPlnrQUsrAAccess::insertNewRec(
			PlnrQUsrAAccess** rec
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
	PlnrQUsrAAccess* _rec = NULL;

	_rec = new PlnrQUsrAAccess(0, jref, jnum, ref, x1IxPlnrVCard, srefX1IxPlnrVCard, titX1IxPlnrVCard, ixPlnrWUiaccess, srefsIxPlnrWUiaccess, titsIxPlnrWUiaccess);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrQUsrAAccess::appendNewRecToRst(
			ListPlnrQUsrAAccess& rst
			, PlnrQUsrAAccess** rec
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
	PlnrQUsrAAccess* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, x1IxPlnrVCard, srefX1IxPlnrVCard, titX1IxPlnrVCard, ixPlnrWUiaccess, srefsIxPlnrWUiaccess, titsIxPlnrWUiaccess);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrQUsrAAccess::insertRst(
			ListPlnrQUsrAAccess& rst
		) {
};

void TblPlnrQUsrAAccess::updateRec(
			PlnrQUsrAAccess* rec
		) {
};

void TblPlnrQUsrAAccess::updateRst(
			ListPlnrQUsrAAccess& rst
		) {
};

void TblPlnrQUsrAAccess::removeRecByQref(
			ubigint qref
		) {
};

void TblPlnrQUsrAAccess::removeRstByJref(
			ubigint jref
		) {
};

bool TblPlnrQUsrAAccess::loadRecByQref(
			ubigint qref
			, PlnrQUsrAAccess** rec
		) {
	return false;
};

ubigint TblPlnrQUsrAAccess::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQUsrAAccess& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrQUsrAAccess
 ******************************************************************************/

MyTblPlnrQUsrAAccess::MyTblPlnrQUsrAAccess() : TblPlnrQUsrAAccess(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblPlnrQUsrAAccess::~MyTblPlnrQUsrAAccess() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblPlnrQUsrAAccess::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrQUsrAAccess (jref, jnum, ref, x1IxPlnrVCard, ixPlnrWUiaccess) VALUES (?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrQUsrAAccess SET jref = ?, jnum = ?, ref = ?, x1IxPlnrVCard = ?, ixPlnrWUiaccess = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblPlnrQUsrAAccess WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblPlnrQUsrAAccess WHERE jref = ?", false);
};

bool MyTblPlnrQUsrAAccess::loadRecBySQL(
			const string& sqlstr
			, PlnrQUsrAAccess** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrQUsrAAccess* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQUsrAAccess / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrQUsrAAccess();

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

ubigint MyTblPlnrQUsrAAccess::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQUsrAAccess& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrQUsrAAccess* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQUsrAAccess / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrQUsrAAccess();

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

void MyTblPlnrQUsrAAccess::insertRec(
			PlnrQUsrAAccess* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->x1IxPlnrVCard,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->ixPlnrWUiaccess,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQUsrAAccess / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQUsrAAccess / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblPlnrQUsrAAccess::insertRst(
			ListPlnrQUsrAAccess& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblPlnrQUsrAAccess::updateRec(
			PlnrQUsrAAccess* rec
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

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQUsrAAccess / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQUsrAAccess / stmtUpdateRec)\n");
};

void MyTblPlnrQUsrAAccess::updateRst(
			ListPlnrQUsrAAccess& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblPlnrQUsrAAccess::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQUsrAAccess / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQUsrAAccess / stmtRemoveRecByQref)\n");
};

void MyTblPlnrQUsrAAccess::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQUsrAAccess / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQUsrAAccess / stmtRemoveRstByJref)\n");
};

bool MyTblPlnrQUsrAAccess::loadRecByQref(
			ubigint qref
			, PlnrQUsrAAccess** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrQUsrAAccess WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblPlnrQUsrAAccess::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQUsrAAccess& rst
		) {
	return loadRstBySQL("SELECT * FROM TblPlnrQUsrAAccess WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrQUsrAAccess
 ******************************************************************************/

PgTblPlnrQUsrAAccess::PgTblPlnrQUsrAAccess() : TblPlnrQUsrAAccess(), PgTable() {
};

PgTblPlnrQUsrAAccess::~PgTblPlnrQUsrAAccess() {
};

void PgTblPlnrQUsrAAccess::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrQUsrAAccess_insertRec", "INSERT INTO TblPlnrQUsrAAccess (jref, jnum, ref, x1IxPlnrVCard, ixPlnrWUiaccess) VALUES ($1,$2,$3,$4,$5) RETURNING qref", 5, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQUsrAAccess_updateRec", "UPDATE TblPlnrQUsrAAccess SET jref = $1, jnum = $2, ref = $3, x1IxPlnrVCard = $4, ixPlnrWUiaccess = $5 WHERE qref = $6", 6, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQUsrAAccess_removeRecByQref", "DELETE FROM TblPlnrQUsrAAccess WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQUsrAAccess_removeRstByJref", "DELETE FROM TblPlnrQUsrAAccess WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrQUsrAAccess_loadRecByQref", "SELECT qref, jref, jnum, ref, x1IxPlnrVCard, ixPlnrWUiaccess FROM TblPlnrQUsrAAccess WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQUsrAAccess_loadRstByJref", "SELECT qref, jref, jnum, ref, x1IxPlnrVCard, ixPlnrWUiaccess FROM TblPlnrQUsrAAccess WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrQUsrAAccess::loadRec(
			PGresult* res
			, PlnrQUsrAAccess** rec
		) {
	char* ptr;

	PlnrQUsrAAccess* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrQUsrAAccess();

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

ubigint PgTblPlnrQUsrAAccess::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrQUsrAAccess& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrQUsrAAccess* rec;

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
			rec = new PlnrQUsrAAccess();

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

bool PgTblPlnrQUsrAAccess::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrQUsrAAccess** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQUsrAAccess / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQUsrAAccess::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrQUsrAAccess& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQUsrAAccess / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblPlnrQUsrAAccess::loadRecBySQL(
			const string& sqlstr
			, PlnrQUsrAAccess** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQUsrAAccess::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQUsrAAccess& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrQUsrAAccess::insertRec(
			PlnrQUsrAAccess* rec
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

	res = PQexecPrepared(dbs, "TblPlnrQUsrAAccess_insertRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQUsrAAccess_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblPlnrQUsrAAccess::insertRst(
			ListPlnrQUsrAAccess& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblPlnrQUsrAAccess::updateRec(
			PlnrQUsrAAccess* rec
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

	res = PQexecPrepared(dbs, "TblPlnrQUsrAAccess_updateRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQUsrAAccess_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrQUsrAAccess::updateRst(
			ListPlnrQUsrAAccess& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblPlnrQUsrAAccess::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblPlnrQUsrAAccess_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQUsrAAccess_removeRecByQref)\n");

	PQclear(res);
};

void PgTblPlnrQUsrAAccess::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblPlnrQUsrAAccess_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQUsrAAccess_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblPlnrQUsrAAccess::loadRecByQref(
			ubigint qref
			, PlnrQUsrAAccess** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrQUsrAAccess_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblPlnrQUsrAAccess::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQUsrAAccess& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrQUsrAAccess_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

