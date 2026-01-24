class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        int size = nums.size();
        for(int i = 0; i < size; ++i){
            int candi = nums[i] + nums[size-i-1];
            if (candi > ans){
                ans = candi;
            }
        }
        
        return ans;
    }
};
