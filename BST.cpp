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

    return root;
}

void inorder(struct node* root) {
    if (root == NULL) {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

node* search(node* root, int key)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->data==key)
    {
        return root;
    }
    else if(root->data<key)
    {
        return search(root->left,key); // Need to return the result of recursive call
    }
    else
    {
        return search(root->right,key); // Need to return the result of recursive call
    }
}

node* min(node* root)
{
    while(root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

node* deletion(node* root, int key)
{
    if(root == NULL)
    {
        return NULL;
    }

    if(key < root->data)
    {
        root->left = deletion(root->left, key);  // Corrected: assign the result to root->left
    }
    else if(key > root->data)
    {
        root->right = deletion(root->right, key);  // Corrected: assign the result to root->right
    }
    else
    {
        // Node found
        if(root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
        }
        else if(root->left == NULL)
        {
            node* temp = root;
            root = root->right;
            delete temp;
        }
        else if(root->right == NULL)
        {
            node* temp = root;
            root = root->left;
            delete temp;
        }
        else
        {
            node* temp = min(root->right);
            root->data = temp->data;
            root->right = deletion(root->right, temp->data);
        }
    }

    return root;  // Return the updated root
}

int main() {
    struct node* root = NULL;
    root = insertion(root, 5);  // Update root after each insertion
    root = insertion(root, 1);
    root = insertion(root, 2);
    root = insertion(root, 3);
    root = insertion(root, 8);
    root = insertion(root, 9);

    cout << "Inorder traversal before deletion: ";
    inorder(root);
    cout << endl;

    root = deletion(root, 8);  // Delete node with value 8

    cout << "Inorder traversal after deletion: ";
    inorder(root);
    cout << endl;

    return 0;
}
