/**
  * \file PlnrQClcList.cpp
  * Dbs and XML wrapper for table TblPlnrQClcList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQClcList.h"

/******************************************************************************
 class PlnrQClcList
 ******************************************************************************/

PlnrQClcList::PlnrQClcList(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string Title
			, const ubigint refPlnrMProject
			, const string stubRefPlnrMProject
			, const uint ixVDim
			, const string srefIxVDim
			, const string titIxVDim
			, const ubigint tplRefPlnrMCalc
			, const string stubTplRefPlnrMCalc
			, const ubigint supRefPlnrMCalc
			, const string stubSupRefPlnrMCalc
			, const ubigint refPlnrMDesign
			, const string stubRefPlnrMDesign
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->Title = Title;
	this->refPlnrMProject = refPlnrMProject;
	this->stubRefPlnrMProject = stubRefPlnrMProject;
	this->ixVDim = ixVDim;
	this->srefIxVDim = srefIxVDim;
	this->titIxVDim = titIxVDim;
	this->tplRefPlnrMCalc = tplRefPlnrMCalc;
	this->stubTplRefPlnrMCalc = stubTplRefPlnrMCalc;
	this->supRefPlnrMCalc = supRefPlnrMCalc;
	this->stubSupRefPlnrMCalc = stubSupRefPlnrMCalc;
	this->refPlnrMDesign = refPlnrMDesign;
	this->stubRefPlnrMDesign = stubRefPlnrMDesign;
};

