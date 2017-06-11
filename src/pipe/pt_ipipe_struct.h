#ifndef pt_ipipe_struct_h
#define pt_ipipe_struct_h

#include "pt_idata_pipe.h"

typedef struct {
    int (*update_url)(pt_idata_pipe *pipe, const char *url);
    int (*destroy)(pt_idata_pipe *pipe);
} pt_ipipe_interface;

typedef struct pt_idata_pipe {
    pt_ipipe_interface *interface;
} pt_idata_pipe;

#endif