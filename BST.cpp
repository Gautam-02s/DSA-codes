// 

#include <iostream>
using namespace std;

struct node {
    int data;
    struct node* left;
    struct node* right;

    node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

node* insertion(struct node* root, int val) {
    if (root == NULL) {
        return new node(val);
    }

    if (val < root->data) {
        root->left = insertion(root->left, val);
    } else {
        root->right = insertion(root->right, val);
    }

    return root;  // Corrected to return the root after insertion
}

void inorder(struct node* root) {
    if (root == NULL) {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";  // Modified to print all data on the same line
    inorder(root->right);
}

int main() {
    struct node* root = NULL;
    root = insertion(root, 5);  // Update root after each insertion
    root = insertion(root, 1);
    root = insertion(root, 2);
    root = insertion(root, 3);
    root = insertion(root, 8);
    root = insertion(root, 9);

    inorder(root);  // Perform inorder traversal
    cout << endl;

    return 0;
}
