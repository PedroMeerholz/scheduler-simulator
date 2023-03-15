#include "../../data-structures/cooperative_task_queue/cooperative_task_queue.h"

typedef struct Fcfs_ Fcfs;

Fcfs* create_fcfs(CooperativeTaskQueue* taskQueue);
void run_fcfs(Fcfs* fcfs);
void destruct_fcfs(Fcfs* fcfs);