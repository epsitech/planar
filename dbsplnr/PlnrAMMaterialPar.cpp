/**
  * \file PlnrAMMaterialPar.cpp
  * database access for table TblPlnrAMMaterialPar (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrAMMaterialPar.h"

/******************************************************************************
 class PlnrAMMaterialPar
 ******************************************************************************/

PlnrAMMaterialPar::PlnrAMMaterialPar(
			const ubigint ref
			, const ubigint refPlnrMMaterial
			, const ubigint x1RefPlnrMDesign
			, const string x2SrefKCat
			, const string x3SrefKProp
			, const ubigint refPlnrMFile
			, const string Val
			, const string Comment
		) {

	this->ref = ref;
	this->refPlnrMMaterial = refPlnrMMaterial;
	this->x1RefPlnrMDesign = x1RefPlnrMDesign;
	this->x2SrefKCat = x2SrefKCat;
	this->x3SrefKProp = x3SrefKProp;
	this->refPlnrMFile = refPlnrMFile;
	this->Val = Val;
	this->Comment = Comment;
};

bool PlnrAMMaterialPar::operator==(
			const PlnrAMMaterialPar& comp
		) {
	return false;
};

bool PlnrAMMaterialPar::operator!=(
			const PlnrAMMaterialPar& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListPlnrAMMaterialPar
 ******************************************************************************/

ListPlnrAMMaterialPar::ListPlnrAMMaterialPar() {
};

ListPlnrAMMaterialPar::ListPlnrAMMaterialPar(
			const ListPlnrAMMaterialPar& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrAMMaterialPar(*(src.nodes[i]));
};

ListPlnrAMMaterialPar::~ListPlnrAMMaterialPar() {
	clear();
};

void ListPlnrAMMaterialPar::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrAMMaterialPar::size() const {
	return(nodes.size());
};

void ListPlnrAMMaterialPar::append(
			PlnrAMMaterialPar* rec
		) {
	nodes.push_back(rec);
};

PlnrAMMaterialPar* ListPlnrAMMaterialPar::operator[](
			const uint ix
		) {
	PlnrAMMaterialPar* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListPlnrAMMaterialPar& ListPlnrAMMaterialPar::operator=(
			const ListPlnrAMMaterialPar& src
		) {
	PlnrAMMaterialPar* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrAMMaterialPar(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListPlnrAMMaterialPar::operator==(
			const ListPlnrAMMaterialPar& comp
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

bool ListPlnrAMMaterialPar::operator!=(
			const ListPlnrAMMaterialPar& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblPlnrAMMaterialPar
 ******************************************************************************/

TblPlnrAMMaterialPar::TblPlnrAMMaterialPar() {
};

TblPlnrAMMaterialPar::~TblPlnrAMMaterialPar() {
};

bool TblPlnrAMMaterialPar::loadRecBySQL(
			const string& sqlstr
			, PlnrAMMaterialPar** rec
		) {
	return false;
};

ubigint TblPlnrAMMaterialPar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrAMMaterialPar& rst
		) {
	return 0;
};

void TblPlnrAMMaterialPar::insertRec(
			PlnrAMMaterialPar* rec
		) {
};

ubigint TblPlnrAMMaterialPar::insertNewRec(
			PlnrAMMaterialPar** rec
			, const ubigint refPlnrMMaterial
			, const ubigint x1RefPlnrMDesign
			, const string x2SrefKCat
			, const string x3SrefKProp
			, const ubigint refPlnrMFile
			, const string Val
			, const string Comment
		) {
	ubigint retval = 0;
	PlnrAMMaterialPar* _rec = NULL;

	_rec = new PlnrAMMaterialPar(0, refPlnrMMaterial, x1RefPlnrMDesign, x2SrefKCat, x3SrefKProp, refPlnrMFile, Val, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrAMMaterialPar::appendNewRecToRst(
			ListPlnrAMMaterialPar& rst
			, PlnrAMMaterialPar** rec
			, const ubigint refPlnrMMaterial
			, const ubigint x1RefPlnrMDesign
			, const string x2SrefKCat
			, const string x3SrefKProp
			, const ubigint refPlnrMFile
			, const string Val
			, const string Comment
		) {
	ubigint retval = 0;
	PlnrAMMaterialPar* _rec = NULL;

	retval = insertNewRec(&_rec, refPlnrMMaterial, x1RefPlnrMDesign, x2SrefKCat, x3SrefKProp, refPlnrMFile, Val, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrAMMaterialPar::insertRst(
			ListPlnrAMMaterialPar& rst
			, bool transact
		) {
};

void TblPlnrAMMaterialPar::updateRec(
			PlnrAMMaterialPar* rec
		) {
};

void TblPlnrAMMaterialPar::updateRst(
			ListPlnrAMMaterialPar& rst
			, bool transact
		) {
};

void TblPlnrAMMaterialPar::removeRecByRef(
			ubigint ref
		) {
};

bool TblPlnrAMMaterialPar::loadRecByRef(
			ubigint ref
			, PlnrAMMaterialPar** rec
		) {
	return false;
};

ubigint TblPlnrAMMaterialPar::loadRefsByMat(
			ubigint refPlnrMMaterial
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblPlnrAMMaterialPar::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListPlnrAMMaterialPar& rst
		) {
	ubigint numload = 0;
	PlnrAMMaterialPar* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrAMMaterialPar
 ******************************************************************************/

MyTblPlnrAMMaterialPar::MyTblPlnrAMMaterialPar() : TblPlnrAMMaterialPar(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblPlnrAMMaterialPar::~MyTblPlnrAMMaterialPar() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblPlnrAMMaterialPar::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrAMMaterialPar (refPlnrMMaterial, x1RefPlnrMDesign, x2SrefKCat, x3SrefKProp, refPlnrMFile, Val, Comment) VALUES (?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrAMMaterialPar SET refPlnrMMaterial = ?, x1RefPlnrMDesign = ?, x2SrefKCat = ?, x3SrefKProp = ?, refPlnrMFile = ?, Val = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblPlnrAMMaterialPar WHERE ref = ?", false);
};

bool MyTblPlnrAMMaterialPar::loadRecBySQL(
			const string& sqlstr
			, PlnrAMMaterialPar** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrAMMaterialPar* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrAMMaterialPar / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrAMMaterialPar();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refPlnrMMaterial = atoll((char*) dbrow[1]); else _rec->refPlnrMMaterial = 0;
		if (dbrow[2]) _rec->x1RefPlnrMDesign = atoll((char*) dbrow[2]); else _rec->x1RefPlnrMDesign = 0;
		if (dbrow[3]) _rec->x2SrefKCat.assign(dbrow[3], dblengths[3]); else _rec->x2SrefKCat = "";
		if (dbrow[4]) _rec->x3SrefKProp.assign(dbrow[4], dblengths[4]); else _rec->x3SrefKProp = "";
		if (dbrow[5]) _rec->refPlnrMFile = atoll((char*) dbrow[5]); else _rec->refPlnrMFile = 0;
		if (dbrow[6]) _rec->Val.assign(dbrow[6], dblengths[6]); else _rec->Val = "";
		if (dbrow[7]) _rec->Comment.assign(dbrow[7], dblengths[7]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrAMMaterialPar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrAMMaterialPar& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrAMMaterialPar* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrAMMaterialPar / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrAMMaterialPar();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refPlnrMMaterial = atoll((char*) dbrow[1]); else rec->refPlnrMMaterial = 0;
			if (dbrow[2]) rec->x1RefPlnrMDesign = atoll((char*) dbrow[2]); else rec->x1RefPlnrMDesign = 0;
			if (dbrow[3]) rec->x2SrefKCat.assign(dbrow[3], dblengths[3]); else rec->x2SrefKCat = "";
			if (dbrow[4]) rec->x3SrefKProp.assign(dbrow[4], dblengths[4]); else rec->x3SrefKProp = "";
			if (dbrow[5]) rec->refPlnrMFile = atoll((char*) dbrow[5]); else rec->refPlnrMFile = 0;
			if (dbrow[6]) rec->Val.assign(dbrow[6], dblengths[6]); else rec->Val = "";
			if (dbrow[7]) rec->Comment.assign(dbrow[7], dblengths[7]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrAMMaterialPar::insertRec(
			PlnrAMMaterialPar* rec
		) {
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	l[2] = rec->x2SrefKCat.length();
	l[3] = rec->x3SrefKProp.length();
	l[5] = rec->Val.length();
	l[6] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refPlnrMMaterial,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->x1RefPlnrMDesign,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->x2SrefKCat.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->x3SrefKProp.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->refPlnrMFile,&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->Val.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[6]),&(n[6]),&(e[6]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrAMMaterialPar / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrAMMaterialPar / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblPlnrAMMaterialPar::insertRst(
			ListPlnrAMMaterialPar& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblPlnrAMMaterialPar::updateRec(
			PlnrAMMaterialPar* rec
		) {
	unsigned long l[8]; my_bool n[8]; my_bool e[8];

	l[2] = rec->x2SrefKCat.length();
	l[3] = rec->x3SrefKProp.length();
	l[5] = rec->Val.length();
	l[6] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refPlnrMMaterial,&(l[0]),&(n[0]),&(e[0])), 
		bindUbigint(&rec->x1RefPlnrMDesign,&(l[1]),&(n[1]),&(e[1])), 
		bindCstring((char*) (rec->x2SrefKCat.c_str()),&(l[2]),&(n[2]),&(e[2])), 
		bindCstring((char*) (rec->x3SrefKProp.c_str()),&(l[3]),&(n[3]),&(e[3])), 
		bindUbigint(&rec->refPlnrMFile,&(l[4]),&(n[4]),&(e[4])), 
		bindCstring((char*) (rec->Val.c_str()),&(l[5]),&(n[5]),&(e[5])), 
		bindCstring((char*) (rec->Comment.c_str()),&(l[6]),&(n[6]),&(e[6])), 
		bindUbigint(&rec->ref,&(l[7]),&(n[7]),&(e[7]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrAMMaterialPar / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrAMMaterialPar / stmtUpdateRec)\n");
};

void MyTblPlnrAMMaterialPar::updateRst(
			ListPlnrAMMaterialPar& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblPlnrAMMaterialPar::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrAMMaterialPar / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrAMMaterialPar / stmtRemoveRecByRef)\n");
};

bool MyTblPlnrAMMaterialPar::loadRecByRef(
			ubigint ref
			, PlnrAMMaterialPar** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrAMMaterialPar WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblPlnrAMMaterialPar::loadRefsByMat(
			ubigint refPlnrMMaterial
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblPlnrAMMaterialPar WHERE refPlnrMMaterial = " + to_string(refPlnrMMaterial) + "", append, refs);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrAMMaterialPar
 ******************************************************************************/

PgTblPlnrAMMaterialPar::PgTblPlnrAMMaterialPar() : TblPlnrAMMaterialPar(), PgTable() {
};

PgTblPlnrAMMaterialPar::~PgTblPlnrAMMaterialPar() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblPlnrAMMaterialPar::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrAMMaterialPar_insertRec", "INSERT INTO TblPlnrAMMaterialPar (refPlnrMMaterial, x1RefPlnrMDesign, x2SrefKCat, x3SrefKProp, refPlnrMFile, Val, Comment) VALUES ($1,$2,$3,$4,$5,$6,$7) RETURNING ref", 7, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrAMMaterialPar_updateRec", "UPDATE TblPlnrAMMaterialPar SET refPlnrMMaterial = $1, x1RefPlnrMDesign = $2, x2SrefKCat = $3, x3SrefKProp = $4, refPlnrMFile = $5, Val = $6, Comment = $7 WHERE ref = $8", 8, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrAMMaterialPar_removeRecByRef", "DELETE FROM TblPlnrAMMaterialPar WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrAMMaterialPar_loadRecByRef", "SELECT ref, refPlnrMMaterial, x1RefPlnrMDesign, x2SrefKCat, x3SrefKProp, refPlnrMFile, Val, Comment FROM TblPlnrAMMaterialPar WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblPlnrAMMaterialPar_loadRefsByMat", "SELECT ref FROM TblPlnrAMMaterialPar WHERE refPlnrMMaterial = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrAMMaterialPar::loadRec(
			PGresult* res
			, PlnrAMMaterialPar** rec
		) {
	char* ptr;

	PlnrAMMaterialPar* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrAMMaterialPar();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refplnrmmaterial"),
			PQfnumber(res, "x1refplnrmdesign"),
			PQfnumber(res, "x2srefkcat"),
			PQfnumber(res, "x3srefkprop"),
			PQfnumber(res, "refplnrmfile"),
			PQfnumber(res, "val"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refPlnrMMaterial = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1RefPlnrMDesign = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->x2SrefKCat.assign(ptr, PQgetlength(res, 0, fnum[3]));
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->x3SrefKProp.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->refPlnrMFile = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->Val.assign(ptr, PQgetlength(res, 0, fnum[6]));
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[7]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrAMMaterialPar::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrAMMaterialPar& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrAMMaterialPar* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refplnrmmaterial"),
			PQfnumber(res, "x1refplnrmdesign"),
			PQfnumber(res, "x2srefkcat"),
			PQfnumber(res, "x3srefkprop"),
			PQfnumber(res, "refplnrmfile"),
			PQfnumber(res, "val"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new PlnrAMMaterialPar();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refPlnrMMaterial = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1RefPlnrMDesign = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->x2SrefKCat.assign(ptr, PQgetlength(res, numread, fnum[3]));
			ptr = PQgetvalue(res, numread, fnum[4]); rec->x3SrefKProp.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->refPlnrMFile = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->Val.assign(ptr, PQgetlength(res, numread, fnum[6]));
			ptr = PQgetvalue(res, numread, fnum[7]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[7]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrAMMaterialPar::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrAMMaterialPar** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrAMMaterialPar / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

bool PgTblPlnrAMMaterialPar::loadRecBySQL(
			const string& sqlstr
			, PlnrAMMaterialPar** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrAMMaterialPar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrAMMaterialPar& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrAMMaterialPar::insertRec(
			PlnrAMMaterialPar* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refPlnrMMaterial = htonl64(rec->refPlnrMMaterial);
	ubigint _x1RefPlnrMDesign = htonl64(rec->x1RefPlnrMDesign);
	ubigint _refPlnrMFile = htonl64(rec->refPlnrMFile);

	const char* vals[] = {
		(char*) &_refPlnrMMaterial,
		(char*) &_x1RefPlnrMDesign,
		rec->x2SrefKCat.c_str(),
		rec->x3SrefKProp.c_str(),
		(char*) &_refPlnrMFile,
		rec->Val.c_str(),
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint),
		0,
		0
	};
	const int f[] = {1, 1, 0, 0, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblPlnrAMMaterialPar_insertRec", 7, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrAMMaterialPar_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblPlnrAMMaterialPar::insertRst(
			ListPlnrAMMaterialPar& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblPlnrAMMaterialPar::updateRec(
			PlnrAMMaterialPar* rec
		) {
	PGresult* res;

	ubigint _refPlnrMMaterial = htonl64(rec->refPlnrMMaterial);
	ubigint _x1RefPlnrMDesign = htonl64(rec->x1RefPlnrMDesign);
	ubigint _refPlnrMFile = htonl64(rec->refPlnrMFile);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refPlnrMMaterial,
		(char*) &_x1RefPlnrMDesign,
		rec->x2SrefKCat.c_str(),
		rec->x3SrefKProp.c_str(),
		(char*) &_refPlnrMFile,
		rec->Val.c_str(),
		rec->Comment.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 0, 0, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblPlnrAMMaterialPar_updateRec", 8, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrAMMaterialPar_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrAMMaterialPar::updateRst(
			ListPlnrAMMaterialPar& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblPlnrAMMaterialPar::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblPlnrAMMaterialPar_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrAMMaterialPar_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblPlnrAMMaterialPar::loadRecByRef(
			ubigint ref
			, PlnrAMMaterialPar** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrAMMaterialPar_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblPlnrAMMaterialPar::loadRefsByMat(
			ubigint refPlnrMMaterial
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refPlnrMMaterial = htonl64(refPlnrMMaterial);

	const char* vals[] = {
		(char*) &_refPlnrMMaterial
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblPlnrAMMaterialPar_loadRefsByMat", 1, vals, l, f, append, refs);
};

// IP pgTbl --- END

