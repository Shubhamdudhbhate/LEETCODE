#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    // DSU for connected components
    vector<int> adj[26];

    void DFS(int node, vector<int> adj[], vector<bool> &visited)
    {
        visited[node] = 1;
        for (int j = 0; j < adj[node].size(); j++)
        {
            if (!visited[adj[node][j]])
                DFS(adj[node][j], adj, visited);
        }
    }

    bool canFormCircle(int N, vector<string> &words)
    {
        vector<int> in(26, 0), out(26, 0);

        // Build graph
        for (string &word : words)
        {
            int u = word.front() - 'a';
            int v = word.back() - 'a';
            adj[u].push_back(v);
            out[u]++;
            in[v]++;
        }

        // 1️⃣ Check if in-degree == out-degree for all characters
        for (int i = 0; i < 26; i++)
        {
            if (in[i] != out[i])
                return false;
        }

        // 2️⃣ Check if all nodes with degree are in the same connected component
        vector<bool> visited(26, 0);

        // Find starting node with out-degree > 0
        int start = -1;
        for (int i = 0; i < 26; i++)
        {
            if (out[i] > 0)
            {
                start = i;
                break;
            }
        }

        DFS(start, adj, visited);

        for (int i = 0; i < 26; i++)
        {
            if ((in[i] > 0 || out[i] > 0) && !visited[i])
                return false;
        }

        return true;
    }
};

int main()
{
    Solution sol;
    vector<string> wor = {"abc", "cde", "efg", "gha"};  // Circle possible: a→c→e→g→a
    int N = wor.size();

    if (sol.canFormCircle(N, wor))
        cout << "✅ Can form a circle of strings.\n";
    else
        cout << "❌ Cannot form a circle of strings.\n";

    return 0;
}
