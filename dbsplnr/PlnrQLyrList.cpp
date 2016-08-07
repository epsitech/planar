/**
  * \file PlnrQLyrList.cpp
  * Dbs and XML wrapper for table TblPlnrQLyrList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQLyrList.h"

/******************************************************************************
 class PlnrQLyrList
 ******************************************************************************/

PlnrQLyrList::PlnrQLyrList(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const ubigint x1RefPlnrMDesign
			, const uint ixVBasetype
			, const string srefIxVBasetype
			, const string titIxVBasetype
			, const uint hkIxVTbl
			, const string srefHkIxVTbl
			, const string titHkIxVTbl
			, const ubigint hkUref
			, const string stubHkUref
			, const ubigint refPlnrMMaterial
			, const string stubRefPlnrMMaterial
			, const uint ixVTtype
			, const string srefIxVTtype
			, const string titIxVTtype
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->sref = sref;
	this->x1RefPlnrMDesign = x1RefPlnrMDesign;
	this->ixVBasetype = ixVBasetype;
	this->srefIxVBasetype = srefIxVBasetype;
	this->titIxVBasetype = titIxVBasetype;
	this->hkIxVTbl = hkIxVTbl;
	this->srefHkIxVTbl = srefHkIxVTbl;
	this->titHkIxVTbl = titHkIxVTbl;
	this->hkUref = hkUref;
	this->stubHkUref = stubHkUref;
	this->refPlnrMMaterial = refPlnrMMaterial;
	this->stubRefPlnrMMaterial = stubRefPlnrMMaterial;
	this->ixVTtype = ixVTtype;
	this->srefIxVTtype = srefIxVTtype;
	this->titIxVTtype = titIxVTtype;
};

