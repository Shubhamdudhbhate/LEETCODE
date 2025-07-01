#include <iostream>
#include <vector>
#include <queue>

#include <climits>
using namespace std;

class Solution
{

public:
    vector<int> djkstra(int v, vector<vector<int>> adj[], int s)
    {

        vector<bool> Explored(v, 0);
        vector<int> dist(v, INT_MAX);

        dist[s] = 0;

        int count = v;

        while (count--)
        {

            int node = -1, value = INT_MAX;


 //priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>  (dist , node)
//                                                      |
//                                                      |
//                                                      |        |

            for (int i = 0; i < v; i++)
            {

                if (!Explored[i] && value > dist[i])
                {

                    node = i;
                    value = dist[i];
                }

            }




            Explored[node] = 1;




            for (int j = 0; j < adj[node].size(); j++)
            {

                int neighbour = adj[node][j][0];
                int weight = adj[node][j][1];

                if (!Explored[neighbour] && dist[node] + weight < dist[neighbour])
                    dist[neighbour] = dist[node] + weight;
            }
        }

        return dist;
    }
};