#include <iostream>
using namespace std;

struct Node {
    int key;     
    Node* left;   
    Node* right;  

    Node(int value) : key(value), left(nullptr), right(nullptr) {}
};

void preOrder(Node* root) {
    if (root != nullptr) {
        cout << root->key << " "; 
        preOrder(root->left);      
        preOrder(root->right);   
    }
}

int main() {
    Node* root = new Node(1);   
    root->left = new Node(2);       
    root->right = new Node(3);     
    root->left->left = new Node(4);   
    root->left->right = new Node(5);  

    cout << "Preorder traversal of the binary tree is: ";
    preOrder(root);  

    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}