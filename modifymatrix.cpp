#include <iostream>
#include <vector>
using namespace std;

void modifymatrix(vector<vector<int>> &nums) {
    int n = nums.size();
    int m = nums[0].size();
    
    vector<bool> row(n, false);
    vector<bool> col(m, false);

    // First pass: Identify the rows and columns that need to be modified
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (nums[i][j] == 1) {
                row[i] = true;
                col[j] = true;
            }
        }
    }

    // Second pass: Modify the matrix based on the row and col vectors
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (row[i] || col[j]) {
                nums[i][j] = 1;
            }
        }
    }
}

// Function to print the matrix
void printMatrix(const vector<vector<int>>& mat) {
    for (const auto& row : mat) {
        for (int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> mat = {
        {1, 0, 0},
        {0, 0, 1},
        {0, 0, 0}
    };

    cout << "Original Matrix:" << endl;
    printMatrix(mat);

    modifymatrix(mat);

    cout << "Modified Matrix:" << endl;
    printMatrix(mat);

    return 0;
}
