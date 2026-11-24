class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> counts(n + 1, 0);
        for(int i = 0; i < n + 1; i++) {
            int x = i;
            while(x > 0) {
                counts[i] += (x & 1);
                x >>= 1;
            }
        }
        return counts;
    }
};
