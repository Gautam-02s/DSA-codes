#include <iostream>
#include <vector>
using namespace std;

// Function to count the number of combinations to sum up to K using elements from A
int countCombinations(int N, int K, const vector<int>& A) {
    // Create a dp array initialized with 0s, with size (K + 1)
    vector<int> dp(K + 1, 0);
    
    // Base case: There is 1 way to get sum 0 (by using no elements)
    dp[0] = 1;

    // Process each element in the array A[]
    for(int i = 0; i < N; ++i) {
        // Update dp array from the back to avoid over-counting
        for(int j = K; j >= A[i]; --j) {
            dp[j] += dp[j - A[i]];
        }
    }
    
    // The answer is stored in dp[K], the number of ways to sum up to K
    return dp[K];
}

int main() {
    int N, K;
    cout << "Enter number of elements and target sum: ";
    cin >> N >> K;

    if (N <= 0 || K < 0) {
        cout << "Invalid input." << endl;
        return 1;
    }

    vector<int> A(N);
    cout << "Enter the elements: ";
    for(int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    int result = countCombinations(N, K, A);
    
    cout << "Number of ways to achieve sum " << K << ": " << result << endl;
    
    return 0;
}
