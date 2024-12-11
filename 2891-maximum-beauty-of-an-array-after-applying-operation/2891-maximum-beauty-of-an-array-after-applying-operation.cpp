class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        const int n = nums.size();
        int r = 0;
        int ans = 1;
        for(int l = 0; l < n; ++l){
            while(r < n && nums[r] - nums[l] <= 2 * k) ++r;
            ans = max(r-l, ans);
        }
        return ans;
    }
};
