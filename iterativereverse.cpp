#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

node* reverse(node* &head) {
    node* cur = head;
    node* prev = NULL;
    node* next = NULL;

    while(cur != NULL) {
        next = cur->next; // Store the next node
        cur->next = prev; // Reverse the current node's pointer
        prev = cur;       // Move prev to the current node
        cur = next;       // Move to the next node
    }
    head = prev; // Update head to the new front node
    return head;
}

node* reverseRecursive(node* &head) {
    // Base case: if the list is empty or has only one node
    if(head == NULL || head->next == NULL) {
        return head;
    }

    // Recursively reverse the rest of the list
    node* newHead = reverseRecursive(head->next);

    // Adjust the next pointer of the current node's next node
    head->next->next = head;

    // Set the next pointer of the current node to NULL
    head->next = NULL;

    return newHead;
}

node* reversek(node* &head, int k) {
    node* prev = NULL;
    node* cur = head;
    node* next = NULL;

    int count = 0;

    // Reverse the first k nodes of the linked list
    while (cur != NULL && count < k) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
        count++;
    }

    // Recursively call for the rest of the list
    if (next != NULL) {
        head->next = reversek(next, k);
    }

    // prev is the new head of the reversed list
    return prev;
}

int main() {
    // Create a simple linked list for demonstration: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9
    node* head = new node{1, new node{2, new node{3, new node{4, new node{5, new node{6, new node{7, new node{8, new node{9, NULL}}}}}}}}};

    int k = 3;

    // Reverse the linked list in groups of k nodes
    head = reversek(head, k);

    // Print the k-reversed list
    node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}
