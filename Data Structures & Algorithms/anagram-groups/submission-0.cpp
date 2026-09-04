class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        for(const auto& str : strs) {
            vector<int> freq(26, 0);
            for(const auto& ch : str) {
                freq[ch - 'a']++;
            }
            string key = to_string(freq[0]);
            for(int i = 1; i < 26; i++) {
                key += ',' + to_string(freq[i]);
            }
            groups[key].push_back(str);
        }
        vector<vector<string>> result;
        for(const auto& p : groups) {
            result.push_back(p.second);
        }

        return result;
    }
};
