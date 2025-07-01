#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

// Dijkstra's Algorithm using Priority Queue
vector<int> dijkstra(int V, int m, vector<vector<int>> edge, int src,int dest)
{
    vector<int> dist(V+1, INT_MAX); // distance array
    vector<bool> Explored(V + 1, 0);
    vector<int> parent(V + 1, -1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> p;

    p.push({0, src});
    dist[src] = 0;


    // Adjency list creation (node,weight)
    vector<pair<int, int>> adj[V + 1];

    for (int i = 0; i < m; i++)
    {

        int u = edge[i][0];
        int v = edge[i][1];

        int weight = edge[i][2];

        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight});
    }



    while (!p.empty())
    {

        int node = p.top().second;
        p.pop();

        if (Explored[node])
        {
            continue;
        }

        Explored[node] = 1;

        for (int j = 0; j < adj[node].size(); j++)
        {

            int neighbour = adj[node][j].first;
            int weight = adj[node][j].second;

            if (!Explored[neighbour] && dist[node] + weight < dist[neighbour]){
                dist[neighbour] = dist[node] + weight;
                 parent[neighbour] = node;
                p.push({dist[neighbour], neighbour});
            }
        }
        
    }


    vector<int> path;

    if (parent[dest] == -1)
    {
        path.push_back(-1);
        return path;
    }


    while (dest != -1)
    {

        path.push_back(dest);
        dest = parent[dest];
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


    int src = 1; // Starting node
    int dest = 5;

    vector<int> path = dijkstra(V + 1, m, edges, src,dest);  // pass V+1 to match 1-based indexing

    // If no path found
    if (path.size() == 1 && path[0] == -1) {
        cout << "No path exists from " << src << " to " << dest << endl;
    } else {
        int totalDistance = path.back(); // last element is distance
        path.pop_back(); // remove distance to print only the path

        cout << "Shortest path from " << src << " to " << dest << ": ";
        for (int node : path) {
            cout << node << " ";
        }
        cout << "\nTotal distance: " << totalDistance << endl;
    }

    return 0;
}
