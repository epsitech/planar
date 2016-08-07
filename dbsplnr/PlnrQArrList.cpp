/**
  * \file PlnrQArrList.cpp
  * Dbs and XML wrapper for table TblPlnrQArrList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQArrList.h"

/******************************************************************************
 class PlnrQArrList
 ******************************************************************************/

PlnrQArrList::PlnrQArrList(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const ubigint refPlnrMTapeout
			, const string stubRefPlnrMTapeout
			, const ubigint refPlnrMDesign
			, const string stubRefPlnrMDesign
			, const usmallint I
			, const usmallint J
			, const usmallint K
			, const usmallint L
			, const usmallint M
			, const usmallint N
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->sref = sref;
	this->refPlnrMTapeout = refPlnrMTapeout;
	this->stubRefPlnrMTapeout = stubRefPlnrMTapeout;
	this->refPlnrMDesign = refPlnrMDesign;
	this->stubRefPlnrMDesign = stubRefPlnrMDesign;
	this->I = I;
	this->J = J;
	this->K = K;
	this->L = L;
	this->M = M;
	this->N = N;
};

void PlnrQArrList::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "PlnrQArrList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "srf", sref);
		writeString(wr, "tpo", stubRefPlnrMTapeout);
		writeString(wr, "dsn", stubRefPlnrMDesign);
		writeUint(wr, "i", I);
		writeUint(wr, "j", J);
		writeUint(wr, "k", K);
		writeUint(wr, "l", L);
		writeUint(wr, "m", M);
		writeUint(wr, "n", N);
	} else {
		writeString(wr, "sref", sref);
		writeString(wr, "stubRefPlnrMTapeout", stubRefPlnrMTapeout);
		writeString(wr, "stubRefPlnrMDesign", stubRefPlnrMDesign);
		writeUint(wr, "I", I);
		writeUint(wr, "J", J);
		writeUint(wr, "K", K);
		writeUint(wr, "L", L);
		writeUint(wr, "M", M);
		writeUint(wr, "N", N);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListPlnrQArrList
 ******************************************************************************/

ListPlnrQArrList::ListPlnrQArrList() {
};

ListPlnrQArrList::ListPlnrQArrList(
			const ListPlnrQArrList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQArrList(*(src.nodes[i]));
};

ListPlnrQArrList::~ListPlnrQArrList() {
	clear();
};

void ListPlnrQArrList::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrQArrList::size() const {
	return(nodes.size());
};

void ListPlnrQArrList::append(
			PlnrQArrList* rec
		) {
	nodes.push_back(rec);
};

ListPlnrQArrList& ListPlnrQArrList::operator=(
			const ListPlnrQArrList& src
		) {
	PlnrQArrList* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrQArrList(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListPlnrQArrList::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListPlnrQArrList";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblPlnrQArrList
 ******************************************************************************/

TblPlnrQArrList::TblPlnrQArrList() {
};

TblPlnrQArrList::~TblPlnrQArrList() {
};

bool TblPlnrQArrList::loadRecBySQL(
			const string& sqlstr
			, PlnrQArrList** rec
		) {
	return false;
};

ubigint TblPlnrQArrList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQArrList& rst
		) {
	return 0;
};

void TblPlnrQArrList::insertRec(
			PlnrQArrList* rec
		) {
};

ubigint TblPlnrQArrList::insertNewRec(
			PlnrQArrList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const ubigint refPlnrMTapeout
			, const string stubRefPlnrMTapeout
			, const ubigint refPlnrMDesign
			, const string stubRefPlnrMDesign
			, const usmallint I
			, const usmallint J
			, const usmallint K
			, const usmallint L
			, const usmallint M
			, const usmallint N
		) {
	ubigint retval = 0;
	PlnrQArrList* _rec = NULL;

	_rec = new PlnrQArrList(0, jref, jnum, ref, sref, refPlnrMTapeout, stubRefPlnrMTapeout, refPlnrMDesign, stubRefPlnrMDesign, I, J, K, L, M, N);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrQArrList::appendNewRecToRst(
			ListPlnrQArrList& rst
			, PlnrQArrList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const ubigint refPlnrMTapeout
			, const string stubRefPlnrMTapeout
			, const ubigint refPlnrMDesign
			, const string stubRefPlnrMDesign
			, const usmallint I
			, const usmallint J
			, const usmallint K
			, const usmallint L
			, const usmallint M
			, const usmallint N
		) {
	ubigint retval = 0;
	PlnrQArrList* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, sref, refPlnrMTapeout, stubRefPlnrMTapeout, refPlnrMDesign, stubRefPlnrMDesign, I, J, K, L, M, N);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrQArrList::insertRst(
			ListPlnrQArrList& rst
		) {
};

void TblPlnrQArrList::updateRec(
			PlnrQArrList* rec
		) {
};

void TblPlnrQArrList::updateRst(
			ListPlnrQArrList& rst
		) {
};

void TblPlnrQArrList::removeRecByQref(
			ubigint qref
		) {
};

void TblPlnrQArrList::removeRstByJref(
			ubigint jref
		) {
};

bool TblPlnrQArrList::loadRecByQref(
			ubigint qref
			, PlnrQArrList** rec
		) {
	return false;
};

ubigint TblPlnrQArrList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQArrList& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrQArrList
 ******************************************************************************/

MyTblPlnrQArrList::MyTblPlnrQArrList() : TblPlnrQArrList(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblPlnrQArrList::~MyTblPlnrQArrList() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblPlnrQArrList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrQArrList (jref, jnum, ref, sref, refPlnrMTapeout, refPlnrMDesign, I, J, K, L, M, N) VALUES (?,?,?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrQArrList SET jref = ?, jnum = ?, ref = ?, sref = ?, refPlnrMTapeout = ?, refPlnrMDesign = ?, I = ?, J = ?, K = ?, L = ?, M = ?, N = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblPlnrQArrList WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblPlnrQArrList WHERE jref = ?", false);
};

bool MyTblPlnrQArrList::loadRecBySQL(
			const string& sqlstr
			, PlnrQArrList** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrQArrList* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQArrList / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrQArrList();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->sref.assign(dbrow[4], dblengths[4]); else _rec->sref = "";
		if (dbrow[5]) _rec->refPlnrMTapeout = atoll((char*) dbrow[5]); else _rec->refPlnrMTapeout = 0;
		if (dbrow[6]) _rec->refPlnrMDesign = atoll((char*) dbrow[6]); else _rec->refPlnrMDesign = 0;
		if (dbrow[7]) _rec->I = atoi((char*) dbrow[7]); else _rec->I = 0;
		if (dbrow[8]) _rec->J = atoi((char*) dbrow[8]); else _rec->J = 0;
		if (dbrow[9]) _rec->K = atoi((char*) dbrow[9]); else _rec->K = 0;
		if (dbrow[10]) _rec->L = atoi((char*) dbrow[10]); else _rec->L = 0;
		if (dbrow[11]) _rec->M = atoi((char*) dbrow[11]); else _rec->M = 0;
		if (dbrow[12]) _rec->N = atoi((char*) dbrow[12]); else _rec->N = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrQArrList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQArrList& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrQArrList* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQArrList / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrQArrList();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->sref.assign(dbrow[4], dblengths[4]); else rec->sref = "";
			if (dbrow[5]) rec->refPlnrMTapeout = atoll((char*) dbrow[5]); else rec->refPlnrMTapeout = 0;
			if (dbrow[6]) rec->refPlnrMDesign = atoll((char*) dbrow[6]); else rec->refPlnrMDesign = 0;
			if (dbrow[7]) rec->I = atoi((char*) dbrow[7]); else rec->I = 0;
			if (dbrow[8]) rec->J = atoi((char*) dbrow[8]); else rec->J = 0;
			if (dbrow[9]) rec->K = atoi((char*) dbrow[9]); else rec->K = 0;
			if (dbrow[10]) rec->L = atoi((char*) dbrow[10]); else rec->L = 0;
			if (dbrow[11]) rec->M = atoi((char*) dbrow[11]); else rec->M = 0;
			if (dbrow[12]) rec->N = atoi((char*) dbrow[12]); else rec->N = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrQArrList::insertRec(
			PlnrQArrList* rec
		) {
	unsigned long l[12]; my_bool n[12]; my_bool e[12];

	l[3] = rec->sref.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->refPlnrMTapeout,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->refPlnrMDesign,&(l[5]),&(n[5]),&(e[5])),
		bindUsmallint(&rec->I,&(l[6]),&(n[6]),&(e[6])),
		bindUsmallint(&rec->J,&(l[7]),&(n[7]),&(e[7])),
		bindUsmallint(&rec->K,&(l[8]),&(n[8]),&(e[8])),
		bindUsmallint(&rec->L,&(l[9]),&(n[9]),&(e[9])),
		bindUsmallint(&rec->M,&(l[10]),&(n[10]),&(e[10])),
		bindUsmallint(&rec->N,&(l[11]),&(n[11]),&(e[11]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQArrList / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQArrList / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblPlnrQArrList::insertRst(
			ListPlnrQArrList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblPlnrQArrList::updateRec(
			PlnrQArrList* rec
		) {
	unsigned long l[13]; my_bool n[13]; my_bool e[13];

	l[3] = rec->sref.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])), 
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])), 
		bindUbigint(&rec->refPlnrMTapeout,&(l[4]),&(n[4]),&(e[4])), 
		bindUbigint(&rec->refPlnrMDesign,&(l[5]),&(n[5]),&(e[5])), 
		bindUsmallint(&rec->I,&(l[6]),&(n[6]),&(e[6])), 
		bindUsmallint(&rec->J,&(l[7]),&(n[7]),&(e[7])), 
		bindUsmallint(&rec->K,&(l[8]),&(n[8]),&(e[8])), 
		bindUsmallint(&rec->L,&(l[9]),&(n[9]),&(e[9])), 
		bindUsmallint(&rec->M,&(l[10]),&(n[10]),&(e[10])), 
		bindUsmallint(&rec->N,&(l[11]),&(n[11]),&(e[11])), 
		bindUbigint(&rec->qref,&(l[12]),&(n[12]),&(e[12]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQArrList / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQArrList / stmtUpdateRec)\n");
};

void MyTblPlnrQArrList::updateRst(
			ListPlnrQArrList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblPlnrQArrList::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQArrList / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQArrList / stmtRemoveRecByQref)\n");
};

void MyTblPlnrQArrList::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQArrList / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQArrList / stmtRemoveRstByJref)\n");
};

