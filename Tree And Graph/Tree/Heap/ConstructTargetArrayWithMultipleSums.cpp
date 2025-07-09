#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isPossible(vector<int>& target) {
    priority_queue<int> pq(target.begin(), target.end());
    long long total = 0;
    for (int num : target) total += num;

    while (true) {
        int maxElem = pq.top(); pq.pop();
        long long rest = total - maxElem;

        if (maxElem == 1 || rest == 1) return true;

        if (rest <= 0 || maxElem <= rest) return false;


        int updated = maxElem - rest;
        int updated = maxElem % rest;
        if (updated == 0) return false;

        pq.push(updated);
        total = rest + updated;
    }
}
