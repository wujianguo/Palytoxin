#ifndef pt_task_manager_h
#define pt_task_manager_h

#include <uv.h>

typedef struct pt_task pt_task;


pt_task* pt_create_task(uv_loop_t *loop, const char *url, const char *full_path);

int pt_resume_task(uv_loop_t *loop, pt_task *task);

int pt_pause_task(uv_loop_t *loop, pt_task *task);

int pt_delete_task(uv_loop_t *loop, pt_task *task);

int pt_free_task(uv_loop_t *loop, pt_task *task);


#endif