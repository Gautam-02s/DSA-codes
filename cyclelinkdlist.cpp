#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

bool cycledetection(node* &head) {
    node* slow = head;
    node* fast = head;

    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        // If slow and fast meet, there's a cycle
        if(slow == fast) {
            return true;
        }
    }

    // No cycle detected
    return false;
}

void removecycle(node* &head) {
    node* slow = head;
    node* fast = head;

    // First, detect the cycle
    do {
        slow = slow->next;
        fast = fast->next->next;
    } while (slow != fast);

    // Move fast to head and keep slow at the meeting point
    fast = head;

    // If they meet at the start of the cycle (i.e., head)
    if (slow == fast) {
        // To remove the cycle, we need to move to the node just before the start
        while (fast->next != slow) {
            fast = fast->next;
        }
    } else {
        // Move both pointers one step at a time to find the start of the cycle
        while (slow->next != fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    // Remove the cycle
    slow->next = NULL;
}

int main() {
    // Create a simple linked list for demonstration: 1 -> 2 -> 3 -> 4 -> 5
    node* head = new node{1, new node{2, new node{3, new node{4, new node{5, NULL}}}}};

    // Example to create a cycle for testing:
    // Let's create a cycle: 5 -> 3
    head->next->next->next->next->next = head->next->next;

    // Check if the linked list has a cycle
    if (cycledetection(head)) {
        cout << "Cycle detected in the linked list." << endl;
        removecycle(head);
        if (!cycledetection(head)) {
            cout << "Cycle removed from the linked list." << endl;
        } else {
            cout << "Cycle removal failed." << endl;
        }
    } else {
        cout << "No cycle detected in the linked list." << endl;
    }

    return 0;
}
