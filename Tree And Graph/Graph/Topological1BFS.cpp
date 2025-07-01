#include<iostream>
#include <queue>
using namespace std;

void topoSortKahn(int V, vector<int> adj[]) {
    vector<int> indegree(V, 0);

    // Count indegrees
    for (int i = 0; i < V; i++) {
        for (int neighbor : adj[i]) {
            indegree[neighbor]++;
        }
    }

    queue<int> q;

    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0)
            q.push(i);
    }

    vector<int> topo;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for (int neighbor : adj[node]) {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0)
                q.push(neighbor);
        }
    }

    // Print result
    for (int val : topo)
        cout << val << " ";
    cout << endl;
}


int main() {
    int V = 6;
    vector<int> adj[V];

    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);


    cout << "Topological Sort using Kahn's Algorithm: ";
    topoSortKahn(V, adj);

    return 0;
}
