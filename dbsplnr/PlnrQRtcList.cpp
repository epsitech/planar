/**
  * \file PlnrQRtcList.cpp
  * Dbs and XML wrapper for table TblPlnrQRtcList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQRtcList.h"

/******************************************************************************
 class PlnrQRtcList
 ******************************************************************************/

PlnrQRtcList::PlnrQRtcList(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const uint hkIxVTbl
			, const string srefHkIxVTbl
			, const string titHkIxVTbl
			, const ubigint hkUref
			, const string stubHkUref
			, const ubigint refPlnrMDesign
			, const string stubRefPlnrMDesign
			, const ubigint refPlnrMLayer
			, const string stubRefPlnrMLayer
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->sref = sref;
	this->hkIxVTbl = hkIxVTbl;
	this->srefHkIxVTbl = srefHkIxVTbl;
	this->titHkIxVTbl = titHkIxVTbl;
	this->hkUref = hkUref;
	this->stubHkUref = stubHkUref;
	this->refPlnrMDesign = refPlnrMDesign;
	this->stubRefPlnrMDesign = stubRefPlnrMDesign;
	this->refPlnrMLayer = refPlnrMLayer;
	this->stubRefPlnrMLayer = stubRefPlnrMLayer;
};

void PlnrQRtcList::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "PlnrQRtcList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "srf", sref);
		writeString(wr, "hkt", srefHkIxVTbl);
		writeString(wr, "hkt2", titHkIxVTbl);
		writeString(wr, "hku", stubHkUref);
		writeString(wr, "dsn", stubRefPlnrMDesign);
		writeString(wr, "lyr", stubRefPlnrMLayer);
	} else {
		writeString(wr, "sref", sref);
		writeString(wr, "srefHkIxVTbl", srefHkIxVTbl);
		writeString(wr, "titHkIxVTbl", titHkIxVTbl);
		writeString(wr, "stubHkUref", stubHkUref);
		writeString(wr, "stubRefPlnrMDesign", stubRefPlnrMDesign);
		writeString(wr, "stubRefPlnrMLayer", stubRefPlnrMLayer);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListPlnrQRtcList
 ******************************************************************************/

ListPlnrQRtcList::ListPlnrQRtcList() {
};

ListPlnrQRtcList::ListPlnrQRtcList(
			const ListPlnrQRtcList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQRtcList(*(src.nodes[i]));
};

ListPlnrQRtcList::~ListPlnrQRtcList() {
	clear();
};

void ListPlnrQRtcList::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrQRtcList::size() const {
	return(nodes.size());
};

void ListPlnrQRtcList::append(
			PlnrQRtcList* rec
		) {
	nodes.push_back(rec);
};

ListPlnrQRtcList& ListPlnrQRtcList::operator=(
			const ListPlnrQRtcList& src
		) {
	PlnrQRtcList* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrQRtcList(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListPlnrQRtcList::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListPlnrQRtcList";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblPlnrQRtcList
 ******************************************************************************/

TblPlnrQRtcList::TblPlnrQRtcList() {
};

TblPlnrQRtcList::~TblPlnrQRtcList() {
};

bool TblPlnrQRtcList::loadRecBySQL(
			const string& sqlstr
			, PlnrQRtcList** rec
		) {
	return false;
};

ubigint TblPlnrQRtcList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQRtcList& rst
		) {
	return 0;
};

void TblPlnrQRtcList::insertRec(
			PlnrQRtcList* rec
		) {
};

ubigint TblPlnrQRtcList::insertNewRec(
			PlnrQRtcList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const uint hkIxVTbl
			, const string srefHkIxVTbl
			, const string titHkIxVTbl
			, const ubigint hkUref
			, const string stubHkUref
			, const ubigint refPlnrMDesign
			, const string stubRefPlnrMDesign
			, const ubigint refPlnrMLayer
			, const string stubRefPlnrMLayer
		) {
	ubigint retval = 0;
	PlnrQRtcList* _rec = NULL;

	_rec = new PlnrQRtcList(0, jref, jnum, ref, sref, hkIxVTbl, srefHkIxVTbl, titHkIxVTbl, hkUref, stubHkUref, refPlnrMDesign, stubRefPlnrMDesign, refPlnrMLayer, stubRefPlnrMLayer);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrQRtcList::appendNewRecToRst(
			ListPlnrQRtcList& rst
			, PlnrQRtcList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const uint hkIxVTbl
			, const string srefHkIxVTbl
			, const string titHkIxVTbl
			, const ubigint hkUref
			, const string stubHkUref
			, const ubigint refPlnrMDesign
			, const string stubRefPlnrMDesign
			, const ubigint refPlnrMLayer
			, const string stubRefPlnrMLayer
		) {
	ubigint retval = 0;
	PlnrQRtcList* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, sref, hkIxVTbl, srefHkIxVTbl, titHkIxVTbl, hkUref, stubHkUref, refPlnrMDesign, stubRefPlnrMDesign, refPlnrMLayer, stubRefPlnrMLayer);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrQRtcList::insertRst(
			ListPlnrQRtcList& rst
		) {
};

void TblPlnrQRtcList::updateRec(
			PlnrQRtcList* rec
		) {
};

void TblPlnrQRtcList::updateRst(
			ListPlnrQRtcList& rst
		) {
};

void TblPlnrQRtcList::removeRecByQref(
			ubigint qref
		) {
};

void TblPlnrQRtcList::removeRstByJref(
			ubigint jref
		) {
};

bool TblPlnrQRtcList::loadRecByQref(
			ubigint qref
			, PlnrQRtcList** rec
		) {
	return false;
};

ubigint TblPlnrQRtcList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQRtcList& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrQRtcList
 ******************************************************************************/

MyTblPlnrQRtcList::MyTblPlnrQRtcList() : TblPlnrQRtcList(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblPlnrQRtcList::~MyTblPlnrQRtcList() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblPlnrQRtcList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrQRtcList (jref, jnum, ref, sref, hkIxVTbl, hkUref, refPlnrMDesign, refPlnrMLayer) VALUES (?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrQRtcList SET jref = ?, jnum = ?, ref = ?, sref = ?, hkIxVTbl = ?, hkUref = ?, refPlnrMDesign = ?, refPlnrMLayer = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblPlnrQRtcList WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblPlnrQRtcList WHERE jref = ?", false);
};

bool MyTblPlnrQRtcList::loadRecBySQL(
			const string& sqlstr
			, PlnrQRtcList** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrQRtcList* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQRtcList / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrQRtcList();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->sref.assign(dbrow[4], dblengths[4]); else _rec->sref = "";
		if (dbrow[5]) _rec->hkIxVTbl = atol((char*) dbrow[5]); else _rec->hkIxVTbl = 0;
		if (dbrow[6]) _rec->hkUref = atoll((char*) dbrow[6]); else _rec->hkUref = 0;
		if (dbrow[7]) _rec->refPlnrMDesign = atoll((char*) dbrow[7]); else _rec->refPlnrMDesign = 0;
		if (dbrow[8]) _rec->refPlnrMLayer = atoll((char*) dbrow[8]); else _rec->refPlnrMLayer = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrQRtcList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQRtcList& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrQRtcList* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQRtcList / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrQRtcList();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->sref.assign(dbrow[4], dblengths[4]); else rec->sref = "";
			if (dbrow[5]) rec->hkIxVTbl = atol((char*) dbrow[5]); else rec->hkIxVTbl = 0;
			if (dbrow[6]) rec->hkUref = atoll((char*) dbrow[6]); else rec->hkUref = 0;
			if (dbrow[7]) rec->refPlnrMDesign = atoll((char*) dbrow[7]); else rec->refPlnrMDesign = 0;
			if (dbrow[8]) rec->refPlnrMLayer = atoll((char*) dbrow[8]); else rec->refPlnrMLayer = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrQRtcList::insertRec(
			PlnrQRtcList* rec
		) {
	unsigned long l[8]; my_bool n[8]; my_bool e[8];

	l[3] = rec->sref.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->hkIxVTbl,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->hkUref,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->refPlnrMDesign,&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->refPlnrMLayer,&(l[7]),&(n[7]),&(e[7]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQRtcList / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQRtcList / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblPlnrQRtcList::insertRst(
			ListPlnrQRtcList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblPlnrQRtcList::updateRec(
			PlnrQRtcList* rec
		) {
	unsigned long l[9]; my_bool n[9]; my_bool e[9];

	l[3] = rec->sref.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])), 
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])), 
		bindUint(&rec->hkIxVTbl,&(l[4]),&(n[4]),&(e[4])), 
		bindUbigint(&rec->hkUref,&(l[5]),&(n[5]),&(e[5])), 
		bindUbigint(&rec->refPlnrMDesign,&(l[6]),&(n[6]),&(e[6])), 
		bindUbigint(&rec->refPlnrMLayer,&(l[7]),&(n[7]),&(e[7])), 
		bindUbigint(&rec->qref,&(l[8]),&(n[8]),&(e[8]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQRtcList / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQRtcList / stmtUpdateRec)\n");
};

void MyTblPlnrQRtcList::updateRst(
			ListPlnrQRtcList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblPlnrQRtcList::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQRtcList / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQRtcList / stmtRemoveRecByQref)\n");
};

void MyTblPlnrQRtcList::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQRtcList / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQRtcList / stmtRemoveRstByJref)\n");
};

