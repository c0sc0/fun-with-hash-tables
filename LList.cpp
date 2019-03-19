/*******************************************************
 * CS 3100-01 Data Structures and Algorithms           *
 * Tyler Cosculluela                                   *
 * Professor Liu                                       *
 * December 5, 2018                                    *
 *                                                     *
 * Project 4 - Hashmaps                                *
 ******************************************************/

#include "LList.h"
#include <sstream> //used to cast string to int

using namespace std;

// Initialize a new LIST so that it is empty.
LList::LList() {
    head = NULL;
    num = 0;
}

// The copy constructor (performs initialization).
LList::LList(const LList &s) {
    num = s.size();
    Lnode* temp = head;
    Lnode* other = s.head;
    while (other ->next != NULL){
        temp->key = other->key;
        temp->next = other->next;
    }
    
}

// Perform actions needed when stack goes out of scope.
LList::~LList() {
    clear();
    head = NULL;
    num = 0;
}



// Returns true if the list is empty, otherwise returns false.
bool LList::is_empty() const {
    return num <= 0;
}

// Returns the number of elements in the list.
int LList::size() const {
    return num;
}

//Print all the elements in the stack onto the ostream
void LList::print(ostream& outs) const {
    if (&outs == &cout) {                                   //printing to console
        Lnode *temp = head;
        while (temp != NULL) {
            outs << temp->key << endl;
            temp = temp->next;
        }
        outs << "----------" << endl;
    } else {                                                //else printing to file and no extra formatting is needed
        Lnode *temp = head;
        if (temp == NULL) outs << "!!!EMPTY!!!" << endl;
        while (temp != NULL) {
            outs << temp->key << endl;
            temp = temp->next;
        }
    }
}

//Insert key to end of list, or to the head if the list is empty
void LList::insertEnd(string newKey) {
    Lnode* iNode = new Lnode(newKey);
    Lnode *last = head;
    if (head == NULL){
        head = iNode;
        num = 1;
        return;
    }
    while (last->next != NULL){
        last = last->next;
    }
    last->next = iNode;
    ++num;
    return;
}

//Delete every node one by one, called by destructor
void LList::clear() {
    Lnode* temp;
    while (head != NULL){
        temp = head;
        head = head->next;
        delete temp;
    }
}

//Iterates through list until sKey is found, then removes it and shifts the list accordingly
void LList::removeNode(string sKey) {
    Lnode *temp, *prev;
    temp = head;

    //removing head
    if (temp != NULL && temp->key == sKey){
        head = temp->next;
        delete temp;
        return;
    }

    while (temp != NULL && temp->key != sKey){
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;   //key not found

    //shift the list
    prev->next = temp->next;
    delete temp;
}

//Iterates through list until sKey is found and returns true, or false if not found
bool LList::locate(string sKey) {
    Lnode* bucket = head;

    while (bucket != NULL){
        if (bucket->key == sKey) return true;
        bucket = bucket -> next;
    }
    return false;
}


//Nonmember << operator, calls print() with the provided ostream
ostream &operator<<(ostream &outs, const LList &stack) {
    stack.print(outs);
    return outs;
}
