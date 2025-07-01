#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Bellman-Ford Algorithm
vector<int> bellmanFord(int V, int src, vector<vector<int>>& edges,int s) {

    vector<int> dist(V, INT_MAX);
    dist[src] = 0;
    int n = edges.size();

    // Step 1: Relax all edges V-1 times
    for (int i = 1; i < V; i++) {
        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            if (dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
            }
        }
    }
    



    // Step 2: Check for negative-weight cycles
    for (auto edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];

        if (dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
            cout << "Negative weight cycle detected!" << endl;
            return {};
        }
    }

    return dist;
}



