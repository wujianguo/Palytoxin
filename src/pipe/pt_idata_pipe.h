#ifndef pt_data_pipe_h
#define pt_data_pipe_h

typedef struct pt_idata_pipe pt_idata_pipe;

typedef struct {
    int (*on_error)(pt_idata_pipe *pipe, int err_code, void *user_data);
    int (*on_complete)(pt_idata_pipe *pipe, void *user_data);
} pt_ipipe_callback;


int pt_ipipe_destroy(pt_idata_pipe *pipe);

#endif