#include <vector>
#include <iostream>
using namespace std;

template <typename T>
void printArray (T A[], int n) {
  for (int i = 0; i < n; i++)
    cout << A[i] << " ";
  cout << endl;
}

template <typename T>
class PriorityQueue {
  vector<T> A;

  void heapify_enqueue (int index) {   
    if (index == 0)                    
      return;
    
	
       int parent = (index - 1) /2;
      
       if (A[index] > A[parent]){
          swap(A[index],A[parent]);
          heapify_enqueue(parent);
       }
             

  }



  void heapify_dequeue (int index) {   
    int max;                           
    // left child 
      int left = (2*index)+1;
    
    // right child 
    int right = (2*index)+2;

    
    if (left < A.size() && A[left] >  A[index]) 
       max = left;
     else
       max = index;

    if (right < A.size() && A[right] >  A[index]) 
       max = right;

    if (max != index) {
      swap (A[index], A[max]);
      heapify_dequeue (max);
    }
  }
  
 public:
  void enqueue (T element) {
    A.push_back (element);
    heapify_enqueue (A.size()-1);  
  }
  
  T dequeue() {
    T removed_element = A[0];
    A[0] = A[A.size()-1];          
    A.pop_back();                 
    heapify_dequeue (0);          
    return removed_element;
  }
  
  int size() {
    return A.size();
  }

  void print() {
    
    for (int i = 0; i < A.size(); i++)
      cout << A[i] << endl;
  }  
};


