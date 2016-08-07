/**
  * \file PlnrQPrsADetail.cpp
  * Dbs and XML wrapper for table TblPlnrQPrsADetail (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQPrsADetail.h"

/******************************************************************************
 class PlnrQPrsADetail
 ******************************************************************************/

PlnrQPrsADetail::PlnrQPrsADetail(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string x1SrefKType
			, const string titX1SrefKType
			, const string Val
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->x1SrefKType = x1SrefKType;
	this->titX1SrefKType = titX1SrefKType;
	this->Val = Val;
};

void PlnrQPrsADetail::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "PlnrQPrsADetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "typ", x1SrefKType);
		writeString(wr, "typ2", titX1SrefKType);
		writeString(wr, "val", Val);
	} else {
		writeString(wr, "x1SrefKType", x1SrefKType);
		writeString(wr, "titX1SrefKType", titX1SrefKType);
		writeString(wr, "Val", Val);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListPlnrQPrsADetail
 ******************************************************************************/

ListPlnrQPrsADetail::ListPlnrQPrsADetail() {
};

ListPlnrQPrsADetail::ListPlnrQPrsADetail(
			const ListPlnrQPrsADetail& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQPrsADetail(*(src.nodes[i]));
};

ListPlnrQPrsADetail::~ListPlnrQPrsADetail() {
	clear();
};

void ListPlnrQPrsADetail::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrQPrsADetail::size() const {
	return(nodes.size());
};

void ListPlnrQPrsADetail::append(
			PlnrQPrsADetail* rec
		) {
	nodes.push_back(rec);
};

ListPlnrQPrsADetail& ListPlnrQPrsADetail::operator=(
			const ListPlnrQPrsADetail& src
		) {
	PlnrQPrsADetail* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrQPrsADetail(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListPlnrQPrsADetail::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListPlnrQPrsADetail";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblPlnrQPrsADetail
 ******************************************************************************/

TblPlnrQPrsADetail::TblPlnrQPrsADetail() {
};

TblPlnrQPrsADetail::~TblPlnrQPrsADetail() {
};

bool TblPlnrQPrsADetail::loadRecBySQL(
			const string& sqlstr
			, PlnrQPrsADetail** rec
		) {
	return false;
};

ubigint TblPlnrQPrsADetail::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQPrsADetail& rst
		) {
	return 0;
};

void TblPlnrQPrsADetail::insertRec(
			PlnrQPrsADetail* rec
		) {
};

ubigint TblPlnrQPrsADetail::insertNewRec(
			PlnrQPrsADetail** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string x1SrefKType
			, const string titX1SrefKType
			, const string Val
		) {
	ubigint retval = 0;
	PlnrQPrsADetail* _rec = NULL;

	_rec = new PlnrQPrsADetail(0, jref, jnum, ref, x1SrefKType, titX1SrefKType, Val);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrQPrsADetail::appendNewRecToRst(
			ListPlnrQPrsADetail& rst
			, PlnrQPrsADetail** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string x1SrefKType
			, const string titX1SrefKType
			, const string Val
		) {
	ubigint retval = 0;
	PlnrQPrsADetail* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, x1SrefKType, titX1SrefKType, Val);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrQPrsADetail::insertRst(
			ListPlnrQPrsADetail& rst
		) {
};

void TblPlnrQPrsADetail::updateRec(
			PlnrQPrsADetail* rec
		) {
};

void TblPlnrQPrsADetail::updateRst(
			ListPlnrQPrsADetail& rst
		) {
};

void TblPlnrQPrsADetail::removeRecByQref(
			ubigint qref
		) {
};

void TblPlnrQPrsADetail::removeRstByJref(
			ubigint jref
		) {
};

bool TblPlnrQPrsADetail::loadRecByQref(
			ubigint qref
			, PlnrQPrsADetail** rec
		) {
	return false;
};

ubigint TblPlnrQPrsADetail::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQPrsADetail& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrQPrsADetail
 ******************************************************************************/

MyTblPlnrQPrsADetail::MyTblPlnrQPrsADetail() : TblPlnrQPrsADetail(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblPlnrQPrsADetail::~MyTblPlnrQPrsADetail() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblPlnrQPrsADetail::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrQPrsADetail (jref, jnum, ref, x1SrefKType, Val) VALUES (?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrQPrsADetail SET jref = ?, jnum = ?, ref = ?, x1SrefKType = ?, Val = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblPlnrQPrsADetail WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblPlnrQPrsADetail WHERE jref = ?", false);
};

bool MyTblPlnrQPrsADetail::loadRecBySQL(
			const string& sqlstr
			, PlnrQPrsADetail** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrQPrsADetail* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQPrsADetail / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrQPrsADetail();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->x1SrefKType.assign(dbrow[4], dblengths[4]); else _rec->x1SrefKType = "";
		if (dbrow[5]) _rec->Val.assign(dbrow[5], dblengths[5]); else _rec->Val = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrQPrsADetail::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQPrsADetail& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrQPrsADetail* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQPrsADetail / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrQPrsADetail();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->x1SrefKType.assign(dbrow[4], dblengths[4]); else rec->x1SrefKType = "";
			if (dbrow[5]) rec->Val.assign(dbrow[5], dblengths[5]); else rec->Val = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrQPrsADetail::insertRec(
			PlnrQPrsADetail* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[3] = rec->x1SrefKType.length();
	l[4] = rec->Val.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->x1SrefKType.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Val.c_str()),&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQPrsADetail / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQPrsADetail / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblPlnrQPrsADetail::insertRst(
			ListPlnrQPrsADetail& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblPlnrQPrsADetail::updateRec(
			PlnrQPrsADetail* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	l[3] = rec->x1SrefKType.length();
	l[4] = rec->Val.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])), 
		bindCstring((char*) (rec->x1SrefKType.c_str()),&(l[3]),&(n[3]),&(e[3])), 
		bindCstring((char*) (rec->Val.c_str()),&(l[4]),&(n[4]),&(e[4])), 
		bindUbigint(&rec->qref,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQPrsADetail / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQPrsADetail / stmtUpdateRec)\n");
};

void MyTblPlnrQPrsADetail::updateRst(
			ListPlnrQPrsADetail& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblPlnrQPrsADetail::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQPrsADetail / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQPrsADetail / stmtRemoveRecByQref)\n");
};

void MyTblPlnrQPrsADetail::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQPrsADetail / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQPrsADetail / stmtRemoveRstByJref)\n");
};

