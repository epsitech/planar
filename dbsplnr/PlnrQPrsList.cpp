/**
  * \file PlnrQPrsList.cpp
  * Dbs and XML wrapper for table TblPlnrQPrsList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQPrsList.h"

/******************************************************************************
 class PlnrQPrsList
 ******************************************************************************/

PlnrQPrsList::PlnrQPrsList(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string Title
			, const string Firstname
			, const string Lastname
			, const ubigint grp
			, const string stubGrp
			, const ubigint own
			, const string stubOwn
			, const uint ixVSex
			, const string srefIxVSex
			, const string titIxVSex
			, const string Tel
			, const string Eml
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->Title = Title;
	this->Firstname = Firstname;
	this->Lastname = Lastname;
	this->grp = grp;
	this->stubGrp = stubGrp;
	this->own = own;
	this->stubOwn = stubOwn;
	this->ixVSex = ixVSex;
	this->srefIxVSex = srefIxVSex;
	this->titIxVSex = titIxVSex;
	this->Tel = Tel;
	this->Eml = Eml;
};

void PlnrQPrsList::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "PlnrQPrsList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "tit", Title);
		writeString(wr, "fnm", Firstname);
		writeString(wr, "lnm", Lastname);
		writeString(wr, "grp", stubGrp);
		writeString(wr, "own", stubOwn);
		writeString(wr, "sex", srefIxVSex);
		writeString(wr, "sex2", titIxVSex);
		writeString(wr, "tel", Tel);
		writeString(wr, "eml", Eml);
	} else {
		writeString(wr, "Title", Title);
		writeString(wr, "Firstname", Firstname);
		writeString(wr, "Lastname", Lastname);
		writeString(wr, "stubGrp", stubGrp);
		writeString(wr, "stubOwn", stubOwn);
		writeString(wr, "srefIxVSex", srefIxVSex);
		writeString(wr, "titIxVSex", titIxVSex);
		writeString(wr, "Tel", Tel);
		writeString(wr, "Eml", Eml);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListPlnrQPrsList
 ******************************************************************************/

ListPlnrQPrsList::ListPlnrQPrsList() {
};

ListPlnrQPrsList::ListPlnrQPrsList(
			const ListPlnrQPrsList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQPrsList(*(src.nodes[i]));
};

ListPlnrQPrsList::~ListPlnrQPrsList() {
	clear();
};

void ListPlnrQPrsList::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrQPrsList::size() const {
	return(nodes.size());
};

void ListPlnrQPrsList::append(
			PlnrQPrsList* rec
		) {
	nodes.push_back(rec);
};

ListPlnrQPrsList& ListPlnrQPrsList::operator=(
			const ListPlnrQPrsList& src
		) {
	PlnrQPrsList* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrQPrsList(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListPlnrQPrsList::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListPlnrQPrsList";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblPlnrQPrsList
 ******************************************************************************/

TblPlnrQPrsList::TblPlnrQPrsList() {
};

TblPlnrQPrsList::~TblPlnrQPrsList() {
};

bool TblPlnrQPrsList::loadRecBySQL(
			const string& sqlstr
			, PlnrQPrsList** rec
		) {
	return false;
};

ubigint TblPlnrQPrsList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQPrsList& rst
		) {
	return 0;
};

void TblPlnrQPrsList::insertRec(
			PlnrQPrsList* rec
		) {
};

ubigint TblPlnrQPrsList::insertNewRec(
			PlnrQPrsList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string Title
			, const string Firstname
			, const string Lastname
			, const ubigint grp
			, const string stubGrp
			, const ubigint own
			, const string stubOwn
			, const uint ixVSex
			, const string srefIxVSex
			, const string titIxVSex
			, const string Tel
			, const string Eml
		) {
	ubigint retval = 0;
	PlnrQPrsList* _rec = NULL;

	_rec = new PlnrQPrsList(0, jref, jnum, ref, Title, Firstname, Lastname, grp, stubGrp, own, stubOwn, ixVSex, srefIxVSex, titIxVSex, Tel, Eml);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrQPrsList::appendNewRecToRst(
			ListPlnrQPrsList& rst
			, PlnrQPrsList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string Title
			, const string Firstname
			, const string Lastname
			, const ubigint grp
			, const string stubGrp
			, const ubigint own
			, const string stubOwn
			, const uint ixVSex
			, const string srefIxVSex
			, const string titIxVSex
			, const string Tel
			, const string Eml
		) {
	ubigint retval = 0;
	PlnrQPrsList* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, Title, Firstname, Lastname, grp, stubGrp, own, stubOwn, ixVSex, srefIxVSex, titIxVSex, Tel, Eml);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrQPrsList::insertRst(
			ListPlnrQPrsList& rst
		) {
};

void TblPlnrQPrsList::updateRec(
			PlnrQPrsList* rec
		) {
};

void TblPlnrQPrsList::updateRst(
			ListPlnrQPrsList& rst
		) {
};

void TblPlnrQPrsList::removeRecByQref(
			ubigint qref
		) {
};

void TblPlnrQPrsList::removeRstByJref(
			ubigint jref
		) {
};

bool TblPlnrQPrsList::loadRecByQref(
			ubigint qref
			, PlnrQPrsList** rec
		) {
	return false;
};

ubigint TblPlnrQPrsList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQPrsList& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrQPrsList
 ******************************************************************************/

MyTblPlnrQPrsList::MyTblPlnrQPrsList() : TblPlnrQPrsList(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblPlnrQPrsList::~MyTblPlnrQPrsList() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblPlnrQPrsList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrQPrsList (jref, jnum, ref, Title, Firstname, Lastname, grp, own, ixVSex, Tel, Eml) VALUES (?,?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrQPrsList SET jref = ?, jnum = ?, ref = ?, Title = ?, Firstname = ?, Lastname = ?, grp = ?, own = ?, ixVSex = ?, Tel = ?, Eml = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblPlnrQPrsList WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblPlnrQPrsList WHERE jref = ?", false);
};

bool MyTblPlnrQPrsList::loadRecBySQL(
			const string& sqlstr
			, PlnrQPrsList** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrQPrsList* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQPrsList / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrQPrsList();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->Title.assign(dbrow[4], dblengths[4]); else _rec->Title = "";
		if (dbrow[5]) _rec->Firstname.assign(dbrow[5], dblengths[5]); else _rec->Firstname = "";
		if (dbrow[6]) _rec->Lastname.assign(dbrow[6], dblengths[6]); else _rec->Lastname = "";
		if (dbrow[7]) _rec->grp = atoll((char*) dbrow[7]); else _rec->grp = 0;
		if (dbrow[8]) _rec->own = atoll((char*) dbrow[8]); else _rec->own = 0;
		if (dbrow[9]) _rec->ixVSex = atol((char*) dbrow[9]); else _rec->ixVSex = 0;
		if (dbrow[10]) _rec->Tel.assign(dbrow[10], dblengths[10]); else _rec->Tel = "";
		if (dbrow[11]) _rec->Eml.assign(dbrow[11], dblengths[11]); else _rec->Eml = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrQPrsList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQPrsList& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrQPrsList* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQPrsList / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrQPrsList();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->Title.assign(dbrow[4], dblengths[4]); else rec->Title = "";
			if (dbrow[5]) rec->Firstname.assign(dbrow[5], dblengths[5]); else rec->Firstname = "";
			if (dbrow[6]) rec->Lastname.assign(dbrow[6], dblengths[6]); else rec->Lastname = "";
			if (dbrow[7]) rec->grp = atoll((char*) dbrow[7]); else rec->grp = 0;
			if (dbrow[8]) rec->own = atoll((char*) dbrow[8]); else rec->own = 0;
			if (dbrow[9]) rec->ixVSex = atol((char*) dbrow[9]); else rec->ixVSex = 0;
			if (dbrow[10]) rec->Tel.assign(dbrow[10], dblengths[10]); else rec->Tel = "";
			if (dbrow[11]) rec->Eml.assign(dbrow[11], dblengths[11]); else rec->Eml = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrQPrsList::insertRec(
			PlnrQPrsList* rec
		) {
	unsigned long l[11]; my_bool n[11]; my_bool e[11];

	l[3] = rec->Title.length();
	l[4] = rec->Firstname.length();
	l[5] = rec->Lastname.length();
	l[9] = rec->Tel.length();
	l[10] = rec->Eml.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Title.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Firstname.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->Lastname.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->grp,&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->own,&(l[7]),&(n[7]),&(e[7])),
		bindUint(&rec->ixVSex,&(l[8]),&(n[8]),&(e[8])),
		bindCstring((char*) (rec->Tel.c_str()),&(l[9]),&(n[9]),&(e[9])),
		bindCstring((char*) (rec->Eml.c_str()),&(l[10]),&(n[10]),&(e[10]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQPrsList / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQPrsList / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblPlnrQPrsList::insertRst(
			ListPlnrQPrsList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblPlnrQPrsList::updateRec(
			PlnrQPrsList* rec
		) {
	unsigned long l[12]; my_bool n[12]; my_bool e[12];

	l[3] = rec->Title.length();
	l[4] = rec->Firstname.length();
	l[5] = rec->Lastname.length();
	l[9] = rec->Tel.length();
	l[10] = rec->Eml.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])), 
		bindCstring((char*) (rec->Title.c_str()),&(l[3]),&(n[3]),&(e[3])), 
		bindCstring((char*) (rec->Firstname.c_str()),&(l[4]),&(n[4]),&(e[4])), 
		bindCstring((char*) (rec->Lastname.c_str()),&(l[5]),&(n[5]),&(e[5])), 
		bindUbigint(&rec->grp,&(l[6]),&(n[6]),&(e[6])), 
		bindUbigint(&rec->own,&(l[7]),&(n[7]),&(e[7])), 
		bindUint(&rec->ixVSex,&(l[8]),&(n[8]),&(e[8])), 
		bindCstring((char*) (rec->Tel.c_str()),&(l[9]),&(n[9]),&(e[9])), 
		bindCstring((char*) (rec->Eml.c_str()),&(l[10]),&(n[10]),&(e[10])), 
		bindUbigint(&rec->qref,&(l[11]),&(n[11]),&(e[11]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQPrsList / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQPrsList / stmtUpdateRec)\n");
};

void MyTblPlnrQPrsList::updateRst(
			ListPlnrQPrsList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblPlnrQPrsList::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQPrsList / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQPrsList / stmtRemoveRecByQref)\n");
};

void MyTblPlnrQPrsList::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQPrsList / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQPrsList / stmtRemoveRstByJref)\n");
};

bool MyTblPlnrQPrsList::loadRecByQref(
			ubigint qref
			, PlnrQPrsList** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrQPrsList WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblPlnrQPrsList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQPrsList& rst
		) {
	return loadRstBySQL("SELECT * FROM TblPlnrQPrsList WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrQPrsList
 ******************************************************************************/

PgTblPlnrQPrsList::PgTblPlnrQPrsList() : TblPlnrQPrsList(), PgTable() {
};

PgTblPlnrQPrsList::~PgTblPlnrQPrsList() {
};

void PgTblPlnrQPrsList::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrQPrsList_insertRec", "INSERT INTO TblPlnrQPrsList (jref, jnum, ref, Title, Firstname, Lastname, grp, own, ixVSex, Tel, Eml) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11) RETURNING qref", 11, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQPrsList_updateRec", "UPDATE TblPlnrQPrsList SET jref = $1, jnum = $2, ref = $3, Title = $4, Firstname = $5, Lastname = $6, grp = $7, own = $8, ixVSex = $9, Tel = $10, Eml = $11 WHERE qref = $12", 12, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQPrsList_removeRecByQref", "DELETE FROM TblPlnrQPrsList WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQPrsList_removeRstByJref", "DELETE FROM TblPlnrQPrsList WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrQPrsList_loadRecByQref", "SELECT qref, jref, jnum, ref, Title, Firstname, Lastname, grp, own, ixVSex, Tel, Eml FROM TblPlnrQPrsList WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQPrsList_loadRstByJref", "SELECT qref, jref, jnum, ref, Title, Firstname, Lastname, grp, own, ixVSex, Tel, Eml FROM TblPlnrQPrsList WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrQPrsList::loadRec(
			PGresult* res
			, PlnrQPrsList** rec
		) {
	char* ptr;

	PlnrQPrsList* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrQPrsList();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "title"),
			PQfnumber(res, "firstname"),
			PQfnumber(res, "lastname"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "ixvsex"),
			PQfnumber(res, "tel"),
			PQfnumber(res, "eml")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->Firstname.assign(ptr, PQgetlength(res, 0, fnum[5]));
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->Lastname.assign(ptr, PQgetlength(res, 0, fnum[6]));
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->grp = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->own = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->ixVSex = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->Tel.assign(ptr, PQgetlength(res, 0, fnum[10]));
		ptr = PQgetvalue(res, 0, fnum[11]); _rec->Eml.assign(ptr, PQgetlength(res, 0, fnum[11]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrQPrsList::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrQPrsList& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrQPrsList* rec;

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
			PQfnumber(res, "firstname"),
			PQfnumber(res, "lastname"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "ixvsex"),
			PQfnumber(res, "tel"),
			PQfnumber(res, "eml")
		};

		while (numread < numrow) {
			rec = new PlnrQPrsList();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->Firstname.assign(ptr, PQgetlength(res, numread, fnum[5]));
			ptr = PQgetvalue(res, numread, fnum[6]); rec->Lastname.assign(ptr, PQgetlength(res, numread, fnum[6]));
			ptr = PQgetvalue(res, numread, fnum[7]); rec->grp = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->own = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->ixVSex = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[10]); rec->Tel.assign(ptr, PQgetlength(res, numread, fnum[10]));
			ptr = PQgetvalue(res, numread, fnum[11]); rec->Eml.assign(ptr, PQgetlength(res, numread, fnum[11]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrQPrsList::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrQPrsList** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQPrsList / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQPrsList::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrQPrsList& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQPrsList / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblPlnrQPrsList::loadRecBySQL(
			const string& sqlstr
			, PlnrQPrsList** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQPrsList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQPrsList& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrQPrsList::insertRec(
			PlnrQPrsList* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	uint _ixVSex = htonl(rec->ixVSex);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->Title.c_str(),
		rec->Firstname.c_str(),
		rec->Lastname.c_str(),
		(char*) &_grp,
		(char*) &_own,
		(char*) &_ixVSex,
		rec->Tel.c_str(),
		rec->Eml.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		0,
		0,
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		0,
		0
	};
	const int f[] = {1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblPlnrQPrsList_insertRec", 11, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQPrsList_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblPlnrQPrsList::insertRst(
			ListPlnrQPrsList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblPlnrQPrsList::updateRec(
			PlnrQPrsList* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	uint _ixVSex = htonl(rec->ixVSex);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->Title.c_str(),
		rec->Firstname.c_str(),
		rec->Lastname.c_str(),
		(char*) &_grp,
		(char*) &_own,
		(char*) &_ixVSex,
		rec->Tel.c_str(),
		rec->Eml.c_str(),
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		0,
		0,
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblPlnrQPrsList_updateRec", 12, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQPrsList_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrQPrsList::updateRst(
			ListPlnrQPrsList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblPlnrQPrsList::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblPlnrQPrsList_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQPrsList_removeRecByQref)\n");

	PQclear(res);
};

void PgTblPlnrQPrsList::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblPlnrQPrsList_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQPrsList_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblPlnrQPrsList::loadRecByQref(
			ubigint qref
			, PlnrQPrsList** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrQPrsList_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblPlnrQPrsList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQPrsList& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrQPrsList_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

