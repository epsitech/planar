/**
  * \file PlnrMArray.cpp
  * database access for table TblPlnrMArray (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrMArray.h"

/******************************************************************************
 class PlnrMArray
 ******************************************************************************/

PlnrMArray::PlnrMArray(
			const ubigint ref
			, const ubigint refPlnrMTapeout
			, const ubigint refPlnrMDesign
			, const string sref
			, const usmallint I
			, const usmallint J
			, const double di
			, const double dj
			, const usmallint K
			, const usmallint L
			, const double dk
			, const double dl
			, const usmallint M
			, const usmallint N
			, const double dm
			, const double dn
		) {

	this->ref = ref;
	this->refPlnrMTapeout = refPlnrMTapeout;
	this->refPlnrMDesign = refPlnrMDesign;
	this->sref = sref;
	this->I = I;
	this->J = J;
	this->di = di;
	this->dj = dj;
	this->K = K;
	this->L = L;
	this->dk = dk;
	this->dl = dl;
	this->M = M;
	this->N = N;
	this->dm = dm;
	this->dn = dn;
};

bool PlnrMArray::operator==(
			const PlnrMArray& comp
		) {
	return false;
};

bool PlnrMArray::operator!=(
			const PlnrMArray& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListPlnrMArray
 ******************************************************************************/

ListPlnrMArray::ListPlnrMArray() {
};

ListPlnrMArray::ListPlnrMArray(
			const ListPlnrMArray& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrMArray(*(src.nodes[i]));
};

ListPlnrMArray::~ListPlnrMArray() {
	clear();
};

void ListPlnrMArray::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrMArray::size() const {
	return(nodes.size());
};

void ListPlnrMArray::append(
			PlnrMArray* rec
		) {
	nodes.push_back(rec);
};

PlnrMArray* ListPlnrMArray::operator[](
			const uint ix
		) {
	PlnrMArray* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListPlnrMArray& ListPlnrMArray::operator=(
			const ListPlnrMArray& src
		) {
	PlnrMArray* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrMArray(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListPlnrMArray::operator==(
			const ListPlnrMArray& comp
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

bool ListPlnrMArray::operator!=(
			const ListPlnrMArray& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblPlnrMArray
 ******************************************************************************/

TblPlnrMArray::TblPlnrMArray() {
};

TblPlnrMArray::~TblPlnrMArray() {
};

bool TblPlnrMArray::loadRecBySQL(
			const string& sqlstr
			, PlnrMArray** rec
		) {
	return false;
};

ubigint TblPlnrMArray::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrMArray& rst
		) {
	return 0;
};

void TblPlnrMArray::insertRec(
			PlnrMArray* rec
		) {
};

ubigint TblPlnrMArray::insertNewRec(
			PlnrMArray** rec
			, const ubigint refPlnrMTapeout
			, const ubigint refPlnrMDesign
			, const string sref
			, const usmallint I
			, const usmallint J
			, const double di
			, const double dj
			, const usmallint K
			, const usmallint L
			, const double dk
			, const double dl
			, const usmallint M
			, const usmallint N
			, const double dm
			, const double dn
		) {
	ubigint retval = 0;
	PlnrMArray* _rec = NULL;

	_rec = new PlnrMArray(0, refPlnrMTapeout, refPlnrMDesign, sref, I, J, di, dj, K, L, dk, dl, M, N, dm, dn);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrMArray::appendNewRecToRst(
			ListPlnrMArray& rst
			, PlnrMArray** rec
			, const ubigint refPlnrMTapeout
			, const ubigint refPlnrMDesign
			, const string sref
			, const usmallint I
			, const usmallint J
			, const double di
			, const double dj
			, const usmallint K
			, const usmallint L
			, const double dk
			, const double dl
			, const usmallint M
			, const usmallint N
			, const double dm
			, const double dn
		) {
	ubigint retval = 0;
	PlnrMArray* _rec = NULL;

	retval = insertNewRec(&_rec, refPlnrMTapeout, refPlnrMDesign, sref, I, J, di, dj, K, L, dk, dl, M, N, dm, dn);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrMArray::insertRst(
			ListPlnrMArray& rst
			, bool transact
		) {
};

void TblPlnrMArray::updateRec(
			PlnrMArray* rec
		) {
};

void TblPlnrMArray::updateRst(
			ListPlnrMArray& rst
			, bool transact
		) {
};

void TblPlnrMArray::removeRecByRef(
			ubigint ref
		) {
};

bool TblPlnrMArray::loadRecByRef(
			ubigint ref
			, PlnrMArray** rec
		) {
	return false;
};

bool TblPlnrMArray::loadSrfByRef(
			ubigint ref
			, string& val
		) {
	return false;
};

ubigint TblPlnrMArray::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListPlnrMArray& rst
		) {
	ubigint numload = 0;
	PlnrMArray* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrMArray
 ******************************************************************************/

MyTblPlnrMArray::MyTblPlnrMArray() : TblPlnrMArray(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblPlnrMArray::~MyTblPlnrMArray() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblPlnrMArray::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrMArray (refPlnrMTapeout, refPlnrMDesign, sref, I, J, di, dj, K, L, dk, dl, M, N, dm, dn) VALUES (?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrMArray SET refPlnrMTapeout = ?, refPlnrMDesign = ?, sref = ?, I = ?, J = ?, di = ?, dj = ?, K = ?, L = ?, dk = ?, dl = ?, M = ?, N = ?, dm = ?, dn = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblPlnrMArray WHERE ref = ?", false);
};

bool MyTblPlnrMArray::loadRecBySQL(
			const string& sqlstr
			, PlnrMArray** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrMArray* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrMArray / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrMArray();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refPlnrMTapeout = atoll((char*) dbrow[1]); else _rec->refPlnrMTapeout = 0;
		if (dbrow[2]) _rec->refPlnrMDesign = atoll((char*) dbrow[2]); else _rec->refPlnrMDesign = 0;
		if (dbrow[3]) _rec->sref.assign(dbrow[3], dblengths[3]); else _rec->sref = "";
		if (dbrow[4]) _rec->I = atoi((char*) dbrow[4]); else _rec->I = 0;
		if (dbrow[5]) _rec->J = atoi((char*) dbrow[5]); else _rec->J = 0;
		if (dbrow[6]) _rec->di = atof((char*) dbrow[6]); else _rec->di = 0.0;
		if (dbrow[7]) _rec->dj = atof((char*) dbrow[7]); else _rec->dj = 0.0;
		if (dbrow[8]) _rec->K = atoi((char*) dbrow[8]); else _rec->K = 0;
		if (dbrow[9]) _rec->L = atoi((char*) dbrow[9]); else _rec->L = 0;
		if (dbrow[10]) _rec->dk = atof((char*) dbrow[10]); else _rec->dk = 0.0;
		if (dbrow[11]) _rec->dl = atof((char*) dbrow[11]); else _rec->dl = 0.0;
		if (dbrow[12]) _rec->M = atoi((char*) dbrow[12]); else _rec->M = 0;
		if (dbrow[13]) _rec->N = atoi((char*) dbrow[13]); else _rec->N = 0;
		if (dbrow[14]) _rec->dm = atof((char*) dbrow[14]); else _rec->dm = 0.0;
		if (dbrow[15]) _rec->dn = atof((char*) dbrow[15]); else _rec->dn = 0.0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrMArray::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrMArray& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrMArray* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrMArray / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrMArray();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refPlnrMTapeout = atoll((char*) dbrow[1]); else rec->refPlnrMTapeout = 0;
			if (dbrow[2]) rec->refPlnrMDesign = atoll((char*) dbrow[2]); else rec->refPlnrMDesign = 0;
			if (dbrow[3]) rec->sref.assign(dbrow[3], dblengths[3]); else rec->sref = "";
			if (dbrow[4]) rec->I = atoi((char*) dbrow[4]); else rec->I = 0;
			if (dbrow[5]) rec->J = atoi((char*) dbrow[5]); else rec->J = 0;
			if (dbrow[6]) rec->di = atof((char*) dbrow[6]); else rec->di = 0.0;
			if (dbrow[7]) rec->dj = atof((char*) dbrow[7]); else rec->dj = 0.0;
			if (dbrow[8]) rec->K = atoi((char*) dbrow[8]); else rec->K = 0;
			if (dbrow[9]) rec->L = atoi((char*) dbrow[9]); else rec->L = 0;
			if (dbrow[10]) rec->dk = atof((char*) dbrow[10]); else rec->dk = 0.0;
			if (dbrow[11]) rec->dl = atof((char*) dbrow[11]); else rec->dl = 0.0;
			if (dbrow[12]) rec->M = atoi((char*) dbrow[12]); else rec->M = 0;
			if (dbrow[13]) rec->N = atoi((char*) dbrow[13]); else rec->N = 0;
			if (dbrow[14]) rec->dm = atof((char*) dbrow[14]); else rec->dm = 0.0;
			if (dbrow[15]) rec->dn = atof((char*) dbrow[15]); else rec->dn = 0.0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrMArray::insertRec(
			PlnrMArray* rec
		) {
	unsigned long l[15]; my_bool n[15]; my_bool e[15];

	l[2] = rec->sref.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refPlnrMTapeout,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refPlnrMDesign,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->sref.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindUsmallint(&rec->I,&(l[3]),&(n[3]),&(e[3])),
		bindUsmallint(&rec->J,&(l[4]),&(n[4]),&(e[4])),
		bindDouble(&rec->di,&(l[5]),&(n[5]),&(e[5])),
		bindDouble(&rec->dj,&(l[6]),&(n[6]),&(e[6])),
		bindUsmallint(&rec->K,&(l[7]),&(n[7]),&(e[7])),
		bindUsmallint(&rec->L,&(l[8]),&(n[8]),&(e[8])),
		bindDouble(&rec->dk,&(l[9]),&(n[9]),&(e[9])),
		bindDouble(&rec->dl,&(l[10]),&(n[10]),&(e[10])),
		bindUsmallint(&rec->M,&(l[11]),&(n[11]),&(e[11])),
		bindUsmallint(&rec->N,&(l[12]),&(n[12]),&(e[12])),
		bindDouble(&rec->dm,&(l[13]),&(n[13]),&(e[13])),
		bindDouble(&rec->dn,&(l[14]),&(n[14]),&(e[14]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrMArray / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrMArray / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblPlnrMArray::insertRst(
			ListPlnrMArray& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblPlnrMArray::updateRec(
			PlnrMArray* rec
		) {
	unsigned long l[16]; my_bool n[16]; my_bool e[16];

	l[2] = rec->sref.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refPlnrMTapeout,&(l[0]),&(n[0]),&(e[0])), 
		bindUbigint(&rec->refPlnrMDesign,&(l[1]),&(n[1]),&(e[1])), 
		bindCstring((char*) (rec->sref.c_str()),&(l[2]),&(n[2]),&(e[2])), 
		bindUsmallint(&rec->I,&(l[3]),&(n[3]),&(e[3])), 
		bindUsmallint(&rec->J,&(l[4]),&(n[4]),&(e[4])), 
		bindDouble(&rec->di,&(l[5]),&(n[5]),&(e[5])), 
		bindDouble(&rec->dj,&(l[6]),&(n[6]),&(e[6])), 
		bindUsmallint(&rec->K,&(l[7]),&(n[7]),&(e[7])), 
		bindUsmallint(&rec->L,&(l[8]),&(n[8]),&(e[8])), 
		bindDouble(&rec->dk,&(l[9]),&(n[9]),&(e[9])), 
		bindDouble(&rec->dl,&(l[10]),&(n[10]),&(e[10])), 
		bindUsmallint(&rec->M,&(l[11]),&(n[11]),&(e[11])), 
		bindUsmallint(&rec->N,&(l[12]),&(n[12]),&(e[12])), 
		bindDouble(&rec->dm,&(l[13]),&(n[13]),&(e[13])), 
		bindDouble(&rec->dn,&(l[14]),&(n[14]),&(e[14])), 
		bindUbigint(&rec->ref,&(l[15]),&(n[15]),&(e[15]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrMArray / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrMArray / stmtUpdateRec)\n");
};

void MyTblPlnrMArray::updateRst(
			ListPlnrMArray& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblPlnrMArray::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrMArray / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrMArray / stmtRemoveRecByRef)\n");
};

bool MyTblPlnrMArray::loadRecByRef(
			ubigint ref
			, PlnrMArray** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrMArray WHERE ref = " + to_string(ref), rec);
};

bool MyTblPlnrMArray::loadSrfByRef(
			ubigint ref
			, string& val
		) {
	return loadStringBySQL("SELECT sref FROM TblPlnrMArray WHERE ref = " + to_string(ref) + "", val);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrMArray
 ******************************************************************************/

PgTblPlnrMArray::PgTblPlnrMArray() : TblPlnrMArray(), PgTable() {
};

PgTblPlnrMArray::~PgTblPlnrMArray() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblPlnrMArray::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrMArray_insertRec", "INSERT INTO TblPlnrMArray (refPlnrMTapeout, refPlnrMDesign, sref, I, J, di, dj, K, L, dk, dl, M, N, dm, dn) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11,$12,$13,$14,$15) RETURNING ref", 15, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrMArray_updateRec", "UPDATE TblPlnrMArray SET refPlnrMTapeout = $1, refPlnrMDesign = $2, sref = $3, I = $4, J = $5, di = $6, dj = $7, K = $8, L = $9, dk = $10, dl = $11, M = $12, N = $13, dm = $14, dn = $15 WHERE ref = $16", 16, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrMArray_removeRecByRef", "DELETE FROM TblPlnrMArray WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrMArray_loadRecByRef", "SELECT ref, refPlnrMTapeout, refPlnrMDesign, sref, I, J, di, dj, K, L, dk, dl, M, N, dm, dn FROM TblPlnrMArray WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblPlnrMArray_loadSrfByRef", "SELECT sref FROM TblPlnrMArray WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrMArray::loadRec(
			PGresult* res
			, PlnrMArray** rec
		) {
	char* ptr;

	PlnrMArray* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrMArray();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refplnrmtapeout"),
			PQfnumber(res, "refplnrmdesign"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "i"),
			PQfnumber(res, "j"),
			PQfnumber(res, "di"),
			PQfnumber(res, "dj"),
			PQfnumber(res, "k"),
			PQfnumber(res, "l"),
			PQfnumber(res, "dk"),
			PQfnumber(res, "dl"),
			PQfnumber(res, "m"),
			PQfnumber(res, "n"),
			PQfnumber(res, "dm"),
			PQfnumber(res, "dn")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refPlnrMTapeout = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->refPlnrMDesign = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[3]));
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->I = atoi(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->J = atoi(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->di = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->dj = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->K = atoi(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->L = atoi(ptr);
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->dk = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[11]); _rec->dl = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[12]); _rec->M = atoi(ptr);
		ptr = PQgetvalue(res, 0, fnum[13]); _rec->N = atoi(ptr);
		ptr = PQgetvalue(res, 0, fnum[14]); _rec->dm = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[15]); _rec->dn = atof(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrMArray::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrMArray& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrMArray* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refplnrmtapeout"),
			PQfnumber(res, "refplnrmdesign"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "i"),
			PQfnumber(res, "j"),
			PQfnumber(res, "di"),
			PQfnumber(res, "dj"),
			PQfnumber(res, "k"),
			PQfnumber(res, "l"),
			PQfnumber(res, "dk"),
			PQfnumber(res, "dl"),
			PQfnumber(res, "m"),
			PQfnumber(res, "n"),
			PQfnumber(res, "dm"),
			PQfnumber(res, "dn")
		};

		while (numread < numrow) {
			rec = new PlnrMArray();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refPlnrMTapeout = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->refPlnrMDesign = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[3]));
			ptr = PQgetvalue(res, numread, fnum[4]); rec->I = atoi(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->J = atoi(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->di = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->dj = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->K = atoi(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->L = atoi(ptr);
			ptr = PQgetvalue(res, numread, fnum[10]); rec->dk = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[11]); rec->dl = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[12]); rec->M = atoi(ptr);
			ptr = PQgetvalue(res, numread, fnum[13]); rec->N = atoi(ptr);
			ptr = PQgetvalue(res, numread, fnum[14]); rec->dm = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[15]); rec->dn = atof(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrMArray::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrMArray** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMArray / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

bool PgTblPlnrMArray::loadRecBySQL(
			const string& sqlstr
			, PlnrMArray** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrMArray::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrMArray& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrMArray::insertRec(
			PlnrMArray* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refPlnrMTapeout = htonl64(rec->refPlnrMTapeout);
	ubigint _refPlnrMDesign = htonl64(rec->refPlnrMDesign);
	usmallint _I = htons(rec->I);
	usmallint _J = htons(rec->J);
	string _di = to_string(rec->di);
	string _dj = to_string(rec->dj);
	usmallint _K = htons(rec->K);
	usmallint _L = htons(rec->L);
	string _dk = to_string(rec->dk);
	string _dl = to_string(rec->dl);
	usmallint _M = htons(rec->M);
	usmallint _N = htons(rec->N);
	string _dm = to_string(rec->dm);
	string _dn = to_string(rec->dn);

	const char* vals[] = {
		(char*) &_refPlnrMTapeout,
		(char*) &_refPlnrMDesign,
		rec->sref.c_str(),
		(char*) &_I,
		(char*) &_J,
		_di.c_str(),
		_dj.c_str(),
		(char*) &_K,
		(char*) &_L,
		_dk.c_str(),
		_dl.c_str(),
		(char*) &_M,
		(char*) &_N,
		_dm.c_str(),
		_dn.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(usmallint),
		sizeof(usmallint),
		0,
		0,
		sizeof(usmallint),
		sizeof(usmallint),
		0,
		0,
		sizeof(usmallint),
		sizeof(usmallint),
		0,
		0
	};
	const int f[] = {1, 1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblPlnrMArray_insertRec", 15, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMArray_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblPlnrMArray::insertRst(
			ListPlnrMArray& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblPlnrMArray::updateRec(
			PlnrMArray* rec
		) {
	PGresult* res;

	ubigint _refPlnrMTapeout = htonl64(rec->refPlnrMTapeout);
	ubigint _refPlnrMDesign = htonl64(rec->refPlnrMDesign);
	usmallint _I = htons(rec->I);
	usmallint _J = htons(rec->J);
	string _di = to_string(rec->di);
	string _dj = to_string(rec->dj);
	usmallint _K = htons(rec->K);
	usmallint _L = htons(rec->L);
	string _dk = to_string(rec->dk);
	string _dl = to_string(rec->dl);
	usmallint _M = htons(rec->M);
	usmallint _N = htons(rec->N);
	string _dm = to_string(rec->dm);
	string _dn = to_string(rec->dn);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refPlnrMTapeout,
		(char*) &_refPlnrMDesign,
		rec->sref.c_str(),
		(char*) &_I,
		(char*) &_J,
		_di.c_str(),
		_dj.c_str(),
		(char*) &_K,
		(char*) &_L,
		_dk.c_str(),
		_dl.c_str(),
		(char*) &_M,
		(char*) &_N,
		_dm.c_str(),
		_dn.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(usmallint),
		sizeof(usmallint),
		0,
		0,
		sizeof(usmallint),
		sizeof(usmallint),
		0,
		0,
		sizeof(usmallint),
		sizeof(usmallint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblPlnrMArray_updateRec", 16, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMArray_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrMArray::updateRst(
			ListPlnrMArray& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblPlnrMArray::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblPlnrMArray_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMArray_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblPlnrMArray::loadRecByRef(
			ubigint ref
			, PlnrMArray** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrMArray_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblPlnrMArray::loadSrfByRef(
			ubigint ref
			, string& val
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadStringByStmt("TblPlnrMArray_loadSrfByRef", 1, vals, l, f, val);
};

// IP pgTbl --- END

