#include <iostream>
using namespace std;

int main() {
    int n, m, key;
    cin >> n >> m;
    int ar[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> ar[i][j];
        }
    }

    cin >> key;  // Input the key to be searched

    int l = 0, r = m - 1;
    while (l < n && r >= 0) {
        if (ar[l][r] == key) {
            cout << "Key found at position (" << l << ", " << r << ")" << endl;
            return 0;
        }
        else if (ar[l][r] > key) {
            r--;  // Move left
        }
        else {
            l++;  // Move down
        }
    }

    cout << "Key not found" << endl;
    return 0;
}
