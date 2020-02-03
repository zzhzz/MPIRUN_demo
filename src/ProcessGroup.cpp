//
// Created by zzhzz on 2020/2/2.
//

#include "ProcessGroup.h"
#include "global.h"

namespace pm{
    using std::cout;
    using std::cerr;
    using std::endl;
    ProcessGroup::ProcessGroup(pm::ProcessManager *pm) {
        this->pm = pm;
    }
    void ProcessGroup::setProcessManager(ProcessManager* pm) {
        this->pm = pm;
    }
    void ProcessGroup::add_application(Application* app) {
        app_list.push_back(app);
        map_relation[app] = vector<Process*>();
    }
    void ProcessGroup::run() {
        int world_rank = 0;
        for(auto* app : app_list){
            int n_workers = app->n_workers;
            for(int i = 0; i < n_workers; i++){
                auto* process = new Process(world_rank++, app);
                process_list.push_back(process);
                map_relation[app].push_back(process);
                int pid = pm->Fork(process);
                if(pid == -1){
                    cerr << "Error happened" << endl;
                } else {
                    process_mapping[pid] = ((int)process_list.size()) - 1;
                }
            }
        }
        while(true){
            bool exit_flag = true;
            for(auto* proc : process_list){
                exit_flag &= (proc->state == PROCESS_EXIT);
            }
            if(exit_flag) break;
        }
        cout << "Congratulations, all clear." << endl;
    }
    Process* ProcessGroup::Find_pid(pid_t pid) {
        if (process_mapping.find(pid) != process_mapping.end()){
            return process_list[process_mapping[pid]];
        } else {
            cerr << "Not record pid " << pid << endl;
            return nullptr;
        }
    }
}