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
…        }
        return false;
    }
};
**/

class BSTIterator {
    stack<TreeNode*> myStack;
    bool reverse;

public:
    BSTIterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }
    
    int next() {
        TreeNode* temp = myStack.top();
        myStack.pop();

        if(reverse)
            pushAll(temp->left);
        else
            pushAll(temp->right);

        return temp->val; 
    }
    
    bool hasNext() {    
        return !myStack.empty();
    }

private:
    void pushAll(TreeNode* node){
        while(node != nullptr){
            myStack.push(node);
            if(reverse)
                node = node->right;
            else
                node = node->left;
        }
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(root == nullptr) return false;

        BSTIterator l(root, false);  // ascending
        BSTIterator r(root, true);   // descending

        int i = l.next();
        int j = r.next();

        while(i < j){
            if(i + j == k) return true;
            else if(i + j < k) i = l.next();
            else j = r.next();
        }

        return false;
    }
};