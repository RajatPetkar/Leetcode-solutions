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
vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        queue<pair<TreeNode*, pair<int, int>>>q; 
        q.push({root,{0,0}});
        map<int, map<int, multiset<int>>>mp;
        while(!q.empty()){
            auto front = q.front();
            q.pop();

            TreeNode* &node = front.first;
            auto coordinate = front.second;
            auto &row = coordinate.first;
            auto &col = coordinate.second;
            mp[col][row].insert(node -> val);
            if(node -> left){
                q.push({{node -> left},{row + 1, col - 1}});
            }
            if(node -> right){
                q.push({{node -> right},{row + 1, col + 1}});
            }
        }
        for(auto i:mp){
            auto &colmp = i.second;
            vector<int> verticalLine;
            for(auto colmpi : colmp){
                auto &mset = colmpi.second;
                verticalLine.insert(verticalLine.end(), mset.begin(), mset.end());
            }
            ans.push_back(verticalLine);
        }
        return ans;
    }
};