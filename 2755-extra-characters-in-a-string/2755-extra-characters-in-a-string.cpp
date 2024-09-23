class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        const int n = s.length();
        vector<int> dp(n+1, n);
        dp[0] = 0;

        for(int i = 0; i < n; ++i){
            dp[i+1] = min(dp[i+1], dp[i] + 1);

            for(const string& dict : dictionary){
                const int dictLen = dict.length();
                if (i + dictLen > n) continue;
                if (s.substr(i, dictLen) == dict){
                    dp[i + dictLen] = min(dp[i + dictLen], dp[i]);
                }
            }
        }
        
        return dp[n];
    }
};