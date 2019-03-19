//The Singly Linked List based Stack header file, SSLStack.h, provided by Dr. Meilin Liu, and you can you can modify it if you want.

/*******************************************************
 * CS 3100-01 Data Structures and Algorithms           *
 * Tyler Cosculluela                                   *
 * Professor Liu                                       *
 * December 5, 2018                                    *
 *                                                     *
 * Project 4 - Hashmaps                                *
 ******************************************************/

#ifndef _LList_
#define _LList_

#include "Lnode.h"
#include <fstream>
#include <iostream>

using namespace std;

class LList

// This implementation of a Singly Linked List based Stack.
{
public:

LList ();
// Initialize a new stack so that it is empty. 
LList (const LList &s);
// The copy constructor (performs initialization).

~LList ();
// Perform actions needed when stack goes out of scope.


void insertEnd(string newKey);
// Inserts key to the end of the list, or at the head if empty

void removeNode(string sKey);
// Iterates through list until key is found, then removes key and shifts list

bool locate(string sKey);
// Returns true if key exists in list


//clear the list
void clear();

// = Check boundary conditions for list operations.
bool is_empty() const;
// Returns true if the list is empty, otherwise returns false.

int size() const;
// Returns the number of elements in the list.

void print(ostream& outs) const;
// Print all the elements in the stack onto the ostream


private:
Lnode *head;
// The top of the Linked List.
int num; 
// the number of elements in the list.

};

ostream& operator << (ostream& outs, const LList &stack);
// Nonmember << operator, calls print() with the provided ostream

#endif