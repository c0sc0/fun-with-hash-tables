/*******************************************************
 * CS 3100-01 Data Structures and Algorithms           *
 * Tyler Cosculluela                                   *
 * Professor Liu                                       *
 * December 5, 2018                                    *
 *                                                     *
 * Project 4 - Hashmaps                                *
 ******************************************************/

#ifndef DJB2_H
#define DJB2_H

#include "LList.h"

class djb2HashTable {
private:
    LList* table[88801];
    int num;

public:
    djb2HashTable();
    ~djb2HashTable();

//djb2 hashing algorithm
    unsigned long hash(const char* str);

// Returns true if key is found
    bool search(string sKey);
// Returns true if no duplicates, inserts key
    bool insert(string sKey);
// Returns true if key exists in table, removes key
    bool remove(string sKey);

    int getSize(){return num;}

// Return the number of occupied buckets
    int getOccupied();

// Print the table to console
    void print();
// Save the table to txt file
    void log(ostream& outs);
// Load the table from input file
    bool loadFile(const string &filename);

};


#endif //DJB2_H
