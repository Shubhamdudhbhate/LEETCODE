#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

class Solution {
public:
    string findOrder(string dict[], int N, int K) {
        // Step 1: Build graph
        vector<int> adj[K];
        vector<int> indegree(K, 0);

        for (int i = 0; i < N - 1; i++) {
            string word1 = dict[i];
            string word2 = dict[i + 1];

            int len = min(word1.length(), word2.length());
            for (int j = 0; j < len; j++) {
                if (word1[j] != word2[j]) {
                    int u = word1[j] - 'a';
                    int v = word2[j] - 'a';
                    adj[u].push_back(v);
                    indegree[v]++;
                    break;
                }
            }
        }

        // Step 2: Topological Sort (BFS)
        queue<int> q;

        for (int i = 0; i < K; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        string result;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            result += (char)(u + 'a');

            for (int v : adj[u]) {
                indegree[v]--;
                if (indegree[v] == 0)
                    q.push(v);
            }
        }

        // Step 3: If result length < K, there's a cycle (invalid dictionary)
        if (result.length() < K)
            return "";

        return result;
    }
};


int main() {
    Solution obj;

    int N = 5, K = 4;
    string dict[] = {"baa", "abcd", "abca", "cab", "cad"};

    string order = obj.findOrder(dict, N, K);

    if (order.empty())
        cout << "Invalid dictionary (cycle detected)." << endl;
    else
        cout << "Alien Dictionary Order: " << order << endl;

    return 0;
}
