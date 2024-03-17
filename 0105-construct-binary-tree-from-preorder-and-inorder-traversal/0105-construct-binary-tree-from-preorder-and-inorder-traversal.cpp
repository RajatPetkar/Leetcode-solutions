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
    
    int findPosition(vector<int>& inorder, int element, int inorderStart, int inorderEnd) {
    for (int i = inorderStart; i <= inorderEnd; ++i) {
        if (inorder[i] == element) {
            return i;
        }
    }
    return -1;
}

TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int& preIndex, int inorderStart, int inorderEnd) {
    if (inorderStart > inorderEnd) {
        return nullptr;
    }
    
    int element = preorder[preIndex++];
    TreeNode* temp = new TreeNode(element);
    
    if (inorderStart == inorderEnd) {
        return temp;
    }
    
    int position = findPosition(inorder, element, inorderStart, inorderEnd);
    
    temp->left = solve(preorder, inorder, preIndex, inorderStart, position - 1);
    temp->right = solve(preorder, inorder, preIndex, position + 1, inorderEnd);

    return temp;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int preIndex = 0;
    return solve(preorder, inorder, preIndex, 0, inorder.size() - 1);
}
};