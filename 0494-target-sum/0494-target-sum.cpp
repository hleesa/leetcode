class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return sumWays(nums, target, 0, 0);
    }
private:
    int sumWays(const vector<int>& nums, int target, int sum, int index){
        if(index == nums.size()){
            if (sum == target){
                return 1;
            }
            return 0;
        }
        int ways = 0;
        ways += sumWays(nums, target, sum + nums[index], index + 1);
        ways += sumWays(nums, target, sum - nums[index], index + 1);
        return ways;
    }
};