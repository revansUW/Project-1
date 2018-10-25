// Node.h
// Ryan Evans
// Project 1
// custom Node class definition

#pragma once
#ifndef _NODE_D_
#define _NODE_D_

#include <iostream>
using std::cout;
using std::endl;


class Node
{
public:
    float entry_;
    Node * next_;

public:
    // this Node contains entry and a NULL pointer
    explicit Node(float entry);

    // this Node contains entry and next
    Node(float entry, Node * next);

    // destructor
    ~Node();

private:
    Node();
    Node(const Node &);
};

#endif