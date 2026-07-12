class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> temp = arr;
        sort(temp.begin(), temp.end());

        unordered_map<int, int> rank;
        int cnt = 1;

        for (int x : temp) {
            if (rank.find(x) == rank.end()) { //if not found 
                rank[x] = cnt++;
            }
        }

        vector<int> ans;
        for (int x : arr) {
            ans.push_back(rank[x]);
        }

        return ans;
    }
};