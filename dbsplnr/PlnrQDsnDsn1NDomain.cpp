/**
  * \file PlnrQDsnDsn1NDomain.cpp
  * Dbs and XML wrapper for table TblPlnrQDsnDsn1NDomain (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQDsnDsn1NDomain.h"

/******************************************************************************
 class PlnrQDsnDsn1NDomain
 ******************************************************************************/

PlnrQDsnDsn1NDomain::PlnrQDsnDsn1NDomain(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
			, const uint dsnNum
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->stubRef = stubRef;
	this->dsnNum = dsnNum;
};

void PlnrQDsnDsn1NDomain::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "PlnrQDsnDsn1NDomain";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "ref", stubRef);
	} else {
		writeString(wr, "stubRef", stubRef);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListPlnrQDsnDsn1NDomain
 ******************************************************************************/

ListPlnrQDsnDsn1NDomain::ListPlnrQDsnDsn1NDomain() {
};

ListPlnrQDsnDsn1NDomain::ListPlnrQDsnDsn1NDomain(
			const ListPlnrQDsnDsn1NDomain& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQDsnDsn1NDomain(*(src.nodes[i]));
};

ListPlnrQDsnDsn1NDomain::~ListPlnrQDsnDsn1NDomain() {
	clear();
};

void ListPlnrQDsnDsn1NDomain::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrQDsnDsn1NDomain::size() const {
	return(nodes.size());
};

void ListPlnrQDsnDsn1NDomain::append(
			PlnrQDsnDsn1NDomain* rec
		) {
	nodes.push_back(rec);
};

ListPlnrQDsnDsn1NDomain& ListPlnrQDsnDsn1NDomain::operator=(
			const ListPlnrQDsnDsn1NDomain& src
		) {
	PlnrQDsnDsn1NDomain* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrQDsnDsn1NDomain(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListPlnrQDsnDsn1NDomain::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListPlnrQDsnDsn1NDomain";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblPlnrQDsnDsn1NDomain
 ******************************************************************************/

TblPlnrQDsnDsn1NDomain::TblPlnrQDsnDsn1NDomain() {
};

TblPlnrQDsnDsn1NDomain::~TblPlnrQDsnDsn1NDomain() {
};

bool TblPlnrQDsnDsn1NDomain::loadRecBySQL(
			const string& sqlstr
			, PlnrQDsnDsn1NDomain** rec
		) {
	return false;
};

ubigint TblPlnrQDsnDsn1NDomain::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQDsnDsn1NDomain& rst
		) {
	return 0;
};

void TblPlnrQDsnDsn1NDomain::insertRec(
			PlnrQDsnDsn1NDomain* rec
		) {
};

ubigint TblPlnrQDsnDsn1NDomain::insertNewRec(
			PlnrQDsnDsn1NDomain** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
			, const uint dsnNum
		) {
	ubigint retval = 0;
	PlnrQDsnDsn1NDomain* _rec = NULL;

	_rec = new PlnrQDsnDsn1NDomain(0, jref, jnum, ref, stubRef, dsnNum);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrQDsnDsn1NDomain::appendNewRecToRst(
			ListPlnrQDsnDsn1NDomain& rst
			, PlnrQDsnDsn1NDomain** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
			, const uint dsnNum
		) {
	ubigint retval = 0;
	PlnrQDsnDsn1NDomain* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, stubRef, dsnNum);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrQDsnDsn1NDomain::insertRst(
			ListPlnrQDsnDsn1NDomain& rst
		) {
};

void TblPlnrQDsnDsn1NDomain::updateRec(
			PlnrQDsnDsn1NDomain* rec
		) {
};

void TblPlnrQDsnDsn1NDomain::updateRst(
			ListPlnrQDsnDsn1NDomain& rst
		) {
};

void TblPlnrQDsnDsn1NDomain::removeRecByQref(
			ubigint qref
		) {
};

void TblPlnrQDsnDsn1NDomain::removeRstByJref(
			ubigint jref
		) {
};

bool TblPlnrQDsnDsn1NDomain::loadRecByQref(
			ubigint qref
			, PlnrQDsnDsn1NDomain** rec
		) {
	return false;
};

ubigint TblPlnrQDsnDsn1NDomain::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQDsnDsn1NDomain& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrQDsnDsn1NDomain
 ******************************************************************************/

MyTblPlnrQDsnDsn1NDomain::MyTblPlnrQDsnDsn1NDomain() : TblPlnrQDsnDsn1NDomain(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblPlnrQDsnDsn1NDomain::~MyTblPlnrQDsnDsn1NDomain() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblPlnrQDsnDsn1NDomain::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrQDsnDsn1NDomain (jref, jnum, ref, dsnNum) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrQDsnDsn1NDomain SET jref = ?, jnum = ?, ref = ?, dsnNum = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblPlnrQDsnDsn1NDomain WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblPlnrQDsnDsn1NDomain WHERE jref = ?", false);
};

bool MyTblPlnrQDsnDsn1NDomain::loadRecBySQL(
			const string& sqlstr
			, PlnrQDsnDsn1NDomain** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrQDsnDsn1NDomain* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQDsnDsn1NDomain / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrQDsnDsn1NDomain();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->dsnNum = atol((char*) dbrow[4]); else _rec->dsnNum = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrQDsnDsn1NDomain::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQDsnDsn1NDomain& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrQDsnDsn1NDomain* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQDsnDsn1NDomain / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrQDsnDsn1NDomain();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->dsnNum = atol((char*) dbrow[4]); else rec->dsnNum = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrQDsnDsn1NDomain::insertRec(
			PlnrQDsnDsn1NDomain* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->dsnNum,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQDsnDsn1NDomain / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQDsnDsn1NDomain / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblPlnrQDsnDsn1NDomain::insertRst(
			ListPlnrQDsnDsn1NDomain& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblPlnrQDsnDsn1NDomain::updateRec(
			PlnrQDsnDsn1NDomain* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])), 
		bindUint(&rec->dsnNum,&(l[3]),&(n[3]),&(e[3])), 
		bindUbigint(&rec->qref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQDsnDsn1NDomain / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQDsnDsn1NDomain / stmtUpdateRec)\n");
};

void MyTblPlnrQDsnDsn1NDomain::updateRst(
			ListPlnrQDsnDsn1NDomain& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblPlnrQDsnDsn1NDomain::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQDsnDsn1NDomain / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQDsnDsn1NDomain / stmtRemoveRecByQref)\n");
};

void MyTblPlnrQDsnDsn1NDomain::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQDsnDsn1NDomain / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQDsnDsn1NDomain / stmtRemoveRstByJref)\n");
};

