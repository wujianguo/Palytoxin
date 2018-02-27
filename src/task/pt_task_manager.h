#ifndef pt_task_manager_h
#define pt_task_manager_h

typedef struct pt_task pt_task;

enum pt_task_state {
    pt_task_state_idle,
    pt_task_state_waiting,
    pt_task_state_running,
    pt_task_state_paused,
    pt_task_state_success,
    pt_task_state_failure
};

pt_task* pt_take_task_by(const char *url, const char *full_path);

int pt_release_task_by(const char *url);


int pt_resume_task(pt_task *task);

int pt_pause_task(pt_task *task);

int pt_delete_task(pt_task *task);

#endif