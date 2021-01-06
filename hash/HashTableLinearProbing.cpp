// #include <vector>
// #include <iostream>
// #include <algorithm>
// #include "LinkedList.cpp" // available at MMLS.

// template <typename T>
// class HashTableLinearProbing {
//     T * table = NULL;
//     int tableSize;

//   //int hashfunction (int hashitem) { // hash function
//   //  return hashitem % tableSize;
//   //}

//     long long hashfunction(string const& hashitem) {
//     int p = 53;
//     int m = 1e9 + 9;
//     long long power_of_p = 1;
//     long long hash_val = 0;


//     for (int i = 0; i < hashitem.length(); i++) {
//         hash_val
//             = (hash_val
//                + (hashitem[i] - 'a' + 1) * power_of_p)
//               % m;
//         power_of_p
//             = (power_of_p * p) % m;
//     }
//     return hash_val % tableSize;
// }
//  public:
//   HashTableLinearProbing (int size) {
//       tableSize = size;
//       table = new T[size];
//       std::fill_n(table, size, " ");
//   }


//   ~HashTableLinearProbing() {
//       // delete table;
//   }

//   int size() {
//     return tableSize;
//   }

//   void insert (T newItem) {
//     int index = hashfunction(newItem);
//     if (table[index] == " ") {
//         table[index] = newItem;
//     } else {
//         bool loaded = false;
//         while(!loaded) {
//             index += 1;
//             if(table[index] == " ") {
//                 table[index] = newItem;
//                 loaded = true;
//             } else if (table[index] == newItem) {
//               return;
//             } else if (index >= tableSize) {
//                 index = -1;
//             }
//         }
//     }
//     table[index] = newItem;
//   }

//   bool retrieve (T & target) {
//     int index = hashfunction(target);
//     int originalIndex = index;
//     if (table[index] == target) {
//         return true;
//     } else {
//         bool found = false;
//         while(!found) {
//             index += 1;
//             if(table[index] == target) {
//                 return true;
//             } else if (index >= tableSize) {
//                 index = -1;
//             } else if (index == originalIndex) {
//               return false;
//             }
//         }
//     }
//   }

//   friend ostream& operator<< (ostream& os, HashTableLinearProbing<T>& ht) {
//     for (int i = 0; i < ht.size(); i++)
//       os << i << " = " << ht.table[i] << endl;
//     return os;
//   }
// };

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
    cout << (hash_val % capacity) << endl;
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
      delete table;
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
    // int index = hashfunction(newItem);
    // // if (table[index] == "") {
    // //     table[index] = newItem;
    // // } else {
    //     bool loaded = false;
    //     while(!table[index].empty() && table[index] != newItem) { 
    //         index++; 
    //     } 
    // if(table[index].empty()) {
    //   tableSize++;
    // }
    // table[index] = newItem;
  }

  void printAt30() {
    cout << table[30] << endl;
  }

  bool retrieve (T target) {
        // Apply hash function to find index for given key 
        int hashIndex = hashfunction(target); 
        int counter = 0; 
        //finding the node with given key   
        while(table[hashIndex].length() > 0) {   
          int counter =0; 
          cout << table[hashIndex] << endl;
          if(counter++>capacity)  //to avoid infinite loop 
            return false;         
            //if node found return its value 
          if(table[hashIndex] == target) 
            return true; 
          hashIndex++; 
          hashIndex %= capacity; 
        } 
          
        //If not found return null 
        return false; 

    // int index = hashfunction(target);
    // int originalIndex = index;
    // if (table[index] == target) {
    //     return true;
    // } else {
    //     bool found = false;
    //     while(!found) {
    //         index += 1;
    //         if(table[index] == target) {
    //             return true;
    //         } else if (index >= tableSize) {
    //             index = -1;
    //         } else if (index == originalIndex) {
    //           return false;
    //         }
    //     }
    // }
    // int index = hashfunction(target);
    // int originalIndex = index;
    // if (table[index] == target) {
    //     return true;
    // } else {
    //     // bool found = false;

    //     int numberSearched = 0;

    //     while(table[index] != NULL) {  
    //       numberSearched+=1;   
    //       if(numberSearched>capacity)  //to avoid infinite loop 
    //         return false;         
    //         //if node found return its value 
    //         if(table[index]->key == key) 
    //             return arr[hashIndex]->value; 
    //         hashIndex++; 
    //         hashIndex %= capacity; 
    //     } 

    //     while(!table[index].empty()) {
    //         numberSearched += 1;
    //         if(numberSearched > capacity) return false;

    //         if(table[index] == target) return true;

    //         index++;
    //         index %= capacity;
    //         // if(table[index] == target) {
    //         //     return true;
    //         // } else if (index >= tableSize) {
    //         //     index = -1;
    //         // } else if (index == originalIndex) {
    //         //   return false;
    //         // }
    //     }
    // }
  }

  friend ostream& operator<< (ostream& os, HashTableLinearProbing<T>& ht) {
    for (int i = 0; i < ht.size(); i++)
      os << i << " = " << ht.table[i] << endl;
    return os;
  }
};
