//// Validate Binary Search Tree
#include <iostream>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isValidBSTUtil(TreeNode* root, long long minVal, long long maxVal) {
    if (!root) return true;
    if (root->val <= minVal || root->val >= maxVal) return false;
    return isValidBSTUtil(root->left, minVal, root->val) &&
           isValidBSTUtil(root->right, root->val, maxVal);
}

bool isValidBST(TreeNode* root) {
    return isValidBSTUtil(root, LLONG_MIN, LLONG_MAX);
}

int main() {
    // Example 1: Valid BST
    TreeNode* root1 = new TreeNode(2);
    root1->left = new TreeNode(1);
    root1->right = new TreeNode(3);
    cout << "Is tree 1 a BST? " << (isValidBST(root1) ? "true" : "false") << endl;

    // Example 2: Invalid BST
    TreeNode* root2 = new TreeNode(5);
    root2->left = new TreeNode(1);
    root2->right = new TreeNode(4);
    root2->right->left = new TreeNode(3);
    root2->right->right = new TreeNode(6);
    cout << "Is tree 2 a BST? " << (isValidBST(root2) ? "true" : "false") << endl;

    
    return 0;
}