bool MyTblPlnrQPrsADetail::loadRecByQref(
			ubigint qref
			, PlnrQPrsADetail** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrQPrsADetail WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblPlnrQPrsADetail::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQPrsADetail& rst
		) {
	return loadRstBySQL("SELECT * FROM TblPlnrQPrsADetail WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrQPrsADetail
 ******************************************************************************/

PgTblPlnrQPrsADetail::PgTblPlnrQPrsADetail() : TblPlnrQPrsADetail(), PgTable() {
};

PgTblPlnrQPrsADetail::~PgTblPlnrQPrsADetail() {
};

void PgTblPlnrQPrsADetail::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrQPrsADetail_insertRec", "INSERT INTO TblPlnrQPrsADetail (jref, jnum, ref, x1SrefKType, Val) VALUES ($1,$2,$3,$4,$5) RETURNING qref", 5, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQPrsADetail_updateRec", "UPDATE TblPlnrQPrsADetail SET jref = $1, jnum = $2, ref = $3, x1SrefKType = $4, Val = $5 WHERE qref = $6", 6, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQPrsADetail_removeRecByQref", "DELETE FROM TblPlnrQPrsADetail WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQPrsADetail_removeRstByJref", "DELETE FROM TblPlnrQPrsADetail WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrQPrsADetail_loadRecByQref", "SELECT qref, jref, jnum, ref, x1SrefKType, Val FROM TblPlnrQPrsADetail WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQPrsADetail_loadRstByJref", "SELECT qref, jref, jnum, ref, x1SrefKType, Val FROM TblPlnrQPrsADetail WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrQPrsADetail::loadRec(
			PGresult* res
			, PlnrQPrsADetail** rec
		) {
	char* ptr;

	PlnrQPrsADetail* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrQPrsADetail();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1srefktype"),
			PQfnumber(res, "val")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->x1SrefKType.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->Val.assign(ptr, PQgetlength(res, 0, fnum[5]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrQPrsADetail::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrQPrsADetail& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrQPrsADetail* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1srefktype"),
			PQfnumber(res, "val")
		};

		while (numread < numrow) {
			rec = new PlnrQPrsADetail();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->x1SrefKType.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->Val.assign(ptr, PQgetlength(res, numread, fnum[5]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrQPrsADetail::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrQPrsADetail** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQPrsADetail / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQPrsADetail::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrQPrsADetail& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQPrsADetail / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblPlnrQPrsADetail::loadRecBySQL(
			const string& sqlstr
			, PlnrQPrsADetail** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQPrsADetail::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQPrsADetail& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrQPrsADetail::insertRec(
			PlnrQPrsADetail* rec
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
		rec->x1SrefKType.c_str(),
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

	res = PQexecPrepared(dbs, "TblPlnrQPrsADetail_insertRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQPrsADetail_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblPlnrQPrsADetail::insertRst(
			ListPlnrQPrsADetail& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblPlnrQPrsADetail::updateRec(
			PlnrQPrsADetail* rec
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
		rec->x1SrefKType.c_str(),
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

	res = PQexecPrepared(dbs, "TblPlnrQPrsADetail_updateRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQPrsADetail_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrQPrsADetail::updateRst(
			ListPlnrQPrsADetail& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblPlnrQPrsADetail::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblPlnrQPrsADetail_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQPrsADetail_removeRecByQref)\n");

	PQclear(res);
};

void PgTblPlnrQPrsADetail::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblPlnrQPrsADetail_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQPrsADetail_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblPlnrQPrsADetail::loadRecByQref(
			ubigint qref
			, PlnrQPrsADetail** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrQPrsADetail_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblPlnrQPrsADetail::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQPrsADetail& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrQPrsADetail_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

