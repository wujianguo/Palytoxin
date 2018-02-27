#ifndef pt_idata_cache_for_pipe_h
#define pt_idata_cache_for_pipe_h

#include <_types/_uint64_t.h>

typedef struct pt_idata_cache pt_idata_cache;

struct pt_icache_interface_for_pipe {
    int (*set_filesize)(pt_idata_cache *cache, uint64_t filesize);
    int (*get_filesize)(pt_idata_cache *cache, uint64_t *filesize);
    int (*write_data)(pt_idata_cache *cache, uint64_t pos, int length, const char *buf);
} pt_icache_interface_for_pipe;

#endif