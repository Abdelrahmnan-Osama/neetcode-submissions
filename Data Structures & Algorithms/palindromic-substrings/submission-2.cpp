class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int totalPals = 0;
        for(int center = 0; center < n; center++) {
            totalPals += expandPal(s, center, center);
            if(s[center] == s[center + 1])
                totalPals += expandPal(s, center, center + 1);
        }
        return totalPals;
    }

private:
    int expandPal(const string& s, int left, int right) {
        int totalPals = 1;
        while(left > 0 && right < s.size() && s[left - 1] == s[right + 1]) {
            left--;
            right++;
            totalPals++;
        }
        return totalPals;
    }
};
