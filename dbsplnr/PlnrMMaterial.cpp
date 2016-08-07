/**
  * \file PlnrMMaterial.cpp
  * database access for table TblPlnrMMaterial (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrMMaterial.h"

/******************************************************************************
 class PlnrMMaterial
 ******************************************************************************/

PlnrMMaterial::PlnrMMaterial(
			const ubigint ref
			, const ubigint grp
			, const ubigint own
			, const uint ixVBasetype
			, const ubigint refPlnrMCalc
			, const ubigint modRefPlnrMMaterial
			, const usmallint modLvl
			, const string sref
			, const string Title
		) {

	this->ref = ref;
	this->grp = grp;
	this->own = own;
	this->ixVBasetype = ixVBasetype;
	this->refPlnrMCalc = refPlnrMCalc;
	this->modRefPlnrMMaterial = modRefPlnrMMaterial;
	this->modLvl = modLvl;
	this->sref = sref;
	this->Title = Title;
};

bool PlnrMMaterial::operator==(
			const PlnrMMaterial& comp
		) {
	return false;
};

bool PlnrMMaterial::operator!=(
			const PlnrMMaterial& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListPlnrMMaterial
 ******************************************************************************/

ListPlnrMMaterial::ListPlnrMMaterial() {
};

ListPlnrMMaterial::ListPlnrMMaterial(
			const ListPlnrMMaterial& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrMMaterial(*(src.nodes[i]));
};

ListPlnrMMaterial::~ListPlnrMMaterial() {
	clear();
};

void ListPlnrMMaterial::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrMMaterial::size() const {
	return(nodes.size());
};

void ListPlnrMMaterial::append(
			PlnrMMaterial* rec
		) {
	nodes.push_back(rec);
};

PlnrMMaterial* ListPlnrMMaterial::operator[](
			const uint ix
		) {
	PlnrMMaterial* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListPlnrMMaterial& ListPlnrMMaterial::operator=(
			const ListPlnrMMaterial& src
		) {
	PlnrMMaterial* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrMMaterial(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListPlnrMMaterial::operator==(
			const ListPlnrMMaterial& comp
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

bool ListPlnrMMaterial::operator!=(
			const ListPlnrMMaterial& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblPlnrMMaterial
 ******************************************************************************/

TblPlnrMMaterial::TblPlnrMMaterial() {
};

TblPlnrMMaterial::~TblPlnrMMaterial() {
};

bool TblPlnrMMaterial::loadRecBySQL(
			const string& sqlstr
			, PlnrMMaterial** rec
		) {
	return false;
};

ubigint TblPlnrMMaterial::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrMMaterial& rst
		) {
	return 0;
};

void TblPlnrMMaterial::insertRec(
			PlnrMMaterial* rec
		) {
};

ubigint TblPlnrMMaterial::insertNewRec(
			PlnrMMaterial** rec
			, const ubigint grp
			, const ubigint own
			, const uint ixVBasetype
			, const ubigint refPlnrMCalc
			, const ubigint modRefPlnrMMaterial
			, const usmallint modLvl
			, const string sref
			, const string Title
		) {
	ubigint retval = 0;
	PlnrMMaterial* _rec = NULL;

	_rec = new PlnrMMaterial(0, grp, own, ixVBasetype, refPlnrMCalc, modRefPlnrMMaterial, modLvl, sref, Title);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrMMaterial::appendNewRecToRst(
			ListPlnrMMaterial& rst
			, PlnrMMaterial** rec
			, const ubigint grp
			, const ubigint own
			, const uint ixVBasetype
			, const ubigint refPlnrMCalc
			, const ubigint modRefPlnrMMaterial
			, const usmallint modLvl
			, const string sref
			, const string Title
		) {
	ubigint retval = 0;
	PlnrMMaterial* _rec = NULL;

	retval = insertNewRec(&_rec, grp, own, ixVBasetype, refPlnrMCalc, modRefPlnrMMaterial, modLvl, sref, Title);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrMMaterial::insertRst(
			ListPlnrMMaterial& rst
			, bool transact
		) {
};

void TblPlnrMMaterial::updateRec(
			PlnrMMaterial* rec
		) {
};

void TblPlnrMMaterial::updateRst(
			ListPlnrMMaterial& rst
			, bool transact
		) {
};

void TblPlnrMMaterial::removeRecByRef(
			ubigint ref
		) {
};

bool TblPlnrMMaterial::loadRecByRef(
			ubigint ref
			, PlnrMMaterial** rec
		) {
	return false;
};

bool TblPlnrMMaterial::confirmByRef(
			ubigint ref
		) {
	return false;
};

bool TblPlnrMMaterial::loadRefBySupSrf(
			ubigint modRefPlnrMMaterial
			, string sref
			, ubigint& val
		) {
	return false;
};

ubigint TblPlnrMMaterial::loadRefsBySup(
			ubigint modRefPlnrMMaterial
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblPlnrMMaterial::loadRstBySup(
			ubigint modRefPlnrMMaterial
			, const bool append
			, ListPlnrMMaterial& rst
		) {
	return 0;
};

bool TblPlnrMMaterial::loadSupByRef(
			ubigint ref
			, ubigint& val
		) {
	return false;
};

ubigint TblPlnrMMaterial::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListPlnrMMaterial& rst
		) {
	ubigint numload = 0;
	PlnrMMaterial* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP loadHrefsup --- BEGIN
ubigint TblPlnrMMaterial::loadHrefsup(
			ubigint ref
			, vector<ubigint>& refs
		) {
	ubigint sup;

	refs.resize(0);
	ubigint retval = 0;

	while (loadSupByRef(ref, sup)) {
		refs.push_back(ref);
		retval++;

		ref = sup;
		if (ref == 0) break;
	};

	return retval;
};

// IP loadHrefsup --- END
// IP loadHrefsdown --- BEGIN
ubigint TblPlnrMMaterial::loadHrefsdown(
			ubigint ref
			, const bool append
			, vector<ubigint>& refs
			, unsigned int firstix
			, unsigned int lastix
		) {
	unsigned int newfirstix, newlastix;

	ubigint retval = 0;

	// initial call
	if ((firstix == 0) && (lastix == 0)) {
		if (!append) refs.resize(0);

		if (confirmByRef(ref)) {
			refs.push_back(ref);
			retval = 1;

		} else {
			// ensure that no recursion takes place
			firstix = 1;
		};
	};

	for (unsigned int i=firstix;i<=lastix;i++) {
		newfirstix = refs.size();
		retval += loadRefsBySup(refs[i], true, refs);
		newlastix = refs.size() - 1;

		if (newlastix >= newfirstix) retval += loadHrefsdown(0, true, refs, newfirstix, newlastix);
	};

	return retval;
};

// IP loadHrefsdown --- END
// IP loadHrstup --- BEGIN
ubigint TblPlnrMMaterial::loadHrstup(
			ubigint ref
			, ListPlnrMMaterial& rst
		) {
	PlnrMMaterial* rec = NULL;

	rst.clear();
	ubigint retval = 0;

	while (loadRecByRef(ref, &rec)) {
		rst.nodes.push_back(rec);
		retval++;

		ref = rec->modRefPlnrMMaterial;
		if (ref == 0) break;
	};

	return retval;
};

// IP loadHrstup --- END
// IP loadHrstdown --- BEGIN
ubigint TblPlnrMMaterial::loadHrstdown(
			ubigint ref
			, const bool append
			, ListPlnrMMaterial& rst
			, unsigned int firstix
			, unsigned int lastix
		) {
	PlnrMMaterial* rec = NULL;

	unsigned int newfirstix, newlastix;

	ubigint retval = 0;

	// initial call
	if ((firstix == 0) && (lastix == 0)) {
		if (!append) rst.clear();

		if (loadRecByRef(ref, &rec)) {
			rst.nodes.push_back(rec);
			retval = 1;

		} else {
			// ensure that no recursion takes place
			firstix = 1;
		};
	};

	for (unsigned int i=firstix;i<=lastix;i++) {
		rec = rst.nodes[i];

		newfirstix = rst.nodes.size();
		retval += loadRstBySup(rec->ref, true, rst);
		newlastix = rst.nodes.size() - 1;

		if (newlastix >= newfirstix) retval += loadHrstdown(0, true, rst, newfirstix, newlastix);
	};

	return retval;
};
// IP loadHrstdown --- END

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrMMaterial
 ******************************************************************************/

MyTblPlnrMMaterial::MyTblPlnrMMaterial() : TblPlnrMMaterial(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblPlnrMMaterial::~MyTblPlnrMMaterial() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblPlnrMMaterial::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrMMaterial (grp, own, ixVBasetype, refPlnrMCalc, modRefPlnrMMaterial, modLvl, sref, Title) VALUES (?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrMMaterial SET grp = ?, own = ?, ixVBasetype = ?, refPlnrMCalc = ?, modRefPlnrMMaterial = ?, modLvl = ?, sref = ?, Title = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblPlnrMMaterial WHERE ref = ?", false);
};

bool MyTblPlnrMMaterial::loadRecBySQL(
			const string& sqlstr
			, PlnrMMaterial** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrMMaterial* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrMMaterial / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrMMaterial();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->grp = atoll((char*) dbrow[1]); else _rec->grp = 0;
		if (dbrow[2]) _rec->own = atoll((char*) dbrow[2]); else _rec->own = 0;
		if (dbrow[3]) _rec->ixVBasetype = atol((char*) dbrow[3]); else _rec->ixVBasetype = 0;
		if (dbrow[4]) _rec->refPlnrMCalc = atoll((char*) dbrow[4]); else _rec->refPlnrMCalc = 0;
		if (dbrow[5]) _rec->modRefPlnrMMaterial = atoll((char*) dbrow[5]); else _rec->modRefPlnrMMaterial = 0;
		if (dbrow[6]) _rec->modLvl = atoi((char*) dbrow[6]); else _rec->modLvl = 0;
		if (dbrow[7]) _rec->sref.assign(dbrow[7], dblengths[7]); else _rec->sref = "";
		if (dbrow[8]) _rec->Title.assign(dbrow[8], dblengths[8]); else _rec->Title = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrMMaterial::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrMMaterial& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrMMaterial* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrMMaterial / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrMMaterial();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->grp = atoll((char*) dbrow[1]); else rec->grp = 0;
			if (dbrow[2]) rec->own = atoll((char*) dbrow[2]); else rec->own = 0;
			if (dbrow[3]) rec->ixVBasetype = atol((char*) dbrow[3]); else rec->ixVBasetype = 0;
			if (dbrow[4]) rec->refPlnrMCalc = atoll((char*) dbrow[4]); else rec->refPlnrMCalc = 0;
			if (dbrow[5]) rec->modRefPlnrMMaterial = atoll((char*) dbrow[5]); else rec->modRefPlnrMMaterial = 0;
			if (dbrow[6]) rec->modLvl = atoi((char*) dbrow[6]); else rec->modLvl = 0;
			if (dbrow[7]) rec->sref.assign(dbrow[7], dblengths[7]); else rec->sref = "";
			if (dbrow[8]) rec->Title.assign(dbrow[8], dblengths[8]); else rec->Title = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrMMaterial::insertRec(
			PlnrMMaterial* rec
		) {
	unsigned long l[8]; my_bool n[8]; my_bool e[8];

	l[6] = rec->sref.length();
	l[7] = rec->Title.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->grp,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->own,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->ixVBasetype,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refPlnrMCalc,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->modRefPlnrMMaterial,&(l[4]),&(n[4]),&(e[4])),
		bindUsmallint(&rec->modLvl,&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->sref.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->Title.c_str()),&(l[7]),&(n[7]),&(e[7]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrMMaterial / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrMMaterial / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblPlnrMMaterial::insertRst(
			ListPlnrMMaterial& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblPlnrMMaterial::updateRec(
			PlnrMMaterial* rec
		) {
	unsigned long l[9]; my_bool n[9]; my_bool e[9];

	l[6] = rec->sref.length();
	l[7] = rec->Title.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->grp,&(l[0]),&(n[0]),&(e[0])), 
		bindUbigint(&rec->own,&(l[1]),&(n[1]),&(e[1])), 
		bindUint(&rec->ixVBasetype,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->refPlnrMCalc,&(l[3]),&(n[3]),&(e[3])), 
		bindUbigint(&rec->modRefPlnrMMaterial,&(l[4]),&(n[4]),&(e[4])), 
		bindUsmallint(&rec->modLvl,&(l[5]),&(n[5]),&(e[5])), 
		bindCstring((char*) (rec->sref.c_str()),&(l[6]),&(n[6]),&(e[6])), 
		bindCstring((char*) (rec->Title.c_str()),&(l[7]),&(n[7]),&(e[7])), 
		bindUbigint(&rec->ref,&(l[8]),&(n[8]),&(e[8]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrMMaterial / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrMMaterial / stmtUpdateRec)\n");
};

void MyTblPlnrMMaterial::updateRst(
			ListPlnrMMaterial& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblPlnrMMaterial::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrMMaterial / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrMMaterial / stmtRemoveRecByRef)\n");
};

bool MyTblPlnrMMaterial::loadRecByRef(
			ubigint ref
			, PlnrMMaterial** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrMMaterial WHERE ref = " + to_string(ref), rec);
};

bool MyTblPlnrMMaterial::confirmByRef(
			ubigint ref
		) {
	ubigint val;
	return loadUbigintBySQL("SELECT ref FROM TblPlnrMMaterial WHERE ref = " + to_string(ref) + "", val);
};

bool MyTblPlnrMMaterial::loadRefBySupSrf(
			ubigint modRefPlnrMMaterial
			, string sref
			, ubigint& val
		) {
	return loadUbigintBySQL("SELECT ref FROM TblPlnrMMaterial WHERE modRefPlnrMMaterial = " + to_string(modRefPlnrMMaterial) + " AND sref = '" + sref + "'", val);
};

ubigint MyTblPlnrMMaterial::loadRefsBySup(
			ubigint modRefPlnrMMaterial
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblPlnrMMaterial WHERE modRefPlnrMMaterial = " + to_string(modRefPlnrMMaterial) + " ORDER BY sref ASC", append, refs);
};

ubigint MyTblPlnrMMaterial::loadRstBySup(
			ubigint modRefPlnrMMaterial
			, const bool append
			, ListPlnrMMaterial& rst
		) {
	return loadRstBySQL("SELECT ref, grp, own, ixVBasetype, refPlnrMCalc, modRefPlnrMMaterial, modLvl, sref, Title FROM TblPlnrMMaterial WHERE modRefPlnrMMaterial = " + to_string(modRefPlnrMMaterial) + " ORDER BY sref ASC", append, rst);
};

bool MyTblPlnrMMaterial::loadSupByRef(
			ubigint ref
			, ubigint& val
		) {
	return loadUbigintBySQL("SELECT modRefPlnrMMaterial FROM TblPlnrMMaterial WHERE ref = " + to_string(ref) + "", val);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrMMaterial
 ******************************************************************************/

PgTblPlnrMMaterial::PgTblPlnrMMaterial() : TblPlnrMMaterial(), PgTable() {
};

PgTblPlnrMMaterial::~PgTblPlnrMMaterial() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblPlnrMMaterial::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrMMaterial_insertRec", "INSERT INTO TblPlnrMMaterial (grp, own, ixVBasetype, refPlnrMCalc, modRefPlnrMMaterial, modLvl, sref, Title) VALUES ($1,$2,$3,$4,$5,$6,$7,$8) RETURNING ref", 8, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrMMaterial_updateRec", "UPDATE TblPlnrMMaterial SET grp = $1, own = $2, ixVBasetype = $3, refPlnrMCalc = $4, modRefPlnrMMaterial = $5, modLvl = $6, sref = $7, Title = $8 WHERE ref = $9", 9, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrMMaterial_removeRecByRef", "DELETE FROM TblPlnrMMaterial WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrMMaterial_loadRecByRef", "SELECT ref, grp, own, ixVBasetype, refPlnrMCalc, modRefPlnrMMaterial, modLvl, sref, Title FROM TblPlnrMMaterial WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblPlnrMMaterial_confirmByRef", "SELECT ref FROM TblPlnrMMaterial WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrMMaterial_loadRefBySupSrf", "SELECT ref FROM TblPlnrMMaterial WHERE modRefPlnrMMaterial = $1 AND sref = $2", 2, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrMMaterial_loadRefsBySup", "SELECT ref FROM TblPlnrMMaterial WHERE modRefPlnrMMaterial = $1 ORDER BY sref ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrMMaterial_loadRstBySup", "SELECT ref, grp, own, ixVBasetype, refPlnrMCalc, modRefPlnrMMaterial, modLvl, sref, Title FROM TblPlnrMMaterial WHERE modRefPlnrMMaterial = $1 ORDER BY sref ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrMMaterial_loadSupByRef", "SELECT modRefPlnrMMaterial FROM TblPlnrMMaterial WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrMMaterial::loadRec(
			PGresult* res
			, PlnrMMaterial** rec
		) {
	char* ptr;

	PlnrMMaterial* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrMMaterial();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "refplnrmcalc"),
			PQfnumber(res, "modrefplnrmmaterial"),
			PQfnumber(res, "modlvl"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "title")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->grp = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->own = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ixVBasetype = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->refPlnrMCalc = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->modRefPlnrMMaterial = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->modLvl = atoi(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[7]));
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[8]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrMMaterial::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrMMaterial& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrMMaterial* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "refplnrmcalc"),
			PQfnumber(res, "modrefplnrmmaterial"),
			PQfnumber(res, "modlvl"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "title")
		};

		while (numread < numrow) {
			rec = new PlnrMMaterial();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->grp = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->own = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ixVBasetype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->refPlnrMCalc = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->modRefPlnrMMaterial = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->modLvl = atoi(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[7]));
			ptr = PQgetvalue(res, numread, fnum[8]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[8]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrMMaterial::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrMMaterial** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMMaterial / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

// IP pgLoadRstByStmt --- BEGIN
ubigint PgTblPlnrMMaterial::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrMMaterial& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMMaterial / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};
// IP pgLoadRstByStmt --- END

bool PgTblPlnrMMaterial::loadRecBySQL(
			const string& sqlstr
			, PlnrMMaterial** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrMMaterial::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrMMaterial& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrMMaterial::insertRec(
			PlnrMMaterial* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	uint _ixVBasetype = htonl(rec->ixVBasetype);
	ubigint _refPlnrMCalc = htonl64(rec->refPlnrMCalc);
	ubigint _modRefPlnrMMaterial = htonl64(rec->modRefPlnrMMaterial);
	usmallint _modLvl = htons(rec->modLvl);

	const char* vals[] = {
		(char*) &_grp,
		(char*) &_own,
		(char*) &_ixVBasetype,
		(char*) &_refPlnrMCalc,
		(char*) &_modRefPlnrMMaterial,
		(char*) &_modLvl,
		rec->sref.c_str(),
		rec->Title.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(usmallint),
		0,
		0
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblPlnrMMaterial_insertRec", 8, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMMaterial_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblPlnrMMaterial::insertRst(
			ListPlnrMMaterial& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblPlnrMMaterial::updateRec(
			PlnrMMaterial* rec
		) {
	PGresult* res;

	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	uint _ixVBasetype = htonl(rec->ixVBasetype);
	ubigint _refPlnrMCalc = htonl64(rec->refPlnrMCalc);
	ubigint _modRefPlnrMMaterial = htonl64(rec->modRefPlnrMMaterial);
	usmallint _modLvl = htons(rec->modLvl);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_grp,
		(char*) &_own,
		(char*) &_ixVBasetype,
		(char*) &_refPlnrMCalc,
		(char*) &_modRefPlnrMMaterial,
		(char*) &_modLvl,
		rec->sref.c_str(),
		rec->Title.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(usmallint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblPlnrMMaterial_updateRec", 9, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMMaterial_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrMMaterial::updateRst(
			ListPlnrMMaterial& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblPlnrMMaterial::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblPlnrMMaterial_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMMaterial_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblPlnrMMaterial::loadRecByRef(
			ubigint ref
			, PlnrMMaterial** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrMMaterial_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblPlnrMMaterial::confirmByRef(
			ubigint ref
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadUbigintByStmt("TblPlnrMMaterial_confirmByRef", 1, vals, l, f, _ref);
};

bool PgTblPlnrMMaterial::loadRefBySupSrf(
			ubigint modRefPlnrMMaterial
			, string sref
			, ubigint& val
		) {
	ubigint _modRefPlnrMMaterial = htonl64(modRefPlnrMMaterial);

	const char* vals[] = {
		(char*) &_modRefPlnrMMaterial,
		sref.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		0
	};
	const int f[] = {1,0};

	return loadUbigintByStmt("TblPlnrMMaterial_loadRefBySupSrf", 2, vals, l, f, val);
};

ubigint PgTblPlnrMMaterial::loadRefsBySup(
			ubigint modRefPlnrMMaterial
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _modRefPlnrMMaterial = htonl64(modRefPlnrMMaterial);

	const char* vals[] = {
		(char*) &_modRefPlnrMMaterial
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblPlnrMMaterial_loadRefsBySup", 1, vals, l, f, append, refs);
};

ubigint PgTblPlnrMMaterial::loadRstBySup(
			ubigint modRefPlnrMMaterial
			, const bool append
			, ListPlnrMMaterial& rst
		) {
	ubigint _modRefPlnrMMaterial = htonl64(modRefPlnrMMaterial);

	const char* vals[] = {
		(char*) &_modRefPlnrMMaterial
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrMMaterial_loadRstBySup", 1, vals, l, f, append, rst);
};

bool PgTblPlnrMMaterial::loadSupByRef(
			ubigint ref
			, ubigint& val
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadUbigintByStmt("TblPlnrMMaterial_loadSupByRef", 1, vals, l, f, val);
};

// IP pgTbl --- END

