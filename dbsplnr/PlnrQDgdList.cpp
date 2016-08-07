/**
  * \file PlnrQDgdList.cpp
  * Dbs and XML wrapper for table TblPlnrQDgdList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQDgdList.h"

/******************************************************************************
 class PlnrQDgdList
 ******************************************************************************/

PlnrQDgdList::PlnrQDgdList(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const uint ixVBasetype
			, const string srefIxVBasetype
			, const string titIxVBasetype
			, const ubigint dsnRefPlnrMDesign
			, const string stubDsnRefPlnrMDesign
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->sref = sref;
	this->ixVBasetype = ixVBasetype;
	this->srefIxVBasetype = srefIxVBasetype;
	this->titIxVBasetype = titIxVBasetype;
	this->dsnRefPlnrMDesign = dsnRefPlnrMDesign;
	this->stubDsnRefPlnrMDesign = stubDsnRefPlnrMDesign;
};

void PlnrQDgdList::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "PlnrQDgdList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "srf", sref);
		writeString(wr, "typ", srefIxVBasetype);
		writeString(wr, "typ2", titIxVBasetype);
		writeString(wr, "dsn", stubDsnRefPlnrMDesign);
	} else {
		writeString(wr, "sref", sref);
		writeString(wr, "srefIxVBasetype", srefIxVBasetype);
		writeString(wr, "titIxVBasetype", titIxVBasetype);
		writeString(wr, "stubDsnRefPlnrMDesign", stubDsnRefPlnrMDesign);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListPlnrQDgdList
 ******************************************************************************/

ListPlnrQDgdList::ListPlnrQDgdList() {
};

ListPlnrQDgdList::ListPlnrQDgdList(
			const ListPlnrQDgdList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQDgdList(*(src.nodes[i]));
};

ListPlnrQDgdList::~ListPlnrQDgdList() {
	clear();
};

void ListPlnrQDgdList::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrQDgdList::size() const {
	return(nodes.size());
};

void ListPlnrQDgdList::append(
			PlnrQDgdList* rec
		) {
	nodes.push_back(rec);
};

ListPlnrQDgdList& ListPlnrQDgdList::operator=(
			const ListPlnrQDgdList& src
		) {
	PlnrQDgdList* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrQDgdList(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListPlnrQDgdList::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListPlnrQDgdList";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblPlnrQDgdList
 ******************************************************************************/

TblPlnrQDgdList::TblPlnrQDgdList() {
};

TblPlnrQDgdList::~TblPlnrQDgdList() {
};

bool TblPlnrQDgdList::loadRecBySQL(
			const string& sqlstr
			, PlnrQDgdList** rec
		) {
	return false;
};

ubigint TblPlnrQDgdList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQDgdList& rst
		) {
	return 0;
};

void TblPlnrQDgdList::insertRec(
			PlnrQDgdList* rec
		) {
};

ubigint TblPlnrQDgdList::insertNewRec(
			PlnrQDgdList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const uint ixVBasetype
			, const string srefIxVBasetype
			, const string titIxVBasetype
			, const ubigint dsnRefPlnrMDesign
			, const string stubDsnRefPlnrMDesign
		) {
	ubigint retval = 0;
	PlnrQDgdList* _rec = NULL;

	_rec = new PlnrQDgdList(0, jref, jnum, ref, sref, ixVBasetype, srefIxVBasetype, titIxVBasetype, dsnRefPlnrMDesign, stubDsnRefPlnrMDesign);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrQDgdList::appendNewRecToRst(
			ListPlnrQDgdList& rst
			, PlnrQDgdList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const uint ixVBasetype
			, const string srefIxVBasetype
			, const string titIxVBasetype
			, const ubigint dsnRefPlnrMDesign
			, const string stubDsnRefPlnrMDesign
		) {
	ubigint retval = 0;
	PlnrQDgdList* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, sref, ixVBasetype, srefIxVBasetype, titIxVBasetype, dsnRefPlnrMDesign, stubDsnRefPlnrMDesign);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrQDgdList::insertRst(
			ListPlnrQDgdList& rst
		) {
};

void TblPlnrQDgdList::updateRec(
			PlnrQDgdList* rec
		) {
};

void TblPlnrQDgdList::updateRst(
			ListPlnrQDgdList& rst
		) {
};

void TblPlnrQDgdList::removeRecByQref(
			ubigint qref
		) {
};

void TblPlnrQDgdList::removeRstByJref(
			ubigint jref
		) {
};

bool TblPlnrQDgdList::loadRecByQref(
			ubigint qref
			, PlnrQDgdList** rec
		) {
	return false;
};

ubigint TblPlnrQDgdList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQDgdList& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrQDgdList
 ******************************************************************************/

MyTblPlnrQDgdList::MyTblPlnrQDgdList() : TblPlnrQDgdList(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblPlnrQDgdList::~MyTblPlnrQDgdList() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblPlnrQDgdList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrQDgdList (jref, jnum, ref, sref, ixVBasetype, dsnRefPlnrMDesign) VALUES (?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrQDgdList SET jref = ?, jnum = ?, ref = ?, sref = ?, ixVBasetype = ?, dsnRefPlnrMDesign = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblPlnrQDgdList WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblPlnrQDgdList WHERE jref = ?", false);
};

bool MyTblPlnrQDgdList::loadRecBySQL(
			const string& sqlstr
			, PlnrQDgdList** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrQDgdList* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQDgdList / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrQDgdList();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->sref.assign(dbrow[4], dblengths[4]); else _rec->sref = "";
		if (dbrow[5]) _rec->ixVBasetype = atol((char*) dbrow[5]); else _rec->ixVBasetype = 0;
		if (dbrow[6]) _rec->dsnRefPlnrMDesign = atoll((char*) dbrow[6]); else _rec->dsnRefPlnrMDesign = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrQDgdList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQDgdList& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrQDgdList* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQDgdList / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrQDgdList();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->sref.assign(dbrow[4], dblengths[4]); else rec->sref = "";
			if (dbrow[5]) rec->ixVBasetype = atol((char*) dbrow[5]); else rec->ixVBasetype = 0;
			if (dbrow[6]) rec->dsnRefPlnrMDesign = atoll((char*) dbrow[6]); else rec->dsnRefPlnrMDesign = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrQDgdList::insertRec(
			PlnrQDgdList* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	l[3] = rec->sref.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->ixVBasetype,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->dsnRefPlnrMDesign,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQDgdList / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQDgdList / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblPlnrQDgdList::insertRst(
			ListPlnrQDgdList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblPlnrQDgdList::updateRec(
			PlnrQDgdList* rec
		) {
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	l[3] = rec->sref.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])), 
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])), 
		bindUint(&rec->ixVBasetype,&(l[4]),&(n[4]),&(e[4])), 
		bindUbigint(&rec->dsnRefPlnrMDesign,&(l[5]),&(n[5]),&(e[5])), 
		bindUbigint(&rec->qref,&(l[6]),&(n[6]),&(e[6]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQDgdList / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQDgdList / stmtUpdateRec)\n");
};

void MyTblPlnrQDgdList::updateRst(
			ListPlnrQDgdList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblPlnrQDgdList::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQDgdList / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQDgdList / stmtRemoveRecByQref)\n");
};

void MyTblPlnrQDgdList::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQDgdList / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQDgdList / stmtRemoveRstByJref)\n");
};