void PlnrQLyrList::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "PlnrQLyrList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "srf", sref);
		writeString(wr, "typ", srefIxVBasetype);
		writeString(wr, "typ2", titIxVBasetype);
		writeString(wr, "hkt", srefHkIxVTbl);
		writeString(wr, "hkt2", titHkIxVTbl);
		writeString(wr, "hku", stubHkUref);
		writeString(wr, "mat", stubRefPlnrMMaterial);
		writeString(wr, "tty", srefIxVTtype);
		writeString(wr, "tty2", titIxVTtype);
	} else {
		writeString(wr, "sref", sref);
		writeString(wr, "srefIxVBasetype", srefIxVBasetype);
		writeString(wr, "titIxVBasetype", titIxVBasetype);
		writeString(wr, "srefHkIxVTbl", srefHkIxVTbl);
		writeString(wr, "titHkIxVTbl", titHkIxVTbl);
		writeString(wr, "stubHkUref", stubHkUref);
		writeString(wr, "stubRefPlnrMMaterial", stubRefPlnrMMaterial);
		writeString(wr, "srefIxVTtype", srefIxVTtype);
		writeString(wr, "titIxVTtype", titIxVTtype);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListPlnrQLyrList
 ******************************************************************************/

ListPlnrQLyrList::ListPlnrQLyrList() {
};

ListPlnrQLyrList::ListPlnrQLyrList(
			const ListPlnrQLyrList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQLyrList(*(src.nodes[i]));
};

ListPlnrQLyrList::~ListPlnrQLyrList() {
	clear();
};

void ListPlnrQLyrList::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrQLyrList::size() const {
	return(nodes.size());
};

void ListPlnrQLyrList::append(
			PlnrQLyrList* rec
		) {
	nodes.push_back(rec);
};

ListPlnrQLyrList& ListPlnrQLyrList::operator=(
			const ListPlnrQLyrList& src
		) {
	PlnrQLyrList* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrQLyrList(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListPlnrQLyrList::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListPlnrQLyrList";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblPlnrQLyrList
 ******************************************************************************/

TblPlnrQLyrList::TblPlnrQLyrList() {
};

TblPlnrQLyrList::~TblPlnrQLyrList() {
};

bool TblPlnrQLyrList::loadRecBySQL(
			const string& sqlstr
			, PlnrQLyrList** rec
		) {
	return false;
};

ubigint TblPlnrQLyrList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQLyrList& rst
		) {
	return 0;
};

void TblPlnrQLyrList::insertRec(
			PlnrQLyrList* rec
		) {
};

ubigint TblPlnrQLyrList::insertNewRec(
			PlnrQLyrList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const ubigint x1RefPlnrMDesign
			, const uint ixVBasetype
			, const string srefIxVBasetype
			, const string titIxVBasetype
			, const uint hkIxVTbl
			, const string srefHkIxVTbl
			, const string titHkIxVTbl
			, const ubigint hkUref
			, const string stubHkUref
			, const ubigint refPlnrMMaterial
			, const string stubRefPlnrMMaterial
			, const uint ixVTtype
			, const string srefIxVTtype
			, const string titIxVTtype
		) {
	ubigint retval = 0;
	PlnrQLyrList* _rec = NULL;

	_rec = new PlnrQLyrList(0, jref, jnum, ref, sref, x1RefPlnrMDesign, ixVBasetype, srefIxVBasetype, titIxVBasetype, hkIxVTbl, srefHkIxVTbl, titHkIxVTbl, hkUref, stubHkUref, refPlnrMMaterial, stubRefPlnrMMaterial, ixVTtype, srefIxVTtype, titIxVTtype);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrQLyrList::appendNewRecToRst(
			ListPlnrQLyrList& rst
			, PlnrQLyrList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const ubigint x1RefPlnrMDesign
			, const uint ixVBasetype
			, const string srefIxVBasetype
			, const string titIxVBasetype
			, const uint hkIxVTbl
			, const string srefHkIxVTbl
			, const string titHkIxVTbl
			, const ubigint hkUref
			, const string stubHkUref
			, const ubigint refPlnrMMaterial
			, const string stubRefPlnrMMaterial
			, const uint ixVTtype
			, const string srefIxVTtype
			, const string titIxVTtype
		) {
	ubigint retval = 0;
	PlnrQLyrList* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, sref, x1RefPlnrMDesign, ixVBasetype, srefIxVBasetype, titIxVBasetype, hkIxVTbl, srefHkIxVTbl, titHkIxVTbl, hkUref, stubHkUref, refPlnrMMaterial, stubRefPlnrMMaterial, ixVTtype, srefIxVTtype, titIxVTtype);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrQLyrList::insertRst(
			ListPlnrQLyrList& rst
		) {
};

void TblPlnrQLyrList::updateRec(
			PlnrQLyrList* rec
		) {
};

void TblPlnrQLyrList::updateRst(
			ListPlnrQLyrList& rst
		) {
};

void TblPlnrQLyrList::removeRecByQref(
			ubigint qref
		) {
};

void TblPlnrQLyrList::removeRstByJref(
			ubigint jref
		) {
};

bool TblPlnrQLyrList::loadRecByQref(
			ubigint qref
			, PlnrQLyrList** rec
		) {
	return false;
};

ubigint TblPlnrQLyrList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQLyrList& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrQLyrList
 ******************************************************************************/

MyTblPlnrQLyrList::MyTblPlnrQLyrList() : TblPlnrQLyrList(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblPlnrQLyrList::~MyTblPlnrQLyrList() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblPlnrQLyrList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrQLyrList (jref, jnum, ref, sref, x1RefPlnrMDesign, ixVBasetype, hkIxVTbl, hkUref, refPlnrMMaterial, ixVTtype) VALUES (?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrQLyrList SET jref = ?, jnum = ?, ref = ?, sref = ?, x1RefPlnrMDesign = ?, ixVBasetype = ?, hkIxVTbl = ?, hkUref = ?, refPlnrMMaterial = ?, ixVTtype = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblPlnrQLyrList WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblPlnrQLyrList WHERE jref = ?", false);
};

bool MyTblPlnrQLyrList::loadRecBySQL(
			const string& sqlstr
			, PlnrQLyrList** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrQLyrList* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQLyrList / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrQLyrList();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->sref.assign(dbrow[4], dblengths[4]); else _rec->sref = "";
		if (dbrow[5]) _rec->x1RefPlnrMDesign = atoll((char*) dbrow[5]); else _rec->x1RefPlnrMDesign = 0;
		if (dbrow[6]) _rec->ixVBasetype = atol((char*) dbrow[6]); else _rec->ixVBasetype = 0;
		if (dbrow[7]) _rec->hkIxVTbl = atol((char*) dbrow[7]); else _rec->hkIxVTbl = 0;
		if (dbrow[8]) _rec->hkUref = atoll((char*) dbrow[8]); else _rec->hkUref = 0;
		if (dbrow[9]) _rec->refPlnrMMaterial = atoll((char*) dbrow[9]); else _rec->refPlnrMMaterial = 0;
		if (dbrow[10]) _rec->ixVTtype = atol((char*) dbrow[10]); else _rec->ixVTtype = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrQLyrList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQLyrList& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrQLyrList* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQLyrList / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrQLyrList();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->sref.assign(dbrow[4], dblengths[4]); else rec->sref = "";
			if (dbrow[5]) rec->x1RefPlnrMDesign = atoll((char*) dbrow[5]); else rec->x1RefPlnrMDesign = 0;
			if (dbrow[6]) rec->ixVBasetype = atol((char*) dbrow[6]); else rec->ixVBasetype = 0;
			if (dbrow[7]) rec->hkIxVTbl = atol((char*) dbrow[7]); else rec->hkIxVTbl = 0;
			if (dbrow[8]) rec->hkUref = atoll((char*) dbrow[8]); else rec->hkUref = 0;
			if (dbrow[9]) rec->refPlnrMMaterial = atoll((char*) dbrow[9]); else rec->refPlnrMMaterial = 0;
			if (dbrow[10]) rec->ixVTtype = atol((char*) dbrow[10]); else rec->ixVTtype = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrQLyrList::insertRec(
			PlnrQLyrList* rec
		) {
	unsigned long l[10]; my_bool n[10]; my_bool e[10];

	l[3] = rec->sref.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->x1RefPlnrMDesign,&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->ixVBasetype,&(l[5]),&(n[5]),&(e[5])),
		bindUint(&rec->hkIxVTbl,&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->hkUref,&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->refPlnrMMaterial,&(l[8]),&(n[8]),&(e[8])),
		bindUint(&rec->ixVTtype,&(l[9]),&(n[9]),&(e[9]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQLyrList / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQLyrList / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblPlnrQLyrList::insertRst(
			ListPlnrQLyrList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblPlnrQLyrList::updateRec(
			PlnrQLyrList* rec
		) {
	unsigned long l[11]; my_bool n[11]; my_bool e[11];

	l[3] = rec->sref.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])), 
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])), 
		bindUbigint(&rec->x1RefPlnrMDesign,&(l[4]),&(n[4]),&(e[4])), 
		bindUint(&rec->ixVBasetype,&(l[5]),&(n[5]),&(e[5])), 
		bindUint(&rec->hkIxVTbl,&(l[6]),&(n[6]),&(e[6])), 
		bindUbigint(&rec->hkUref,&(l[7]),&(n[7]),&(e[7])), 
		bindUbigint(&rec->refPlnrMMaterial,&(l[8]),&(n[8]),&(e[8])), 
		bindUint(&rec->ixVTtype,&(l[9]),&(n[9]),&(e[9])), 
		bindUbigint(&rec->qref,&(l[10]),&(n[10]),&(e[10]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQLyrList / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQLyrList / stmtUpdateRec)\n");
};

void MyTblPlnrQLyrList::updateRst(
			ListPlnrQLyrList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblPlnrQLyrList::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQLyrList / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQLyrList / stmtRemoveRecByQref)\n");
};

void MyTblPlnrQLyrList::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQLyrList / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQLyrList / stmtRemoveRstByJref)\n");
};

