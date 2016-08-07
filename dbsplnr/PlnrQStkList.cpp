/**
  * \file PlnrQStkList.cpp
  * Dbs and XML wrapper for table TblPlnrQStkList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQStkList.h"

/******************************************************************************
 class PlnrQStkList
 ******************************************************************************/

PlnrQStkList::PlnrQStkList(
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
			, const uint ixVModtype
			, const string srefIxVModtype
			, const string titIxVModtype
			, const uint ixVFlrAligntype
			, const string srefIxVFlrAligntype
			, const string titIxVFlrAligntype
			, const uint ixVCeilAligntype
			, const string srefIxVCeilAligntype
			, const string titIxVCeilAligntype
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
	this->ixVModtype = ixVModtype;
	this->srefIxVModtype = srefIxVModtype;
	this->titIxVModtype = titIxVModtype;
	this->ixVFlrAligntype = ixVFlrAligntype;
	this->srefIxVFlrAligntype = srefIxVFlrAligntype;
	this->titIxVFlrAligntype = titIxVFlrAligntype;
	this->ixVCeilAligntype = ixVCeilAligntype;
	this->srefIxVCeilAligntype = srefIxVCeilAligntype;
	this->titIxVCeilAligntype = titIxVCeilAligntype;
};

void PlnrQStkList::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "PlnrQStkList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "srf", sref);
		writeString(wr, "typ", srefIxVBasetype);
		writeString(wr, "typ2", titIxVBasetype);
		writeString(wr, "dsn", stubDsnRefPlnrMDesign);
		writeString(wr, "mty", srefIxVModtype);
		writeString(wr, "mty2", titIxVModtype);
		writeString(wr, "fal", srefIxVFlrAligntype);
		writeString(wr, "fal2", titIxVFlrAligntype);
		writeString(wr, "cal", srefIxVCeilAligntype);
		writeString(wr, "cal2", titIxVCeilAligntype);
	} else {
		writeString(wr, "sref", sref);
		writeString(wr, "srefIxVBasetype", srefIxVBasetype);
		writeString(wr, "titIxVBasetype", titIxVBasetype);
		writeString(wr, "stubDsnRefPlnrMDesign", stubDsnRefPlnrMDesign);
		writeString(wr, "srefIxVModtype", srefIxVModtype);
		writeString(wr, "titIxVModtype", titIxVModtype);
		writeString(wr, "srefIxVFlrAligntype", srefIxVFlrAligntype);
		writeString(wr, "titIxVFlrAligntype", titIxVFlrAligntype);
		writeString(wr, "srefIxVCeilAligntype", srefIxVCeilAligntype);
		writeString(wr, "titIxVCeilAligntype", titIxVCeilAligntype);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListPlnrQStkList
 ******************************************************************************/

ListPlnrQStkList::ListPlnrQStkList() {
};

ListPlnrQStkList::ListPlnrQStkList(
			const ListPlnrQStkList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQStkList(*(src.nodes[i]));
};

ListPlnrQStkList::~ListPlnrQStkList() {
	clear();
};

void ListPlnrQStkList::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrQStkList::size() const {
	return(nodes.size());
};

void ListPlnrQStkList::append(
			PlnrQStkList* rec
		) {
	nodes.push_back(rec);
};

ListPlnrQStkList& ListPlnrQStkList::operator=(
			const ListPlnrQStkList& src
		) {
	PlnrQStkList* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrQStkList(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListPlnrQStkList::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListPlnrQStkList";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblPlnrQStkList
 ******************************************************************************/

TblPlnrQStkList::TblPlnrQStkList() {
};

TblPlnrQStkList::~TblPlnrQStkList() {
};

bool TblPlnrQStkList::loadRecBySQL(
			const string& sqlstr
			, PlnrQStkList** rec
		) {
	return false;
};

ubigint TblPlnrQStkList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQStkList& rst
		) {
	return 0;
};

void TblPlnrQStkList::insertRec(
			PlnrQStkList* rec
		) {
};

ubigint TblPlnrQStkList::insertNewRec(
			PlnrQStkList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const uint ixVBasetype
			, const string srefIxVBasetype
			, const string titIxVBasetype
			, const ubigint dsnRefPlnrMDesign
			, const string stubDsnRefPlnrMDesign
			, const uint ixVModtype
			, const string srefIxVModtype
			, const string titIxVModtype
			, const uint ixVFlrAligntype
			, const string srefIxVFlrAligntype
			, const string titIxVFlrAligntype
			, const uint ixVCeilAligntype
			, const string srefIxVCeilAligntype
			, const string titIxVCeilAligntype
		) {
	ubigint retval = 0;
	PlnrQStkList* _rec = NULL;

	_rec = new PlnrQStkList(0, jref, jnum, ref, sref, ixVBasetype, srefIxVBasetype, titIxVBasetype, dsnRefPlnrMDesign, stubDsnRefPlnrMDesign, ixVModtype, srefIxVModtype, titIxVModtype, ixVFlrAligntype, srefIxVFlrAligntype, titIxVFlrAligntype, ixVCeilAligntype, srefIxVCeilAligntype, titIxVCeilAligntype);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrQStkList::appendNewRecToRst(
			ListPlnrQStkList& rst
			, PlnrQStkList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const uint ixVBasetype
			, const string srefIxVBasetype
			, const string titIxVBasetype
			, const ubigint dsnRefPlnrMDesign
			, const string stubDsnRefPlnrMDesign
			, const uint ixVModtype
			, const string srefIxVModtype
			, const string titIxVModtype
			, const uint ixVFlrAligntype
			, const string srefIxVFlrAligntype
			, const string titIxVFlrAligntype
			, const uint ixVCeilAligntype
			, const string srefIxVCeilAligntype
			, const string titIxVCeilAligntype
		) {
	ubigint retval = 0;
	PlnrQStkList* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, sref, ixVBasetype, srefIxVBasetype, titIxVBasetype, dsnRefPlnrMDesign, stubDsnRefPlnrMDesign, ixVModtype, srefIxVModtype, titIxVModtype, ixVFlrAligntype, srefIxVFlrAligntype, titIxVFlrAligntype, ixVCeilAligntype, srefIxVCeilAligntype, titIxVCeilAligntype);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrQStkList::insertRst(
			ListPlnrQStkList& rst
		) {
};

void TblPlnrQStkList::updateRec(
			PlnrQStkList* rec
		) {
};

void TblPlnrQStkList::updateRst(
			ListPlnrQStkList& rst
		) {
};

void TblPlnrQStkList::removeRecByQref(
			ubigint qref
		) {
};

void TblPlnrQStkList::removeRstByJref(
			ubigint jref
		) {
};

bool TblPlnrQStkList::loadRecByQref(
			ubigint qref
			, PlnrQStkList** rec
		) {
	return false;
};

ubigint TblPlnrQStkList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQStkList& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrQStkList
 ******************************************************************************/

MyTblPlnrQStkList::MyTblPlnrQStkList() : TblPlnrQStkList(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblPlnrQStkList::~MyTblPlnrQStkList() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblPlnrQStkList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrQStkList (jref, jnum, ref, sref, ixVBasetype, dsnRefPlnrMDesign, ixVModtype, ixVFlrAligntype, ixVCeilAligntype) VALUES (?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrQStkList SET jref = ?, jnum = ?, ref = ?, sref = ?, ixVBasetype = ?, dsnRefPlnrMDesign = ?, ixVModtype = ?, ixVFlrAligntype = ?, ixVCeilAligntype = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblPlnrQStkList WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblPlnrQStkList WHERE jref = ?", false);
};

bool MyTblPlnrQStkList::loadRecBySQL(
			const string& sqlstr
			, PlnrQStkList** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrQStkList* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQStkList / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrQStkList();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->sref.assign(dbrow[4], dblengths[4]); else _rec->sref = "";
		if (dbrow[5]) _rec->ixVBasetype = atol((char*) dbrow[5]); else _rec->ixVBasetype = 0;
		if (dbrow[6]) _rec->dsnRefPlnrMDesign = atoll((char*) dbrow[6]); else _rec->dsnRefPlnrMDesign = 0;
		if (dbrow[7]) _rec->ixVModtype = atol((char*) dbrow[7]); else _rec->ixVModtype = 0;
		if (dbrow[8]) _rec->ixVFlrAligntype = atol((char*) dbrow[8]); else _rec->ixVFlrAligntype = 0;
		if (dbrow[9]) _rec->ixVCeilAligntype = atol((char*) dbrow[9]); else _rec->ixVCeilAligntype = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrQStkList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQStkList& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrQStkList* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQStkList / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrQStkList();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->sref.assign(dbrow[4], dblengths[4]); else rec->sref = "";
			if (dbrow[5]) rec->ixVBasetype = atol((char*) dbrow[5]); else rec->ixVBasetype = 0;
			if (dbrow[6]) rec->dsnRefPlnrMDesign = atoll((char*) dbrow[6]); else rec->dsnRefPlnrMDesign = 0;
			if (dbrow[7]) rec->ixVModtype = atol((char*) dbrow[7]); else rec->ixVModtype = 0;
			if (dbrow[8]) rec->ixVFlrAligntype = atol((char*) dbrow[8]); else rec->ixVFlrAligntype = 0;
			if (dbrow[9]) rec->ixVCeilAligntype = atol((char*) dbrow[9]); else rec->ixVCeilAligntype = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrQStkList::insertRec(
			PlnrQStkList* rec
		) {
	unsigned long l[9]; my_bool n[9]; my_bool e[9];

	l[3] = rec->sref.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->ixVBasetype,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->dsnRefPlnrMDesign,&(l[5]),&(n[5]),&(e[5])),
		bindUint(&rec->ixVModtype,&(l[6]),&(n[6]),&(e[6])),
		bindUint(&rec->ixVFlrAligntype,&(l[7]),&(n[7]),&(e[7])),
		bindUint(&rec->ixVCeilAligntype,&(l[8]),&(n[8]),&(e[8]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQStkList / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQStkList / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblPlnrQStkList::insertRst(
			ListPlnrQStkList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblPlnrQStkList::updateRec(
			PlnrQStkList* rec
		) {
	unsigned long l[10]; my_bool n[10]; my_bool e[10];

	l[3] = rec->sref.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])), 
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])), 
		bindUint(&rec->ixVBasetype,&(l[4]),&(n[4]),&(e[4])), 
		bindUbigint(&rec->dsnRefPlnrMDesign,&(l[5]),&(n[5]),&(e[5])), 
		bindUint(&rec->ixVModtype,&(l[6]),&(n[6]),&(e[6])), 
		bindUint(&rec->ixVFlrAligntype,&(l[7]),&(n[7]),&(e[7])), 
		bindUint(&rec->ixVCeilAligntype,&(l[8]),&(n[8]),&(e[8])), 
		bindUbigint(&rec->qref,&(l[9]),&(n[9]),&(e[9]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQStkList / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQStkList / stmtUpdateRec)\n");
};

void MyTblPlnrQStkList::updateRst(
			ListPlnrQStkList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblPlnrQStkList::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQStkList / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQStkList / stmtRemoveRecByQref)\n");
};

void MyTblPlnrQStkList::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQStkList / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQStkList / stmtRemoveRstByJref)\n");
};

