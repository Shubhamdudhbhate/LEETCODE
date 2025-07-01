#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int n, m;
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    void dfs(int x, int y, vector<vector<char>>& board) {
        board[x][y] = '#';

        for (int d = 0; d < 4; d++) {
            int newX = x + dx[d];
            int newY = y + dy[d];

            if (newX >= 0 && newX < n &&
                newY >= 0 && newY < m &&
                board[newX][newY] == 'O') {
                dfs(newX, newY, board);
            }
        }
    }

    void replaceO(vector<vector<char>>& board) {
        if (board.empty()) return;

        n = board.size();
        m = board[0].size();

        // Step 1: Boundary DFS
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O') dfs(i, 0, board);
            if (board[i][m - 1] == 'O') dfs(i, m - 1, board);
        }
        for (int j = 0; j < m; j++) {
            if (board[0][j] == 'O') dfs(0, j, board);
            if (board[n - 1][j] == 'O') dfs(n - 1, j, board);
        }

        // Step 2: Replace remaining 'O' with 'X', and '#' back to 'O'
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == '#') board[i][j] = 'O';
            }
        }
    }
};

int main() {
    Solution obj;

    vector<vector<char>> board = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}
    };

    obj.replaceO(board);

    for (auto& row : board) {
        for (char ch : row)
            cout << ch << " ";
        cout << endl;
    }

    return 0;
}
