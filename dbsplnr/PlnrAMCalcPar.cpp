/**
  * \file PlnrAMCalcPar.cpp
  * database access for table TblPlnrAMCalcPar (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrAMCalcPar.h"

/******************************************************************************
 class PlnrAMCalcPar
 ******************************************************************************/

PlnrAMCalcPar::PlnrAMCalcPar(
			const ubigint ref
			, const ubigint refPlnrMCalc
			, const ubigint x1RefPlnrMCalcitem
			, const string x2SrefKCat
			, const string x3SrefKProp
			, const string Val
		) {

	this->ref = ref;
	this->refPlnrMCalc = refPlnrMCalc;
	this->x1RefPlnrMCalcitem = x1RefPlnrMCalcitem;
	this->x2SrefKCat = x2SrefKCat;
	this->x3SrefKProp = x3SrefKProp;
	this->Val = Val;
};

bool PlnrAMCalcPar::operator==(
			const PlnrAMCalcPar& comp
		) {
	return false;
};

bool PlnrAMCalcPar::operator!=(
			const PlnrAMCalcPar& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListPlnrAMCalcPar
 ******************************************************************************/

ListPlnrAMCalcPar::ListPlnrAMCalcPar() {
};

ListPlnrAMCalcPar::ListPlnrAMCalcPar(
			const ListPlnrAMCalcPar& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrAMCalcPar(*(src.nodes[i]));
};

ListPlnrAMCalcPar::~ListPlnrAMCalcPar() {
	clear();
};

void ListPlnrAMCalcPar::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrAMCalcPar::size() const {
	return(nodes.size());
};

void ListPlnrAMCalcPar::append(
			PlnrAMCalcPar* rec
		) {
	nodes.push_back(rec);
};

PlnrAMCalcPar* ListPlnrAMCalcPar::operator[](
			const uint ix
		) {
	PlnrAMCalcPar* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListPlnrAMCalcPar& ListPlnrAMCalcPar::operator=(
			const ListPlnrAMCalcPar& src
		) {
	PlnrAMCalcPar* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrAMCalcPar(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListPlnrAMCalcPar::operator==(
			const ListPlnrAMCalcPar& comp
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

bool ListPlnrAMCalcPar::operator!=(
			const ListPlnrAMCalcPar& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblPlnrAMCalcPar
 ******************************************************************************/

TblPlnrAMCalcPar::TblPlnrAMCalcPar() {
};

TblPlnrAMCalcPar::~TblPlnrAMCalcPar() {
};

bool TblPlnrAMCalcPar::loadRecBySQL(
			const string& sqlstr
			, PlnrAMCalcPar** rec
		) {
	return false;
};

ubigint TblPlnrAMCalcPar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrAMCalcPar& rst
		) {
	return 0;
};

void TblPlnrAMCalcPar::insertRec(
			PlnrAMCalcPar* rec
		) {
};

ubigint TblPlnrAMCalcPar::insertNewRec(
			PlnrAMCalcPar** rec
			, const ubigint refPlnrMCalc
			, const ubigint x1RefPlnrMCalcitem
			, const string x2SrefKCat
			, const string x3SrefKProp
			, const string Val
		) {
	ubigint retval = 0;
	PlnrAMCalcPar* _rec = NULL;

	_rec = new PlnrAMCalcPar(0, refPlnrMCalc, x1RefPlnrMCalcitem, x2SrefKCat, x3SrefKProp, Val);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrAMCalcPar::appendNewRecToRst(
			ListPlnrAMCalcPar& rst
			, PlnrAMCalcPar** rec
			, const ubigint refPlnrMCalc
			, const ubigint x1RefPlnrMCalcitem
			, const string x2SrefKCat
			, const string x3SrefKProp
			, const string Val
		) {
	ubigint retval = 0;
	PlnrAMCalcPar* _rec = NULL;

	retval = insertNewRec(&_rec, refPlnrMCalc, x1RefPlnrMCalcitem, x2SrefKCat, x3SrefKProp, Val);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrAMCalcPar::insertRst(
			ListPlnrAMCalcPar& rst
			, bool transact
		) {
};

void TblPlnrAMCalcPar::updateRec(
			PlnrAMCalcPar* rec
		) {
};

void TblPlnrAMCalcPar::updateRst(
			ListPlnrAMCalcPar& rst
			, bool transact
		) {
};

void TblPlnrAMCalcPar::removeRecByRef(
			ubigint ref
		) {
};

bool TblPlnrAMCalcPar::loadRecByRef(
			ubigint ref
			, PlnrAMCalcPar** rec
		) {
	return false;
};

bool TblPlnrAMCalcPar::loadRecByCalCliCatPrp(
			ubigint refPlnrMCalc
			, ubigint x1RefPlnrMCalcitem
			, string x2SrefKCat
			, string x3SrefKProp
			, PlnrAMCalcPar** rec
		) {
	return false;
};

ubigint TblPlnrAMCalcPar::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListPlnrAMCalcPar& rst
		) {
	ubigint numload = 0;
	PlnrAMCalcPar* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrAMCalcPar
 ******************************************************************************/

MyTblPlnrAMCalcPar::MyTblPlnrAMCalcPar() : TblPlnrAMCalcPar(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblPlnrAMCalcPar::~MyTblPlnrAMCalcPar() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblPlnrAMCalcPar::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrAMCalcPar (refPlnrMCalc, x1RefPlnrMCalcitem, x2SrefKCat, x3SrefKProp, Val) VALUES (?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrAMCalcPar SET refPlnrMCalc = ?, x1RefPlnrMCalcitem = ?, x2SrefKCat = ?, x3SrefKProp = ?, Val = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblPlnrAMCalcPar WHERE ref = ?", false);
};

bool MyTblPlnrAMCalcPar::loadRecBySQL(
			const string& sqlstr
			, PlnrAMCalcPar** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrAMCalcPar* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrAMCalcPar / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrAMCalcPar();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refPlnrMCalc = atoll((char*) dbrow[1]); else _rec->refPlnrMCalc = 0;
		if (dbrow[2]) _rec->x1RefPlnrMCalcitem = atoll((char*) dbrow[2]); else _rec->x1RefPlnrMCalcitem = 0;
		if (dbrow[3]) _rec->x2SrefKCat.assign(dbrow[3], dblengths[3]); else _rec->x2SrefKCat = "";
		if (dbrow[4]) _rec->x3SrefKProp.assign(dbrow[4], dblengths[4]); else _rec->x3SrefKProp = "";
		if (dbrow[5]) _rec->Val.assign(dbrow[5], dblengths[5]); else _rec->Val = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrAMCalcPar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrAMCalcPar& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrAMCalcPar* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrAMCalcPar / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrAMCalcPar();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refPlnrMCalc = atoll((char*) dbrow[1]); else rec->refPlnrMCalc = 0;
			if (dbrow[2]) rec->x1RefPlnrMCalcitem = atoll((char*) dbrow[2]); else rec->x1RefPlnrMCalcitem = 0;
			if (dbrow[3]) rec->x2SrefKCat.assign(dbrow[3], dblengths[3]); else rec->x2SrefKCat = "";
			if (dbrow[4]) rec->x3SrefKProp.assign(dbrow[4], dblengths[4]); else rec->x3SrefKProp = "";
			if (dbrow[5]) rec->Val.assign(dbrow[5], dblengths[5]); else rec->Val = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrAMCalcPar::insertRec(
			PlnrAMCalcPar* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[2] = rec->x2SrefKCat.length();
	l[3] = rec->x3SrefKProp.length();
	l[4] = rec->Val.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refPlnrMCalc,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->x1RefPlnrMCalcitem,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->x2SrefKCat.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->x3SrefKProp.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Val.c_str()),&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrAMCalcPar / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrAMCalcPar / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblPlnrAMCalcPar::insertRst(
			ListPlnrAMCalcPar& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblPlnrAMCalcPar::updateRec(
			PlnrAMCalcPar* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	l[2] = rec->x2SrefKCat.length();
	l[3] = rec->x3SrefKProp.length();
	l[4] = rec->Val.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refPlnrMCalc,&(l[0]),&(n[0]),&(e[0])), 
		bindUbigint(&rec->x1RefPlnrMCalcitem,&(l[1]),&(n[1]),&(e[1])), 
		bindCstring((char*) (rec->x2SrefKCat.c_str()),&(l[2]),&(n[2]),&(e[2])), 
		bindCstring((char*) (rec->x3SrefKProp.c_str()),&(l[3]),&(n[3]),&(e[3])), 
		bindCstring((char*) (rec->Val.c_str()),&(l[4]),&(n[4]),&(e[4])), 
		bindUbigint(&rec->ref,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrAMCalcPar / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrAMCalcPar / stmtUpdateRec)\n");
};

void MyTblPlnrAMCalcPar::updateRst(
			ListPlnrAMCalcPar& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblPlnrAMCalcPar::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrAMCalcPar / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrAMCalcPar / stmtRemoveRecByRef)\n");
};

bool MyTblPlnrAMCalcPar::loadRecByRef(
			ubigint ref
			, PlnrAMCalcPar** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrAMCalcPar WHERE ref = " + to_string(ref), rec);
};

bool MyTblPlnrAMCalcPar::loadRecByCalCliCatPrp(
			ubigint refPlnrMCalc
			, ubigint x1RefPlnrMCalcitem
			, string x2SrefKCat
			, string x3SrefKProp
			, PlnrAMCalcPar** rec
		) {
	return loadRecBySQL("SELECT ref, refPlnrMCalc, x1RefPlnrMCalcitem, x2SrefKCat, x3SrefKProp, Val FROM TblPlnrAMCalcPar WHERE refPlnrMCalc = " + to_string(refPlnrMCalc) + " AND x1RefPlnrMCalcitem = " + to_string(x1RefPlnrMCalcitem) + " AND x2SrefKCat = '" + x2SrefKCat + "' AND x3SrefKProp = '" + x3SrefKProp + "'", rec);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrAMCalcPar
 ******************************************************************************/

PgTblPlnrAMCalcPar::PgTblPlnrAMCalcPar() : TblPlnrAMCalcPar(), PgTable() {
};

PgTblPlnrAMCalcPar::~PgTblPlnrAMCalcPar() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblPlnrAMCalcPar::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrAMCalcPar_insertRec", "INSERT INTO TblPlnrAMCalcPar (refPlnrMCalc, x1RefPlnrMCalcitem, x2SrefKCat, x3SrefKProp, Val) VALUES ($1,$2,$3,$4,$5) RETURNING ref", 5, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrAMCalcPar_updateRec", "UPDATE TblPlnrAMCalcPar SET refPlnrMCalc = $1, x1RefPlnrMCalcitem = $2, x2SrefKCat = $3, x3SrefKProp = $4, Val = $5 WHERE ref = $6", 6, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrAMCalcPar_removeRecByRef", "DELETE FROM TblPlnrAMCalcPar WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrAMCalcPar_loadRecByRef", "SELECT ref, refPlnrMCalc, x1RefPlnrMCalcitem, x2SrefKCat, x3SrefKProp, Val FROM TblPlnrAMCalcPar WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblPlnrAMCalcPar_loadRecByCalCliCatPrp", "SELECT ref, refPlnrMCalc, x1RefPlnrMCalcitem, x2SrefKCat, x3SrefKProp, Val FROM TblPlnrAMCalcPar WHERE refPlnrMCalc = $1 AND x1RefPlnrMCalcitem = $2 AND x2SrefKCat = $3 AND x3SrefKProp = $4", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrAMCalcPar::loadRec(
			PGresult* res
			, PlnrAMCalcPar** rec
		) {
	char* ptr;

	PlnrAMCalcPar* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrAMCalcPar();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refplnrmcalc"),
			PQfnumber(res, "x1refplnrmcalcitem"),
			PQfnumber(res, "x2srefkcat"),
			PQfnumber(res, "x3srefkprop"),
			PQfnumber(res, "val")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refPlnrMCalc = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1RefPlnrMCalcitem = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->x2SrefKCat.assign(ptr, PQgetlength(res, 0, fnum[3]));
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->x3SrefKProp.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->Val.assign(ptr, PQgetlength(res, 0, fnum[5]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrAMCalcPar::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrAMCalcPar& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrAMCalcPar* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refplnrmcalc"),
			PQfnumber(res, "x1refplnrmcalcitem"),
			PQfnumber(res, "x2srefkcat"),
			PQfnumber(res, "x3srefkprop"),
			PQfnumber(res, "val")
		};

		while (numread < numrow) {
			rec = new PlnrAMCalcPar();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refPlnrMCalc = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1RefPlnrMCalcitem = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->x2SrefKCat.assign(ptr, PQgetlength(res, numread, fnum[3]));
			ptr = PQgetvalue(res, numread, fnum[4]); rec->x3SrefKProp.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->Val.assign(ptr, PQgetlength(res, numread, fnum[5]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrAMCalcPar::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrAMCalcPar** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrAMCalcPar / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

bool PgTblPlnrAMCalcPar::loadRecBySQL(
			const string& sqlstr
			, PlnrAMCalcPar** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrAMCalcPar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrAMCalcPar& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrAMCalcPar::insertRec(
			PlnrAMCalcPar* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refPlnrMCalc = htonl64(rec->refPlnrMCalc);
	ubigint _x1RefPlnrMCalcitem = htonl64(rec->x1RefPlnrMCalcitem);

	const char* vals[] = {
		(char*) &_refPlnrMCalc,
		(char*) &_x1RefPlnrMCalcitem,
		rec->x2SrefKCat.c_str(),
		rec->x3SrefKProp.c_str(),
		rec->Val.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		0
	};
	const int f[] = {1, 1, 0, 0, 0};

	res = PQexecPrepared(dbs, "TblPlnrAMCalcPar_insertRec", 5, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrAMCalcPar_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblPlnrAMCalcPar::insertRst(
			ListPlnrAMCalcPar& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblPlnrAMCalcPar::updateRec(
			PlnrAMCalcPar* rec
		) {
	PGresult* res;

	ubigint _refPlnrMCalc = htonl64(rec->refPlnrMCalc);
	ubigint _x1RefPlnrMCalcitem = htonl64(rec->x1RefPlnrMCalcitem);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refPlnrMCalc,
		(char*) &_x1RefPlnrMCalcitem,
		rec->x2SrefKCat.c_str(),
		rec->x3SrefKProp.c_str(),
		rec->Val.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 0, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblPlnrAMCalcPar_updateRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrAMCalcPar_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrAMCalcPar::updateRst(
			ListPlnrAMCalcPar& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblPlnrAMCalcPar::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblPlnrAMCalcPar_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrAMCalcPar_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblPlnrAMCalcPar::loadRecByRef(
			ubigint ref
			, PlnrAMCalcPar** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrAMCalcPar_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblPlnrAMCalcPar::loadRecByCalCliCatPrp(
			ubigint refPlnrMCalc
			, ubigint x1RefPlnrMCalcitem
			, string x2SrefKCat
			, string x3SrefKProp
			, PlnrAMCalcPar** rec
		) {
	ubigint _refPlnrMCalc = htonl64(refPlnrMCalc);
	ubigint _x1RefPlnrMCalcitem = htonl64(x1RefPlnrMCalcitem);

	const char* vals[] = {
		(char*) &_refPlnrMCalc,
		(char*) &_x1RefPlnrMCalcitem,
		x2SrefKCat.c_str(),
		x3SrefKProp.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0
	};
	const int f[] = {1,1,0,0};

	return loadRecByStmt("TblPlnrAMCalcPar_loadRecByCalCliCatPrp", 4, vals, l, f, rec);
};

// IP pgTbl --- END

