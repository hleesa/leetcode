class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        const int n = nums.size();
        vector<int> sum(n);
        sum[0] = nums[0];
        for(int i = 1; i < n; ++i){
            if(nums[i] > nums[i-1]){
                sum[i] = sum[i-1] + nums[i];
            }
            else{
                sum[i] = nums[i];
            }
        }

        int ans = 0;
        for(int i = 0; i < n; ++i){
            ans = max(sum[i], ans);
        }
        return ans;
    }
};