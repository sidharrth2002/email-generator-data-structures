#include <iostream>
#include <fstream>
using namespace std;

int main() {
  ifstream Read;
  Read.open("SetB.txt");
  while (!Read.eof()) {
    string email;
    Read >> email;
    if (email.length() != 21) {
      cout << "flag bitch" << endl;
      cout << email << endl;
    }
  }
}
