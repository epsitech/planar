/**
  * \file PlnrMDomain.cpp
  * database access for table TblPlnrMDomain (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrMDomain.h"

/******************************************************************************
 class PlnrMDomain
 ******************************************************************************/

PlnrMDomain::PlnrMDomain(
			const ubigint ref
			, const uint ixVBasetype
			, const ubigint dsnRefPlnrMDesign
			, const uint dsnNum
			, const string sref
			, const string flrSrefPlnrMLevel
			, const string ceilSrefPlnrMLevel
			, const string vtx1SrefPlnrMVertex
			, const string lgd1SrefPlnrMLineguide
			, const string vtx2SrefPlnrMVertex
			, const string lgd2SrefPlnrMLineguide
			, const string vtx3SrefPlnrMVertex
			, const string lgd3SrefPlnrMLineguide
			, const string vtx4SrefPlnrMVertex
			, const string lgd4SrefPlnrMLineguide
			, const string dx
			, const string dy
			, const string dxy
			, const string dz
		) {

	this->ref = ref;
	this->ixVBasetype = ixVBasetype;
	this->dsnRefPlnrMDesign = dsnRefPlnrMDesign;
	this->dsnNum = dsnNum;
	this->sref = sref;
	this->flrSrefPlnrMLevel = flrSrefPlnrMLevel;
	this->ceilSrefPlnrMLevel = ceilSrefPlnrMLevel;
	this->vtx1SrefPlnrMVertex = vtx1SrefPlnrMVertex;
	this->lgd1SrefPlnrMLineguide = lgd1SrefPlnrMLineguide;
	this->vtx2SrefPlnrMVertex = vtx2SrefPlnrMVertex;
	this->lgd2SrefPlnrMLineguide = lgd2SrefPlnrMLineguide;
	this->vtx3SrefPlnrMVertex = vtx3SrefPlnrMVertex;
	this->lgd3SrefPlnrMLineguide = lgd3SrefPlnrMLineguide;
	this->vtx4SrefPlnrMVertex = vtx4SrefPlnrMVertex;
	this->lgd4SrefPlnrMLineguide = lgd4SrefPlnrMLineguide;
	this->dx = dx;
	this->dy = dy;
	this->dxy = dxy;
	this->dz = dz;
};

bool PlnrMDomain::operator==(
			const PlnrMDomain& comp
		) {
	return false;
};

