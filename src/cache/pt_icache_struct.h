#ifndef pt_icache_struct_h
#define pt_icache_struct_h

#include "pipe/pt_idata_cache.h"

typedef struct {
    int (*set_user_data)(idata_cache *cache, int index, void *user_data);
    int (*read_data)(idata_cache *cache, int index, range rg, char *buf);
    int (*write_data)(idata_cache *cache, int index, range rg, const char *buf);
    int (*set_clips_num)(idata_cache *cache, int num);
    int (*set_filesize)(idata_cache *cache, int index, uint64_t filesize);
    uint64_t (*get_filesize)(idata_cache *cache, int index);
    int (*downloaded_range)(idata_cache *cache, int index, range *rg); // todo: change range to range_queue
    int (*can_download_more)(idata_cache *cache, int index, int *size);
    int (*get_undownload_range_queue)(idata_cache *cache, int index, range_queue *rgq);
    int (*destroy)(idata_cache *cache);
} pt_icache_interface;

typedef struct pt_idata_cache {
    pt_icache_interface *interface;
} pt_idata_cache;

#endif