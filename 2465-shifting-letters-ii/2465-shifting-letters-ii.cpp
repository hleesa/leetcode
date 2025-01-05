class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        const int n = s.length();
        const int mod = 26;
        vector<int> in(n+1), out(n+1);
        for(const auto& shift : shifts){
            int sign = shift.back() == 1 ? 1 : -1;
            in[shift[0]] = (in[shift[0]] + sign + mod) % mod;
            out[shift[1]+1] = (out[shift[1]+1] -sign + mod) % mod;
        }
        string ans;
        int cur = 0;
        for(int i = 0; i < n; ++i){
            cur += in[i] + out[i];
            ans.push_back((s[i] - 'a' + cur + mod) %mod + 'a');
        }
        return ans;
    }
};