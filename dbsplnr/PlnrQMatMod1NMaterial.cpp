/**
  * \file PlnrQMatMod1NMaterial.cpp
  * Dbs and XML wrapper for table TblPlnrQMatMod1NMaterial (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQMatMod1NMaterial.h"

/******************************************************************************
 class PlnrQMatMod1NMaterial
 ******************************************************************************/

PlnrQMatMod1NMaterial::PlnrQMatMod1NMaterial(
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

void PlnrQMatMod1NMaterial::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "PlnrQMatMod1NMaterial";

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
 class ListPlnrQMatMod1NMaterial
 ******************************************************************************/

ListPlnrQMatMod1NMaterial::ListPlnrQMatMod1NMaterial() {
};

ListPlnrQMatMod1NMaterial::ListPlnrQMatMod1NMaterial(
			const ListPlnrQMatMod1NMaterial& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQMatMod1NMaterial(*(src.nodes[i]));
};

ListPlnrQMatMod1NMaterial::~ListPlnrQMatMod1NMaterial() {
	clear();
};

void ListPlnrQMatMod1NMaterial::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrQMatMod1NMaterial::size() const {
	return(nodes.size());
};

void ListPlnrQMatMod1NMaterial::append(
			PlnrQMatMod1NMaterial* rec
		) {
	nodes.push_back(rec);
};

ListPlnrQMatMod1NMaterial& ListPlnrQMatMod1NMaterial::operator=(
			const ListPlnrQMatMod1NMaterial& src
		) {
	PlnrQMatMod1NMaterial* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrQMatMod1NMaterial(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListPlnrQMatMod1NMaterial::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListPlnrQMatMod1NMaterial";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblPlnrQMatMod1NMaterial
 ******************************************************************************/

TblPlnrQMatMod1NMaterial::TblPlnrQMatMod1NMaterial() {
};

TblPlnrQMatMod1NMaterial::~TblPlnrQMatMod1NMaterial() {
};

bool TblPlnrQMatMod1NMaterial::loadRecBySQL(
			const string& sqlstr
			, PlnrQMatMod1NMaterial** rec
		) {
	return false;
};

ubigint TblPlnrQMatMod1NMaterial::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQMatMod1NMaterial& rst
		) {
	return 0;
};

void TblPlnrQMatMod1NMaterial::insertRec(
			PlnrQMatMod1NMaterial* rec
		) {
};

ubigint TblPlnrQMatMod1NMaterial::insertNewRec(
			PlnrQMatMod1NMaterial** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	PlnrQMatMod1NMaterial* _rec = NULL;

	_rec = new PlnrQMatMod1NMaterial(0, jref, jnum, ref, stubRef);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrQMatMod1NMaterial::appendNewRecToRst(
			ListPlnrQMatMod1NMaterial& rst
			, PlnrQMatMod1NMaterial** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	PlnrQMatMod1NMaterial* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, stubRef);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrQMatMod1NMaterial::insertRst(
			ListPlnrQMatMod1NMaterial& rst
		) {
};

void TblPlnrQMatMod1NMaterial::updateRec(
			PlnrQMatMod1NMaterial* rec
		) {
};

void TblPlnrQMatMod1NMaterial::updateRst(
			ListPlnrQMatMod1NMaterial& rst
		) {
};

void TblPlnrQMatMod1NMaterial::removeRecByQref(
			ubigint qref
		) {
};

void TblPlnrQMatMod1NMaterial::removeRstByJref(
			ubigint jref
		) {
};

bool TblPlnrQMatMod1NMaterial::loadRecByQref(
			ubigint qref
			, PlnrQMatMod1NMaterial** rec
		) {
	return false;
};

ubigint TblPlnrQMatMod1NMaterial::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQMatMod1NMaterial& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrQMatMod1NMaterial
 ******************************************************************************/

MyTblPlnrQMatMod1NMaterial::MyTblPlnrQMatMod1NMaterial() : TblPlnrQMatMod1NMaterial(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblPlnrQMatMod1NMaterial::~MyTblPlnrQMatMod1NMaterial() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblPlnrQMatMod1NMaterial::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrQMatMod1NMaterial (jref, jnum, ref) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrQMatMod1NMaterial SET jref = ?, jnum = ?, ref = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblPlnrQMatMod1NMaterial WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblPlnrQMatMod1NMaterial WHERE jref = ?", false);
};

bool MyTblPlnrQMatMod1NMaterial::loadRecBySQL(
			const string& sqlstr
			, PlnrQMatMod1NMaterial** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrQMatMod1NMaterial* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQMatMod1NMaterial / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrQMatMod1NMaterial();

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

ubigint MyTblPlnrQMatMod1NMaterial::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQMatMod1NMaterial& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrQMatMod1NMaterial* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQMatMod1NMaterial / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrQMatMod1NMaterial();

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

void MyTblPlnrQMatMod1NMaterial::insertRec(
			PlnrQMatMod1NMaterial* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQMatMod1NMaterial / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQMatMod1NMaterial / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblPlnrQMatMod1NMaterial::insertRst(
			ListPlnrQMatMod1NMaterial& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblPlnrQMatMod1NMaterial::updateRec(
			PlnrQMatMod1NMaterial* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->qref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQMatMod1NMaterial / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQMatMod1NMaterial / stmtUpdateRec)\n");
};

void MyTblPlnrQMatMod1NMaterial::updateRst(
			ListPlnrQMatMod1NMaterial& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblPlnrQMatMod1NMaterial::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQMatMod1NMaterial / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQMatMod1NMaterial / stmtRemoveRecByQref)\n");
};

void MyTblPlnrQMatMod1NMaterial::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQMatMod1NMaterial / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQMatMod1NMaterial / stmtRemoveRstByJref)\n");
};

bool MyTblPlnrQMatMod1NMaterial::loadRecByQref(
			ubigint qref
			, PlnrQMatMod1NMaterial** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrQMatMod1NMaterial WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblPlnrQMatMod1NMaterial::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQMatMod1NMaterial& rst
		) {
	return loadRstBySQL("SELECT * FROM TblPlnrQMatMod1NMaterial WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrQMatMod1NMaterial
 ******************************************************************************/

PgTblPlnrQMatMod1NMaterial::PgTblPlnrQMatMod1NMaterial() : TblPlnrQMatMod1NMaterial(), PgTable() {
};

PgTblPlnrQMatMod1NMaterial::~PgTblPlnrQMatMod1NMaterial() {
};

void PgTblPlnrQMatMod1NMaterial::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrQMatMod1NMaterial_insertRec", "INSERT INTO TblPlnrQMatMod1NMaterial (jref, jnum, ref) VALUES ($1,$2,$3) RETURNING qref", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQMatMod1NMaterial_updateRec", "UPDATE TblPlnrQMatMod1NMaterial SET jref = $1, jnum = $2, ref = $3 WHERE qref = $4", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQMatMod1NMaterial_removeRecByQref", "DELETE FROM TblPlnrQMatMod1NMaterial WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQMatMod1NMaterial_removeRstByJref", "DELETE FROM TblPlnrQMatMod1NMaterial WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrQMatMod1NMaterial_loadRecByQref", "SELECT qref, jref, jnum, ref FROM TblPlnrQMatMod1NMaterial WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQMatMod1NMaterial_loadRstByJref", "SELECT qref, jref, jnum, ref FROM TblPlnrQMatMod1NMaterial WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrQMatMod1NMaterial::loadRec(
			PGresult* res
			, PlnrQMatMod1NMaterial** rec
		) {
	char* ptr;

	PlnrQMatMod1NMaterial* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrQMatMod1NMaterial();

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

ubigint PgTblPlnrQMatMod1NMaterial::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrQMatMod1NMaterial& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrQMatMod1NMaterial* rec;

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
			rec = new PlnrQMatMod1NMaterial();

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

bool PgTblPlnrQMatMod1NMaterial::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrQMatMod1NMaterial** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQMatMod1NMaterial / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQMatMod1NMaterial::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrQMatMod1NMaterial& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQMatMod1NMaterial / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblPlnrQMatMod1NMaterial::loadRecBySQL(
			const string& sqlstr
			, PlnrQMatMod1NMaterial** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQMatMod1NMaterial::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQMatMod1NMaterial& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrQMatMod1NMaterial::insertRec(
			PlnrQMatMod1NMaterial* rec
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

	res = PQexecPrepared(dbs, "TblPlnrQMatMod1NMaterial_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQMatMod1NMaterial_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblPlnrQMatMod1NMaterial::insertRst(
			ListPlnrQMatMod1NMaterial& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblPlnrQMatMod1NMaterial::updateRec(
			PlnrQMatMod1NMaterial* rec
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

	res = PQexecPrepared(dbs, "TblPlnrQMatMod1NMaterial_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQMatMod1NMaterial_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrQMatMod1NMaterial::updateRst(
			ListPlnrQMatMod1NMaterial& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblPlnrQMatMod1NMaterial::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblPlnrQMatMod1NMaterial_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQMatMod1NMaterial_removeRecByQref)\n");

	PQclear(res);
};

void PgTblPlnrQMatMod1NMaterial::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblPlnrQMatMod1NMaterial_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQMatMod1NMaterial_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblPlnrQMatMod1NMaterial::loadRecByQref(
			ubigint qref
			, PlnrQMatMod1NMaterial** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrQMatMod1NMaterial_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblPlnrQMatMod1NMaterial::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQMatMod1NMaterial& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrQMatMod1NMaterial_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

