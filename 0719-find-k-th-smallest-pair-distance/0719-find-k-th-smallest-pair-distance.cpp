class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.back() - nums.front();

        while(left < right){
            int mid = left + (right - left) / 2;
            if(countParis(nums, mid) >= k){
                right = mid;
            }
            else{
                left = mid + 1;
            }
        }

        return left;
    }
private:
    int countParis(const vector<int>& nums, int distance){
        int count = 0;
        int j = 0;
        for(int i = 0; i < nums.size(); ++i){
            while(j < nums.size() && nums[j] - nums[i] <= distance){
                ++j;
            }
            count += j-i-1;
        }
        return count;
    }
};