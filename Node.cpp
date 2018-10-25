// Node.cpp
// Ryan Evans
// Project 1
// function definitions for custom Node class

#include "Node.h"

// constructor with a NULL pointer
Node::Node(float entry) : entry_(entry), next_(NULL)
{}

// constructor with a next_ pointer
Node::Node(float entry, Node * next) : entry_(entry), next_(next)
{}

Node::~Node()
{}
