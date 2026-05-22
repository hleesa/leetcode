class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> stot(255, -1), ttos(255,-1);
        for(size_t i = 0 ; i < s.length(); ++i){
            int si = static_cast<unsigned char>(s[i]);
            int ti = static_cast<unsigned char>(t[i]);
            if(stot[si] == -1) stot[si] = ti;
            if(ttos[ti] == -1) ttos[ti] = si;
            if(stot[si] != ti || ttos[ti] != si) return false;
        }

        return true;
    }
};