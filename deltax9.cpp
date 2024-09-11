#include <iostream>
#include <string>

void jsonFormatter(const std::string &json) {
    int indentLevel = 0;
    std::string indent = "**"; // represents a unit of indentation
    bool insideQuotes = false; // to track whether we are inside a string

    for (size_t i = 0; i < json.size(); i++) {
        char c = json[i];

        // Check if the current character is a quote to toggle insideQuotes
        if (c == '\"') {
            std::cout << c;
            insideQuotes = !insideQuotes;
            continue;
        }

        // If inside quotes, just print characters as they are
        if (insideQuotes) {
            std::cout << c;
            continue;
        }

        // Handle opening braces
        if (c == '{' || c == '[') {
            std::cout << c;
            std::cout << "\n";
            indentLevel++;
            for (int j = 0; j < indentLevel; j++) {
                std::cout << indent;
            }
        }
        // Handle closing braces
        else if (c == '}' || c == ']') {
            std::cout << "\n";
            indentLevel--;
            for (int j = 0; j < indentLevel; j++) {
                std::cout << indent;
            }
            std::cout << c;
        }
        // Handle commas
        else if (c == ',') {
            std::cout << c;
            std::cout << "\n";
            for (int j = 0; j < indentLevel; j++) {
                std::cout << indent;
            }
        }
        // Handle other characters (inside braces or array)
        else {
            std::cout << c;
        }
    }
}

int main() {
    std::string input1 = "{\"name\":\"John\",\"email\":\"john.dg@gmail.com\"}";
    std::string input2 = "{\"name\":\"John\",\"friends\":[\"Joe\",\"Jerry\"]}";

    std::cout << "Formatted Output 1:\n";
    jsonFormatter(input1);
    std::cout << "\n\nFormatted Output 2:\n";
    jsonFormatter(input2);

    return 0;
}
