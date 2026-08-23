class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int l = 0, r = n - 1;
        int maxx = 0;
        for(int l = 0, r = l+1; r < n; r++) {
            if(prices[r] > prices[l])
                maxx = max(maxx, prices[r] - prices[l]);
            else
                l = r;
        }
        return maxx;
    }
};
