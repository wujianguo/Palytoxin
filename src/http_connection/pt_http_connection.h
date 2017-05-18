#ifndef pt_http_connection_h
#define pt_http_connection_h


#include <uv.h>
#include "queue.h"

typedef struct pt_http_connection pt_http_connection;

struct pt_http_header_field_value {
    char field[MAX_HTTP_FIELD_LEN];
    char value[MAX_HTTP_VALUE_LEN];
    
    QUEUE node;
};

struct pt_http_header {
    http_parser parser;
    struct http_parser_url url;
    char url_buf[MAX_URL_LEN];
    
    QUEUE headers;
};

struct pt_http_connection_settings {
    void (*on_error)(pt_http_connection *conn, void *user_data, int err_code);
    void (*on_connect)(pt_http_connection *conn, void *user_data);
    void (*on_send)(pt_http_connection *conn, void *user_data);
    void (*on_header_complete)(pt_http_connection *conn, struct http_header *header, void *user_data);
    void (*on_body)(pt_http_connection *conn, const char *at, size_t length, void *user_data);
    void (*on_message_complete)(pt_http_connection *conn, void *user_data);
    void (*on_chunk_header)(pt_http_connection *conn, void *user_data);
    void (*on_chunk_complete)(pt_http_connection *conn, void *user_data);
};

pt_http_connection* pt_create_http_connection(uv_loop_t *loop, struct pt_http_connection_settings settings, void *user_data);

pt_http_connection* pt_create_passive_http_connection(uv_stream_t *server, struct pt_http_connection_settings settings, void *user_data);

int pt_http_connection_connect(pt_http_connection *conn, const char host[MAX_HOST_LEN], unsigned short port);

int pt_http_connection_send(pt_http_connection *conn, const char *buf, size_t len);

void pt_free_http_connection(pt_http_connection *conn);

void pt_http_connection_stop_read(pt_http_connection *conn);

void pt_http_connection_start_read(pt_http_connection *conn);


#endif
