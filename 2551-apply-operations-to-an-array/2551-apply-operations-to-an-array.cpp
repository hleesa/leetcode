class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        for(int i = 0; i + 1 < nums.size(); ++i){
            if(nums[i] == nums[i+1]){
                nums[i] *= 2;
                nums[i+1] = 0;
            }
        }
        for(int i = 0; i < nums.size(); ++i){
            if (nums[i] != 0){
                int bi = i;
                while(bi - 1 >= 0 && nums[bi - 1] == 0) --bi;
                swap(nums[bi], nums[i]);
            }
        }
        return nums;
    }
};