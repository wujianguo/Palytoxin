#include "task/pt_task_manager.h"

typedef struct pt_task {
    enum pt_task_state state;
    char url;
    char file_path;
} pt_task;

pt_task* pt_create_task(uv_loop_t *loop, const char *url, const char *full_path) {
    pt_task *task = malloc(sizeof(pt_task));
    return task;
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
/*
NSMutableArray *sampleList = [[NSMutableArray alloc] init];

    [sampleList addObject:@[@"bipbop basic master playlist",
                            @"http://devimages.apple.com.edgekey.net/streaming/examples/bipbop_4x3/bipbop_4x3_variant.m3u8"]];
    [sampleList addObject:@[@"bipbop basic 400x300 @ 232 kbps",
                            @"http://devimages.apple.com.edgekey.net/streaming/examples/bipbop_4x3/gear1/prog_index.m3u8"]];
    [sampleList addObject:@[@"bipbop basic 640x480 @ 650 kbps",
                            @"http://devimages.apple.com.edgekey.net/streaming/examples/bipbop_4x3/gear2/prog_index.m3u8"]];
    [sampleList addObject:@[@"bipbop basic 640x480 @ 1 Mbps",
                            @"http://devimages.apple.com.edgekey.net/streaming/examples/bipbop_4x3/gear3/prog_index.m3u8"]];
    [sampleList addObject:@[@"bipbop basic 960x720 @ 2 Mbps",
                            @"http://devimages.apple.com.edgekey.net/streaming/examples/bipbop_4x3/gear4/prog_index.m3u8"]];
    [sampleList addObject:@[@"bipbop basic 22.050Hz stereo @ 40 kbps",
                            @"http://devimages.apple.com.edgekey.net/streaming/examples/bipbop_4x3/gear0/prog_index.m3u8"]];

    [sampleList addObject:@[@"bipbop advanced master playlist",
                            @"http://devimages.apple.com.edgekey.net/streaming/examples/bipbop_16x9/bipbop_16x9_variant.m3u8"]];
    [sampleList addObject:@[@"bipbop advanced 416x234 @ 265 kbps",
                            @"http://devimages.apple.com.edgekey.net/streaming/examples/bipbop_16x9/gear1/prog_index.m3u8"]];
    [sampleList addObject:@[@"bipbop advanced 640x360 @ 580 kbps",
                            @"http://devimages.apple.com.edgekey.net/streaming/examples/bipbop_16x9/gear2/prog_index.m3u8"]];
    [sampleList addObject:@[@"bipbop advanced 960x540 @ 910 kbps",
                            @"http://devimages.apple.com.edgekey.net/streaming/examples/bipbop_16x9/gear3/prog_index.m3u8"]];
    [sampleList addObject:@[@"bipbop advanced 1280x720 @ 1 Mbps",
                            @"http://devimages.apple.com.edgekey.net/streaming/examples/bipbop_16x9/gear4/prog_index.m3u8"]];
    [sampleList addObject:@[@"bipbop advanced 1920x1080 @ 2 Mbps",
                            @"http://devimages.apple.com.edgekey.net/streaming/examples/bipbop_16x9/gear5/prog_index.m3u8"]];
    [sampleList addObject:@[@"bipbop advanced 22.050Hz stereo @ 40 kbps",
                            @"http://devimages.apple.com.edgekey.net/streaming/examples/bipbop_16x9/gear0/prog_index.m3u8"]];
*/

int main(int argc, char *argv[]) {
    uv_loop_t *loop = uv_default_loop();
    pt_task *task = pt_create_task(loop, "http://0.s3.envato.com/h264-video-previews/80fad324-9db4-11e3-bf3d-0050569255a8/490527.mp4", "tmp/test.mp4")
    pt_resume_task(loop, task);
    uv_timer_t timer_handle;
    uv_timer_init(loop, &timer_handle);
    uv_timer_start(&timer_handle, on_timer_expire, 1000, 1000);

    uv_run(loop, UV_RUN_DEFAULT);
    return 0;
}