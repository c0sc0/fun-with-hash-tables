/*******************************************************
 * CS 3100-01 Data Structures and Algorithms           *
 * Tyler Cosculluela                                   *
 * Professor Liu                                       *
 * December 5, 2018                                    *
 *                                                     *
 * Project 4 - Hashmaps                                *
 ******************************************************/

#include <iostream>
#include "djb2HashTable.h"
#include "sdbmHashTable.h"
#include <limits>

int displayMenu();
int chooseAlgo();

int main() {
    int choice, algorithm;
    djb2HashTable *djb2Table = new djb2HashTable();
    sdbmHashTable *sdbmTable = new sdbmHashTable();
    ofstream out;

    string lastname;
    string filename = "all.last.txt";

    djb2HashTable* djb2 = new djb2HashTable();
    sdbmHashTable* sdbm = new sdbmHashTable();

    if (!djb2->loadFile("all.last.txt")) cout << "Error: input file not found" << endl;
    if(!sdbm->loadFile("all.last.txt")) cout << "Error: input file not found" << endl;

    cout << "\n--!djb2!--" << endl;
    cout << "buckets occupied - " << djb2->getOccupied();
    cout << "\nload factor - ";
    cout << (djb2->getSize() / 88801.0) << endl << endl;

    cout << "--!sdbm!--" << endl;
    cout << "buckets occupied - " << sdbm->getOccupied();
    cout << "\nload factor - ";
    cout << (sdbm->getSize() / 88801.0) << endl << endl;

    delete djb2;
    delete sdbm;

    //begin menu

    algorithm = chooseAlgo();                                   //used as a flag for the nested switch case
    if (algorithm < 1 || algorithm > 2){                        //which made me realize that I should have
        algorithm = 1;                                          //implemented the hashing algos using inheritance
        cout << "invalid input, defaulting to djb2" << endl;    //but it's too late for that now :)
    }

    if (algorithm == 1){
        cout << "Using djb2 hashing algorithm" << endl;
        if (!djb2Table->loadFile("all.last.txt")) cout << "Error: input file not found" << endl;
    } else{
        cout << "Using sdbm hashing algorithm";
        if(!sdbmTable->loadFile("all.last.txt")) cout << "Error: input file not found" << endl;
    }

    while (choice != 5){
        choice = displayMenu(); //show menu and receive input

        switch (choice){
            case 1: //Insert

                switch (algorithm){
                    case 1:
                        cout << "Enter a last name to insert into the Hashtable" << endl;
                        getline(cin,lastname);
                        if (!djb2Table->insert(lastname)) cout << "Error: no duplicates allowed" << endl;
                        break;
                    case 2:
                        cout << "Enter a last name to insert into the Hashtable" << endl;
                        getline(cin,lastname);
                        if (!sdbmTable->insert(lastname)) cout << "Error: no duplicates allowed" << endl;
                        break;
                }
                break;
            case 2: //Remove

                switch (algorithm){
                    case 1:
                        cout << "Enter a last name to remove from the table" << endl;
                        getline(cin,lastname);
                        if (!djb2Table -> remove(lastname)) cout << "Error: key not found" << endl;
                        break;
                    case 2:
                        cout << "Enter a last name to remove from the table" << endl;
                        getline(cin,lastname);
                        if (!sdbmTable -> remove(lastname)) cout << "Error: key not found" << endl;
                        break;
                };
                break;
            case 3: //Search

                switch (algorithm){
                    case 1:
                        cout << "Enter a last name to search for" << endl;
                        getline(cin,lastname);
                        if (!djb2Table -> search(lastname)) cout << "Error: key not found" << endl;
                        break;
                    case 2:
                        cout << "Enter a last name to search for" << endl;
                        getline(cin,lastname);
                        if (!sdbmTable -> search(lastname)) cout << "Error: key not found" << endl;
                        break;
                }
                break;
            case 4: //Log

                switch (algorithm){
                    case 1:
                        cout << "Printing to djb2.txt" << endl;
                        out.open("djb2.txt");
                        djb2Table -> log(out);
                        out.close();
                        cout << "Done!" << endl << endl;
                        break;
                    case 2:
                        cout << "Printing to sdbm.txt" << endl;
                        out.open("sdbm.txt");
                        sdbmTable -> log(out);
                        out.close();
                        cout << "Done!" << endl << endl;
                        break;
                }
                break;
            case 5: //Quit
                cout << "Goodbye" << endl;
                break;
        }
    }
    return 0;
}

// Prints menu choices and receives input for the switch case
int displayMenu() {
    int input = 10;
    cout << "\n1. Insert new entry" << endl;
    cout << "2. Delete entry" << endl;
    cout << "3. Search by last name" << endl;
    cout << "4. Logfile" << endl;
    cout << "5. Quit" << endl;
    cout << "\nWhat would you like to do? ";
    cin >> input;
    cin.ignore();

    if ( cin.fail() ){                  // If the failbit is set,
        cin.clear();                    // Reset the failbit

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        input = 0;                      // Clear out the input that triggered the bit (until '\n' is reached)
        // If the input is not numeric, the while loop will run indefinitely
    }                                   // http://www.cplusplus.com/reference/istream/istream/ignore/

    cout << endl;
    return input;                       // Return the choice
}

int chooseAlgo() {
    int input = 10;
    cout << "\n1. djb2" << endl;
    cout << "2. sdbm" << endl;
    cout << "\nPlease select a hashing algorithm ";
    cin >> input;
    cin.ignore();

    if ( cin.fail() ){                  // If the failbit is set,
        cin.clear();                    // Reset the failbit

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        input = 0;                      // Clear out the input that triggered the bit (until '\n' is reached)
        // If the input is not numeric, the while loop will run indefinitely
    }                                   // http://www.cplusplus.com/reference/istream/istream/ignore/

    cout << endl;
    return input;                       // Return the choice
}