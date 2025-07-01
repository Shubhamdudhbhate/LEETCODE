#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{

public:
    bool IsPossible(int V, vector<int> adj[])
    {
        vector<int> indegree(V, 0);

        // Step 1: Calculate in-degrees
        for (int i = 0; i < V; i++)
        {
            for (int neighbor : adj[i])
            {
                indegree[neighbor]++;
            }
        }

        // Step 2: Push all nodes with in-degree 0
        queue<int> q;
        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }

        int count = 0;

        // Step 3: Process queue
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            count++;

            for (int neighbor : adj[node])
            {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }

        // Step 4: If count != V, cycle exists
        return count == V;
    }


    // Function 1: Get topological order (if possible)
    vector<int> getTaskOrder(int V, vector<int> adj[]) {
        vector<int> indegree(V, 0);
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

        vector<int> topoOrder;
        while (!q.empty()) {
            int node = q.front(); q.pop();
            topoOrder.push_back(node); //<<<<<<------------------------this is extra line

            for (int neighbor : adj[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }

        // If topological sort didn't include all nodes, cycle exists
        if (topoOrder.size() != V)
            return {}; // return empty list if cycle exists

        return topoOrder;
    }




    bool PrerequisitTaskBFS(int N, int P, vector<pair<int, int>> &pre)
    {
        vector<int> adj[N];
        for (int i = 0; i < P; i++)
        {
            adj[pre[i].second].push_back(pre[i].first);
        }
        if (IsPossible(N, adj))   return true;

        return false;
    }



    vector<int> PrerequisiteTaskOrder(int N, int P, vector<pair<int, int>>& pre) {
        vector<int> adj[N];
        for (int i = 0; i < P; i++) {
            adj[pre[i].second].push_back(pre[i].first); // B → A (A depends on B)
        }

        return getTaskOrder(N, adj);
    }


};


int main() {
    Solution obj;

    int N = 4; // Number of tasks
    int P = 3; // Number of prerequisites

    // Example: task 1 depends on 0, 2 on 1, 3 on 2
    vector<pair<int, int>> prerequisites = {
        {1, 0}, {2, 1}, {3, 2}
    };

    

    if (obj.PrerequisitTaskBFS(N, P, prerequisites))
        cout << "Yes, all tasks can be completed." << endl;
    else
        cout << "No, there is a cycle. Tasks cannot be completed." << endl;



   vector<int> order = obj.PrerequisiteTaskOrder(N, P, prerequisites);

    if (order.empty())
        cout << "No valid task order (cycle detected)." << endl;
    else {
        cout << "Valid task order: ";
        for (int task : order)
            cout << task << " ";
        cout << endl;
    }

    return 0;
}
