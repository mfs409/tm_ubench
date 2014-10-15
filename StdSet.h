#pragma once

#include <set>

class StdSet
{
    std::set<int> s;

  public:

    StdSet() { }

    // standard IntSet methods

    __attribute__((transaction_safe))
    bool lookup(int val) const
    {
        return s.find(val) != s.end();
    }

    __attribute__((transaction_safe))
    bool insert(int val)
    {
        return s.insert(val).second;
    }

    __attribute__((transaction_safe))
    bool remove(int val)
    {
        return s.erase(val) == 1;
    }

    void modify(int val)
    {
        if (s.find(val) != s.end())
            s.erase(val);
        else
            s.insert(val);
    }

    bool isSane() const
    {
        return true;
    }
};
