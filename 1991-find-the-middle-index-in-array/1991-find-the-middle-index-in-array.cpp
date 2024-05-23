class Solution {
public:
      int findMiddleIndex(vector<int>& nums) {
        int n = nums.size();
        int leftSum = 0, totalSum = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            totalSum += nums[i];
        }

        for(int i = 0; i < nums.size(); i++)
        {
            if(leftSum == totalSum-leftSum - nums[i]) // sum of leftSum == sum of rightSum
            return i; 
            leftSum += nums[i];
        }


        return -1;
    }
};