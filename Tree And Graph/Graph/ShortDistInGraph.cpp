#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

class shortDist
{

public:
    int row[4] = {1, -1, 0, 0};
    int col[4] = {0, 0, 1, -1};

    bool valid(int i, int j, int n, int m)
    {
        return i >= 0 && i < n && j >= 0 && j < m;
    }

    int shortDistance(int N, int M, vector<vector<int>> A, int x, int y)
    { // N row    M col

        if (x == 0 && y == 0)
            return 0;

        if (!A[0][0])
            return -1;

        queue<pair<int, int>> q;
        q.push({0, 0});

        A[0][0] = 0;
        int step = 0;

        while (!q.empty())
        {

            int count = q.size();

            while (count--)
            {

                int i = q.front().first;  // row
                int j = q.front().second; // col

                q.pop();

                for (int k = 0; k < 4; k++)
                {
                    int new_i = i + row[k];
                    int new_j = j + col[k];

                    if (valid(new_i, new_j, N, M) && A[new_i][new_j] /*&& !visited[new_i][new_j]*/)
                    {
                        if (new_i == x && new_j == y)
                            return step + 1;

                        // visited[new_i][new_j] = 1;
                        A[new_i][new_j] = 0;
                        q.push({new_i, new_j});
                    }
                }
            }

            step++;
        }

        return -1;
    }
};

int main()
{
    vector<vector<int>> grid = {
        {1, 1, 1},
        {0, 0, 1},
        {1, 1, 1}};

    shortDist obj;
    int N = 3, M = 3;
    int dest_x = 3, dest_y = 1;

    int result = obj.shortDistance(N, M, grid, dest_x-1, dest_y-1);

    if (result != -1)
        cout << "Minimum steps to reach (" << dest_x << "," << dest_y << ") = " << result << endl;
    else
        cout << "Destination not reachable." << endl;

    return 0;
}
