#include <iostream>
#include <fstream>
#include "heap.cpp"
using namespace std::chrono;
using namespace std;

int main () {


  PriorityQueue<string> setA, setB, setC ;
  ifstream Read;

    // Set A ------------------------------- 
    Read.open("../data/SetA/SetA.txt");

    auto start100 = high_resolution_clock::now();

    while (!Read.eof()) {
        string email;
        Read >> email;
        setA.enqueue(email);
    }

    cout << endl;
    cout << "Enqueued 100 emails (Set A): " << endl;
    cout << endl;
    setA.print();
    cout << endl;
    

    auto stop100 = high_resolution_clock::now();

    auto duration100 = duration_cast<microseconds>(stop100-start100);

    cout << "Duration to insert 100 emails: " << duration100.count() << " microseconds." << endl;
    cout << endl;
    Read.close();

  //deqeue set A:
  cout << "\nDequeue\t: PriorityQueue\n";
  cout << endl;
  auto startde = high_resolution_clock::now();
  int n = (setA.size() * 0.1);
  for (int i = 0; i < n; i++) {    
    cout << i + 1 << ": "<< setA.dequeue() << endl;
  }
  auto stopde = high_resolution_clock::now();

  auto duration = duration_cast<microseconds>(stopde-startde);

  cout << "Duration to remove 10 emails: " << duration.count() << " microseconds." << endl;
  cout << endl;
 

  // Set B ------------------------------- 
    Read.open("../data/SetB/SetB.txt");

    auto start100000 = high_resolution_clock::now();

    while (!Read.eof()) {
        string email;
        Read >> email;
        setB.enqueue(email);
    }

    cout << endl;
    cout << "Enqueued 100000 emails (Set B): " << endl;
    cout << endl;
    setB.print();
    cout << endl;

    auto stop100000 = high_resolution_clock::now();

    auto duration100000 = duration_cast<microseconds>(stop100000-start100000);

    cout << "Duration to insert 100000 emails: " << duration100000.count() << " microseconds." << endl;
    cout << endl;
    Read.close();

  //deqeue set B:
  cout << "\nDequeue\t: PriorityQueue\n";
  cout << endl;
  auto startde2 = high_resolution_clock::now();
  int n2 = (setB.size() * 0.1);
  for (int i = 0; i < n2; i++) {    
    cout << i + 1 << ": "<< setB.dequeue() << endl;
  }
  auto stopde2 = high_resolution_clock::now();

  auto duration2 = duration_cast<microseconds>(stopde2-startde2);

  cout << "Duration to remove 10000 emails: " << duration2.count() << " microseconds." << endl;
  cout << endl;


    // Set C ------------------------------- 
    Read.open("../data/SetC/SetC.txt");

    auto start500000 = high_resolution_clock::now();

    while (!Read.eof()) {
        string email;
        Read >> email;
        setC.enqueue(email);
    }

    cout << endl;
    cout << "Enqueued 500000 emails (Set C): " << endl;
    cout << endl;
    setC.print();
    cout << endl;

    auto stop500000 = high_resolution_clock::now();

    auto duration500000 = duration_cast<microseconds>(stop500000-start500000);

    cout << "Duration to insert 500000 emails: " << duration500000.count() << " microseconds." << endl;

    cout << endl;
    Read.close();

  //deqeue set C:
  cout << "\nDequeue\t: PriorityQueue\n";
  cout << endl;
  auto startde3 = high_resolution_clock::now();
  int n3 = (setC.size() * 0.1);
  for (int i = 0; i < n3; i++) {    
    cout << i + 1 << ": "<< setC.dequeue() << endl;
  }
  auto stopde3 = high_resolution_clock::now();

  auto duration3 = duration_cast<microseconds>(stopde3-startde3);

  cout << "Duration to remove 50000 emails: " << duration3.count() << " microseconds." << endl;
  cout << endl;


 
  
}
