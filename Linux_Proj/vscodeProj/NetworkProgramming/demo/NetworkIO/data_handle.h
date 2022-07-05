#ifndef _DATA_HANDLE_H
#define _DATA_HANDLE_H

#include <sys/uio.h>

struct iovec *vs =NULL, *vc=NULL;

void handle_conn_server_rwv(int s);
void handle_conn_client_rwv(int s);

void handle_conn_client_sr(int s);
void handle_conn_server_sr(int s);

void handle_conn_client_srmsg(int s);
void handle_conn_server_srmsg(int s);

#endif // !_DATA_HANDLE_H   

