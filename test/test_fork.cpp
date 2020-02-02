//
// Created by zzhzz on 2020/2/2.
//

#include <iostream>
#include <unistd.h>
using namespace std;

int main(int argv, char** argc) {
    cout << "Succeess Child Process: " << getpid() << endl;
}
