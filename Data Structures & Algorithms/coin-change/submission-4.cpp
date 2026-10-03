class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int result = coinChangeHelper(coins, amount);
        return (result > amount) ? -1 : result; 
    }

private:
    unordered_map<int, int> memo;

    int coinChangeHelper(vector<int>& coins, int amount) {
        if(amount == 0)
            return 0;

        int minn = 1e5;
        if(!memo.contains(amount)) {    
            for(const auto& coin : coins) {
                if(coin <= amount) {
                    minn = min(minn, 1 + coinChangeHelper(coins, amount - coin));
                }       
            }
            memo[amount] = minn;
        }

        return memo[amount];
    }
};
