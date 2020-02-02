//
// Created by zzhzz on 2020/2/2.
//
#pragma once
#include "global.h"
#include "Application.h"

namespace pm{
    using std::string;
    enum PROCESS_STATE{
        PROCESS_UNINIT,
        PROCESS_ALIVE,
        PROCESS_EXIT
    };
    class Process {
    public:
        Process(int rank, Application* app);
        int wRank;
        Application* app;
        pid_t pid;
        PROCESS_STATE state;
        int execute();
    };
}


