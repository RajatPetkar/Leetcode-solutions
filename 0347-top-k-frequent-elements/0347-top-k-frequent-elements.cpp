class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        typedef pair<int,int> pp;
        
        unordered_map<int,int> mp;
        for(int x : nums) {
            mp[x]++;
        }

        priority_queue<pp, vector<pp>, greater<pp>> pq;

        for(auto &it : mp) {
            pq.push({it.second, it.first});
            if(pq.size() > k) {
                pq.pop();
            }
        }

        vector<int> ans;
        while(!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans; 
    }
};
