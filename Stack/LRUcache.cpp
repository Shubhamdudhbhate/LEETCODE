#include <unordered_map>
using namespace std;

class Node {
public:
    int key, val;
    Node* prev;
    Node* next;

    Node(int k, int v) {
        key = k;
        val = v;
        prev = next = NULL;
    }
};

class LRUCache {
public:
    Node* head;
    Node* tail;
    unordered_map<int, Node*> M;
    int limit;

    // Constructor
    LRUCache(int capacity) {
        limit = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    // Add node just after head
    void addNode(Node* newNode) {
        Node* oldNext = head->next;
        head->next = newNode;
        newNode->prev = head;
        newNode->next = oldNext;
        oldNext->prev = newNode;
    }

    // Delete a node from anywhere
    void delNode(Node* oldNode) {
        Node* oldPrev = oldNode->prev;
        Node* oldNext = oldNode->next;
        oldPrev->next = oldNext;
        oldNext->prev = oldPrev;
    }

    int get(int key) {
        if (M.find(key) == M.end()) {
            return -1;
        }

        Node* currNode = M[key];
        int value = currNode->val;

        // Move to front (most recently used)
        M.erase(key);
        delNode(currNode);
        addNode(currNode);
        M[key] = head->next;

        return value;
    }

    void put(int key, int value) {
        // If key exists, delete the old node
        if (M.find(key) != M.end()) {
            Node* oldNode = M[key];
            delNode(oldNode);
            M.erase(key);
        }

        // If cache is full, remove least recently used (node before tail)
        if (M.size() == limit) {
            Node* lru = tail->prev;
            delNode(lru);
            M.erase(lru->key);
        }

        // Add new node to front
        Node* newNode = new Node(key, value);
        addNode(newNode);
        M[key] = head->next;
    }
};
