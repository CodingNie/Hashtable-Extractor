// Name: Ning
// USC NetID: Nie
// CSCI 455 PA5
// Spring 2022

/*
 * grades.cpp
 * A program to test the Table class.
 * How to run it:
 *      grades [hashSize]
 * 
 * the optional argument hashSize is the size of hash table to use.
 * if it's not given, the program uses default size (Table::HASH_SIZE)
 *
 */

#include "Table.h"
//#include "Table.cpp"
//#include "listFuncs.h"
//#include "listFuncs.cpp"

// cstdlib needed for call to atoi
#include <cstdlib>

using namespace std;

void execute(Table *table);
void insert(Table *table);
void change(Table *table);
void lookup(Table *table);
void remove(Table *table);
void help(Table *table);


int main(int argc, char * argv[]) {

   // gets the hash table size from the command line

   int hashSize = Table::HASH_SIZE;

   Table * grades;  // Table is dynamically allocated below, so we can call
   // different constructors depending on input from the user.

   if (argc > 1) {
      hashSize = atoi(argv[1]);  // atoi converts c-string to int

      if (hashSize < 1) {
         cout << "Command line argument (hashSize) must be a positive number" 
              << endl;
         return 1;
      }

      grades = new Table(hashSize);

   }
   else {   // no command line args given -- use default table size
      grades = new Table();
   }


   grades->hashStats(cout);

   // add more code here
   // Reminder: use -> when calling Table methods, since grades is type Table*
    execute(grades);

   return 0;
}

// this function is to deal with the user command in the certain case
void execute(Table *table){
    while (true){
        cout << "cmd>";
        string command;
        cin >> command;
        if (command == "insert"){
            insert(table);
        }else if (command == "change"){
            change(table);
        }else if (command == "lookup"){
            lookup(table);
        }else if (command == "remove"){
            remove(table);
        }else if (command == "print"){
            table->printAll();
        }else if (command == "size"){
            cout << table->numEntries() <<endl;
        }else if (command == "stats"){
            table->hashStats(cout);
        }else if (command == "help"){
            help(table);
        }else if (command == "quit"){
            break;
        }else{
            cout << "Invalid command. Please type again" << endl;
        }
    }
}

// This function is to deal with the command "insert", which is followed by a string and an int
void insert(Table *table){
    string key;
    int value;
    cin >> key;
    cin >> value;
    bool result = table->insert(key, value);
    if (!result){
        cout << "Error: Cannot insert. The name " << key << " already exists." << endl;
    }
}

// This function is to deal with the command "change", which is followed by a string and an int
void change(Table *table){
    string key;
    int valueNew;
    cin >> key;
    cin >> valueNew;
    int *pValue = table->lookup(key);
    if (pValue != NULL){
        *pValue = valueNew;
    }else{
        cout << "Error: Cannot change. The student " << key << " is not in the table." << endl;
    }
}

// This function is to deal with the command "lookup", which is followed by a string
void lookup(Table *table){
    string key;
    cin >> key;
    int *pValue = table->lookup(key);
    if (pValue != NULL){
        cout << key << " has the score of " << *pValue << endl;
    }else{
        cout << "Error: Find nothing. The student " << key << " is not in the table." << endl;
    }
}

// This function is to deal with the command "remove", which is followed by a string
void remove(Table *table){
    string key;
    cin >> key;
    bool result = table->remove(key);
    if (!result){
        cout << "Error: Cannot remove. The student " << key << " is not in the table." << endl;
    }
}

// This function is to deal with the command "help"
void help(Table *table){
    cout << "As valid command, you can type in [insert, change, lookup, remove, print, size, stats, help, quit]" << endl;
    cout << "type [insert name score] to add the name to the table" << endl;
    cout << "type [change name newscore] to change the corresponding score of the name" << endl;
    cout << "type [lookup name] to search for the certain score of the name" << endl;
    cout << "type [remove name] to delete the entry in the table" << endl;
    cout << "type [print] to print all of the entries in the table" << endl;
    cout << "type [size] to print the number of entries in the table" << endl;
    cout << "type [stats] to show the current status of the table" << endl;
    cout << "type [help] to see the command summary" << endl;
    cout << "type [quit] to close the program" << endl;
}
