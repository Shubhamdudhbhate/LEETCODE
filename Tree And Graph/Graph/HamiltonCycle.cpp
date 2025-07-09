#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, int start, int count, vector<int> &visited, vector<vector<int>> &adj, int n) {
    if (count == n) {
        // Check if there's a back edge to form a cycle
        for (int neighbor : adj[node]) {
            if (neighbor == start)
                return true;
        }
        return false;
    }

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            visited[neighbor] = 1;
            if (dfs(neighbor, start, count + 1, visited, adj, n))
                return true;
            visited[neighbor] = 0; // backtrack
        }
    }
    return false;
}

bool hasHamiltonianCycle(int n, vector<vector<int>> &adj) {
    vector<int> visited(n, 0);

    for (int start = 0; start < n; ++start) {
        visited[start] = 1;
        if (dfs(start, start, 1, visited, adj, n))
            return true;
        visited[start] = 0;
    }
    return false;
}


int main() {
    int n = 4;
    vector<vector<int>> adj(n);

    // Create undirected graph
    adj[0] = {1, 3};
    adj[1] = {0, 2};
    adj[2] = {1, 3};
    adj[3] = {0, 2};

    if (hasHamiltonianCycle(n, adj))
        cout << "Hamiltonian Cycle Exists ✅\n";
    else
        cout << "No Hamiltonian Cycle ❌\n";

    return 0;
}
