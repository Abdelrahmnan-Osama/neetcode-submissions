class Solution {
private:
    unordered_map<int, int> memo;
public:
    int climbStairs(int n) {
        if(n == 1 || n == 2)
            return n;
        if(!memo.contains(n))
            memo[n] = climbStairs(n - 1) + climbStairs(n - 2);

        return memo[n];
    }
};
