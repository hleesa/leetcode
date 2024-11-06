class Solution {
public:
    int bitCount(int n){
        return __builtin_popcount(n);
    }
    bool canSortArray(vector<int>& nums) {
        const int n = nums.size();
        for(int i = 0; i + 1 < n; ++i){
            for(int j = 0; j + i + 1 < n; ++j){
                if (nums[j+1] < nums[j] && bitCount(nums[j+1]) == bitCount(nums[j])){
                    swap(nums[j+1], nums[j]);
                }
            }
        }
        for(int i = 0; i + 1 < n; ++i){
            if(nums[i] > nums[i+1]){
                return false;
            }
        }
        return true;
    }
};