#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canPlaceRooms(const vector<int>& A, int N, int K, int mid) {
    int count = 1, last_position = A[0];
    for (int i = 1; i < N; ++i) {
        if (A[i] - last_position >= mid) {
            count++;
            last_position = A[i];
            if (count == K) {
                return true;
            }
        }
    }
    return false;
}

int largestMinDistance(int N, int K, vector<int>& A) {
    sort(A.begin(), A.end());
    int left = 1, right = A[N-1] - A[0];
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (canPlaceRooms(A, N, K, mid)) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return right;
}

int main() {
    int N = 5, K = 3;
    vector<int> A = {1, 2, 4, 8, 9};
    cout << largestMinDistance(N, K, A) << endl;  // Output: 3
    return 0;
}
