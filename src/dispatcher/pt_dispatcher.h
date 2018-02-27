#ifndef pt_dispatch_h
#define pt_dispatch_h

#include "pipe/pt_idata_cache_for_pipe.h"

typedef struct pt_dispatcher pt_dispatcher;

typedef struct pt_dispatcher_callback {
    int (*on_complete)(pt_dispatcher *dispatcher, int err_code, void *user_data);
} pt_dispatcher_callback;

pt_dispatcher *pt_create_dispatcher(const char *url, pt_idata_cache *cache, pt_dispatcher_callback callback, pt_idata_cache_for_pipe cache_interface, void *user_data);

int pt_dispatcher_get_download_speed(pt_dispatcher *dispatcher, double *speed);

int pt_free_dispatcher(pt_dispatcher *dispatcher);

#endif