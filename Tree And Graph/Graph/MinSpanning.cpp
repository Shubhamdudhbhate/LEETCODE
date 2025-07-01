#include <iostream>
#include <vector>
#include <climits>
using namespace std;

const int V = 5; // Number of vertices

int minKey(vector<int>& key, vector<bool>& mst) {
    int min = INT_MAX, index;

    for (int v = 0; v < V; v++) {
        if (!mst[v] && key[v] < min) {
            min = key[v];
            index = v;
        }
    }
    return index;
}

void primMST(int graph[V][V]) {
    vector<int> key(V, INT_MAX);      // Initialize key values
    vector<bool> mst(V, false);       // MST set
    vector<int> parent(V, -1);        // To store MST edges

    key[0] = 0; // Start from vertex 0

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mst);     // Pick minimum key vertex not yet in MST
        mst[u] = true;

        // Update keys of adjacent vertices of u
        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !mst[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    // Print MST edges
    cout << "MST edges and weights:\n";
    int totalWeight = 0;
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << "  wt = " << graph[i][parent[i]] << "\n";
        totalWeight += graph[i][parent[i]];
    }
    cout << "Total MST Weight: " << totalWeight << endl;
}

int main() {
    // Example graph (Adjacency Matrix)
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    primMST(graph);

    return 0;
}
