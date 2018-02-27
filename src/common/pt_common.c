#include "pt_common.h"

static uv_loop_t *pt_current_loop = (void *)0;

uv_loop_t *pt_get_current_loop() {
    return pt_current_loop; 
}

void pt_set_current_loop(uv_loop_t *loop) {
    pt_current_loop = loop;
}