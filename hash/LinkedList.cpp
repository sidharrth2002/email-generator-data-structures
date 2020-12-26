

#ifndef LINKEDLIST_CPP
#define LINKEDLIST_CPP

#include <iostream>
using namespace std;

template <typename T>
struct Node {
  T info;
  Node<T> *next;
};

template <typename T>
class LinkedList {
  Node<T> *start;
 public:
  LinkedList() { start = NULL; }
  ~LinkedList() { makeEmpty(); }

  void insertFront (T & element ) {
    Node<T> *newNode = new Node<T>;
    newNode->info = element;
    newNode->next = start;
    start = newNode;
  }

  bool find (T & target) {
    bool found = false;
    Node<T> *ptr = start;
    while (ptr != NULL && !found) {
      if (ptr->info == target) {
        found = true;
      }
      else
        ptr = ptr->next;
    }
    return found;
  }
  bool isEmpty() { return start == NULL; }
  void makeEmpty() {
    while (start != NULL) {
      Node<T> *ptr  = start;
      start = start->next;
      delete ptr;
    }
  }
  friend ostream& operator<< (ostream& os, LinkedList<T>& list) {
    Node<T> *ptr = list.start;
    while (ptr != NULL) {
      os << ptr->info << " ";
      ptr = ptr->next;
    }
    return os;
  }
};
#endif
