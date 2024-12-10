class Solution {
public:
    int maximumLength(string s) {
        const int n = s.length();
        vector<vector<int>> dp(26, vector<int>(n, 0));

        dp[s.front()-'a'][0] = 1;
        for(int i = 1; i < n; ++i){
            char ch = s[i] - 'a';
            dp[ch][i] = dp[ch][i-1] + 1;
        }

        int ans = -1;
        for(int ch = 0; ch < 26; ++ch){
            sort(dp[ch].begin(), dp[ch].end());
            if(dp[ch][n-3] == 0) continue;
            ans = max(dp[ch][n-3], ans);
        }

        return ans;
    }
};