class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int result = coinChangeHelper(coins, amount);
        return (result == INT_MAX) ? -1 : result; 
    }

private:
    unordered_map<int, int> memo;

    int coinChangeHelper(vector<int>& coins, int amount) {
        if(amount == 0)
            return 0;

        int minn = INT_MAX;
        if(!memo.contains(amount)) {    
            for(const auto& coin : coins) {
                if(coin <= amount) {
                    int newAmountChange = coinChangeHelper(coins, amount - coin);
                    if(!(newAmountChange == INT_MAX))
                        minn = min(minn, 1 + newAmountChange);
                }       
            }
            memo[amount] = minn;
        }

        return memo[amount];
    }
};
