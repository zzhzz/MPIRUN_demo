//
// Created by zzhzz on 2020/2/2.
//

#include "ProcessManager.h"
#include "global.h"
#include <csignal>
#include <sys/wait.h>
#include "Application.h"

namespace pm{
    using std::cout;
    using std::cerr;
    using std::endl;
    static vector<Process*> process_templist;
    ProcessManager::ProcessManager() {
        signal(SIGCHLD, ProcessManager::child_exit_handler);
    }
    void ProcessManager::child_exit_handler(int v) {
        union wait wstat;
        pid_t pid;
        while(true){
            pid = wait3((int*)&wstat, WNOHANG, (struct rusage*)NULL);
            if(pid == 0) return;
            else if(pid == -1) return;
            else{
                for(auto* proc : process_templist){
                    if(proc->pid == pid){
                        proc->state = PROCESS_EXIT;
                    }
                }
            }
        }
    }
    int ProcessManager::Fork(Process* process) {
        pid_t pid = fork();
        if (pid < 0){
            cerr << "Process Fork Failed" << endl;
            return -1;
        } else if(pid == 0){
            // Child process
            process->state = PROCESS_UNINIT;
            int s = process->execute();
            cout << "No" << endl;
            return -1;
        } else {
            cout << "Parent process " << getpid() << " fork child process " << pid << endl;
            process->pid = pid;
            process_templist.push_back(process);
            return pid;
        }
    }
}
