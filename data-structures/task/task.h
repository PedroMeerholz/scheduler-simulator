typedef  struct Task_ Task;

Task* create_task(int id, int priority, int instant_arrival, int size);

int update_ramaining_size(Task* task, int size_to_reduce);
void execute(Task* task);