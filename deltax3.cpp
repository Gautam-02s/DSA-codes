#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Function to check if a character is a valid email character
bool isValidEmailChar(char c) {
    return (isalnum(c) || c == '.' || c == '-' || c == '_');
}

// Function to validate email
bool isValidEmail(const string& email) {
    int atPos = -1, dotPos = -1;
    int n = email.length();

    // Check for '@' and '.'
    for (int i = 0; i < n; ++i) {
        if (email[i] == '@') {
            if (atPos == -1) {
                atPos = i;
            } else {
                return false; // More than one '@'
            }
        } else if (email[i] == '.') {
            dotPos = i;
        } else if (!isValidEmailChar(email[i])) {
            return false; // Invalid character
        }
    }

    // Check positions of '@' and '.'
    if (atPos == -1 || dotPos == -1 || atPos > dotPos || atPos == 0 || dotPos == n - 1) {
        return false;
    }

    return true;
}

int main() {
    int n;
    cin >> n;
    vector<string> emails(n);

    // Input email addresses
    for (int i = 0; i < n; ++i) {
        cin >> emails[i];
    }

    // Validate each email
    for (const string& email : emails) {
        if (isValidEmail(email)) {
            cout << "True" << endl;
        } else {
            cout << "False" << endl;
        }
    }

    return 0;
}
