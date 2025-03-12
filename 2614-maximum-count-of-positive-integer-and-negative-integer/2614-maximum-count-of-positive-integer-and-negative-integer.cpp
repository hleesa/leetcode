class Solution {
public:
    int maximumCount(vector<int>& nums) {
        auto li = lower_bound(nums.begin(), nums.end(), 0) - nums.begin();
        auto ui = upper_bound(nums.begin(), nums.end(), 0) - nums.begin();
        return max(li, (int)nums.size() - ui);
    }
};