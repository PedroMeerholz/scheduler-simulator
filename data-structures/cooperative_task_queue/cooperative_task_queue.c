#include <stdlib.h>
#include <stdio.h>
#include "cooperative_task_queue.h"
#include "../cooperative_task/cooperative_task.h"

struct CooperativeTaskQueue_ {
    int quantity;
    CooperativeTask* task[QUEUE_SIZE];
};
CooperativeTaskQueue* create_task_queue() {
    CooperativeTaskQueue* taskQueue = (CooperativeTaskQueue*) malloc(sizeof(CooperativeTaskQueue));
    if(taskQueue != NULL) {
        taskQueue->quantity = 0;
    }
    return taskQueue;
}
int inserting(CooperativeTaskQueue* taskQueue, CooperativeTask *task) {
    if(taskQueue->quantity == QUEUE_SIZE) {
        return 0;
    } else {
        taskQueue->task[taskQueue->quantity++] = task;
        return 1;
    }
}
CooperativeTask* removing(CooperativeTaskQueue* taskQueue) {
    if(taskQueue == 0) {
        return 0;
    } else {
        CooperativeTask* task = taskQueue->task[0];
        taskQueue->quantity--;
        for(int i = 0; i < taskQueue->quantity; i++) {
            taskQueue->task[i] = taskQueue->task[i+1];
        }
        return task;
    }
}
int return_queue_quantity(CooperativeTaskQueue* taskQueue) {
    return taskQueue->quantity;
}
void free_task_queue(CooperativeTaskQueue* queue) {
    free(queue);
}