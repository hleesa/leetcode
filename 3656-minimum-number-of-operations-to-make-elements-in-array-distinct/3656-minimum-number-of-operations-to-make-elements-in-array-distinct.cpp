class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        const int n = nums.size();
        int ans = 0;
        for(int i = 0; i < n; i += 3){
            set<int> numSet;
            bool distinct = true;
            for(int j = i; j < n; ++j){
                if(numSet.find(nums[j]) != numSet.end()) {
                    distinct = false;
                    ++ans;
                    break;
                }
                numSet.insert(nums[j]);
            }
            if(distinct) break;
        }
        return ans;
    }
};