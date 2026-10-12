class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
            return 0;
        vector<pair<int, int>> dp(n);
        dp[0] = {nums[0], nums[0]};
        int maxProd = dp[0].second;
        for(int i = 1; i < n; i++) {
            dp[i].first = min(dp[i-1].first * nums[i], min(dp[i-1].second * nums[i],  nums[i]));
            dp[i].second = max(dp[i-1].first * nums[i], max(dp[i-1].second * nums[i],  nums[i]));
            maxProd = max(maxProd, dp[i].second);
        }
        return maxProd;
    }
};
