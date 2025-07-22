class Solution {
public:
    // int maximumUniqueSubarray(vector<int>& nums) {
    //    unordered_set<int> set;
    //    int maxSum = 0, currSum = 0;
    //    int left = 0;

    //     for (int right = 0; right < nums.size(); ++right) {
    //         while (set.count(nums[right])) {
    //             currSum -= nums[left];
    //             set.erase(nums[left]);
    //             ++left;
    //         }
    //         set.insert(nums[right]);
    //         currSum += nums[right];
    //         maxSum = max(maxSum, currSum);
    //     }
    //     return maxSum;
    // }

    int maximumUniqueSubarray(vector<int>& nums) {
    unordered_map<int, int> lastIndex;
    int maxSum = 0, currSum = 0;
    int left = 0;
    for (int right = 0; right < nums.size(); ++right) {
        if (lastIndex.count(nums[right]) && lastIndex[nums[right]] >= left) {
            int prevIdx = lastIndex[nums[right]];
            for (int i = left; i <= prevIdx; ++i) {
                currSum -= nums[i];
            }
            left = prevIdx + 1;
        }
        currSum += nums[right];
        lastIndex[nums[right]] = right;
        maxSum = max(maxSum, currSum);
    }
    return maxSum;
}
};