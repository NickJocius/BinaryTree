/*********************************
Name: Nick Jocius
Binary Search Tree C++
File: data.h
Purpose: Create a binary search tree
object that will work with the same struct
Data and struct Node from previous assignments.
**********************************/

#ifndef BINTREE_DATA_H
#define BINTREE_DATA_H

#include <string>
using std::string;

struct Data
{
    int id;
    string information;
};

struct DataNode
{
    Data data;
    DataNode *left, *right;
};

#endif /* DATA_H */
