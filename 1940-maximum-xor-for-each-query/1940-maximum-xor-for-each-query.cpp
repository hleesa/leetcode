class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        const int n = nums.size();
        vector<int> ans(n);
        int val = 0;
        for(int i = 0; i < n; ++i){
            val ^= nums[i];
            int k = ((1 << maximumBit) - 1) ^ val;
            ans[n-1-i] = k;
        }
        return ans;
    }
};
