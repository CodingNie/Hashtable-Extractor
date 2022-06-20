// Name: Ning Nie
// USC NetID: nnie
// CS 455 PA5
// Spring 2022

// pa5list.cpp
// a program to test the linked list code necessary for a hash table chain

// You are not required to submit this program for pa5.

// We gave you this starter file for it so you don't have to figure
// out the #include stuff.  The code that's being tested will be in
// listFuncs.cpp, which uses the header file listFuncs.h

// The pa5 Makefile includes a rule that compiles these two modules
// into one executable.

#include <iostream>
#include <string>
#include <cassert>

using namespace std;

#include "listFuncs.h"
#include "listFuncs.cpp"


int main() {
    ListType list = NULL;
    //check the initial size
    cout << "the original size is : " << getSize(list) << endl;
    // add some elements and print
    addNode(list, "Wang", 88);
    addNode(list, "Sarah", 92);
    addNode(list, "Tommy", 75);
    cout << "the current list is : " << endl;
    printList(list);
    // do some lookup
    cout << "lookup Sarah's value (expect 92): " << *lookupNode(list, "Sarah") << endl;
    cout << "lookup Bob's value (expect NULL): ";
    if (lookupNode(list, "Bob") == NULL){
        cout << "NULL" << endl;
    }
    // remove element that does not exist
    cout << removeNode(list, "Zoe") << endl;
    // remove element that in the list
    cout << removeNode(list, "Wang") << endl;
    cout << "List after removing: " << endl;
    printList(list);
    cout << "The current size of the list is: " << getSize(list);
    return 0;
}

// why do we need include cpp doc? is that about "make"?
// why print false 0 and true 1, to distinguish int 0 and 1?
// why print NULL 0, how to print NULL or difference of 0 and NULL?