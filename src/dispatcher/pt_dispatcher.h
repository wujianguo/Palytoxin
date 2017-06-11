#ifndef pt_dispatch_h
#define pt_dispatch_h

#include "pipe/pt_idata_cache_for_pipe.h"

typedef struct pt_dispatcher pt_dispatcher;

pt_dispatcher *pt_create_dispatcher(const char *url, pt_idata_cache *cache, struct pt_icache_interface_for_pipe *interface);

int free_dispatcher(pt_dispatcher *dispatcher);

#endif