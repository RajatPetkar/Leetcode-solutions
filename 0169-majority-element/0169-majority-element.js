class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        map<int,int> mapp;
        
        for(int i=0;i<n;i++){
            mapp[nums[i]]++;
        }
        
        for (auto it : mapp) {
        if (it.second > (n / 2)) {
            return it.first;
        }
    }

    return -1;
    }
};