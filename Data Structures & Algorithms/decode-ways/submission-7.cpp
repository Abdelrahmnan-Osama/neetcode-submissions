class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();

        int two_before = (s[0] == '0') ? 0 : 1;
        if(n == 1)
            return two_before;

        int one_before = (s[1] != '0') ? two_before : 0;
        if(s[0] == '1' || (s[0] == '2' && s[1] < '7'))
                one_before++;

        for(int i = 2; i < n; i++) {
            int curr = (s[i] != '0') ? one_before : 0;

            if(s[i - 1] == '1' || (s[i - 1] == '2' && s[i] < '7'))
                curr += two_before;

            two_before = one_before;
            one_before = curr;
        }
        return one_before;
    }
};