bool MyTblPlnrQLyrList::loadRecByQref(
			ubigint qref
			, PlnrQLyrList** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrQLyrList WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblPlnrQLyrList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQLyrList& rst
		) {
	return loadRstBySQL("SELECT * FROM TblPlnrQLyrList WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrQLyrList
 ******************************************************************************/

PgTblPlnrQLyrList::PgTblPlnrQLyrList() : TblPlnrQLyrList(), PgTable() {
};

PgTblPlnrQLyrList::~PgTblPlnrQLyrList() {
};

void PgTblPlnrQLyrList::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrQLyrList_insertRec", "INSERT INTO TblPlnrQLyrList (jref, jnum, ref, sref, x1RefPlnrMDesign, ixVBasetype, hkIxVTbl, hkUref, refPlnrMMaterial, ixVTtype) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10) RETURNING qref", 10, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQLyrList_updateRec", "UPDATE TblPlnrQLyrList SET jref = $1, jnum = $2, ref = $3, sref = $4, x1RefPlnrMDesign = $5, ixVBasetype = $6, hkIxVTbl = $7, hkUref = $8, refPlnrMMaterial = $9, ixVTtype = $10 WHERE qref = $11", 11, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQLyrList_removeRecByQref", "DELETE FROM TblPlnrQLyrList WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQLyrList_removeRstByJref", "DELETE FROM TblPlnrQLyrList WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrQLyrList_loadRecByQref", "SELECT qref, jref, jnum, ref, sref, x1RefPlnrMDesign, ixVBasetype, hkIxVTbl, hkUref, refPlnrMMaterial, ixVTtype FROM TblPlnrQLyrList WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQLyrList_loadRstByJref", "SELECT qref, jref, jnum, ref, sref, x1RefPlnrMDesign, ixVBasetype, hkIxVTbl, hkUref, refPlnrMMaterial, ixVTtype FROM TblPlnrQLyrList WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrQLyrList::loadRec(
			PGresult* res
			, PlnrQLyrList** rec
		) {
	char* ptr;

	PlnrQLyrList* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrQLyrList();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "x1refplnrmdesign"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "hkixvtbl"),
			PQfnumber(res, "hkuref"),
			PQfnumber(res, "refplnrmmaterial"),
			PQfnumber(res, "ixvttype")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->x1RefPlnrMDesign = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->ixVBasetype = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->hkIxVTbl = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->hkUref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->refPlnrMMaterial = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->ixVTtype = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrQLyrList::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrQLyrList& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrQLyrList* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "x1refplnrmdesign"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "hkixvtbl"),
			PQfnumber(res, "hkuref"),
			PQfnumber(res, "refplnrmmaterial"),
			PQfnumber(res, "ixvttype")
		};

		while (numread < numrow) {
			rec = new PlnrQLyrList();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->x1RefPlnrMDesign = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->ixVBasetype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->hkIxVTbl = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->hkUref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->refPlnrMMaterial = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[10]); rec->ixVTtype = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrQLyrList::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrQLyrList** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQLyrList / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQLyrList::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrQLyrList& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQLyrList / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblPlnrQLyrList::loadRecBySQL(
			const string& sqlstr
			, PlnrQLyrList** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQLyrList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQLyrList& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrQLyrList::insertRec(
			PlnrQLyrList* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _x1RefPlnrMDesign = htonl64(rec->x1RefPlnrMDesign);
	uint _ixVBasetype = htonl(rec->ixVBasetype);
	uint _hkIxVTbl = htonl(rec->hkIxVTbl);
	ubigint _hkUref = htonl64(rec->hkUref);
	ubigint _refPlnrMMaterial = htonl64(rec->refPlnrMMaterial);
	uint _ixVTtype = htonl(rec->ixVTtype);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->sref.c_str(),
		(char*) &_x1RefPlnrMDesign,
		(char*) &_ixVBasetype,
		(char*) &_hkIxVTbl,
		(char*) &_hkUref,
		(char*) &_refPlnrMMaterial,
		(char*) &_ixVTtype
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1, 0, 1, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblPlnrQLyrList_insertRec", 10, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQLyrList_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblPlnrQLyrList::insertRst(
			ListPlnrQLyrList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblPlnrQLyrList::updateRec(
			PlnrQLyrList* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _x1RefPlnrMDesign = htonl64(rec->x1RefPlnrMDesign);
	uint _ixVBasetype = htonl(rec->ixVBasetype);
	uint _hkIxVTbl = htonl(rec->hkIxVTbl);
	ubigint _hkUref = htonl64(rec->hkUref);
	ubigint _refPlnrMMaterial = htonl64(rec->refPlnrMMaterial);
	uint _ixVTtype = htonl(rec->ixVTtype);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->sref.c_str(),
		(char*) &_x1RefPlnrMDesign,
		(char*) &_ixVBasetype,
		(char*) &_hkIxVTbl,
		(char*) &_hkUref,
		(char*) &_refPlnrMMaterial,
		(char*) &_ixVTtype,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblPlnrQLyrList_updateRec", 11, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQLyrList_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrQLyrList::updateRst(
			ListPlnrQLyrList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblPlnrQLyrList::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblPlnrQLyrList_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQLyrList_removeRecByQref)\n");

	PQclear(res);
};

void PgTblPlnrQLyrList::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblPlnrQLyrList_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQLyrList_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblPlnrQLyrList::loadRecByQref(
			ubigint qref
			, PlnrQLyrList** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrQLyrList_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblPlnrQLyrList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQLyrList& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrQLyrList_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

