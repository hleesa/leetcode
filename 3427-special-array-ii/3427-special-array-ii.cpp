class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        const int n = nums.size();
        vector<int> prefix(n, 0);
        prefix[0] = 0;
        for(int i = 1; i < n; ++i){
            prefix[i] = prefix[i-1] + (nums[i-1] % 2 == nums[i] % 2);
        }
        
        vector<bool> ans;
        for(const auto& q: queries){
            ans.push_back(prefix[q.front()] == prefix[q.back()]);
        }

        return ans;
    }
};