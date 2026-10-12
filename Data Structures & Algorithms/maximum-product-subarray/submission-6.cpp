class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
            return 0;
        int curMax = nums[0], curMin = nums[0];
        int maxProd = curMax;
        for(int i = 1; i < n; i++) {
            int temp = curMin;
            curMin = min(curMin * nums[i], min(curMax * nums[i],  nums[i]));
            curMax = max(temp * nums[i], max(curMax * nums[i],  nums[i]));
            maxProd = max(maxProd, curMax);
        }
        return maxProd;
    }
};
