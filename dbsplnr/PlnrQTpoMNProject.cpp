/**
  * \file PlnrQTpoMNProject.cpp
  * Dbs and XML wrapper for table TblPlnrQTpoMNProject (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQTpoMNProject.h"

/******************************************************************************
 class PlnrQTpoMNProject
 ******************************************************************************/

PlnrQTpoMNProject::PlnrQTpoMNProject(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->mref = mref;
	this->stubMref = stubMref;
	this->ref = ref;
};

void PlnrQTpoMNProject::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "PlnrQTpoMNProject";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "mref", stubMref);
	} else {
		writeString(wr, "stubMref", stubMref);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListPlnrQTpoMNProject
 ******************************************************************************/

ListPlnrQTpoMNProject::ListPlnrQTpoMNProject() {
};

ListPlnrQTpoMNProject::ListPlnrQTpoMNProject(
			const ListPlnrQTpoMNProject& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQTpoMNProject(*(src.nodes[i]));
};

ListPlnrQTpoMNProject::~ListPlnrQTpoMNProject() {
	clear();
};

void ListPlnrQTpoMNProject::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrQTpoMNProject::size() const {
	return(nodes.size());
};

void ListPlnrQTpoMNProject::append(
			PlnrQTpoMNProject* rec
		) {
	nodes.push_back(rec);
};

ListPlnrQTpoMNProject& ListPlnrQTpoMNProject::operator=(
			const ListPlnrQTpoMNProject& src
		) {
	PlnrQTpoMNProject* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrQTpoMNProject(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListPlnrQTpoMNProject::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListPlnrQTpoMNProject";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblPlnrQTpoMNProject
 ******************************************************************************/

TblPlnrQTpoMNProject::TblPlnrQTpoMNProject() {
};

TblPlnrQTpoMNProject::~TblPlnrQTpoMNProject() {
};

bool TblPlnrQTpoMNProject::loadRecBySQL(
			const string& sqlstr
			, PlnrQTpoMNProject** rec
		) {
	return false;
};

ubigint TblPlnrQTpoMNProject::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQTpoMNProject& rst
		) {
	return 0;
};

void TblPlnrQTpoMNProject::insertRec(
			PlnrQTpoMNProject* rec
		) {
};

ubigint TblPlnrQTpoMNProject::insertNewRec(
			PlnrQTpoMNProject** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
		) {
	ubigint retval = 0;
	PlnrQTpoMNProject* _rec = NULL;

	_rec = new PlnrQTpoMNProject(0, jref, jnum, mref, stubMref, ref);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrQTpoMNProject::appendNewRecToRst(
			ListPlnrQTpoMNProject& rst
			, PlnrQTpoMNProject** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
		) {
	ubigint retval = 0;
	PlnrQTpoMNProject* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, mref, stubMref, ref);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrQTpoMNProject::insertRst(
			ListPlnrQTpoMNProject& rst
		) {
};

void TblPlnrQTpoMNProject::updateRec(
			PlnrQTpoMNProject* rec
		) {
};

void TblPlnrQTpoMNProject::updateRst(
			ListPlnrQTpoMNProject& rst
		) {
};

void TblPlnrQTpoMNProject::removeRecByQref(
			ubigint qref
		) {
};

void TblPlnrQTpoMNProject::removeRstByJref(
			ubigint jref
		) {
};

bool TblPlnrQTpoMNProject::loadRecByQref(
			ubigint qref
			, PlnrQTpoMNProject** rec
		) {
	return false;
};

ubigint TblPlnrQTpoMNProject::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQTpoMNProject& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrQTpoMNProject
 ******************************************************************************/

MyTblPlnrQTpoMNProject::MyTblPlnrQTpoMNProject() : TblPlnrQTpoMNProject(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblPlnrQTpoMNProject::~MyTblPlnrQTpoMNProject() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblPlnrQTpoMNProject::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrQTpoMNProject (jref, jnum, mref, ref) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrQTpoMNProject SET jref = ?, jnum = ?, mref = ?, ref = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblPlnrQTpoMNProject WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblPlnrQTpoMNProject WHERE jref = ?", false);
};

bool MyTblPlnrQTpoMNProject::loadRecBySQL(
			const string& sqlstr
			, PlnrQTpoMNProject** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrQTpoMNProject* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQTpoMNProject / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrQTpoMNProject();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->mref = atoll((char*) dbrow[3]); else _rec->mref = 0;
		if (dbrow[4]) _rec->ref = atoll((char*) dbrow[4]); else _rec->ref = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrQTpoMNProject::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQTpoMNProject& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrQTpoMNProject* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQTpoMNProject / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrQTpoMNProject();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->mref = atoll((char*) dbrow[3]); else rec->mref = 0;
			if (dbrow[4]) rec->ref = atoll((char*) dbrow[4]); else rec->ref = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrQTpoMNProject::insertRec(
			PlnrQTpoMNProject* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->mref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQTpoMNProject / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQTpoMNProject / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblPlnrQTpoMNProject::insertRst(
			ListPlnrQTpoMNProject& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblPlnrQTpoMNProject::updateRec(
			PlnrQTpoMNProject* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->mref,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3])), 
		bindUbigint(&rec->qref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQTpoMNProject / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQTpoMNProject / stmtUpdateRec)\n");
};

void MyTblPlnrQTpoMNProject::updateRst(
			ListPlnrQTpoMNProject& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblPlnrQTpoMNProject::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQTpoMNProject / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQTpoMNProject / stmtRemoveRecByQref)\n");
};

void MyTblPlnrQTpoMNProject::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQTpoMNProject / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQTpoMNProject / stmtRemoveRstByJref)\n");
};

