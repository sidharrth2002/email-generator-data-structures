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
      string email1;
      in >> email1;
      h1.insert(email1);
  }

  cout << h1 << endl;

  in.close();

  auto stop1 = high_resolution_clock::now();
  auto duration1 = duration_cast<microseconds>(stop1-start1);
  cout << "Duration to insert 100 emails: " << duration1.count() << " microseconds." << endl;
  cout << " " << endl;

 in.open("../data/SetA/canbefound.txt"); 
    double avgTimeForSuccessFulSearch1 = 0;
    while (!in.eof()) {
        string email1;
        in >> email1;
        auto start100 = high_resolution_clock::now();
        
        h1.retrieve(email1);
        
        auto end100 = high_resolution_clock::now();
        avgTimeForSuccessFulSearch1 += duration_cast<microseconds>(end100-start100).count();
        
    }
    avgTimeForSuccessFulSearch1 /= 10;
    cout << "Average duration to search Tree A with emails that can be found " << avgTimeForSuccessFulSearch1 << endl;
    in.close();

    in.open("../data/SetA/cannotbefound.txt");
    double avgTimeForSuccessFulSearch100 = 0;
    while (!in.eof()) {
        string email100;
        in >> email100;
        auto start200 = high_resolution_clock::now();
        h1.retrieve(email100);
        auto end200 = high_resolution_clock::now();
        avgTimeForSuccessFulSearch100 += duration_cast<microseconds>(end200-start200).count();
        
    }
    avgTimeForSuccessFulSearch100 /= 10;
    cout << "Average duration to search Tree A with emails that cannot be found " << avgTimeForSuccessFulSearch100 << endl;
    in.close(); 

/*
   //Set B
  HashTableChaining<string> h2(90000);

  auto start2 = high_resolution_clock::now();


  in.open("../data/SetB/SetB.txt");

  while (!in.eof()) {
      string email2;
      in >> email2;
      h2.insert(email2);
  }

  cout << h2 << endl;
  in.close();

  auto stop2 = high_resolution_clock::now();
  auto duration2 = duration_cast<microseconds>(stop2-start2);
  cout << "Duration to insert 100000 emails: " << duration2.count() << " microseconds." << endl;
  cout << " " << endl;

   in.open("../data/SetB/canbefound.txt"); 
    double avgTimeForSuccessFulSearch2 = 0;
    while (!in.eof()) {
        string email2;
        in >> email2;
        auto start300 = high_resolution_clock::now();
        
        h1.retrieve(email2);
        
        auto end300 = high_resolution_clock::now();
        avgTimeForSuccessFulSearch1 += duration_cast<microseconds>(end300-start300).count();
        
    }
    avgTimeForSuccessFulSearch1 /= 10;
    cout << "Average duration to search Tree B with emails that can be found " << avgTimeForSuccessFulSearch2 << endl;
    in.close();

    in.open("../data/SetB/cannotbefound.txt");
    double avgTimeForSuccessFulSearch200 = 0;
    while (!in.eof()) {
        string email200;
        in >> email200;
        auto start400 = high_resolution_clock::now();
        h1.retrieve(email200);
        auto end400 = high_resolution_clock::now();
        avgTimeForSuccessFulSearch200 += duration_cast<microseconds>(end400-start400).count();
        
    }
    avgTimeForSuccessFulSearch200 /= 10;
    cout << "Average duration to search Tree B with emails that cannot be found " << avgTimeForSuccessFulSearch200 << endl;
    in.close(); 

  
  //Set C
  HashTableChaining<string> h3(450000);

  auto start3 = high_resolution_clock::now();

  in.open("../data/SetC/SetC.txt");

  while (!in.eof()) {
      string email3;
      in >> email3;
      h3.insert(email3);
  }

  cout << h3 << endl;
  in.close();

  auto stop3 = high_resolution_clock::now();
  auto duration3 = duration_cast<microseconds>(stop3-start3);
  cout << "Duration to insert 500000 emails: " << duration3.count() << " microseconds." << endl;
  cout << " " << endl;
  
  in.open("../data/SetC/canbefound.txt"); 
    double avgTimeForSuccessFulSearch3 = 0;
    while (!in.eof()) {
        string email3;
        in >> email3;
        auto start500 = high_resolution_clock::now();
        
        h1.retrieve(email3);
        
        auto end500 = high_resolution_clock::now();
        avgTimeForSuccessFulSearch3 += duration_cast<microseconds>(end500-start500).count();
    }
    avgTimeForSuccessFulSearch3 /= 10;
    cout << "Average duration to search Tree C with emails that can be found " << avgTimeForSuccessFulSearch3 << endl;
    in.close();

        in.open("../data/SetC/cannotbefound.txt");
    double avgTimeForSuccessFulSearch300 = 0;
    while (!in.eof()) {
        string email300;
        in >> email300;
        auto start600 = high_resolution_clock::now();
        h1.retrieve(email300);
        auto end600 = high_resolution_clock::now();
        avgTimeForSuccessFulSearch300 += duration_cast<microseconds>(end600-start600).count();
        
    }
    avgTimeForSuccessFulSearch300 /= 10;
    cout << "Average duration to search Tree C with emails that cannot be found " << avgTimeForSuccessFulSearch300 << endl;
    in.close();

*/
  

}
