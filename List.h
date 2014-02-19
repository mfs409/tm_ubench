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
#include <cstdint>

// We construct other data structures from the List. In order to do their
// sanity checks correctly, we might need to pass in a validation function of
// this type
typedef bool (*verifier)(uint32_t, uint32_t);

// Set of LLNodes represented as a linked list in sorted order
class List
{

  // Node in a List
  struct Node
  {
      int m_val;
      Node* m_next;

      // ctors
      Node(int val = -1) : m_val(val), m_next() { }

      Node(int val, Node* next) : m_val(val), m_next(next) { }
  };

    Node* sentinel;

  public:

    List();

    // true iff val is in the data structure
    __attribute__((transaction_safe))
    bool lookup(int val) const;

    // standard IntSet methods
    __attribute__((transaction_safe))
    bool insert(int val);

    // remove a node if its value = val
    __attribute__((transaction_safe))
    bool remove(int val);

    // make sure the list is in sorted order
    bool isSane() const;

    // make sure the list is in sorted order and for each node x,
    // v(x, verifier_param) is true
    bool extendedSanityCheck(verifier v, uint32_t param) const;

    // find max and min
    __attribute__((transaction_safe))
    int findmax() const;

    __attribute__((transaction_safe))
    int findmin() const;

    // overwrite all elements up to val
    __attribute__((transaction_safe))
    void overwrite(int val);
};
