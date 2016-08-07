/**
  * \file PlnrQDvcList.cpp
  * Dbs and XML wrapper for table TblPlnrQDvcList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQDvcList.h"

/******************************************************************************
 class PlnrQDvcList
 ******************************************************************************/

PlnrQDvcList::PlnrQDvcList(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const ubigint dsnRefPlnrMDesign
			, const string stubDsnRefPlnrMDesign
			, const ubigint supRefPlnrMDevice
			, const string stubSupRefPlnrMDevice
			, const ubigint tplRefPlnrMDevice
			, const string stubTplRefPlnrMDevice
			, const uint ixVModtype
			, const string srefIxVModtype
			, const string titIxVModtype
			, const uint ixVAligntype
			, const string srefIxVAligntype
			, const string titIxVAligntype
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->sref = sref;
	this->dsnRefPlnrMDesign = dsnRefPlnrMDesign;
	this->stubDsnRefPlnrMDesign = stubDsnRefPlnrMDesign;
	this->supRefPlnrMDevice = supRefPlnrMDevice;
	this->stubSupRefPlnrMDevice = stubSupRefPlnrMDevice;
	this->tplRefPlnrMDevice = tplRefPlnrMDevice;
	this->stubTplRefPlnrMDevice = stubTplRefPlnrMDevice;
	this->ixVModtype = ixVModtype;
	this->srefIxVModtype = srefIxVModtype;
	this->titIxVModtype = titIxVModtype;
	this->ixVAligntype = ixVAligntype;
	this->srefIxVAligntype = srefIxVAligntype;
	this->titIxVAligntype = titIxVAligntype;
};

