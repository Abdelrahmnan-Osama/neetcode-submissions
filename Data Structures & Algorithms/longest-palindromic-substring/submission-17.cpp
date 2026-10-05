class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int start = 0, maxLen = 0;
        for(int center = 0; center < n; center++) {
            const auto& [oddStart, oddLen] = expandPal(center, center, s);
            if(oddLen > maxLen) {
                maxLen = oddLen;
                start = oddStart;
            }
            if(center < n - 1 && s[center] == s[center + 1]) {
                const auto& [evenStart, evenLen] = expandPal(center, center+1, s);
                if(evenLen > maxLen) {
                    maxLen = evenLen;
                    start = evenStart;
                }
            }
        }
        return s.substr(start, maxLen);
    }

private:
    pair<int, int> expandPal(int left, int right, const string& s) {
        while(left > 0 && right < s.size() - 1 && s[left - 1] == s[right + 1]) {
            left -= 1;
            right += 1;
        }
        return {left, right - left + 1};
    }
};
