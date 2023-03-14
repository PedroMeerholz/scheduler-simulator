#include "fcfs.h"
#include <stdlib.h>
#include <stdio.h>
#include "../../utils/generator/generator.h"

struct Fcfs_ {
    TaskQueue* taskQueue;
};

Fcfs* create_fcfs(TaskQueue* taskQueue) {
    Fcfs* fcfs = (Fcfs*) malloc(sizeof(Fcfs));
    if(fcfs != NULL) {
        fcfs->taskQueue = taskQueue;
    }
    return fcfs;
}
void run_fcfs(Fcfs* fcfs) {
    inserting(fcfs->taskQueue,create_task(1, 1, 1, 5));
    printf("[FCFS] Nova task adicionada na fila de execução. Total de tasks na fila: %d.\n", return_queue_quantity(fcfs->taskQueue));
    int instant = 1;
    int current_id = 2;
    while(return_queue_quantity(fcfs->taskQueue) > 0) {
        int will_add_new_task = generate();
        if(will_add_new_task == 1) {
            Task* new_task = create_task(current_id, 1, instant, 3);
            inserting(fcfs->taskQueue, new_task);
            printf("[FCFS] Nova task adicionada na fila de execução. Total de tasks na fila: %d.\n", return_queue_quantity(fcfs->taskQueue));
            current_id += 1;
        }
        Task* task = removing(fcfs->taskQueue);
        execute(task);
        destruct(task);
        printf("[FCFS] Tasks em fila: %d\n", return_queue_quantity(fcfs->taskQueue));
    }
    printf("[FCFS] O escalonador FCFS terminou de executar todas as tasks em fila.\n");
    destruct_fcfs(fcfs);
    exit(0);
}

void destruct_fcfs(Fcfs* fcfs) {
    free(fcfs->taskQueue);
    free(fcfs);
}