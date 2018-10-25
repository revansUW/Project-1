// LinkedListDaily.h
// Ryan Evans
// Project 1
// prototypes functions for daily linked list

#ifndef _LINKED_LIST_D_
#define _LINKED_LIST_D_

#include <iostream>
#include <string>
using std::string;
using std::ostream;

#include "Node.h"

class LList
{
public:
    LList();
    LList(const LList & other);
    ~LList();
    bool empty() const;
    void insert(float x);
    void print(ostream & outfile) const;
    float removeFirst();
    int size() const;
    float sum() const;
    float	minReading() const;
    float	maxReading() const;
    string daySummary() const;

private:
    // a pointer to a copy of the linked structure
    static Node * clone(Node * ptr);

private:
    Node * first_;
    int size_;
    float sum_;
};

ostream & operator<<(ostream & outfile, const LList & list);
#endif