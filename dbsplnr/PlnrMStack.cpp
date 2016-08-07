/**
  * \file PlnrMStack.cpp
  * database access for table TblPlnrMStack (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrMStack.h"

/******************************************************************************
 class PlnrMStack
 ******************************************************************************/

PlnrMStack::PlnrMStack(
			const ubigint ref
			, const uint ixVBasetype
			, const ubigint dsnRefPlnrMDesign
			, const uint dsnNum
			, const string sref
			, const uint ixVModtype
			, const uint ixVFlrAligntype
			, const string flrSrefPlnrMLevel
			, const double zFlr
			, const uint ixVCeilAligntype
			, const string ceilSrefPlnrMLevel
			, const double zCeil
			, const string srefsPlnrMLayer
			, const string N
		) {

	this->ref = ref;
	this->ixVBasetype = ixVBasetype;
	this->dsnRefPlnrMDesign = dsnRefPlnrMDesign;
	this->dsnNum = dsnNum;
	this->sref = sref;
	this->ixVModtype = ixVModtype;
	this->ixVFlrAligntype = ixVFlrAligntype;
	this->flrSrefPlnrMLevel = flrSrefPlnrMLevel;
	this->zFlr = zFlr;
	this->ixVCeilAligntype = ixVCeilAligntype;
	this->ceilSrefPlnrMLevel = ceilSrefPlnrMLevel;
	this->zCeil = zCeil;
	this->srefsPlnrMLayer = srefsPlnrMLayer;
	this->N = N;
};

bool PlnrMStack::operator==(
			const PlnrMStack& comp
		) {
	return false;
};

