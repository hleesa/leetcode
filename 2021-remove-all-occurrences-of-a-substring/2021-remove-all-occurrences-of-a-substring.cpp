class Solution {
public:
    string removeOccurrences(string s, string part) {
        string ans;
        const int sLen = s.length();
        const int pLen = part.length();
        for(int i = 0; i < sLen; ++i){
            ans += s[i];
            if(ans.length() >= pLen && ans.back() == part.back()){
                if(ans.substr(ans.length() - pLen) == part){
                    for(int j = 0; j < pLen; ++j){
                        ans.pop_back();
                    }
                }
            }
        }
        return ans;
    }
};