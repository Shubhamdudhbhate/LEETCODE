#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Cell {
    int x, y, dist; // x and y are coordinates, dist is move count
};

bool isInsideBoard(int x, int y, int N) {
    return (x >= 0 && x < N && y >= 0 && y < N);
}


int knightWalk(int N, int srcX, int srcY, int destX, int destY) {
    // If source is same as destination
    if (srcX == destX && srcY == destY) 
        return 0;

    // 8 possible movements of a knight(horse)
    int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};


    //  up down left right

    vector<vector<bool>> visited(N, vector<bool>(N, false));
    queue<Cell> q;

    // Start from source
    q.push({srcX, srcY, 0});
    visited[srcX][srcY] = true;

    while (!q.empty()) {
        Cell curr = q.front();
        q.pop();

        // Try all 8 possible knight moves
        for (int i = 0; i < 8; i++) {
            int newX = curr.x + dx[i];
            int newY = curr.y + dy[i];

            if (isInsideBoard(newX, newY, N) && !visited[newX][newY]) {
                visited[newX][newY] = true;
                q.push({newX, newY, curr.dist + 1});

                if (newX == destX && newY == destY)
                    return curr.dist + 1;
            }
        }
    }

    // If destination cannot be reached
    return -1;
}


int main() {
    int N = 8; // 8x8 chessboard
    int srcX = 0, srcY = 0;
    int destX = 7, destY = 7;

    int steps = knightWalk(N, srcX, srcY, destX, destY);
    cout << "Minimum moves: " << steps << endl;

    return 0;
}

