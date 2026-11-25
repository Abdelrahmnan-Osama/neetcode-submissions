class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        
        int exp = 0;
        for(int num = 0; num < n + 1; num++)
            exp ^= num;

        int act = 0;
        for(auto num : nums)
            act ^= num;

        return act ^ exp;
    }
};
