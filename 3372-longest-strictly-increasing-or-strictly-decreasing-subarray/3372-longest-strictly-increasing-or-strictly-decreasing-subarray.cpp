class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        const int n = nums.size();
        int longSub = 1;

        for(int i = 0; i + 1 < n; ++i){
            int asc = 1, desc = 1;
            for(int j = i; j + 1 < n && nums[j+1] > nums[j]; ++j){
                ++asc;
            }
            for(int j = i ; j + 1 < n && nums[j+1] < nums[j]; ++j){
                ++desc;
            }
            longSub = max({asc, desc, longSub});
        }

        return longSub;
    }
};