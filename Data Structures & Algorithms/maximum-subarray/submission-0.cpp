class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur = 0;
        int maxSum = INT_MIN;
        for(auto num : nums) {
            cur = max(cur + num, num);
            maxSum = max(maxSum, cur);
        }
        return maxSum;
    }
};
