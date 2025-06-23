#include <iostream>
#include <vector>
using namespace std;

class CircularQueueSTL {
private:
    vector<int> buffer;
    int front, rear, size, capacity;

public:
    CircularQueueSTL(int k) {
        capacity = k;
        buffer.resize(k);
        front = -1;
        rear = -1;
        size = 0;
    }

    bool enqueue(int val) {
        if (isFull()) return false;

        if (isEmpty())
            front = 0;

        rear = (rear + 1) % capacity;
        buffer[rear] = val;
        size++;
        return true;
    }

    bool dequeue() {
        if (isEmpty()) return false;

        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % capacity;
        }
        size--;
        return true;
    }

    int getFront() {
        if (isEmpty()) return -1;
        return buffer[front];
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }
};

int main() {
    CircularQueueSTL cq(3);
    cq.enqueue(1);
    cq.enqueue(2);
    cq.enqueue(3);

    cout << "Front: " << cq.getFront() << endl; // 1
    cq.dequeue();
    cq.enqueue(4);

    cout << "Front: " << cq.getFront() << endl; // 2
    return 0;
}
