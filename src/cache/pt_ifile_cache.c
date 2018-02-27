#include "pt_ifile_cache.h"
#include "pt_icache_struct.h"

typedef struct pt_ifile_cache {
    pt_icache_interface *interface;
} pt_ifile_cache;


static pt_ifile_cache *cast_from_data_cache(pt_idata_cache *data_cache) {
    return (pt_ifile_cache *)data_cache;
}

static pt_idata_cache *cast_to_data_cache(pt_ifile_cache *file_cache) {
    return (pt_idata_cache *)file_cache;
}

pt_idata_cache* pt_open_file_cache(pt_icache_callback callback, const char* url) {
    pt_ifile_cache *cache = (pt_ifile_cache *)malloc(sizeof(pt_ifile_cache))
    return cast_to_data_cache(cache);
}