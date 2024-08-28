#include <iostream>
#include <stack>
using namespace std;

void reverse(string s) {
    stack<string> st;
    string word = "";
    
    for (int i = 0; i < s.length(); i++) {
        // Check if current character is not a space
        if (s[i] != ' ') {
            word += s[i]; // Append character to the current word
        } else {
            if (!word.empty()) {
                st.push(word); // Push the word to the stack
                word = ""; // Clear the word
            }
        }
    }
    
    // Push the last word if it's not empty
    if (!word.empty()) {
        st.push(word);
    }

    // Print the reversed words
    while (!st.empty()) {
        cout << st.top() << " "; // Print the top word
        st.pop(); // Remove the top word
    }
    cout << endl;
}

int main() {
    string s = "Hey there! Gautam Sharma this side";
    reverse(s);
    return 0;
}
