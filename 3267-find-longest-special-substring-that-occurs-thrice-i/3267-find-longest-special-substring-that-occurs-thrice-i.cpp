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
            priority_queue<int> pq;
            for(int i = 0; i < n; ++i){
                pq.push(dp[ch][i]);
            }
            pq.pop(); pq.pop();
            if (pq.top() == 0) continue;
            ans = max(pq.top(), ans);
        }
        
        return ans;
    }
};