bool MyTblPlnrQTpoMNProject::loadRecByQref(
			ubigint qref
			, PlnrQTpoMNProject** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrQTpoMNProject WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblPlnrQTpoMNProject::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQTpoMNProject& rst
		) {
	return loadRstBySQL("SELECT * FROM TblPlnrQTpoMNProject WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrQTpoMNProject
 ******************************************************************************/

PgTblPlnrQTpoMNProject::PgTblPlnrQTpoMNProject() : TblPlnrQTpoMNProject(), PgTable() {
};

PgTblPlnrQTpoMNProject::~PgTblPlnrQTpoMNProject() {
};

void PgTblPlnrQTpoMNProject::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrQTpoMNProject_insertRec", "INSERT INTO TblPlnrQTpoMNProject (jref, jnum, mref, ref) VALUES ($1,$2,$3,$4) RETURNING qref", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQTpoMNProject_updateRec", "UPDATE TblPlnrQTpoMNProject SET jref = $1, jnum = $2, mref = $3, ref = $4 WHERE qref = $5", 5, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQTpoMNProject_removeRecByQref", "DELETE FROM TblPlnrQTpoMNProject WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQTpoMNProject_removeRstByJref", "DELETE FROM TblPlnrQTpoMNProject WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrQTpoMNProject_loadRecByQref", "SELECT qref, jref, jnum, mref, ref FROM TblPlnrQTpoMNProject WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQTpoMNProject_loadRstByJref", "SELECT qref, jref, jnum, mref, ref FROM TblPlnrQTpoMNProject WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrQTpoMNProject::loadRec(
			PGresult* res
			, PlnrQTpoMNProject** rec
		) {
	char* ptr;

	PlnrQTpoMNProject* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrQTpoMNProject();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "mref"),
			PQfnumber(res, "ref")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->mref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->ref = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrQTpoMNProject::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrQTpoMNProject& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrQTpoMNProject* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "mref"),
			PQfnumber(res, "ref")
		};

		while (numread < numrow) {
			rec = new PlnrQTpoMNProject();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->mref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->ref = atoll(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrQTpoMNProject::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrQTpoMNProject** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQTpoMNProject / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQTpoMNProject::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrQTpoMNProject& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQTpoMNProject / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblPlnrQTpoMNProject::loadRecBySQL(
			const string& sqlstr
			, PlnrQTpoMNProject** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQTpoMNProject::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQTpoMNProject& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrQTpoMNProject::insertRec(
			PlnrQTpoMNProject* rec
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
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblPlnrQTpoMNProject_insertRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQTpoMNProject_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblPlnrQTpoMNProject::insertRst(
			ListPlnrQTpoMNProject& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblPlnrQTpoMNProject::updateRec(
			PlnrQTpoMNProject* rec
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
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblPlnrQTpoMNProject_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQTpoMNProject_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrQTpoMNProject::updateRst(
			ListPlnrQTpoMNProject& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblPlnrQTpoMNProject::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblPlnrQTpoMNProject_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQTpoMNProject_removeRecByQref)\n");

	PQclear(res);
};

void PgTblPlnrQTpoMNProject::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblPlnrQTpoMNProject_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQTpoMNProject_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblPlnrQTpoMNProject::loadRecByQref(
			ubigint qref
			, PlnrQTpoMNProject** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrQTpoMNProject_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblPlnrQTpoMNProject::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQTpoMNProject& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrQTpoMNProject_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

