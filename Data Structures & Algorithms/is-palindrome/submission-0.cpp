class Solution {
public:
    bool isPalindrome(string s) {
        string str = "";
        for(auto&& c : s) {
            if(!isalnum(c)) continue;
            str += tolower(c);
        }

        int n = str.size();
        int i = 0, j = n - 1;

        cout << str << endl;
        while(i < j) {
            if(str[i] != str[j])
                return false;

            i++;
            j--;
        }
        return true;
    }
};
