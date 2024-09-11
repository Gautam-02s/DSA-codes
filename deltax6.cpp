#include <iostream>
#include <string>
#include <unordered_map>
#include <sstream>

// Function to parse query parameters from a URL
std::unordered_map<std::string, std::string> parseQueryParameters(const std::string& url) {
    std::unordered_map<std::string, std::string> queryParams;
    std::size_t pos = url.find('?');
    if (pos == std::string::npos) {
        return queryParams;
    }

    std::string query = url.substr(pos + 1);
    std::istringstream queryStream(query);
    std::string pair;

    while (std::getline(queryStream, pair, '&')) {
        std::size_t eqPos = pair.find('=');
        if (eqPos != std::string::npos) {
            std::string key = pair.substr(0, eqPos);
            std::string value = pair.substr(eqPos + 1);
            queryParams[key] = value;
        }
    }

    return queryParams;
}

int main() {
    std::string url;
    std::cout << "Enter URL: ";
    std::getline(std::cin, url);

    int n;
    std::cout << "Enter number of query parameters to find: ";
    std::cin >> n;
    std::cin.ignore(); // Ignore the newline character after the integer input

    std::vector<std::string> keys(n);
    std::cout << "Enter the query parameter keys:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::getline(std::cin, keys[i]);
    }

    std::unordered_map<std::string, std::string> queryParams = parseQueryParameters(url);

    for (const auto& key : keys) {
        if (queryParams.find(key) != queryParams.end()) {
            std::cout << key << ": " << queryParams[key] << std::endl;
        } else {
            std::cout << key << ": -1" << std::endl;
        }
    }

    return 0;
}
