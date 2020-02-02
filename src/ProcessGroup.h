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
    class ProcessGroup {
    public:
        ProcessGroup(const ProcessManager* pm);
        void add_application(Application* app);
        void run();
    private:
        vector<Process*> process_list;
        vector<Application*> app_list;
        map<Application*, vector<Process*> > map_relation;
        ProcessManager* pm;
    };
}


