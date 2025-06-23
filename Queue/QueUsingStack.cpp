#include <iostream>
#include <stack>
using namespace std;

class QueueUsingStacks { // this is better than below
private:
    stack<int> s1, s2;

public:
    void enqueue(int x) {  // s1 storing elements in reverse order as stack is LIFO
        s1.push(x);
    }

    void dequeue() {                //  s2 storing elements in correct order as stack is LIFO              
        if (s1.empty() && s2.empty()) {
            cout << "Queue is empty\n";
            return;
        }

        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        s2.pop();
    }

    int front() {
        if (s1.empty() && s2.empty()) {
            cout << "Queue is empty\n";
            return -1;
        }

        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        return s2.top();
    }

    bool empty() {
        return s1.empty() && s2.empty();
    }
    

class MyQueue {
private:
    stack<int> s1, s2;

public:
    MyQueue() {
        // Constructor
    }

    // Enqueue
    void push(int x) {
        s1.push(x);
    }

    // Dequeue
    int pop() {
        if (s1.empty()) return -1;

        // Move s1 to s2
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        // Get front
        int front = s2.top();
        s2.pop();

        // Move back to s1
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }

        return front;
    }

    // Get front
    int peek() {
        if (s1.empty()) return -1;

        // Move s1 to s2
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        // Get front
        int front = s2.top();

        // Move back to s1
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }

        return front;
    }

    // Check if empty
    bool empty() {
        return s1.empty();
    }
};





};

int main() {
    QueueUsingStacks q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout << "Front: " << q.front() << endl; // 10
    q.dequeue();
    cout << "Front: " << q.front() << endl; // 20
}
