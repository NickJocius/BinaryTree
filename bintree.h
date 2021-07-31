/*********************************
Name: Nick Jocius
Binary Search Tree C++
File: bintree.h
Purpose: Create a binary search tree
object that will work with the same struct
Data and struct Node from previous assignments.
**********************************/

#ifndef BINTREE_BINTREE_H
#define BINTREE_BINTREE_H

#include "data.h"
#include <iostream>
#include <algorithm>

class BinTree
{

public:
    BinTree(/* args */);
    ~BinTree();
    bool isEmpty();
    int getCount();
    bool getRootData(Data *);
    void displayTree();
    void clear();
    bool addNode(int, const string *);
    bool removeNode(int);
    bool getNode(Data *, int);
    bool contains(int);
    int getHeight();
    void displayPreOrder();
    void displayPostOrder();
    void displayInOrder();

protected:
    int count;
    DataNode *root;
    /* private methods */
    void clear(DataNode *);
    bool addNode(DataNode *, DataNode **);
    DataNode *removeNode(int, DataNode *);
    bool getNode(Data *, int, DataNode *);
    bool contains(int, DataNode *);
    int getHeight(DataNode *);
    void displayPreOrder(DataNode *);
    void displayPostOrder(DataNode *);
    void displayInOrder(DataNode *);
    DataNode *minValueNode(DataNode *);
};

#endif /* BINTREE_BINTREE_H */