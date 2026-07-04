class Solution {
public:
    vector<vector<vector<long long>>> dp;

    long long f(vector<int>& prices, int ind, int state, int k) {
        if (ind == prices.size()) {
            if (state == 0)
                return 0;
            return -(long long)1e18;
        }

        if (k == 0) {
            return state == 0 ? 0 : -(long long)1e18;
        }

        if (dp[ind][state][k] != -1)
            return dp[ind][state][k];

        long long ans = 0;

        if (state == 0) {
            long long buy = -prices[ind] + f(prices, ind + 1, 1, k);

            long long shortSell = prices[ind] + f(prices, ind + 1, 2, k);

            long long skip = f(prices, ind + 1, 0, k);

            ans = max({buy, shortSell, skip});
        } else if (state == 1) {
            long long sell = prices[ind] + f(prices, ind + 1, 0, k - 1);

            long long hold = f(prices, ind + 1, 1, k);

            ans = max(sell, hold);
        } else {
            long long buyBack = -prices[ind] + f(prices, ind + 1, 0, k - 1);

            long long hold = f(prices, ind + 1, 2, k);

            ans = max(buyBack, hold);
        }

        return dp[ind][state][k] = ans;
    }

    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        dp.assign(n,
                  vector<vector<long long>>(3, vector<long long>(k + 1, -1)));
        return f(prices, 0, 0, k);
    }
};