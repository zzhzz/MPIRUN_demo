//
// Created by zzhzz on 2020/2/2.
//

#include "Application.h"

namespace pm{
    Application::Application(const string& execname, int n_workers) {
        this->n_workers = n_workers;
        this->execname = execname;
    }
}