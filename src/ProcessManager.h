//
// Created by zzhzz on 2020/2/2.
//
#pragma once
#include "Process.h"
#include "ProcessGroup.h"

namespace pm{
    class ProcessGroup;
    class ProcessManager {
    public:
        static ProcessManager* getInstance() {
            static ProcessManager pm;
            return &pm;
        }
        static void child_exit_handler(int v);
        static void setProcessGroup(ProcessGroup* pGroup);
        static int Fork(Process* process);
    private:
        ProcessManager();
    };
}


