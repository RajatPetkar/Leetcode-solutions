class Solution {
public:
    vector<int> power(vector<int>& nums){
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            ans.push_back(nums[i]*nums[i]);
        }  
        sort(ans.begin(),ans.end());
        return ans;
    }
    vector<int> sortedSquares(vector<int>& nums) {
        return power(nums);
    }
};