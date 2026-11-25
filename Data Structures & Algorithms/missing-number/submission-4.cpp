class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        int exp = n;
        for(int i = 0; i < n; i++)
            exp ^= i ^ nums[i];

        return exp;
    }
};
