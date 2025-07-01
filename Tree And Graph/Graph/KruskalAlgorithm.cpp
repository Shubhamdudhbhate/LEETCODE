#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Basic edge structure
struct Edge
{
    int src, dest, weight;

    // Sort edges by weight
    // bool operator<(const Edge& other) const {
    //     return weight < other.weight;
    //}
};

// Comparator function to sort edges by weight
bool compareByWeight(const Edge &a, const Edge &b)
{
    return a.weight < b.weight;
}



// Disjoint Set Union (DSU) with union by rank and path compression
class DSU
{
public:
    vector<int> parent, rank;

    DSU(int n)
    {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int findParent(int node)
    {
        if (parent[node] != node)
            parent[node] = findParent(parent[node]); // Path compression
        return parent[node];
    }

    void unionByRank(int u, int v)
    {
        int pu = findParent(u);
        int pv = findParent(v);
        if (pu == pv)
            return;

        if (rank[pu] < rank[pv])
        {
            parent[pu] = pv;
        }
        else if (rank[pu] > rank[pv])
        {
            parent[pv] = pu;
        }
        else
        {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
};

int main()
{
    int V = 4; // Number of nodes
    
    vector<Edge> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}};
 
    // Sort using separate comparator
    sort(edges.begin(), edges.end(), compareByWeight);

    DSU dsu(V);
    int totalWeight = 0;

    cout << "Edges in MST:\n";
    for (const Edge &e : edges)
    {
        if (dsu.findParent(e.src) != dsu.findParent(e.dest))
        {
            dsu.unionByRank(e.src, e.dest);
            totalWeight += e.weight;
            cout << e.src << " - " << e.dest << "  weight = " << e.weight << endl;
        }
    }

    cout << "Total weight of MST: " << totalWeight << endl;
    return 0;
}
