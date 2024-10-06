#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int data;     
    Node* left;   
    Node* right;  

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

int maxPathSumUtil(Node* root, int &maxSum) {
    if (root == nullptr) return 0; 

    int leftMax = max(0, maxPathSumUtil(root->left, maxSum));  
    int rightMax = max(0, maxPathSumUtil(root->right, maxSum));

    int currentMax = root->data + leftMax + rightMax;

    maxSum = max(maxSum, currentMax);

    return root->data + max(leftMax, rightMax);
}

int maxPathSum(Node* root) {
    int maxSum = INT_MIN; 
    maxPathSumUtil(root, maxSum); 
    return maxSum; 
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(2);
    root->right = new Node(10);
    root->left->left = new Node(20);
    root->left->right = new Node(1);
    root->right->right = new Node(-25);
    root->right->right->left = new Node(3);
    root->right->right->right = new Node(4);

    cout << "Maximum path sum is: " << maxPathSum(root) << endl;

    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right->right->left;
    delete root->right->right->right;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}