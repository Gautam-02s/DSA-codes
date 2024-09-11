#include <iostream>
#include <string>
#include <unordered_map>
#include <sstream>
#include <vector>

using namespace std;

// Function to parse query parameters from a URL
unordered_map<string, string> parseQueryParameters(const string& url) {
    unordered_map<string, string> queryParams;
    size_t pos = url.find('?');
    if (pos == string::npos) {
        return queryParams;
    }

    string query = url.substr(pos + 1);
    istringstream queryStream(query);
    string pair;

    while (getline(queryStream, pair, '&')) {
        size_t eqPos = pair.find('=');
        if (eqPos != string::npos) {
            string key = pair.substr(0, eqPos);
            string value = pair.substr(eqPos + 1);
            queryParams[key] = value;
        }
    }

    return queryParams;
}

int main() {
    string url;
    cout << "Enter URL: ";
    getline(cin, url);

    int n;
    cout << "Enter number of query parameters to find: ";
    cin >> n;
    cin.ignore(); // Ignore the newline character after the integer input

    vector<string> keys(n);
    cout << "Enter the query parameter keys:" << endl;
    for (int i = 0; i < n; ++i) {
        getline(cin, keys[i]);
    }

    unordered_map<string, string> queryParams = parseQueryParameters(url);

    for (const auto& key : keys) {
        if (queryParams.find(key) != queryParams.end()) {
            cout << key << ": " << queryParams[key] << endl;
        } else {
            cout << key << ": -1" << endl;
        }
    }

    return 0;
}
