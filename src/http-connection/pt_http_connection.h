#ifndef pt_http_connection_h
#define pt_http_connection_h

#include <uv.h>
#include "queue.h"
#include "http-parser/http_parser.h"

#define PT_MAX_NAME_LEN 1024
#define PT_MAX_HOST_LEN 128
#define PT_MAX_URL_LEN 1024
#define PT_MAX_HTTP_FIELD_LEN 56
#define PT_MAX_HTTP_VALUE_LEN 1024
#define MAX_REQUEST_HEADER_LEN 2048
#define MAX_RESPONSE_HEADER_LEN 2048

typedef struct pt_http_connection pt_http_connection;

struct pt_http_header_field_value {
    char field[PT_MAX_HTTP_FIELD_LEN];
    char value[PT_MAX_HTTP_VALUE_LEN];
    
    QUEUE node;
};

struct pt_http_header {
    http_parser parser;
    struct http_parser_url url;
    char url_buf[PT_MAX_URL_LEN];
    
    QUEUE headers;
};

struct pt_http_connection_settings {
    void (*pt_on_error)(pt_http_connection *conn, void *user_data, int err_code);
    void (*pt_on_connect)(pt_http_connection *conn, void *user_data);
    void (*pt_on_send)(pt_http_connection *conn, const char *buf, size_t len, void *user_data);
    void (*pt_on_header_complete)(pt_http_connection *conn, struct pt_http_header *header, void *user_data);
    void (*pt_on_body)(pt_http_connection *conn, const char *at, size_t length, void *user_data);
    void (*pt_on_message_complete)(pt_http_connection *conn, void *user_data);
    void (*pt_on_chunk_header)(pt_http_connection *conn, void *user_data);
    void (*pt_on_chunk_complete)(pt_http_connection *conn, void *user_data);
};

pt_http_connection* pt_create_http_connection(struct pt_http_connection_settings settings, void *user_data);

pt_http_connection* pt_create_passive_http_connection(uv_stream_t *server, struct pt_http_connection_settings settings, void *user_data);

int pt_http_connection_connect(pt_http_connection *conn, const char host[MAX_HOST_LEN], unsigned short port);

int pt_http_connection_send(pt_http_connection *conn, const char *buf, size_t len);

void pt_free_http_connection(pt_http_connection *conn);

void pt_http_connection_stop_read(pt_http_connection *conn);

void pt_http_connection_start_read(pt_http_connection *conn);


#endif
