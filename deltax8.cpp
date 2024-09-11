#include <iostream>
#include <vector>

using namespace std;

// Function to calculate total donations
int calculateDonations(const vector<int>& donations) {
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
    for (int i = 0; i < N; ++i) {
        cin >> donations[i];
    }

    // Calculate the total donation amount
    int totalDonation = calculateDonations(donations);
    
    // Output the result
    cout << "Total Donations Collected: " << totalDonation << endl;

    return 0;
}
