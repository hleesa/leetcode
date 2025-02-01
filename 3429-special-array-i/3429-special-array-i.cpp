class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        for(int i = 0; i + 1 < nums.size(); ++i){
            if ((nums[i] & 1) + (nums[i+1] & 1) != 1) return false;
        }
        return true;
    }
};