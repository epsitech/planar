/**
  * \file PlnrQMatList.cpp
  * Dbs and XML wrapper for table TblPlnrQMatList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQMatList.h"

/******************************************************************************
 class PlnrQMatList
 ******************************************************************************/

PlnrQMatList::PlnrQMatList(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const string Title
			, const uint ixVBasetype
			, const string srefIxVBasetype
			, const string titIxVBasetype
			, const ubigint refPlnrMCalc
			, const string stubRefPlnrMCalc
			, const ubigint modRefPlnrMMaterial
			, const string stubModRefPlnrMMaterial
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->sref = sref;
	this->Title = Title;
	this->ixVBasetype = ixVBasetype;
	this->srefIxVBasetype = srefIxVBasetype;
	this->titIxVBasetype = titIxVBasetype;
	this->refPlnrMCalc = refPlnrMCalc;
	this->stubRefPlnrMCalc = stubRefPlnrMCalc;
	this->modRefPlnrMMaterial = modRefPlnrMMaterial;
	this->stubModRefPlnrMMaterial = stubModRefPlnrMMaterial;
};

void PlnrQMatList::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "PlnrQMatList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "srf", sref);
		writeString(wr, "tit", Title);
		writeString(wr, "typ", srefIxVBasetype);
		writeString(wr, "typ2", titIxVBasetype);
		writeString(wr, "cal", stubRefPlnrMCalc);
		writeString(wr, "sup", stubModRefPlnrMMaterial);
	} else {
		writeString(wr, "sref", sref);
		writeString(wr, "Title", Title);
		writeString(wr, "srefIxVBasetype", srefIxVBasetype);
		writeString(wr, "titIxVBasetype", titIxVBasetype);
		writeString(wr, "stubRefPlnrMCalc", stubRefPlnrMCalc);
		writeString(wr, "stubModRefPlnrMMaterial", stubModRefPlnrMMaterial);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListPlnrQMatList
 ******************************************************************************/

ListPlnrQMatList::ListPlnrQMatList() {
};

ListPlnrQMatList::ListPlnrQMatList(
			const ListPlnrQMatList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQMatList(*(src.nodes[i]));
};

ListPlnrQMatList::~ListPlnrQMatList() {
	clear();
};

void ListPlnrQMatList::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrQMatList::size() const {
	return(nodes.size());
};

void ListPlnrQMatList::append(
			PlnrQMatList* rec
		) {
	nodes.push_back(rec);
};

ListPlnrQMatList& ListPlnrQMatList::operator=(
			const ListPlnrQMatList& src
		) {
	PlnrQMatList* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrQMatList(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListPlnrQMatList::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListPlnrQMatList";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblPlnrQMatList
 ******************************************************************************/

TblPlnrQMatList::TblPlnrQMatList() {
};

TblPlnrQMatList::~TblPlnrQMatList() {
};

bool TblPlnrQMatList::loadRecBySQL(
			const string& sqlstr
			, PlnrQMatList** rec
		) {
	return false;
};

ubigint TblPlnrQMatList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQMatList& rst
		) {
	return 0;
};

void TblPlnrQMatList::insertRec(
			PlnrQMatList* rec
		) {
};

ubigint TblPlnrQMatList::insertNewRec(
			PlnrQMatList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const string Title
			, const uint ixVBasetype
			, const string srefIxVBasetype
			, const string titIxVBasetype
			, const ubigint refPlnrMCalc
			, const string stubRefPlnrMCalc
			, const ubigint modRefPlnrMMaterial
			, const string stubModRefPlnrMMaterial
		) {
	ubigint retval = 0;
	PlnrQMatList* _rec = NULL;

	_rec = new PlnrQMatList(0, jref, jnum, ref, sref, Title, ixVBasetype, srefIxVBasetype, titIxVBasetype, refPlnrMCalc, stubRefPlnrMCalc, modRefPlnrMMaterial, stubModRefPlnrMMaterial);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrQMatList::appendNewRecToRst(
			ListPlnrQMatList& rst
			, PlnrQMatList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const string Title
			, const uint ixVBasetype
			, const string srefIxVBasetype
			, const string titIxVBasetype
			, const ubigint refPlnrMCalc
			, const string stubRefPlnrMCalc
			, const ubigint modRefPlnrMMaterial
			, const string stubModRefPlnrMMaterial
		) {
	ubigint retval = 0;
	PlnrQMatList* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, sref, Title, ixVBasetype, srefIxVBasetype, titIxVBasetype, refPlnrMCalc, stubRefPlnrMCalc, modRefPlnrMMaterial, stubModRefPlnrMMaterial);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrQMatList::insertRst(
			ListPlnrQMatList& rst
		) {
};

void TblPlnrQMatList::updateRec(
			PlnrQMatList* rec
		) {
};

void TblPlnrQMatList::updateRst(
			ListPlnrQMatList& rst
		) {
};

void TblPlnrQMatList::removeRecByQref(
			ubigint qref
		) {
};

void TblPlnrQMatList::removeRstByJref(
			ubigint jref
		) {
};

bool TblPlnrQMatList::loadRecByQref(
			ubigint qref
			, PlnrQMatList** rec
		) {
	return false;
};

ubigint TblPlnrQMatList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQMatList& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrQMatList
 ******************************************************************************/

MyTblPlnrQMatList::MyTblPlnrQMatList() : TblPlnrQMatList(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblPlnrQMatList::~MyTblPlnrQMatList() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblPlnrQMatList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrQMatList (jref, jnum, ref, sref, Title, ixVBasetype, refPlnrMCalc, modRefPlnrMMaterial) VALUES (?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrQMatList SET jref = ?, jnum = ?, ref = ?, sref = ?, Title = ?, ixVBasetype = ?, refPlnrMCalc = ?, modRefPlnrMMaterial = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblPlnrQMatList WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblPlnrQMatList WHERE jref = ?", false);
};

bool MyTblPlnrQMatList::loadRecBySQL(
			const string& sqlstr
			, PlnrQMatList** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrQMatList* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQMatList / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrQMatList();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->sref.assign(dbrow[4], dblengths[4]); else _rec->sref = "";
		if (dbrow[5]) _rec->Title.assign(dbrow[5], dblengths[5]); else _rec->Title = "";
		if (dbrow[6]) _rec->ixVBasetype = atol((char*) dbrow[6]); else _rec->ixVBasetype = 0;
		if (dbrow[7]) _rec->refPlnrMCalc = atoll((char*) dbrow[7]); else _rec->refPlnrMCalc = 0;
		if (dbrow[8]) _rec->modRefPlnrMMaterial = atoll((char*) dbrow[8]); else _rec->modRefPlnrMMaterial = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrQMatList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQMatList& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrQMatList* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQMatList / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrQMatList();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->sref.assign(dbrow[4], dblengths[4]); else rec->sref = "";
			if (dbrow[5]) rec->Title.assign(dbrow[5], dblengths[5]); else rec->Title = "";
			if (dbrow[6]) rec->ixVBasetype = atol((char*) dbrow[6]); else rec->ixVBasetype = 0;
			if (dbrow[7]) rec->refPlnrMCalc = atoll((char*) dbrow[7]); else rec->refPlnrMCalc = 0;
			if (dbrow[8]) rec->modRefPlnrMMaterial = atoll((char*) dbrow[8]); else rec->modRefPlnrMMaterial = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrQMatList::insertRec(
			PlnrQMatList* rec
		) {
	unsigned long l[8]; my_bool n[8]; my_bool e[8];

	l[3] = rec->sref.length();
	l[4] = rec->Title.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Title.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->ixVBasetype,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->refPlnrMCalc,&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->modRefPlnrMMaterial,&(l[7]),&(n[7]),&(e[7]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQMatList / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQMatList / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblPlnrQMatList::insertRst(
			ListPlnrQMatList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblPlnrQMatList::updateRec(
			PlnrQMatList* rec
		) {
	unsigned long l[9]; my_bool n[9]; my_bool e[9];

	l[3] = rec->sref.length();
	l[4] = rec->Title.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])), 
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])), 
		bindCstring((char*) (rec->Title.c_str()),&(l[4]),&(n[4]),&(e[4])), 
		bindUint(&rec->ixVBasetype,&(l[5]),&(n[5]),&(e[5])), 
		bindUbigint(&rec->refPlnrMCalc,&(l[6]),&(n[6]),&(e[6])), 
		bindUbigint(&rec->modRefPlnrMMaterial,&(l[7]),&(n[7]),&(e[7])), 
		bindUbigint(&rec->qref,&(l[8]),&(n[8]),&(e[8]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQMatList / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQMatList / stmtUpdateRec)\n");
};

void MyTblPlnrQMatList::updateRst(
			ListPlnrQMatList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblPlnrQMatList::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQMatList / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQMatList / stmtRemoveRecByQref)\n");
};

void MyTblPlnrQMatList::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQMatList / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQMatList / stmtRemoveRstByJref)\n");
};

