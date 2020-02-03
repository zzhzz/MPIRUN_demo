#include "global.h"
#include "Process.h"
#include "ProcessManager.h"
#include "ProcessGroup.h"
#include "Application.h"
using namespace std;
using pm::ProcessManager;
using pm::ProcessGroup;
using pm::Process;
using pm::Application;

int main(int argv, char** argc) {
    if(argv >= 4){
        int np = atoi(argc[1]);
        const char* app_name = argc[2];
        const char* wdir = argc[3];
        cout << "n_workers=" << np << endl;
        auto* app = new Application(string(app_name), np, string(wdir));
        auto* pm = ProcessManager::getInstance();
        auto* pGroup = new ProcessGroup(pm);
        ProcessManager::setProcessGroup(pGroup);
        pGroup->add_application(app);
        pGroup->run();
    } else if(argv == 1){
        cerr << "No options" << endl;
    }
    return 0;
}