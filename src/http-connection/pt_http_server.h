#ifndef pt_http_server_h
#define pt_http_server_h

#include "queue.h"

struct pt_http_connection;


struct pt_http_session {
    struct pt_http_connection *connection;
    void (*complete)(struct pt_http_session *session);
    void (*send_header)(struct pt_http_session *session);
    void (*send_body)(struct pt_http_session *session, const char *buf, size_t length);
    
    void *user_data;
};



struct pt_http_handler_setting {
    void (*on_header_complete)(struct pt_http_session *session);
    void (*on_body)(struct pt_http_session *session, const char *at, size_t length);
    void (*on_message_complete)(struct pt_http_session *session);
    void (*on_sent)(struct pt_http_session *session, const char *buf, size_t length);
    void (*on_error)(struct pt_http_session *session, int errno);
    int (*should_handle)(const char *path, size_t length, void **user_data);
    QUEUE node;
}

struct pt_http_server_config {
    const char *bind_host;
    unsigned short bind_port;
    unsigned int idle_timeout;

    QUEUE handlers;
};

#endif