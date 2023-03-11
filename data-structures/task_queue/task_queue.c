#include <stdlib.h>
#include <stdio.h>
#include "task_queue.h"
#include "../task/task.h"

struct TaskQueue_ {
    int quantity;
    Task* task[QUEUE_SIZE];
};
TaskQueue* create_task_queue() {
    TaskQueue* taskQueue = (TaskQueue*) malloc(sizeof(TaskQueue));
    if(taskQueue != NULL) {
        taskQueue->quantity = 0;
    }
    return taskQueue;
}
int inserting(TaskQueue* taskQueue, Task *task) {
    if(taskQueue->quantity == QUEUE_SIZE) {
        return 0;
    } else {
        taskQueue->task[taskQueue->quantity++] = task;
        return 1;
    }
}
Task* removing(TaskQueue* taskQueue) {
    if(taskQueue == 0) {
        return 0;
    } else {
        Task* task = taskQueue->task[0];
        taskQueue->quantity--;
        for(int i = 0; i < taskQueue->quantity; i++) {
            taskQueue->task[i] = taskQueue->task[i+1];
        }
        return task;
    }
}
int return_queue_quantity(TaskQueue* taskQueue) {
    return taskQueue->quantity;
}
void free_task_queue(TaskQueue* queue) {
    free(queue);
}