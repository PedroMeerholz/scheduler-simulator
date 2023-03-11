#include "task.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct Task_ {
    int id;
    int priority;
    int arrival_instant;
    int size;
    int remaining_size;
    int finish_instant;
} Task;

Task* create_task(int id, int priority, int instant_arrival, int size) {
    Task* task = (Task*) malloc(sizeof(Task));
    if(task != NULL) {
        task->id = id;
        task->priority = priority;
        task->arrival_instant = instant_arrival;
        task->size = size;
        task->remaining_size = task->size;
    } else {
        exit(1);
    }
    return task;
}

int update_ramaining_size(Task* task, int size_to_reduce) {
    if(task == NULL || task->remaining_size == 0) {
        return 0;
    } else {
        task->remaining_size -= size_to_reduce;
        return 1;
    }
}

void execute(Task* task) {
    printf("[TASK] Executando Task %d\n", task->id);
    sleep(task->size);
    printf("[TASK] Task %d finalizada\n", task->id);
    free(task);
}