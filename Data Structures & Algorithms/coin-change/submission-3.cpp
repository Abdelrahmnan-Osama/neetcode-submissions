class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int result = coinChangeHelper(coins, amount);
        return (result == INT_MAX) ? -1 : result; 
    }

private:
    int coinChangeHelper(vector<int>& coins, int amount) {
        if(amount == 0)
            return 0;

        vector<int> dp(amount+1);  
        dp[0] = 0;
        for(int t = 1; t < amount + 1; t++) {
            int minn = INT_MAX;
            for(const auto& coin : coins) {
                if(coin <= t) {
                    int newAmountChange = dp[t - coin];
                    if(!(newAmountChange == INT_MAX))
                        minn = min(minn, 1 + newAmountChange);
                }       
            }
            dp[t] = minn;
        }

        return dp[amount];
    }
};
