#include <iostream>
using namespace std;

class Stack {
    int top;
    int* arr;
    int max_size;

public:
    Stack(int size) {
        arr = new int[size];
        max_size = size;
        top = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    void push(int val) {
        if (isFull()) {
            cout << "Stack Overflow!" << endl;
            return;
        }
        arr[++top] = val;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!" << endl;
            return -1;
        }
        return arr[top--];
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is Empty!" << endl;
            return -1;
        }
        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == max_size - 1;
    }

    int size() {
        return top + 1;
    }
};
int main() {
    Stack stack(5);

    stack.push(10);
    stack.push(20);
    stack.push(30);
    
    cout << "Top element: " << stack.peek() << endl;
    cout << "Popped element: " << stack.pop() << endl;
    cout << "Current size of stack: " << stack.size() << endl;

    return 0;
}