class Solution {
public:
    int solve(vector<int>& coins, int amount){
        if(amount == 0){
            return 0;
        }
        if(amount <0){
            return INT_MAX;
        }
        int mini = INT_MAX;
        for(int i=0;i<coins.size();i++){
            int ans = solve(coins,amount-coins[i]);
            if(ans!=INT_MAX){
                mini = min(mini,1+ans);
            }
        }
        return mini;
    }
    
    int solveMem(vector<int>& coins, int amount,vector<int> &dp){
        if(amount == 0){
            return 0;
        }
        if(amount <0){
            return INT_MAX;
        }
        if(dp[amount]!=-1){
            return dp[amount];
        }
        
        int mini = INT_MAX;
        for(int i=0;i<coins.size();i++){
            int ans = solve(coins,amount-coins[i]);
            if(ans!=INT_MAX){
                mini = min(mini,1+ans);
            }
        }
        dp[amount] = mini;
        return mini;
    }
    
    int solveTabu(vector<int>& coins, int amount){
       vector<int> dp(amount+1,INT_MAX);
        dp[0]=0;
        for(int i=1;i<=amount;i++){
            for(int j=0;j<coins.size();j++){
                if(i-coins[j]>=0 && dp[i-coins[j]] != INT_MAX ){
                    dp[i] = min(dp[i],1+dp[i-coins[j]]);
                }
            }
        }
        
        if(dp[amount]==INT_MAX){
            return -1;
        }
        return dp[amount];
    }
    
    int coinChange(vector<int>& coins, int amount) {
        // using reccursion - TLE
        // int ans = solve(coins,amount);
        // if(ans==INT_MAX){
        //     return -1;
        // }
        // return ans;
        
        //Using DP - TLE
        // vector<int> dp(amount+1,-1);
        // int ans = solveMem(coins,amount,dp);
        // if(ans==INT_MAX){
        //     return -1;
        // }
        // return ans;
        
        //Using Tabulation - Success
        return solveTabu(coins,amount);
    }
};