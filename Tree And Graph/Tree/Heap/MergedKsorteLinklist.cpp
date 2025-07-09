#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Custom comparator for min-heap
struct compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

ListNode* mergeKLists(vector<ListNode*>& lists) {

    
    priority_queue<ListNode*, vector<ListNode*>, compare> minHeap;

    // Step 1: Push all non-null heads into the heap
    for (auto node : lists) {
        if (node)
            minHeap.push(node);
    }

    // Step 2: Dummy head for result
    ListNode* dummy = new ListNode(0);
    ListNode* tail = dummy;

    // Step 3: Process the heap
    while (!minHeap.empty()) {
        ListNode* smallest = minHeap.top();
        minHeap.pop();

        // Add to result
        tail->next = smallest;
        tail = tail->next;

        // If there is a next node in the list, push it
        if (smallest->next) {
            minHeap.push(smallest->next);
        }
    }

    return dummy->next;
}
