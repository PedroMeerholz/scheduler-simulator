#include "../../data-structures/cooperative_task_queue/cooperative_task_queue.h"
#include "../../scheduler/fcfs/fcfs.h"

int main() {
    CooperativeTaskQueue* taskQueue = create_task_queue();
    Fcfs* fcfs =  create_fcfs(taskQueue);
    run_fcfs(fcfs);
}