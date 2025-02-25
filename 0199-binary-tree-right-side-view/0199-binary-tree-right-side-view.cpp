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
vector<int> View(TreeNode* root, int level, vector<int>& ans) {
    if (root == NULL) {
        return ans;
    }
    if (level == ans.size()) {
        ans.push_back(root->val);
    }
    View(root->right, level + 1, ans);
    View(root->left, level + 1, ans);
    return ans;
}

vector<int> rightSideView(TreeNode* root) {
    vector<int> ans;
    View(root, 0, ans);
    return ans;
}
};