#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

int getCelebrity(vector<vector<int>> &M) {
    int n = M.size();
    stack<int> s;

    // Push all candidates onto the stack
    for (int i = 0; i < n; i++) {
        s.push(i);
    }

    // Find the potential celebrity
    while (s.size() > 1) {
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();

        if (M[a][b] == 1) {
            // a knows b, so a cannot be a celebrity
            s.push(b);
        } else {
            // a does not know b, so b cannot be a celebrity
            s.push(a);
        }
    }


    // Check if the remaining candidate is a celebrity
    int candidate = s.top();
    s.pop();
    for (int i = 0; i < n; i++) {
        if (i != candidate && (M[candidate][i] == 1 || M[i][candidate] == 0)) {
            return -1; // Not a celebrity
        }
    }

    return candidate; // Found the celebrity
}

int main() {
    vector<vector<int>> M = {
        {0, 1, 0},
        {0, 0, 0},
        {1, 1, 0}
    };

    int celebrity = getCelebrity(M);
    if (celebrity != -1) {
        cout << "Celebrity found at index: " << celebrity << endl;
    } else {
        cout << "No celebrity found." << endl;
    }

    return 0;
}