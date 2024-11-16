class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        const int n = nums.size();
        vector<int> ans;
        for(int i = 0; i + k - 1 < n; ++i){
            int power = asc(nums, i, k) ? nums[i+k-1] : - 1;
            ans.push_back(power);
        }
        return ans;
    }

private:
    bool asc(const vector<int>& nums, int s, int k){
        for(int i = 0; i + 1 < k; ++i){
            if(nums[s+i+1] - nums[s] != i + 1 ){
                return false;
            }
        }
        return true;
    }
};