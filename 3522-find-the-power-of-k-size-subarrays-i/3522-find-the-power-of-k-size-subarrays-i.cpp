class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        const int n = nums.size();
        vector<int> ans;
        for(int i = 0; i + k - 1 < n; ++i){
            vector<int> sub (nums.begin() + i, nums.begin() + i + k);
            int power = asc(sub) ? sub.back() : - 1;
            ans.push_back(power);
        }
        return ans;
    }

private:
    bool asc(const vector<int>& nums){
        for(int i = 0; i + 1 < nums.size(); ++i){
            if(nums[i+1] - nums[i] != 1 ){
                return false;
            }
        }
        return true;
    }
};