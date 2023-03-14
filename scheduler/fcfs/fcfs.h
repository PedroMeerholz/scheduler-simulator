#include "../../data-structures/task_queue/task_queue.h"

typedef struct Fcfs_ Fcfs;

Fcfs* create_fcfs(TaskQueue* taskQueue);
void run_fcfs(Fcfs* fcfs);
void destruct_fcfs(Fcfs* fcfs);