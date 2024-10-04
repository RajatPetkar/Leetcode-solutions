class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int> mp;
        mp[0] = 1;
        
        int presum = 0;
        int cnt = 0;
        
        for(int i=0;i<n;i++){
            presum+=nums[i];
            int remove = presum-k;
            cnt+=mp[remove];
            
            mp[presum]++;
            
        }
        return cnt;
    }
};