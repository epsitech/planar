/**
  * \file PlnrQCtpKParProp.cpp
  * Dbs and XML wrapper for table TblPlnrQCtpKParProp (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQCtpKParProp.h"

/******************************************************************************
 class PlnrQCtpKParProp
 ******************************************************************************/

PlnrQCtpKParProp::PlnrQCtpKParProp(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint klsNum
			, const string sref
			, const string Avail
			, const ubigint refJ
			, const string Title
			, const string Comment
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->klsNum = klsNum;
	this->sref = sref;
	this->Avail = Avail;
	this->refJ = refJ;
	this->Title = Title;
	this->Comment = Comment;
};

void PlnrQCtpKParProp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "PlnrQCtpKParProp";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "srf", sref);
		writeString(wr, "avl", Avail);
		writeString(wr, "tit", Title);
		writeString(wr, "cmt", Comment);
	} else {
		writeString(wr, "sref", sref);
		writeString(wr, "Avail", Avail);
		writeString(wr, "Title", Title);
		writeString(wr, "Comment", Comment);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListPlnrQCtpKParProp
 ******************************************************************************/

ListPlnrQCtpKParProp::ListPlnrQCtpKParProp() {
};

ListPlnrQCtpKParProp::ListPlnrQCtpKParProp(
			const ListPlnrQCtpKParProp& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQCtpKParProp(*(src.nodes[i]));
};

ListPlnrQCtpKParProp::~ListPlnrQCtpKParProp() {
	clear();
};

void ListPlnrQCtpKParProp::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrQCtpKParProp::size() const {
	return(nodes.size());
};

void ListPlnrQCtpKParProp::append(
			PlnrQCtpKParProp* rec
		) {
	nodes.push_back(rec);
};

ListPlnrQCtpKParProp& ListPlnrQCtpKParProp::operator=(
			const ListPlnrQCtpKParProp& src
		) {
	PlnrQCtpKParProp* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrQCtpKParProp(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListPlnrQCtpKParProp::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListPlnrQCtpKParProp";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblPlnrQCtpKParProp
 ******************************************************************************/

TblPlnrQCtpKParProp::TblPlnrQCtpKParProp() {
};

TblPlnrQCtpKParProp::~TblPlnrQCtpKParProp() {
};

bool TblPlnrQCtpKParProp::loadRecBySQL(
			const string& sqlstr
			, PlnrQCtpKParProp** rec
		) {
	return false;
};

ubigint TblPlnrQCtpKParProp::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQCtpKParProp& rst
		) {
	return 0;
};

void TblPlnrQCtpKParProp::insertRec(
			PlnrQCtpKParProp* rec
		) {
};

ubigint TblPlnrQCtpKParProp::insertNewRec(
			PlnrQCtpKParProp** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint klsNum
			, const string sref
			, const string Avail
			, const ubigint refJ
			, const string Title
			, const string Comment
		) {
	ubigint retval = 0;
	PlnrQCtpKParProp* _rec = NULL;

	_rec = new PlnrQCtpKParProp(0, jref, jnum, ref, klsNum, sref, Avail, refJ, Title, Comment);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrQCtpKParProp::appendNewRecToRst(
			ListPlnrQCtpKParProp& rst
			, PlnrQCtpKParProp** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint klsNum
			, const string sref
			, const string Avail
			, const ubigint refJ
			, const string Title
			, const string Comment
		) {
	ubigint retval = 0;
	PlnrQCtpKParProp* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, klsNum, sref, Avail, refJ, Title, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrQCtpKParProp::insertRst(
			ListPlnrQCtpKParProp& rst
		) {
};

void TblPlnrQCtpKParProp::updateRec(
			PlnrQCtpKParProp* rec
		) {
};

void TblPlnrQCtpKParProp::updateRst(
			ListPlnrQCtpKParProp& rst
		) {
};

void TblPlnrQCtpKParProp::removeRecByQref(
			ubigint qref
		) {
};

void TblPlnrQCtpKParProp::removeRstByJref(
			ubigint jref
		) {
};

bool TblPlnrQCtpKParProp::loadRecByQref(
			ubigint qref
			, PlnrQCtpKParProp** rec
		) {
	return false;
};

ubigint TblPlnrQCtpKParProp::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQCtpKParProp& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrQCtpKParProp
 ******************************************************************************/

MyTblPlnrQCtpKParProp::MyTblPlnrQCtpKParProp() : TblPlnrQCtpKParProp(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblPlnrQCtpKParProp::~MyTblPlnrQCtpKParProp() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblPlnrQCtpKParProp::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrQCtpKParProp (jref, jnum, ref, klsNum, sref, Avail, refJ, Title, Comment) VALUES (?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrQCtpKParProp SET jref = ?, jnum = ?, ref = ?, klsNum = ?, sref = ?, Avail = ?, refJ = ?, Title = ?, Comment = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblPlnrQCtpKParProp WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblPlnrQCtpKParProp WHERE jref = ?", false);
};

bool MyTblPlnrQCtpKParProp::loadRecBySQL(
			const string& sqlstr
			, PlnrQCtpKParProp** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrQCtpKParProp* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQCtpKParProp / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrQCtpKParProp();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->klsNum = atol((char*) dbrow[4]); else _rec->klsNum = 0;
		if (dbrow[5]) _rec->sref.assign(dbrow[5], dblengths[5]); else _rec->sref = "";
		if (dbrow[6]) _rec->Avail.assign(dbrow[6], dblengths[6]); else _rec->Avail = "";
		if (dbrow[7]) _rec->refJ = atoll((char*) dbrow[7]); else _rec->refJ = 0;
		if (dbrow[8]) _rec->Title.assign(dbrow[8], dblengths[8]); else _rec->Title = "";
		if (dbrow[9]) _rec->Comment.assign(dbrow[9], dblengths[9]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrQCtpKParProp::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQCtpKParProp& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrQCtpKParProp* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQCtpKParProp / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrQCtpKParProp();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->klsNum = atol((char*) dbrow[4]); else rec->klsNum = 0;
			if (dbrow[5]) rec->sref.assign(dbrow[5], dblengths[5]); else rec->sref = "";
			if (dbrow[6]) rec->Avail.assign(dbrow[6], dblengths[6]); else rec->Avail = "";
			if (dbrow[7]) rec->refJ = atoll((char*) dbrow[7]); else rec->refJ = 0;
			if (dbrow[8]) rec->Title.assign(dbrow[8], dblengths[8]); else rec->Title = "";
			if (dbrow[9]) rec->Comment.assign(dbrow[9], dblengths[9]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrQCtpKParProp::insertRec(
			PlnrQCtpKParProp* rec
		) {
	unsigned long l[9]; my_bool n[9]; my_bool e[9];

	l[4] = rec->sref.length();
	l[5] = rec->Avail.length();
	l[7] = rec->Title.length();
	l[8] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->klsNum,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->sref.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->Avail.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->refJ,&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->Title.c_str()),&(l[7]),&(n[7]),&(e[7])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[8]),&(n[8]),&(e[8]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQCtpKParProp / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQCtpKParProp / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblPlnrQCtpKParProp::insertRst(
			ListPlnrQCtpKParProp& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblPlnrQCtpKParProp::updateRec(
			PlnrQCtpKParProp* rec
		) {
	unsigned long l[10]; my_bool n[10]; my_bool e[10];

	l[4] = rec->sref.length();
	l[5] = rec->Avail.length();
	l[7] = rec->Title.length();
	l[8] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])), 
		bindUint(&rec->klsNum,&(l[3]),&(n[3]),&(e[3])), 
		bindCstring((char*) (rec->sref.c_str()),&(l[4]),&(n[4]),&(e[4])), 
		bindCstring((char*) (rec->Avail.c_str()),&(l[5]),&(n[5]),&(e[5])), 
		bindUbigint(&rec->refJ,&(l[6]),&(n[6]),&(e[6])), 
		bindCstring((char*) (rec->Title.c_str()),&(l[7]),&(n[7]),&(e[7])), 
		bindCstring((char*) (rec->Comment.c_str()),&(l[8]),&(n[8]),&(e[8])), 
		bindUbigint(&rec->qref,&(l[9]),&(n[9]),&(e[9]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQCtpKParProp / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQCtpKParProp / stmtUpdateRec)\n");
};

void MyTblPlnrQCtpKParProp::updateRst(
			ListPlnrQCtpKParProp& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblPlnrQCtpKParProp::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQCtpKParProp / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQCtpKParProp / stmtRemoveRecByQref)\n");
};

void MyTblPlnrQCtpKParProp::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQCtpKParProp / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQCtpKParProp / stmtRemoveRstByJref)\n");
};

bool MyTblPlnrQCtpKParProp::loadRecByQref(
			ubigint qref
			, PlnrQCtpKParProp** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrQCtpKParProp WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblPlnrQCtpKParProp::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQCtpKParProp& rst
		) {
	return loadRstBySQL("SELECT * FROM TblPlnrQCtpKParProp WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrQCtpKParProp
 ******************************************************************************/

PgTblPlnrQCtpKParProp::PgTblPlnrQCtpKParProp() : TblPlnrQCtpKParProp(), PgTable() {
};

PgTblPlnrQCtpKParProp::~PgTblPlnrQCtpKParProp() {
};

void PgTblPlnrQCtpKParProp::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrQCtpKParProp_insertRec", "INSERT INTO TblPlnrQCtpKParProp (jref, jnum, ref, klsNum, sref, Avail, refJ, Title, Comment) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9) RETURNING qref", 9, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQCtpKParProp_updateRec", "UPDATE TblPlnrQCtpKParProp SET jref = $1, jnum = $2, ref = $3, klsNum = $4, sref = $5, Avail = $6, refJ = $7, Title = $8, Comment = $9 WHERE qref = $10", 10, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQCtpKParProp_removeRecByQref", "DELETE FROM TblPlnrQCtpKParProp WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQCtpKParProp_removeRstByJref", "DELETE FROM TblPlnrQCtpKParProp WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrQCtpKParProp_loadRecByQref", "SELECT qref, jref, jnum, ref, klsNum, sref, Avail, refJ, Title, Comment FROM TblPlnrQCtpKParProp WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQCtpKParProp_loadRstByJref", "SELECT qref, jref, jnum, ref, klsNum, sref, Avail, refJ, Title, Comment FROM TblPlnrQCtpKParProp WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrQCtpKParProp::loadRec(
			PGresult* res
			, PlnrQCtpKParProp** rec
		) {
	char* ptr;

	PlnrQCtpKParProp* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrQCtpKParProp();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "klsnum"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "avail"),
			PQfnumber(res, "refj"),
			PQfnumber(res, "title"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->klsNum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[5]));
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->Avail.assign(ptr, PQgetlength(res, 0, fnum[6]));
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->refJ = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[8]));
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[9]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrQCtpKParProp::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrQCtpKParProp& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrQCtpKParProp* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "klsnum"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "avail"),
			PQfnumber(res, "refj"),
			PQfnumber(res, "title"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new PlnrQCtpKParProp();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->klsNum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[5]));
			ptr = PQgetvalue(res, numread, fnum[6]); rec->Avail.assign(ptr, PQgetlength(res, numread, fnum[6]));
			ptr = PQgetvalue(res, numread, fnum[7]); rec->refJ = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[8]));
			ptr = PQgetvalue(res, numread, fnum[9]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[9]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrQCtpKParProp::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrQCtpKParProp** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQCtpKParProp / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQCtpKParProp::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrQCtpKParProp& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQCtpKParProp / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblPlnrQCtpKParProp::loadRecBySQL(
			const string& sqlstr
			, PlnrQCtpKParProp** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQCtpKParProp::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQCtpKParProp& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrQCtpKParProp::insertRec(
			PlnrQCtpKParProp* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _klsNum = htonl(rec->klsNum);
	ubigint _refJ = htonl64(rec->refJ);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_klsNum,
		rec->sref.c_str(),
		rec->Avail.c_str(),
		(char*) &_refJ,
		rec->Title.c_str(),
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		0,
		0,
		sizeof(ubigint),
		0,
		0
	};
	const int f[] = {1, 1, 1, 1, 0, 0, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblPlnrQCtpKParProp_insertRec", 9, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQCtpKParProp_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblPlnrQCtpKParProp::insertRst(
			ListPlnrQCtpKParProp& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblPlnrQCtpKParProp::updateRec(
			PlnrQCtpKParProp* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _klsNum = htonl(rec->klsNum);
	ubigint _refJ = htonl64(rec->refJ);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_klsNum,
		rec->sref.c_str(),
		rec->Avail.c_str(),
		(char*) &_refJ,
		rec->Title.c_str(),
		rec->Comment.c_str(),
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		0,
		0,
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 0, 0, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblPlnrQCtpKParProp_updateRec", 10, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQCtpKParProp_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrQCtpKParProp::updateRst(
			ListPlnrQCtpKParProp& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblPlnrQCtpKParProp::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblPlnrQCtpKParProp_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQCtpKParProp_removeRecByQref)\n");

	PQclear(res);
};

void PgTblPlnrQCtpKParProp::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblPlnrQCtpKParProp_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQCtpKParProp_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblPlnrQCtpKParProp::loadRecByQref(
			ubigint qref
			, PlnrQCtpKParProp** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrQCtpKParProp_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblPlnrQCtpKParProp::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQCtpKParProp& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrQCtpKParProp_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

