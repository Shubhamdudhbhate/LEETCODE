#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

int main()
{

    vector<vector<int>> vec = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
        {10, 11, 12,52},  // dynamic sizing of vector
        {13, 14, 15}
    
    
    };


    // Display the 2D vector
    cout << "2D vector elements:" << endl;  
    for (const auto &row : vec)
    {
        for (const auto &elem : row)
        {
            cout << elem << " ";
        }
        cout << endl;
    }



    int maxSum = INT_MIN;
    int rowidx = -1;

    for (int i = 0; i < vec.size(); i++)
    {
        int sum = 0;
        for (int j = 0; j < vec[i].size(); j++)
        {
            sum += vec[i][j];
        }

        if (sum > maxSum)
        {

            rowidx = i;
            maxSum = sum;
        }
        // maxSum = max(maxSum, sum);
    }

    cout << "Maximum sum of a row (" << rowidx << ") in the 2D vector is: " << rowidx << maxSum << endl;


    // max Column sum
    int maxColSum = INT_MIN;    

    int colidx = -1;
    for (int j = 0; j < vec[0].size(); j++)
    {
        int sum = 0;
        for (int i = 0; i < vec.size(); i++)
        {
            if (j < vec[i].size()) // Check if the column index is valid for the current row
            {
                sum += vec[i][j];
            }
        }

        if (sum > maxColSum)
        {
            colidx = j;
            maxColSum = sum;
        }
    }


    cout << "Maximum sum of a column (" << colidx << ") in the 2D vector is: " << maxColSum << endl;
 

    //Linear search in 2D vector
    int target = 52;
    bool found = false;
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[i].size(); j++)
        {
            if (vec[i][j] == target)
            {
                cout << "Element " << target << " found at position (" << i << ", " << j << ")." << endl;
                found = true;
                break; // Exit the inner loop if the element is found
            }
        }
        if (found)
            break; // Exit the outer loop if the element is found
    }


    if (!found)
    {
        cout << "Element " << target << " not found in the 2D vector." << endl;
    }



    return 0;
}