#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

// Dijkstra's Algorithm with path retrieval
vector<int> dijkstra(int V, int m, vector<vector<int>> edge, int src, int dest) {
    vector<int> dist(V + 1, INT_MAX); // Distance array
    vector<bool> visited(V + 1, false);
    vector<int> parent(V + 1, -1);

    vector<pair<int, int>> adj[V + 1]; // Adjacency list

    // Build the adjacency list
    for (int i = 0; i < m; i++) {
        int u = edge[i][0];
        int v = edge[i][1];
        int wt = edge[i][2];

        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    // Min heap: {distance, node}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, src});
    dist[src] = 0;

    while (!pq.empty()) {
        int node = pq.top().second;
        pq.pop();

        if (visited[node]) continue;
        visited[node] = true;

        for (auto it : adj[node]) {
            int neighbor = it.first;
            int weight = it.second;

            if (!visited[neighbor] && dist[node] + weight < dist[neighbor]) {
                dist[neighbor] = dist[node] + weight;
                parent[neighbor] = node;
                pq.push({dist[neighbor], neighbor});
            }
        }
    }

    // Build path from destination to source
    vector<int> path;
    if (dist[dest] == INT_MAX) {
        path.push_back(-1); // No path
        return path;
    }

    int curr = dest;
    while (curr != -1) {
        path.push_back(curr);
        curr = parent[curr];
    }

    reverse(path.begin(), path.end());
    path.push_back(dist[dest]); // Append total distance

    return path;
}



int main() {
    int V = 5;
    int m = 6;

    vector<vector<int>> edges = {
        {1, 2, 2},
        {1, 3, 4},
        {2, 3, 1},
        {2, 4, 7},
        {3, 5, 3},
        {4, 5, 1}
    };

    int src = 1;
    int dest = 5;

    vector<int> path = dijkstra(V, m, edges, src, dest);

    if (path.size() == 1 && path[0] == -1) {
        cout << "No path exists from " << src << " to " << dest << endl;
    } else {
        int totalDistance = path.back();
        path.pop_back();

        cout << "Shortest path from " << src << " to " << dest << ": ";
        for (int node : path) {
            cout << node << " ";
        }
        cout << "\nTotal distance: " << totalDistance << endl;
    }

    return 0;
}

