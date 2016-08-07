/**
  * \file PlnrQMat1NLayer.cpp
  * Dbs and XML wrapper for table TblPlnrQMat1NLayer (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQMat1NLayer.h"

/******************************************************************************
 class PlnrQMat1NLayer
 ******************************************************************************/

PlnrQMat1NLayer::PlnrQMat1NLayer(
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

void PlnrQMat1NLayer::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "PlnrQMat1NLayer";

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
 class ListPlnrQMat1NLayer
 ******************************************************************************/

ListPlnrQMat1NLayer::ListPlnrQMat1NLayer() {
};

ListPlnrQMat1NLayer::ListPlnrQMat1NLayer(
			const ListPlnrQMat1NLayer& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQMat1NLayer(*(src.nodes[i]));
};

ListPlnrQMat1NLayer::~ListPlnrQMat1NLayer() {
	clear();
};

void ListPlnrQMat1NLayer::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrQMat1NLayer::size() const {
	return(nodes.size());
};

void ListPlnrQMat1NLayer::append(
			PlnrQMat1NLayer* rec
		) {
	nodes.push_back(rec);
};

ListPlnrQMat1NLayer& ListPlnrQMat1NLayer::operator=(
			const ListPlnrQMat1NLayer& src
		) {
	PlnrQMat1NLayer* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrQMat1NLayer(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListPlnrQMat1NLayer::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListPlnrQMat1NLayer";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblPlnrQMat1NLayer
 ******************************************************************************/

TblPlnrQMat1NLayer::TblPlnrQMat1NLayer() {
};

TblPlnrQMat1NLayer::~TblPlnrQMat1NLayer() {
};

bool TblPlnrQMat1NLayer::loadRecBySQL(
			const string& sqlstr
			, PlnrQMat1NLayer** rec
		) {
	return false;
};

ubigint TblPlnrQMat1NLayer::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQMat1NLayer& rst
		) {
	return 0;
};

void TblPlnrQMat1NLayer::insertRec(
			PlnrQMat1NLayer* rec
		) {
};

ubigint TblPlnrQMat1NLayer::insertNewRec(
			PlnrQMat1NLayer** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	PlnrQMat1NLayer* _rec = NULL;

	_rec = new PlnrQMat1NLayer(0, jref, jnum, ref, stubRef);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrQMat1NLayer::appendNewRecToRst(
			ListPlnrQMat1NLayer& rst
			, PlnrQMat1NLayer** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	PlnrQMat1NLayer* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, stubRef);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrQMat1NLayer::insertRst(
			ListPlnrQMat1NLayer& rst
		) {
};

void TblPlnrQMat1NLayer::updateRec(
			PlnrQMat1NLayer* rec
		) {
};

void TblPlnrQMat1NLayer::updateRst(
			ListPlnrQMat1NLayer& rst
		) {
};

void TblPlnrQMat1NLayer::removeRecByQref(
			ubigint qref
		) {
};

void TblPlnrQMat1NLayer::removeRstByJref(
			ubigint jref
		) {
};

bool TblPlnrQMat1NLayer::loadRecByQref(
			ubigint qref
			, PlnrQMat1NLayer** rec
		) {
	return false;
};

ubigint TblPlnrQMat1NLayer::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQMat1NLayer& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrQMat1NLayer
 ******************************************************************************/

MyTblPlnrQMat1NLayer::MyTblPlnrQMat1NLayer() : TblPlnrQMat1NLayer(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblPlnrQMat1NLayer::~MyTblPlnrQMat1NLayer() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblPlnrQMat1NLayer::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrQMat1NLayer (jref, jnum, ref) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrQMat1NLayer SET jref = ?, jnum = ?, ref = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblPlnrQMat1NLayer WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblPlnrQMat1NLayer WHERE jref = ?", false);
};

bool MyTblPlnrQMat1NLayer::loadRecBySQL(
			const string& sqlstr
			, PlnrQMat1NLayer** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrQMat1NLayer* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQMat1NLayer / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrQMat1NLayer();

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

ubigint MyTblPlnrQMat1NLayer::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQMat1NLayer& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrQMat1NLayer* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQMat1NLayer / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrQMat1NLayer();

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

void MyTblPlnrQMat1NLayer::insertRec(
			PlnrQMat1NLayer* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQMat1NLayer / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQMat1NLayer / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblPlnrQMat1NLayer::insertRst(
			ListPlnrQMat1NLayer& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblPlnrQMat1NLayer::updateRec(
			PlnrQMat1NLayer* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->qref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQMat1NLayer / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQMat1NLayer / stmtUpdateRec)\n");
};

void MyTblPlnrQMat1NLayer::updateRst(
			ListPlnrQMat1NLayer& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblPlnrQMat1NLayer::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQMat1NLayer / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQMat1NLayer / stmtRemoveRecByQref)\n");
};

void MyTblPlnrQMat1NLayer::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQMat1NLayer / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQMat1NLayer / stmtRemoveRstByJref)\n");
};

bool MyTblPlnrQMat1NLayer::loadRecByQref(
			ubigint qref
			, PlnrQMat1NLayer** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrQMat1NLayer WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblPlnrQMat1NLayer::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQMat1NLayer& rst
		) {
	return loadRstBySQL("SELECT * FROM TblPlnrQMat1NLayer WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrQMat1NLayer
 ******************************************************************************/

PgTblPlnrQMat1NLayer::PgTblPlnrQMat1NLayer() : TblPlnrQMat1NLayer(), PgTable() {
};

PgTblPlnrQMat1NLayer::~PgTblPlnrQMat1NLayer() {
};

void PgTblPlnrQMat1NLayer::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrQMat1NLayer_insertRec", "INSERT INTO TblPlnrQMat1NLayer (jref, jnum, ref) VALUES ($1,$2,$3) RETURNING qref", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQMat1NLayer_updateRec", "UPDATE TblPlnrQMat1NLayer SET jref = $1, jnum = $2, ref = $3 WHERE qref = $4", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQMat1NLayer_removeRecByQref", "DELETE FROM TblPlnrQMat1NLayer WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQMat1NLayer_removeRstByJref", "DELETE FROM TblPlnrQMat1NLayer WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrQMat1NLayer_loadRecByQref", "SELECT qref, jref, jnum, ref FROM TblPlnrQMat1NLayer WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQMat1NLayer_loadRstByJref", "SELECT qref, jref, jnum, ref FROM TblPlnrQMat1NLayer WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrQMat1NLayer::loadRec(
			PGresult* res
			, PlnrQMat1NLayer** rec
		) {
	char* ptr;

	PlnrQMat1NLayer* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrQMat1NLayer();

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

ubigint PgTblPlnrQMat1NLayer::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrQMat1NLayer& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrQMat1NLayer* rec;

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
			rec = new PlnrQMat1NLayer();

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

bool PgTblPlnrQMat1NLayer::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrQMat1NLayer** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQMat1NLayer / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQMat1NLayer::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrQMat1NLayer& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQMat1NLayer / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblPlnrQMat1NLayer::loadRecBySQL(
			const string& sqlstr
			, PlnrQMat1NLayer** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQMat1NLayer::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQMat1NLayer& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrQMat1NLayer::insertRec(
			PlnrQMat1NLayer* rec
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

	res = PQexecPrepared(dbs, "TblPlnrQMat1NLayer_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQMat1NLayer_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblPlnrQMat1NLayer::insertRst(
			ListPlnrQMat1NLayer& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblPlnrQMat1NLayer::updateRec(
			PlnrQMat1NLayer* rec
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

	res = PQexecPrepared(dbs, "TblPlnrQMat1NLayer_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQMat1NLayer_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrQMat1NLayer::updateRst(
			ListPlnrQMat1NLayer& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblPlnrQMat1NLayer::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblPlnrQMat1NLayer_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQMat1NLayer_removeRecByQref)\n");

	PQclear(res);
};

void PgTblPlnrQMat1NLayer::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblPlnrQMat1NLayer_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQMat1NLayer_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblPlnrQMat1NLayer::loadRecByQref(
			ubigint qref
			, PlnrQMat1NLayer** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrQMat1NLayer_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblPlnrQMat1NLayer::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQMat1NLayer& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrQMat1NLayer_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

