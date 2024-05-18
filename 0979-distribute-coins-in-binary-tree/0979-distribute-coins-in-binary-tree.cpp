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
    int calculateBalance(TreeNode* node, int& steps) {
        if (node == nullptr) {
            return 0;
        }

        int leftBalance = calculateBalance(node->left, steps);
        int rightBalance = calculateBalance(node->right, steps);

        steps += abs(leftBalance) + abs(rightBalance);
        return node->val + leftBalance + rightBalance - 1;
    }

    int distributeCoins(TreeNode* root) {
        int steps = 0;
        calculateBalance(root, steps);
        return steps;
    }
};