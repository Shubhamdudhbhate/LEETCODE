#include <iostream>
#include <vector>
#include<algorithm>
#include <queue>
using namespace std;


void printPath(int node, vector<int>& parent) {
    vector<int> path;
    while (node != -1) {
        path.push_back(node);
        node = parent[node];
    }
    reverse(path.begin(), path.end());

    cout << "Path: ";
    for (int n : path)
        cout << n << " ";
    cout << endl;
}



void shortestPath(int V, vector<int> adj[], int src) {
    vector<int> distance(V, -1);  // -1 means not visited
    vector<int> parent(V, -1);
    queue<int> q;

    distance[src] = 0;
    q.push(src);
    int maxDist=0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (distance[v] == -1) {  // not visited
                distance[v] = distance[u] + 1;
               
                maxDist = max(maxDist, distance[v]);  //<<<<---------- for Longest path between any two Nodes
                parent[v] = u;
               
                q.push(v);
            }
        }
    }



    // Print distances and paths from src
    for (int i = 0; i < V; ++i) {
        cout << "Shortest distance from " << src << " to " << i << " = " << distance[i] << endl;
        cout<<" And Maximum Distance is :"<<maxDist<<endl;
        
        if (distance[i] != -1)
            printPath(i, parent);
        else
            cout << "No path exists." << endl;
    }



}

int main() {
    int V = 6;  // number of vertices
    vector<int> adj[V];

    // Undirected edges
    adj[0].push_back(1); adj[1].push_back(0);
    adj[0].push_back(2); adj[2].push_back(0);
    adj[1].push_back(3); adj[3].push_back(1);
    adj[2].push_back(3); adj[3].push_back(2);
    adj[3].push_back(4); adj[4].push_back(3);
    adj[4].push_back(5); adj[5].push_back(4);

    int src = 0;
    shortestPath(V, adj, 5);

    return 0;
}
