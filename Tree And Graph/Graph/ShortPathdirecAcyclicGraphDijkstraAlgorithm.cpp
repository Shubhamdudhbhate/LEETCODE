#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>

using namespace std;

typedef pair<int, int> pii;

void printPath(int node, vector<int> &parent)
{
    vector<int> path;
    while (node != -1)
    {
        path.push_back(node);
        node = parent[node];
    }
    reverse(path.begin(), path.end());

    cout << "Path: ";
    for (int n : path)
        cout << n << " ";
    cout << endl;
}

void dijkstra(int V, vector<vector<pii>> &adj, int src)  // pii = pair<int,int>
{
    vector<int> dist(V, INT_MAX);
    vector<int> parent(V, -1);
    priority_queue<pii, vector<pii>, greater<pii>> pq; //// Min-heap priority queue that stores {distance, node} pairs in vector from (min dist to max dist) for Dijkstra's algorithm

    dist[src] = 0;
    pq.push({0, src}); // {distance, node}

    while (!pq.empty())
    {
        int u = pq.top().second; // node
        int d = pq.top().first; // dist
        pq.pop();

        if (d > dist[u])
            continue; // Skip outdated entry

        for (pair<int, int> &edge : adj[u])
        {
            int v = edge.first;  //node
            int w = edge.second;  //weight

            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    // Output
    for (int i = 0; i < V; ++i)
    {
        if (dist[i] == INT_MAX)
        {
            cout << "No path from " << src << " to " << i << endl;
        }
        else
        {
            cout << "Shortest distance from " << src << " to " << i << " = " << dist[i] << endl;
            printPath(i, parent);
        }
    }
}

int main()
{
    int V = 6;
    vector<vector<pii>> adj(V); // adj[u] = {v, weight}


    // Directed edges (u → v, weight)
    adj[0].push_back({1, 5});
    adj[0].push_back({2, 3});
    adj[1].push_back({3, 6});
    adj[1].push_back({2, 2});
    adj[2].push_back({4, 4});
    adj[2].push_back({5, 2});
    adj[2].push_back({3, 7});
    adj[3].push_back({4, -1});
    adj[4].push_back({5, -2});

    int src = 0;
    dijkstra(V, adj, src);

    return 0;
}
