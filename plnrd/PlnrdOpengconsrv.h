/**
  * \file PlnrdOpengconsrv.h
  * op engine connection server for Plnr daemon (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRDOPENGCONSRV_H
#define PLNRDOPENGCONSRV_H

#ifndef _WIN32
	#include <arpa/inet.h>
#endif

/**
  * PlnrdOpengconsrv
  */
namespace PlnrdOpengconsrv {
	MHD_Daemon* start(XchgPlnr* xchg);
	void stop(MHD_Daemon* d);

	int MhdAccept(void* cls, const sockaddr* addr, socklen_t addrlen);
	int MhdCallback(void* cls, MHD_Connection* connection, const char* url, const char* method, const char* version, const char* upload_data, size_t* upload_data_size, void** con_cls);
	int MhdPostrecv(void* con_cls, MHD_ValueKind kind, const char* key, const char* filename, const char* content_type, const char* transfer_encoding, const char* data, uint64_t off, size_t size);
	void MhdComplete(void* cls, MHD_Connection* connection, void** con_cls, MHD_RequestTerminationCode toe);

	uint readDpch(XchgPlnrd* xchg, ReqopengconPlnr* req);
	void writeDpchAck(ReqopengconPlnr* req);
	void writeDpchReg(XchgPlnrd* xchg, ReqopengconPlnr* req, const ubigint nref);
};

#endif


