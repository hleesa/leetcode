class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        const int n = nums.size();
        int ans = 0;
        for(int i = 0; i < n; i += 3){
            vector<bool> num(102);
            bool distinct = true;
            for(int j = i; j < n; ++j){
                if(num[nums[j]]){
                    distinct = false;
                    ++ans;
                    break;
                }
                num[nums[j]] = true;
            }
            if(distinct) break;
        }
        return ans;
    }
};