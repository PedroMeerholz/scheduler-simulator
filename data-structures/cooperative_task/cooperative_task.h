#define QUANTUM 2

typedef  struct CooperativeTask_ CooperativeTask;

CooperativeTask* create_task(int id, int instant_arrival, int size);

int return_task_id(CooperativeTask* task);
int update_ramaining_size(CooperativeTask* task, int size_to_reduce);
void execute(CooperativeTask* task);
void destruct(CooperativeTask* task);