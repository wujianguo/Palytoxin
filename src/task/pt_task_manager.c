#include "task/pt_task_manager.h"
#include "dispatch/pt_dispatcher.h"
#include "cache/pt_icache_struct.h"

typedef struct pt_task {
    char *url;
    char *file_path;
    pt_dispatcher *dispatcher;
    pt_idata_cache *cache;

} pt_task;

static pt_task* cast_from_user_data(void *user_data) {
    return (pt_task *)user_data;
}

static void* cast_to_user_data(pt_task *task) {
    return (void *)task;
}

static int on_read(pt_idata_cache *cache, uint64_t pos, int length, char *buf, void *user_data) {
    return 0;
}

static int on_cache_complete(pt_idata_cache *cache, int err_code, void *user_data) {
    pt_task *task = cast_from_data_cache(user_data);
    printf("on_complete err_code %d, %s", err_code, task->url);
    return 0;
}

static int on_dispatcher_complete(pt_dispatcher *dispatcher, int err_code, void *user_data) {

}

pt_task* pt_create_task(uv_loop_t *loop, const char *url, const char *full_path) {
    pt_task *task = malloc(sizeof(pt_task));
    pt_icache_callback cache_callback = {on_read, on_cache_complete};
    task->cache = pt_open_file_cache(cache_callback, url);

    pt_dispatcher_callback dispatcher_callback = {on_dispatcher_complete};
    pt_icache_interface_for_pipe cache_interface = {tak->cache->set_filesize, task->cache->get_filesize, task->cache->write_data};
    task->dispatcher = pt_create_dispatcher(url, task->cache, dispatcher_callback, cache_interface, task);

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

static void print_task_description(pt_task *task) {
    double speed = 0;
    pt_dispatcher_get_download_speed(task->dispatcher, *speed);
    uint64_t downloaded_size = 0;
    task->cache->get_downloaded_size(task->cache, *downloaded_size);
    uint64_t filesize = 0;
    task-cache->get_filesize(task->cache, *filesize);
    printf("%s, %f, %llu/%llu", task->url, speed, downloaded_size, filesize);
}

static void on_timer_expire(uv_timer_t *handle) {
    pt_task *task = cast_from_user_data(handle->data);
    print_task_description(task);
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
    pt_set_current_loop(loop);
    pt_task *task = pt_create_task(loop, "http://0.s3.envato.com/h264-video-previews/80fad324-9db4-11e3-bf3d-0050569255a8/490527.mp4", "tmp/test.mp4")
    pt_resume_task(loop, task);
    uv_timer_t timer_handle;
    uv_timer_init(loop, &timer_handle);
    timer_handle.data = task;
    uv_timer_start(&timer_handle, on_timer_expire, 1000, 1000);

    uv_run(loop, UV_RUN_DEFAULT);
    return 0;
}