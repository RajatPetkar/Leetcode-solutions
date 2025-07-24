class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int closest = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < nums.size() - 2; ++i) {
            int low = i + 1, high = nums.size() - 1;

            while (low < high) {
                int sum = nums[i] + nums[low] + nums[high];

                if (abs(sum - target) < abs(closest - target)) {
                    closest = sum;
                }

                if (sum < target) {
                    ++low;
                } else if (sum > target) {
                    --high;
                } else {
                    return sum;
                }
            }
        }

        return closest;
    }
};