bool PlnrMDomain::operator!=(
			const PlnrMDomain& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListPlnrMDomain
 ******************************************************************************/

ListPlnrMDomain::ListPlnrMDomain() {
};

ListPlnrMDomain::ListPlnrMDomain(
			const ListPlnrMDomain& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrMDomain(*(src.nodes[i]));
};

ListPlnrMDomain::~ListPlnrMDomain() {
	clear();
};

void ListPlnrMDomain::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrMDomain::size() const {
	return(nodes.size());
};

void ListPlnrMDomain::append(
			PlnrMDomain* rec
		) {
	nodes.push_back(rec);
};

PlnrMDomain* ListPlnrMDomain::operator[](
			const uint ix
		) {
	PlnrMDomain* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListPlnrMDomain& ListPlnrMDomain::operator=(
			const ListPlnrMDomain& src
		) {
	PlnrMDomain* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrMDomain(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListPlnrMDomain::operator==(
			const ListPlnrMDomain& comp
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

bool ListPlnrMDomain::operator!=(
			const ListPlnrMDomain& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblPlnrMDomain
 ******************************************************************************/

TblPlnrMDomain::TblPlnrMDomain() {
};

TblPlnrMDomain::~TblPlnrMDomain() {
};

bool TblPlnrMDomain::loadRecBySQL(
			const string& sqlstr
			, PlnrMDomain** rec
		) {
	return false;
};

ubigint TblPlnrMDomain::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrMDomain& rst
		) {
	return 0;
};

void TblPlnrMDomain::insertRec(
			PlnrMDomain* rec
		) {
};

ubigint TblPlnrMDomain::insertNewRec(
			PlnrMDomain** rec
			, const uint ixVBasetype
			, const ubigint dsnRefPlnrMDesign
			, const uint dsnNum
			, const string sref
			, const string flrSrefPlnrMLevel
			, const string ceilSrefPlnrMLevel
			, const string vtx1SrefPlnrMVertex
			, const string lgd1SrefPlnrMLineguide
			, const string vtx2SrefPlnrMVertex
			, const string lgd2SrefPlnrMLineguide
			, const string vtx3SrefPlnrMVertex
			, const string lgd3SrefPlnrMLineguide
			, const string vtx4SrefPlnrMVertex
			, const string lgd4SrefPlnrMLineguide
			, const string dx
			, const string dy
			, const string dxy
			, const string dz
		) {
	ubigint retval = 0;
	PlnrMDomain* _rec = NULL;

	_rec = new PlnrMDomain(0, ixVBasetype, dsnRefPlnrMDesign, dsnNum, sref, flrSrefPlnrMLevel, ceilSrefPlnrMLevel, vtx1SrefPlnrMVertex, lgd1SrefPlnrMLineguide, vtx2SrefPlnrMVertex, lgd2SrefPlnrMLineguide, vtx3SrefPlnrMVertex, lgd3SrefPlnrMLineguide, vtx4SrefPlnrMVertex, lgd4SrefPlnrMLineguide, dx, dy, dxy, dz);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrMDomain::appendNewRecToRst(
			ListPlnrMDomain& rst
			, PlnrMDomain** rec
			, const uint ixVBasetype
			, const ubigint dsnRefPlnrMDesign
			, const uint dsnNum
			, const string sref
			, const string flrSrefPlnrMLevel
			, const string ceilSrefPlnrMLevel
			, const string vtx1SrefPlnrMVertex
			, const string lgd1SrefPlnrMLineguide
			, const string vtx2SrefPlnrMVertex
			, const string lgd2SrefPlnrMLineguide
			, const string vtx3SrefPlnrMVertex
			, const string lgd3SrefPlnrMLineguide
			, const string vtx4SrefPlnrMVertex
			, const string lgd4SrefPlnrMLineguide
			, const string dx
			, const string dy
			, const string dxy
			, const string dz
		) {
	ubigint retval = 0;
	PlnrMDomain* _rec = NULL;

	retval = insertNewRec(&_rec, ixVBasetype, dsnRefPlnrMDesign, dsnNum, sref, flrSrefPlnrMLevel, ceilSrefPlnrMLevel, vtx1SrefPlnrMVertex, lgd1SrefPlnrMLineguide, vtx2SrefPlnrMVertex, lgd2SrefPlnrMLineguide, vtx3SrefPlnrMVertex, lgd3SrefPlnrMLineguide, vtx4SrefPlnrMVertex, lgd4SrefPlnrMLineguide, dx, dy, dxy, dz);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrMDomain::insertRst(
			ListPlnrMDomain& rst
			, bool transact
		) {
};

void TblPlnrMDomain::updateRec(
			PlnrMDomain* rec
		) {
};

void TblPlnrMDomain::updateRst(
			ListPlnrMDomain& rst
			, bool transact
		) {
};

void TblPlnrMDomain::removeRecByRef(
			ubigint ref
		) {
};

bool TblPlnrMDomain::loadRecByRef(
			ubigint ref
			, PlnrMDomain** rec
		) {
	return false;
};

bool TblPlnrMDomain::loadRefByTypDsn(
			uint ixVBasetype
			, ubigint dsnRefPlnrMDesign
			, ubigint& val
		) {
	return false;
};

ubigint TblPlnrMDomain::loadRstByDsn(
			ubigint dsnRefPlnrMDesign
			, const bool append
			, ListPlnrMDomain& rst
		) {
	return 0;
};

ubigint TblPlnrMDomain::loadRstByTypDsn(
			uint ixVBasetype
			, ubigint dsnRefPlnrMDesign
			, const bool append
			, ListPlnrMDomain& rst
		) {
	return 0;
};

bool TblPlnrMDomain::loadSrfByRef(
			ubigint ref
			, string& val
		) {
	return false;
};

ubigint TblPlnrMDomain::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListPlnrMDomain& rst
		) {
	ubigint numload = 0;
	PlnrMDomain* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrMDomain
 ******************************************************************************/

MyTblPlnrMDomain::MyTblPlnrMDomain() : TblPlnrMDomain(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblPlnrMDomain::~MyTblPlnrMDomain() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblPlnrMDomain::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrMDomain (ixVBasetype, dsnRefPlnrMDesign, dsnNum, sref, flrSrefPlnrMLevel, ceilSrefPlnrMLevel, vtx1SrefPlnrMVertex, lgd1SrefPlnrMLineguide, vtx2SrefPlnrMVertex, lgd2SrefPlnrMLineguide, vtx3SrefPlnrMVertex, lgd3SrefPlnrMLineguide, vtx4SrefPlnrMVertex, lgd4SrefPlnrMLineguide, dx, dy, dxy, dz) VALUES (?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrMDomain SET ixVBasetype = ?, dsnRefPlnrMDesign = ?, dsnNum = ?, sref = ?, flrSrefPlnrMLevel = ?, ceilSrefPlnrMLevel = ?, vtx1SrefPlnrMVertex = ?, lgd1SrefPlnrMLineguide = ?, vtx2SrefPlnrMVertex = ?, lgd2SrefPlnrMLineguide = ?, vtx3SrefPlnrMVertex = ?, lgd3SrefPlnrMLineguide = ?, vtx4SrefPlnrMVertex = ?, lgd4SrefPlnrMLineguide = ?, dx = ?, dy = ?, dxy = ?, dz = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblPlnrMDomain WHERE ref = ?", false);
};

bool MyTblPlnrMDomain::loadRecBySQL(
			const string& sqlstr
			, PlnrMDomain** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrMDomain* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrMDomain / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrMDomain();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->ixVBasetype = atol((char*) dbrow[1]); else _rec->ixVBasetype = 0;
		if (dbrow[2]) _rec->dsnRefPlnrMDesign = atoll((char*) dbrow[2]); else _rec->dsnRefPlnrMDesign = 0;
		if (dbrow[3]) _rec->dsnNum = atol((char*) dbrow[3]); else _rec->dsnNum = 0;
		if (dbrow[4]) _rec->sref.assign(dbrow[4], dblengths[4]); else _rec->sref = "";
		if (dbrow[5]) _rec->flrSrefPlnrMLevel.assign(dbrow[5], dblengths[5]); else _rec->flrSrefPlnrMLevel = "";
		if (dbrow[6]) _rec->ceilSrefPlnrMLevel.assign(dbrow[6], dblengths[6]); else _rec->ceilSrefPlnrMLevel = "";
		if (dbrow[7]) _rec->vtx1SrefPlnrMVertex.assign(dbrow[7], dblengths[7]); else _rec->vtx1SrefPlnrMVertex = "";
		if (dbrow[8]) _rec->lgd1SrefPlnrMLineguide.assign(dbrow[8], dblengths[8]); else _rec->lgd1SrefPlnrMLineguide = "";
		if (dbrow[9]) _rec->vtx2SrefPlnrMVertex.assign(dbrow[9], dblengths[9]); else _rec->vtx2SrefPlnrMVertex = "";
		if (dbrow[10]) _rec->lgd2SrefPlnrMLineguide.assign(dbrow[10], dblengths[10]); else _rec->lgd2SrefPlnrMLineguide = "";
		if (dbrow[11]) _rec->vtx3SrefPlnrMVertex.assign(dbrow[11], dblengths[11]); else _rec->vtx3SrefPlnrMVertex = "";
		if (dbrow[12]) _rec->lgd3SrefPlnrMLineguide.assign(dbrow[12], dblengths[12]); else _rec->lgd3SrefPlnrMLineguide = "";
		if (dbrow[13]) _rec->vtx4SrefPlnrMVertex.assign(dbrow[13], dblengths[13]); else _rec->vtx4SrefPlnrMVertex = "";
		if (dbrow[14]) _rec->lgd4SrefPlnrMLineguide.assign(dbrow[14], dblengths[14]); else _rec->lgd4SrefPlnrMLineguide = "";
		if (dbrow[15]) _rec->dx.assign(dbrow[15], dblengths[15]); else _rec->dx = "";
		if (dbrow[16]) _rec->dy.assign(dbrow[16], dblengths[16]); else _rec->dy = "";
		if (dbrow[17]) _rec->dxy.assign(dbrow[17], dblengths[17]); else _rec->dxy = "";
		if (dbrow[18]) _rec->dz.assign(dbrow[18], dblengths[18]); else _rec->dz = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrMDomain::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrMDomain& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrMDomain* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrMDomain / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrMDomain();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->ixVBasetype = atol((char*) dbrow[1]); else rec->ixVBasetype = 0;
			if (dbrow[2]) rec->dsnRefPlnrMDesign = atoll((char*) dbrow[2]); else rec->dsnRefPlnrMDesign = 0;
			if (dbrow[3]) rec->dsnNum = atol((char*) dbrow[3]); else rec->dsnNum = 0;
			if (dbrow[4]) rec->sref.assign(dbrow[4], dblengths[4]); else rec->sref = "";
			if (dbrow[5]) rec->flrSrefPlnrMLevel.assign(dbrow[5], dblengths[5]); else rec->flrSrefPlnrMLevel = "";
			if (dbrow[6]) rec->ceilSrefPlnrMLevel.assign(dbrow[6], dblengths[6]); else rec->ceilSrefPlnrMLevel = "";
			if (dbrow[7]) rec->vtx1SrefPlnrMVertex.assign(dbrow[7], dblengths[7]); else rec->vtx1SrefPlnrMVertex = "";
			if (dbrow[8]) rec->lgd1SrefPlnrMLineguide.assign(dbrow[8], dblengths[8]); else rec->lgd1SrefPlnrMLineguide = "";
			if (dbrow[9]) rec->vtx2SrefPlnrMVertex.assign(dbrow[9], dblengths[9]); else rec->vtx2SrefPlnrMVertex = "";
			if (dbrow[10]) rec->lgd2SrefPlnrMLineguide.assign(dbrow[10], dblengths[10]); else rec->lgd2SrefPlnrMLineguide = "";
			if (dbrow[11]) rec->vtx3SrefPlnrMVertex.assign(dbrow[11], dblengths[11]); else rec->vtx3SrefPlnrMVertex = "";
			if (dbrow[12]) rec->lgd3SrefPlnrMLineguide.assign(dbrow[12], dblengths[12]); else rec->lgd3SrefPlnrMLineguide = "";
			if (dbrow[13]) rec->vtx4SrefPlnrMVertex.assign(dbrow[13], dblengths[13]); else rec->vtx4SrefPlnrMVertex = "";
			if (dbrow[14]) rec->lgd4SrefPlnrMLineguide.assign(dbrow[14], dblengths[14]); else rec->lgd4SrefPlnrMLineguide = "";
			if (dbrow[15]) rec->dx.assign(dbrow[15], dblengths[15]); else rec->dx = "";
			if (dbrow[16]) rec->dy.assign(dbrow[16], dblengths[16]); else rec->dy = "";
			if (dbrow[17]) rec->dxy.assign(dbrow[17], dblengths[17]); else rec->dxy = "";
			if (dbrow[18]) rec->dz.assign(dbrow[18], dblengths[18]); else rec->dz = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrMDomain::insertRec(
			PlnrMDomain* rec
		) {
	unsigned long l[18]; my_bool n[18]; my_bool e[18];

	l[3] = rec->sref.length();
	l[4] = rec->flrSrefPlnrMLevel.length();
	l[5] = rec->ceilSrefPlnrMLevel.length();
	l[6] = rec->vtx1SrefPlnrMVertex.length();
	l[7] = rec->lgd1SrefPlnrMLineguide.length();
	l[8] = rec->vtx2SrefPlnrMVertex.length();
	l[9] = rec->lgd2SrefPlnrMLineguide.length();
	l[10] = rec->vtx3SrefPlnrMVertex.length();
	l[11] = rec->lgd3SrefPlnrMLineguide.length();
	l[12] = rec->vtx4SrefPlnrMVertex.length();
	l[13] = rec->lgd4SrefPlnrMLineguide.length();
	l[14] = rec->dx.length();
	l[15] = rec->dy.length();
	l[16] = rec->dxy.length();
	l[17] = rec->dz.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->ixVBasetype,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->dsnRefPlnrMDesign,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->dsnNum,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->flrSrefPlnrMLevel.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->ceilSrefPlnrMLevel.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->vtx1SrefPlnrMVertex.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->lgd1SrefPlnrMLineguide.c_str()),&(l[7]),&(n[7]),&(e[7])),
		bindCstring((char*) (rec->vtx2SrefPlnrMVertex.c_str()),&(l[8]),&(n[8]),&(e[8])),
		bindCstring((char*) (rec->lgd2SrefPlnrMLineguide.c_str()),&(l[9]),&(n[9]),&(e[9])),
		bindCstring((char*) (rec->vtx3SrefPlnrMVertex.c_str()),&(l[10]),&(n[10]),&(e[10])),
		bindCstring((char*) (rec->lgd3SrefPlnrMLineguide.c_str()),&(l[11]),&(n[11]),&(e[11])),
		bindCstring((char*) (rec->vtx4SrefPlnrMVertex.c_str()),&(l[12]),&(n[12]),&(e[12])),
		bindCstring((char*) (rec->lgd4SrefPlnrMLineguide.c_str()),&(l[13]),&(n[13]),&(e[13])),
		bindCstring((char*) (rec->dx.c_str()),&(l[14]),&(n[14]),&(e[14])),
		bindCstring((char*) (rec->dy.c_str()),&(l[15]),&(n[15]),&(e[15])),
		bindCstring((char*) (rec->dxy.c_str()),&(l[16]),&(n[16]),&(e[16])),
		bindCstring((char*) (rec->dz.c_str()),&(l[17]),&(n[17]),&(e[17]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrMDomain / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrMDomain / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblPlnrMDomain::insertRst(
			ListPlnrMDomain& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblPlnrMDomain::updateRec(
			PlnrMDomain* rec
		) {
	unsigned long l[19]; my_bool n[19]; my_bool e[19];

	l[3] = rec->sref.length();
	l[4] = rec->flrSrefPlnrMLevel.length();
	l[5] = rec->ceilSrefPlnrMLevel.length();
	l[6] = rec->vtx1SrefPlnrMVertex.length();
	l[7] = rec->lgd1SrefPlnrMLineguide.length();
	l[8] = rec->vtx2SrefPlnrMVertex.length();
	l[9] = rec->lgd2SrefPlnrMLineguide.length();
	l[10] = rec->vtx3SrefPlnrMVertex.length();
	l[11] = rec->lgd3SrefPlnrMLineguide.length();
	l[12] = rec->vtx4SrefPlnrMVertex.length();
	l[13] = rec->lgd4SrefPlnrMLineguide.length();
	l[14] = rec->dx.length();
	l[15] = rec->dy.length();
	l[16] = rec->dxy.length();
	l[17] = rec->dz.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->ixVBasetype,&(l[0]),&(n[0]),&(e[0])), 
		bindUbigint(&rec->dsnRefPlnrMDesign,&(l[1]),&(n[1]),&(e[1])), 
		bindUint(&rec->dsnNum,&(l[2]),&(n[2]),&(e[2])), 
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])), 
		bindCstring((char*) (rec->flrSrefPlnrMLevel.c_str()),&(l[4]),&(n[4]),&(e[4])), 
		bindCstring((char*) (rec->ceilSrefPlnrMLevel.c_str()),&(l[5]),&(n[5]),&(e[5])), 
		bindCstring((char*) (rec->vtx1SrefPlnrMVertex.c_str()),&(l[6]),&(n[6]),&(e[6])), 
		bindCstring((char*) (rec->lgd1SrefPlnrMLineguide.c_str()),&(l[7]),&(n[7]),&(e[7])), 
		bindCstring((char*) (rec->vtx2SrefPlnrMVertex.c_str()),&(l[8]),&(n[8]),&(e[8])), 
		bindCstring((char*) (rec->lgd2SrefPlnrMLineguide.c_str()),&(l[9]),&(n[9]),&(e[9])), 
		bindCstring((char*) (rec->vtx3SrefPlnrMVertex.c_str()),&(l[10]),&(n[10]),&(e[10])), 
		bindCstring((char*) (rec->lgd3SrefPlnrMLineguide.c_str()),&(l[11]),&(n[11]),&(e[11])), 
		bindCstring((char*) (rec->vtx4SrefPlnrMVertex.c_str()),&(l[12]),&(n[12]),&(e[12])), 
		bindCstring((char*) (rec->lgd4SrefPlnrMLineguide.c_str()),&(l[13]),&(n[13]),&(e[13])), 
		bindCstring((char*) (rec->dx.c_str()),&(l[14]),&(n[14]),&(e[14])), 
		bindCstring((char*) (rec->dy.c_str()),&(l[15]),&(n[15]),&(e[15])), 
		bindCstring((char*) (rec->dxy.c_str()),&(l[16]),&(n[16]),&(e[16])), 
		bindCstring((char*) (rec->dz.c_str()),&(l[17]),&(n[17]),&(e[17])), 
		bindUbigint(&rec->ref,&(l[18]),&(n[18]),&(e[18]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrMDomain / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrMDomain / stmtUpdateRec)\n");
};

void MyTblPlnrMDomain::updateRst(
			ListPlnrMDomain& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblPlnrMDomain::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrMDomain / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrMDomain / stmtRemoveRecByRef)\n");
};

bool MyTblPlnrMDomain::loadRecByRef(
			ubigint ref
			, PlnrMDomain** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrMDomain WHERE ref = " + to_string(ref), rec);
};

bool MyTblPlnrMDomain::loadRefByTypDsn(
			uint ixVBasetype
			, ubigint dsnRefPlnrMDesign
			, ubigint& val
		) {
	return loadUbigintBySQL("SELECT ref FROM TblPlnrMDomain WHERE ixVBasetype = " + to_string(ixVBasetype) + " AND dsnRefPlnrMDesign = " + to_string(dsnRefPlnrMDesign) + "", val);
};

ubigint MyTblPlnrMDomain::loadRstByDsn(
			ubigint dsnRefPlnrMDesign
			, const bool append
			, ListPlnrMDomain& rst
		) {
	return loadRstBySQL("SELECT ref, ixVBasetype, dsnRefPlnrMDesign, dsnNum, sref, flrSrefPlnrMLevel, ceilSrefPlnrMLevel, vtx1SrefPlnrMVertex, lgd1SrefPlnrMLineguide, vtx2SrefPlnrMVertex, lgd2SrefPlnrMLineguide, vtx3SrefPlnrMVertex, lgd3SrefPlnrMLineguide, vtx4SrefPlnrMVertex, lgd4SrefPlnrMLineguide, dx, dy, dxy, dz FROM TblPlnrMDomain WHERE dsnRefPlnrMDesign = " + to_string(dsnRefPlnrMDesign) + " ORDER BY dsnNum ASC", append, rst);
};

ubigint MyTblPlnrMDomain::loadRstByTypDsn(
			uint ixVBasetype
			, ubigint dsnRefPlnrMDesign
			, const bool append
			, ListPlnrMDomain& rst
		) {
	return loadRstBySQL("SELECT ref, ixVBasetype, dsnRefPlnrMDesign, dsnNum, sref, flrSrefPlnrMLevel, ceilSrefPlnrMLevel, vtx1SrefPlnrMVertex, lgd1SrefPlnrMLineguide, vtx2SrefPlnrMVertex, lgd2SrefPlnrMLineguide, vtx3SrefPlnrMVertex, lgd3SrefPlnrMLineguide, vtx4SrefPlnrMVertex, lgd4SrefPlnrMLineguide, dx, dy, dxy, dz FROM TblPlnrMDomain WHERE ixVBasetype = " + to_string(ixVBasetype) + " AND dsnRefPlnrMDesign = " + to_string(dsnRefPlnrMDesign) + " ORDER BY dsnNum ASC", append, rst);
};

bool MyTblPlnrMDomain::loadSrfByRef(
			ubigint ref
			, string& val
		) {
	return loadStringBySQL("SELECT sref FROM TblPlnrMDomain WHERE ref = " + to_string(ref) + "", val);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrMDomain
 ******************************************************************************/

PgTblPlnrMDomain::PgTblPlnrMDomain() : TblPlnrMDomain(), PgTable() {
};

PgTblPlnrMDomain::~PgTblPlnrMDomain() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblPlnrMDomain::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrMDomain_insertRec", "INSERT INTO TblPlnrMDomain (ixVBasetype, dsnRefPlnrMDesign, dsnNum, sref, flrSrefPlnrMLevel, ceilSrefPlnrMLevel, vtx1SrefPlnrMVertex, lgd1SrefPlnrMLineguide, vtx2SrefPlnrMVertex, lgd2SrefPlnrMLineguide, vtx3SrefPlnrMVertex, lgd3SrefPlnrMLineguide, vtx4SrefPlnrMVertex, lgd4SrefPlnrMLineguide, dx, dy, dxy, dz) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11,$12,$13,$14,$15,$16,$17,$18) RETURNING ref", 18, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrMDomain_updateRec", "UPDATE TblPlnrMDomain SET ixVBasetype = $1, dsnRefPlnrMDesign = $2, dsnNum = $3, sref = $4, flrSrefPlnrMLevel = $5, ceilSrefPlnrMLevel = $6, vtx1SrefPlnrMVertex = $7, lgd1SrefPlnrMLineguide = $8, vtx2SrefPlnrMVertex = $9, lgd2SrefPlnrMLineguide = $10, vtx3SrefPlnrMVertex = $11, lgd3SrefPlnrMLineguide = $12, vtx4SrefPlnrMVertex = $13, lgd4SrefPlnrMLineguide = $14, dx = $15, dy = $16, dxy = $17, dz = $18 WHERE ref = $19", 19, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrMDomain_removeRecByRef", "DELETE FROM TblPlnrMDomain WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrMDomain_loadRecByRef", "SELECT ref, ixVBasetype, dsnRefPlnrMDesign, dsnNum, sref, flrSrefPlnrMLevel, ceilSrefPlnrMLevel, vtx1SrefPlnrMVertex, lgd1SrefPlnrMLineguide, vtx2SrefPlnrMVertex, lgd2SrefPlnrMLineguide, vtx3SrefPlnrMVertex, lgd3SrefPlnrMLineguide, vtx4SrefPlnrMVertex, lgd4SrefPlnrMLineguide, dx, dy, dxy, dz FROM TblPlnrMDomain WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblPlnrMDomain_loadRefByTypDsn", "SELECT ref FROM TblPlnrMDomain WHERE ixVBasetype = $1 AND dsnRefPlnrMDesign = $2", 2, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrMDomain_loadRstByDsn", "SELECT ref, ixVBasetype, dsnRefPlnrMDesign, dsnNum, sref, flrSrefPlnrMLevel, ceilSrefPlnrMLevel, vtx1SrefPlnrMVertex, lgd1SrefPlnrMLineguide, vtx2SrefPlnrMVertex, lgd2SrefPlnrMLineguide, vtx3SrefPlnrMVertex, lgd3SrefPlnrMLineguide, vtx4SrefPlnrMVertex, lgd4SrefPlnrMLineguide, dx, dy, dxy, dz FROM TblPlnrMDomain WHERE dsnRefPlnrMDesign = $1 ORDER BY dsnNum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrMDomain_loadRstByTypDsn", "SELECT ref, ixVBasetype, dsnRefPlnrMDesign, dsnNum, sref, flrSrefPlnrMLevel, ceilSrefPlnrMLevel, vtx1SrefPlnrMVertex, lgd1SrefPlnrMLineguide, vtx2SrefPlnrMVertex, lgd2SrefPlnrMLineguide, vtx3SrefPlnrMVertex, lgd3SrefPlnrMLineguide, vtx4SrefPlnrMVertex, lgd4SrefPlnrMLineguide, dx, dy, dxy, dz FROM TblPlnrMDomain WHERE ixVBasetype = $1 AND dsnRefPlnrMDesign = $2 ORDER BY dsnNum ASC", 2, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrMDomain_loadSrfByRef", "SELECT sref FROM TblPlnrMDomain WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrMDomain::loadRec(
			PGresult* res
			, PlnrMDomain** rec
		) {
	char* ptr;

	PlnrMDomain* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrMDomain();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "dsnrefplnrmdesign"),
			PQfnumber(res, "dsnnum"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "flrsrefplnrmlevel"),
			PQfnumber(res, "ceilsrefplnrmlevel"),
			PQfnumber(res, "vtx1srefplnrmvertex"),
			PQfnumber(res, "lgd1srefplnrmlineguide"),
			PQfnumber(res, "vtx2srefplnrmvertex"),
			PQfnumber(res, "lgd2srefplnrmlineguide"),
			PQfnumber(res, "vtx3srefplnrmvertex"),
			PQfnumber(res, "lgd3srefplnrmlineguide"),
			PQfnumber(res, "vtx4srefplnrmvertex"),
			PQfnumber(res, "lgd4srefplnrmlineguide"),
			PQfnumber(res, "dx"),
			PQfnumber(res, "dy"),
			PQfnumber(res, "dxy"),
			PQfnumber(res, "dz")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->ixVBasetype = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->dsnRefPlnrMDesign = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->dsnNum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->flrSrefPlnrMLevel.assign(ptr, PQgetlength(res, 0, fnum[5]));
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->ceilSrefPlnrMLevel.assign(ptr, PQgetlength(res, 0, fnum[6]));
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->vtx1SrefPlnrMVertex.assign(ptr, PQgetlength(res, 0, fnum[7]));
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->lgd1SrefPlnrMLineguide.assign(ptr, PQgetlength(res, 0, fnum[8]));
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->vtx2SrefPlnrMVertex.assign(ptr, PQgetlength(res, 0, fnum[9]));
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->lgd2SrefPlnrMLineguide.assign(ptr, PQgetlength(res, 0, fnum[10]));
		ptr = PQgetvalue(res, 0, fnum[11]); _rec->vtx3SrefPlnrMVertex.assign(ptr, PQgetlength(res, 0, fnum[11]));
		ptr = PQgetvalue(res, 0, fnum[12]); _rec->lgd3SrefPlnrMLineguide.assign(ptr, PQgetlength(res, 0, fnum[12]));
		ptr = PQgetvalue(res, 0, fnum[13]); _rec->vtx4SrefPlnrMVertex.assign(ptr, PQgetlength(res, 0, fnum[13]));
		ptr = PQgetvalue(res, 0, fnum[14]); _rec->lgd4SrefPlnrMLineguide.assign(ptr, PQgetlength(res, 0, fnum[14]));
		ptr = PQgetvalue(res, 0, fnum[15]); _rec->dx.assign(ptr, PQgetlength(res, 0, fnum[15]));
		ptr = PQgetvalue(res, 0, fnum[16]); _rec->dy.assign(ptr, PQgetlength(res, 0, fnum[16]));
		ptr = PQgetvalue(res, 0, fnum[17]); _rec->dxy.assign(ptr, PQgetlength(res, 0, fnum[17]));
		ptr = PQgetvalue(res, 0, fnum[18]); _rec->dz.assign(ptr, PQgetlength(res, 0, fnum[18]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrMDomain::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrMDomain& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrMDomain* rec;

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
			PQfnumber(res, "flrsrefplnrmlevel"),
			PQfnumber(res, "ceilsrefplnrmlevel"),
			PQfnumber(res, "vtx1srefplnrmvertex"),
			PQfnumber(res, "lgd1srefplnrmlineguide"),
			PQfnumber(res, "vtx2srefplnrmvertex"),
			PQfnumber(res, "lgd2srefplnrmlineguide"),
			PQfnumber(res, "vtx3srefplnrmvertex"),
			PQfnumber(res, "lgd3srefplnrmlineguide"),
			PQfnumber(res, "vtx4srefplnrmvertex"),
			PQfnumber(res, "lgd4srefplnrmlineguide"),
			PQfnumber(res, "dx"),
			PQfnumber(res, "dy"),
			PQfnumber(res, "dxy"),
			PQfnumber(res, "dz")
		};

		while (numread < numrow) {
			rec = new PlnrMDomain();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->ixVBasetype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->dsnRefPlnrMDesign = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->dsnNum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->flrSrefPlnrMLevel.assign(ptr, PQgetlength(res, numread, fnum[5]));
			ptr = PQgetvalue(res, numread, fnum[6]); rec->ceilSrefPlnrMLevel.assign(ptr, PQgetlength(res, numread, fnum[6]));
			ptr = PQgetvalue(res, numread, fnum[7]); rec->vtx1SrefPlnrMVertex.assign(ptr, PQgetlength(res, numread, fnum[7]));
			ptr = PQgetvalue(res, numread, fnum[8]); rec->lgd1SrefPlnrMLineguide.assign(ptr, PQgetlength(res, numread, fnum[8]));
			ptr = PQgetvalue(res, numread, fnum[9]); rec->vtx2SrefPlnrMVertex.assign(ptr, PQgetlength(res, numread, fnum[9]));
			ptr = PQgetvalue(res, numread, fnum[10]); rec->lgd2SrefPlnrMLineguide.assign(ptr, PQgetlength(res, numread, fnum[10]));
			ptr = PQgetvalue(res, numread, fnum[11]); rec->vtx3SrefPlnrMVertex.assign(ptr, PQgetlength(res, numread, fnum[11]));
			ptr = PQgetvalue(res, numread, fnum[12]); rec->lgd3SrefPlnrMLineguide.assign(ptr, PQgetlength(res, numread, fnum[12]));
			ptr = PQgetvalue(res, numread, fnum[13]); rec->vtx4SrefPlnrMVertex.assign(ptr, PQgetlength(res, numread, fnum[13]));
			ptr = PQgetvalue(res, numread, fnum[14]); rec->lgd4SrefPlnrMLineguide.assign(ptr, PQgetlength(res, numread, fnum[14]));
			ptr = PQgetvalue(res, numread, fnum[15]); rec->dx.assign(ptr, PQgetlength(res, numread, fnum[15]));
			ptr = PQgetvalue(res, numread, fnum[16]); rec->dy.assign(ptr, PQgetlength(res, numread, fnum[16]));
			ptr = PQgetvalue(res, numread, fnum[17]); rec->dxy.assign(ptr, PQgetlength(res, numread, fnum[17]));
			ptr = PQgetvalue(res, numread, fnum[18]); rec->dz.assign(ptr, PQgetlength(res, numread, fnum[18]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrMDomain::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrMDomain** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMDomain / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

// IP pgLoadRstByStmt --- BEGIN
ubigint PgTblPlnrMDomain::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrMDomain& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMDomain / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};
// IP pgLoadRstByStmt --- END

bool PgTblPlnrMDomain::loadRecBySQL(
			const string& sqlstr
			, PlnrMDomain** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrMDomain::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrMDomain& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrMDomain::insertRec(
			PlnrMDomain* rec
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
		rec->flrSrefPlnrMLevel.c_str(),
		rec->ceilSrefPlnrMLevel.c_str(),
		rec->vtx1SrefPlnrMVertex.c_str(),
		rec->lgd1SrefPlnrMLineguide.c_str(),
		rec->vtx2SrefPlnrMVertex.c_str(),
		rec->lgd2SrefPlnrMLineguide.c_str(),
		rec->vtx3SrefPlnrMVertex.c_str(),
		rec->lgd3SrefPlnrMLineguide.c_str(),
		rec->vtx4SrefPlnrMVertex.c_str(),
		rec->lgd4SrefPlnrMLineguide.c_str(),
		rec->dx.c_str(),
		rec->dy.c_str(),
		rec->dxy.c_str(),
		rec->dz.c_str()
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
		0,
		0,
		0,
		0,
		0,
		0
	};
	const int f[] = {1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	res = PQexecPrepared(dbs, "TblPlnrMDomain_insertRec", 18, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMDomain_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblPlnrMDomain::insertRst(
			ListPlnrMDomain& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblPlnrMDomain::updateRec(
			PlnrMDomain* rec
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
		rec->flrSrefPlnrMLevel.c_str(),
		rec->ceilSrefPlnrMLevel.c_str(),
		rec->vtx1SrefPlnrMVertex.c_str(),
		rec->lgd1SrefPlnrMLineguide.c_str(),
		rec->vtx2SrefPlnrMVertex.c_str(),
		rec->lgd2SrefPlnrMLineguide.c_str(),
		rec->vtx3SrefPlnrMVertex.c_str(),
		rec->lgd3SrefPlnrMLineguide.c_str(),
		rec->vtx4SrefPlnrMVertex.c_str(),
		rec->lgd4SrefPlnrMLineguide.c_str(),
		rec->dx.c_str(),
		rec->dy.c_str(),
		rec->dxy.c_str(),
		rec->dz.c_str(),
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
		0,
		0,
		0,
		0,
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblPlnrMDomain_updateRec", 19, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMDomain_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrMDomain::updateRst(
			ListPlnrMDomain& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblPlnrMDomain::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblPlnrMDomain_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMDomain_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblPlnrMDomain::loadRecByRef(
			ubigint ref
			, PlnrMDomain** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrMDomain_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblPlnrMDomain::loadRefByTypDsn(
			uint ixVBasetype
			, ubigint dsnRefPlnrMDesign
			, ubigint& val
		) {
	uint _ixVBasetype = htonl(ixVBasetype);
	ubigint _dsnRefPlnrMDesign = htonl64(dsnRefPlnrMDesign);

	const char* vals[] = {
		(char*) &_ixVBasetype,
		(char*) &_dsnRefPlnrMDesign
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1,1};

	return loadUbigintByStmt("TblPlnrMDomain_loadRefByTypDsn", 2, vals, l, f, val);
};

ubigint PgTblPlnrMDomain::loadRstByDsn(
			ubigint dsnRefPlnrMDesign
			, const bool append
			, ListPlnrMDomain& rst
		) {
	ubigint _dsnRefPlnrMDesign = htonl64(dsnRefPlnrMDesign);

	const char* vals[] = {
		(char*) &_dsnRefPlnrMDesign
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrMDomain_loadRstByDsn", 1, vals, l, f, append, rst);
};

ubigint PgTblPlnrMDomain::loadRstByTypDsn(
			uint ixVBasetype
			, ubigint dsnRefPlnrMDesign
			, const bool append
			, ListPlnrMDomain& rst
		) {
	uint _ixVBasetype = htonl(ixVBasetype);
	ubigint _dsnRefPlnrMDesign = htonl64(dsnRefPlnrMDesign);

	const char* vals[] = {
		(char*) &_ixVBasetype,
		(char*) &_dsnRefPlnrMDesign
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1,1};

	return loadRstByStmt("TblPlnrMDomain_loadRstByTypDsn", 2, vals, l, f, append, rst);
};

bool PgTblPlnrMDomain::loadSrfByRef(
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

	return loadStringByStmt("TblPlnrMDomain_loadSrfByRef", 1, vals, l, f, val);
};

// IP pgTbl --- END

