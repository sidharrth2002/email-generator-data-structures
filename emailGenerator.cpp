#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <random>
using namespace std;

void generateRandomLetter();
void shuffleList();
void loadValues();
void generateEmails(int num);

//stores all possible characters including letters and numbers
vector<char> possibleCharsAll;
//stores only letters
vector<char> possibleLetters;
//.com or .net or .org
vector<string> extensions;
//stores generated emails
vector<string> emails;

int main() {
    ofstream Write;

    //load possible values
    loadValues();

    //initial shuffle
    shuffleList();
    srand(time(NULL));

    //Set A
    cout << "Generating first set of 100 emails" << endl;
    generateEmails(100);

    //Set B
    cout << "Generating second set of 100000 emails" << endl;
    generateEmails(100000);

    //Set C
    cout << "Generating third set of 500000 emails" << endl;
    generateEmails(500000);

    Write.open("SetA.txt");
    for(int k = 0; k < 100; ++k) {
        cout << k << endl;
        cout << emails[k] << endl;
        Write << emails[k] << endl;
    }
    Write.close();

    emails.erase(emails.begin(), emails.begin() + 100);

    // //Set B
    Write.open("SetB.txt");
    for(int k=0; k<100000; ++k) {
        cout<<emails[k] << endl;
        Write << emails[k] << endl;
    }
    Write.close();

    emails.erase(emails.begin(), emails.begin() + 100000);

    // //Set C
    Write.open("SetC.txt");
    for(int k=0; k<500000; ++k) {
        cout<<emails[k] << endl;
        Write << emails[k] << endl;
    }
    Write.close();
}

//loading values
void loadValues() {
    for (int i = 48; i <= 57; i++) {
        possibleCharsAll.push_back((char)i);
    }
    for (int i = 65; i <= 90; i++) {
        possibleCharsAll.push_back((char)i);
        possibleLetters.push_back((char)i);
    }
    for (int i = 97; i <= 122; i++) {
        possibleCharsAll.push_back((char)i);
        possibleLetters.push_back((char)i);
    }
    extensions.push_back("com");
    extensions.push_back("net");
    extensions.push_back("org");
}

//shuffles list of possible characters
void shuffleList() {
    default_random_engine e(chrono::system_clock::now().time_since_epoch().count());
    shuffle(possibleCharsAll.begin(), possibleCharsAll.end(), e);
    shuffle(possibleLetters.begin(), possibleLetters.end(), e);
}

//generates emails randomly
void generateEmails(int num) {
    for (int k = 0; k < num; ++k) {
        string email;
        for(int i = 0; i < 5; ++i) {
            email += possibleCharsAll[rand() % possibleCharsAll.size() - 1];
        }
        email += ".";
        for(int i = 0; i < 5; ++i) {
            email += possibleCharsAll[rand() % possibleCharsAll.size() - 1];
        }
        email += "@";
        for (int j = 0; j < 5; ++j) {
            email += possibleLetters[rand() % possibleLetters.size() - 1];
        }
        email += ".";
        email += extensions[rand() % 3];

        emails.push_back(email);
    }
}
