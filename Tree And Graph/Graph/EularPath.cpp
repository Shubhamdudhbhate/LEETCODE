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

    void DFS(int v, vector<bool>& visited) {
        visited[v] = true;
        for (int nbr : adj[v])
            if (!visited[nbr])
                DFS(nbr, visited);
    }

    bool isConnected() {
        vector<bool> visited(V, false);
        int start = -1;

        // Find first non-zero degree vertex
        for (int i = 0; i < V; i++) {
            if (!adj[i].empty()) {
                start = i;
                break;
            }
        }

        if (start == -1) return true; // No edges = Euler Path exists trivially

        DFS(start, visited);

        for (int i = 0; i < V; i++) {
            if (!visited[i] && !adj[i].empty())
                return false;
        }

        return true;
    }

    bool hasEulerPath() {
        if (!isConnected())
            return false;

        int odd = 0;
        for (int i = 0; i < V; i++) {
            if (adj[i].size() % 2 != 0)
                odd++;
        }

        return (odd == 0 || odd == 2);
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    if (g.hasEulerPath())
        cout << "✅ The graph has an Euler Path.\n";
    else
        cout << "❌ The graph does not have an Euler Path.\n";

    return 0;
}
