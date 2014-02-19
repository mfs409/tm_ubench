// -*-c++-*-

/**
 *  Copyright (C) 2011
 *  University of Rochester Department of Computer Science
 *    and
 *  Lehigh University Department of Computer Science and Engineering
 *
 * License: Modified BSD
 *          Please see the file LICENSE.RSTM for licensing information
 */

#pragma once

#include <cstdlib>
#include <cstdio>

class Counter
{
    int counter;

    /// a simple increment function
    int increment() {
        return ++counter;
    }

  public:

    /// Just zero the counter
    Counter() : counter(0) { }

    /// OK, this is gross, but we can just implement the three intset methods
    /// as calls to increment.
    bool lookup(int val) {
        return increment() == 0;
    }

    /// OK, this is gross, but we can just implement the three intset methods
    /// as calls to increment.
    bool insert(int val) {
        return increment() == 0;
    }

    /// OK, this is gross, but we can just implement the three intset methods
    /// as calls to increment.
    bool remove(int val) {
        return increment() == 0;
    }

    /// isSane will just print the counter value, so we can eyeball it
    bool isSane() {
        printf("Counter value = %d\n", counter);
        return true;
    }
};