bool MyTblPlnrQMatList::loadRecByQref(
			ubigint qref
			, PlnrQMatList** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrQMatList WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblPlnrQMatList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQMatList& rst
		) {
	return loadRstBySQL("SELECT * FROM TblPlnrQMatList WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrQMatList
 ******************************************************************************/

PgTblPlnrQMatList::PgTblPlnrQMatList() : TblPlnrQMatList(), PgTable() {
};

PgTblPlnrQMatList::~PgTblPlnrQMatList() {
};

void PgTblPlnrQMatList::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrQMatList_insertRec", "INSERT INTO TblPlnrQMatList (jref, jnum, ref, sref, Title, ixVBasetype, refPlnrMCalc, modRefPlnrMMaterial) VALUES ($1,$2,$3,$4,$5,$6,$7,$8) RETURNING qref", 8, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQMatList_updateRec", "UPDATE TblPlnrQMatList SET jref = $1, jnum = $2, ref = $3, sref = $4, Title = $5, ixVBasetype = $6, refPlnrMCalc = $7, modRefPlnrMMaterial = $8 WHERE qref = $9", 9, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQMatList_removeRecByQref", "DELETE FROM TblPlnrQMatList WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQMatList_removeRstByJref", "DELETE FROM TblPlnrQMatList WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrQMatList_loadRecByQref", "SELECT qref, jref, jnum, ref, sref, Title, ixVBasetype, refPlnrMCalc, modRefPlnrMMaterial FROM TblPlnrQMatList WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQMatList_loadRstByJref", "SELECT qref, jref, jnum, ref, sref, Title, ixVBasetype, refPlnrMCalc, modRefPlnrMMaterial FROM TblPlnrQMatList WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrQMatList::loadRec(
			PGresult* res
			, PlnrQMatList** rec
		) {
	char* ptr;

	PlnrQMatList* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrQMatList();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "title"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "refplnrmcalc"),
			PQfnumber(res, "modrefplnrmmaterial")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[5]));
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->ixVBasetype = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->refPlnrMCalc = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->modRefPlnrMMaterial = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrQMatList::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrQMatList& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrQMatList* rec;

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
			PQfnumber(res, "title"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "refplnrmcalc"),
			PQfnumber(res, "modrefplnrmmaterial")
		};

		while (numread < numrow) {
			rec = new PlnrQMatList();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[5]));
			ptr = PQgetvalue(res, numread, fnum[6]); rec->ixVBasetype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->refPlnrMCalc = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->modRefPlnrMMaterial = atoll(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrQMatList::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrQMatList** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQMatList / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQMatList::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrQMatList& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQMatList / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblPlnrQMatList::loadRecBySQL(
			const string& sqlstr
			, PlnrQMatList** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQMatList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQMatList& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrQMatList::insertRec(
			PlnrQMatList* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _ixVBasetype = htonl(rec->ixVBasetype);
	ubigint _refPlnrMCalc = htonl64(rec->refPlnrMCalc);
	ubigint _modRefPlnrMMaterial = htonl64(rec->modRefPlnrMMaterial);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->sref.c_str(),
		rec->Title.c_str(),
		(char*) &_ixVBasetype,
		(char*) &_refPlnrMCalc,
		(char*) &_modRefPlnrMMaterial
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		0,
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 0, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblPlnrQMatList_insertRec", 8, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQMatList_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblPlnrQMatList::insertRst(
			ListPlnrQMatList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblPlnrQMatList::updateRec(
			PlnrQMatList* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _ixVBasetype = htonl(rec->ixVBasetype);
	ubigint _refPlnrMCalc = htonl64(rec->refPlnrMCalc);
	ubigint _modRefPlnrMMaterial = htonl64(rec->modRefPlnrMMaterial);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->sref.c_str(),
		rec->Title.c_str(),
		(char*) &_ixVBasetype,
		(char*) &_refPlnrMCalc,
		(char*) &_modRefPlnrMMaterial,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		0,
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 0, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblPlnrQMatList_updateRec", 9, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQMatList_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrQMatList::updateRst(
			ListPlnrQMatList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblPlnrQMatList::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblPlnrQMatList_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQMatList_removeRecByQref)\n");

	PQclear(res);
};

void PgTblPlnrQMatList::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblPlnrQMatList_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQMatList_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblPlnrQMatList::loadRecByQref(
			ubigint qref
			, PlnrQMatList** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrQMatList_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblPlnrQMatList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQMatList& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrQMatList_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

