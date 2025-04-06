class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        const int n = nums.size();
        vector<int> dp(n,1), prev(n,-1);
        for(int i = 1; i < n; ++i){
            for(int j = 0; j < i; ++j){
                if(nums[i] % nums[j] == 0 || nums[j] % nums[i] == 0){
                    if(dp[j] + 1 > dp[i]) {
                        prev[i] = j;
                        dp[i] = dp[j] + 1;
                    }
                }
            }
        }

        int idx = 0;
        for(int i = 1; i < n; ++i){
            if (dp[i] > dp[idx]){
                idx = i;
            }
        }

        vector<int> ans;
        while(idx != -1){
            ans.push_back(nums[idx]);
            idx = prev[idx];
        }
        return ans;
    }
};
