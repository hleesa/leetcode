class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        const int n = nums.size();
        vector<int> ans;

        int val = nums.front();
        for(int i = 1; i < n; ++i){
            val ^= nums[i];
        }
        for(int i = 0; i < n; ++i){
            int k = ((1 << maximumBit) - 1) ^ val;
            ans.push_back(k);
            val ^= nums[n-1-i];
        }
        
        return ans;
    }
};
