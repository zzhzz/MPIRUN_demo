//
// Created by zzhzz on 2020/2/2.
//
#pragma once
#include "global.h"

namespace pm{
    using string = std::string;
    using std::vector;
    class Application {
    public:
        Application(const string& execname, int n_workers);
        int n_workers;
        string execname;
    };
}



