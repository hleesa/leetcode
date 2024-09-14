class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxValue = *max_element(nums.begin(), nums.end());
        int n = nums.size();
        int ret = 1;
        for(int i=0; i < n; ++i){
            if (nums[i] != maxValue) continue;

            int candi = 0;
            while(i < n && nums[i] == maxValue){
                ++candi;
                ++i;
            }
            if (candi > ret){
                ret = candi;
            }
            --i;
        }
        return ret;
    }
};