/*********************************
Name: Nick Jocius
Binary Search Tree C++
File: functions.cpp
Purpose: Create a binary search tree
object that will work with the same struct
Data and struct Node from previous assignments.
**********************************/
#include "functions.h"

// do not modify this function
int random_range(int min, int max)
{
    //returns a random number between min and max inclusive
    return (rand() % (max - min + 1)) + min;
}

// you may add more functions here if you need them