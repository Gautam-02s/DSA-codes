#include <iostream>
#include <string>
#include <cctype>

bool isValidPhoneNumber(const std::string& number) {
    // Check if the number starts with +91, 0, 7, 8, or 9
    if (number.substr(0, 3) == "+91" || number[0] == '0' || number[0] == '7' || number[0] == '8' || number[0] == '9') {
        // Remove spaces and check if the rest of the number is digits only
        std::string digitsOnly;
        for (char c : number) {
            if (std::isdigit(c)) {
                digitsOnly += c;
            } else if (c != ' ' && c != '+') {
                return false; // Invalid character found
            }
        }
        // Check the length of the number excluding prefix and spaces
        if (digitsOnly.length() == 10) {
            return true;
        }
    }
    return false;
}

int main() {
    std::string phoneNumber;
    std::cout << "Enter phone number: ";
    std::getline(std::cin, phoneNumber);

    if (isValidPhoneNumber(phoneNumber)) {
        std::cout << "Valid phone number." << std::endl;
    } else {
        std::cout << "Invalid phone number." << std::endl;
    }

    return 0;
}
