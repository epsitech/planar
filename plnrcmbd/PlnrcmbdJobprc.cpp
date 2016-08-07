/**
  * \file PlnrcmbdJobprc.cpp
  * job processor for Plnr combined daemon (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "Plnrcmbd.h"

#include "PlnrcmbdJobprc.h"

/******************************************************************************
 namespace PlnrcmbdJobprc
 ******************************************************************************/

void* PlnrcmbdJobprc::run(
			void* arg
		) {
	XchgPlnrcmbd* xchg = (XchgPlnrcmbd*) arg;

	JobPlnr* job = NULL;

	// open database connection
	DbsPlnr dbsplnr;
	int contry = 10;

	while (contry > 0) {
		try {
			dbsplnr.init(xchg->stgplnrdatabase.ixDbsVDbstype, "", xchg->stgplnrdatabase.dbsname, xchg->stgplnrdatabase.ip,
						xchg->stgplnrdatabase.port, xchg->stgplnrdatabase.username, xchg->stgplnrdatabase.password);
			break;
		} catch (DbsException e) {
			contry--;
			if (contry == 0) throw;
		};
	};

	ReqPlnr* req = NULL;

	// thread settings
	pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, 0);
	pthread_cleanup_push(&cleanup, arg);

	// main loop: wait for requests
	while (true) {
		// req is already here
		req = xchg->pullFirstReq();

		while (req == NULL) {
			// no req here ; wait for it
			Mutex::lock(&(xchg->mcJobprcs), "xchg->mcJobprcs", "PlnrcmbdJobprc", "run");
			Cond::wait(&(xchg->cJobprcs), &(xchg->mcJobprcs), "xchg->cJobprcs", "PlnrcmbdJobprc", "run");

			// note that the result for req might be NULL, if another (idle) job processor strikes first
			req = xchg->pullFirstReq();

			Mutex::unlock(&(xchg->mcJobprcs), "xchg->mcJobprcs", "PlnrcmbdJobprc", "run");
		};

		if (req) {
			// --- handle request
			if (req->ixVBasetype == ReqPlnr::VecVBasetype::CMD) {
				// pass on to job
				accessJob(xchg, &dbsplnr, req);

			} else if (req->ixVBasetype == ReqPlnr::VecVBasetype::REGULAR) {
				if (req->dpchapp) {
					//cout << "PlnrcmbdJobprc::run() REGULAR request: '" << VecPlnrVDpch::getSref(req->dpchapp->ixPlnrVDpch) << "'" << endl;

					// pass on to job
					accessJob(xchg, &dbsplnr, req);
				};

				if (!req->dpcheng) req->dpcheng = new DpchEngPlnrAck(req->jref);

			} else if (req->ixVBasetype == ReqPlnr::VecVBasetype::UPLOAD) {
				//cout << "PlnrcmbdJobprc::run() UPLOAD request file name: '" << req->filename << "'" << endl;

				// pass on to job
				accessJob(xchg, &dbsplnr, req);

				// usually the job leaves req unchanged

			} else if (req->ixVBasetype == ReqPlnr::VecVBasetype::DOWNLOAD) {
				// pass on to job
				accessJob(xchg, &dbsplnr, req);

				// if everything went well, the job has filled in req->filename

			} else if (req->ixVBasetype == ReqPlnr::VecVBasetype::RET) {
				if (req->dpchret) {
					//cout << "PlnrcmbdJobprc::run() RET request: '" << VecPlnrVDpch::getSref(req->dpchret->ixPlnrVDpch) << "'" << endl;

					job = xchg->getJobByJref(req->jref);
					if (job) job->removeOp(req->dpchret->oref);

					accessJob(xchg, &dbsplnr, req);
				};

			} else if (req->ixVBasetype == ReqPlnr::VecVBasetype::TIMER) {
				// pass on to job
				job = xchg->getJobByJref(req->jref);
				if (job) if (req->wref >= job->wrefMin) accessJob(xchg, &dbsplnr, req);
			};

			if ((req->ixVBasetype == ReqPlnr::VecVBasetype::RET) || (req->ixVBasetype == ReqPlnr::VecVBasetype::TIMER)) {
				// ret and timer requests can be deleted here
				delete req;

			} else {
				// all other requests are being waited for for further processing
				if (!(req->retain)) req->setStateReply();
			};
		};
	};

	pthread_cleanup_pop(0);

	return(NULL);
};

void PlnrcmbdJobprc::cleanup(
			void* arg
		) {
	XchgPlnrcmbd* xchg = (XchgPlnrcmbd*) arg;

	Mutex::unlock(&(xchg->mcJobprcs), "xchg->mcJobprcs", "PlnrcmbdJobprc", "cleanup");
};

void PlnrcmbdJobprc::accessJob(
			XchgPlnrcmbd* xchg
			, DbsPlnr* dbsplnr
			, ReqPlnr* req
		) {
	JobPlnr* job = NULL;
	
	job = xchg->getJobByJref(req->jref);
	if (job) {
		if (!req->weak) job->lockAccess("PlnrcmbdJobprc", "accessJob");

		req->ixPlnrVLocale = job->ixPlnrVLocale;
		job->handleRequest(dbsplnr, req);
	};

	if (!req->weak) {
		job = xchg->getJobByJref(req->jref);
		if (job) job->unlockAccess("PlnrcmbdJobprc", "accessJob");
	};
};


