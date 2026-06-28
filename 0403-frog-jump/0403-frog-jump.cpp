class Solution {
public:
    int n;
    unordered_map<int,int> mp;
    vector<vector<int>> dp;

    bool solve(vector<int>& stones, int i, int k) {
        if (i == n - 1)
            return true;
        if (dp[i][k] != -1)
            return dp[i][k];
        for (int jump = k - 1; jump <= k + 1; jump++) {
            if (jump <= 0)
                continue;
            int nextStone = stones[i] + jump;
            if (mp.count(nextStone)) {
                int j = mp[nextStone];
                if (solve(stones, j, jump))
                    return dp[i][k] = true;
            }
        }
        return dp[i][k] = false;
    }

    bool canCross(vector<int>& stones) {
        n = stones.size();
        if (stones[1] != 1)
            return false;
        for (int i = 0; i < n; i++)
            mp[stones[i]] = i;
        dp.resize(n, vector<int>(n + 1, -1));
        return solve(stones, 1, 1);
    }
};