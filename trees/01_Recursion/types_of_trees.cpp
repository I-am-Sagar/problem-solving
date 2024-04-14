#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;

        Node(int data) {
            this->data = data;
            this->left = this->right = NULL;
        }
};

// check if tree is full
bool is_full(Node* root) {
    // If tree is empty
    if (root == NULL)
        return true;

    // If we are at a leaf node
    if (root->left == NULL && root->right == NULL)
        return true;

    // If left and right both should exist
    if (root->left && root->right)
        return is_full(root->left) && is_full(root->right);

    return false;
}

// check if tree is complete
int node_count(Node* root) {
    if (root == NULL) 
        return 0;
    return 1 + node_count(root->left) + node_count(root->right);
}

bool is_complete_helper(Node* root, int index, int num_nodes) {
    if (root == NULL)
        return true;
    
    if (index >= num_nodes)
        return false;
    
    return is_complete_helper(root->left, 2*index+1, num_nodes) && \
        is_complete_helper(root->right, 2*index+2, num_nodes);
}

bool is_complete(Node* root) {
    return is_complete_helper(root, 0, node_count(root));
}


// check if tree is perfect
int height(Node* root) {
    if (root == NULL)
        return 0;
    return 1 + max(height(root->left), height(root->right));
}

// All leaves should be at level = height - 1
bool is_perfect_helper(Node* root, int h, int level) {
    if (root == NULL)
        return true;
    
    if (root->left == NULL && root->right == NULL)
        return (level == h-1);
    
    if (root->left == NULL || root->right == NULL) 
        return false;

    return is_perfect_helper(root->left, h, level+1) && \
        is_perfect_helper(root->right, h, level+1);

}

bool is_perfect(Node* root) {
    int h = height(root);
    return is_perfect_helper(root, h, 0);
}


// check if tree is skewed
bool is_skewed(Node* root) {
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return true;
    
    if (root->left && root->right)
        return false;

    if (root->left)
        return is_skewed(root->left);
    
    return is_skewed(root->right);
}



int main() {
    // First tree that is full

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(7);
    root->left->right = new Node(3);
    root->left->left = new Node(8);
    root->right->left = new Node(4);
    root->right->right = new Node (5);
    root->left->left->left = new Node(6);
    root->left->left->right = new Node(9);

    /*
                 1
              2     7
           8    3  4  5
         6   9             
    */

    cout << is_full(root) << endl;
    cout << is_complete(root) << endl;
    cout << is_perfect(root) << endl;
    cout << is_skewed(root) << endl;
  
    return 0;
}