// Name: Ning nie
// USC NetID: nnie
// CSCI 455 PA5
// Spring 2022

// Table.cpp  Table class implementation


#include "Table.h"

#include <iostream>
#include <string>
#include <cassert>

// for hash function called in private hashCode method defined below
#include <functional>

using namespace std;


// listFuncs.h has the definition of Node and its methods.  -- when
// you complete it it will also have the function prototypes for your
// list functions.  With this #include, you can use Node type (and
// Node*, and ListType), and call those list functions from inside
// your Table methods, below.

#include "listFuncs.h"


//*************************************************************************


Table::Table() {
    // using the initial hash_size and construct the table
    data = new ListType[HASH_SIZE];
    entries = 0;
    nonEmptyBuckets = 0;
    longestChain = 0;
    hashSize = HASH_SIZE;
}


Table::Table(unsigned int hSize) {
    //using the specified hash size for the table
    data = new ListType[hSize];
    entries = 0;
    nonEmptyBuckets = 0;
    longestChain = 0;
    hashSize = hSize;

}

// since we have defined the lookup function in listFuncs.cpp and return the requested value, we can use it directly
int * Table::lookup(const string &key) {
    int code = hashCode(key);
    return lookupNode(data[code], key);
}


bool Table::remove(const string &key) {
    int code = hashCode(key);
    bool feedback = removeNode(data[code], key);
    // if certainly delete one entry, we need to check the status of the bucket, and maintain the private field as well
    if (feedback){
        entries--;
        // when this bucket is empty after a single remove, it will release an empty bucket
        if (getSize(data[code]) == 0){
            nonEmptyBuckets--;
        }
        // loop through the bucket to find the max chain length
        int maxChain = 0;
        for (int i = 0; i < hashSize; i++){
            int curChain = getSize(data[i]);
            maxChain = curChain > maxChain ? curChain : maxChain;
        }
        longestChain = maxChain;
        return true;
    }
    return false;
}


bool Table::insert(const string &key, int value) {
    int code = hashCode(key);
    bool feedback = addNode(data[code], key, value);
    // if certainly insert the entry, we need to check the status of the bucket, and maintain the private field
    if (feedback){
        entries++;
        int curChain = getSize(data[code]);
        // if the size of one bucket is equal to one after one single insertion, then we used an empty bucket just now
        if (curChain == 1){
            nonEmptyBuckets++;
        }
        // only need to check if the longest chain changes after this insertion
        longestChain = curChain > longestChain ? curChain : longestChain;
        return true;
    }else{
        return false;
    }
}


int Table::numEntries() const {
    return entries;
}


void Table::printAll() const {
    int count = 0;
    for (int i = 0; i < hashSize; i++){
        printList(data[i]);
        count += getSize(data[i]);
        if (count >= entries){
            break;
        }
    }
}

void Table::hashStats(ostream &out) const {
    cout << "number of buckets: " << hashSize << endl;
    cout << "number of entries: " << entries << endl;
    cout << "number of non-empty buckets: " << nonEmptyBuckets << endl;
    cout << "longest chain: " << longestChain << endl;
}


// hash function for a string
// (we defined it for you)
// returns a value in the range [0, hashSize)
unsigned int Table::hashCode(const string &word) const {

   // Note: calls a std library hash function for string (it uses the good hash
   //   algorithm for strings that we discussed in lecture).
   return hash<string>()(word) % hashSize;

}


// add definitions for your private methods here

