#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int ar[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> ar[i][j];
        }
    }

    int rows = 0, rowe = n - 1, cols = 0, cole = m - 1;

    while (rows <= rowe && cols <= cole) {
        // row start
        for (int c = cols; c <= cole; c++) {
            cout << ar[rows][c] << " ";
        }
        rows++;

        // col end
        for (int r = rows; r <= rowe; r++) {
            cout << ar[r][cole] << " ";
        }
        cole--;

        // row end
        if (rows <= rowe) {
            for (int c = cole; c >= cols; c--) {
                cout << ar[rowe][c] << " ";
            }
            rowe--;
        }

        // col start
        if (cols <= cole) {
            for (int r = rowe; r >= rows; r--) {
                cout << ar[r][cols] << " ";
            }
            cols++;
        }
    }
    return 0;
}
