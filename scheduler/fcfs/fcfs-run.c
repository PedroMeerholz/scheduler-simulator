#include "../../data-structures/task_queue/task_queue.h"
#include "../../scheduler/fcfs/fcfs.h"

int main() {
    TaskQueue* taskQueue = create_task_queue();
    Fcfs* fcfs =  create_fcfs(taskQueue);
    run_fcfs(fcfs);
}