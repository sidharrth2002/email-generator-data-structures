#include <vector>
#include "LinkedList.cpp"

template <typename T>
class HashTable {
  vector< LinkedList<T> > table;

  long long hashfunction (string const& hashitem) {
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
    return hash_val % table.size();
}


 public:
  HashTable (int size) {
table.resize (size);
  }
  ~HashTable() {
    for (int i = 0; i < table.size(); i++)
      table[i].makeEmpty();
  }
  int size() {
    return table.size();
  }
  void insert (T newItem) {
      long long  index = hashfunction (newItem);
      table[index].insertFront (newItem);
  }

    bool retrieve (T & target) {
      int index = hashfunction (target);
      if (!table[index].find (target))
        return false;
      return true;
  }

  friend ostream& operator<< (ostream& os, HashTable<T>& ht) {
    for (int i = 0; i < ht.size(); i++)
      os << (i + 1) << " = " << ht.table[i] << endl;
    return os;
  }


};

