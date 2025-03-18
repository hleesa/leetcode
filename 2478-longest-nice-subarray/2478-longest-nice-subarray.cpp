class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        const int n = nums.size();
        int ans = 0;
        int bits = 0;
        int left = 0;

        for(int right = 0; right < n; ++right){
            while((bits & nums[right]) != 0){
                bits ^= nums[left];
                ++left;
            }
            bits |= nums[right];
            ans = max(right - left + 1, ans);
        }
        
        return ans;
    }
};