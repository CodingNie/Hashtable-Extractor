// Name: Ning Nie
// USC NetID: nnie
// CSCI 455 PA5
// Spring 2022


//*************************************************************************
// Node class definition 
// and declarations for functions on ListType

// Note: we don't need Node in Table.h
// because it's used by the Table class; not by any Table client code.

// Note2: it's good practice to *not* put "using" statement in *header* files.  Thus
// here, things from std libary appear as, for example, std::string

#ifndef LIST_FUNCS_H
#define LIST_FUNCS_H

#include <string>
  

struct Node {
   std::string key;
   int value;

   Node *next;

   Node(const std::string &theKey, int theValue);

   Node(const std::string &theKey, int theValue, Node *n);
};


typedef Node * ListType;

//*************************************************************************
//add function headers (aka, function prototypes) for your functions
//that operate on a list here (i.e., each includes a parameter of type
//ListType or ListType&).  No function definitions go in this file.


// add the element into the list with the specified key and value, return false if the key is already in it
bool addNode(ListType &list, const std::string &target, int value);

// remove the element from the list with the specified key, return false when the node(with the key) doesn't exist
bool removeNode(ListType &list, const std::string &target);


// lookup for the element in the linked list with a specified key, return the value address of the key, return null else
int* lookupNode(ListType &list, const std::string &target);

// print all the current elements in the linked list
void printList(ListType &list);

// get the size of the current linked list
int getSize(ListType &list);



// keep the following line at the end of the file
#endif
