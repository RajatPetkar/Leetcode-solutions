/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    queue<int> q1, q2;
    preorder(root1, q1);
    preorder(root2, q2);
    
    return q1 == q2;
}

void preorder(TreeNode* root, queue<int>& q) {
    if (root == NULL) {
        return;
    }
    
    if (root->left == NULL && root->right == NULL) {
        q.push(root->val);
        return;
    }
    
    preorder(root->left, q);
    preorder(root->right, q);
}

};