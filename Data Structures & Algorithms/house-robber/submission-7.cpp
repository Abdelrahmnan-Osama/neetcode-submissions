class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
            return 0;

        int twoAhead = 0, oneAhead = 0;
        for(int i = n - 1; i >= 0; i--) {
            int curr = max(nums[i] + twoAhead, oneAhead);
            twoAhead = oneAhead;
            oneAhead = curr;
        }
        return oneAhead;
    }
};
