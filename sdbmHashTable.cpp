/*******************************************************
 * CS 3100-01 Data Structures and Algorithms           *
 * Tyler Cosculluela                                   *
 * Professor Liu                                       *
 * December 5, 2018                                    *
 *                                                     *
 * Project 4 - Hashmaps                                *
 ******************************************************/

#include "sdbmHashTable.h"

sdbmHashTable::sdbmHashTable() {
    for (int i=0; i< 88801; ++i){
        table[i] = new LList(); // "Perfectly balanced,
    }
}

sdbmHashTable::~sdbmHashTable() {
    for (int i = 0; i < 88801; ++i) {
        delete table[i];        // as all things should be" -Thanos
    }
}

//www.cse.yorku.ca/%7eoz/hash.html
unsigned long sdbmHashTable::hash(const char *str) {  // Modified to work with c_strings
    unsigned long hash = 0;
    int c;

    while (c = *str++)
        hash = c + (hash << 6) + (hash << 16) - hash;

    return hash % 88801;
}

//Returns true if the search key is located in the table
bool sdbmHashTable::search(string sKey) {
    unsigned long hashCode = hash(sKey.c_str());
    LList* bucket = table[hashCode];
    if (bucket->locate(sKey)) {
        cout << sKey << " found in bucket #" << hashCode << endl;
        return true;
    } else return false;
}

//Returns true if the insertion key is unique, and adds the key to the table
bool sdbmHashTable::insert(string iKey) {
    unsigned long hashCode = hash(iKey.c_str()); //.c_str() converts to a const char array,
    LList* bucket = table[hashCode];
    //Don't insert the key if it's already in the table
    if (!search(iKey)){
        bucket->insertEnd(iKey);
        cout << "Inserted " << iKey << " into bucket #" << hashCode << endl;
        return true;
    } else return false;
}

//Returns true if the key is found, and removes it from the table
bool sdbmHashTable::remove(string sKey) {
    unsigned long hashCode = hash(sKey.c_str());
    if (!search(sKey)) return false;    //Can't remove a key if it doesn't exist
    LList *bucket = table[hashCode];
    bucket->removeNode(sKey);
    cout << "Removed " << sKey << " from bucket #" << hashCode << endl;
    return true;
}

//Print the table to console
void sdbmHashTable::print() {
    for (int i =0; i<8; ++i) {
        cout << "Printing bucket - " << i << endl;
        cout << *table[i];
    }
    cout << "\n--There are " << num << " items in the table" << endl;

}

//Loads the table from an input file
bool sdbmHashTable::loadFile(const string &filename) {

    ifstream ins(filename.c_str());
    if (!ins){
        cout << "Error: unable to open file" << endl;
        return false;
    }
    string last;
    int tempNum;

    getline(ins, last);

    insert(last);
    num = 1;
    while (getline(ins, last)){

        insert(last);
        ++num;
    }
    ins.close();
    return true;
}

//Returns the number of occupied buckets
int sdbmHashTable::getOccupied() {
    int count = 0;
    for (int i = 0; i < 88801; ++i) {
        if (!table[i]->is_empty()) ++count;
    }
    return count;
}

//Print the table to a text file
void sdbmHashTable::log(ostream &outs) {
    for (int i =0; i<88801; ++i) {
        outs << "Bucket - " << i << endl;
        outs << *table[i];
    }
}
