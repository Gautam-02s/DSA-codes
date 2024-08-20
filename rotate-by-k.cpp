#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void rotateArray(vector<int>& arr, int d) {
    int n = arr.size();
    d = d % n;  // In case d > n
    reverse(arr.begin(), arr.begin() + d);
    reverse(arr.begin() + d, arr.end());
    reverse(arr.begin(), arr.end());
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    int d = 2;
    rotateArray(arr, d);

    for (int num : arr) {
        cout << num << " ";
    }
    return 0;
}



