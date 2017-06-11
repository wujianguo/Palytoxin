#ifndef pt_idata_cache_h
#define pt_idata_cache_h

typedef struct pt_idata_cache pt_idata_cache;

typedef struct {
    int (*on_read)(pt_idata_cache *cache, uint64_t pos, int length, char *buf, void *user_data);
    int (*on_error)(pt_idata_cache *cache, int err_code, void *user_data);
    int (*on_complete)(pt_idata_cache *cache, void *user_data);
} pt_icache_callback;

int pt_icache_set_user_data(pt_idata_cache *cache, void *user_data);

int pt_icache_read_data(pt_idata_cache *cache, uint64_t pos, int length, char *buf);

#endif