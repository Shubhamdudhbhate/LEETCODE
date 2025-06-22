#include <iostream>
using namespace std;

// ✅ Node definition
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node(int _val) {
        val = _val;
        prev = NULL;
        next = NULL;
        child = NULL;
    }
};

// ✅ Solution class with flatten logic
class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return head;
        flattenDFS(head);
        return head;
    }

private:
    Node* flattenDFS(Node* node) {
        Node* curr = node;
        Node* last = node;

        while (curr) {
            Node* next = curr->next;

            if (curr->child) {
                Node* childHead = curr->child;
                Node* childTail = flattenDFS(childHead);

                curr->next = childHead;
                childHead->prev = curr;

                if (next) {
                    childTail->next = next;
                    next->prev = childTail;
                }

                curr->child = nullptr;
                last = childTail;
            } else {
                last = curr;
            }

            curr = next;
        }

        return last;
    }
};

// ✅ Helper function to print flattened list
void printList(Node* head) {
    Node* curr = head;
    while (curr) {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
}

// ✅ Main function with sample input
int main() {
    // Create nodes
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);
    Node* n7 = new Node(7);
    Node* n8 = new Node(8);
    Node* n9 = new Node(9);
    Node* n10 = new Node(10);
    Node* n11 = new Node(11);

    // Connect next pointers (main level)
    n1->next = n2; n2->prev = n1;
    n2->next = n3; n3->prev = n2;
    n3->next = n4; n4->prev = n3;
    n4->next = n5; n5->prev = n4;

    // Connect child lists
    n3->child = n7;
    n7->next = n8; n8->prev = n7;
    n8->next = n9; n9->prev = n8;

    n8->child = n10;
    n10->next = n11; n11->prev = n10;

    // Flatten and print
    Solution obj;
    Node* flatHead = obj.flatten(n1);
    printList(flatHead);

    return 0;
}
