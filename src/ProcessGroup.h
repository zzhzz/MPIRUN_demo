//
// Created by zzhzz on 2020/2/2.
//
#pragma once
#include "global.h"
#include "Process.h"
#include "Application.h"
#include "ProcessManager.h"

namespace pm{
    using std::vector;
    using std::string;
    using std::map;
    class ProcessManager;
    class ProcessGroup {
    public:
        ProcessGroup() = default;
        explicit ProcessGroup(ProcessManager* pm);
        void setProcessManager(ProcessManager* pm);
        void add_application(Application* app);
        void run();
        Process* Find_pid(pid_t pid);
    private:
        vector<Process*> process_list;
        vector<Application*> app_list;
        map<Application*, vector<Process*> > map_relation;
        map<pid_t, int> process_mapping;
        ProcessManager* pm;
    };
}


