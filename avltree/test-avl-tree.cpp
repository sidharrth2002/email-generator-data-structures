#include <iostream>
#include <fstream>
#include "avltree.cpp"
using namespace std::chrono;

int main() {
    // 3 different trees, one for each set
    BST<string> treeA, treeB, treeC;
    
    ifstream Read;

    // // Set A
    // Read.open("../data/SetA/SetA.txt");

    // auto start100 = high_resolution_clock::now();

    // while (!Read.eof()) {
    //     string email;
    //     Read >> email;
    //     cout << email << endl;
    //     treeA.insert(email);
    // }
    
    // auto stop100 = high_resolution_clock::now();

    // auto duration100 = duration_cast<microseconds>(stop100-start100);

    // cout << "Duration to insert 100 emails: " << duration100.count() << " microseconds." << endl;

    // Read.close();

    // treeA.display();



    // // Set B
    // Read.open("../data/SetB/SetB.txt");

    // auto start100000 = high_resolution_clock::now();

    // while (!Read.eof()) {
    //     string email;
    //     Read >> email;
    //     cout << email << endl;
    //     treeB.insert(email);
    // }

    // auto stop100000 = high_resolution_clock::now();

    // auto duration100000 = duration_cast<microseconds>(stop100000-start100000);

    // cout << "Duration to insert 100000 emails: " << duration100.count() << " microseconds." << endl;

    // Read.close();

    // treeB.display();



    // Set C
    Read.open("../data/SetC/SetC.txt");

    auto start500000 = high_resolution_clock::now();

    while (!Read.eof()) {
        string email;
        Read >> email;
        cout << email << endl;
        treeC.insert(email);
    }

    // int test[] = {2, 7, 11, 3, 9, 21, 30, 4, 26, 20};
    // for (int i = 0; i < 10; i++) {
    //     cout << test[i] << endl;
    //     treeC.insert(test[i]);
    // }

    auto stop500000 = high_resolution_clock::now();

    auto duration500000 = duration_cast<microseconds>(stop500000-start500000);

    cout << "Time is " << duration500000.count() << endl;


    Read.close();

    cout << treeC.find("5rwsj.Etobk@SrjnF.org") << endl;
    // treeC.display();

}