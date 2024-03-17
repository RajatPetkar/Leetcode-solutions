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

TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int& postIndex, int inorderStart, int inorderEnd) {
    if (inorderStart > inorderEnd) {
        return nullptr;
    }
    
    int element = postorder[postIndex--]; 
    TreeNode* temp = new TreeNode(element);
    
    if (inorderStart == inorderEnd) {
        return temp;
    }
    
    int position = findPosition(inorder, element, inorderStart, inorderEnd);
    
    temp->right = solve(inorder, postorder, postIndex, position + 1, inorderEnd); 
    temp->left = solve(inorder, postorder, postIndex, inorderStart, position - 1);

    return temp;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    int postIndex = postorder.size() - 1; 
    return solve(inorder, postorder, postIndex, 0, inorder.size() - 1);
}
    };
