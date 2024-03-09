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
    void preOrder(TreeNode* root, string path, vector<string>& paths) {
    if (root == NULL) {
        return;
    }
    if (path.empty()) {
        path = to_string(root->val);
    } else {
        path += "->" + to_string(root->val);
    }
    if (root->left == NULL && root->right == NULL) {
        paths.push_back(path);
        return;
    }
    preOrder(root->left, path, paths);
    preOrder(root->right, path, paths);
}

vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> paths;
    preOrder(root, "", paths);
    return paths;
}
};