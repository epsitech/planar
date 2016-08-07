/**
  * \file PlnrQUsgMNUser.cpp
  * Dbs and XML wrapper for table TblPlnrQUsgMNUser (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQUsgMNUser.h"

/******************************************************************************
 class PlnrQUsgMNUser
 ******************************************************************************/

PlnrQUsgMNUser::PlnrQUsgMNUser(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const uint ixPlnrVUserlevel
			, const string srefIxPlnrVUserlevel
			, const string titIxPlnrVUserlevel
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->mref = mref;
	this->stubMref = stubMref;
	this->ref = ref;
	this->ixPlnrVUserlevel = ixPlnrVUserlevel;
	this->srefIxPlnrVUserlevel = srefIxPlnrVUserlevel;
	this->titIxPlnrVUserlevel = titIxPlnrVUserlevel;
};

void PlnrQUsgMNUser::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "PlnrQUsgMNUser";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "mref", stubMref);
		writeString(wr, "ulv", srefIxPlnrVUserlevel);
		writeString(wr, "ulv2", titIxPlnrVUserlevel);
	} else {
		writeString(wr, "stubMref", stubMref);
		writeString(wr, "srefIxPlnrVUserlevel", srefIxPlnrVUserlevel);
		writeString(wr, "titIxPlnrVUserlevel", titIxPlnrVUserlevel);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListPlnrQUsgMNUser
 ******************************************************************************/

ListPlnrQUsgMNUser::ListPlnrQUsgMNUser() {
};

ListPlnrQUsgMNUser::ListPlnrQUsgMNUser(
			const ListPlnrQUsgMNUser& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQUsgMNUser(*(src.nodes[i]));
};

ListPlnrQUsgMNUser::~ListPlnrQUsgMNUser() {
	clear();
};

void ListPlnrQUsgMNUser::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrQUsgMNUser::size() const {
	return(nodes.size());
};

void ListPlnrQUsgMNUser::append(
			PlnrQUsgMNUser* rec
		) {
	nodes.push_back(rec);
};

ListPlnrQUsgMNUser& ListPlnrQUsgMNUser::operator=(
			const ListPlnrQUsgMNUser& src
		) {
	PlnrQUsgMNUser* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrQUsgMNUser(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListPlnrQUsgMNUser::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListPlnrQUsgMNUser";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblPlnrQUsgMNUser
 ******************************************************************************/

TblPlnrQUsgMNUser::TblPlnrQUsgMNUser() {
};

TblPlnrQUsgMNUser::~TblPlnrQUsgMNUser() {
};

bool TblPlnrQUsgMNUser::loadRecBySQL(
			const string& sqlstr
			, PlnrQUsgMNUser** rec
		) {
	return false;
};

ubigint TblPlnrQUsgMNUser::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQUsgMNUser& rst
		) {
	return 0;
};

void TblPlnrQUsgMNUser::insertRec(
			PlnrQUsgMNUser* rec
		) {
};

ubigint TblPlnrQUsgMNUser::insertNewRec(
			PlnrQUsgMNUser** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const uint ixPlnrVUserlevel
			, const string srefIxPlnrVUserlevel
			, const string titIxPlnrVUserlevel
		) {
	ubigint retval = 0;
	PlnrQUsgMNUser* _rec = NULL;

	_rec = new PlnrQUsgMNUser(0, jref, jnum, mref, stubMref, ref, ixPlnrVUserlevel, srefIxPlnrVUserlevel, titIxPlnrVUserlevel);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrQUsgMNUser::appendNewRecToRst(
			ListPlnrQUsgMNUser& rst
			, PlnrQUsgMNUser** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const uint ixPlnrVUserlevel
			, const string srefIxPlnrVUserlevel
			, const string titIxPlnrVUserlevel
		) {
	ubigint retval = 0;
	PlnrQUsgMNUser* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, mref, stubMref, ref, ixPlnrVUserlevel, srefIxPlnrVUserlevel, titIxPlnrVUserlevel);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrQUsgMNUser::insertRst(
			ListPlnrQUsgMNUser& rst
		) {
};

void TblPlnrQUsgMNUser::updateRec(
			PlnrQUsgMNUser* rec
		) {
};

void TblPlnrQUsgMNUser::updateRst(
			ListPlnrQUsgMNUser& rst
		) {
};

void TblPlnrQUsgMNUser::removeRecByQref(
			ubigint qref
		) {
};

void TblPlnrQUsgMNUser::removeRstByJref(
			ubigint jref
		) {
};

bool TblPlnrQUsgMNUser::loadRecByQref(
			ubigint qref
			, PlnrQUsgMNUser** rec
		) {
	return false;
};

ubigint TblPlnrQUsgMNUser::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQUsgMNUser& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrQUsgMNUser
 ******************************************************************************/

MyTblPlnrQUsgMNUser::MyTblPlnrQUsgMNUser() : TblPlnrQUsgMNUser(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblPlnrQUsgMNUser::~MyTblPlnrQUsgMNUser() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblPlnrQUsgMNUser::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrQUsgMNUser (jref, jnum, mref, ref, ixPlnrVUserlevel) VALUES (?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrQUsgMNUser SET jref = ?, jnum = ?, mref = ?, ref = ?, ixPlnrVUserlevel = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblPlnrQUsgMNUser WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblPlnrQUsgMNUser WHERE jref = ?", false);
};

bool MyTblPlnrQUsgMNUser::loadRecBySQL(
			const string& sqlstr
			, PlnrQUsgMNUser** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrQUsgMNUser* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQUsgMNUser / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrQUsgMNUser();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->mref = atoll((char*) dbrow[3]); else _rec->mref = 0;
		if (dbrow[4]) _rec->ref = atoll((char*) dbrow[4]); else _rec->ref = 0;
		if (dbrow[5]) _rec->ixPlnrVUserlevel = atol((char*) dbrow[5]); else _rec->ixPlnrVUserlevel = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrQUsgMNUser::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQUsgMNUser& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrQUsgMNUser* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQUsgMNUser / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrQUsgMNUser();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->mref = atoll((char*) dbrow[3]); else rec->mref = 0;
			if (dbrow[4]) rec->ref = atoll((char*) dbrow[4]); else rec->ref = 0;
			if (dbrow[5]) rec->ixPlnrVUserlevel = atol((char*) dbrow[5]); else rec->ixPlnrVUserlevel = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrQUsgMNUser::insertRec(
			PlnrQUsgMNUser* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->mref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->ixPlnrVUserlevel,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQUsgMNUser / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQUsgMNUser / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblPlnrQUsgMNUser::insertRst(
			ListPlnrQUsgMNUser& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblPlnrQUsgMNUser::updateRec(
			PlnrQUsgMNUser* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->mref,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3])), 
		bindUint(&rec->ixPlnrVUserlevel,&(l[4]),&(n[4]),&(e[4])), 
		bindUbigint(&rec->qref,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQUsgMNUser / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQUsgMNUser / stmtUpdateRec)\n");
};

void MyTblPlnrQUsgMNUser::updateRst(
			ListPlnrQUsgMNUser& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblPlnrQUsgMNUser::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQUsgMNUser / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQUsgMNUser / stmtRemoveRecByQref)\n");
};

void MyTblPlnrQUsgMNUser::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQUsgMNUser / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQUsgMNUser / stmtRemoveRstByJref)\n");
};

bool MyTblPlnrQUsgMNUser::loadRecByQref(
			ubigint qref
			, PlnrQUsgMNUser** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrQUsgMNUser WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblPlnrQUsgMNUser::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQUsgMNUser& rst
		) {
	return loadRstBySQL("SELECT * FROM TblPlnrQUsgMNUser WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrQUsgMNUser
 ******************************************************************************/

PgTblPlnrQUsgMNUser::PgTblPlnrQUsgMNUser() : TblPlnrQUsgMNUser(), PgTable() {
};

PgTblPlnrQUsgMNUser::~PgTblPlnrQUsgMNUser() {
};

void PgTblPlnrQUsgMNUser::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrQUsgMNUser_insertRec", "INSERT INTO TblPlnrQUsgMNUser (jref, jnum, mref, ref, ixPlnrVUserlevel) VALUES ($1,$2,$3,$4,$5) RETURNING qref", 5, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQUsgMNUser_updateRec", "UPDATE TblPlnrQUsgMNUser SET jref = $1, jnum = $2, mref = $3, ref = $4, ixPlnrVUserlevel = $5 WHERE qref = $6", 6, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQUsgMNUser_removeRecByQref", "DELETE FROM TblPlnrQUsgMNUser WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQUsgMNUser_removeRstByJref", "DELETE FROM TblPlnrQUsgMNUser WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrQUsgMNUser_loadRecByQref", "SELECT qref, jref, jnum, mref, ref, ixPlnrVUserlevel FROM TblPlnrQUsgMNUser WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQUsgMNUser_loadRstByJref", "SELECT qref, jref, jnum, mref, ref, ixPlnrVUserlevel FROM TblPlnrQUsgMNUser WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrQUsgMNUser::loadRec(
			PGresult* res
			, PlnrQUsgMNUser** rec
		) {
	char* ptr;

	PlnrQUsgMNUser* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrQUsgMNUser();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "mref"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "ixplnrvuserlevel")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->mref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->ixPlnrVUserlevel = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrQUsgMNUser::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrQUsgMNUser& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrQUsgMNUser* rec;

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
			PQfnumber(res, "ixplnrvuserlevel")
		};

		while (numread < numrow) {
			rec = new PlnrQUsgMNUser();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->mref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->ixPlnrVUserlevel = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrQUsgMNUser::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrQUsgMNUser** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQUsgMNUser / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQUsgMNUser::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrQUsgMNUser& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQUsgMNUser / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblPlnrQUsgMNUser::loadRecBySQL(
			const string& sqlstr
			, PlnrQUsgMNUser** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQUsgMNUser::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQUsgMNUser& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrQUsgMNUser::insertRec(
			PlnrQUsgMNUser* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _mref = htonl64(rec->mref);
	ubigint _ref = htonl64(rec->ref);
	uint _ixPlnrVUserlevel = htonl(rec->ixPlnrVUserlevel);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_mref,
		(char*) &_ref,
		(char*) &_ixPlnrVUserlevel
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblPlnrQUsgMNUser_insertRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQUsgMNUser_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblPlnrQUsgMNUser::insertRst(
			ListPlnrQUsgMNUser& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblPlnrQUsgMNUser::updateRec(
			PlnrQUsgMNUser* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _mref = htonl64(rec->mref);
	ubigint _ref = htonl64(rec->ref);
	uint _ixPlnrVUserlevel = htonl(rec->ixPlnrVUserlevel);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_mref,
		(char*) &_ref,
		(char*) &_ixPlnrVUserlevel,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblPlnrQUsgMNUser_updateRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQUsgMNUser_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrQUsgMNUser::updateRst(
			ListPlnrQUsgMNUser& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblPlnrQUsgMNUser::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblPlnrQUsgMNUser_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQUsgMNUser_removeRecByQref)\n");

	PQclear(res);
};

void PgTblPlnrQUsgMNUser::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblPlnrQUsgMNUser_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQUsgMNUser_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblPlnrQUsgMNUser::loadRecByQref(
			ubigint qref
			, PlnrQUsgMNUser** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrQUsgMNUser_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblPlnrQUsgMNUser::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQUsgMNUser& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrQUsgMNUser_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

