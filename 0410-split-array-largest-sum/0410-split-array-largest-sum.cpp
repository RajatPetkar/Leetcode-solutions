class Solution {
public:
    bool canSplit(vector<int>& nums, int maxSumAllowed, int k) {
        int currentSum = 0;
        int countSubarrays = 1; 

        for (int num : nums) {
            if (currentSum + num > maxSumAllowed) {
                countSubarrays++;
                currentSum = 0;
            }
            currentSum += num;
        }

        return countSubarrays <= k;
    }

    int splitArray(vector<int>& nums, int k) {
        int left = *max_element(nums.begin(), nums.end()); 
        int right = accumulate(nums.begin(), nums.end(), 0); 

    
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canSplit(nums, mid, k)) {
                right = mid;
            } else {
                left = mid + 1; 
            }
        }
        return left; 
    }
};
