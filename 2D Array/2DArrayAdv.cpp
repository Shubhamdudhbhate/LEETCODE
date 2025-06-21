#include <iostream>
#include <vector>
using namespace std;

bool BinarySearch(const vector<vector<int>> &vec, int key)
{
    if (vec.empty() || vec[0].empty())
        return false;

    int rows = vec.size();
    int cols = vec[0].size(); // proper column count
    int low = 0, high = rows * cols - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        int i = mid / cols; // row index   most imp
        int j = mid % cols; // col index   most imp

        if (vec[i][j] == key)
        {
            cout << "Elements found at position: (" << i << ", " << j << ")" << endl;
            return true;
        }
        else if (vec[i][j] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    cout << "Element not found.\n";
    return false;
}

bool SearchMatrix(vector<vector<int>> &vec, int key)
{

    int row = vec.size(), col = vec[0].size();

    int r = 0, c = col - 1;

    while (r < row && c >= 0)
    {
        if (key == vec[r][c])
        {
            cout << " \nElements found at position : " << "(" << r << "," << c << ")" << endl;
            return true;
        }
        else if (key < vec[r][c])
        {

            c--;
        }
        else
        {
            r++;
        }
    }

    return false;
}

void spiralPrint(const vector<vector<int>> &matrix)
{
    if (matrix.empty() || matrix[0].empty())
    {
        return;
    }

    int top = 0;
    int bottom = matrix.size() - 1;
    int left = 0;
    int right = matrix[0].size() - 1;

    cout << "Spiral Order: ";

    while (top <= bottom && left <= right)
    {

        for (int col = left; col <= right; col++)
        {
            cout << matrix[top][col] << " ";
        }
        top++;

        for (int row = top; row <= bottom; row++)
        {
            cout << matrix[row][right] << " ";
        }
        right--;

        if (top <= bottom)
        {
            for (int col = right; col >= left; col--)
            {
                cout << matrix[bottom][col] << " ";
            }
            bottom--;
        }

        if (left <= right)
        {
            for (int row = bottom; row >= top; row--)
            {
                cout << matrix[row][left] << " ";
            }
            left++;
        }
    }

    cout << endl;
}

int main()
{
    vector<vector<int>> vec = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
        {10, 11, 12},
        {13, 14, 15}};

    vector<vector<int>> matrix = {
        {1, 2, 3},
        {12, 13, 4},
        {11, 14, 5},
        {10, 15, 6},
        {9, 8, 7}};

    // int key = 6;
    cout << "Hello\n";
    BinarySearch(vec, 6);
    SearchMatrix(vec, 15);
    spiralPrint(matrix);

    return 0;
}
