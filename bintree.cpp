/*********************************
Name: Nick Jocius
Binary Search Tree C++
File: bintree.cpp
Purpose: Create a binary search tree
object that will work with the same struct
Data and struct Node from previous assignments.
**********************************/

#include "bintree.h"

BinTree::BinTree()
{
    count = 0;
    root = nullptr;
} // end constructor

BinTree::~BinTree()
{
    clear();

} // end deconstructor

bool BinTree::isEmpty()
{
    bool empty = true;
    if (root)
    {
        empty = false;
    }
    return empty;
} // end isEmpty()

int BinTree::getCount()
{
    return count;
} // end getCount()

bool BinTree::getRootData(Data *data)
{
    bool outcome = false;
    if (root)
    {
        data->id = root->data.id;
        data->information = root->data.information;
        outcome = true;
    }
    else
    {
        data->id = -1;
        data->information = "";
    }

    return outcome;

} // end getRootData()

void BinTree::displayTree()
{
    bool outcome;

    std::cout << "DISPLAY TREE" << std::endl;
    std::cout << "=======================================" << std::endl;
    outcome = isEmpty();
    if (outcome)
    {
        std::cout << "Tree is empty" << std::endl;
    }
    else
    {
        std::cout << "Tree is not empty" << std::endl;
    }
    std::cout << "Height " << getHeight() << std::endl;
    std::cout << "Node count: " << count << std::endl
              << std::endl;
    std::cout << "Pre-Order Traversal" << std::endl;
    displayPreOrder();
    std::cout << "\n"
              << std::endl;
    std::cout << "In-Order Traversal" << std::endl;
    displayInOrder();
    std::cout << "\n"
              << std::endl;
    std::cout << "Post-Order Traversal" << std::endl;
    displayPostOrder();
    std::cout << "====================================="
              << std::endl
              << std::endl;

} // end displayTree()

void BinTree::clear()
{
    clear(root);
    count = 0;
    root = nullptr;

} // end clear()

void BinTree::clear(DataNode *dnode)
{

    if (dnode == NULL)
    {
        return;
    }
    else if (dnode)
    {
        clear(dnode->left);
        clear(dnode->right);
        dnode->left = NULL;
        dnode->right = NULL;
        delete dnode;
        count--;
    }

} // end overloaded clear()

bool BinTree::addNode(int id, const string *info)
{
    bool outcome = false;
    if (id > 0 && sizeof(info) != 0)
    {
        DataNode *newNode = new DataNode;
        DataNode *temproot = root;
        newNode->data.id = id;
        newNode->data.information = *info;
        newNode->left = NULL;
        newNode->right = NULL;
        outcome = addNode(newNode, &root);
        if (outcome)
        {
            count++;
        }
    }

    return outcome;

} // end addNode()

bool BinTree::addNode(DataNode *node1, DataNode **subtree)
{
    bool outcome = false;

    if ((*subtree) == NULL)
    {
        *subtree = node1;
        outcome = true;
    }
    else if (node1->data.id < (*subtree)->data.id)
    {
        outcome = addNode(node1, &(*subtree)->left);
    }
    else if (node1->data.id > (*subtree)->data.id)
    {
        outcome = addNode(node1, &(*subtree)->right);
    }

    return outcome;

} // end overloaded addNode()

bool BinTree::removeNode(int id)
{
    bool outcome = false;
    int tempcount = count;
    DataNode *temproot = root;

    if (id > 0)
    {

        root = removeNode(id, root);

        if (count < tempcount)
        {
            outcome = true;
        }
    }

    return outcome;

} // end removeNode()