bool MyTblPlnrQStkList::loadRecByQref(
			ubigint qref
			, PlnrQStkList** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrQStkList WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblPlnrQStkList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQStkList& rst
		) {
	return loadRstBySQL("SELECT * FROM TblPlnrQStkList WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrQStkList
 ******************************************************************************/

PgTblPlnrQStkList::PgTblPlnrQStkList() : TblPlnrQStkList(), PgTable() {
};

PgTblPlnrQStkList::~PgTblPlnrQStkList() {
};

void PgTblPlnrQStkList::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrQStkList_insertRec", "INSERT INTO TblPlnrQStkList (jref, jnum, ref, sref, ixVBasetype, dsnRefPlnrMDesign, ixVModtype, ixVFlrAligntype, ixVCeilAligntype) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9) RETURNING qref", 9, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQStkList_updateRec", "UPDATE TblPlnrQStkList SET jref = $1, jnum = $2, ref = $3, sref = $4, ixVBasetype = $5, dsnRefPlnrMDesign = $6, ixVModtype = $7, ixVFlrAligntype = $8, ixVCeilAligntype = $9 WHERE qref = $10", 10, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQStkList_removeRecByQref", "DELETE FROM TblPlnrQStkList WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQStkList_removeRstByJref", "DELETE FROM TblPlnrQStkList WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrQStkList_loadRecByQref", "SELECT qref, jref, jnum, ref, sref, ixVBasetype, dsnRefPlnrMDesign, ixVModtype, ixVFlrAligntype, ixVCeilAligntype FROM TblPlnrQStkList WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQStkList_loadRstByJref", "SELECT qref, jref, jnum, ref, sref, ixVBasetype, dsnRefPlnrMDesign, ixVModtype, ixVFlrAligntype, ixVCeilAligntype FROM TblPlnrQStkList WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrQStkList::loadRec(
			PGresult* res
			, PlnrQStkList** rec
		) {
	char* ptr;

	PlnrQStkList* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrQStkList();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "dsnrefplnrmdesign"),
			PQfnumber(res, "ixvmodtype"),
			PQfnumber(res, "ixvflraligntype"),
			PQfnumber(res, "ixvceilaligntype")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->ixVBasetype = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->dsnRefPlnrMDesign = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->ixVModtype = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->ixVFlrAligntype = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->ixVCeilAligntype = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrQStkList::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrQStkList& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrQStkList* rec;

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
			PQfnumber(res, "dsnrefplnrmdesign"),
			PQfnumber(res, "ixvmodtype"),
			PQfnumber(res, "ixvflraligntype"),
			PQfnumber(res, "ixvceilaligntype")
		};

		while (numread < numrow) {
			rec = new PlnrQStkList();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->ixVBasetype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->dsnRefPlnrMDesign = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->ixVModtype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->ixVFlrAligntype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->ixVCeilAligntype = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrQStkList::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrQStkList** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQStkList / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQStkList::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrQStkList& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQStkList / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblPlnrQStkList::loadRecBySQL(
			const string& sqlstr
			, PlnrQStkList** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQStkList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQStkList& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrQStkList::insertRec(
			PlnrQStkList* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _ixVBasetype = htonl(rec->ixVBasetype);
	ubigint _dsnRefPlnrMDesign = htonl64(rec->dsnRefPlnrMDesign);
	uint _ixVModtype = htonl(rec->ixVModtype);
	uint _ixVFlrAligntype = htonl(rec->ixVFlrAligntype);
	uint _ixVCeilAligntype = htonl(rec->ixVCeilAligntype);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->sref.c_str(),
		(char*) &_ixVBasetype,
		(char*) &_dsnRefPlnrMDesign,
		(char*) &_ixVModtype,
		(char*) &_ixVFlrAligntype,
		(char*) &_ixVCeilAligntype
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1, 0, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblPlnrQStkList_insertRec", 9, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQStkList_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblPlnrQStkList::insertRst(
			ListPlnrQStkList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblPlnrQStkList::updateRec(
			PlnrQStkList* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _ixVBasetype = htonl(rec->ixVBasetype);
	ubigint _dsnRefPlnrMDesign = htonl64(rec->dsnRefPlnrMDesign);
	uint _ixVModtype = htonl(rec->ixVModtype);
	uint _ixVFlrAligntype = htonl(rec->ixVFlrAligntype);
	uint _ixVCeilAligntype = htonl(rec->ixVCeilAligntype);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->sref.c_str(),
		(char*) &_ixVBasetype,
		(char*) &_dsnRefPlnrMDesign,
		(char*) &_ixVModtype,
		(char*) &_ixVFlrAligntype,
		(char*) &_ixVCeilAligntype,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 1, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblPlnrQStkList_updateRec", 10, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQStkList_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrQStkList::updateRst(
			ListPlnrQStkList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblPlnrQStkList::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblPlnrQStkList_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQStkList_removeRecByQref)\n");

	PQclear(res);
};

void PgTblPlnrQStkList::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblPlnrQStkList_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQStkList_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblPlnrQStkList::loadRecByQref(
			ubigint qref
			, PlnrQStkList** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrQStkList_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblPlnrQStkList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQStkList& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrQStkList_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

