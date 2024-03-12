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
bool solve(TreeNode* root, vector<int>& path, int currentSum, int targetSum) {
    if (root == nullptr) {
        return false;
    }

    currentSum += root->val;

    path.push_back(root->val);
    if (root->left == nullptr && root->right == nullptr && currentSum == targetSum) {
        return true;
    }

    bool leftPath = solve(root->left, path, currentSum, targetSum);
    bool rightPath = solve(root->right, path, currentSum, targetSum);

    if (leftPath || rightPath) {
        return true;
    }
    path.pop_back();
    return false;
}

bool hasPathSum(TreeNode* root, int targetSum) {
    vector<int> path;
    return solve(root, path, 0, targetSum);
}


};