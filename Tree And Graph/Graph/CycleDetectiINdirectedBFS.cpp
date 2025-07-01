#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool detectCycleBFS(int V, vector<int> adj[]) {
    vector<int> indegree(V, 0);

    // Step 1: Calculate in-degrees
    for (int i = 0; i < V; i++) {
        for (int neighbor : adj[i]) {
            indegree[neighbor]++;
        }
    }

    // Step 2: Push all nodes with in-degree 0
    queue<int> q;
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0)
            q.push(i);
    }

    int count = 0;

    // Step 3: Process queue
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        count++;

        for (int neighbor : adj[node]) {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0)
                q.push(neighbor);
        }
    }

    // Step 4: If count != V, cycle exists
    return count != V;
}


int main() {
    int V = 4;
    vector<int> adj[V];

    // Directed edges
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(3);
    adj[3].push_back(1); // ← back edge forms a cycle

    if (detectCycleBFS(V, adj))
        cout << "Cycle detected in Directed Graph.\n";
    else
        cout << "No cycle found.\n";

    return 0;
}
