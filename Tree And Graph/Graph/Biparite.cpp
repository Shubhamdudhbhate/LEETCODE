#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

class Solution
{

public:



    bool IsPartiteBFS(int V, vector<int> adj[])
    {

        vector<int> color(V, -1);
        queue<int> q;

        for (int i = 0; i < V; i++)
        {
            if (color[i] == -1)
            {
                q.push(0);
                color[0] = 0;

                while (!q.empty())
                {
                    int node = q.front();
                    q.pop();

                    for (int j = 0; j < adj[node].size() - 1; j++)
                    {

                        if (color[adj[node][j] == -1])
                        {

                            color[adj[node][j]] == (color[node] + 1) % 2;
                            q.push(adj[node][j]);
                        }
                        else
                        {

                            if (color[node] == color[adj[node][j]])
                                return 0;
                        }
                    }
                }
            }
        }

        return 1;
    }
    //___________________________________________________________________________________________________
    //___________________________________________________________________________________________________

    bool IsPartiteDFS(int node, vector<int> adj[], vector<int> &color)
    {

        for (int j = 0; j < adj[node].size(); j++)
        {
            if (color[adj[node][j]] == -1)
            {

                color[adj[node][j]] == (color[node] + 1) % 2;

                if (!IsPartiteDFS(adj[node][j], adj, color))
                {
                    return 0;
                }
            }
            else
            {

                if (color[node] == color[adj[node][j]])
                    return 0;
            }
        }

        return 1;
    }




    bool CHeckBip(int V, vector<int> adj[])
    {

        vector<int> color(V, -1);

        for (int i = 0; i < V; i++)
        {

            if (color[i] == -1)
            {
                color[i] = 0;

                if (!IsPartiteDFS(0, adj, color))
                    return 0;
            }
        }

        return 1;
    }

    //___________________________________________________________________________________________________
    //___________________________________________________________________________________________________

};