bool MyTblPlnrQDsnDsn1NDomain::loadRecByQref(
			ubigint qref
			, PlnrQDsnDsn1NDomain** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrQDsnDsn1NDomain WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblPlnrQDsnDsn1NDomain::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQDsnDsn1NDomain& rst
		) {
	return loadRstBySQL("SELECT * FROM TblPlnrQDsnDsn1NDomain WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrQDsnDsn1NDomain
 ******************************************************************************/

PgTblPlnrQDsnDsn1NDomain::PgTblPlnrQDsnDsn1NDomain() : TblPlnrQDsnDsn1NDomain(), PgTable() {
};

PgTblPlnrQDsnDsn1NDomain::~PgTblPlnrQDsnDsn1NDomain() {
};

void PgTblPlnrQDsnDsn1NDomain::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrQDsnDsn1NDomain_insertRec", "INSERT INTO TblPlnrQDsnDsn1NDomain (jref, jnum, ref, dsnNum) VALUES ($1,$2,$3,$4) RETURNING qref", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQDsnDsn1NDomain_updateRec", "UPDATE TblPlnrQDsnDsn1NDomain SET jref = $1, jnum = $2, ref = $3, dsnNum = $4 WHERE qref = $5", 5, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQDsnDsn1NDomain_removeRecByQref", "DELETE FROM TblPlnrQDsnDsn1NDomain WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQDsnDsn1NDomain_removeRstByJref", "DELETE FROM TblPlnrQDsnDsn1NDomain WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrQDsnDsn1NDomain_loadRecByQref", "SELECT qref, jref, jnum, ref, dsnNum FROM TblPlnrQDsnDsn1NDomain WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQDsnDsn1NDomain_loadRstByJref", "SELECT qref, jref, jnum, ref, dsnNum FROM TblPlnrQDsnDsn1NDomain WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrQDsnDsn1NDomain::loadRec(
			PGresult* res
			, PlnrQDsnDsn1NDomain** rec
		) {
	char* ptr;

	PlnrQDsnDsn1NDomain* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrQDsnDsn1NDomain();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "dsnnum")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->dsnNum = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrQDsnDsn1NDomain::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrQDsnDsn1NDomain& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrQDsnDsn1NDomain* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "dsnnum")
		};

		while (numread < numrow) {
			rec = new PlnrQDsnDsn1NDomain();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->dsnNum = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrQDsnDsn1NDomain::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrQDsnDsn1NDomain** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDsnDsn1NDomain / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQDsnDsn1NDomain::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrQDsnDsn1NDomain& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDsnDsn1NDomain / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblPlnrQDsnDsn1NDomain::loadRecBySQL(
			const string& sqlstr
			, PlnrQDsnDsn1NDomain** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQDsnDsn1NDomain::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQDsnDsn1NDomain& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrQDsnDsn1NDomain::insertRec(
			PlnrQDsnDsn1NDomain* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _dsnNum = htonl(rec->dsnNum);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_dsnNum
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblPlnrQDsnDsn1NDomain_insertRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDsnDsn1NDomain_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblPlnrQDsnDsn1NDomain::insertRst(
			ListPlnrQDsnDsn1NDomain& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblPlnrQDsnDsn1NDomain::updateRec(
			PlnrQDsnDsn1NDomain* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _dsnNum = htonl(rec->dsnNum);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_dsnNum,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblPlnrQDsnDsn1NDomain_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDsnDsn1NDomain_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrQDsnDsn1NDomain::updateRst(
			ListPlnrQDsnDsn1NDomain& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblPlnrQDsnDsn1NDomain::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblPlnrQDsnDsn1NDomain_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDsnDsn1NDomain_removeRecByQref)\n");

	PQclear(res);
};

void PgTblPlnrQDsnDsn1NDomain::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblPlnrQDsnDsn1NDomain_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDsnDsn1NDomain_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblPlnrQDsnDsn1NDomain::loadRecByQref(
			ubigint qref
			, PlnrQDsnDsn1NDomain** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrQDsnDsn1NDomain_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblPlnrQDsnDsn1NDomain::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQDsnDsn1NDomain& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrQDsnDsn1NDomain_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

