#include "cooperative_task.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct CooperativeTask_ {
    int id;
    int arrival_instant;
    int size;
    int remaining_size;
    int finish_instant;
} CooperativeTask;

CooperativeTask* create_task(int id, int instant_arrival, int size) {
    CooperativeTask* task = (CooperativeTask*) malloc(sizeof(CooperativeTask));
    if(task != NULL) {
        task->id = id;
        task->arrival_instant = instant_arrival;
        task->size = size;
        task->remaining_size = task->size;
    } else {
        exit(1);
    }
    return task;
}

int return_task_id(CooperativeTask* task) {
    return task->id;
}

int update_ramaining_size(CooperativeTask* task, int size_to_reduce) {
    if(task == NULL || task->remaining_size == 0) {
        return 0;
    } else {
        task->remaining_size -= size_to_reduce;
        return 1;
    }
}

void execute(CooperativeTask* task) {
    printf("[TASK] Executando Task %d\n", task->id);
    sleep(task->size);
    printf("[TASK] Task %d finalizada\n", task->id);
}

void destruct(CooperativeTask* task) {
    free(task);
}