class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        const int n = nums.size();
        map<int, int> counter;
        for(int i = 0; i < n; ++i){
            ++counter[nums[i]-i];
        }
        long long ans = sum(n-1);
        for(auto it : counter){
            if (it.second > 1){
                ans -= sum(it.second - 1);
            }
        }
        return ans;
    }

    long long sum(long long n){
        return (n * (n + 1)) / 2;
    }
};
