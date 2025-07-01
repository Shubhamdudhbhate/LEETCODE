#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

typedef pair<int, int> pii;

void dijkstra(int V, vector<pii> adj[], int src) {
    

    vector<int> dist(V, INT_MAX);
    priority_queue<pii, vector<pii>, greater<pii>> pq; // min-heap

    dist[src] = 0;
    pq.push({0, src}); // {distance, node}

    while (!pq.empty()) {
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (auto it : adj[node]) {

            int neighbor = it.first;
            int weight = it.second;

            if (dist[neighbor] > d + weight) {
                dist[neighbor] = d + weight;
                pq.push({dist[neighbor], neighbor});
            }
        }
    }


    // Output distances
    for (int i = 0; i < V; i++) {
        cout << "Shortest distance from " << src << " to " << i << " is " << dist[i] << endl;
    }
}

int main() {
    int V = 6;
    vector<pii> adj[V]; // adj[u] = {v, weight}

    // Add undirected weighted edges
    adj[0].push_back({1, 4});
    adj[1].push_back({0, 4});

    adj[0].push_back({2, 1});
    adj[2].push_back({0, 1});

    adj[1].push_back({3, 1});
    adj[3].push_back({1, 1});

    adj[2].push_back({3, 2});
    adj[3].push_back({2, 2});

    adj[3].push_back({4, 3});
    adj[4].push_back({3, 3});

    adj[4].push_back({5, 1});
    adj[5].push_back({4, 1});

    int src = 0;
    dijkstra(V, adj, src);

    return 0;
}
