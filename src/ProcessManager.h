//
// Created by zzhzz on 2020/2/2.
//
#pragma once
#include "Process.h"


namespace pm{
    class ProcessManager {
    public:
        ProcessManager();
        static void child_exit_handler(int v);
        int Fork(Process* process);
    };
}


