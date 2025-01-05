class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        const int n = s.length();
        const int mod = 26;
        vector<int> pShift(n+1);
        for(const auto& shift : shifts){
            int sign = shift.back() == 1 ? 1 : -1;
            pShift[shift[0]] = (pShift[shift[0]] + sign + mod) % mod;
            pShift[shift[1]+1] = (pShift[shift[1]+1] -sign + mod) % mod;
        }
        string ans;
        int cur = 0;
        for(int i = 0; i < n; ++i){
            cur += pShift[i];
            ans.push_back((s[i] - 'a' + cur + mod) %mod + 'a');
        }
        return ans;
    }
};