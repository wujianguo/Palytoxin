#include "pt_dispatcher.h"
#include "queue.h"

typedef struct pt_dispatcher {
    char *url;
    QUEUE connection;
} pt_dispatcher;


void on_error(pt_http_connection *conn, void *user_data, int err_code) {

}

void on_connect(pt_http_connection *conn, void *user_data) {

}
void on_send(pt_http_connection *conn, void *user_data) {

}
void on_header_complete(pt_http_connection *conn, struct http_header *header, void *user_data) {

}
void on_body(pt_http_connection *conn, const char *at, size_t length, void *user_data) {

}
void on_message_complete(pt_http_connection *conn, void *user_data) {

}
void on_chunk_header(pt_http_connection *conn, void *user_data) {
    
}
void on_chunk_complete(pt_http_connection *conn, void *user_data) {

}

static pt_http_connection *create_connection(pt_dispatcher *dispatcher, char *url, range rg) {
    struct pt_http_connection_settings settings = {on_error, on_connect, on_send, on_header_complete, on_body, on_message_complete, on_chunk_header, on_chunk_complete};
    pt_http_connection *conn = pt_create_http_connection(pt_get_current_loop(), settings, dispatcher);
    pt_http_connection_connect(conn, "", 80);
    return conn;
}

static void dispatch_connections(pt_dispatcher *dispatcher) {

}

pt_dispatcher *pt_create_dispatcher(const char *url, pt_idata_cache *cache, pt_dispatcher_callback callback, pt_idata_cache_for_pipe cache_interface, void *user_data) {
    pt_dispatcher *dispatcher = (pt_dispatcher *)malloc(sizeof(pt_dispatcher));
    return dispatcher;
}

int pt_dispatcher_get_download_speed(pt_dispatcher *dispatcher, double *speed) {
    return 0;
}

int pt_free_dispatcher(pt_dispatcher *dispatcher) {
    return 0;
}