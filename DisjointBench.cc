#include "bmconfig.h"
#include "bmharness.h"
#include "Disjoint.h"

/// This is the tree we will manipulate in this experiment
benchmark<Disjoint>* SET;

/// This static, declared in bmconfig, needs to be defined
Config Config::CFG;

/*** Initialize the disjoint buffers */
void reparse_args() {
    if (Config::CFG.bmname == "") Config::CFG.bmname   = "DrDw-10-10-0";

    std::string str = Config::CFG.bmname;
    int pos1 = str.find_first_of('-', 0);
    int pos2 = str.find_first_of('-', pos1+1);
    int pos3 = str.find_first_of('-', pos2+1);
    int pos4 = str.size();
    int size = atoi(str.substr(pos1+1, pos2-pos1-1).c_str());
    int read = atoi(str.substr(pos2+1, pos3-pos2-1).c_str());
    int write = atoi(str.substr(pos3+1, pos4-pos3-1).c_str());
    bool shared = (Config::CFG.bmname.substr(0, 4) == "SrDw");
    SET = new benchmark<Disjoint>(new Disjoint(read, write, size, shared));
}

/// We just call to SET functions in main
int main(int argc, char** argv) {
    // parse command line
    Config::CFG.parseargs(argc, argv, "DisjointBench");
    reparse_args();

    // run the tests
    SET->launch_test();

    // print results
    Config::CFG.dump_csv();
}