bool MyTblPlnrQArrList::loadRecByQref(
			ubigint qref
			, PlnrQArrList** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrQArrList WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblPlnrQArrList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQArrList& rst
		) {
	return loadRstBySQL("SELECT * FROM TblPlnrQArrList WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrQArrList
 ******************************************************************************/

PgTblPlnrQArrList::PgTblPlnrQArrList() : TblPlnrQArrList(), PgTable() {
};

PgTblPlnrQArrList::~PgTblPlnrQArrList() {
};

void PgTblPlnrQArrList::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrQArrList_insertRec", "INSERT INTO TblPlnrQArrList (jref, jnum, ref, sref, refPlnrMTapeout, refPlnrMDesign, I, J, K, L, M, N) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11,$12) RETURNING qref", 12, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQArrList_updateRec", "UPDATE TblPlnrQArrList SET jref = $1, jnum = $2, ref = $3, sref = $4, refPlnrMTapeout = $5, refPlnrMDesign = $6, I = $7, J = $8, K = $9, L = $10, M = $11, N = $12 WHERE qref = $13", 13, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQArrList_removeRecByQref", "DELETE FROM TblPlnrQArrList WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQArrList_removeRstByJref", "DELETE FROM TblPlnrQArrList WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrQArrList_loadRecByQref", "SELECT qref, jref, jnum, ref, sref, refPlnrMTapeout, refPlnrMDesign, I, J, K, L, M, N FROM TblPlnrQArrList WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQArrList_loadRstByJref", "SELECT qref, jref, jnum, ref, sref, refPlnrMTapeout, refPlnrMDesign, I, J, K, L, M, N FROM TblPlnrQArrList WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrQArrList::loadRec(
			PGresult* res
			, PlnrQArrList** rec
		) {
	char* ptr;

	PlnrQArrList* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrQArrList();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "refplnrmtapeout"),
			PQfnumber(res, "refplnrmdesign"),
			PQfnumber(res, "i"),
			PQfnumber(res, "j"),
			PQfnumber(res, "k"),
			PQfnumber(res, "l"),
			PQfnumber(res, "m"),
			PQfnumber(res, "n")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->refPlnrMTapeout = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->refPlnrMDesign = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->I = atoi(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->J = atoi(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->K = atoi(ptr);
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->L = atoi(ptr);
		ptr = PQgetvalue(res, 0, fnum[11]); _rec->M = atoi(ptr);
		ptr = PQgetvalue(res, 0, fnum[12]); _rec->N = atoi(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrQArrList::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrQArrList& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrQArrList* rec;

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
			PQfnumber(res, "refplnrmtapeout"),
			PQfnumber(res, "refplnrmdesign"),
			PQfnumber(res, "i"),
			PQfnumber(res, "j"),
			PQfnumber(res, "k"),
			PQfnumber(res, "l"),
			PQfnumber(res, "m"),
			PQfnumber(res, "n")
		};

		while (numread < numrow) {
			rec = new PlnrQArrList();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->refPlnrMTapeout = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->refPlnrMDesign = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->I = atoi(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->J = atoi(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->K = atoi(ptr);
			ptr = PQgetvalue(res, numread, fnum[10]); rec->L = atoi(ptr);
			ptr = PQgetvalue(res, numread, fnum[11]); rec->M = atoi(ptr);
			ptr = PQgetvalue(res, numread, fnum[12]); rec->N = atoi(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrQArrList::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrQArrList** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQArrList / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQArrList::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrQArrList& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQArrList / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblPlnrQArrList::loadRecBySQL(
			const string& sqlstr
			, PlnrQArrList** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQArrList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQArrList& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrQArrList::insertRec(
			PlnrQArrList* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _refPlnrMTapeout = htonl64(rec->refPlnrMTapeout);
	ubigint _refPlnrMDesign = htonl64(rec->refPlnrMDesign);
	usmallint _I = htons(rec->I);
	usmallint _J = htons(rec->J);
	usmallint _K = htons(rec->K);
	usmallint _L = htons(rec->L);
	usmallint _M = htons(rec->M);
	usmallint _N = htons(rec->N);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->sref.c_str(),
		(char*) &_refPlnrMTapeout,
		(char*) &_refPlnrMDesign,
		(char*) &_I,
		(char*) &_J,
		(char*) &_K,
		(char*) &_L,
		(char*) &_M,
		(char*) &_N
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(usmallint),
		sizeof(usmallint),
		sizeof(usmallint),
		sizeof(usmallint),
		sizeof(usmallint),
		sizeof(usmallint)
	};
	const int f[] = {1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblPlnrQArrList_insertRec", 12, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQArrList_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblPlnrQArrList::insertRst(
			ListPlnrQArrList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblPlnrQArrList::updateRec(
			PlnrQArrList* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _refPlnrMTapeout = htonl64(rec->refPlnrMTapeout);
	ubigint _refPlnrMDesign = htonl64(rec->refPlnrMDesign);
	usmallint _I = htons(rec->I);
	usmallint _J = htons(rec->J);
	usmallint _K = htons(rec->K);
	usmallint _L = htons(rec->L);
	usmallint _M = htons(rec->M);
	usmallint _N = htons(rec->N);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->sref.c_str(),
		(char*) &_refPlnrMTapeout,
		(char*) &_refPlnrMDesign,
		(char*) &_I,
		(char*) &_J,
		(char*) &_K,
		(char*) &_L,
		(char*) &_M,
		(char*) &_N,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(usmallint),
		sizeof(usmallint),
		sizeof(usmallint),
		sizeof(usmallint),
		sizeof(usmallint),
		sizeof(usmallint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblPlnrQArrList_updateRec", 13, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQArrList_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrQArrList::updateRst(
			ListPlnrQArrList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblPlnrQArrList::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblPlnrQArrList_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQArrList_removeRecByQref)\n");

	PQclear(res);
};

void PgTblPlnrQArrList::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblPlnrQArrList_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQArrList_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblPlnrQArrList::loadRecByQref(
			ubigint qref
			, PlnrQArrList** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrQArrList_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblPlnrQArrList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQArrList& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrQArrList_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

