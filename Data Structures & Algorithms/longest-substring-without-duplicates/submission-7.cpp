class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> pos(256, -1);
        int n = s.size();
        int longest = 0;
        for(int l = 0, r = 0; r < n; r++) {
            if(pos[s[r]] >= l) {
                l = pos[s[r]] + 1;
            }
            longest = max(longest, r - l + 1);
            pos[s[r]] = r;
        }
        
        return longest;
    }
};
