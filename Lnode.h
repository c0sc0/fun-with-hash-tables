//The Singly Linked List node header file Lnode.h provided by Dr. Meilin Liu, and you can modify it if you want.

/*******************************************************
 * CS 3100-01 Data Structures and Algorithms           *
 * Tyler Cosculluela                                   *
 * Professor Liu                                       *
 * December 5, 2018                                    *
 *                                                     *
 * Project 4 - Hashmaps                                *
 ******************************************************/


#ifndef _Lnode_
#define  _Lnode_

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;


class Lnode
{
	public:
		string key;
		Lnode *next;

		Lnode(string newKey = "") {
		    key = newKey;
		    next = NULL;
		}
};


#endif