#include <iostream>
using namespace std;

class Queue {
    int front, rear;
    int* arr;
    int max_size;

public:
    Queue(int size) {
        arr = new int[size];
        max_size = size;
        front = rear = -1;
    }

    ~Queue() {
        delete[] arr;
    }

    void enqueue(int val) {
        if (isFull()) {
            cout << "Queue Overflow!" << endl;
            return;
        }
        if (front == -1) front = 0; // First insertion
        arr[++rear] = val;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow!" << endl;
            return -1;
        }
        int val = arr[front];
        if (front >= rear) { // Queue becomes empty
            front = rear = -1;
        } else {
            front++;
        }
        return val;
    }

    int getFront() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return -1;
        }
        return arr[front];
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return rear == max_size - 1;
    }

    int size() {
        if (isEmpty()) return 0;
        return rear - front + 1;
    }
};
int main() {
    Queue queue(5);

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    cout << "Front element: " << queue.getFront() << endl;
    cout << "Dequeued element: " << queue.dequeue() << endl;
    cout << "Current size of queue: " << queue.size() << endl;

    return 0;
}
