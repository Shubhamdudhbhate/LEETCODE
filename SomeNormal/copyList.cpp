#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;


class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
Node* copyRandomList(Node* head) {
    if (!head) return nullptr;

    // Step 1: Interweave original and copy nodes
    Node* curr = head;
    while (curr) {
        Node* copy = new Node(curr->val);
        copy->next = curr->next;
        curr->next = copy;
        curr = copy->next;
    }

    // Step 2: Assign random pointers to the copy nodes
    curr = head;
    while (curr) {
        if (curr->random)
            curr->next->random = curr->random->next;
        curr = curr->next->next;
    }

    // Step 3: Separate the two lists
    Node* dummyHead = new Node(0);
    Node* copyCurr = dummyHead;
    curr = head;

    while (curr) {
        copyCurr->next = curr->next;         // pick copy
        curr->next = curr->next->next;       // restore original

        copyCurr = copyCurr->next;
        curr = curr->next;
    }

    return dummyHead->next;
}







Node* copyRandomList(Node* head) {
    if (!head) return NULL;

    unordered_map<Node*, Node*> map;

    Node* curr = head;

   
    while (curr) {
        map[curr] = new Node(curr->val);  
        curr = curr->next;
    }

    curr = head;


    while (curr) {
        map[curr]->next = map[curr->next];     
        map[curr]->random = map[curr->random];  
        curr = curr->next;
    }

    return map[head]; 
}





















};








