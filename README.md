# MPIRUN small demo

## Introduction
This project implements a simple child-process launch control. The implementation refers to the source code of `mpiexec`


## Usage
Download this project.

`git clone https://github.com/zzhzz/MPIRUN_demo.git`

make a build directory.

`cd MPIRUN_demo`

`mkdir build`

run cmake

`cmake ..`

run make

`make`

Then run

`src/small_deom 4 ./test/test_fork .` 

where `4` means 4 workers; 
`./test/test_fork` is the program run by child process;
`.` is the working directory.
