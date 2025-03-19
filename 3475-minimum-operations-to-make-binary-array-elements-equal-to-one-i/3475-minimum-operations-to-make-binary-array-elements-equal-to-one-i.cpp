class Solution {
public:
    int minOperations(vector<int>& nums) {
        const int n = nums.size();
        int numOp = 0;
        for(int i = 0; i + 2 < n; ++i){
            if(nums[i] == 0){
                ++numOp;
                for(int j = 0; j < 3; ++j){
                    nums[i+j] ^= 1;
                }
            }
        }

        for(int i = 0; i < n; ++i){
            if(nums[i] == 0){
                return -1;
            }
        }
        return numOp;
    }
};