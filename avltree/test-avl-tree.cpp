#include <iostream>
#include <fstream>
#include "avltree.cpp"
using namespace std::chrono;

int main() {
    BST<string> t;
    
    ifstream Read;
    Read.open("SetA.txt");

    auto start100 = high_resolution_clock::now();
    while (!Read.eof()) {
        string email;
        Read >> email;
        cout << email << endl;
        t.insert(email);
    }
    auto stop100 = high_resolution_clock::now();

    auto duration100 = duration_cast<microseconds>(stop100-start100);
    cout << "Duration to insert 100 emails: " << duration100.count() << " microseconds." << endl;
    
    Read.close();

    Read.open("SetB.txt");
    auto start100000 = high_resolution_clock::now();
    while (!Read.eof()) {
        string email;
        Read >> email;
        cout << email << endl;
        t.insert(email);
    }
    auto stop100000 = high_resolution_clock::now();

    auto duration100000 = duration_cast<microseconds>(stop100000-start100000);
    cout << "Duration to insert 100000 emails: " << duration100000.count() << " microseconds." << endl;
    Read.close();

    Read.open("SetC.txt");
    auto start500000 = high_resolution_clock::now();
    while (!Read.eof()) {
        string email;
        Read >> email;
        cout << email << endl;
        t.insert(email);
    }
    auto stop500000 = high_resolution_clock::now();

    auto duration500000 = duration_cast<microseconds>(stop500000-start500000);
    cout << "Duration to insert 100000 emails: " << duration500000.count() << " microseconds." << endl;
    Read.close();
}

// int main() {
//     BST<int> t;
//     t.insert(1000);
//     // t.insert(25);
//     t.insert(15);
//     t.insert(10);
//     t.insert(5);
//     t.insert(30);
//     t.insert(50);
//     t.insert(60);
//     t.insert(70);
//     t.insert(80);
//     t.display();

//     node<int>* result = t.findElement(t.root, 10);
//     if(result == NULL) {
//         cout << "not found" << endl;
//     } else {
//         cout << "found" << endl;
//     }

//     cout << "height is" << endl;
//     cout << t.nodeHeight(t.root) << endl;

//     return 0; 
// }