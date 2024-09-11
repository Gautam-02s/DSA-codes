#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

// Function to convert a Roman numeral to decimal
int romanToDecimal(string roman) {
    unordered_map<char, int> romanMap = {
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
        {'C', 100}, {'D', 500}, {'M', 1000}
    };
    
    int n = roman.length();
    int result = 0;
    
    for (int i = 0; i < n; i++) {
        // If the current value is less than the next value, we subtract it
        if (i + 1 < n && romanMap[roman[i]] < romanMap[roman[i + 1]]) {
            result -= romanMap[roman[i]];
        } else {
            result += romanMap[roman[i]];
        }
    }
    
    return result;
}

// Function to check if the string is a valid Roman numeral
bool isValidRoman(string roman) {
    // Valid Roman numeral characters
    string validChars = "IVXLCDM";
    
    // Check for invalid characters
    for (char c : roman) {
        if (validChars.find(c) == string::npos) {
            return false;
        }
    }

    // Rules for Roman numeral correctness
    unordered_map<char, int> romanMap = {
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
        {'C', 100}, {'D', 500}, {'M', 1000}
    };
    
    int n = roman.length();
    for (int i = 0; i < n - 1; i++) {
        // Rule: A smaller number can only be placed before larger numbers if it's I, X, or C
        if (romanMap[roman[i]] < romanMap[roman[i + 1]]) {
            if (roman[i] == 'I' && (roman[i + 1] == 'V' || roman[i + 1] == 'X')) {
                continue;
            } else if (roman[i] == 'X' && (roman[i + 1] == 'L' || roman[i + 1] == 'C')) {
                continue;
            } else if (roman[i] == 'C' && (roman[i + 1] == 'D' || roman[i + 1] == 'M')) {
                continue;
            } else {
                return false;
            }
        }
    }
    
    return true;
}

int main() {
    string roman;
    cout << "Enter a Roman numeral: ";
    cin >> roman;
    
    if (isValidRoman(roman)) {
        cout << "Decimal value: " << romanToDecimal(roman) << endl;
    } else {
        cout << "Invalid" << endl;
    }
    
    return 0;
}
