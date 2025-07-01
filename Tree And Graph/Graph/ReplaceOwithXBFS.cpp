#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int row[4] = {-1, 1, 0, 0};
    int col[4] = {0, 0, -1, 1};
    int r, c;

    void bfs(int i, int j, vector<vector<char>>& board) {
        queue<pair<int, int>> q;
        q.push({i, j});
        board[i][j] = '#'; // Temporarily mark as safe

        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (int k = 0; k < 4; k++) {
                int newRow = x + row[k];
                int newCol = y + col[k];

                if (newRow >= 0 && newRow < r &&
                    newCol >= 0 && newCol < c &&
                    board[newRow][newCol] == 'O') {
                    board[newRow][newCol] = '#';
                    q.push({newRow, newCol});
                }
            }
        }
    }

    void replaceO(vector<vector<char>>& board) {
        if (board.empty()) return;

        r = board.size();
        c = board[0].size();

        // Step 1: Traverse boundary and run BFS from 'O's
        for (int i = 0; i < r; i++) {
            if (board[i][0] == 'O') bfs(i, 0, board);
            if (board[i][c - 1] == 'O') bfs(i, c - 1, board);
        }

        for (int j = 0; j < c; j++) {
            if (board[0][j] == 'O') bfs(0, j, board);
            if (board[r - 1][j] == 'O') bfs(r - 1, j, board);
        }

        // Step 2: Replace all remaining 'O' with 'X', and '#' back to 'O'
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == '#') board[i][j] = 'O';
            }
        }
    }
};


int main() {
    Solution obj;

    vector<vector<char>> board = {
        {'X', 'X', 'X', 'O'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'},
        {'X', 'O', 'O', 'X'}
    };

    obj.replaceO(board);

    for (auto& row : board) {
        for (char ch : row)
            cout << ch << " ";
        cout << endl;
    }

    return 0;
}
