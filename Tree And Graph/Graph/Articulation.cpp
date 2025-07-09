#include <bits/stdc++.h>
using namespace std;

void dfs(int u, int parent, vector<int> adj[], vector<bool> &visited,
         vector<int> &tin, vector<int> &low, int &timer, set<int> &articulationPoints) {
    visited[u] = true;
    tin[u] = low[u] = timer++;
    int children = 0;

    for (int v : adj[u]) {
        if (v == parent) continue;

        if (!visited[v]) {
            dfs(v, u, adj, visited, tin, low, timer, articulationPoints);
            low[u] = min(low[u], low[v]);

            if (low[v] >= tin[u] && parent != -1)
                articulationPoints.insert(u);

            children++;
        } else {
            // back edge
            low[u] = min(low[u], tin[v]);
        }
    }

    // Special case for root
    if (parent == -1 && children > 1)
        articulationPoints.insert(u);
}

vector<int> tarjansArticulationPoints(int V, vector<int> adj[]) {
    vector<bool> visited(V, false);
    vector<int> tin(V, -1), low(V, -1);
    set<int> articulationPoints;
    int timer = 0;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i, -1, adj, visited, tin, low, timer, articulationPoints);
        }
    }

    if (articulationPoints.empty()) return {-1};
    return vector<int>(articulationPoints.begin(), articulationPoints.end());
}
