class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        sort(nums.begin(),nums.end());
        int lastsmaller = INT_MIN;
        int largets = 1;
        int cnt = 0;

        for(int i=0;i<nums.size();i++){
            if(nums[i]-1 == lastsmaller){
                cnt++;
                lastsmaller = nums[i];
            }else if(nums[i] != lastsmaller){
                cnt = 1;
                lastsmaller = nums[i];
            }
            largets = max(largets, cnt);
        }
        return largets;
    }
};