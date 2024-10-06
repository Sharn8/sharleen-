#include <iostream>
using namespace std;

struct Node {
    int key;     
    Node* left;  
    Node* right; 

    Node(int value) : key(value), left(nullptr), right(nullptr) {}
};

void postOrder(Node* root) {
    if (root != nullptr) {
        postOrder(root->left);   
        postOrder(root->right);  
        cout << root->key << " ";  
    }
}

int main() {
    Node* root = new Node(1);    
    root->left = new Node(2);   
    root->right = new Node(3);       
    root->left->left = new Node(4); 
    root->left->right = new Node(5);   

    cout << "Postorder traversal of the binary tree is: ";
    postOrder(root);

    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}