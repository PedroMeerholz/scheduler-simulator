#include "../cooperative_task/cooperative_task.h"
#define QUEUE_SIZE 10

typedef struct CooperativeTaskQueue_ CooperativeTaskQueue;

CooperativeTaskQueue* create_task_queue();
int inserting(CooperativeTaskQueue* task_queue, CooperativeTask *task);
CooperativeTask* removing(CooperativeTaskQueue* task_queue);
int return_queue_quantity(CooperativeTaskQueue* taskQueue);
void free_task_queue(CooperativeTaskQueue* queue);