void PlnrQDvcList::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "PlnrQDvcList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "srf", sref);
		writeString(wr, "dsn", stubDsnRefPlnrMDesign);
		writeString(wr, "sup", stubSupRefPlnrMDevice);
		writeString(wr, "tpl", stubTplRefPlnrMDevice);
		writeString(wr, "mty", srefIxVModtype);
		writeString(wr, "mty2", titIxVModtype);
		writeString(wr, "aty", srefIxVAligntype);
		writeString(wr, "aty2", titIxVAligntype);
	} else {
		writeString(wr, "sref", sref);
		writeString(wr, "stubDsnRefPlnrMDesign", stubDsnRefPlnrMDesign);
		writeString(wr, "stubSupRefPlnrMDevice", stubSupRefPlnrMDevice);
		writeString(wr, "stubTplRefPlnrMDevice", stubTplRefPlnrMDevice);
		writeString(wr, "srefIxVModtype", srefIxVModtype);
		writeString(wr, "titIxVModtype", titIxVModtype);
		writeString(wr, "srefIxVAligntype", srefIxVAligntype);
		writeString(wr, "titIxVAligntype", titIxVAligntype);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListPlnrQDvcList
 ******************************************************************************/

ListPlnrQDvcList::ListPlnrQDvcList() {
};

ListPlnrQDvcList::ListPlnrQDvcList(
			const ListPlnrQDvcList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQDvcList(*(src.nodes[i]));
};

ListPlnrQDvcList::~ListPlnrQDvcList() {
	clear();
};

void ListPlnrQDvcList::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrQDvcList::size() const {
	return(nodes.size());
};

void ListPlnrQDvcList::append(
			PlnrQDvcList* rec
		) {
	nodes.push_back(rec);
};

ListPlnrQDvcList& ListPlnrQDvcList::operator=(
			const ListPlnrQDvcList& src
		) {
	PlnrQDvcList* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrQDvcList(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListPlnrQDvcList::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListPlnrQDvcList";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblPlnrQDvcList
 ******************************************************************************/

TblPlnrQDvcList::TblPlnrQDvcList() {
};

TblPlnrQDvcList::~TblPlnrQDvcList() {
};

bool TblPlnrQDvcList::loadRecBySQL(
			const string& sqlstr
			, PlnrQDvcList** rec
		) {
	return false;
};

ubigint TblPlnrQDvcList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQDvcList& rst
		) {
	return 0;
};

void TblPlnrQDvcList::insertRec(
			PlnrQDvcList* rec
		) {
};

ubigint TblPlnrQDvcList::insertNewRec(
			PlnrQDvcList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const ubigint dsnRefPlnrMDesign
			, const string stubDsnRefPlnrMDesign
			, const ubigint supRefPlnrMDevice
			, const string stubSupRefPlnrMDevice
			, const ubigint tplRefPlnrMDevice
			, const string stubTplRefPlnrMDevice
			, const uint ixVModtype
			, const string srefIxVModtype
			, const string titIxVModtype
			, const uint ixVAligntype
			, const string srefIxVAligntype
			, const string titIxVAligntype
		) {
	ubigint retval = 0;
	PlnrQDvcList* _rec = NULL;

	_rec = new PlnrQDvcList(0, jref, jnum, ref, sref, dsnRefPlnrMDesign, stubDsnRefPlnrMDesign, supRefPlnrMDevice, stubSupRefPlnrMDevice, tplRefPlnrMDevice, stubTplRefPlnrMDevice, ixVModtype, srefIxVModtype, titIxVModtype, ixVAligntype, srefIxVAligntype, titIxVAligntype);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrQDvcList::appendNewRecToRst(
			ListPlnrQDvcList& rst
			, PlnrQDvcList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const ubigint dsnRefPlnrMDesign
			, const string stubDsnRefPlnrMDesign
			, const ubigint supRefPlnrMDevice
			, const string stubSupRefPlnrMDevice
			, const ubigint tplRefPlnrMDevice
			, const string stubTplRefPlnrMDevice
			, const uint ixVModtype
			, const string srefIxVModtype
			, const string titIxVModtype
			, const uint ixVAligntype
			, const string srefIxVAligntype
			, const string titIxVAligntype
		) {
	ubigint retval = 0;
	PlnrQDvcList* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, sref, dsnRefPlnrMDesign, stubDsnRefPlnrMDesign, supRefPlnrMDevice, stubSupRefPlnrMDevice, tplRefPlnrMDevice, stubTplRefPlnrMDevice, ixVModtype, srefIxVModtype, titIxVModtype, ixVAligntype, srefIxVAligntype, titIxVAligntype);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrQDvcList::insertRst(
			ListPlnrQDvcList& rst
		) {
};

void TblPlnrQDvcList::updateRec(
			PlnrQDvcList* rec
		) {
};

void TblPlnrQDvcList::updateRst(
			ListPlnrQDvcList& rst
		) {
};

void TblPlnrQDvcList::removeRecByQref(
			ubigint qref
		) {
};

void TblPlnrQDvcList::removeRstByJref(
			ubigint jref
		) {
};

bool TblPlnrQDvcList::loadRecByQref(
			ubigint qref
			, PlnrQDvcList** rec
		) {
	return false;
};

ubigint TblPlnrQDvcList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQDvcList& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrQDvcList
 ******************************************************************************/

MyTblPlnrQDvcList::MyTblPlnrQDvcList() : TblPlnrQDvcList(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblPlnrQDvcList::~MyTblPlnrQDvcList() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblPlnrQDvcList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrQDvcList (jref, jnum, ref, sref, dsnRefPlnrMDesign, supRefPlnrMDevice, tplRefPlnrMDevice, ixVModtype, ixVAligntype) VALUES (?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrQDvcList SET jref = ?, jnum = ?, ref = ?, sref = ?, dsnRefPlnrMDesign = ?, supRefPlnrMDevice = ?, tplRefPlnrMDevice = ?, ixVModtype = ?, ixVAligntype = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblPlnrQDvcList WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblPlnrQDvcList WHERE jref = ?", false);
};

bool MyTblPlnrQDvcList::loadRecBySQL(
			const string& sqlstr
			, PlnrQDvcList** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrQDvcList* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQDvcList / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrQDvcList();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->sref.assign(dbrow[4], dblengths[4]); else _rec->sref = "";
		if (dbrow[5]) _rec->dsnRefPlnrMDesign = atoll((char*) dbrow[5]); else _rec->dsnRefPlnrMDesign = 0;
		if (dbrow[6]) _rec->supRefPlnrMDevice = atoll((char*) dbrow[6]); else _rec->supRefPlnrMDevice = 0;
		if (dbrow[7]) _rec->tplRefPlnrMDevice = atoll((char*) dbrow[7]); else _rec->tplRefPlnrMDevice = 0;
		if (dbrow[8]) _rec->ixVModtype = atol((char*) dbrow[8]); else _rec->ixVModtype = 0;
		if (dbrow[9]) _rec->ixVAligntype = atol((char*) dbrow[9]); else _rec->ixVAligntype = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrQDvcList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQDvcList& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrQDvcList* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQDvcList / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrQDvcList();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->sref.assign(dbrow[4], dblengths[4]); else rec->sref = "";
			if (dbrow[5]) rec->dsnRefPlnrMDesign = atoll((char*) dbrow[5]); else rec->dsnRefPlnrMDesign = 0;
			if (dbrow[6]) rec->supRefPlnrMDevice = atoll((char*) dbrow[6]); else rec->supRefPlnrMDevice = 0;
			if (dbrow[7]) rec->tplRefPlnrMDevice = atoll((char*) dbrow[7]); else rec->tplRefPlnrMDevice = 0;
			if (dbrow[8]) rec->ixVModtype = atol((char*) dbrow[8]); else rec->ixVModtype = 0;
			if (dbrow[9]) rec->ixVAligntype = atol((char*) dbrow[9]); else rec->ixVAligntype = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrQDvcList::insertRec(
			PlnrQDvcList* rec
		) {
	unsigned long l[9]; my_bool n[9]; my_bool e[9];

	l[3] = rec->sref.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->dsnRefPlnrMDesign,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->supRefPlnrMDevice,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->tplRefPlnrMDevice,&(l[6]),&(n[6]),&(e[6])),
		bindUint(&rec->ixVModtype,&(l[7]),&(n[7]),&(e[7])),
		bindUint(&rec->ixVAligntype,&(l[8]),&(n[8]),&(e[8]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQDvcList / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQDvcList / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblPlnrQDvcList::insertRst(
			ListPlnrQDvcList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblPlnrQDvcList::updateRec(
			PlnrQDvcList* rec
		) {
	unsigned long l[10]; my_bool n[10]; my_bool e[10];

	l[3] = rec->sref.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])), 
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])), 
		bindUbigint(&rec->dsnRefPlnrMDesign,&(l[4]),&(n[4]),&(e[4])), 
		bindUbigint(&rec->supRefPlnrMDevice,&(l[5]),&(n[5]),&(e[5])), 
		bindUbigint(&rec->tplRefPlnrMDevice,&(l[6]),&(n[6]),&(e[6])), 
		bindUint(&rec->ixVModtype,&(l[7]),&(n[7]),&(e[7])), 
		bindUint(&rec->ixVAligntype,&(l[8]),&(n[8]),&(e[8])), 
		bindUbigint(&rec->qref,&(l[9]),&(n[9]),&(e[9]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQDvcList / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQDvcList / stmtUpdateRec)\n");
};

void MyTblPlnrQDvcList::updateRst(
			ListPlnrQDvcList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblPlnrQDvcList::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQDvcList / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQDvcList / stmtRemoveRecByQref)\n");
};

void MyTblPlnrQDvcList::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQDvcList / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQDvcList / stmtRemoveRstByJref)\n");
};

