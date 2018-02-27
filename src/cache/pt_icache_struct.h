#ifndef pt_icache_struct_h
#define pt_icache_struct_h

#include "pipe/pt_idata_cache.h"

typedef struct {
    int (*read_data)(pt_idata_cache *cache, uint64_t pos, int length, char *buf);
    int (*write_data)(pt_idata_cache *cache, uint64_t pos, int length, const char *buf);
    int (*set_filesize)(pt_idata_cache *cache, uint64_t filesize);
    int (*get_filesize)(pt_idata_cache *cache, uint64_t *filesize);
    int (*get_downloaded_size)(pt_idata_cache *cache, uint64_t downloaded_size);
    int (*get_undowload_range)(pt_idata_cache *cache, range *rg);
    int (*destroy)(pt_idata_cache *cache);
} pt_icache_interface;

typedef struct pt_idata_cache {
    pt_icache_interface *interface;
} pt_idata_cache;

#endif