bool MyTblPlnrQRtcList::loadRecByQref(
			ubigint qref
			, PlnrQRtcList** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrQRtcList WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblPlnrQRtcList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQRtcList& rst
		) {
	return loadRstBySQL("SELECT * FROM TblPlnrQRtcList WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrQRtcList
 ******************************************************************************/

PgTblPlnrQRtcList::PgTblPlnrQRtcList() : TblPlnrQRtcList(), PgTable() {
};

PgTblPlnrQRtcList::~PgTblPlnrQRtcList() {
};

void PgTblPlnrQRtcList::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrQRtcList_insertRec", "INSERT INTO TblPlnrQRtcList (jref, jnum, ref, sref, hkIxVTbl, hkUref, refPlnrMDesign, refPlnrMLayer) VALUES ($1,$2,$3,$4,$5,$6,$7,$8) RETURNING qref", 8, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQRtcList_updateRec", "UPDATE TblPlnrQRtcList SET jref = $1, jnum = $2, ref = $3, sref = $4, hkIxVTbl = $5, hkUref = $6, refPlnrMDesign = $7, refPlnrMLayer = $8 WHERE qref = $9", 9, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQRtcList_removeRecByQref", "DELETE FROM TblPlnrQRtcList WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQRtcList_removeRstByJref", "DELETE FROM TblPlnrQRtcList WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrQRtcList_loadRecByQref", "SELECT qref, jref, jnum, ref, sref, hkIxVTbl, hkUref, refPlnrMDesign, refPlnrMLayer FROM TblPlnrQRtcList WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQRtcList_loadRstByJref", "SELECT qref, jref, jnum, ref, sref, hkIxVTbl, hkUref, refPlnrMDesign, refPlnrMLayer FROM TblPlnrQRtcList WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrQRtcList::loadRec(
			PGresult* res
			, PlnrQRtcList** rec
		) {
	char* ptr;

	PlnrQRtcList* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrQRtcList();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "hkixvtbl"),
			PQfnumber(res, "hkuref"),
			PQfnumber(res, "refplnrmdesign"),
			PQfnumber(res, "refplnrmlayer")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->hkIxVTbl = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->hkUref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->refPlnrMDesign = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->refPlnrMLayer = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrQRtcList::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrQRtcList& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrQRtcList* rec;

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
			PQfnumber(res, "hkixvtbl"),
			PQfnumber(res, "hkuref"),
			PQfnumber(res, "refplnrmdesign"),
			PQfnumber(res, "refplnrmlayer")
		};

		while (numread < numrow) {
			rec = new PlnrQRtcList();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->hkIxVTbl = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->hkUref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->refPlnrMDesign = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->refPlnrMLayer = atoll(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrQRtcList::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrQRtcList** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQRtcList / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQRtcList::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrQRtcList& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQRtcList / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblPlnrQRtcList::loadRecBySQL(
			const string& sqlstr
			, PlnrQRtcList** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQRtcList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQRtcList& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrQRtcList::insertRec(
			PlnrQRtcList* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _hkIxVTbl = htonl(rec->hkIxVTbl);
	ubigint _hkUref = htonl64(rec->hkUref);
	ubigint _refPlnrMDesign = htonl64(rec->refPlnrMDesign);
	ubigint _refPlnrMLayer = htonl64(rec->refPlnrMLayer);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->sref.c_str(),
		(char*) &_hkIxVTbl,
		(char*) &_hkUref,
		(char*) &_refPlnrMDesign,
		(char*) &_refPlnrMLayer
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblPlnrQRtcList_insertRec", 8, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQRtcList_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblPlnrQRtcList::insertRst(
			ListPlnrQRtcList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblPlnrQRtcList::updateRec(
			PlnrQRtcList* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _hkIxVTbl = htonl(rec->hkIxVTbl);
	ubigint _hkUref = htonl64(rec->hkUref);
	ubigint _refPlnrMDesign = htonl64(rec->refPlnrMDesign);
	ubigint _refPlnrMLayer = htonl64(rec->refPlnrMLayer);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->sref.c_str(),
		(char*) &_hkIxVTbl,
		(char*) &_hkUref,
		(char*) &_refPlnrMDesign,
		(char*) &_refPlnrMLayer,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblPlnrQRtcList_updateRec", 9, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQRtcList_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrQRtcList::updateRst(
			ListPlnrQRtcList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblPlnrQRtcList::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblPlnrQRtcList_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQRtcList_removeRecByQref)\n");

	PQclear(res);
};

void PgTblPlnrQRtcList::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblPlnrQRtcList_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQRtcList_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblPlnrQRtcList::loadRecByQref(
			ubigint qref
			, PlnrQRtcList** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrQRtcList_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblPlnrQRtcList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQRtcList& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrQRtcList_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

