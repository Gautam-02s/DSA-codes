#include <iostream>
using namespace std;

struct node {
    int data;
    node* left;
    node* right;

    node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void preorder(struct node* root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << endl;
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct node* root) {
    if (root == NULL) {
        return;
    }
    
    inorder(root->left);
    cout << root->data << endl;
    inorder(root->right);
}

void postorder(struct node* root) {
    if (root == NULL) {
        return;
    }
    
    postorder(root->left);
    postorder(root->right);
     cout << root->data << endl;
}

int main() {
    struct node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);

    preorder(root);  
    inorder(root);
    postorder(root);
    return 0;
}
