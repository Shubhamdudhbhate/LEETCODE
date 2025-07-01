
#include <iostream>
#include <vector>

#include <queue>
using namespace std;

class Solution
{
public:
    int row[4] = {-1, 1, 0, 0}; // Up, Down
    int col[4] = {0, 0, -1, 1}; // Left, Right
    int r, c;

    void bfs(int i, int j, vector<vector<char>> &grid)
    {
        queue<pair<int, int>> q;
        q.push({i, j});
        grid[i][j] = '2'; // Mark as visited

        while (!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
              q.pop();
              
            for (int k = 0; k < 4; k++)
            {
                int newRow = x + row[k];
                int newCol = y + col[k];

                if (newRow >= 0 && newRow < r &&
                    newCol >= 0 && newCol < c &&
                    grid[newRow][newCol] == '1')
                {

                    grid[newRow][newCol] = '2'; // Mark as visited
                    q.push({newRow, newCol});
                }
            }
        }
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
                    bfs(i, j, grid);
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
        {'1', '1', '0', '0'},
        {'1', '0', '0', '1'},
        {'0', '0', '1', '1'},
        {'1', '0', '1', '1'}};

    cout << "Number of Islands: " << obj.numIslands(grid) << endl;

    return 0;
}
