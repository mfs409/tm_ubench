#
# Files to compile that don't have a main() function
#
CXXFILES = Tree List

#
# Files to compile that do have a main() function
#
TARGETS = TreeBench ListBench DisjointBench CounterBench

#
# Let the user choose 32-bit or 64-bit compilation, but default to 32
#
BITS ?= 32

#
# Directory Names
#
ODIR          := ./obj_$(BITS)
output_folder := $(shell mkdir -p $(ODIR))

#
# Names of files that the compiler generates
#
EXEFILES  = $(patsubst %, $(ODIR)/%,   $(TARGETS))
OFILES    = $(patsubst %, $(ODIR)/%.o, $(CXXFILES))
EXEOFILES = $(patsubst %, $(ODIR)/%.o, $(TARGETS))
DEPS      = $(patsubst %, $(ODIR)/%.d, $(CXXFILES) $(TARGETS))

#
# Use g++ in C++11 mode, TM enabled.
#
CXX      = g++
CXXFLAGS = -MMD -O3 -fgnu-tm -ggdb -m$(BITS) -std=c++11
LDFLAGS  = -m$(BITS) -litm

#
# At Lehigh, we have a custom version of GCC with more statistics
# reporting... enable its reports here
#
CXXFLAGS += -DLU_GCC

#
# Best to be safe...
#
.DEFAULT_GOAL = all
.PRECIOUS: $(OFILES) $(EXEOFILES)
.PHONY:    all clean

#
# Goal is to build all executables
#
all: $(EXEFILES)

#
# Rules for building object files
#
$(ODIR)/%.o: %.cc
	@echo "[CXX] $< --> $@"
	@$(CXX) $< -o $@ -c $(CXXFLAGS)

#
# Rules for building executable files... we'll be lazy and link all of the
# OFILES, even if we don't need them...
#
$(ODIR)/%: $(ODIR)/%.o $(OFILES)
	@echo "[LD] $< --> $@"
	@$(CXX) $^ -o $@ $(LDFLAGS) 

#
# clean by clobbering the build folder
#
clean:
	@echo Cleaning up...
	@rm -rf $(ODIR)

#
# Include dependencies
#
-include $(DEPS)
