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
    TreeNode* solve(vector<int>& preorder, vector<int>& postorder, int& preIndex, int postStart, int postEnd) {
    if (preIndex >= preorder.size() || postStart > postEnd) {
        return nullptr;
    }
    
    int element = preorder[preIndex++];
    TreeNode* temp = new TreeNode(element);
    
    if (preIndex >= preorder.size() || postStart == postEnd) {
        return temp;
    }
    
    int leftChild = preorder[preIndex];
    int position = -1;
    for (int i = postStart; i < postEnd; ++i) {
        if (postorder[i] == leftChild) {
            position = i;
            break;
        }
    }
    
    if (position != -1) {
        temp->left = solve(preorder, postorder, preIndex, postStart, position);
        temp->right = solve(preorder, postorder, preIndex, position + 1, postEnd - 1);
    }
    
    return temp;
}

TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
    int preIndex = 0;
    int postStart = 0;
    int postEnd = postorder.size() - 1;
    return solve(preorder, postorder, preIndex, postStart, postEnd);
}
};