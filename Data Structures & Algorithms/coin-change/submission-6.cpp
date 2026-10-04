class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, amount+1);  
        dp[0] = 0;
        for(int t = 1; t < amount + 1; t++) {
            for(const auto& coin : coins) {
                if(coin <= t)
                    dp[t] = min(dp[t], 1 + dp[t - coin]);     
            }
        }
        
        return (dp[amount] > amount) ? -1 : dp[amount];
    }
};
