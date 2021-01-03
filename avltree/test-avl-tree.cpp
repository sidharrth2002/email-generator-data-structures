#include <iostream>
#include <fstream>
#include "avltree.cpp"
using namespace std::chrono;

int main() {
    // 3 different trees, one for each set
    BST<string> treeA, treeB, treeC;
    ifstream Read;

    // Set A
    Read.open("../data/SetA/SetA.txt");
    auto start100 = high_resolution_clock::now();
    while (!Read.eof()) {
        string email;
        Read >> email;
        treeA.insert(email);
    }
    auto stop100 = high_resolution_clock::now();
    auto duration100 = duration_cast<microseconds>(stop100-start100);
    cout << "Duration to insert 100 emails: " << duration100.count() << " microseconds." << endl;
    Read.close();

    //test search time
    Read.open("../data/SetA/canbefound.txt");
    double avgTimeForSuccessFulSearch = 0;
    while (!Read.eof()) {
        string email;
        Read >> email;
        auto start = high_resolution_clock::now();
        treeA.find(email);
        auto end = high_resolution_clock::now();
        avgTimeForSuccessFulSearch += duration_cast<microseconds>(end-start).count();
    }
    avgTimeForSuccessFulSearch /= 10;
    cout << "Average duration to search Tree A with emails that can be found " << avgTimeForSuccessFulSearch << endl;
    Read.close();

    Read.open("../data/SetA/cannotbefound.txt");
    avgTimeForSuccessFulSearch = 0;
    while (!Read.eof()) {
        string email;
        Read >> email;
        auto start = high_resolution_clock::now();
        treeA.find(email);
        auto end = high_resolution_clock::now();
        avgTimeForSuccessFulSearch += duration_cast<microseconds>(end-start).count();
    }
    avgTimeForSuccessFulSearch /= 10;

    cout << "Average duration to search Tree A with emails that cannot be found " << avgTimeForSuccessFulSearch << endl;

    Read.close();



    // Set B
    Read.open("../data/SetB/SetB.txt");
    auto start100000 = high_resolution_clock::now();
    while (!Read.eof()) {
        string email;
        Read >> email;
        treeB.insert(email);
    }
    auto stop100000 = high_resolution_clock::now();
    auto duration100000 = duration_cast<microseconds>(stop100000-start100000);
    cout << "Duration to insert 100000 emails: " << duration100000.count() << " microseconds." << endl;
    Read.close();
    //test search time
    Read.open("../data/SetB/canbefound.txt");
    avgTimeForSuccessFulSearch = 0;
    while (!Read.eof()) {
        string email;
        Read >> email;
        auto start = high_resolution_clock::now();
        treeB.find(email);
        auto end = high_resolution_clock::now();
        avgTimeForSuccessFulSearch += duration_cast<microseconds>(end-start).count();
    }
    avgTimeForSuccessFulSearch /= 10;
    cout << "Average duration to search Tree B with emails that can be found " << avgTimeForSuccessFulSearch << endl;
    Read.close();

    Read.open("../data/SetB/cannotbefound.txt");
    avgTimeForSuccessFulSearch = 0;
    while (!Read.eof()) {
        string email;
        Read >> email;
        auto start = high_resolution_clock::now();
        treeB.find(email);
        auto end = high_resolution_clock::now();
        avgTimeForSuccessFulSearch += duration_cast<microseconds>(end-start).count();
    }

    avgTimeForSuccessFulSearch /= 10;
    cout << "Average duration to search Tree B with emails that cannot be found " << avgTimeForSuccessFulSearch << endl;
    Read.close();

    // Set C
    Read.open("../data/SetC/SetC.txt");
    auto start500000 = high_resolution_clock::now();
    while (!Read.eof()) {
        string email;
        Read >> email;
        treeC.insert(email);
    }
    auto stop500000 = high_resolution_clock::now();
    auto duration500000 = duration_cast<microseconds>(stop500000-start500000);
    cout << "Duration to insert 500000 emails: " << duration500000.count() << endl;
    Read.close();

    Read.open("../data/SetC/canbefound.txt");
    avgTimeForSuccessFulSearch = 0;
    while (!Read.eof()) {
        string email;
        Read >> email;
        auto start = high_resolution_clock::now();
        treeC.find(email);
        auto end = high_resolution_clock::now();
        avgTimeForSuccessFulSearch += duration_cast<microseconds>(end-start).count();
    }

    avgTimeForSuccessFulSearch /= 10;
    cout << "Average duration to search Tree C with emails that can be found " << avgTimeForSuccessFulSearch << endl;
    Read.close();
    // treeC.display();

    Read.open("../data/SetC/cannotbefound.txt");
    avgTimeForSuccessFulSearch = 0;
    while (!Read.eof()) {
        string email;
        Read >> email;
        auto start = high_resolution_clock::now();
        treeC.find(email);
        auto end = high_resolution_clock::now();
        avgTimeForSuccessFulSearch += duration_cast<microseconds>(end-start).count();
    }
    avgTimeForSuccessFulSearch /= 10;
    cout << "Average duration to search Tree C with emails that cannot be found " << avgTimeForSuccessFulSearch << endl;
    Read.close();
}