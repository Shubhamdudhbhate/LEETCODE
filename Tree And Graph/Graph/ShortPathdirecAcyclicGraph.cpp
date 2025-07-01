#include <iostream>
#include <vector>
#include <stack>
#include <climits>
using namespace std;

typedef pair<int, int> pii;

// DFS for topological sorting
void topoSortDFS(int node, vector<vector<pii>> &adj, vector<bool> &visited, stack<int> &st) {
    visited[node] = true;

    for (auto edge : adj[node]) {
        int neighbor = edge.first;
        if (!visited[neighbor])
            topoSortDFS(neighbor, adj, visited, st);
    }

    st.push(node); // Push to stack after visiting all descendants
}

// DAG Shortest Path using DFS-based Topo Sort
void shortestPathDAG(int V, vector<vector<pii>> &adj, int src) {
    vector<bool> visited(V, false);
    stack<int> topo;

    // Step 1: Topological sort
    for (int i = 0; i < V; ++i) {
        if (!visited[i])
            topoSortDFS(i, adj, visited, topo);
    }

    // Step 2: Initialize distances
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    // Step 3: Relax nodes in topological order
    while (!topo.empty()) {
        int u = topo.top(); topo.pop();

        if (dist[u] != INT_MAX) { // Only process reachable nodes |u|---w-->|v|
            for (auto edge : adj[u]) {
                int v = edge.first;
                int w = edge.second;
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                }
            }
        }
    }

    // Step 4: Print result
    for (int i = 0; i < V; ++i) {
        cout << "Shortest distance from " << src << " to " << i << " = ";
        if (dist[i] == INT_MAX)
            cout << "∞" << endl;
        else
            cout << dist[i] << endl;
    }
}




 /*     0 
      /   \
     1     2
    /    / 
   3->5  
     /
    7
   /
  6     inthis case dry run   */




int main() {

int V = 7;
vector<vector<pair<int, int>>> adj(V);


    // DAG: u -> v with weight w
adj[0].push_back({1, 2});   // 0 → 1 (weight 2)
adj[0].push_back({2, 3});   // 0 → 2 (weight 3)
adj[1].push_back({3, 1});   // 1 → 3 (weight 1)
adj[2].push_back({3, 4});   // 2 → 3 (weight 4)
adj[3].push_back({5, 1});   // 3 → 5 (weight 1)
adj[5].push_back({7, 2});   // 5 → 7 (weight 2)
adj[7].push_back({6, 1});   // 7 → 6 (weight 1)

//0, 2, 1, 3, 5, 7, 6 stack


    int src = 0;
    shortestPathDAG(V, adj, src);

    return 0;
}

