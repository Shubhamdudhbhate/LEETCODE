#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* getMiddle(Node* start, Node* end) {
    if (!start) return nullptr;
    Node* slow = start;
    Node* fast = start->next;

    while (fast != end) {
        fast = fast->next;
        if (fast != end) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    return slow;
}

bool binarySearchLL(Node* head, int key) {
    Node* start = head;
    Node* end = nullptr;

    while (start != end) {
        Node* mid = getMiddle(start, end);
        if (!mid) return false;

        if (mid->data == key) return true;
        else if (mid->data < key) start = mid->next;
        else end = mid;
    }
    return false;
}
