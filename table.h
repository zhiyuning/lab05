//
//  table.h
//  W19 - Lab04
//
#ifndef table_h
#define table_h
#include <vector>
#include <string>
#include <iosfwd>
#include "entry.h"

class Table{
 public:

  //Add:
  Table(const Table &orig);
  Table & operator=(const Table &RHS);
  ~Table();

   Table(unsigned int max_entries=100);
   //One constructor that builds an empty Table designed to hold a maximum number
   //of entries equal to the only parameter.

   Table(unsigned int entries, std::istream& input);
   //Another constructor that builds a Table designed to hold the number of
   //entries specified by the first parameter, and puts that many entries into
   //the Table by reading them one at a time from the input stream that is the
   //second parameter:


   void put(unsigned int key, std::string data);
   //creates a new Entry to put in the Table.


   void put(Entry e);
   //puts a copy of the parameter in the Table

   //where the Table already contains an Entry with the given key, these
   //functions act to update the Entry for that key. The Table is not allowed to
   //contain duplicate keys



   std::string get(unsigned int key) const;
   //returns the string associated with the parameter

   bool remove(unsigned int key);
   //removes the Entry containing the given key,returns true if it removes an
   //Entry, or false if the Table has no such Entr


   friend std::ostream& operator<< (std::ostream& out, const Table& t);
   //overloads the << operator to print the Table
   //To a separate line of the given output stream in the order of their key
   //values

  // bool ifsame(const Table& t);


 private:
   unsigned int CAPACITY;
   unsigned int hash(unsigned int key) const; //a hash function by own
   std::vector<Entry> *HashTable;

};

//helper:

void mergesort(Entry a[], unsigned int size);
void merge(Entry a[], unsigned int leftArraySize, unsigned int rightArraySize);



#endif /* table_h */
