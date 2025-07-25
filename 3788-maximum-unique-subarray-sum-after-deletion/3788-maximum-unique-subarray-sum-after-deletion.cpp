class Solution {
public:
   int maxSum(vector<int>& nums) {         
   int result = INT_MIN, sum = 0;         
   sort(nums.begin(), nums.end());         
   for(int i = 0; i < nums.size(); i++)         
   {             
       if(i < nums.size() - 1 && nums[i] == nums[i+1]) {
           continue;
       }
       sum += nums[i];             
       result = max(result, sum);
       if(nums[i] < 0) {
           sum = 0;  // Reset sum after negative number
       }
   }         
   return result;     
}
};