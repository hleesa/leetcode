class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> stot(255, -1), ttos(255,-1);
        for(size_t i = 0 ; i < s.length(); ++i){
            if(stot[s[i]] == -1) stot[s[i]] = t[i];
            if(ttos[t[i]] == -1) ttos[t[i]] = s[i];
            if(stot[s[i]] != t[i] || ttos[t[i]] != s[i]) return false;
        }

        return true;
    }
};