DataNode *BinTree::removeNode(int id, DataNode *temproot)
{
    if (temproot == NULL)
    {
        return temproot;
    }
    if (temproot)
    {
        if (id < temproot->data.id)
        {
            temproot->left = removeNode(id, temproot->left);
        }
        else if (id > temproot->data.id)
        {
            temproot->right = removeNode(id, temproot->right);
        }
        else
        {
            DataNode *temp = nullptr;
            if (temproot->left == NULL)
            {
                temp = temproot->right;
                delete temproot;
                temproot = temp;
                count--;
            }
            else if (temproot->right == NULL)
            {
                temp = temproot->left;
                delete temproot;
                temproot = temp;
                count--;
            }
            else
            {
                temp = minValueNode(temproot->right);
                temproot->data.id = temp->data.id;
                temproot->data.information = temp->data.information;
                temproot->right = removeNode(temp->data.id, temproot->right);
            }
        }
    }
    return temproot;

} // end overloaded removeNode()

DataNode *BinTree::minValueNode(DataNode *temproot)
{
    DataNode *current = temproot;
    while (current && current->left != NULL)
    {
        current = current->left;
    }
    return current;
} // end minValueNode()

bool BinTree::getNode(Data *data, int id)
{
    bool outcome = false;
    if (id > 0)
    {
        outcome = getNode(data, id, root);
    }

    return outcome;

} // end getNode()

bool BinTree::getNode(Data *data, int id, DataNode *temproot)
{
    bool outcome = false;
    if (temproot)
    {
        if (temproot->data.id == id)
        {
            data->id = temproot->data.id;
            data->information = temproot->data.information;
            outcome = true;
        }
        else
        {
            if (id < temproot->data.id)
            {
                outcome = getNode(data, id, temproot->left);
            }
            else if (id > temproot->data.id)
            {
                outcome = getNode(data, id, temproot->right);
            }
        }
    }

    return outcome;

} // end overloaded getNode()

bool BinTree::contains(int id)
{
    bool outcome = false;
    if (id > 0)
    {
        outcome = contains(id, root);
    }
    return outcome;
} // end contains()

bool BinTree::contains(int id, DataNode *node1)
{
    bool outcome = false;
    if (node1)
    {
        if (node1->data.id == id)
        {
            outcome = true;
        }
        else
        {
            if (id < node1->data.id)
            {
                outcome = contains(id, node1->left);
            }
            else if (id > node1->data.id)
            {
                outcome = contains(id, node1->right);
            }
        }
    }
    return outcome;

} // end overloaded contains()

int BinTree::getHeight()
{
    return getHeight(root);
} // end getHeight()

int BinTree::getHeight(DataNode *temproot)
{
    int lh = 0;
    int rh = 0;
    int outcome = 0;

    if (temproot)
    {
        lh = getHeight(temproot->left);
        rh = getHeight(temproot->right);
        outcome = std::max(lh, rh) + 1;
    }
    return outcome;
} // end overloaded getHeight()

void BinTree::displayPreOrder()
{
    displayPreOrder(root);
} // end displayPreOrder()

void BinTree::displayPreOrder(DataNode *temproot)
{
    if (temproot)
    {
        std::cout << temproot->data.id << " " << temproot->data.information << std::endl;
        if (temproot->left)
        {
            displayPreOrder(temproot->left);
        }
        if (temproot->right)
        {
            displayPreOrder(temproot->right);
        }
    }
    return;

} // end overloaded displayPreOrder()

void BinTree::displayPostOrder()
{
    displayPostOrder(root);

} // end displayPostOrder()

void BinTree::displayPostOrder(DataNode *temproot)
{
    if (temproot)
    {
        if (temproot->left)
        {
            displayPostOrder(temproot->left);
        }
        if (temproot->right)
        {
            displayPostOrder(temproot->right);
        }
        std::cout << temproot->data.id << " " << temproot->data.information << std::endl;
    }
    return;

} // end overloaded displayPostOrder()

void BinTree::displayInOrder()
{
    displayInOrder(root);

} // end displayInOrder()

void BinTree::displayInOrder(DataNode *temproot)
{
    if (temproot)
    {
        if (temproot->left)
        {
            displayInOrder(temproot->left);
        }
        std::cout << temproot->data.id << " " << temproot->data.information << std::endl;
        if (temproot->right)
        {
            displayInOrder(temproot->right);
        }
    }
    return;

} // end overloaded displayInOrder()