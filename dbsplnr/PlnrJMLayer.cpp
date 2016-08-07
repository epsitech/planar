/**
  * \file PlnrJMLayer.cpp
  * database access for table TblPlnrJMLayer (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrJMLayer.h"

/******************************************************************************
 class PlnrJMLayer
 ******************************************************************************/

PlnrJMLayer::PlnrJMLayer(
			const ubigint ref
			, const ubigint refPlnrMLayer
			, const ubigint x1RefPlnrMDesign
			, const string t
			, const string ML
		) {

	this->ref = ref;
	this->refPlnrMLayer = refPlnrMLayer;
	this->x1RefPlnrMDesign = x1RefPlnrMDesign;
	this->t = t;
	this->ML = ML;
};

bool PlnrJMLayer::operator==(
			const PlnrJMLayer& comp
		) {
	return false;
};

bool PlnrJMLayer::operator!=(
			const PlnrJMLayer& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListPlnrJMLayer
 ******************************************************************************/

ListPlnrJMLayer::ListPlnrJMLayer() {
};

ListPlnrJMLayer::ListPlnrJMLayer(
			const ListPlnrJMLayer& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrJMLayer(*(src.nodes[i]));
};

ListPlnrJMLayer::~ListPlnrJMLayer() {
	clear();
};

void ListPlnrJMLayer::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrJMLayer::size() const {
	return(nodes.size());
};

void ListPlnrJMLayer::append(
			PlnrJMLayer* rec
		) {
	nodes.push_back(rec);
};

PlnrJMLayer* ListPlnrJMLayer::operator[](
			const uint ix
		) {
	PlnrJMLayer* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListPlnrJMLayer& ListPlnrJMLayer::operator=(
			const ListPlnrJMLayer& src
		) {
	PlnrJMLayer* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrJMLayer(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListPlnrJMLayer::operator==(
			const ListPlnrJMLayer& comp
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

bool ListPlnrJMLayer::operator!=(
			const ListPlnrJMLayer& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblPlnrJMLayer
 ******************************************************************************/

TblPlnrJMLayer::TblPlnrJMLayer() {
};

TblPlnrJMLayer::~TblPlnrJMLayer() {
};

bool TblPlnrJMLayer::loadRecBySQL(
			const string& sqlstr
			, PlnrJMLayer** rec
		) {
	return false;
};

ubigint TblPlnrJMLayer::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrJMLayer& rst
		) {
	return 0;
};

void TblPlnrJMLayer::insertRec(
			PlnrJMLayer* rec
		) {
};

ubigint TblPlnrJMLayer::insertNewRec(
			PlnrJMLayer** rec
			, const ubigint refPlnrMLayer
			, const ubigint x1RefPlnrMDesign
			, const string t
			, const string ML
		) {
	ubigint retval = 0;
	PlnrJMLayer* _rec = NULL;

	_rec = new PlnrJMLayer(0, refPlnrMLayer, x1RefPlnrMDesign, t, ML);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrJMLayer::appendNewRecToRst(
			ListPlnrJMLayer& rst
			, PlnrJMLayer** rec
			, const ubigint refPlnrMLayer
			, const ubigint x1RefPlnrMDesign
			, const string t
			, const string ML
		) {
	ubigint retval = 0;
	PlnrJMLayer* _rec = NULL;

	retval = insertNewRec(&_rec, refPlnrMLayer, x1RefPlnrMDesign, t, ML);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrJMLayer::insertRst(
			ListPlnrJMLayer& rst
			, bool transact
		) {
};

void TblPlnrJMLayer::updateRec(
			PlnrJMLayer* rec
		) {
};

void TblPlnrJMLayer::updateRst(
			ListPlnrJMLayer& rst
			, bool transact
		) {
};

void TblPlnrJMLayer::removeRecByRef(
			ubigint ref
		) {
};

bool TblPlnrJMLayer::loadRecByRef(
			ubigint ref
			, PlnrJMLayer** rec
		) {
	return false;
};

bool TblPlnrJMLayer::loadRecByLyrDsn(
			ubigint refPlnrMLayer
			, ubigint x1RefPlnrMDesign
			, PlnrJMLayer** rec
		) {
	return false;
};

ubigint TblPlnrJMLayer::loadRstByLyr(
			ubigint refPlnrMLayer
			, const bool append
			, ListPlnrJMLayer& rst
		) {
	return 0;
};

ubigint TblPlnrJMLayer::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListPlnrJMLayer& rst
		) {
	ubigint numload = 0;
	PlnrJMLayer* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrJMLayer
 ******************************************************************************/

MyTblPlnrJMLayer::MyTblPlnrJMLayer() : TblPlnrJMLayer(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblPlnrJMLayer::~MyTblPlnrJMLayer() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblPlnrJMLayer::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrJMLayer (refPlnrMLayer, x1RefPlnrMDesign, t, ML) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrJMLayer SET refPlnrMLayer = ?, x1RefPlnrMDesign = ?, t = ?, ML = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblPlnrJMLayer WHERE ref = ?", false);
};

bool MyTblPlnrJMLayer::loadRecBySQL(
			const string& sqlstr
			, PlnrJMLayer** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrJMLayer* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrJMLayer / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrJMLayer();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refPlnrMLayer = atoll((char*) dbrow[1]); else _rec->refPlnrMLayer = 0;
		if (dbrow[2]) _rec->x1RefPlnrMDesign = atoll((char*) dbrow[2]); else _rec->x1RefPlnrMDesign = 0;
		if (dbrow[3]) _rec->t.assign(dbrow[3], dblengths[3]); else _rec->t = "";
		if (dbrow[4]) _rec->ML.assign(dbrow[4], dblengths[4]); else _rec->ML = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrJMLayer::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrJMLayer& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrJMLayer* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrJMLayer / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrJMLayer();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refPlnrMLayer = atoll((char*) dbrow[1]); else rec->refPlnrMLayer = 0;
			if (dbrow[2]) rec->x1RefPlnrMDesign = atoll((char*) dbrow[2]); else rec->x1RefPlnrMDesign = 0;
			if (dbrow[3]) rec->t.assign(dbrow[3], dblengths[3]); else rec->t = "";
			if (dbrow[4]) rec->ML.assign(dbrow[4], dblengths[4]); else rec->ML = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrJMLayer::insertRec(
			PlnrJMLayer* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[2] = rec->t.length();
	l[3] = rec->ML.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refPlnrMLayer,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->x1RefPlnrMDesign,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->t.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->ML.c_str()),&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrJMLayer / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrJMLayer / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblPlnrJMLayer::insertRst(
			ListPlnrJMLayer& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblPlnrJMLayer::updateRec(
			PlnrJMLayer* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[2] = rec->t.length();
	l[3] = rec->ML.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refPlnrMLayer,&(l[0]),&(n[0]),&(e[0])), 
		bindUbigint(&rec->x1RefPlnrMDesign,&(l[1]),&(n[1]),&(e[1])), 
		bindCstring((char*) (rec->t.c_str()),&(l[2]),&(n[2]),&(e[2])), 
		bindCstring((char*) (rec->ML.c_str()),&(l[3]),&(n[3]),&(e[3])), 
		bindUbigint(&rec->ref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrJMLayer / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrJMLayer / stmtUpdateRec)\n");
};

void MyTblPlnrJMLayer::updateRst(
			ListPlnrJMLayer& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblPlnrJMLayer::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrJMLayer / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrJMLayer / stmtRemoveRecByRef)\n");
};

bool MyTblPlnrJMLayer::loadRecByRef(
			ubigint ref
			, PlnrJMLayer** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrJMLayer WHERE ref = " + to_string(ref), rec);
};

bool MyTblPlnrJMLayer::loadRecByLyrDsn(
			ubigint refPlnrMLayer
			, ubigint x1RefPlnrMDesign
			, PlnrJMLayer** rec
		) {
	return loadRecBySQL("SELECT ref, refPlnrMLayer, x1RefPlnrMDesign, t, ML FROM TblPlnrJMLayer WHERE refPlnrMLayer = " + to_string(refPlnrMLayer) + " AND x1RefPlnrMDesign = " + to_string(x1RefPlnrMDesign) + "", rec);
};

ubigint MyTblPlnrJMLayer::loadRstByLyr(
			ubigint refPlnrMLayer
			, const bool append
			, ListPlnrJMLayer& rst
		) {
	return loadRstBySQL("SELECT ref, refPlnrMLayer, x1RefPlnrMDesign, t, ML FROM TblPlnrJMLayer WHERE refPlnrMLayer = " + to_string(refPlnrMLayer) + " ORDER BY x1RefPlnrMDesign ASC", append, rst);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrJMLayer
 ******************************************************************************/

PgTblPlnrJMLayer::PgTblPlnrJMLayer() : TblPlnrJMLayer(), PgTable() {
};

PgTblPlnrJMLayer::~PgTblPlnrJMLayer() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblPlnrJMLayer::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrJMLayer_insertRec", "INSERT INTO TblPlnrJMLayer (refPlnrMLayer, x1RefPlnrMDesign, t, ML) VALUES ($1,$2,$3,$4) RETURNING ref", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrJMLayer_updateRec", "UPDATE TblPlnrJMLayer SET refPlnrMLayer = $1, x1RefPlnrMDesign = $2, t = $3, ML = $4 WHERE ref = $5", 5, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrJMLayer_removeRecByRef", "DELETE FROM TblPlnrJMLayer WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrJMLayer_loadRecByRef", "SELECT ref, refPlnrMLayer, x1RefPlnrMDesign, t, ML FROM TblPlnrJMLayer WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblPlnrJMLayer_loadRecByLyrDsn", "SELECT ref, refPlnrMLayer, x1RefPlnrMDesign, t, ML FROM TblPlnrJMLayer WHERE refPlnrMLayer = $1 AND x1RefPlnrMDesign = $2", 2, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrJMLayer_loadRstByLyr", "SELECT ref, refPlnrMLayer, x1RefPlnrMDesign, t, ML FROM TblPlnrJMLayer WHERE refPlnrMLayer = $1 ORDER BY x1RefPlnrMDesign ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrJMLayer::loadRec(
			PGresult* res
			, PlnrJMLayer** rec
		) {
	char* ptr;

	PlnrJMLayer* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrJMLayer();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refplnrmlayer"),
			PQfnumber(res, "x1refplnrmdesign"),
			PQfnumber(res, "t"),
			PQfnumber(res, "ml")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refPlnrMLayer = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1RefPlnrMDesign = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->t.assign(ptr, PQgetlength(res, 0, fnum[3]));
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->ML.assign(ptr, PQgetlength(res, 0, fnum[4]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrJMLayer::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrJMLayer& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrJMLayer* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refplnrmlayer"),
			PQfnumber(res, "x1refplnrmdesign"),
			PQfnumber(res, "t"),
			PQfnumber(res, "ml")
		};

		while (numread < numrow) {
			rec = new PlnrJMLayer();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refPlnrMLayer = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1RefPlnrMDesign = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->t.assign(ptr, PQgetlength(res, numread, fnum[3]));
			ptr = PQgetvalue(res, numread, fnum[4]); rec->ML.assign(ptr, PQgetlength(res, numread, fnum[4]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrJMLayer::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrJMLayer** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrJMLayer / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

// IP pgLoadRstByStmt --- BEGIN
ubigint PgTblPlnrJMLayer::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrJMLayer& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrJMLayer / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};
// IP pgLoadRstByStmt --- END

bool PgTblPlnrJMLayer::loadRecBySQL(
			const string& sqlstr
			, PlnrJMLayer** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrJMLayer::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrJMLayer& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrJMLayer::insertRec(
			PlnrJMLayer* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refPlnrMLayer = htonl64(rec->refPlnrMLayer);
	ubigint _x1RefPlnrMDesign = htonl64(rec->x1RefPlnrMDesign);

	const char* vals[] = {
		(char*) &_refPlnrMLayer,
		(char*) &_x1RefPlnrMDesign,
		rec->t.c_str(),
		rec->ML.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0
	};
	const int f[] = {1, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblPlnrJMLayer_insertRec", 4, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrJMLayer_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblPlnrJMLayer::insertRst(
			ListPlnrJMLayer& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblPlnrJMLayer::updateRec(
			PlnrJMLayer* rec
		) {
	PGresult* res;

	ubigint _refPlnrMLayer = htonl64(rec->refPlnrMLayer);
	ubigint _x1RefPlnrMDesign = htonl64(rec->x1RefPlnrMDesign);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refPlnrMLayer,
		(char*) &_x1RefPlnrMDesign,
		rec->t.c_str(),
		rec->ML.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblPlnrJMLayer_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrJMLayer_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrJMLayer::updateRst(
			ListPlnrJMLayer& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblPlnrJMLayer::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblPlnrJMLayer_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrJMLayer_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblPlnrJMLayer::loadRecByRef(
			ubigint ref
			, PlnrJMLayer** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrJMLayer_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblPlnrJMLayer::loadRecByLyrDsn(
			ubigint refPlnrMLayer
			, ubigint x1RefPlnrMDesign
			, PlnrJMLayer** rec
		) {
	ubigint _refPlnrMLayer = htonl64(refPlnrMLayer);
	ubigint _x1RefPlnrMDesign = htonl64(x1RefPlnrMDesign);

	const char* vals[] = {
		(char*) &_refPlnrMLayer,
		(char*) &_x1RefPlnrMDesign
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1,1};

	return loadRecByStmt("TblPlnrJMLayer_loadRecByLyrDsn", 2, vals, l, f, rec);
};

ubigint PgTblPlnrJMLayer::loadRstByLyr(
			ubigint refPlnrMLayer
			, const bool append
			, ListPlnrJMLayer& rst
		) {
	ubigint _refPlnrMLayer = htonl64(refPlnrMLayer);

	const char* vals[] = {
		(char*) &_refPlnrMLayer
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrJMLayer_loadRstByLyr", 1, vals, l, f, append, rst);
};

// IP pgTbl --- END