bool MyTblPlnrQDvcList::loadRecByQref(
			ubigint qref
			, PlnrQDvcList** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrQDvcList WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblPlnrQDvcList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQDvcList& rst
		) {
	return loadRstBySQL("SELECT * FROM TblPlnrQDvcList WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrQDvcList
 ******************************************************************************/

PgTblPlnrQDvcList::PgTblPlnrQDvcList() : TblPlnrQDvcList(), PgTable() {
};

PgTblPlnrQDvcList::~PgTblPlnrQDvcList() {
};

void PgTblPlnrQDvcList::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrQDvcList_insertRec", "INSERT INTO TblPlnrQDvcList (jref, jnum, ref, sref, dsnRefPlnrMDesign, supRefPlnrMDevice, tplRefPlnrMDevice, ixVModtype, ixVAligntype) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9) RETURNING qref", 9, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQDvcList_updateRec", "UPDATE TblPlnrQDvcList SET jref = $1, jnum = $2, ref = $3, sref = $4, dsnRefPlnrMDesign = $5, supRefPlnrMDevice = $6, tplRefPlnrMDevice = $7, ixVModtype = $8, ixVAligntype = $9 WHERE qref = $10", 10, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQDvcList_removeRecByQref", "DELETE FROM TblPlnrQDvcList WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQDvcList_removeRstByJref", "DELETE FROM TblPlnrQDvcList WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrQDvcList_loadRecByQref", "SELECT qref, jref, jnum, ref, sref, dsnRefPlnrMDesign, supRefPlnrMDevice, tplRefPlnrMDevice, ixVModtype, ixVAligntype FROM TblPlnrQDvcList WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQDvcList_loadRstByJref", "SELECT qref, jref, jnum, ref, sref, dsnRefPlnrMDesign, supRefPlnrMDevice, tplRefPlnrMDevice, ixVModtype, ixVAligntype FROM TblPlnrQDvcList WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrQDvcList::loadRec(
			PGresult* res
			, PlnrQDvcList** rec
		) {
	char* ptr;

	PlnrQDvcList* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrQDvcList();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "dsnrefplnrmdesign"),
			PQfnumber(res, "suprefplnrmdevice"),
			PQfnumber(res, "tplrefplnrmdevice"),
			PQfnumber(res, "ixvmodtype"),
			PQfnumber(res, "ixvaligntype")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->dsnRefPlnrMDesign = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->supRefPlnrMDevice = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->tplRefPlnrMDevice = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->ixVModtype = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->ixVAligntype = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrQDvcList::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrQDvcList& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrQDvcList* rec;

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
			PQfnumber(res, "dsnrefplnrmdesign"),
			PQfnumber(res, "suprefplnrmdevice"),
			PQfnumber(res, "tplrefplnrmdevice"),
			PQfnumber(res, "ixvmodtype"),
			PQfnumber(res, "ixvaligntype")
		};

		while (numread < numrow) {
			rec = new PlnrQDvcList();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->dsnRefPlnrMDesign = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->supRefPlnrMDevice = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->tplRefPlnrMDevice = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->ixVModtype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->ixVAligntype = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrQDvcList::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrQDvcList** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDvcList / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQDvcList::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrQDvcList& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDvcList / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblPlnrQDvcList::loadRecBySQL(
			const string& sqlstr
			, PlnrQDvcList** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQDvcList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQDvcList& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrQDvcList::insertRec(
			PlnrQDvcList* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _dsnRefPlnrMDesign = htonl64(rec->dsnRefPlnrMDesign);
	ubigint _supRefPlnrMDevice = htonl64(rec->supRefPlnrMDevice);
	ubigint _tplRefPlnrMDevice = htonl64(rec->tplRefPlnrMDevice);
	uint _ixVModtype = htonl(rec->ixVModtype);
	uint _ixVAligntype = htonl(rec->ixVAligntype);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->sref.c_str(),
		(char*) &_dsnRefPlnrMDesign,
		(char*) &_supRefPlnrMDevice,
		(char*) &_tplRefPlnrMDevice,
		(char*) &_ixVModtype,
		(char*) &_ixVAligntype
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1, 0, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblPlnrQDvcList_insertRec", 9, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDvcList_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblPlnrQDvcList::insertRst(
			ListPlnrQDvcList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblPlnrQDvcList::updateRec(
			PlnrQDvcList* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _dsnRefPlnrMDesign = htonl64(rec->dsnRefPlnrMDesign);
	ubigint _supRefPlnrMDevice = htonl64(rec->supRefPlnrMDevice);
	ubigint _tplRefPlnrMDevice = htonl64(rec->tplRefPlnrMDevice);
	uint _ixVModtype = htonl(rec->ixVModtype);
	uint _ixVAligntype = htonl(rec->ixVAligntype);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->sref.c_str(),
		(char*) &_dsnRefPlnrMDesign,
		(char*) &_supRefPlnrMDevice,
		(char*) &_tplRefPlnrMDevice,
		(char*) &_ixVModtype,
		(char*) &_ixVAligntype,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 1, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblPlnrQDvcList_updateRec", 10, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDvcList_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrQDvcList::updateRst(
			ListPlnrQDvcList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblPlnrQDvcList::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblPlnrQDvcList_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDvcList_removeRecByQref)\n");

	PQclear(res);
};

void PgTblPlnrQDvcList::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblPlnrQDvcList_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDvcList_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblPlnrQDvcList::loadRecByQref(
			ubigint qref
			, PlnrQDvcList** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrQDvcList_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblPlnrQDvcList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQDvcList& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrQDvcList_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

