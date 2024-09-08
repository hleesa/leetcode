class Solution {
public:
    bool isPalindrome(string s) {
        string str;
        for(auto ch : s){
            if (!isalpha(ch) && !isdigit(ch)) continue;
            str += tolower(ch);
        }
        int n = str.size();
        string back = str.substr(n/2);
        reverse(back.begin(), back.end());
        return str.substr(0, n/2 + n%2) == back;
    }
};