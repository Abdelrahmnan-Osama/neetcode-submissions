class Solution {
   public:
    string encode(vector<string>& strs) {
        string encoded = "";
        for (auto&& str : strs) {
            encoded += to_string(str.size()) + '#' + str;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> decoded;
        for(int i = 0; i < s.size();) {
            int pos = s.find('#', i);
            int len = stoi(s.substr(i, pos - i));
            i = pos + 1;
            string word = s.substr(i, len);
            decoded.push_back(word);
            i+= len;
        }
        return decoded;
    }
};
