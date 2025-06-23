#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    vector<int> prevSmaller(n), nextSmaller(n);
    stack<int> s;

    // Previous Smaller Element
    for (int i = 0; i < n; i++) {
        while (!s.empty() && heights[s.top()] >= heights[i]) {
            s.pop();
        }
        prevSmaller[i] = (s.empty()) ? -1 : s.top();
        s.push(i);
    }

    // Clear stack to reuse
    while (!s.empty()) s.pop();

    // Next Smaller Element
    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && heights[s.top()] >= heights[i]) {
            s.pop();
        }
        nextSmaller[i] = (s.empty()) ? n : s.top();
        s.push(i);
    }

    // Calculate max area
    int maxArea = 0;
    for (int i = 0; i < n; i++) {
        int width = nextSmaller[i] - prevSmaller[i] - 1;
        int area = heights[i] * width;
        maxArea = max(maxArea, area);
    }

    return maxArea;
}
