#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

bool dfs(int node, int parent, vector<int> adj[], vector<bool> &visited)
{
    visited[node] = true;
        
    for (int neighbor : adj[node])
    {
        if (!visited[neighbor])
        {
            if (dfs(neighbor, node, adj, visited))
                return true;
        }
        else if (neighbor != parent)
        {
            // Cycle found
            return true;
        }
    }
    return false;
}

bool hasCycle(int V, vector<int> adj[])
{
    vector<bool> visited(V, false);
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            if (dfs(i, -1, adj, visited))
                return true;
        }
    }
    return false;
} 

bool BFS(vector<int> adj[], vector<bool> &visited)
{

    queue<pair<int, int>> q;
    visited[0] = 1;

    q.push(make_pair(0, 1));

    while (!q.empty())
    {

        int Node = q.front().first;
        int parent = q.front().second; // temprory

        q.pop();


         //Visiting neighbour of each node of list
          
        for (int j = 0; j < adj[Node].size(); j++)
        {

            if (parent == adj[Node][j])
            {
                continue;
            }

            if (visited[adj[Node][j]])
            {
                return 1;
            }

            visited[adj[Node][j]] = 1;

            q.push(make_pair(adj[Node][j], Node));
        }
    }

    return 0;
}

bool IsCycle(int V, vector<int> adj[])
{

    vector<bool> visited(V, 0);
    return BFS(adj, visited);

}


