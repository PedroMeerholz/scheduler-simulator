#include "fcfs.h"
#include <stdlib.h>
#include <stdio.h>
#include "../../utils/generator/generator.h"

struct Fcfs_ {
    CooperativeTaskQueue* taskQueue;
};

Fcfs* create_fcfs(CooperativeTaskQueue* taskQueue) {
    Fcfs* fcfs = (Fcfs*) malloc(sizeof(Fcfs));
    if(fcfs != NULL) {
        fcfs->taskQueue = taskQueue;
    }
    return fcfs;
}
void run_fcfs(Fcfs* fcfs) {
    inserting(fcfs->taskQueue,create_task(1, 1, 5));
    printf("[FCFS] Iniciado a execução do escalonador FCFS. Total de tasks na fila: %d.\n", return_queue_quantity(fcfs->taskQueue));
    int instant = 1;
    int current_id = 2;
    while(return_queue_quantity(fcfs->taskQueue) > 0) {
        int will_add_new_task = generate();
        if(will_add_new_task == 1) {
            CooperativeTask* new_task = create_task(current_id, instant, 3);
            inserting(fcfs->taskQueue, new_task);
            printf("[FCFS] Task %d chegou na fila de execução e está agurdando o processador. Total de tasks na fila: %d.\n", return_task_id(new_task), return_queue_quantity(fcfs->taskQueue));
            current_id += 1;
        }
        CooperativeTask* task = removing(fcfs->taskQueue);
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