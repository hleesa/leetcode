class Solution {
public:
    bool isPalindrome(string s) {
        string str;
        for(auto ch : s){
            if (!isalnum(ch)) continue;
            str.push_back(tolower(ch));
        }
        int begin = 0, end = str.size() - 1;
        while(begin < end){
            if(str[begin] != str[end]){
                return false;
            }
            ++begin;
            --end;
        }
        return true;
    }
};
