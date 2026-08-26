class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> window, ref;
        int n = s.size(), have = 0;
        int shortest = INT_MAX, start = 0, end = 0;

        if(!t.size())
            return "";
        
        for(int i = 0; i < t.size(); i++) 
            ref[t[i]]++;

        int need = ref.size();

        for(int l = 0, r = 0; r < n; r++) {
            char c = s[r];
            if(ref.contains(c)) {
                window[c]++;
                if(window[c] == ref[c])
                    have++;
            }
        
            while(have == need) {
                if(r - l + 1 < shortest) {
                    shortest = r - l + 1;
                    start = l;
                    end = r;
                }
                char c = s[l];
                if(ref.contains(c)) {
                    window[c]--;
                    if(window[c] < ref[c])
                        have--;
                }
                l++;
                
            }

        }
        return (shortest == INT_MAX) ? "" : s.substr(start, end - start + 1);
    }
};
