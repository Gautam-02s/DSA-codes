#include <iostream>
#include <vector>
using namespace std;

int countCombinations(int N, int K, vector<int>& A) {
    // Create a dp array initialized with 0s, with size (K + 1)
    vector<int> dp(K + 1, 0);
    
    // Base case: There is 1 way to get sum 0 (by using no elements)
    dp[0] = 1;

    // Process each element in the array A[]
    for(int i = 0; i < N; i++) {
        // Update dp array from the back to avoid over-counting
        for(int j = K; j >= A[i]; j--) {
            dp[j] += dp[j - A[i]];
        }
    }
    
    // The answer is stored in dp[K], the number of ways to sum up to K
    return dp[K];
}

int main() {
    // Input handling
    int N, K;
    cin >> N >> K;
    
    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    // Get the result
    int result = countCombinations(N, K, A);
    
    // Output the result
    cout << result << endl;
    
    return 0;
}

