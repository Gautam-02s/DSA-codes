#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to calculate total donations or process input based on assumptions
int calculateDonations(vector<int>& donations) {
    // Example calculation (sum of donations)
    int total = 0;
    for (int donation : donations) {
        total += donation;
    }
    return total;
}

int main() {
    int N;
    cout << "Enter the number of donations: ";
    cin >> N; // Number of donations

    vector<int> donations(N);
    
    cout << "Enter the donations: ";
    // Input donations
    for (int i = 0; i < N; i++) {
        cin >> donations[i];
    }

    // Assuming we need to calculate the total donation amount
    int totalDonation = calculateDonations(donations);
    
    // Output result
    cout << "Total Donations Collected: " << totalDonation << endl;

    return 0;
}
