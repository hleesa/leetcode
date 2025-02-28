class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        const int len1 = str1.length();
        const int len2 = str2.length();
        vector<vector<int>> dp(len1+1,vector<int>(len2+1,0));

        for(int i = 1; i <= len1; ++i){
            for(int j = 1; j <= len2; ++j){
                if(str1[i-1] == str2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        string ans;
        int i = len1, j = len2;
        while(i > 0 || j > 0){
            if(i > 0 && j > 0 && str1[i-1] == str2[j-1]){
                ans = str1[i-1] + ans;
                --i;--j;
            }
            else if(j == 0 || (i>0 && dp[i-1][j] >= dp[i][j-1])){
                ans = str1[i-1] + ans;
                --i;
            }
            else{
                ans = str2[j-1] + ans;
                --j;
            }
        }

        return ans;
    }
};