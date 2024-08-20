#include <iostream>
#include <sstream>
using namespace std;

int main() {
    string str = "C++ is a powerful language";
    stringstream ss(str);
    string word;
    while (ss >> word) {
        cout << word << endl;
    }
}
