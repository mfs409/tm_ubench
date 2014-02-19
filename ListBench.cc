#include "bmconfig.h"
#include "bmharness.h"
#include "List.h"

/// This is the list we will manipulate in this experiment
benchmark<List> SET;

/// This static, declared in bmconfig, needs to be defined
Config Config::CFG;

/// A helper function to update the configuration based on some custom names
void reparse_args()
{
    if      (Config::CFG.bmname == "")     Config::CFG.bmname   = "List";
    else if (Config::CFG.bmname == "List") Config::CFG.elements = 256;
}

/// We just call to SET functions in main
int main(int argc, char** argv) {
    // parse command line
    Config::CFG.parseargs(argc, argv, "ListBench");
    reparse_args();

    // warm up the data structure
    SET.warmup();

    // run the tests
    SET.launch_test();

    // print results
    Config::CFG.dump_csv();
}