bool PlnrMStack::operator!=(
			const PlnrMStack& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListPlnrMStack
 ******************************************************************************/

ListPlnrMStack::ListPlnrMStack() {
};

ListPlnrMStack::ListPlnrMStack(
			const ListPlnrMStack& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrMStack(*(src.nodes[i]));
};

ListPlnrMStack::~ListPlnrMStack() {
	clear();
};

void ListPlnrMStack::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrMStack::size() const {
	return(nodes.size());
};

void ListPlnrMStack::append(
			PlnrMStack* rec
		) {
	nodes.push_back(rec);
};

PlnrMStack* ListPlnrMStack::operator[](
			const uint ix
		) {
	PlnrMStack* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListPlnrMStack& ListPlnrMStack::operator=(
			const ListPlnrMStack& src
		) {
	PlnrMStack* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrMStack(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListPlnrMStack::operator==(
			const ListPlnrMStack& comp
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

bool ListPlnrMStack::operator!=(
			const ListPlnrMStack& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblPlnrMStack
 ******************************************************************************/

TblPlnrMStack::TblPlnrMStack() {
};

TblPlnrMStack::~TblPlnrMStack() {
};

bool TblPlnrMStack::loadRecBySQL(
			const string& sqlstr
			, PlnrMStack** rec
		) {
	return false;
};

ubigint TblPlnrMStack::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrMStack& rst
		) {
	return 0;
};

void TblPlnrMStack::insertRec(
			PlnrMStack* rec
		) {
};

ubigint TblPlnrMStack::insertNewRec(
			PlnrMStack** rec
			, const uint ixVBasetype
			, const ubigint dsnRefPlnrMDesign
			, const uint dsnNum
			, const string sref
			, const uint ixVModtype
			, const uint ixVFlrAligntype
			, const string flrSrefPlnrMLevel
			, const double zFlr
			, const uint ixVCeilAligntype
			, const string ceilSrefPlnrMLevel
			, const double zCeil
			, const string srefsPlnrMLayer
			, const string N
		) {
	ubigint retval = 0;
	PlnrMStack* _rec = NULL;

	_rec = new PlnrMStack(0, ixVBasetype, dsnRefPlnrMDesign, dsnNum, sref, ixVModtype, ixVFlrAligntype, flrSrefPlnrMLevel, zFlr, ixVCeilAligntype, ceilSrefPlnrMLevel, zCeil, srefsPlnrMLayer, N);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrMStack::appendNewRecToRst(
			ListPlnrMStack& rst
			, PlnrMStack** rec
			, const uint ixVBasetype
			, const ubigint dsnRefPlnrMDesign
			, const uint dsnNum
			, const string sref
			, const uint ixVModtype
			, const uint ixVFlrAligntype
			, const string flrSrefPlnrMLevel
			, const double zFlr
			, const uint ixVCeilAligntype
			, const string ceilSrefPlnrMLevel
			, const double zCeil
			, const string srefsPlnrMLayer
			, const string N
		) {
	ubigint retval = 0;
	PlnrMStack* _rec = NULL;

	retval = insertNewRec(&_rec, ixVBasetype, dsnRefPlnrMDesign, dsnNum, sref, ixVModtype, ixVFlrAligntype, flrSrefPlnrMLevel, zFlr, ixVCeilAligntype, ceilSrefPlnrMLevel, zCeil, srefsPlnrMLayer, N);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrMStack::insertRst(
			ListPlnrMStack& rst
			, bool transact
		) {
};

void TblPlnrMStack::updateRec(
			PlnrMStack* rec
		) {
};

void TblPlnrMStack::updateRst(
			ListPlnrMStack& rst
			, bool transact
		) {
};

void TblPlnrMStack::removeRecByRef(
			ubigint ref
		) {
};

bool TblPlnrMStack::loadRecByRef(
			ubigint ref
			, PlnrMStack** rec
		) {
	return false;
};

ubigint TblPlnrMStack::loadRstByDsn(
			ubigint dsnRefPlnrMDesign
			, const bool append
			, ListPlnrMStack& rst
		) {
	return 0;
};

bool TblPlnrMStack::loadSrfByRef(
			ubigint ref
			, string& val
		) {
	return false;
};

ubigint TblPlnrMStack::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListPlnrMStack& rst
		) {
	ubigint numload = 0;
	PlnrMStack* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrMStack
 ******************************************************************************/

MyTblPlnrMStack::MyTblPlnrMStack() : TblPlnrMStack(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblPlnrMStack::~MyTblPlnrMStack() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblPlnrMStack::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrMStack (ixVBasetype, dsnRefPlnrMDesign, dsnNum, sref, ixVModtype, ixVFlrAligntype, flrSrefPlnrMLevel, zFlr, ixVCeilAligntype, ceilSrefPlnrMLevel, zCeil, srefsPlnrMLayer, N) VALUES (?,?,?,?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrMStack SET ixVBasetype = ?, dsnRefPlnrMDesign = ?, dsnNum = ?, sref = ?, ixVModtype = ?, ixVFlrAligntype = ?, flrSrefPlnrMLevel = ?, zFlr = ?, ixVCeilAligntype = ?, ceilSrefPlnrMLevel = ?, zCeil = ?, srefsPlnrMLayer = ?, N = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblPlnrMStack WHERE ref = ?", false);
};

bool MyTblPlnrMStack::loadRecBySQL(
			const string& sqlstr
			, PlnrMStack** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrMStack* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrMStack / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrMStack();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->ixVBasetype = atol((char*) dbrow[1]); else _rec->ixVBasetype = 0;
		if (dbrow[2]) _rec->dsnRefPlnrMDesign = atoll((char*) dbrow[2]); else _rec->dsnRefPlnrMDesign = 0;
		if (dbrow[3]) _rec->dsnNum = atol((char*) dbrow[3]); else _rec->dsnNum = 0;
		if (dbrow[4]) _rec->sref.assign(dbrow[4], dblengths[4]); else _rec->sref = "";
		if (dbrow[5]) _rec->ixVModtype = atol((char*) dbrow[5]); else _rec->ixVModtype = 0;
		if (dbrow[6]) _rec->ixVFlrAligntype = atol((char*) dbrow[6]); else _rec->ixVFlrAligntype = 0;
		if (dbrow[7]) _rec->flrSrefPlnrMLevel.assign(dbrow[7], dblengths[7]); else _rec->flrSrefPlnrMLevel = "";
		if (dbrow[8]) _rec->zFlr = atof((char*) dbrow[8]); else _rec->zFlr = 0.0;
		if (dbrow[9]) _rec->ixVCeilAligntype = atol((char*) dbrow[9]); else _rec->ixVCeilAligntype = 0;
		if (dbrow[10]) _rec->ceilSrefPlnrMLevel.assign(dbrow[10], dblengths[10]); else _rec->ceilSrefPlnrMLevel = "";
		if (dbrow[11]) _rec->zCeil = atof((char*) dbrow[11]); else _rec->zCeil = 0.0;
		if (dbrow[12]) _rec->srefsPlnrMLayer.assign(dbrow[12], dblengths[12]); else _rec->srefsPlnrMLayer = "";
		if (dbrow[13]) _rec->N.assign(dbrow[13], dblengths[13]); else _rec->N = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrMStack::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrMStack& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrMStack* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrMStack / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrMStack();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->ixVBasetype = atol((char*) dbrow[1]); else rec->ixVBasetype = 0;
			if (dbrow[2]) rec->dsnRefPlnrMDesign = atoll((char*) dbrow[2]); else rec->dsnRefPlnrMDesign = 0;
			if (dbrow[3]) rec->dsnNum = atol((char*) dbrow[3]); else rec->dsnNum = 0;
			if (dbrow[4]) rec->sref.assign(dbrow[4], dblengths[4]); else rec->sref = "";
			if (dbrow[5]) rec->ixVModtype = atol((char*) dbrow[5]); else rec->ixVModtype = 0;
			if (dbrow[6]) rec->ixVFlrAligntype = atol((char*) dbrow[6]); else rec->ixVFlrAligntype = 0;
			if (dbrow[7]) rec->flrSrefPlnrMLevel.assign(dbrow[7], dblengths[7]); else rec->flrSrefPlnrMLevel = "";
			if (dbrow[8]) rec->zFlr = atof((char*) dbrow[8]); else rec->zFlr = 0.0;
			if (dbrow[9]) rec->ixVCeilAligntype = atol((char*) dbrow[9]); else rec->ixVCeilAligntype = 0;
			if (dbrow[10]) rec->ceilSrefPlnrMLevel.assign(dbrow[10], dblengths[10]); else rec->ceilSrefPlnrMLevel = "";
			if (dbrow[11]) rec->zCeil = atof((char*) dbrow[11]); else rec->zCeil = 0.0;
			if (dbrow[12]) rec->srefsPlnrMLayer.assign(dbrow[12], dblengths[12]); else rec->srefsPlnrMLayer = "";
			if (dbrow[13]) rec->N.assign(dbrow[13], dblengths[13]); else rec->N = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrMStack::insertRec(
			PlnrMStack* rec
		) {
	unsigned long l[13]; my_bool n[13]; my_bool e[13];

	l[3] = rec->sref.length();
	l[6] = rec->flrSrefPlnrMLevel.length();
	l[9] = rec->ceilSrefPlnrMLevel.length();
	l[11] = rec->srefsPlnrMLayer.length();
	l[12] = rec->N.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->ixVBasetype,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->dsnRefPlnrMDesign,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->dsnNum,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->ixVModtype,&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->ixVFlrAligntype,&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->flrSrefPlnrMLevel.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindDouble(&rec->zFlr,&(l[7]),&(n[7]),&(e[7])),
		bindUint(&rec->ixVCeilAligntype,&(l[8]),&(n[8]),&(e[8])),
		bindCstring((char*) (rec->ceilSrefPlnrMLevel.c_str()),&(l[9]),&(n[9]),&(e[9])),
		bindDouble(&rec->zCeil,&(l[10]),&(n[10]),&(e[10])),
		bindCstring((char*) (rec->srefsPlnrMLayer.c_str()),&(l[11]),&(n[11]),&(e[11])),
		bindCstring((char*) (rec->N.c_str()),&(l[12]),&(n[12]),&(e[12]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrMStack / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrMStack / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblPlnrMStack::insertRst(
			ListPlnrMStack& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblPlnrMStack::updateRec(
			PlnrMStack* rec
		) {
	unsigned long l[14]; my_bool n[14]; my_bool e[14];

	l[3] = rec->sref.length();
	l[6] = rec->flrSrefPlnrMLevel.length();
	l[9] = rec->ceilSrefPlnrMLevel.length();
	l[11] = rec->srefsPlnrMLayer.length();
	l[12] = rec->N.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->ixVBasetype,&(l[0]),&(n[0]),&(e[0])), 
		bindUbigint(&rec->dsnRefPlnrMDesign,&(l[1]),&(n[1]),&(e[1])), 
		bindUint(&rec->dsnNum,&(l[2]),&(n[2]),&(e[2])), 
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])), 
		bindUint(&rec->ixVModtype,&(l[4]),&(n[4]),&(e[4])), 
		bindUint(&rec->ixVFlrAligntype,&(l[5]),&(n[5]),&(e[5])), 
		bindCstring((char*) (rec->flrSrefPlnrMLevel.c_str()),&(l[6]),&(n[6]),&(e[6])), 
		bindDouble(&rec->zFlr,&(l[7]),&(n[7]),&(e[7])), 
		bindUint(&rec->ixVCeilAligntype,&(l[8]),&(n[8]),&(e[8])), 
		bindCstring((char*) (rec->ceilSrefPlnrMLevel.c_str()),&(l[9]),&(n[9]),&(e[9])), 
		bindDouble(&rec->zCeil,&(l[10]),&(n[10]),&(e[10])), 
		bindCstring((char*) (rec->srefsPlnrMLayer.c_str()),&(l[11]),&(n[11]),&(e[11])), 
		bindCstring((char*) (rec->N.c_str()),&(l[12]),&(n[12]),&(e[12])), 
		bindUbigint(&rec->ref,&(l[13]),&(n[13]),&(e[13]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrMStack / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrMStack / stmtUpdateRec)\n");
};

void MyTblPlnrMStack::updateRst(
			ListPlnrMStack& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblPlnrMStack::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrMStack / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrMStack / stmtRemoveRecByRef)\n");
};

bool MyTblPlnrMStack::loadRecByRef(
			ubigint ref
			, PlnrMStack** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrMStack WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblPlnrMStack::loadRstByDsn(
			ubigint dsnRefPlnrMDesign
			, const bool append
			, ListPlnrMStack& rst
		) {
	return loadRstBySQL("SELECT ref, ixVBasetype, dsnRefPlnrMDesign, dsnNum, sref, ixVModtype, ixVFlrAligntype, flrSrefPlnrMLevel, zFlr, ixVCeilAligntype, ceilSrefPlnrMLevel, zCeil, srefsPlnrMLayer, N FROM TblPlnrMStack WHERE dsnRefPlnrMDesign = " + to_string(dsnRefPlnrMDesign) + " ORDER BY dsnNum ASC", append, rst);
};

bool MyTblPlnrMStack::loadSrfByRef(
			ubigint ref
			, string& val
		) {
	return loadStringBySQL("SELECT sref FROM TblPlnrMStack WHERE ref = " + to_string(ref) + "", val);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrMStack
 ******************************************************************************/

PgTblPlnrMStack::PgTblPlnrMStack() : TblPlnrMStack(), PgTable() {
};

PgTblPlnrMStack::~PgTblPlnrMStack() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblPlnrMStack::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrMStack_insertRec", "INSERT INTO TblPlnrMStack (ixVBasetype, dsnRefPlnrMDesign, dsnNum, sref, ixVModtype, ixVFlrAligntype, flrSrefPlnrMLevel, zFlr, ixVCeilAligntype, ceilSrefPlnrMLevel, zCeil, srefsPlnrMLayer, N) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11,$12,$13) RETURNING ref", 13, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrMStack_updateRec", "UPDATE TblPlnrMStack SET ixVBasetype = $1, dsnRefPlnrMDesign = $2, dsnNum = $3, sref = $4, ixVModtype = $5, ixVFlrAligntype = $6, flrSrefPlnrMLevel = $7, zFlr = $8, ixVCeilAligntype = $9, ceilSrefPlnrMLevel = $10, zCeil = $11, srefsPlnrMLayer = $12, N = $13 WHERE ref = $14", 14, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrMStack_removeRecByRef", "DELETE FROM TblPlnrMStack WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrMStack_loadRecByRef", "SELECT ref, ixVBasetype, dsnRefPlnrMDesign, dsnNum, sref, ixVModtype, ixVFlrAligntype, flrSrefPlnrMLevel, zFlr, ixVCeilAligntype, ceilSrefPlnrMLevel, zCeil, srefsPlnrMLayer, N FROM TblPlnrMStack WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblPlnrMStack_loadRstByDsn", "SELECT ref, ixVBasetype, dsnRefPlnrMDesign, dsnNum, sref, ixVModtype, ixVFlrAligntype, flrSrefPlnrMLevel, zFlr, ixVCeilAligntype, ceilSrefPlnrMLevel, zCeil, srefsPlnrMLayer, N FROM TblPlnrMStack WHERE dsnRefPlnrMDesign = $1 ORDER BY dsnNum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrMStack_loadSrfByRef", "SELECT sref FROM TblPlnrMStack WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrMStack::loadRec(
			PGresult* res
			, PlnrMStack** rec
		) {
	char* ptr;

	PlnrMStack* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrMStack();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "dsnrefplnrmdesign"),
			PQfnumber(res, "dsnnum"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "ixvmodtype"),
			PQfnumber(res, "ixvflraligntype"),
			PQfnumber(res, "flrsrefplnrmlevel"),
			PQfnumber(res, "zflr"),
			PQfnumber(res, "ixvceilaligntype"),
			PQfnumber(res, "ceilsrefplnrmlevel"),
			PQfnumber(res, "zceil"),
			PQfnumber(res, "srefsplnrmlayer"),
			PQfnumber(res, "n")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->ixVBasetype = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->dsnRefPlnrMDesign = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->dsnNum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->ixVModtype = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->ixVFlrAligntype = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->flrSrefPlnrMLevel.assign(ptr, PQgetlength(res, 0, fnum[7]));
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->zFlr = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->ixVCeilAligntype = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->ceilSrefPlnrMLevel.assign(ptr, PQgetlength(res, 0, fnum[10]));
		ptr = PQgetvalue(res, 0, fnum[11]); _rec->zCeil = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[12]); _rec->srefsPlnrMLayer.assign(ptr, PQgetlength(res, 0, fnum[12]));
		ptr = PQgetvalue(res, 0, fnum[13]); _rec->N.assign(ptr, PQgetlength(res, 0, fnum[13]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrMStack::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrMStack& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrMStack* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "dsnrefplnrmdesign"),
			PQfnumber(res, "dsnnum"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "ixvmodtype"),
			PQfnumber(res, "ixvflraligntype"),
			PQfnumber(res, "flrsrefplnrmlevel"),
			PQfnumber(res, "zflr"),
			PQfnumber(res, "ixvceilaligntype"),
			PQfnumber(res, "ceilsrefplnrmlevel"),
			PQfnumber(res, "zceil"),
			PQfnumber(res, "srefsplnrmlayer"),
			PQfnumber(res, "n")
		};

		while (numread < numrow) {
			rec = new PlnrMStack();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->ixVBasetype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->dsnRefPlnrMDesign = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->dsnNum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->ixVModtype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->ixVFlrAligntype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->flrSrefPlnrMLevel.assign(ptr, PQgetlength(res, numread, fnum[7]));
			ptr = PQgetvalue(res, numread, fnum[8]); rec->zFlr = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->ixVCeilAligntype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[10]); rec->ceilSrefPlnrMLevel.assign(ptr, PQgetlength(res, numread, fnum[10]));
			ptr = PQgetvalue(res, numread, fnum[11]); rec->zCeil = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[12]); rec->srefsPlnrMLayer.assign(ptr, PQgetlength(res, numread, fnum[12]));
			ptr = PQgetvalue(res, numread, fnum[13]); rec->N.assign(ptr, PQgetlength(res, numread, fnum[13]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrMStack::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrMStack** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMStack / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

// IP pgLoadRstByStmt --- BEGIN
ubigint PgTblPlnrMStack::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrMStack& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMStack / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};
// IP pgLoadRstByStmt --- END

bool PgTblPlnrMStack::loadRecBySQL(
			const string& sqlstr
			, PlnrMStack** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrMStack::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrMStack& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrMStack::insertRec(
			PlnrMStack* rec
		) {
	PGresult* res;
	char* ptr;

	uint _ixVBasetype = htonl(rec->ixVBasetype);
	ubigint _dsnRefPlnrMDesign = htonl64(rec->dsnRefPlnrMDesign);
	uint _dsnNum = htonl(rec->dsnNum);
	uint _ixVModtype = htonl(rec->ixVModtype);
	uint _ixVFlrAligntype = htonl(rec->ixVFlrAligntype);
	string _zFlr = to_string(rec->zFlr);
	uint _ixVCeilAligntype = htonl(rec->ixVCeilAligntype);
	string _zCeil = to_string(rec->zCeil);

	const char* vals[] = {
		(char*) &_ixVBasetype,
		(char*) &_dsnRefPlnrMDesign,
		(char*) &_dsnNum,
		rec->sref.c_str(),
		(char*) &_ixVModtype,
		(char*) &_ixVFlrAligntype,
		rec->flrSrefPlnrMLevel.c_str(),
		_zFlr.c_str(),
		(char*) &_ixVCeilAligntype,
		rec->ceilSrefPlnrMLevel.c_str(),
		_zCeil.c_str(),
		rec->srefsPlnrMLayer.c_str(),
		rec->N.c_str()
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		0,
		sizeof(uint),
		sizeof(uint),
		0,
		0,
		sizeof(uint),
		0,
		0,
		0,
		0
	};
	const int f[] = {1, 1, 1, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0};

	res = PQexecPrepared(dbs, "TblPlnrMStack_insertRec", 13, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMStack_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblPlnrMStack::insertRst(
			ListPlnrMStack& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblPlnrMStack::updateRec(
			PlnrMStack* rec
		) {
	PGresult* res;

	uint _ixVBasetype = htonl(rec->ixVBasetype);
	ubigint _dsnRefPlnrMDesign = htonl64(rec->dsnRefPlnrMDesign);
	uint _dsnNum = htonl(rec->dsnNum);
	uint _ixVModtype = htonl(rec->ixVModtype);
	uint _ixVFlrAligntype = htonl(rec->ixVFlrAligntype);
	string _zFlr = to_string(rec->zFlr);
	uint _ixVCeilAligntype = htonl(rec->ixVCeilAligntype);
	string _zCeil = to_string(rec->zCeil);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_ixVBasetype,
		(char*) &_dsnRefPlnrMDesign,
		(char*) &_dsnNum,
		rec->sref.c_str(),
		(char*) &_ixVModtype,
		(char*) &_ixVFlrAligntype,
		rec->flrSrefPlnrMLevel.c_str(),
		_zFlr.c_str(),
		(char*) &_ixVCeilAligntype,
		rec->ceilSrefPlnrMLevel.c_str(),
		_zCeil.c_str(),
		rec->srefsPlnrMLayer.c_str(),
		rec->N.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		0,
		sizeof(uint),
		sizeof(uint),
		0,
		0,
		sizeof(uint),
		0,
		0,
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblPlnrMStack_updateRec", 14, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMStack_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrMStack::updateRst(
			ListPlnrMStack& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblPlnrMStack::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblPlnrMStack_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMStack_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblPlnrMStack::loadRecByRef(
			ubigint ref
			, PlnrMStack** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrMStack_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblPlnrMStack::loadRstByDsn(
			ubigint dsnRefPlnrMDesign
			, const bool append
			, ListPlnrMStack& rst
		) {
	ubigint _dsnRefPlnrMDesign = htonl64(dsnRefPlnrMDesign);

	const char* vals[] = {
		(char*) &_dsnRefPlnrMDesign
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrMStack_loadRstByDsn", 1, vals, l, f, append, rst);
};

bool PgTblPlnrMStack::loadSrfByRef(
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

	return loadStringByStmt("TblPlnrMStack_loadSrfByRef", 1, vals, l, f, val);
};

// IP pgTbl --- END

