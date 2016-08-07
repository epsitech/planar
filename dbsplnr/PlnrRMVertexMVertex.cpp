/**
  * \file PlnrRMVertexMVertex.cpp
  * database access for table TblPlnrRMVertexMVertex (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrRMVertexMVertex.h"

/******************************************************************************
 class PlnrRMVertexMVertex
 ******************************************************************************/

PlnrRMVertexMVertex::PlnrRMVertexMVertex(
			const ubigint ref
			, const ubigint devRefPlnrMVertex
			, const ubigint dsnRefPlnrMVertex
		) {

	this->ref = ref;
	this->devRefPlnrMVertex = devRefPlnrMVertex;
	this->dsnRefPlnrMVertex = dsnRefPlnrMVertex;
};

bool PlnrRMVertexMVertex::operator==(
			const PlnrRMVertexMVertex& comp
		) {
	return false;
};

bool PlnrRMVertexMVertex::operator!=(
			const PlnrRMVertexMVertex& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListPlnrRMVertexMVertex
 ******************************************************************************/

ListPlnrRMVertexMVertex::ListPlnrRMVertexMVertex() {
};

ListPlnrRMVertexMVertex::ListPlnrRMVertexMVertex(
			const ListPlnrRMVertexMVertex& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrRMVertexMVertex(*(src.nodes[i]));
};

ListPlnrRMVertexMVertex::~ListPlnrRMVertexMVertex() {
	clear();
};

void ListPlnrRMVertexMVertex::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrRMVertexMVertex::size() const {
	return(nodes.size());
};

void ListPlnrRMVertexMVertex::append(
			PlnrRMVertexMVertex* rec
		) {
	nodes.push_back(rec);
};

PlnrRMVertexMVertex* ListPlnrRMVertexMVertex::operator[](
			const uint ix
		) {
	PlnrRMVertexMVertex* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListPlnrRMVertexMVertex& ListPlnrRMVertexMVertex::operator=(
			const ListPlnrRMVertexMVertex& src
		) {
	PlnrRMVertexMVertex* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrRMVertexMVertex(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListPlnrRMVertexMVertex::operator==(
			const ListPlnrRMVertexMVertex& comp
		) {
	bool retval;

	retval = (size() == comp.size());

	if (retval) {
		for (unsigned int i=0;i<size();i++) {
			retval = ( *(nodes[i]) == *(comp.nodes[i]) );

			if (!retval) break;
		};
	};

	return retval;
};

bool ListPlnrRMVertexMVertex::operator!=(
			const ListPlnrRMVertexMVertex& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblPlnrRMVertexMVertex
 ******************************************************************************/

TblPlnrRMVertexMVertex::TblPlnrRMVertexMVertex() {
};

TblPlnrRMVertexMVertex::~TblPlnrRMVertexMVertex() {
};

bool TblPlnrRMVertexMVertex::loadRecBySQL(
			const string& sqlstr
			, PlnrRMVertexMVertex** rec
		) {
	return false;
};

ubigint TblPlnrRMVertexMVertex::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrRMVertexMVertex& rst
		) {
	return 0;
};

void TblPlnrRMVertexMVertex::insertRec(
			PlnrRMVertexMVertex* rec
		) {
};

ubigint TblPlnrRMVertexMVertex::insertNewRec(
			PlnrRMVertexMVertex** rec
			, const ubigint devRefPlnrMVertex
			, const ubigint dsnRefPlnrMVertex
		) {
	ubigint retval = 0;
	PlnrRMVertexMVertex* _rec = NULL;

	_rec = new PlnrRMVertexMVertex(0, devRefPlnrMVertex, dsnRefPlnrMVertex);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrRMVertexMVertex::appendNewRecToRst(
			ListPlnrRMVertexMVertex& rst
			, PlnrRMVertexMVertex** rec
			, const ubigint devRefPlnrMVertex
			, const ubigint dsnRefPlnrMVertex
		) {
	ubigint retval = 0;
	PlnrRMVertexMVertex* _rec = NULL;

	retval = insertNewRec(&_rec, devRefPlnrMVertex, dsnRefPlnrMVertex);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrRMVertexMVertex::insertRst(
			ListPlnrRMVertexMVertex& rst
			, bool transact
		) {
};

void TblPlnrRMVertexMVertex::updateRec(
			PlnrRMVertexMVertex* rec
		) {
};

void TblPlnrRMVertexMVertex::updateRst(
			ListPlnrRMVertexMVertex& rst
			, bool transact
		) {
};

void TblPlnrRMVertexMVertex::removeRecByRef(
			ubigint ref
		) {
};

bool TblPlnrRMVertexMVertex::loadRecByRef(
			ubigint ref
			, PlnrRMVertexMVertex** rec
		) {
	return false;
};

ubigint TblPlnrRMVertexMVertex::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListPlnrRMVertexMVertex& rst
		) {
	ubigint numload = 0;
	PlnrRMVertexMVertex* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrRMVertexMVertex
 ******************************************************************************/

MyTblPlnrRMVertexMVertex::MyTblPlnrRMVertexMVertex() : TblPlnrRMVertexMVertex(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblPlnrRMVertexMVertex::~MyTblPlnrRMVertexMVertex() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblPlnrRMVertexMVertex::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrRMVertexMVertex (devRefPlnrMVertex, dsnRefPlnrMVertex) VALUES (?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrRMVertexMVertex SET devRefPlnrMVertex = ?, dsnRefPlnrMVertex = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblPlnrRMVertexMVertex WHERE ref = ?", false);
};

bool MyTblPlnrRMVertexMVertex::loadRecBySQL(
			const string& sqlstr
			, PlnrRMVertexMVertex** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrRMVertexMVertex* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrRMVertexMVertex / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrRMVertexMVertex();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->devRefPlnrMVertex = atoll((char*) dbrow[1]); else _rec->devRefPlnrMVertex = 0;
		if (dbrow[2]) _rec->dsnRefPlnrMVertex = atoll((char*) dbrow[2]); else _rec->dsnRefPlnrMVertex = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrRMVertexMVertex::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrRMVertexMVertex& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrRMVertexMVertex* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrRMVertexMVertex / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrRMVertexMVertex();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->devRefPlnrMVertex = atoll((char*) dbrow[1]); else rec->devRefPlnrMVertex = 0;
			if (dbrow[2]) rec->dsnRefPlnrMVertex = atoll((char*) dbrow[2]); else rec->dsnRefPlnrMVertex = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrRMVertexMVertex::insertRec(
			PlnrRMVertexMVertex* rec
		) {
	unsigned long l[2]; my_bool n[2]; my_bool e[2];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->devRefPlnrMVertex,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->dsnRefPlnrMVertex,&(l[1]),&(n[1]),&(e[1]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrRMVertexMVertex / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrRMVertexMVertex / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblPlnrRMVertexMVertex::insertRst(
			ListPlnrRMVertexMVertex& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblPlnrRMVertexMVertex::updateRec(
			PlnrRMVertexMVertex* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->devRefPlnrMVertex,&(l[0]),&(n[0]),&(e[0])), 
		bindUbigint(&rec->dsnRefPlnrMVertex,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrRMVertexMVertex / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrRMVertexMVertex / stmtUpdateRec)\n");
};

void MyTblPlnrRMVertexMVertex::updateRst(
			ListPlnrRMVertexMVertex& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblPlnrRMVertexMVertex::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrRMVertexMVertex / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrRMVertexMVertex / stmtRemoveRecByRef)\n");
};

bool MyTblPlnrRMVertexMVertex::loadRecByRef(
			ubigint ref
			, PlnrRMVertexMVertex** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrRMVertexMVertex WHERE ref = " + to_string(ref), rec);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrRMVertexMVertex
 ******************************************************************************/

PgTblPlnrRMVertexMVertex::PgTblPlnrRMVertexMVertex() : TblPlnrRMVertexMVertex(), PgTable() {
};

PgTblPlnrRMVertexMVertex::~PgTblPlnrRMVertexMVertex() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblPlnrRMVertexMVertex::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrRMVertexMVertex_insertRec", "INSERT INTO TblPlnrRMVertexMVertex (devRefPlnrMVertex, dsnRefPlnrMVertex) VALUES ($1,$2) RETURNING ref", 2, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrRMVertexMVertex_updateRec", "UPDATE TblPlnrRMVertexMVertex SET devRefPlnrMVertex = $1, dsnRefPlnrMVertex = $2 WHERE ref = $3", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrRMVertexMVertex_removeRecByRef", "DELETE FROM TblPlnrRMVertexMVertex WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrRMVertexMVertex_loadRecByRef", "SELECT ref, devRefPlnrMVertex, dsnRefPlnrMVertex FROM TblPlnrRMVertexMVertex WHERE ref = $1", 1, NULL);
};

bool PgTblPlnrRMVertexMVertex::loadRec(
			PGresult* res
			, PlnrRMVertexMVertex** rec
		) {
	char* ptr;

	PlnrRMVertexMVertex* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrRMVertexMVertex();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "devrefplnrmvertex"),
			PQfnumber(res, "dsnrefplnrmvertex")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->devRefPlnrMVertex = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->dsnRefPlnrMVertex = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrRMVertexMVertex::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrRMVertexMVertex& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrRMVertexMVertex* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "devrefplnrmvertex"),
			PQfnumber(res, "dsnrefplnrmvertex")
		};

		while (numread < numrow) {
			rec = new PlnrRMVertexMVertex();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->devRefPlnrMVertex = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->dsnRefPlnrMVertex = atoll(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrRMVertexMVertex::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrRMVertexMVertex** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrRMVertexMVertex / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

bool PgTblPlnrRMVertexMVertex::loadRecBySQL(
			const string& sqlstr
			, PlnrRMVertexMVertex** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrRMVertexMVertex::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrRMVertexMVertex& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrRMVertexMVertex::insertRec(
			PlnrRMVertexMVertex* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _devRefPlnrMVertex = htonl64(rec->devRefPlnrMVertex);
	ubigint _dsnRefPlnrMVertex = htonl64(rec->dsnRefPlnrMVertex);

	const char* vals[] = {
		(char*) &_devRefPlnrMVertex,
		(char*) &_dsnRefPlnrMVertex
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1};

	res = PQexecPrepared(dbs, "TblPlnrRMVertexMVertex_insertRec", 2, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrRMVertexMVertex_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblPlnrRMVertexMVertex::insertRst(
			ListPlnrRMVertexMVertex& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblPlnrRMVertexMVertex::updateRec(
			PlnrRMVertexMVertex* rec
		) {
	PGresult* res;

	ubigint _devRefPlnrMVertex = htonl64(rec->devRefPlnrMVertex);
	ubigint _dsnRefPlnrMVertex = htonl64(rec->dsnRefPlnrMVertex);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_devRefPlnrMVertex,
		(char*) &_dsnRefPlnrMVertex,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1};

	res = PQexecPrepared(dbs, "TblPlnrRMVertexMVertex_updateRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrRMVertexMVertex_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrRMVertexMVertex::updateRst(
			ListPlnrRMVertexMVertex& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblPlnrRMVertexMVertex::removeRecByRef(
			ubigint ref
		) {
	PGresult* res;

	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	res = PQexecPrepared(dbs, "TblPlnrRMVertexMVertex_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrRMVertexMVertex_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblPlnrRMVertexMVertex::loadRecByRef(
			ubigint ref
			, PlnrRMVertexMVertex** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrRMVertexMVertex_loadRecByRef", 1, vals, l, f, rec);
};

// IP pgTbl --- END

