#include "../task/task.h"
#define QUEUE_SIZE 10

typedef struct TaskQueue_ TaskQueue;

TaskQueue* create_task_queue();
int inserting(TaskQueue* task_queue, Task *task);
Task* removing(TaskQueue* task_queue);
int return_queue_quantity(TaskQueue* taskQueue);
void free_task_queue(TaskQueue* queue);
