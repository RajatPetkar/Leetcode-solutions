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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> list;
        if(root==NULL) return list;

         if(root->left) {
        vector<int> left_list = inorderTraversal(root->left);
        list.insert(list.end(), left_list.begin(), left_list.end());
     }
    
    list.push_back(root->val);

    if(root->right) {
        vector<int> right_list = inorderTraversal(root->right);
        list.insert(list.end(), right_list.begin(), right_list.end());
    }
        return list;
    }
};