bool MyTblPlnrQDgdList::loadRecByQref(
			ubigint qref
			, PlnrQDgdList** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrQDgdList WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblPlnrQDgdList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQDgdList& rst
		) {
	return loadRstBySQL("SELECT * FROM TblPlnrQDgdList WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrQDgdList
 ******************************************************************************/

PgTblPlnrQDgdList::PgTblPlnrQDgdList() : TblPlnrQDgdList(), PgTable() {
};

PgTblPlnrQDgdList::~PgTblPlnrQDgdList() {
};

void PgTblPlnrQDgdList::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrQDgdList_insertRec", "INSERT INTO TblPlnrQDgdList (jref, jnum, ref, sref, ixVBasetype, dsnRefPlnrMDesign) VALUES ($1,$2,$3,$4,$5,$6) RETURNING qref", 6, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQDgdList_updateRec", "UPDATE TblPlnrQDgdList SET jref = $1, jnum = $2, ref = $3, sref = $4, ixVBasetype = $5, dsnRefPlnrMDesign = $6 WHERE qref = $7", 7, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQDgdList_removeRecByQref", "DELETE FROM TblPlnrQDgdList WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQDgdList_removeRstByJref", "DELETE FROM TblPlnrQDgdList WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrQDgdList_loadRecByQref", "SELECT qref, jref, jnum, ref, sref, ixVBasetype, dsnRefPlnrMDesign FROM TblPlnrQDgdList WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQDgdList_loadRstByJref", "SELECT qref, jref, jnum, ref, sref, ixVBasetype, dsnRefPlnrMDesign FROM TblPlnrQDgdList WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrQDgdList::loadRec(
			PGresult* res
			, PlnrQDgdList** rec
		) {
	char* ptr;

	PlnrQDgdList* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrQDgdList();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "dsnrefplnrmdesign")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->ixVBasetype = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->dsnRefPlnrMDesign = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrQDgdList::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrQDgdList& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrQDgdList* rec;

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
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "dsnrefplnrmdesign")
		};

		while (numread < numrow) {
			rec = new PlnrQDgdList();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->ixVBasetype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->dsnRefPlnrMDesign = atoll(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrQDgdList::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrQDgdList** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDgdList / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQDgdList::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrQDgdList& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDgdList / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblPlnrQDgdList::loadRecBySQL(
			const string& sqlstr
			, PlnrQDgdList** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQDgdList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQDgdList& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrQDgdList::insertRec(
			PlnrQDgdList* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _ixVBasetype = htonl(rec->ixVBasetype);
	ubigint _dsnRefPlnrMDesign = htonl64(rec->dsnRefPlnrMDesign);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->sref.c_str(),
		(char*) &_ixVBasetype,
		(char*) &_dsnRefPlnrMDesign
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 1, 1};

	res = PQexecPrepared(dbs, "TblPlnrQDgdList_insertRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDgdList_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblPlnrQDgdList::insertRst(
			ListPlnrQDgdList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblPlnrQDgdList::updateRec(
			PlnrQDgdList* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _ixVBasetype = htonl(rec->ixVBasetype);
	ubigint _dsnRefPlnrMDesign = htonl64(rec->dsnRefPlnrMDesign);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->sref.c_str(),
		(char*) &_ixVBasetype,
		(char*) &_dsnRefPlnrMDesign,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblPlnrQDgdList_updateRec", 7, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDgdList_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrQDgdList::updateRst(
			ListPlnrQDgdList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblPlnrQDgdList::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblPlnrQDgdList_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDgdList_removeRecByQref)\n");

	PQclear(res);
};

void PgTblPlnrQDgdList::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblPlnrQDgdList_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDgdList_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblPlnrQDgdList::loadRecByQref(
			ubigint qref
			, PlnrQDgdList** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrQDgdList_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblPlnrQDgdList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQDgdList& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrQDgdList_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

