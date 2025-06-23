#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<int> dq;

    // Insertion
    dq.push_back(10);
    dq.push_front(5);
    dq.push_back(15);

    // Current deque: 5 10 15
    cout << "Deque elements: ";
    for (int val : dq) {
        cout << val << " ";
    }
    cout << endl;

    // Accessing elements
    cout << "Front: " << dq.front() << endl; // 5
    cout << "Back: " << dq.back() << endl;   // 15
    cout << "Element at index 1: " << dq[1] << endl; // 10

    // Removing elements
    dq.pop_front();  // removes 5
    dq.pop_back();   // removes 15

    cout << "After pops: ";
    for (int val : dq) {
        cout << val << " ";
    }
    cout << endl;

    // Check empty
    if (dq.empty()) {
        cout << "Deque is empty\n";
    } else {
        cout << "Deque is not empty\n";
    }

    return 0;
}