void PlnrQClcList::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "PlnrQClcList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "tit", Title);
		writeString(wr, "prj", stubRefPlnrMProject);
		writeString(wr, "dim", srefIxVDim);
		writeString(wr, "dim2", titIxVDim);
		writeString(wr, "tpl", stubTplRefPlnrMCalc);
		writeString(wr, "sup", stubSupRefPlnrMCalc);
		writeString(wr, "dsn", stubRefPlnrMDesign);
	} else {
		writeString(wr, "Title", Title);
		writeString(wr, "stubRefPlnrMProject", stubRefPlnrMProject);
		writeString(wr, "srefIxVDim", srefIxVDim);
		writeString(wr, "titIxVDim", titIxVDim);
		writeString(wr, "stubTplRefPlnrMCalc", stubTplRefPlnrMCalc);
		writeString(wr, "stubSupRefPlnrMCalc", stubSupRefPlnrMCalc);
		writeString(wr, "stubRefPlnrMDesign", stubRefPlnrMDesign);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListPlnrQClcList
 ******************************************************************************/

ListPlnrQClcList::ListPlnrQClcList() {
};

ListPlnrQClcList::ListPlnrQClcList(
			const ListPlnrQClcList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQClcList(*(src.nodes[i]));
};

ListPlnrQClcList::~ListPlnrQClcList() {
	clear();
};

void ListPlnrQClcList::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrQClcList::size() const {
	return(nodes.size());
};

void ListPlnrQClcList::append(
			PlnrQClcList* rec
		) {
	nodes.push_back(rec);
};

ListPlnrQClcList& ListPlnrQClcList::operator=(
			const ListPlnrQClcList& src
		) {
	PlnrQClcList* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrQClcList(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListPlnrQClcList::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListPlnrQClcList";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblPlnrQClcList
 ******************************************************************************/

TblPlnrQClcList::TblPlnrQClcList() {
};

TblPlnrQClcList::~TblPlnrQClcList() {
};

bool TblPlnrQClcList::loadRecBySQL(
			const string& sqlstr
			, PlnrQClcList** rec
		) {
	return false;
};

ubigint TblPlnrQClcList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQClcList& rst
		) {
	return 0;
};

void TblPlnrQClcList::insertRec(
			PlnrQClcList* rec
		) {
};

ubigint TblPlnrQClcList::insertNewRec(
			PlnrQClcList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string Title
			, const ubigint refPlnrMProject
			, const string stubRefPlnrMProject
			, const uint ixVDim
			, const string srefIxVDim
			, const string titIxVDim
			, const ubigint tplRefPlnrMCalc
			, const string stubTplRefPlnrMCalc
			, const ubigint supRefPlnrMCalc
			, const string stubSupRefPlnrMCalc
			, const ubigint refPlnrMDesign
			, const string stubRefPlnrMDesign
		) {
	ubigint retval = 0;
	PlnrQClcList* _rec = NULL;

	_rec = new PlnrQClcList(0, jref, jnum, ref, Title, refPlnrMProject, stubRefPlnrMProject, ixVDim, srefIxVDim, titIxVDim, tplRefPlnrMCalc, stubTplRefPlnrMCalc, supRefPlnrMCalc, stubSupRefPlnrMCalc, refPlnrMDesign, stubRefPlnrMDesign);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrQClcList::appendNewRecToRst(
			ListPlnrQClcList& rst
			, PlnrQClcList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string Title
			, const ubigint refPlnrMProject
			, const string stubRefPlnrMProject
			, const uint ixVDim
			, const string srefIxVDim
			, const string titIxVDim
			, const ubigint tplRefPlnrMCalc
			, const string stubTplRefPlnrMCalc
			, const ubigint supRefPlnrMCalc
			, const string stubSupRefPlnrMCalc
			, const ubigint refPlnrMDesign
			, const string stubRefPlnrMDesign
		) {
	ubigint retval = 0;
	PlnrQClcList* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, Title, refPlnrMProject, stubRefPlnrMProject, ixVDim, srefIxVDim, titIxVDim, tplRefPlnrMCalc, stubTplRefPlnrMCalc, supRefPlnrMCalc, stubSupRefPlnrMCalc, refPlnrMDesign, stubRefPlnrMDesign);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrQClcList::insertRst(
			ListPlnrQClcList& rst
		) {
};

void TblPlnrQClcList::updateRec(
			PlnrQClcList* rec
		) {
};

void TblPlnrQClcList::updateRst(
			ListPlnrQClcList& rst
		) {
};

void TblPlnrQClcList::removeRecByQref(
			ubigint qref
		) {
};

void TblPlnrQClcList::removeRstByJref(
			ubigint jref
		) {
};

bool TblPlnrQClcList::loadRecByQref(
			ubigint qref
			, PlnrQClcList** rec
		) {
	return false;
};

ubigint TblPlnrQClcList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQClcList& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrQClcList
 ******************************************************************************/

MyTblPlnrQClcList::MyTblPlnrQClcList() : TblPlnrQClcList(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblPlnrQClcList::~MyTblPlnrQClcList() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblPlnrQClcList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrQClcList (jref, jnum, ref, Title, refPlnrMProject, ixVDim, tplRefPlnrMCalc, supRefPlnrMCalc, refPlnrMDesign) VALUES (?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrQClcList SET jref = ?, jnum = ?, ref = ?, Title = ?, refPlnrMProject = ?, ixVDim = ?, tplRefPlnrMCalc = ?, supRefPlnrMCalc = ?, refPlnrMDesign = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblPlnrQClcList WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblPlnrQClcList WHERE jref = ?", false);
};

bool MyTblPlnrQClcList::loadRecBySQL(
			const string& sqlstr
			, PlnrQClcList** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrQClcList* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQClcList / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrQClcList();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->Title.assign(dbrow[4], dblengths[4]); else _rec->Title = "";
		if (dbrow[5]) _rec->refPlnrMProject = atoll((char*) dbrow[5]); else _rec->refPlnrMProject = 0;
		if (dbrow[6]) _rec->ixVDim = atol((char*) dbrow[6]); else _rec->ixVDim = 0;
		if (dbrow[7]) _rec->tplRefPlnrMCalc = atoll((char*) dbrow[7]); else _rec->tplRefPlnrMCalc = 0;
		if (dbrow[8]) _rec->supRefPlnrMCalc = atoll((char*) dbrow[8]); else _rec->supRefPlnrMCalc = 0;
		if (dbrow[9]) _rec->refPlnrMDesign = atoll((char*) dbrow[9]); else _rec->refPlnrMDesign = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrQClcList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQClcList& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrQClcList* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQClcList / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrQClcList();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->Title.assign(dbrow[4], dblengths[4]); else rec->Title = "";
			if (dbrow[5]) rec->refPlnrMProject = atoll((char*) dbrow[5]); else rec->refPlnrMProject = 0;
			if (dbrow[6]) rec->ixVDim = atol((char*) dbrow[6]); else rec->ixVDim = 0;
			if (dbrow[7]) rec->tplRefPlnrMCalc = atoll((char*) dbrow[7]); else rec->tplRefPlnrMCalc = 0;
			if (dbrow[8]) rec->supRefPlnrMCalc = atoll((char*) dbrow[8]); else rec->supRefPlnrMCalc = 0;
			if (dbrow[9]) rec->refPlnrMDesign = atoll((char*) dbrow[9]); else rec->refPlnrMDesign = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrQClcList::insertRec(
			PlnrQClcList* rec
		) {
	unsigned long l[9]; my_bool n[9]; my_bool e[9];

	l[3] = rec->Title.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Title.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->refPlnrMProject,&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->ixVDim,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->tplRefPlnrMCalc,&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->supRefPlnrMCalc,&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->refPlnrMDesign,&(l[8]),&(n[8]),&(e[8]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQClcList / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQClcList / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblPlnrQClcList::insertRst(
			ListPlnrQClcList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblPlnrQClcList::updateRec(
			PlnrQClcList* rec
		) {
	unsigned long l[10]; my_bool n[10]; my_bool e[10];

	l[3] = rec->Title.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])), 
		bindCstring((char*) (rec->Title.c_str()),&(l[3]),&(n[3]),&(e[3])), 
		bindUbigint(&rec->refPlnrMProject,&(l[4]),&(n[4]),&(e[4])), 
		bindUint(&rec->ixVDim,&(l[5]),&(n[5]),&(e[5])), 
		bindUbigint(&rec->tplRefPlnrMCalc,&(l[6]),&(n[6]),&(e[6])), 
		bindUbigint(&rec->supRefPlnrMCalc,&(l[7]),&(n[7]),&(e[7])), 
		bindUbigint(&rec->refPlnrMDesign,&(l[8]),&(n[8]),&(e[8])), 
		bindUbigint(&rec->qref,&(l[9]),&(n[9]),&(e[9]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQClcList / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQClcList / stmtUpdateRec)\n");
};

void MyTblPlnrQClcList::updateRst(
			ListPlnrQClcList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblPlnrQClcList::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQClcList / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQClcList / stmtRemoveRecByQref)\n");
};

void MyTblPlnrQClcList::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQClcList / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQClcList / stmtRemoveRstByJref)\n");
};

bool MyTblPlnrQClcList::loadRecByQref(
			ubigint qref
			, PlnrQClcList** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrQClcList WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblPlnrQClcList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQClcList& rst
		) {
	return loadRstBySQL("SELECT * FROM TblPlnrQClcList WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrQClcList
 ******************************************************************************/

PgTblPlnrQClcList::PgTblPlnrQClcList() : TblPlnrQClcList(), PgTable() {
};

PgTblPlnrQClcList::~PgTblPlnrQClcList() {
};

void PgTblPlnrQClcList::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrQClcList_insertRec", "INSERT INTO TblPlnrQClcList (jref, jnum, ref, Title, refPlnrMProject, ixVDim, tplRefPlnrMCalc, supRefPlnrMCalc, refPlnrMDesign) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9) RETURNING qref", 9, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQClcList_updateRec", "UPDATE TblPlnrQClcList SET jref = $1, jnum = $2, ref = $3, Title = $4, refPlnrMProject = $5, ixVDim = $6, tplRefPlnrMCalc = $7, supRefPlnrMCalc = $8, refPlnrMDesign = $9 WHERE qref = $10", 10, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQClcList_removeRecByQref", "DELETE FROM TblPlnrQClcList WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQClcList_removeRstByJref", "DELETE FROM TblPlnrQClcList WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrQClcList_loadRecByQref", "SELECT qref, jref, jnum, ref, Title, refPlnrMProject, ixVDim, tplRefPlnrMCalc, supRefPlnrMCalc, refPlnrMDesign FROM TblPlnrQClcList WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQClcList_loadRstByJref", "SELECT qref, jref, jnum, ref, Title, refPlnrMProject, ixVDim, tplRefPlnrMCalc, supRefPlnrMCalc, refPlnrMDesign FROM TblPlnrQClcList WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrQClcList::loadRec(
			PGresult* res
			, PlnrQClcList** rec
		) {
	char* ptr;

	PlnrQClcList* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrQClcList();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "title"),
			PQfnumber(res, "refplnrmproject"),
			PQfnumber(res, "ixvdim"),
			PQfnumber(res, "tplrefplnrmcalc"),
			PQfnumber(res, "suprefplnrmcalc"),
			PQfnumber(res, "refplnrmdesign")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->refPlnrMProject = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->ixVDim = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->tplRefPlnrMCalc = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->supRefPlnrMCalc = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->refPlnrMDesign = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrQClcList::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrQClcList& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrQClcList* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "title"),
			PQfnumber(res, "refplnrmproject"),
			PQfnumber(res, "ixvdim"),
			PQfnumber(res, "tplrefplnrmcalc"),
			PQfnumber(res, "suprefplnrmcalc"),
			PQfnumber(res, "refplnrmdesign")
		};

		while (numread < numrow) {
			rec = new PlnrQClcList();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->refPlnrMProject = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->ixVDim = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->tplRefPlnrMCalc = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->supRefPlnrMCalc = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->refPlnrMDesign = atoll(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrQClcList::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrQClcList** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQClcList / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQClcList::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrQClcList& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQClcList / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblPlnrQClcList::loadRecBySQL(
			const string& sqlstr
			, PlnrQClcList** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQClcList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQClcList& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrQClcList::insertRec(
			PlnrQClcList* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _refPlnrMProject = htonl64(rec->refPlnrMProject);
	uint _ixVDim = htonl(rec->ixVDim);
	ubigint _tplRefPlnrMCalc = htonl64(rec->tplRefPlnrMCalc);
	ubigint _supRefPlnrMCalc = htonl64(rec->supRefPlnrMCalc);
	ubigint _refPlnrMDesign = htonl64(rec->refPlnrMDesign);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->Title.c_str(),
		(char*) &_refPlnrMProject,
		(char*) &_ixVDim,
		(char*) &_tplRefPlnrMCalc,
		(char*) &_supRefPlnrMCalc,
		(char*) &_refPlnrMDesign
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblPlnrQClcList_insertRec", 9, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQClcList_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblPlnrQClcList::insertRst(
			ListPlnrQClcList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblPlnrQClcList::updateRec(
			PlnrQClcList* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _refPlnrMProject = htonl64(rec->refPlnrMProject);
	uint _ixVDim = htonl(rec->ixVDim);
	ubigint _tplRefPlnrMCalc = htonl64(rec->tplRefPlnrMCalc);
	ubigint _supRefPlnrMCalc = htonl64(rec->supRefPlnrMCalc);
	ubigint _refPlnrMDesign = htonl64(rec->refPlnrMDesign);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->Title.c_str(),
		(char*) &_refPlnrMProject,
		(char*) &_ixVDim,
		(char*) &_tplRefPlnrMCalc,
		(char*) &_supRefPlnrMCalc,
		(char*) &_refPlnrMDesign,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 1, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblPlnrQClcList_updateRec", 10, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQClcList_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrQClcList::updateRst(
			ListPlnrQClcList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblPlnrQClcList::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblPlnrQClcList_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQClcList_removeRecByQref)\n");

	PQclear(res);
};

void PgTblPlnrQClcList::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblPlnrQClcList_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQClcList_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblPlnrQClcList::loadRecByQref(
			ubigint qref
			, PlnrQClcList** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrQClcList_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblPlnrQClcList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQClcList& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrQClcList_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

