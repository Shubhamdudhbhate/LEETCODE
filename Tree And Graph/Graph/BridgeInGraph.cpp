#include <iostream>
#include <vector>
using namespace std;

class Solution {
    int timer;

    void dfs(int u, int parent, vector<int> adj[], vector<bool>& visited,
             vector<int>& tin, vector<int>& low, vector<pair<int, int>>& bridges) {
        
        visited[u] = true;
        tin[u] = low[u] = timer++;

        for (int v : adj[u]) {
            if (v == parent) continue;

            if (!visited[v]) {
                dfs(v, u, adj, visited, tin, low, bridges);
                low[u] = min(low[u], low[v]);

                if (low[v] > tin[u]) {
                    bridges.push_back({u, v});
                }
            } else {
                low[u] = min(low[u], tin[v]);
            }
        }
    }

public:
    vector<pair<int, int>> findBridges(int V, vector<int> adj[]) {
        timer = 0;
        vector<bool> visited(V, false);
        vector<int> tin(V, -1), low(V, -1);
        vector<pair<int, int>> bridges;

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, -1, adj, visited, tin, low, bridges);
            }
        }
        return bridges;
    }
};

int main() {
    int V = 5;  // number of vertices
    vector<int> adj[5];

    // Example Graph:
    // 0 - 1 - 2
    //     |
    //     3 - 4

    adj[0].push_back(1);
    adj[1].push_back(0);

    adj[1].push_back(2);
    adj[2].push_back(1);

    adj[1].push_back(3);
    adj[3].push_back(1);

    adj[3].push_back(4);
    adj[4].push_back(3);

    Solution sol;
    vector<pair<int, int>> bridges = sol.findBridges(V, adj);

    cout << "Bridges in the graph:\n";
    for (auto& bridge : bridges) {
        cout << bridge.first << " - " << bridge.second << "\n";
    }

    return 0;
}
