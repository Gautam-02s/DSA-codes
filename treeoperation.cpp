#include <iostream>
using namespace std;

struct nodes {
    int data;
    nodes* left;
    nodes* right;
    
    // Constructor
    nodes(int val) : data(val), left(NULL), right(NULL) {}
};

int countcodes(struct nodes* root) {
    if (root == NULL) {
        return 0;
    }
    return countcodes(root->left) + countcodes(root->right) + 1;
}

int sumnodes(struct nodes* root) {
    if (root == NULL) {
        return 0;
    }
    return sumnodes(root->left) + sumnodes(root->right) + root->data;
}

int height(struct nodes* root) {
    if (root == NULL) {
        return 0;
    }
    int lh = height(root->left);
    int rh = height(root->right);

    return max(lh, rh) + 1;
}

int diameter(struct nodes* root) {
    if (root == NULL) {
        return 0;
    }
    int lheight = height(root->left);
    int rheight = height(root->right);
    int curheight = lheight + rheight;

    int ld = diameter(root->left);
    int rd = diameter(root->right);

    return max(curheight, max(ld, rd));
}

void sumreplacement(struct nodes* root) {
    if (root == NULL) {
        return;
    }

    sumreplacement(root->left);
    sumreplacement(root->right);

    if (root->left != NULL) {
        root->data += root->left->data;
    }

    if (root->right != NULL) {
        root->data += root->right->data;
    }
}

bool isbalanced(struct nodes* root) {
    if (root == NULL) {
        return true;  // An empty tree is balanced
    }

    if (!isbalanced(root->left)) {
        return false;
    }
    if (!isbalanced(root->right)) {
        return false;
    }

    int lh = height(root->left);
    int rh = height(root->right);

    if (abs(lh - rh) <= 1) {
        return true;
    } else {
        return false;
    }
}

int main() {
    // Creating the root of the tree
    struct nodes* root = new nodes(5);

    // Adding more elements to the binary tree
    root->left = new nodes(3);
    root->right = new nodes(8);

    root->left->left = new nodes(2);
    root->left->right = new nodes(4);

    root->right->left = new nodes(7);
    root->right->right = new nodes(10);

    // Output the number of nodes in the binary tree
    cout << "Number of nodes in the tree: " << countcodes(root) << endl;
    cout << "Sum of nodes in the tree: " << sumnodes(root) << endl;
    cout << "Height of the tree: " << height(root) << endl;
    cout << "Diameter of the tree: " << diameter(root) << endl;

    sumreplacement(root);
    cout << "Sum replacement: Root node value after replacement: " << root->data << endl;

    if (isbalanced(root)) {
        cout << "The tree is balanced." << endl;
    } else {
        cout << "The tree is not balanced." << endl;
    }

    return 0;
}
