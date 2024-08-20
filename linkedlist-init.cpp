#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node* next;

    node(int val) {
        data = val;
        next = nullptr;
    }
};

void inserttail(node*& head, int val)
{
    node* n = new node(val);

    if (head == nullptr) {
        head = n;
        return;
    }

    node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = n;
}

void inserthead(node*& head, int val)
{
    node* n = new node(val);
    n->next = head;
    head = n;
}

int search(node* head, int key)
{
    int count = 1;
    node* temp = head;

    while (temp != nullptr) {
        if (temp->data == key) {
            cout << "The key is found at position " << count << endl;
            return count; 
        }
        temp = temp->next;
        count++;
    }
    
    cout << "The key is not found in the list." << endl;
    return -1; 
}

int main()
{
    node* head = nullptr;

    inserttail(head, 10);
    inserttail(head, 20);
    inserttail(head, 30);
    inserthead(head, 3);
    inserthead(head, 5);
    inserthead(head, 7);

    search(head, 20);

    node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}
