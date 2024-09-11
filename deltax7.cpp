#include <iostream>
#include <string>
#include <vector>

// Function to generate the next ticket code based on the previous one
std::string generateNextCode(const std::string& prevCode) {
    std::string nextCode;
    int count = 1;
    char currentChar = prevCode[0];

    for (size_t i = 1; i < prevCode.size(); ++i) {
        if (prevCode[i] == currentChar) {
            ++count;
        } else {
            nextCode += std::to_string(count) + currentChar;
            currentChar = prevCode[i];
            count = 1;
        }
    }
    nextCode += std::to_string(count) + currentChar;
    return nextCode;
}

// Function to generate ticket codes up to the Nth ticket
std::vector<std::string> generateTicketCodes(int N) {
    std::vector<std::string> ticketCodes;
    if (N <= 0) return ticketCodes;

    ticketCodes.push_back("A"); // First ticket code

    for (int i = 1; i < N; ++i) {
        ticketCodes.push_back(generateNextCode(ticketCodes.back()));
    }

    return ticketCodes;
}

int main() {
    int N;
    std::cout << "Enter the number of tickets: ";
    std::cin >> N;

    std::vector<std::string> ticketCodes = generateTicketCodes(N);

    for (int i = 0; i < N; ++i) {
        std::cout << "Ticket #" << (i + 1) << ": " << ticketCodes[i] << std::endl;
    }

    return 0;
}
