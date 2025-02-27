class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        const int n = arr.size();
        unordered_map<int ,int> iMap;
        vector<vector<int>> dp(n, vector<int>(n, 2));
        for(int i = 0 ; i < n; ++i){
            iMap[arr[i]] = i;
        }

        int maxLen = 0;
        for(int k = 0; k < n; ++k){
            for(int j = 0; j < k; ++j){
                int prev = arr[k] - arr[j];

                if (iMap.count(prev) && iMap[prev] < j){
                    int i = iMap[prev];
                    dp[j][k] = dp[i][j] + 1;
                    maxLen = max(dp[j][k], maxLen);
                }
            }
        }
        return maxLen;
    }
};