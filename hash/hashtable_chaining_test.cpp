#include <iostream>
#include <fstream>
#include "HashTableChaining.cpp"
#include <chrono>
#include <vector>
using namespace std::chrono;

int main() {
  //Set A
  HashTableChaining<string> h1(90);

  auto start1 = high_resolution_clock::now();

  ifstream in;

  in.open("../data/SetA/SetA.txt");

  while (!in.eof()) {
      string email;
      in >> email;
      h1.insert(email);
  }

  cout << h1 << endl;

  in.close();

  auto stop1 = high_resolution_clock::now();
  auto duration1 = duration_cast<microseconds>(stop1-start1);
  cout << "Duration to insert 100 emails: " << duration1.count() << " microseconds." << endl;
  cout << " " << endl;

  cout << h1.retrieve("6EbPI.E8QhS@APDBy.net") << endl;

  string target1;
  cout << "Target to retrieve: ";
  cin >> target1;

  auto start2 = high_resolution_clock::now();

  if (h1.retrieve (target1))
    cout << "Target found\n";
  else
    cout << "Target not found\n";

  auto stop2 = high_resolution_clock::now();
  auto duration2 = duration_cast<microseconds>(stop2-start2);
  cout << "Duration to search the data: " << duration2.count() << " microseconds." << endl;
  cout << " " << endl;


//    Set B
  HashTableChaining<string> h2(90000);

  auto start3 = high_resolution_clock::now();


  in.open("../data/SetB/SetB.txt");

  while (!in.eof()) {
      string email;
      in >> email;
      h2.insert(email);
  }

//   cout << h2 << endl;
  in.close();

  auto stop3 = high_resolution_clock::now();
  auto duration3 = duration_cast<microseconds>(stop3-start3);
  cout << "Duration to insert 100000 emails: " << duration3.count() << " microseconds." << endl;
  cout << " " << endl;

  string target2;
  cout << "Target to retrieve: ";
  cin >> target2;

  auto start4 = high_resolution_clock::now();

  if (h2.retrieve (target2))
    cout << "Target found\n";
  else
    cout << "Target not found\n";

  auto stop4 = high_resolution_clock::now();
  auto duration4 = duration_cast<microseconds>(stop4-start4);
  cout << "Duration to search the data: " << duration4.count() << " microseconds." << endl;
  cout << " " << endl;


//   Set C
  HashTableChaining<string> h3(450000);

  auto start5 = high_resolution_clock::now();

  in.open("../data/SetC/SetC.txt");

  while (!in.eof()) {
      string email;
      in >> email;
      h3.insert(email);
  }

//   cout << h3 << endl;
  in.close();

  auto stop5 = high_resolution_clock::now();
  auto duration5 = duration_cast<microseconds>(stop5-start5);
  cout << "Duration to insert 500000 emails: " << duration5.count() << " microseconds." << endl;
  cout << " " << endl;

  string target3;
  cout << "Target to retrieve: ";
  cin >> target3;

  auto start6 = high_resolution_clock::now();

  if (h3.retrieve (target3))
    cout << "Target found\n";
  else
    cout << "Target not found\n";

  auto stop6 = high_resolution_clock::now();
  auto duration6 = duration_cast<microseconds>(stop6-start6);
  cout << "Duration to search the data: " << duration6.count() << " microseconds." << endl;
  cout << " " << endl;

  }




