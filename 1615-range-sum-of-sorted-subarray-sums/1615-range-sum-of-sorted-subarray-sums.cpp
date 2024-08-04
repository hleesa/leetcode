class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int size = nums.size();
        vector<int> subArr;
        subArr.reserve(2*size);
        for(int i=0; i < size; ++i){
            subArr.push_back(nums[i]);
            for(int j=i+1; j < size; ++j){
                subArr.push_back(subArr.back() + nums[j]);
            }
        }
        sort(subArr.begin(), subArr.end());

        int sum = 0;
        for(int i = left-1; i < right; ++i){
            sum = (sum +subArr[i]) % 1000000007;
        }
        return sum;
    }
};