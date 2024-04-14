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

int sum(Node* root) {
    if (root == NULL)
        return 0;
    return root->data + sum(root->left) + sum(root->right);
}

int height(Node* root) {
    if (root == NULL)
        return 0;

    return 1 + max(height(root->left), height(root->right));
}

int maximum(Node* root) {
    if (root == NULL)
        return 0;

    return max(root->data, max(maximum(root->left), maximum(root->right)));
}

bool search(Node* root, int key) {
    if (root == NULL)
        return false;

    if (root->data == key)
        return true;

    return search(root->left, key) || search(root->right, key);
}

int main() {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(7);
    root->left->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node (5);
    root->right->right->right = new Node(6);

    /*
                 1
              2     7
                3  4  5
                        6 
    */

    cout << sum(root) << endl;
    cout << height(root) << endl;
    cout << maximum(root) << endl;

    cout << search(root, 4) << endl;
    cout << search(root, 9) << endl;

    return 0;
}