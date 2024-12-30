class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<vector<int>> dp(high+1, vector<int>(2,0));
        dp[zero][0] = 1;
        dp[one][1] = 1;
        const int mod = 1e9+7;
        for(int i = 2; i <= high; ++i){
            if (i >= zero){
                dp[i][0] += (dp[i-zero][0] + dp[i-zero][1]) % mod;
            }
            if (i >= one){
                dp[i][1] += (dp[i-one][0] + dp[i-one][1]) % mod;
            }
        }
        int ans = 0;
        for(int i = low; i <= high; ++i){
            ans = (ans + (dp[i][0] + dp[i][1]) % mod ) % mod;
        }
        return ans;
    }
};