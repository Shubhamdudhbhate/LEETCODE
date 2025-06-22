#include <iostream>
using namespace std;

// 🔹 Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(NULL) {}
};

// 🔹 Solution class with swapping function
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;

        while (prev->next && prev->next->next) {
            ListNode* first = prev->next;
            ListNode* second = first->next;

            // Swapping
            first->next = second->next;
            second->next = first;
            prev->next = second;

            // Move prev pointer
            prev = first;
        }

        return dummy.next;
    }
};

// 🔹 Helper function to print list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// 🔹 Main function with test case
int main() {
    // Create linked list: 1 -> 2 -> 3 -> 4
    ListNode* head = new ListNode(1);
    ListNode* node = head;
    for (int i = 2; i <= 4; ++i) {
        node->next = new ListNode(i);
        node = node->next;
    }

    cout << "Original List: ";
    printList(head);

    Solution sol;
    ListNode* swapped = sol.swapPairs(head);

    cout << "After Swapping Pairs: ";
    printList(swapped);

    return 0;
}
