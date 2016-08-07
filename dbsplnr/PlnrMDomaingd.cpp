/**
  * \file PlnrMDomaingd.cpp
  * database access for table TblPlnrMDomaingd (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrMDomaingd.h"

/******************************************************************************
 class PlnrMDomaingd
 ******************************************************************************/

PlnrMDomaingd::PlnrMDomaingd(
			const ubigint ref
			, const uint ixVBasetype
			, const ubigint dsnRefPlnrMDesign
			, const uint dsnNum
			, const string sref
			, const string srefPlnrMLevel
			, const string av1SrefPlnrMVertex
			, const string av2SrefPlnrMVertex
			, const string al1SrefPlnrMLineguide
			, const string al2SrefPlnrMLineguide
			, const string srefPlnrMArcguide
			, const string d
			, const string dphi
		) {

	this->ref = ref;
	this->ixVBasetype = ixVBasetype;
	this->dsnRefPlnrMDesign = dsnRefPlnrMDesign;
	this->dsnNum = dsnNum;
	this->sref = sref;
	this->srefPlnrMLevel = srefPlnrMLevel;
	this->av1SrefPlnrMVertex = av1SrefPlnrMVertex;
	this->av2SrefPlnrMVertex = av2SrefPlnrMVertex;
	this->al1SrefPlnrMLineguide = al1SrefPlnrMLineguide;
	this->al2SrefPlnrMLineguide = al2SrefPlnrMLineguide;
	this->srefPlnrMArcguide = srefPlnrMArcguide;
	this->d = d;
	this->dphi = dphi;
};

bool PlnrMDomaingd::operator==(
			const PlnrMDomaingd& comp
		) {
	return false;
};

