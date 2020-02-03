//
// Created by zzhzz on 2020/2/2.
//

#include "Process.h"

namespace pm{
    using std::cout;
    using std::cerr;
    using std::endl;
    Process::Process(int rank, Application* app) {
        this->wRank = rank;
        this->app = app;
    }

    int Process::execute() {
        cout << "child process " << getpid() << " run " << app->execname << endl;
        vector<const char*> args;
        int err;
        args.push_back(app->execname.c_str());
        err = chdir(app->wdir.c_str());
        if (err < 0){
            cerr << "child process " << getpid() << " trap in error "
                 << sys_errlist[errno] << " when chdir " << endl;

        }
        state = PROCESS_ALIVE;
        err = execvp(app->execname.c_str(), const_cast<char**>(args.data()));
        if (err < 0){
            cerr << "child process " << getpid() << " trap in error "
                    << sys_errlist[errno] << " when execvp " << endl;
            exit(0);
        }
    }
}