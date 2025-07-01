#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int minimumSemesters(int n, vector<vector<int>> &relations)
    {
        vector<int> adj[n + 1]; // 1-based indexing
        vector<int> indegree(n + 1, 0);

        // Build graph
        for (int i = 0; i < relations.size(); i++)
        {
            int u = relations[i][0];
            int v = relations[i][1];

            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;
        // Add all nodes with indegree 0 (no prereqs)
        for (int i = 1; i <= n; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }

        int semester = 0;
        int completed = 0;

        while (!q.empty())
        {
            int size = q.size();
            semester++;

            for (int i = 0; i < size; i++)
            {
                int node = q.front();
                q.pop();
                completed++;

                for (int neighbor : adj[node])
                {
                    indegree[neighbor]--;
                    if (indegree[neighbor] == 0)
                        q.push(neighbor);
                }
            }
        }

        return completed == n ? semester : -1; // return -1 if cycle (not all courses can be completed)
    }
};

int main()
{
    Solution obj;

    int n = 3;
    vector<vector<int>> relations = {
        {1, 3}, {2, 3}};

    int semesters = obj.minimumSemesters(n, relations);
    if (semesters == -1)
        cout << "Not possible to finish all courses (cycle detected)." << endl;
    else
        cout << "Minimum semesters required: " << semesters << endl;

    return 0;
}
