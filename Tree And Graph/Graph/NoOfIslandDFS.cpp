#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    // Not Diagonal

    // int row[4] = {-1, 1, 0, 0};
    // int col[4] = {0, 0, -1, 1};

    // Diagonal
    
    int row[8] = {-1, -1, -1, 1, 1, 1, 0, 0};
    int col[8] = {-1, 0, 1, -1, 0, 1, -1, 1};

    int r, c;

    void dfs(int i, int j, vector<vector<char>> &grid)
    {
        if (i < 0 || i >= r || j < 0 || j >= c || grid[i][j] != '1')
            return;

        grid[i][j] = '2'; // Mark as visited


        
    // Diagonal
        for (int k = 0; k < 8; k++)
        {
            dfs(i + row[k], j + col[k], grid);
        }


        
    //  Non-Diagonal
        // for (int k = 0; k < 4; k++)
        // {
        //     dfs(i + row[k], j + col[k], grid);
        // }
    }

    int numIslands(vector<vector<char>> &grid)
    {
        if (grid.empty())
            return 0;

        r = grid.size();
        c = grid[0].size();

        int count = 0;

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (grid[i][j] == '1')
                {
                    count++;

                    dfs(i, j, grid);
                }
            }
        }

        return count;
    }
};

int main()
{
    Solution obj;

    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}};

    cout << "Number of Islands: " << obj.numIslands(grid) << endl;

    return 0;
}
