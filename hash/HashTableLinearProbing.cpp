#include <vector>
#include <iostream>
#include <algorithm>
#include "LinkedList.cpp" // available at MMLS.

template <typename T>
class HashTableLinearProbing {
    T * table = NULL;
    int capacity;
    int tableSize;

  long long hashfunction(string const& hashitem) {
    int p = 53;
    int m = 1e9 + 9;
    long long power_of_p = 1;
    long long hash_val = 0;

    for (int i = 0; i < hashitem.length(); i++) {
        hash_val
            = (hash_val
               + (hashitem[i] - 'a' + 1) * power_of_p)
              % m;
        power_of_p
            = (power_of_p * p) % m;
    }
    return hash_val % capacity;
  }

  public:
  HashTableLinearProbing (int size) {
      capacity = size;
      tableSize = 0;
      table = new T[size];
      std::fill_n(table, size, "");
  }

  ~HashTableLinearProbing() {
      delete [] table;
  }

  int size() {
    return tableSize;
  }

  void insert (T newItem) {          
        int hashIndex = hashfunction(newItem); 
        while(table[hashIndex].length() != 0 && table[hashIndex] != newItem) 
        { 
            hashIndex++; 
            hashIndex %= capacity; 
        } 
          
        if(table[hashIndex].length() == 0) 
            tableSize++; 
        table[hashIndex] = newItem; 
  }

  void printAt30() {
    cout << table[30] << endl;
  }

  bool retrieve (T target) {
        int hashIndex = hashfunction(target); 
        int counter = 0; 
        while(table[hashIndex].length() > 0) {   
          int counter =0; 
          cout << table[hashIndex] << endl;
          if(counter++>capacity) 
            return false;         
          if(table[hashIndex] == target) 
            return true; 
          hashIndex++; 
          hashIndex %= capacity; 
        } 
        return false; 
  }

  friend ostream& operator<< (ostream& os, HashTableLinearProbing<T>& ht) {
    for (int i = 0; i < ht.size(); i++)
      os << i << " = " << ht.table[i] << endl;
    return os;
  }
};
