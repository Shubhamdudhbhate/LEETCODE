#include <bits/stdc++.h>
using namespace std;

// DFS function to check all paths
bool dfs(int node, int count, vector<int> &visited, vector<vector<int>> &adj, int n) {
    if (count == n) return true;

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            visited[neighbor] = 1;
            if (dfs(neighbor, count + 1, visited, adj, n))
                return true;
            visited[neighbor] = 0; // backtrack
        }
    }
    return false;
}

// Main function to test all possible starting points
bool hasHamiltonianPath(int n, vector<vector<int>> &adj) {
    vector<int> visited(n, 0);

    for (int start = 0; start < n; ++start) {
        visited[start] = 1;
        if (dfs(start, 1, visited, adj, n))
            return true;
        visited[start] = 0;
    }
    return false;
}

// Main program
int main() {
    int n, m;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;

    vector<vector<int>> adj(n);

    cout << "Enter " << m << " edges (u v):\n";
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        // Assuming 0-based indexing
        adj[u].push_back(v);
        adj[v].push_back(u); // remove this line for directed graph
    }

    if (hasHamiltonianPath(n, adj))
        cout << "Hamiltonian Path Exists ✅\n";
    else
        cout << "No Hamiltonian Path ❌\n";

    return 0;
}
