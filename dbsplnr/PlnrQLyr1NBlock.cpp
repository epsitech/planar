/**
  * \file PlnrQLyr1NBlock.cpp
  * Dbs and XML wrapper for table TblPlnrQLyr1NBlock (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQLyr1NBlock.h"

/******************************************************************************
 class PlnrQLyr1NBlock
 ******************************************************************************/

PlnrQLyr1NBlock::PlnrQLyr1NBlock(
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

void PlnrQLyr1NBlock::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "PlnrQLyr1NBlock";

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
 class ListPlnrQLyr1NBlock
 ******************************************************************************/

ListPlnrQLyr1NBlock::ListPlnrQLyr1NBlock() {
};

ListPlnrQLyr1NBlock::ListPlnrQLyr1NBlock(
			const ListPlnrQLyr1NBlock& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQLyr1NBlock(*(src.nodes[i]));
};

ListPlnrQLyr1NBlock::~ListPlnrQLyr1NBlock() {
	clear();
};

void ListPlnrQLyr1NBlock::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrQLyr1NBlock::size() const {
	return(nodes.size());
};

void ListPlnrQLyr1NBlock::append(
			PlnrQLyr1NBlock* rec
		) {
	nodes.push_back(rec);
};

ListPlnrQLyr1NBlock& ListPlnrQLyr1NBlock::operator=(
			const ListPlnrQLyr1NBlock& src
		) {
	PlnrQLyr1NBlock* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrQLyr1NBlock(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListPlnrQLyr1NBlock::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListPlnrQLyr1NBlock";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblPlnrQLyr1NBlock
 ******************************************************************************/

TblPlnrQLyr1NBlock::TblPlnrQLyr1NBlock() {
};

TblPlnrQLyr1NBlock::~TblPlnrQLyr1NBlock() {
};

bool TblPlnrQLyr1NBlock::loadRecBySQL(
			const string& sqlstr
			, PlnrQLyr1NBlock** rec
		) {
	return false;
};

ubigint TblPlnrQLyr1NBlock::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQLyr1NBlock& rst
		) {
	return 0;
};

void TblPlnrQLyr1NBlock::insertRec(
			PlnrQLyr1NBlock* rec
		) {
};

ubigint TblPlnrQLyr1NBlock::insertNewRec(
			PlnrQLyr1NBlock** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	PlnrQLyr1NBlock* _rec = NULL;

	_rec = new PlnrQLyr1NBlock(0, jref, jnum, ref, stubRef);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrQLyr1NBlock::appendNewRecToRst(
			ListPlnrQLyr1NBlock& rst
			, PlnrQLyr1NBlock** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	PlnrQLyr1NBlock* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, stubRef);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrQLyr1NBlock::insertRst(
			ListPlnrQLyr1NBlock& rst
		) {
};

void TblPlnrQLyr1NBlock::updateRec(
			PlnrQLyr1NBlock* rec
		) {
};

void TblPlnrQLyr1NBlock::updateRst(
			ListPlnrQLyr1NBlock& rst
		) {
};

void TblPlnrQLyr1NBlock::removeRecByQref(
			ubigint qref
		) {
};

void TblPlnrQLyr1NBlock::removeRstByJref(
			ubigint jref
		) {
};

bool TblPlnrQLyr1NBlock::loadRecByQref(
			ubigint qref
			, PlnrQLyr1NBlock** rec
		) {
	return false;
};

ubigint TblPlnrQLyr1NBlock::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQLyr1NBlock& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrQLyr1NBlock
 ******************************************************************************/

MyTblPlnrQLyr1NBlock::MyTblPlnrQLyr1NBlock() : TblPlnrQLyr1NBlock(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblPlnrQLyr1NBlock::~MyTblPlnrQLyr1NBlock() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblPlnrQLyr1NBlock::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrQLyr1NBlock (jref, jnum, ref) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrQLyr1NBlock SET jref = ?, jnum = ?, ref = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblPlnrQLyr1NBlock WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblPlnrQLyr1NBlock WHERE jref = ?", false);
};

bool MyTblPlnrQLyr1NBlock::loadRecBySQL(
			const string& sqlstr
			, PlnrQLyr1NBlock** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrQLyr1NBlock* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQLyr1NBlock / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrQLyr1NBlock();

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

ubigint MyTblPlnrQLyr1NBlock::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQLyr1NBlock& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrQLyr1NBlock* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQLyr1NBlock / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrQLyr1NBlock();

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

void MyTblPlnrQLyr1NBlock::insertRec(
			PlnrQLyr1NBlock* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQLyr1NBlock / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQLyr1NBlock / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblPlnrQLyr1NBlock::insertRst(
			ListPlnrQLyr1NBlock& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblPlnrQLyr1NBlock::updateRec(
			PlnrQLyr1NBlock* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->qref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQLyr1NBlock / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQLyr1NBlock / stmtUpdateRec)\n");
};

void MyTblPlnrQLyr1NBlock::updateRst(
			ListPlnrQLyr1NBlock& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblPlnrQLyr1NBlock::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQLyr1NBlock / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQLyr1NBlock / stmtRemoveRecByQref)\n");
};

void MyTblPlnrQLyr1NBlock::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQLyr1NBlock / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQLyr1NBlock / stmtRemoveRstByJref)\n");
};

bool MyTblPlnrQLyr1NBlock::loadRecByQref(
			ubigint qref
			, PlnrQLyr1NBlock** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrQLyr1NBlock WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblPlnrQLyr1NBlock::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQLyr1NBlock& rst
		) {
	return loadRstBySQL("SELECT * FROM TblPlnrQLyr1NBlock WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrQLyr1NBlock
 ******************************************************************************/

PgTblPlnrQLyr1NBlock::PgTblPlnrQLyr1NBlock() : TblPlnrQLyr1NBlock(), PgTable() {
};

PgTblPlnrQLyr1NBlock::~PgTblPlnrQLyr1NBlock() {
};

void PgTblPlnrQLyr1NBlock::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrQLyr1NBlock_insertRec", "INSERT INTO TblPlnrQLyr1NBlock (jref, jnum, ref) VALUES ($1,$2,$3) RETURNING qref", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQLyr1NBlock_updateRec", "UPDATE TblPlnrQLyr1NBlock SET jref = $1, jnum = $2, ref = $3 WHERE qref = $4", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQLyr1NBlock_removeRecByQref", "DELETE FROM TblPlnrQLyr1NBlock WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQLyr1NBlock_removeRstByJref", "DELETE FROM TblPlnrQLyr1NBlock WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrQLyr1NBlock_loadRecByQref", "SELECT qref, jref, jnum, ref FROM TblPlnrQLyr1NBlock WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQLyr1NBlock_loadRstByJref", "SELECT qref, jref, jnum, ref FROM TblPlnrQLyr1NBlock WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrQLyr1NBlock::loadRec(
			PGresult* res
			, PlnrQLyr1NBlock** rec
		) {
	char* ptr;

	PlnrQLyr1NBlock* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrQLyr1NBlock();

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

ubigint PgTblPlnrQLyr1NBlock::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrQLyr1NBlock& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrQLyr1NBlock* rec;

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
			rec = new PlnrQLyr1NBlock();

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

bool PgTblPlnrQLyr1NBlock::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrQLyr1NBlock** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQLyr1NBlock / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQLyr1NBlock::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrQLyr1NBlock& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQLyr1NBlock / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblPlnrQLyr1NBlock::loadRecBySQL(
			const string& sqlstr
			, PlnrQLyr1NBlock** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQLyr1NBlock::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQLyr1NBlock& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrQLyr1NBlock::insertRec(
			PlnrQLyr1NBlock* rec
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

	res = PQexecPrepared(dbs, "TblPlnrQLyr1NBlock_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQLyr1NBlock_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblPlnrQLyr1NBlock::insertRst(
			ListPlnrQLyr1NBlock& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblPlnrQLyr1NBlock::updateRec(
			PlnrQLyr1NBlock* rec
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

	res = PQexecPrepared(dbs, "TblPlnrQLyr1NBlock_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQLyr1NBlock_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrQLyr1NBlock::updateRst(
			ListPlnrQLyr1NBlock& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblPlnrQLyr1NBlock::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblPlnrQLyr1NBlock_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQLyr1NBlock_removeRecByQref)\n");

	PQclear(res);
};

void PgTblPlnrQLyr1NBlock::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblPlnrQLyr1NBlock_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQLyr1NBlock_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblPlnrQLyr1NBlock::loadRecByQref(
			ubigint qref
			, PlnrQLyr1NBlock** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrQLyr1NBlock_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblPlnrQLyr1NBlock::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQLyr1NBlock& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrQLyr1NBlock_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

