class Solution {
public:
    int rob(vector<int>& nums) {
        return dfs(nums, 0);
    }

private:
    int dfs(const vector<int>& nums, int index) {
        int n = nums.size();
        if(index >= n)
            return 0;
        int twoAhead = 0, oneAhead = 0;
        for(int i = n - 1; i >=index; i--) {
            int curr = max(nums[i] + twoAhead, oneAhead);
            twoAhead = oneAhead;
            oneAhead = curr;
        }

        return oneAhead;
    }
};
