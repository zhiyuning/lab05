#include "table.h"
#include <iostream>


Table::Table(unsigned int max_entries){
  this->CAPACITY = max_entries;
  this->HashTable = new std::vector<Entry>[max_entries];
}


Table::Table(unsigned int entries, std::istream& input){
  this->CAPACITY = entries;
  this->HashTable = new std::vector<Entry>[entries];
  Entry temp;
  for(unsigned int i=0;i<entries;i++){
    input>>temp;
    this->put(temp);
  }

}


void Table::put(unsigned int key, std::string data){
  put(Entry(key, data));
}

void Table::put(Entry e){
  if(HashTable[hash(e.get_key())].empty()){
    HashTable[hash(e.get_key())].push_back(e);
  }else{
    for(unsigned int i = 0;i<HashTable[hash(e.get_key())].size();i++){
      if(HashTable[hash(e.get_key())][i].get_key()==e.get_key()){
        HashTable[hash(e.get_key())][i].set_data(e.get_data());
        return;
      }
    }
    HashTable[hash(e.get_key())].push_back(e);
  }
}


std::string Table::get(unsigned int key) const {
  std::string res="";
  for(unsigned int i = 0;i<HashTable[hash(key)].size();i++){
    if(HashTable[hash(key)].at(i).get_key()==key){
      res=HashTable[hash(key)].at(i).get_data();
    }
  }
  return res;
}

bool Table::remove(unsigned int key){
  if(HashTable[hash(key)].empty()){
    return false;
  }else{
    for(unsigned int i = 0;i<HashTable[hash(key)].size();i++){
      if(HashTable[hash(key)].at(i).get_key()==key){
        HashTable[hash(key)].erase(HashTable[hash(key)].begin()+i);
        return true;
      }
    }
    return false;
  }
}


unsigned int Table::hash(unsigned int key) const {
  return key%CAPACITY;
}

void mergesort(Entry a[], unsigned int size) {
	unsigned int leftArraySize;
	unsigned int rightArraySize;

	if (size > 1) {
		leftArraySize = size / 2;
		rightArraySize = size - leftArraySize;

		mergesort(a, leftArraySize);
		mergesort((a + leftArraySize), rightArraySize);

		merge(a, leftArraySize, rightArraySize);
	}
}

void merge(Entry a[], unsigned int leftArraySize, unsigned int rightArraySize) {

	Entry* tempArray;
	unsigned int copied = 0;
	unsigned int leftCopied = 0;
  unsigned int rightCopied = 0;

	tempArray = new Entry[leftArraySize + rightArraySize];


	while ((leftCopied < leftArraySize) && (rightCopied < rightArraySize)) {
		if (a[leftCopied] < (a + leftArraySize)[rightCopied]) {
			tempArray[copied++] = a[leftCopied++];
		} else {
			tempArray[copied++] = (a + leftArraySize)[rightCopied++];
		}
	}

	while (leftCopied < leftArraySize) {
		tempArray[copied++] = a[leftCopied++];
	}

	while (rightCopied < rightArraySize) {
		tempArray[copied++] = (a + leftArraySize)[rightCopied++];
	}

	for (int i = 0; i < leftArraySize + rightArraySize; i++) {
		a[i] = tempArray[i];
	}

	delete [] tempArray;
}

std::ostream& operator<< (std::ostream& out, const Table& t) {
  int b=t.CAPACITY;
  Entry *temp=new Entry[t.CAPACITY];
  int count = 0;
  for(int i=0;i<b;i++){
    for(int j=0;j<(t.HashTable[i]).size();j++){
      temp[count++] = t.HashTable[i][j];
    }
  }
  mergesort(temp, b);
  for(int c=0;c<b;c++){
    out<<temp[c]<<"\n";
  }
  return out;
}


Table::Table(const Table &orig){
  this->CAPACITY=orig.CAPACITY;
  this->HashTable = new std::vector<Entry>[this->CAPACITY];
  for(int i=0;i<orig.CAPACITY;i++){
    for(int j=0;j<(orig.HashTable[i]).size();j++){
      put(orig.HashTable[i][j]);
    }
  }
}


Table & Table::operator=(const Table &RHS){
  if(this == &RHS){
    //std::cout<<"S  C"<<std::endl;
    return (*this);
  }else{
    this->CAPACITY==RHS.CAPACITY;
    this->HashTable = new std::vector<Entry>[CAPACITY];
    for(int i=0;i<RHS.CAPACITY;i++){
      for(int j=0;j<(RHS.HashTable[i]).size();j++){
	put(RHS.HashTable[i][j]);
      }
      //std::cout<<"Check"<<std::endl;
    }
    return (*this);
}
}





Table::~Table(){
  //std::cout<<"Destructor called";
  delete[] HashTable;
}

/*

bool Table::ifsame(const Table& t){
   bool issame=true;
   for(int i=0;i<t.CAPACITY;i++){
     for(int j=0;j<(t.HashTable[i]).size();j++){
       //std::cout<<"Steps check1"<<std::endl;
       if(this->HashTable[i][j]!=t.HashTable[i][j]){
	 return false;
       }
     }
   }
   return issame;
}

*/
