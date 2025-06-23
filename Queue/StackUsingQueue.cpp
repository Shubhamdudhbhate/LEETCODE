#include <iostream>
#include <queue>
using namespace std;

class StackUsingQueues {
private:
    queue<int> q1, q2;

public:
    void push(int x) {
        q2.push(x);

        // Move all elements of q1 to q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // Swap q1 and q2
        swap(q1, q2);
    }

    void pop() {
        if (q1.empty()) {
            cout << "Stack is empty\n";
            return;
        }
        q1.pop();
    }

    int top() {
        if (q1.empty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return q1.front();
    }

    bool empty() {
        return q1.empty();
    }

};


class MyStack {
private:
    queue<int> q;

public:
    MyStack() {
        // no special initialization needed
    }

    void push(int x) {
        q.push(x);
        int size = q.size();
        
        // Rotate the queue to bring the last inserted element to front
        for (int i = 0; i < size - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        int topElement = q.front();
        q.pop();
        return topElement;
    }

    int top() {
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};


int main() {
    StackUsingQueues s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << "Top: " << s.top() << endl; // 30
    s.pop();
    cout << "Top: " << s.top() << endl; // 20
}
