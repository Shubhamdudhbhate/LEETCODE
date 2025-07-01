#include <iostream>
#include <vector>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // undirected
    }

    void DFS(int v, vector<bool> &visited) {
        visited[v] = true;
        for (int nbr : adj[v])
            if (!visited[nbr])
                DFS(nbr, visited);
    }

    bool isConnected() {
        vector<bool> visited(V, false);
        int start = -1;

        // Find a vertex with non-zero degree
        for (int i = 0; i < V; i++) {
            if (!adj[i].empty()) {
                start = i;
                break;
            }
        }

        if (start == -1) return true; // No edges

        DFS(start, visited);

        for (int i = 0; i < V; i++) {
            if (!visited[i] && !adj[i].empty())
                return false;
        }

        return true;
    }

    bool hasEulerCircuit() {
        if (!isConnected())
            return false;

        for (int i = 0; i < V; i++) {
            if (adj[i].size() % 2 != 0)
                return false;
        }

        return true;
    }
};

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 0);
    g.addEdge(0, 2);
    g.addEdge(1, 3);

    if (g.hasEulerCircuit())
        cout << "✅ The graph has an Euler Circuit.\n";
    else
        cout << "❌ The graph does not have an Euler Circuit.\n";

    return 0;
}
