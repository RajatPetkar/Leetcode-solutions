class Solution {
public:
    vector<vector<int>> dp;

    int fn(vector<int>& nums, int i, int j) {
        if (i == j)
            return nums[i];

        if (dp[i][j] != -1)
            return dp[i][j];

        int left = nums[i] - fn(nums, i + 1, j);
        int right = nums[j] - fn(nums, i, j - 1);

        return dp[i][j] = max(left, right);
    }

    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        dp.assign(n, vector<int>(n, -1));
        return fn(nums, 0, n - 1) >= 0;
    }
};