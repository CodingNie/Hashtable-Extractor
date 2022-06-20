// Name: Ning Nie
// USC NetID: nnie
// CSCI 455 PA5
// Spring 2022


#include <iostream>

#include <cassert>

#include "listFuncs.h"

using namespace std;

Node::Node(const string &theKey, int theValue) {
   key = theKey;
   value = theValue;
   next = NULL;
}

Node::Node(const string &theKey, int theValue, Node *n) {
   key = theKey;
   value = theValue;
   next = n;
}


// add the element into the list with the specified key and value, return false if the key is already in it
bool addNode(ListType &list, const string &target, int value){
    if (lookupNode(list, target) == NULL){
        list = new Node(target, value, list);
        return true;
    }else{
        return false;
    }
}

// remove the element from the list with the specified key, return false when the node(with the key) doesn't exist
bool removeNode(ListType &list, const string &target){
    if (lookupNode(list, target) == NULL){ // this contains list == NULL or no such element in the list
        return false;
    }
    // the target is the first element
    if (list->key == target){
        ListType temp = list;
        list = list->next;
        delete temp;
        return true;
    }else{
        ListType pre = list;
        ListType next = list->next;
        // next will not be NULL since we lookupNode first, hence it's safety for next->next below
        while (next != NULL){
            if (next->key == target){
                pre->next = next->next;
                delete next;
                return true;
            }else{
                pre = next;
                next = next->next;
            }
        }
    }
}

// lookup for the element in the linked list with a specified key, return the value address of the key, return null else
int* lookupNode(ListType &list, const string &target){
    ListType cur = list;
    while (cur != NULL){
        if (cur->key == target){
            int *p = &(cur->value);
            return p;
        }else{
            cur = cur->next;
        }
    }
    return NULL;
}

// print all the current elements in the linked list
void printList(ListType &list){
    ListType cur = list;
    while (cur != NULL){
        cout << cur->key << " " << cur->value << endl;
        cur = cur->next;
    }
}

// get the size of the current linked list
int getSize(ListType &list){
    ListType cur = list;
    int num = 0;
    while (cur != NULL){
        cur = cur->next;
        num++;
    }
    return num;
}



//*************************************************************************
// put the function definitions for your list functions below
