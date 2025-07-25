#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        // 1) Sort events by start day
        sort(events.begin(), events.end());          // O(n log n)
        
        priority_queue<int, vector<int>, greater<int>> pq; // min‑heap of end days
        int i   = 0;                    // pointer in events
        int day = 0;                    // current day we are simulating
        int ans = 0;                    // events attended
        int n   = events.size();
        
        // 2) Process until no events left to consider
        while (i < n || !pq.empty()) {
            // If heap empty, jump 'day' to next event's start
            if (pq.empty())
                day = events[i][0];
            
            // 3) Push all events that start today into the heap
            while (i < n && events[i][0] == day) {
                pq.push(events[i][1]);              // store end day
                ++i;
            }
            
            // 4) Remove events that already expired
            while (!pq.empty() && pq.top() < day)
                pq.pop();
            
            // 5) Attend the event that ends earliest (if any)
            if (!pq.empty()) {
                pq.pop();   // attend it
                ++ans;
            }
            
            ++day;  // move to next day
        }
        return ans;
    }
};
