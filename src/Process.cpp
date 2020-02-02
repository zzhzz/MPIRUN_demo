//
// Created by zzhzz on 2020/2/2.
//

#include "Process.h"

namespace pm{
    using std::cout;
    using std::endl;
    Process::Process(int rank, Application* app) {
        this->wRank = rank;
        this->app = app;
    }

    int Process::execute() {
        cout << "child process " << getpid() << " run " << app->execname << endl;
        vector<const char*> args;
        args.push_back(app->execname.c_str());
        chdir("./test/");
        state = PROCESS_ALIVE;
        int rc = execvp(app->execname.c_str(), const_cast<char**>(args.data()));
        if (rc < 0){
            cout << sys_errlist[errno] << endl;
        }
    }
}