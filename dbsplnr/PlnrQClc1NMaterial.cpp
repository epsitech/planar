/**
  * \file PlnrQClc1NMaterial.cpp
  * Dbs and XML wrapper for table TblPlnrQClc1NMaterial (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQClc1NMaterial.h"

/******************************************************************************
 class PlnrQClc1NMaterial
 ******************************************************************************/

PlnrQClc1NMaterial::PlnrQClc1NMaterial(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->stubRef = stubRef;
};

void PlnrQClc1NMaterial::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "PlnrQClc1NMaterial";

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
 class ListPlnrQClc1NMaterial
 ******************************************************************************/

ListPlnrQClc1NMaterial::ListPlnrQClc1NMaterial() {
};

ListPlnrQClc1NMaterial::ListPlnrQClc1NMaterial(
			const ListPlnrQClc1NMaterial& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQClc1NMaterial(*(src.nodes[i]));
};

ListPlnrQClc1NMaterial::~ListPlnrQClc1NMaterial() {
	clear();
};

void ListPlnrQClc1NMaterial::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrQClc1NMaterial::size() const {
	return(nodes.size());
};

void ListPlnrQClc1NMaterial::append(
			PlnrQClc1NMaterial* rec
		) {
	nodes.push_back(rec);
};

ListPlnrQClc1NMaterial& ListPlnrQClc1NMaterial::operator=(
			const ListPlnrQClc1NMaterial& src
		) {
	PlnrQClc1NMaterial* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrQClc1NMaterial(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListPlnrQClc1NMaterial::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListPlnrQClc1NMaterial";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblPlnrQClc1NMaterial
 ******************************************************************************/

TblPlnrQClc1NMaterial::TblPlnrQClc1NMaterial() {
};

TblPlnrQClc1NMaterial::~TblPlnrQClc1NMaterial() {
};

bool TblPlnrQClc1NMaterial::loadRecBySQL(
			const string& sqlstr
			, PlnrQClc1NMaterial** rec
		) {
	return false;
};

ubigint TblPlnrQClc1NMaterial::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQClc1NMaterial& rst
		) {
	return 0;
};

void TblPlnrQClc1NMaterial::insertRec(
			PlnrQClc1NMaterial* rec
		) {
};

ubigint TblPlnrQClc1NMaterial::insertNewRec(
			PlnrQClc1NMaterial** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	PlnrQClc1NMaterial* _rec = NULL;

	_rec = new PlnrQClc1NMaterial(0, jref, jnum, ref, stubRef);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrQClc1NMaterial::appendNewRecToRst(
			ListPlnrQClc1NMaterial& rst
			, PlnrQClc1NMaterial** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	PlnrQClc1NMaterial* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, stubRef);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrQClc1NMaterial::insertRst(
			ListPlnrQClc1NMaterial& rst
		) {
};

void TblPlnrQClc1NMaterial::updateRec(
			PlnrQClc1NMaterial* rec
		) {
};

void TblPlnrQClc1NMaterial::updateRst(
			ListPlnrQClc1NMaterial& rst
		) {
};

void TblPlnrQClc1NMaterial::removeRecByQref(
			ubigint qref
		) {
};

void TblPlnrQClc1NMaterial::removeRstByJref(
			ubigint jref
		) {
};

bool TblPlnrQClc1NMaterial::loadRecByQref(
			ubigint qref
			, PlnrQClc1NMaterial** rec
		) {
	return false;
};

ubigint TblPlnrQClc1NMaterial::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQClc1NMaterial& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrQClc1NMaterial
 ******************************************************************************/

MyTblPlnrQClc1NMaterial::MyTblPlnrQClc1NMaterial() : TblPlnrQClc1NMaterial(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblPlnrQClc1NMaterial::~MyTblPlnrQClc1NMaterial() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblPlnrQClc1NMaterial::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrQClc1NMaterial (jref, jnum, ref) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrQClc1NMaterial SET jref = ?, jnum = ?, ref = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblPlnrQClc1NMaterial WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblPlnrQClc1NMaterial WHERE jref = ?", false);
};

bool MyTblPlnrQClc1NMaterial::loadRecBySQL(
			const string& sqlstr
			, PlnrQClc1NMaterial** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrQClc1NMaterial* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQClc1NMaterial / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrQClc1NMaterial();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrQClc1NMaterial::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQClc1NMaterial& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrQClc1NMaterial* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQClc1NMaterial / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrQClc1NMaterial();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrQClc1NMaterial::insertRec(
			PlnrQClc1NMaterial* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQClc1NMaterial / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQClc1NMaterial / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblPlnrQClc1NMaterial::insertRst(
			ListPlnrQClc1NMaterial& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblPlnrQClc1NMaterial::updateRec(
			PlnrQClc1NMaterial* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->qref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQClc1NMaterial / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQClc1NMaterial / stmtUpdateRec)\n");
};

void MyTblPlnrQClc1NMaterial::updateRst(
			ListPlnrQClc1NMaterial& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblPlnrQClc1NMaterial::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQClc1NMaterial / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQClc1NMaterial / stmtRemoveRecByQref)\n");
};

void MyTblPlnrQClc1NMaterial::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQClc1NMaterial / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQClc1NMaterial / stmtRemoveRstByJref)\n");
};

bool MyTblPlnrQClc1NMaterial::loadRecByQref(
			ubigint qref
			, PlnrQClc1NMaterial** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrQClc1NMaterial WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblPlnrQClc1NMaterial::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQClc1NMaterial& rst
		) {
	return loadRstBySQL("SELECT * FROM TblPlnrQClc1NMaterial WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrQClc1NMaterial
 ******************************************************************************/

PgTblPlnrQClc1NMaterial::PgTblPlnrQClc1NMaterial() : TblPlnrQClc1NMaterial(), PgTable() {
};

PgTblPlnrQClc1NMaterial::~PgTblPlnrQClc1NMaterial() {
};

void PgTblPlnrQClc1NMaterial::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrQClc1NMaterial_insertRec", "INSERT INTO TblPlnrQClc1NMaterial (jref, jnum, ref) VALUES ($1,$2,$3) RETURNING qref", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQClc1NMaterial_updateRec", "UPDATE TblPlnrQClc1NMaterial SET jref = $1, jnum = $2, ref = $3 WHERE qref = $4", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQClc1NMaterial_removeRecByQref", "DELETE FROM TblPlnrQClc1NMaterial WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQClc1NMaterial_removeRstByJref", "DELETE FROM TblPlnrQClc1NMaterial WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrQClc1NMaterial_loadRecByQref", "SELECT qref, jref, jnum, ref FROM TblPlnrQClc1NMaterial WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQClc1NMaterial_loadRstByJref", "SELECT qref, jref, jnum, ref FROM TblPlnrQClc1NMaterial WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrQClc1NMaterial::loadRec(
			PGresult* res
			, PlnrQClc1NMaterial** rec
		) {
	char* ptr;

	PlnrQClc1NMaterial* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrQClc1NMaterial();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrQClc1NMaterial::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrQClc1NMaterial& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrQClc1NMaterial* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref")
		};

		while (numread < numrow) {
			rec = new PlnrQClc1NMaterial();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrQClc1NMaterial::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrQClc1NMaterial** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQClc1NMaterial / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQClc1NMaterial::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrQClc1NMaterial& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQClc1NMaterial / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblPlnrQClc1NMaterial::loadRecBySQL(
			const string& sqlstr
			, PlnrQClc1NMaterial** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQClc1NMaterial::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQClc1NMaterial& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrQClc1NMaterial::insertRec(
			PlnrQClc1NMaterial* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1};

	res = PQexecPrepared(dbs, "TblPlnrQClc1NMaterial_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQClc1NMaterial_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblPlnrQClc1NMaterial::insertRst(
			ListPlnrQClc1NMaterial& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblPlnrQClc1NMaterial::updateRec(
			PlnrQClc1NMaterial* rec
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
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblPlnrQClc1NMaterial_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQClc1NMaterial_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrQClc1NMaterial::updateRst(
			ListPlnrQClc1NMaterial& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblPlnrQClc1NMaterial::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblPlnrQClc1NMaterial_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQClc1NMaterial_removeRecByQref)\n");

	PQclear(res);
};

void PgTblPlnrQClc1NMaterial::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblPlnrQClc1NMaterial_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQClc1NMaterial_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblPlnrQClc1NMaterial::loadRecByQref(
			ubigint qref
			, PlnrQClc1NMaterial** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrQClc1NMaterial_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblPlnrQClc1NMaterial::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQClc1NMaterial& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrQClc1NMaterial_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

