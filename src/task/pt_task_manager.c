#include "task/pt_task_manager.h"

typedef struct pt_task {

} pt_task;

pt_task* pt_create_task(uv_loop_t *loop, const char *url, const char *full_path) {
    return 0;
}

int pt_resume_task(uv_loop_t *loop, pt_task *task) {
    return 0;
}

int pt_pause_task(uv_loop_t *loop, pt_task *task) {
    return 0;
}

int pt_delete_task(uv_loop_t *loop, pt_task *task) {
    return 0;
}

int pt_free_task(uv_loop_t *loop, pt_task *task) {
    return 0;
}

static void on_timer_expire(uv_timer_t *handle) {

}

// gcc src/task/pt_task_manager.c -Isrc -I/usr/local/include
int main(int argc, char *argv[]) {
    uv_loop_t *loop = uv_default_loop();
    pt_task *task = pt_create_task(loop, "http://0.s3.envato.com/h264-video-previews/80fad324-9db4-11e3-bf3d-0050569255a8/490527.mp4", "tmp/test.mp4")

    uv_timer_t timer_handle;
    uv_timer_init(loop, &timer_handle);
    uv_timer_start(&timer_handle, on_timer_expire, 1000, 1000);

    uv_run(loop, UV_RUN_DEFAULT);
    return 0;
}