#include <iostream>
using namespace std;

// 🔹 Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(NULL) {}
};

// 🔹 Function to reverse nodes in k-group
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        // Dummy node simplifies head updates
        ListNode dummy(0);
        dummy.next = head;

        ListNode* prev = &dummy;
        ListNode* curr;
        ListNode* nex;

        // Step 1: Count total nodes
        int count = 0;
        curr = head;
        while (curr) {
            count++;
            curr = curr->next;
        }

        // Step 2: Reverse in groups
        curr = prev->next;
        while (count >= k) {
            curr = prev->next;
            nex = curr->next;

            // Reverse k nodes
            for (int i = 1; i < k; i++) {
                curr->next = nex->next;
                nex->next = prev->next;
                prev->next = nex;
                nex = curr->next;
            }

            prev = curr;
            count -= k;
        }

        return dummy.next;
    }
};

// 🔹 Helper function to print linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// 🔹 Main function
int main() {
    // Create linked list: 1->2->3->4->5->6->7
    ListNode* head = new ListNode(1);
    ListNode* node = head;
    for (int i = 2; i <= 7; ++i) {
        node->next = new ListNode(i);
        node = node->next;
    }

    int k = 3;  // Group size

    cout << "Original List: ";
    printList(head);

    // Call the function
    Solution sol;
    ListNode* result = sol.reverseKGroup(head, k);

    cout << "Reversed in " << k << "-group: ";
    printList(result);

    return 0;
}
