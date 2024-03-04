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
    void solve(TreeNode* &root, int& maxDepth, int& leftValue, int depth){
        if(root==NULL){
            return;
        }
        if (depth > maxDepth) {
        maxDepth = depth;
        leftValue = root->val;
    }

    solve(root->left, maxDepth, leftValue, depth + 1);
    solve(root->right, maxDepth, leftValue, depth + 1);
}

int findBottomLeftValue(TreeNode* root) {
    int maxDepth = 0;
    int leftValue = root->val;
    solve(root, maxDepth, leftValue, 0);
    return leftValue;
}
};