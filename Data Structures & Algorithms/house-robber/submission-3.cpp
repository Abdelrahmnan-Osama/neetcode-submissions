class Solution {
public:
    int rob(vector<int>& nums) {
        return dfs(nums, 0);
    }

private:
    unordered_map<int, int> dp;

    int dfs(const vector<int>& nums, int index) {
        int n = nums.size();
        if(index >= n)
            return 0;
        int a = 0, b = 0;
        for(int i = n - 1; i >=index; i--) {
            int curr = max(nums[i] + b, a);
            b = a;
            a = curr;
        }

        return a;
    }
};
