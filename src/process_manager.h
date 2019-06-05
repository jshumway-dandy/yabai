#ifndef PROCESS_MANAGER_H
#define PROCESS_MANAGER_H

struct process_manager
{
    struct table process;
    EventTargetRef target;
    EventHandlerUPP handler;
    EventTypeSpec type[3];
    EventHandlerRef ref;
    pid_t front_pid;
};

struct process *process_manager_find_process(struct process_manager *pm, ProcessSerialNumber *psn);
void process_manager_remove_process(struct process_manager *pm, ProcessSerialNumber *psn);
void process_manager_add_process(struct process_manager *pm, struct process *process);
void process_manager_init(struct process_manager *pm);
bool process_manager_begin(struct process_manager *pm);
bool process_manager_end(struct process_manager *pm);

#endif
