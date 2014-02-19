#include "bmconfig.h"
#include "bmharness.h"
#include "Counter.h"

/// This is the counter we'll manipulate in the experiment... we make it look
/// like an IntSet so that we can reuse the benchmark template
benchmark<Counter> SET;

/// This static, declared in bmconfig, needs to be defined
Config Config::CFG;

/// No reparsing needed
void reparse_args() {
    Config::CFG.bmname = "Counter";
}

/// We just call to SET functions in main
int main(int argc, char** argv) {
    // parse command line
    Config::CFG.parseargs(argc, argv, "CounterBench");
    reparse_args();

    // warm up the data structure
    SET.warmup();

    // run the tests
    SET.launch_test();

    // print results
    Config::CFG.dump_csv();
}
