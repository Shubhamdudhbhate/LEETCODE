#include <iostream>
#include <climits>
using namespace std;

int main() {
    int mat[10][10];
    int rows, cols;

    cout << "Enter number of rows and columns (max 10): ";
    cin >> rows >> cols;

    // 1. Input
    cout << "Enter elements of 2D array:\n";
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            cin >> mat[i][j];

    // 2. Display
    cout << "\n2D Array:\n";
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }

    // 3. Search
    int key;
    cout << "\nEnter element to search: ";
    cin >> key;
    bool found = false;
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            if(mat[i][j] == key) {
                cout << "Found at (" << i << ", " << j << ")\n";
                found = true;
            }
    if (!found) cout << "Element not found.\n";

    // 4. Insert/Update
    int r, c, val;
    cout << "\nEnter row, column and value to insert/update: ";
    cin >> r >> c >> val;
    if(r >= 0 && r < rows && c >= 0 && c < cols) {
        mat[r][c] = val;
    } else {
        cout << "Invalid position.\n";
    }

    // 5. Delete (set to -1)
    cout << "\nEnter row and column to delete (set to -1): ";
    cin >> r >> c;
    if(r >= 0 && r < rows && c >= 0 && c < cols) {
        mat[r][c] = -1;
    } else {
        cout << "Invalid position.\n";
    }

    // Updated display
    cout << "\nUpdated 2D Array:\n";
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }

    // 6. Row-wise Sum
    cout << "\nRow-wise Sum:\n";
    for(int i = 0; i < rows; i++) {
        int sum = 0;
        for(int j = 0; j < cols; j++)
            sum += mat[i][j];
        cout << "Row " << i << " sum = " << sum << endl;
    }

    // 7. Column-wise Sum
    cout << "\nColumn-wise Sum:\n";
    for(int j = 0; j < cols; j++) {
        int sum = 0;
        for(int i = 0; i < rows; i++)
            sum += mat[i][j];
        cout << "Column " << j << " sum = " << sum << endl;
    }

    // 8. Transpose
    cout << "\nTranspose of Matrix:\n";
    for(int j = 0; j < cols; j++) {
        for(int i = 0; i < rows; i++)
            cout << mat[i][j] << " ";
        cout << endl;
    }

    // 9. Find Max and Min
    int maxVal = INT_MIN, minVal = INT_MAX;
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++) {
            if(mat[i][j] > maxVal) maxVal = mat[i][j];
            if(mat[i][j] < minVal) minVal = mat[i][j];
        }
    cout << "\nMaximum element = " << maxVal << endl;
    cout << "Minimum element = " << minVal << endl;

    // 10. Total sum
    int totalSum = 0;
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            totalSum += mat[i][j];
    cout << "Total sum of all elements = " << totalSum << endl;


 // diagonal sum
    int diagonalSum = 0;    
    cout << "\nDiagonal Sum:\n";
    for(int i = 0; i < rows && i < cols; i++) {
        diagonalSum += mat[i][i];
    }
    cout << "Diagonal sum = " << diagonalSum << endl; 
     














    return 0;
}
