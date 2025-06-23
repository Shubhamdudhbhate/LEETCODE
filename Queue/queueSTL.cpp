#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;

    q.push(10); // enqueue
    q.push(20);
    q.push(30);

    cout << "Front: " << q.front() << endl; // get front
    cout << "Back: " << q.back() << endl;   // get rear

    q.pop(); // dequeue
    cout << "Front after pop: " << q.front() << endl;

    cout << "Size: " << q.size() << endl;
    cout << (q.empty() ? "Queue is empty" : "Queue is not empty") << endl;

    return 0;
}
