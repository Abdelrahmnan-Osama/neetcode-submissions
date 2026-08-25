class Solution {
public:
    int characterReplacement(string s, int k) {
        int freq[26] = {0};
        int max_freq = 0, max_len = 0;
        int n = s.size();
        for(int l = 0, r = 0; r < n; r++) {
            freq[s[r] - 'A']++;
            max_freq = max(max_freq, freq[s[r]- 'A']);
            int replacements = (r - l + 1) - max_freq;
            if(replacements > k) {
                freq[s[l] - 'A']--;
                l++;
            }
            max_len = r - l + 1;
        }   
        return max_len;
    }
};