bool PlnrMDomaingd::operator!=(
			const PlnrMDomaingd& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListPlnrMDomaingd
 ******************************************************************************/

ListPlnrMDomaingd::ListPlnrMDomaingd() {
};

ListPlnrMDomaingd::ListPlnrMDomaingd(
			const ListPlnrMDomaingd& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrMDomaingd(*(src.nodes[i]));
};

ListPlnrMDomaingd::~ListPlnrMDomaingd() {
	clear();
};

void ListPlnrMDomaingd::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrMDomaingd::size() const {
	return(nodes.size());
};

void ListPlnrMDomaingd::append(
			PlnrMDomaingd* rec
		) {
	nodes.push_back(rec);
};

PlnrMDomaingd* ListPlnrMDomaingd::operator[](
			const uint ix
		) {
	PlnrMDomaingd* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListPlnrMDomaingd& ListPlnrMDomaingd::operator=(
			const ListPlnrMDomaingd& src
		) {
	PlnrMDomaingd* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrMDomaingd(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListPlnrMDomaingd::operator==(
			const ListPlnrMDomaingd& comp
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

bool ListPlnrMDomaingd::operator!=(
			const ListPlnrMDomaingd& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblPlnrMDomaingd
 ******************************************************************************/

TblPlnrMDomaingd::TblPlnrMDomaingd() {
};

TblPlnrMDomaingd::~TblPlnrMDomaingd() {
};

bool TblPlnrMDomaingd::loadRecBySQL(
			const string& sqlstr
			, PlnrMDomaingd** rec
		) {
	return false;
};

ubigint TblPlnrMDomaingd::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrMDomaingd& rst
		) {
	return 0;
};

void TblPlnrMDomaingd::insertRec(
			PlnrMDomaingd* rec
		) {
};

ubigint TblPlnrMDomaingd::insertNewRec(
			PlnrMDomaingd** rec
			, const uint ixVBasetype
			, const ubigint dsnRefPlnrMDesign
			, const uint dsnNum
			, const string sref
			, const string srefPlnrMLevel
			, const string av1SrefPlnrMVertex
			, const string av2SrefPlnrMVertex
			, const string al1SrefPlnrMLineguide
			, const string al2SrefPlnrMLineguide
			, const string srefPlnrMArcguide
			, const string d
			, const string dphi
		) {
	ubigint retval = 0;
	PlnrMDomaingd* _rec = NULL;

	_rec = new PlnrMDomaingd(0, ixVBasetype, dsnRefPlnrMDesign, dsnNum, sref, srefPlnrMLevel, av1SrefPlnrMVertex, av2SrefPlnrMVertex, al1SrefPlnrMLineguide, al2SrefPlnrMLineguide, srefPlnrMArcguide, d, dphi);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrMDomaingd::appendNewRecToRst(
			ListPlnrMDomaingd& rst
			, PlnrMDomaingd** rec
			, const uint ixVBasetype
			, const ubigint dsnRefPlnrMDesign
			, const uint dsnNum
			, const string sref
			, const string srefPlnrMLevel
			, const string av1SrefPlnrMVertex
			, const string av2SrefPlnrMVertex
			, const string al1SrefPlnrMLineguide
			, const string al2SrefPlnrMLineguide
			, const string srefPlnrMArcguide
			, const string d
			, const string dphi
		) {
	ubigint retval = 0;
	PlnrMDomaingd* _rec = NULL;

	retval = insertNewRec(&_rec, ixVBasetype, dsnRefPlnrMDesign, dsnNum, sref, srefPlnrMLevel, av1SrefPlnrMVertex, av2SrefPlnrMVertex, al1SrefPlnrMLineguide, al2SrefPlnrMLineguide, srefPlnrMArcguide, d, dphi);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrMDomaingd::insertRst(
			ListPlnrMDomaingd& rst
			, bool transact
		) {
};

void TblPlnrMDomaingd::updateRec(
			PlnrMDomaingd* rec
		) {
};

void TblPlnrMDomaingd::updateRst(
			ListPlnrMDomaingd& rst
			, bool transact
		) {
};

void TblPlnrMDomaingd::removeRecByRef(
			ubigint ref
		) {
};

bool TblPlnrMDomaingd::loadRecByRef(
			ubigint ref
			, PlnrMDomaingd** rec
		) {
	return false;
};

ubigint TblPlnrMDomaingd::loadRstByDsn(
			ubigint dsnRefPlnrMDesign
			, const bool append
			, ListPlnrMDomaingd& rst
		) {
	return 0;
};

ubigint TblPlnrMDomaingd::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListPlnrMDomaingd& rst
		) {
	ubigint numload = 0;
	PlnrMDomaingd* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrMDomaingd
 ******************************************************************************/

MyTblPlnrMDomaingd::MyTblPlnrMDomaingd() : TblPlnrMDomaingd(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblPlnrMDomaingd::~MyTblPlnrMDomaingd() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblPlnrMDomaingd::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrMDomaingd (ixVBasetype, dsnRefPlnrMDesign, dsnNum, sref, srefPlnrMLevel, av1SrefPlnrMVertex, av2SrefPlnrMVertex, al1SrefPlnrMLineguide, al2SrefPlnrMLineguide, srefPlnrMArcguide, d, dphi) VALUES (?,?,?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrMDomaingd SET ixVBasetype = ?, dsnRefPlnrMDesign = ?, dsnNum = ?, sref = ?, srefPlnrMLevel = ?, av1SrefPlnrMVertex = ?, av2SrefPlnrMVertex = ?, al1SrefPlnrMLineguide = ?, al2SrefPlnrMLineguide = ?, srefPlnrMArcguide = ?, d = ?, dphi = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblPlnrMDomaingd WHERE ref = ?", false);
};

bool MyTblPlnrMDomaingd::loadRecBySQL(
			const string& sqlstr
			, PlnrMDomaingd** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrMDomaingd* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrMDomaingd / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrMDomaingd();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->ixVBasetype = atol((char*) dbrow[1]); else _rec->ixVBasetype = 0;
		if (dbrow[2]) _rec->dsnRefPlnrMDesign = atoll((char*) dbrow[2]); else _rec->dsnRefPlnrMDesign = 0;
		if (dbrow[3]) _rec->dsnNum = atol((char*) dbrow[3]); else _rec->dsnNum = 0;
		if (dbrow[4]) _rec->sref.assign(dbrow[4], dblengths[4]); else _rec->sref = "";
		if (dbrow[5]) _rec->srefPlnrMLevel.assign(dbrow[5], dblengths[5]); else _rec->srefPlnrMLevel = "";
		if (dbrow[6]) _rec->av1SrefPlnrMVertex.assign(dbrow[6], dblengths[6]); else _rec->av1SrefPlnrMVertex = "";
		if (dbrow[7]) _rec->av2SrefPlnrMVertex.assign(dbrow[7], dblengths[7]); else _rec->av2SrefPlnrMVertex = "";
		if (dbrow[8]) _rec->al1SrefPlnrMLineguide.assign(dbrow[8], dblengths[8]); else _rec->al1SrefPlnrMLineguide = "";
		if (dbrow[9]) _rec->al2SrefPlnrMLineguide.assign(dbrow[9], dblengths[9]); else _rec->al2SrefPlnrMLineguide = "";
		if (dbrow[10]) _rec->srefPlnrMArcguide.assign(dbrow[10], dblengths[10]); else _rec->srefPlnrMArcguide = "";
		if (dbrow[11]) _rec->d.assign(dbrow[11], dblengths[11]); else _rec->d = "";
		if (dbrow[12]) _rec->dphi.assign(dbrow[12], dblengths[12]); else _rec->dphi = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrMDomaingd::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrMDomaingd& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrMDomaingd* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrMDomaingd / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrMDomaingd();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->ixVBasetype = atol((char*) dbrow[1]); else rec->ixVBasetype = 0;
			if (dbrow[2]) rec->dsnRefPlnrMDesign = atoll((char*) dbrow[2]); else rec->dsnRefPlnrMDesign = 0;
			if (dbrow[3]) rec->dsnNum = atol((char*) dbrow[3]); else rec->dsnNum = 0;
			if (dbrow[4]) rec->sref.assign(dbrow[4], dblengths[4]); else rec->sref = "";
			if (dbrow[5]) rec->srefPlnrMLevel.assign(dbrow[5], dblengths[5]); else rec->srefPlnrMLevel = "";
			if (dbrow[6]) rec->av1SrefPlnrMVertex.assign(dbrow[6], dblengths[6]); else rec->av1SrefPlnrMVertex = "";
			if (dbrow[7]) rec->av2SrefPlnrMVertex.assign(dbrow[7], dblengths[7]); else rec->av2SrefPlnrMVertex = "";
			if (dbrow[8]) rec->al1SrefPlnrMLineguide.assign(dbrow[8], dblengths[8]); else rec->al1SrefPlnrMLineguide = "";
			if (dbrow[9]) rec->al2SrefPlnrMLineguide.assign(dbrow[9], dblengths[9]); else rec->al2SrefPlnrMLineguide = "";
			if (dbrow[10]) rec->srefPlnrMArcguide.assign(dbrow[10], dblengths[10]); else rec->srefPlnrMArcguide = "";
			if (dbrow[11]) rec->d.assign(dbrow[11], dblengths[11]); else rec->d = "";
			if (dbrow[12]) rec->dphi.assign(dbrow[12], dblengths[12]); else rec->dphi = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrMDomaingd::insertRec(
			PlnrMDomaingd* rec
		) {
	unsigned long l[12]; my_bool n[12]; my_bool e[12];

	l[3] = rec->sref.length();
	l[4] = rec->srefPlnrMLevel.length();
	l[5] = rec->av1SrefPlnrMVertex.length();
	l[6] = rec->av2SrefPlnrMVertex.length();
	l[7] = rec->al1SrefPlnrMLineguide.length();
	l[8] = rec->al2SrefPlnrMLineguide.length();
	l[9] = rec->srefPlnrMArcguide.length();
	l[10] = rec->d.length();
	l[11] = rec->dphi.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->ixVBasetype,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->dsnRefPlnrMDesign,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->dsnNum,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->srefPlnrMLevel.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->av1SrefPlnrMVertex.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->av2SrefPlnrMVertex.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->al1SrefPlnrMLineguide.c_str()),&(l[7]),&(n[7]),&(e[7])),
		bindCstring((char*) (rec->al2SrefPlnrMLineguide.c_str()),&(l[8]),&(n[8]),&(e[8])),
		bindCstring((char*) (rec->srefPlnrMArcguide.c_str()),&(l[9]),&(n[9]),&(e[9])),
		bindCstring((char*) (rec->d.c_str()),&(l[10]),&(n[10]),&(e[10])),
		bindCstring((char*) (rec->dphi.c_str()),&(l[11]),&(n[11]),&(e[11]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrMDomaingd / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrMDomaingd / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblPlnrMDomaingd::insertRst(
			ListPlnrMDomaingd& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblPlnrMDomaingd::updateRec(
			PlnrMDomaingd* rec
		) {
	unsigned long l[13]; my_bool n[13]; my_bool e[13];

	l[3] = rec->sref.length();
	l[4] = rec->srefPlnrMLevel.length();
	l[5] = rec->av1SrefPlnrMVertex.length();
	l[6] = rec->av2SrefPlnrMVertex.length();
	l[7] = rec->al1SrefPlnrMLineguide.length();
	l[8] = rec->al2SrefPlnrMLineguide.length();
	l[9] = rec->srefPlnrMArcguide.length();
	l[10] = rec->d.length();
	l[11] = rec->dphi.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->ixVBasetype,&(l[0]),&(n[0]),&(e[0])), 
		bindUbigint(&rec->dsnRefPlnrMDesign,&(l[1]),&(n[1]),&(e[1])), 
		bindUint(&rec->dsnNum,&(l[2]),&(n[2]),&(e[2])), 
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])), 
		bindCstring((char*) (rec->srefPlnrMLevel.c_str()),&(l[4]),&(n[4]),&(e[4])), 
		bindCstring((char*) (rec->av1SrefPlnrMVertex.c_str()),&(l[5]),&(n[5]),&(e[5])), 
		bindCstring((char*) (rec->av2SrefPlnrMVertex.c_str()),&(l[6]),&(n[6]),&(e[6])), 
		bindCstring((char*) (rec->al1SrefPlnrMLineguide.c_str()),&(l[7]),&(n[7]),&(e[7])), 
		bindCstring((char*) (rec->al2SrefPlnrMLineguide.c_str()),&(l[8]),&(n[8]),&(e[8])), 
		bindCstring((char*) (rec->srefPlnrMArcguide.c_str()),&(l[9]),&(n[9]),&(e[9])), 
		bindCstring((char*) (rec->d.c_str()),&(l[10]),&(n[10]),&(e[10])), 
		bindCstring((char*) (rec->dphi.c_str()),&(l[11]),&(n[11]),&(e[11])), 
		bindUbigint(&rec->ref,&(l[12]),&(n[12]),&(e[12]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrMDomaingd / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrMDomaingd / stmtUpdateRec)\n");
};

void MyTblPlnrMDomaingd::updateRst(
			ListPlnrMDomaingd& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblPlnrMDomaingd::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrMDomaingd / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrMDomaingd / stmtRemoveRecByRef)\n");
};

bool MyTblPlnrMDomaingd::loadRecByRef(
			ubigint ref
			, PlnrMDomaingd** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrMDomaingd WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblPlnrMDomaingd::loadRstByDsn(
			ubigint dsnRefPlnrMDesign
			, const bool append
			, ListPlnrMDomaingd& rst
		) {
	return loadRstBySQL("SELECT ref, ixVBasetype, dsnRefPlnrMDesign, dsnNum, sref, srefPlnrMLevel, av1SrefPlnrMVertex, av2SrefPlnrMVertex, al1SrefPlnrMLineguide, al2SrefPlnrMLineguide, srefPlnrMArcguide, d, dphi FROM TblPlnrMDomaingd WHERE dsnRefPlnrMDesign = " + to_string(dsnRefPlnrMDesign) + " ORDER BY dsnNum ASC", append, rst);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrMDomaingd
 ******************************************************************************/

PgTblPlnrMDomaingd::PgTblPlnrMDomaingd() : TblPlnrMDomaingd(), PgTable() {
};

PgTblPlnrMDomaingd::~PgTblPlnrMDomaingd() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblPlnrMDomaingd::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrMDomaingd_insertRec", "INSERT INTO TblPlnrMDomaingd (ixVBasetype, dsnRefPlnrMDesign, dsnNum, sref, srefPlnrMLevel, av1SrefPlnrMVertex, av2SrefPlnrMVertex, al1SrefPlnrMLineguide, al2SrefPlnrMLineguide, srefPlnrMArcguide, d, dphi) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11,$12) RETURNING ref", 12, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrMDomaingd_updateRec", "UPDATE TblPlnrMDomaingd SET ixVBasetype = $1, dsnRefPlnrMDesign = $2, dsnNum = $3, sref = $4, srefPlnrMLevel = $5, av1SrefPlnrMVertex = $6, av2SrefPlnrMVertex = $7, al1SrefPlnrMLineguide = $8, al2SrefPlnrMLineguide = $9, srefPlnrMArcguide = $10, d = $11, dphi = $12 WHERE ref = $13", 13, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrMDomaingd_removeRecByRef", "DELETE FROM TblPlnrMDomaingd WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrMDomaingd_loadRecByRef", "SELECT ref, ixVBasetype, dsnRefPlnrMDesign, dsnNum, sref, srefPlnrMLevel, av1SrefPlnrMVertex, av2SrefPlnrMVertex, al1SrefPlnrMLineguide, al2SrefPlnrMLineguide, srefPlnrMArcguide, d, dphi FROM TblPlnrMDomaingd WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblPlnrMDomaingd_loadRstByDsn", "SELECT ref, ixVBasetype, dsnRefPlnrMDesign, dsnNum, sref, srefPlnrMLevel, av1SrefPlnrMVertex, av2SrefPlnrMVertex, al1SrefPlnrMLineguide, al2SrefPlnrMLineguide, srefPlnrMArcguide, d, dphi FROM TblPlnrMDomaingd WHERE dsnRefPlnrMDesign = $1 ORDER BY dsnNum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrMDomaingd::loadRec(
			PGresult* res
			, PlnrMDomaingd** rec
		) {
	char* ptr;

	PlnrMDomaingd* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrMDomaingd();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "dsnrefplnrmdesign"),
			PQfnumber(res, "dsnnum"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "srefplnrmlevel"),
			PQfnumber(res, "av1srefplnrmvertex"),
			PQfnumber(res, "av2srefplnrmvertex"),
			PQfnumber(res, "al1srefplnrmlineguide"),
			PQfnumber(res, "al2srefplnrmlineguide"),
			PQfnumber(res, "srefplnrmarcguide"),
			PQfnumber(res, "d"),
			PQfnumber(res, "dphi")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->ixVBasetype = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->dsnRefPlnrMDesign = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->dsnNum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->srefPlnrMLevel.assign(ptr, PQgetlength(res, 0, fnum[5]));
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->av1SrefPlnrMVertex.assign(ptr, PQgetlength(res, 0, fnum[6]));
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->av2SrefPlnrMVertex.assign(ptr, PQgetlength(res, 0, fnum[7]));
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->al1SrefPlnrMLineguide.assign(ptr, PQgetlength(res, 0, fnum[8]));
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->al2SrefPlnrMLineguide.assign(ptr, PQgetlength(res, 0, fnum[9]));
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->srefPlnrMArcguide.assign(ptr, PQgetlength(res, 0, fnum[10]));
		ptr = PQgetvalue(res, 0, fnum[11]); _rec->d.assign(ptr, PQgetlength(res, 0, fnum[11]));
		ptr = PQgetvalue(res, 0, fnum[12]); _rec->dphi.assign(ptr, PQgetlength(res, 0, fnum[12]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrMDomaingd::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrMDomaingd& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrMDomaingd* rec;

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
			PQfnumber(res, "srefplnrmlevel"),
			PQfnumber(res, "av1srefplnrmvertex"),
			PQfnumber(res, "av2srefplnrmvertex"),
			PQfnumber(res, "al1srefplnrmlineguide"),
			PQfnumber(res, "al2srefplnrmlineguide"),
			PQfnumber(res, "srefplnrmarcguide"),
			PQfnumber(res, "d"),
			PQfnumber(res, "dphi")
		};

		while (numread < numrow) {
			rec = new PlnrMDomaingd();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->ixVBasetype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->dsnRefPlnrMDesign = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->dsnNum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->srefPlnrMLevel.assign(ptr, PQgetlength(res, numread, fnum[5]));
			ptr = PQgetvalue(res, numread, fnum[6]); rec->av1SrefPlnrMVertex.assign(ptr, PQgetlength(res, numread, fnum[6]));
			ptr = PQgetvalue(res, numread, fnum[7]); rec->av2SrefPlnrMVertex.assign(ptr, PQgetlength(res, numread, fnum[7]));
			ptr = PQgetvalue(res, numread, fnum[8]); rec->al1SrefPlnrMLineguide.assign(ptr, PQgetlength(res, numread, fnum[8]));
			ptr = PQgetvalue(res, numread, fnum[9]); rec->al2SrefPlnrMLineguide.assign(ptr, PQgetlength(res, numread, fnum[9]));
			ptr = PQgetvalue(res, numread, fnum[10]); rec->srefPlnrMArcguide.assign(ptr, PQgetlength(res, numread, fnum[10]));
			ptr = PQgetvalue(res, numread, fnum[11]); rec->d.assign(ptr, PQgetlength(res, numread, fnum[11]));
			ptr = PQgetvalue(res, numread, fnum[12]); rec->dphi.assign(ptr, PQgetlength(res, numread, fnum[12]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrMDomaingd::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrMDomaingd** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMDomaingd / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

// IP pgLoadRstByStmt --- BEGIN
ubigint PgTblPlnrMDomaingd::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrMDomaingd& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMDomaingd / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};
// IP pgLoadRstByStmt --- END

bool PgTblPlnrMDomaingd::loadRecBySQL(
			const string& sqlstr
			, PlnrMDomaingd** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrMDomaingd::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrMDomaingd& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrMDomaingd::insertRec(
			PlnrMDomaingd* rec
		) {
	PGresult* res;
	char* ptr;

	uint _ixVBasetype = htonl(rec->ixVBasetype);
	ubigint _dsnRefPlnrMDesign = htonl64(rec->dsnRefPlnrMDesign);
	uint _dsnNum = htonl(rec->dsnNum);

	const char* vals[] = {
		(char*) &_ixVBasetype,
		(char*) &_dsnRefPlnrMDesign,
		(char*) &_dsnNum,
		rec->sref.c_str(),
		rec->srefPlnrMLevel.c_str(),
		rec->av1SrefPlnrMVertex.c_str(),
		rec->av2SrefPlnrMVertex.c_str(),
		rec->al1SrefPlnrMLineguide.c_str(),
		rec->al2SrefPlnrMLineguide.c_str(),
		rec->srefPlnrMArcguide.c_str(),
		rec->d.c_str(),
		rec->dphi.c_str()
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0
	};
	const int f[] = {1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	res = PQexecPrepared(dbs, "TblPlnrMDomaingd_insertRec", 12, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMDomaingd_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblPlnrMDomaingd::insertRst(
			ListPlnrMDomaingd& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblPlnrMDomaingd::updateRec(
			PlnrMDomaingd* rec
		) {
	PGresult* res;

	uint _ixVBasetype = htonl(rec->ixVBasetype);
	ubigint _dsnRefPlnrMDesign = htonl64(rec->dsnRefPlnrMDesign);
	uint _dsnNum = htonl(rec->dsnNum);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_ixVBasetype,
		(char*) &_dsnRefPlnrMDesign,
		(char*) &_dsnNum,
		rec->sref.c_str(),
		rec->srefPlnrMLevel.c_str(),
		rec->av1SrefPlnrMVertex.c_str(),
		rec->av2SrefPlnrMVertex.c_str(),
		rec->al1SrefPlnrMLineguide.c_str(),
		rec->al2SrefPlnrMLineguide.c_str(),
		rec->srefPlnrMArcguide.c_str(),
		rec->d.c_str(),
		rec->dphi.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblPlnrMDomaingd_updateRec", 13, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMDomaingd_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrMDomaingd::updateRst(
			ListPlnrMDomaingd& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblPlnrMDomaingd::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblPlnrMDomaingd_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMDomaingd_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblPlnrMDomaingd::loadRecByRef(
			ubigint ref
			, PlnrMDomaingd** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrMDomaingd_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblPlnrMDomaingd::loadRstByDsn(
			ubigint dsnRefPlnrMDesign
			, const bool append
			, ListPlnrMDomaingd& rst
		) {
	ubigint _dsnRefPlnrMDesign = htonl64(dsnRefPlnrMDesign);

	const char* vals[] = {
		(char*) &_dsnRefPlnrMDesign
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrMDomaingd_loadRstByDsn", 1, vals, l, f, append, rst);
};

// IP pgTbl --- END

