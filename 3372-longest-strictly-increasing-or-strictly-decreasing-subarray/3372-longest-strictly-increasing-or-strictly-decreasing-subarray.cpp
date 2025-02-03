class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int longSub = 1, asc = 1, desc = 1;

        for(int i = 0; i + 1 < nums.size(); ++i){
            if(nums[i+1] < nums[i]){
                ++desc;
                asc = 1;
            }
            else if (nums[i+1] > nums[i]){
                ++asc;
                desc = 1;
            }
            else{
                asc = 1;
                desc = 1;
            }
            longSub = max({asc, desc, longSub});
        }
        
        return longSub;
    }
};